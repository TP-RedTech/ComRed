#ifndef UNTITLED_SESSION_H
#define UNTITLED_SESSION_H

#include "Editor.h"

class BaseSession {
public:
    virtual ~BaseSession() = default;
    virtual void manageOperation(int idEditor, Operation operation) = 0;
    virtual std::vector<Operation> sendToServerBufOfhanger() = 0;
    virtual void addEditor(int idEditor) = 0;
};

class Session: public BaseSession {
public:
    Session(const Session&) = delete;
    Session(Session&&) = delete;
    Session(std::unique_ptr<EditorManager> editorManager): editorManager{editorManager.release()}, editors(0), bufferOfChanges(0)
    {
        std::cout << "Session created\n";
    }
    ~Session() {
        std::cout << "Session destructed\n";
    }

    void manageOperation(int idEditor, Operation operation) override;
    std::vector<Operation> sendToServerBufOfhanger() override;
    void addEditor(int idEditor) override;

private:
    std::shared_ptr<EditorManager> editorManager;
    std::vector<Editor> editors;
    std::vector<Operation> bufferOfChanges;
};

#endif //UNTITLED_SESSION_H
