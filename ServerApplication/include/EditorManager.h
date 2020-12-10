#ifndef UNTITLED_EDITORMANAGER_H
#define UNTITLED_EDITORMANAGER_H

#include "ServerHeader.h"

#include "../../Utils/include/Document.h"
#include "../../Utils/include/Operation.h"

class Editor;

class BaseEditorManager {
public:
    virtual ~BaseEditorManager() = default;
    virtual Operation changeOperationRelativelyOthers(Operation operation) = 0;
    virtual void addOperationToLog(std::shared_ptr<Operation> operation) = 0;
    virtual void changeServerDocument() = 0;
    virtual void sendOperationToClient(Operation operation) = 0;
    virtual void sendAnswerToOriginalClient(Operation operation) = 0;
    virtual void addOperationToQueue(std::shared_ptr<Operation> operation) = 0;
    virtual int getLastRevision() = 0;
};

class EditorManager: public BaseEditorManager {
public:
    EditorManager(std::shared_ptr<Document> document): document(std::make_shared<Document>(document)), logRevision(0),
                                                       waitingForProcessing(), editors(0) { }

    EditorManager(std::shared_ptr<EditorManager> editorManager): document(editorManager->document), logRevision(editorManager->logRevision), waitingForProcessing(editorManager->waitingForProcessing), editors(0)
    { }

    ~EditorManager() {
        logRevision.clear();
        waitingForProcessing.clear();
    }

    Operation changeOperationRelativelyOthers(Operation operation) override;
    void addOperationToLog(std::shared_ptr<Operation> operation) override;
    void changeServerDocument() override;
    void sendOperationToClient(Operation operation) override;
    void sendAnswerToOriginalClient(Operation operation) override;

    // Delegate Method
    void addOperationToQueue(std::shared_ptr<Operation> operation) override;

    int getLastRevision() override;
    std::shared_ptr<Document> getCurrentVersionOfDocument();
    void addEeditor(const std::shared_ptr<Editor>& editor);

private:
    std::shared_ptr<Document> document;
    std::vector<std::shared_ptr<Operation>> logRevision;
    std::deque<std::shared_ptr<Operation>> waitingForProcessing;
    std::vector<std::weak_ptr<Editor>> editors;
};

#endif //UNTITLED_EDITORMANAGER_H
