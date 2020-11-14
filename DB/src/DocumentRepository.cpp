#include "../include/DocumentRepository.h"

DocumentRepository::DocumentRepository(weak_ptr<AbstractDBController> ctrl) {}
    
DocumentRepository::~DocumentRepository() {}

void DocumentRepository::createDoc(Document& d) {}

void DocumentRepository::changeDoc(Document& d) {}

void DocumentRepository::deleteDoc(Document& d) {}

Document DocumentRepository::getById(int id) {}

Document DocumentRepository::getByUser(User& u) {}

void DocumentRepository::addUser(User& u, Document& d) {}
