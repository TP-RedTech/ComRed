#include "ServerApplication.h"

int main(int argc, const char * argv[]) {

//    shared_ptr<Kek> kk(new Kek(1, 2));
//    weak_ptr<Kek> weakkk(kk);
//
//    kk->prt();
//    weakkk->w

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

//    std::string text = "some text";
//
//    std::shared_ptr<Document> document(new Document(1, text));
//    std::shared_ptr<EditorManager> editorManager(new EditorManager(document));
//    std::shared_ptr<Session> session(new Session(document->getId(), editorManager));
//    session->addEditor(3);
//    session->addEditor(5);
//    session->addEditor(9);

    std::unique_ptr<ServerApplication> server(new ServerApplication());
    server->connectDocument(1, 30);
    server->connectDocument(2, 30);
    server->connectDocument(2, 30);

    std::cout << "\nHello, World!\n" << std::endl;
    return 0;
}
