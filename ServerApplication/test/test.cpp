#include <gtest/gtest.h>
#include <vector>
#include "gmock/gmock.h"

#include "../include/ServerApplication.h"
#include "../../Utils/include/Document.h"
#include "../../Utils/include/Operation.h"

using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

class MockServerApplication: public BaseServerApplication {
public:
    MOCK_METHOD0(createDocument, int());
    MOCK_METHOD1(updateDocument, std::vector<Operation>(Operation));
    MOCK_METHOD1(deleteDocument, std::vector<Operation>(Operation));
    MOCK_METHOD0(deleteDocument, void());
    MOCK_METHOD0(readDocument, void());
    MOCK_METHOD2(connectDocument, std::string(int, int));
    MOCK_METHOD0(loginUser, std::string());
    MOCK_METHOD1(registerUser, std::string(std::string));
    MOCK_METHOD0(logoutUser, std::string());
    MOCK_METHOD0(updateUser, std::string());
};

class MockEditorManager: public BaseEditorManager, public EditorManagerDelegate {
public:
    MOCK_METHOD1(changeOperationRelativelyOthers, Operation(Operation));
    MOCK_METHOD1(addOperationToLog, void(Operation));
    MOCK_METHOD1(changeServerDocument, void(Document));
    MOCK_METHOD1(sendOperationToClient, void(Operation));
    MOCK_METHOD1(sendAnswerToOriginalClient, void(Operation));


    // Delegate Method
    MOCK_METHOD1(addOperationToQueue, void(Operation));

private:
};

class MockEditor: public BaseEditor, public EditorListener {
public:
    MockEditor() = default;
    MOCK_METHOD1(submitToServer, Operation(Operation));
    MOCK_METHOD0(makeNewOperation, Operation());
    MOCK_METHOD1(changeDocument, void(Operation));

    // Observers Methods
    MOCK_METHOD0(hearChangesFromServer, void());
    MOCK_METHOD0(hearSubmitFromServer, void());

private:
    int syncRevision;
    Operation sendedOperation;
    std::vector<Operation> waitingForSendOperation;
    Document document;
    std::weak_ptr<EditorManagerDelegate> editorManager;
};

class MockSession: public BaseSession {
public:
    MockSession() = default;
    MOCK_METHOD1(manageOperation, void(Operation));
    MOCK_METHOD0(sendToServerBufOfhanger, std::vector<Operation>());

private:
    EditorManager editorManager;
    std::vector<Editor> editors;
    std::vector<Operation> bufferOfChanges;
};

class MockOperation : public Operation {
public:
    MOCK_METHOD0(getRevision, int());
    MOCK_METHOD0(getLengthBeforeOperation, int());
    MOCK_METHOD0(getLengthAfterOperation, int());
    MOCK_METHOD0(getIdEditor, int());
    MOCK_METHOD0(getChanges, std::vector<std::shared_ptr<BaseChange>>());
};


TEST(Document, testUpdateText) {
    MockServerApplication mockServerApplication;
    MockEditorManager mockEditorManager;
    MockEditor mockEditor;
    MockSession mockSession;

    MockOperation opr;
    std::string str;

    EXPECT_CALL(mockServerApplication, createDocument()).Times(AtLeast(2));
    EXPECT_CALL(mockServerApplication, updateDocument(opr)).Times(AtLeast(2));
    EXPECT_CALL(mockServerApplication, deleteDocument()).Times(AtLeast(2));
    EXPECT_CALL(mockServerApplication, readDocument()).Times(AtLeast(2));
    EXPECT_CALL(mockServerApplication, connectDocument(0, 0)).Times(AtLeast(2));
    EXPECT_CALL(mockServerApplication, loginUser()).Times(AtLeast(2));
    EXPECT_CALL(mockServerApplication, registerUser(str)).Times(AtLeast(2));
    EXPECT_CALL(mockServerApplication, logoutUser()).Times(AtLeast(2));
    EXPECT_CALL(mockServerApplication, updateUser()).Times(AtLeast(2));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}