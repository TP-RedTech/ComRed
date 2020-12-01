#ifndef UNTITLED_EDITOR_H
#define UNTITLED_EDITOR_H

#include "EditorManager.h"

class BaseEditor {
public:
    virtual ~BaseEditor() = default;
    virtual Operation submitToServer(Operation operation) = 0;
    virtual Operation makeNewOperation() = 0;
    virtual void changeDocument(Operation operation) = 0;

    virtual void hearChangesFromServer() = 0;
    virtual void hearSubmitFromServer() = 0;
};

class Editor: public BaseEditor {
public:
    Editor() {}
    Editor(int idEditor, const std::shared_ptr<EditorManager>& editorManager):
            id(idEditor),
            waitingForSendOperation(0) {
        this->editorManager = editorManager;
        syncRevision = editorManager->getLastRevision();
        document = editorManager->getCurrentDocumentVersion();
    }
    Operation submitToServer(Operation operation) override;
    Operation makeNewOperation() override;
    void changeDocument(Operation operation) override;

    // Observers Methods
    void hearChangesFromServer() override;
    void hearSubmitFromServer() override;

    int getId();

private:
    int id;
    int syncRevision;
    Operation sendedOperation;
    Document document;
    std::vector<Operation> waitingForSendOperation;
    std::weak_ptr<EditorManager> editorManager;
};

#endif //UNTITLED_EDITOR_H
