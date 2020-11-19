#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "controller/ConnectController.h"
#include "controller/CreateController.h"
#include "controller/DeleteController.h"
#include "controller/EditController.h"
#include "controller/LoginController.h"
#include "controller/LogoutController.h"
#include "controller/RegistrationController.h"

#include "requests/Request.h"
#include "requests/Reply.h"

#include "client/Client.h"

using namespace http;

class MockClient : public Client {
public:
  MockClient() = default;
  MOCK_METHOD0(run, void());
};

class MockConnectController : public server::ConnectController {
public:
  MockConnectController() = default;
  MOCK_METHOD1(handleRequest, Reply(const Request &request));
};

class MockCreateController : public server::CreateController {
public:
  MockCreateController() = default;
  MOCK_METHOD1(handleRequest, Reply(const Request &request));
};

class MockDeleteController : public server::DeleteController {
public:
  MockDeleteController() = default;
  MOCK_METHOD1(handleRequest, Reply(const Request &request));
};

class MockEditController : public server::EditController {
public:
  MockEditController() = default;
  MOCK_METHOD1(handleRequest, Reply(const Request &request));
};

class MockLoginController : public server::LoginController {
public:
  MockLoginController() = default;
  MOCK_METHOD1(handleRequest, Reply(const Request &request));
};

class MockLogoutController : public server::LogoutController {
public:
  MockLogoutController() = default;
  MOCK_METHOD1(handleRequest, Reply(const Request &request));
};

class MockRegistrationController : public server::RegistrationController {
public:
  MockRegistrationController() = default;
  MOCK_METHOD1(handleRequest, Reply(const Request &request));
};

class ConnectContorllerTest : public ::testing::Test {
protected:
  void SetUp() override
  {

  }

};

TEST(ConnectControllerTest, test1) {
}

TEST(CreateControllerTest, test1) {
  MockCreateController c;
}

TEST(DeleteControllerTest, test1) {
  MockDeleteController c;
}

TEST(EditControllerTest, test1) {
  MockEditController c;
}

TEST(LoginControllerTest, test1) {
  MockLoginController c;
}

TEST(LogoutControllerTest, test1) {
  MockLogoutController c;
}

TEST(RegistrationControllerTest, test1) {
  MockRegistrationController c;
}
