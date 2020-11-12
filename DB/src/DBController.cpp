#include "../inc/DBController.h"

DBController::DBController(int size) {}

DBController::~DBController() {}

bool DBController::runQuery(const string& query, 
                            vector<vector<string>>& result) {}

void DBController::createPool(int size) {}

pqxx::connection& DBController::getConnection(void) {}

void DBController::freeConnection(pqxx::connection& connection) {}
