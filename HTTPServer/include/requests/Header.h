#ifndef COMREDSERVER_HEADER_H
#define COMREDSERVER_HEADER_H

#include <string>
#include <utility>
#include <unordered_map>

namespace http {
using Header = std::pair<std::string, std::string>;
using Headers = std::unordered_map<std::string, std::string>;
}

#endif
