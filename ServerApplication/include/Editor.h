#ifndef UNTITLED_EDITOR_H
#define UNTITLED_EDITOR_H

#include "ServerHeader.h"

#include "EditorManagerDelegate.h"
#include "EditorManager.h"

#include "EditorListener.h"

#include "../../Utils/include/Operation.h"
#include "../../Utils/include/Document.h"


class BaseEditor {
public:
    virtual ~BaseEditor() = default;
    virtual Operation submitToServer(Operation operation) = 0;
    virtual Operation makeNewOperation() = 0;
    virtual void changeDocument(Operation operation) = 0;
    virtual void addOperation(Operation operation) = 0;
};

class Editor: public BaseEditor, public EditorListener {
public:
    Editor(Document document, int revision, EditorManagerDelegate manager): syncRevision(revision),
    sendedOperation(),
    waitingForSendOperation{0},
    document(document),
    std::weak_ptr<EditorManagerDelegate> editorManager(manager) {}
    Operation submitToServer(Operation operation) override;
    Operation makeNewOperation() override;
    void changeDocument(Operation operation) override;

    // Observers Methods
    void hearChangesFromServer() override;
    void hearSubmitFromServer() override;

    void addOperation(Operation operation) override;

private:
    int syncRevision;
    Operation sendedOperation;
    std::vector<Operation> waitingForSendOperation;
    Document document;
    std::weak_ptr<EditorManagerDelegate> editorManager;
};

#endif //UNTITLED_EDITOR_H
