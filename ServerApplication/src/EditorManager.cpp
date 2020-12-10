#include "EditorManager.h"
#include "Editor.h"

Operation EditorManager::changeOperationRelativelyOthers(Operation operation) {
    return Operation();
}

void EditorManager::addOperationToLog(std::shared_ptr<Operation> operation) {


}

void EditorManager::changeServerDocument() {
    auto operation = waitingForProcessing.front();
    waitingForProcessing.pop_front();
    for (auto iter = waitingForProcessing.begin(); iter != waitingForProcessing.end(); iter++) {
        //iter = operation->transform(*iter)[1];
        if ((*iter)->getRevision() >= operation->getRevision()) {
            *(iter->get()) = operation->transform(*(iter->get()))[1];
        }
    }

    document->updateText(operation);

    std::cout << "\nSERVER[" << document->getId() << "] DOCUMENT: " << document->getText() << std::endl;
    for (auto iter = editors.cbegin(); iter != editors.cend(); iter++) {
        if (operation->getIdEditor() == (*iter).lock()->getId()) {
            (*iter).lock()->hearSubmitFromServer();
        } else {
            (*iter).lock()->hearChangesFromServer(operation);
        }
    }
//
//    logRevision.push_back(operation);
}

void EditorManager::sendOperationToClient(Operation operation) {

}

void EditorManager::sendAnswerToOriginalClient(Operation operation) {

}

void EditorManager::addOperationToQueue(std::shared_ptr<Operation> operation)  {
    waitingForProcessing.push_back(operation);
    changeServerDocument();
}

int EditorManager::getLastRevision() {
    return 0;
}

std::shared_ptr<Document> EditorManager::getCurrentVersionOfDocument() {
    return std::make_shared<Document>(document);
}

void EditorManager::addEeditor(const std::shared_ptr<Editor>& editor) {
    std::weak_ptr<Editor> weakEditor(editor);
    editors.push_back(weakEditor);
}
