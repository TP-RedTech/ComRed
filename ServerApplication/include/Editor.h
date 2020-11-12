#ifndef UNTITLED_EDITOR_H
#define UNTITLED_EDITOR_H

#include "ServerHeader.h"

class BaseEditor {
public:
    virtual ~BaseEditor() = default;
    virtual Operation submitToServer(Operation oepration) = 0;
    virtual void hearChangesFromServer() = 0;
    virtual void hearSubmitFromServer() = 0;
    virtual Operation makeNewOperation() = 0;
    virtual void changeDocument(Operation operation) = 0;
};

class Editor: public BaseEditor {
public:
    Editor() = default;
    Operation submitToServer(Operation operation) override;
    void hearChangesFromServer() override;
    void hearSubmitFromServer() override;
    Operation makeNewOperation() override;
    void changeDocument(Operation operation) override;

private:
    int syncRevision;
    Operation sendedOperation;
    std::vector<Operation> waitingForSendOperation;
    Document document;
};

#endif //UNTITLED_EDITOR_H
