#ifndef UNTITLED_EDITORMANAGER_H
#define UNTITLED_EDITORMANAGER_H

#include "ServerHeader.h"

#include "EditorManagerDelegate.h"
#include "Editor.h"
#include "EditorListener.h"

#include "../../Utils/include/Document.h"

class BaseEditorManager {
public:
    virtual ~BaseEditorManager() = default;
    virtual Operation changeOperationRelativelyOthers(Operation operation) = 0;
    virtual void addOperationToLog(Operation operation) = 0;
    virtual void changeServerDocument(Document document) = 0;
    virtual void sendOperationToClient(Operation operation) = 0;
    virtual void sendAnswerToOriginalClient(Operation operation) = 0;
};

class EditorManager: public BaseEditorManager, public EditorManagerDelegate {
public:
    EditorManager();
    EditorManager(Document document): BaseEditorManager() {
        this->document = document;
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
    std::vector<EditorListener> editors;
    std::queue<Operation> waitingForProcessing;
};

#endif //UNTITLED_EDITORMANAGER_H
