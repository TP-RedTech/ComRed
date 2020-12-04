#include "Document.h"

void Document::setId(int newId) {
    if (newId >= 0) {
        id = newId;
    }
}

int Document::getId() const {
    return id;
}

std::string Document::getText() {
    return text;
}

void Document::updateText(Operation operation) {
    text += "Override updateText() with OT\n";
}
