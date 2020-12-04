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

    virtual int getId() = 0;
};

class Editor: public BaseEditor {
public:
    Editor() {
        std::cout << "Editor" << " manager has been constructed" << std::endl;
    }
    Editor(int idEditor, const std::shared_ptr<EditorManager>& editorManager):
            id(idEditor),
            waitingForSendOperation(0) {
        this->editorManager = editorManager;
        syncRevision = editorManager->getLastRevision();
        document = editorManager->getCurrentVersionOfDocument();
        std::cout << "Editor" << " manager has been constructed" << std::endl;
    }
    ~Editor() {
        std::cout << "Editor" << " manager has been destructed" << std::endl;
    }
    Operation submitToServer(Operation operation) override;
    Operation makeNewOperation() override;
    void changeDocument(Operation operation) override;

    // Observers Methods
    void hearChangesFromServer() override;
    void hearSubmitFromServer() override;

    int getId() override;

private:
    int id;
    int syncRevision;
    Operation *sendedOperation;
    std::shared_ptr<Document> document;
    std::vector<Operation> waitingForSendOperation;
    std::weak_ptr<EditorManager> editorManager;
};

// Проверка на наличие указателя. Не уничтожили его до этого
// 0 если указатель жив
// 1 - если указатель сброшен
// weakkk.expired()
//    kk.reset();
//    cout << "isExpired = " << weakkk.expired() << endl;

// Получение временного shared указателя, для того
// чтобы мы могли вызвать функцию. После вызова
// объект shared уничтожится, а weak так и останется
//    weakkk.lock()->prt();
// создает копию объекта shared_ptr<int> p2(std::make_shared<int>(*p1));

#endif //UNTITLED_EDITOR_H
