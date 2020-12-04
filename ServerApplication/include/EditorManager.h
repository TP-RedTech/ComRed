#ifndef UNTITLED_EDITORMANAGER_H
#define UNTITLED_EDITORMANAGER_H

#include "ServerHeader.h"

#include "../../Utils/include/Document.h"
#include "../../Utils/include/Operation.h"

class BaseEditorManager {
public:
    virtual ~BaseEditorManager() = default;
    virtual Operation changeOperationRelativelyOthers(Operation operation) = 0;
    virtual void addOperationToLog(Operation operation) = 0;
    virtual void changeServerDocument(Document document) = 0;
    virtual void sendOperationToClient(Operation operation) = 0;
    virtual void sendAnswerToOriginalClient(Operation operation) = 0;
    virtual void addOperationToQueue(Operation operation) = 0;
    virtual int getLastRevision() = 0;
};

class EditorManager: public BaseEditorManager {
public:
    EditorManager(std::shared_ptr<Document> document): document(std::make_shared<Document>(document)), logRevision(0), waitingForProcessing() {
        std::cout << "EditorManager" << document->getId() << " manager has been constructed" << std::endl;
    }

    EditorManager(std::shared_ptr<EditorManager> editorManager): document(editorManager->document), logRevision(editorManager->logRevision), waitingForProcessing(editorManager->waitingForProcessing)
    {
        std::cout << "EditorManager" << document->getId() << " manager has been constructed" << std::endl;

    }

    ~EditorManager() {
        logRevision.clear();
        while(!waitingForProcessing.empty()) waitingForProcessing.pop();
        std::cout << "EditorManager" << document->getId() <<" manager has been destructed" << std::endl;
    }

    Operation changeOperationRelativelyOthers(Operation operation) override;
    void addOperationToLog(Operation operation) override;
    void changeServerDocument(Document document) override;
    void sendOperationToClient(Operation operation) override;
    void sendAnswerToOriginalClient(Operation operation) override;

    // Delegate Method
    void addOperationToQueue(Operation operation) override;

    int getLastRevision() override;
    std::shared_ptr<Document> getCurrentVersionOfDocument();

private:
    std::shared_ptr<Document> document;
    std::vector<Operation> logRevision;
    std::queue<Operation> waitingForProcessing;
};

#endif //UNTITLED_EDITORMANAGER_H
