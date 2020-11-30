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
    Editor(int revision, Document document, const std::shared_ptr<EditorManager>& editorManager): syncRevision(revision),
                              waitingForSendOperation(0), document(document) {
        this->editorManager = editorManager;
    }
    Operation submitToServer(Operation operation) override;
    Operation makeNewOperation() override;
    void changeDocument(Operation operation) override;

    // Observers Methods
    void hearChangesFromServer() override;
    void hearSubmitFromServer() override;

private:
    int syncRevision;
    Operation sendedOperation;
    std::vector<Operation> waitingForSendOperation;
    Document document;
    std::weak_ptr<EditorManager> editorManager;
};

#endif //UNTITLED_EDITOR_H
