#include "Session.h"

void Session::manageOperation(int idEditor, Operation operation) {
    for (int i = 0; i < editors.size(); i++) {
        break;
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
    std::cout<< "added editor with id: " << editors.back()->getId() << std::endl;
}


int Session::getIdDocument() {
    return idDocument;
}