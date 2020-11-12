#include <gtest/gtest.h>
#include "gmock/gmock.h"

using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

#include "../inc/AbstractDBController.h"
#include "../inc/DocumentRepository.h"
#include "../inc/UserRepository.h"

class MockDBController : public AbstractDBController
{
public:
    MOCK_METHOD2(runQuery, bool(const string&, vector<vector<string>>&));
}

