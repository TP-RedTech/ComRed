#include "Session.h"

void Session::manageOperation(int idEditor, std::shared_ptr<Operation> operation) {
    for (std::vector<std::shared_ptr<Editor>>::const_iterator i = editors.cbegin(); i != editors.cend(); i++) {
        if ((*i)->getId() == idEditor) {
            (*i)->changeDocument(operation);
            break;
        }
    }
}

std::vector<Operation> Session::sendToServerBufOfhanger() {
    return std::vector<Operation>();
}

void Session::addEditor(int idEditor) {
    for (int i = 0; i < editors.size(); i++) {
        if (editors[i]->getId() == idEditor) {
            return;
        }
    }
    std::shared_ptr<Editor> newEditor(new Editor(idEditor, editorManager));
    editors.push_back(newEditor);
    editorManager->addEeditor(newEditor);
    std::cout<< "Added editor with id: " << editors.back()->getId() << std::endl;
}


int Session::getIdDocument() {
    return idDocument;
}

std::string Session::getDocumentText() {
    return editorManager->getCurrentTextOfDocument();
}
