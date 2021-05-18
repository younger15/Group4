#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "HttpListener.h"

// Testing HttpListener mock class
class HttpListenerMock : public HttpListener {
 private:
  static HttpListenerMock* test_listener;
  HttpListenerMock(){

  };

 public:
  static HttpListenerMock* GetInstance() {
    HttpListener::GetInstance();
    if (test_listener == nullptr) {
      test_listener = new HttpListenerMock();
    }
    return test_listener;
  }
  ::testing::MockFunction<void(const int&, const std::string&)> mock_callback;
  // MOCK_METHOD(void, callback, (const int &sock_fd, const std::string &data),
  // (override));
  MOCK_METHOD(void, ThreadListen, (), (const));
  MOCK_METHOD(void, BindPort, (const int& port_num), (const));
};

// Init static variable for mock
HttpListenerMock* HttpListenerMock::test_listener = nullptr;

// Test waiting for request and do the callback
TEST(HttpListener_MOCK, Listening) {
  std::function<void(const int&, const std::string&)> test_callback;
  int port_num = 9000;
  HttpListenerMock* http_listener = HttpListenerMock::GetInstance();
  EXPECT_CALL(*http_listener, BindPort(port_num)).Times(1);
  EXPECT_CALL(*http_listener, ThreadListen()).Times(1);
  EXPECT_CALL(http_listener->mock_callback, Call(::testing::_, ::testing::_))
      .Times(::testing::AtLeast(1));
  http_listener->InitInstance(test_callback, port_num);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleMock(&argc, argv);
  RUN_ALL_TESTS();
}