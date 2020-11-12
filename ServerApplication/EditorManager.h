#ifndef UNTITLED_EDITORMANAGER_H
#define UNTITLED_EDITORMANAGER_H

#include "vector"
#include "string"
#include "queue"
#include "undefStructs.h"

class BaseEditorManager {
public:
    virtual ~BaseEditorManager() = default;
    virtual Operation changeOperationRelativelyOthers(Operation operation) = 0;
    virtual void addOperationToLog(Operation operation) = 0;
    virtual void acceptOperation(Operation operation) = 0;
    virtual void changeServerDocument(Document document) = 0;
    virtual void sendOperationToClient(Operation operation) = 0;
    virtual void sendAnswerToOriginalClient(Operation operation) = 0;
};

class EditorManager: public BaseEditorManager {
public:
    EditorManager(Document document) {}
    Operation changeOperationRelativelyOthers(Operation operation) override {}
    void addOperationToLog(Operation operation) override {}
    void acceptOperation(Operation operation) override {}
    void changeServerDocument(Document document) override {}
    void sendOperationToClient(Operation operation) override {}
    void sendAnswerToOriginalClient(Operation operation) override {}

private:
    Document document;
    std::vector<Operation> logRevision;
    std::queue<Operation> waitinForProcessing;
};

#endif //UNTITLED_EDITORMANAGER_H
