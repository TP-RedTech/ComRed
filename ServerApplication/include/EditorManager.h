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
};

class EditorManager: public BaseEditorManager {
public:
    // EditorManger() = default;
    EditorManager(Document document): document(document), logRevision(0), waitingForProcessing() {
        std::cout << document.getId() << std::endl;
        document.addOwner(1);
        std::cout << document.getId() << std::endl;
    }
    Operation changeOperationRelativelyOthers(Operation operation) override;
    void addOperationToLog(Operation operation) override;
    void changeServerDocument(Document document) override;
    void sendOperationToClient(Operation operation) override;
    void sendAnswerToOriginalClient(Operation operation) override;

    // Delegate Method
    void addOperationToQueue(Operation operation) override;

private:
    Document document;
    std::vector<Operation> logRevision;
    std::queue<Operation> waitingForProcessing;
};

#endif //UNTITLED_EDITORMANAGER_H
