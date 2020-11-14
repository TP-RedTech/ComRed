#ifndef __DBCONTROLLER_H__
#define __DBCONTROLLER_H__

#include <mutex>
#include <condition_variable>
#include <queue>
#include <pqxx/pqxx>
#include "AbstractDBController.h"

#define DEFAULT_SIZE 10

using namespace std;

class DBController : public AbstractDBController
{
public:
    explicit DBController(int size = DEFAULT_SIZE);
    ~DBController();

    bool runQuery(const string& query, 
                  vector<vector<string>>& result) override;

private:
    queue<pqxx::connection> connectionPool;

    void createPool(int size);
    pqxx::connection& getConnection(void);
    void freeConnection(pqxx::connection& connection);
};

#endif