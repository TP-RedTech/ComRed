#include "server/controller/EditController.h"

namespace server {
ServerApplicationOut EditController::handle(const std::string &body) {
  std::istringstream ss(body);
  int editorId, docId, cursorPosition;
  std::string operations;
  ss >> editorId >> docId >> cursorPosition;
  getline(ss, operations);
  return ServerApplication::get_instance()->updateDocument(editorId, docId, cursorPosition, operations);
};
}
