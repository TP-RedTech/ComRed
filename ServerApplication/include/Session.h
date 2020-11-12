#ifndef UNTITLED_SESSION_H
#define UNTITLED_SESSION_H

#include "string"
#include "vector"
#include "undefStructs.h"
#include "EditorManager.h"

class BaseSession {
public:
    virtual ~BaseSession() = default;
    virtual void manageOperation(Operation operation) = 0;
    virtual std::vector<Operation> sendToServerBufOfhanger() = 0;
};

class Session: public BaseSession {
public:
    Session() = default;
    virtual void manageOperation(Operation operation) override {}
    virtual std::vector<Operation> sendToServerBufOfhanger() override {}

private:
    EditorManager editorManager;
    std::vector<Editor> editors;
    std::vector<Operation> bufferOfChanges;
};

#endif //UNTITLED_SESSION_H
