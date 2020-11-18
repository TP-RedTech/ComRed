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
  MockClient() = default;
  MOCK_METHOD0(run, void());
};

class MockConnectController : public server::ConnectController {
  MockConnectController() = default;
  MOCK_METHOD1(handleRequest, Reply(const Request &request));
};

class MockCreateController : public server::CreateController {
  MockCreateController() = default;
  MOCK_METHOD1(handleRequest, Reply(const Request &request));
};

class MockDeleteController : public server::DeleteController {
  MockDeleteController() = default;
  MOCK_METHOD1(handleRequest, Reply(const Request &request));
};

class MockEditController : public server::EditController {
  MockEditController() = default;
  MOCK_METHOD1(handleRequest, Reply(const Request &request));
};

class MockLoginController : public server::LoginController {
  MockLoginController() = default;
  MOCK_METHOD1(handleRequest, Reply(const Request &request));
};

class MockLogoutController : public server::LogoutController {
  MockLogoutController() = default;
  MOCK_METHOD1(handleRequest, Reply(const Request &request));
};


TEST(test, test) {
  ASSERT_EQ(true, true);
}
