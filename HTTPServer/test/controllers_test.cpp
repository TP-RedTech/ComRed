#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "controller/controllers.h"

#include "requests/Request.h"
#include "requests/Reply.h"

#include "client/Client.h"


/*
Добрый день!
В данный момент этот класс должен находиться в папке ServerApplication,
но, к сожалению, возникла некоторая неопределнность, так как этот
класс является связующим между http-сервером и логикой приложения.
В ближайшее время это недарозумение будет приведено к порядочному виду.
 */
class BaseServerApplication {
public:
  BaseServerApplication() = default;
  virtual ~BaseServerApplication() = default;

  virtual int createDocument(std::string userData, std::string documentName) = 0;

  virtual std::vector<std::string> updateDocument(std::string userData, int docId, std::vector<std::string> operations) = 0;

  virtual void deleteDocument(std::string userData, int docId) = 0;

  virtual std::string readDocument(std::string userData, int docId) = 0;

  virtual std::string connectDocument(std::string userData, int docId) = 0;

  virtual std::string  loginUser(std::string userData) = 0;

  virtual std::string registerUser(std::string userData) = 0;

  virtual std::string logoutUser(std::string userData) = 0;

  virtual std::string updateUser(std::string userData, std::string newUserData) = 0;
};

using namespace std;

class MockServerApplication {
public:
  MockServerApplication() = default;

  virtual ~MockServerApplication() = default;

  MOCK_METHOD2(createDocument, int(string userData, string documentName));

  MOCK_METHOD3(updateDocument, vector<string>(string userData, int docId, vector<string> operations));

  MOCK_METHOD2(deleteDocument, void(string userData, int docId));

  MOCK_METHOD2(readDocument, string(string userData, int docId));

  MOCK_METHOD2(connectDocument, std::string(string userData, int docId));

  MOCK_METHOD1(loginUser, string(string userData));

  MOCK_METHOD1(registerUser, string(string userData));

  MOCK_METHOD1(logoutUser, string(string userData));

  MOCK_METHOD2(updateUser, string(string userData, string newUserData));
};

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

class ConnectControllerTest : public ::testing::Test {
protected:
  void SetUp() override {

  }

};

TEST(ConnectControllerTest, test1) {
  server::ConnectController c;
  Request q;
  q.headers["type"] = "connect";
  Reply r = c.handleRequest(q);
  ASSERT_EQ(r.headers["type"], "connect");
}

TEST(CreateControllerTest, test1) {
  server::CreateController c;
  Request q;
  q.headers["type"] = "create";
  Reply r = c.handleRequest(q);
  ASSERT_EQ(r.headers["type"], "create");
}

TEST(DeleteControllerTest, test1) {
  server::CreateController c;
  Request q;
  q.headers["type"] = "delete";
  Reply r = c.handleRequest(q);
  ASSERT_EQ(r.headers["type"], "delete");
}

TEST(EditControllerTest, test1) {
  server::CreateController c;
  Request q;
  q.headers["type"] = "edit";
  Reply r = c.handleRequest(q);
  ASSERT_EQ(r.headers["type"], "edit");
}

TEST(LoginControllerTest, test1) {
  server::CreateController c;
  Request q;
  q.headers["type"] = "login";
  Reply r = c.handleRequest(q);
  ASSERT_EQ(r.headers["type"], "login");
}

TEST(LogoutControllerTest, test1) {
  server::CreateController c;
  Request q;
  q.headers["type"] = "logout";
  Reply r = c.handleRequest(q);
  ASSERT_EQ(r.headers["type"], "logout");
}

TEST(RegistrationControllerTest, test1) {
  server::CreateController c;
  Request q;
  q.headers["type"] = "register";
  Reply r = c.handleRequest(q);
  ASSERT_EQ(r.headers["type"], "register");
}
