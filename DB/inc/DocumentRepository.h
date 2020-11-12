#ifndef __DOCUMENTREPOSITORY_H__
#define __DOCUMENTREPOSITORY_H__

#include <memory>
#include "DBController.h"
//#include "User.h"
//#include "Document.h"

using namespace std;

class DocumentRepository
{
public:
    DocumentRepository(weak_ptr<AbstractDBController> ctrl);
    ~DocumentRepository();

    void createDoc(Document& d);
    void changeDoc(Document& d);
    void deleteDoc(Document& d);
    Document getById(int id);
    Document getByUser(User& u);
    void addUser(User& u, Document& d);

private:
    weak_ptr<AbstractDBController> db;
};

#endif