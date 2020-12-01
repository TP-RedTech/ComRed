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
        if (editors[i].getId() == idEditor) {
            return;
        }
    }
    Editor newEditor(idEditor, editorManager);
    editors.push_back(newEditor);
    std::cout<< "added editor with id: " << editors.back().getId() << std::endl;
}