// Copyright (c) 2021, 鍾淯丞, 周杰仕, 林仁鴻. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "MainManager.h"
#include "RequestHandler.h"

namespace {
class RequestHandlerMock : RequestHandler {
 public:
  int GetFd() { return client_fd; }
};
void TestClient() {
  int sockfd = 0;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in info;
  bzero(&info, sizeof(info));
  info.sin_family = PF_INET;
  info.sin_addr.s_addr = inet_addr("127.0.0.1");
  info.sin_port = htons(*test_port);
  int err = connect(sockfd, (struct sockaddr*)&info, sizeof(info));
  std::string test_string = "POST /explorer/file HTTP/1.1\n";
  test_string += "Host: echo.paw.cloud\n";
  test_string += "Content-Type: application/json; charset=utf-8\n";
  test_string +=
      "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.12; rv:53.0) ";
  test_string += "Gecko/20100101 Firefox/53.0\n";
  test_string += "Connection: close\n";
  test_string += "Content-Length: 136\n\n";
  test_string += "{";
  test_string += "\"path\":\"testPath/myFile/filename.txt\",";
  test_string += "\"pos\":\"0\",";
  test_string += "\"data\":\"123456789\"";
  test_string += "}";
  const char* message = test_string.c_str();
  send(sockfd, message, test_string.length(), 0);
  close(sockfd);
}
}  // namespace

TEST(MainManager_TEST, SimpleTest) {
  uint16_t port_num = 9000;
  MainManager* test_manager = MainManager::GetInstance();
  test_manager.InitInstance(port_num);
  RequestHandlerMock tester_mock;
  test_manager.SetRequestHandler(test_mock);
  TestClient();
  EXPECT_EQ(port_num, tester_mock.GetFd());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleMock(&argc, argv);
  RUN_ALL_TESTS();
}
