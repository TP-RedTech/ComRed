#include "server/controller/EditController.h"

namespace server {
ServerApplicationOut EditController::handle(const std::string &body) {
  std::istringstream ss(body);
  std::cout << body << std::endl;
  int editorId, docId, cursorPosition;
  std::string operations;
  ss >> editorId >> docId >> cursorPosition;
  ss.ignore(1);
  getline(ss, operations);
  std::cout << '"' << operations << '"' << std::endl;
  return ServerApplication::get_instance()->updateDocument(editorId, docId, cursorPosition, operations);
}
}
