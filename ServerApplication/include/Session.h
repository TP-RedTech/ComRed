#ifndef UNTITLED_SESSION_H
#define UNTITLED_SESSION_H

#include "Editor.h"

class BaseSession {
public:
    virtual ~BaseSession() = default;
    virtual void manageOperation(Operation operation) = 0;
    virtual std::vector<Operation> sendToServerBufOfhanger() = 0;
};

class Session: public BaseSession {
public:
    Session(const Session&) = delete;
    Session(Session&&) = default;
    Session(EditorManager& editorManager): editorManager(editorManager), editors(0), bufferOfChanges(0) {}
    void manageOperation(Operation operation) override;
    std::vector<Operation> sendToServerBufOfhanger() override;

private:
    EditorManager editorManager;
    std::vector<Editor> editors;
    std::vector<Operation> bufferOfChanges;
};

#endif //UNTITLED_SESSION_H
