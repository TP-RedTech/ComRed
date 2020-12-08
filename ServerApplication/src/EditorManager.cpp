#include "EditorManager.h"
#include "Editor.h"

Operation EditorManager::changeOperationRelativelyOthers(Operation operation) {
    return Operation();
}

void EditorManager::addOperationToLog(Operation operation) {


}

void EditorManager::changeServerDocument(Document document) {
}

void EditorManager::sendOperationToClient(Operation operation) {

}

void EditorManager::sendAnswerToOriginalClient(Operation operation) {

}

void EditorManager::addOperationToQueue(Operation operation)  {

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
