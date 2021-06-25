// Copyright (c) 2021, 鍾淯丞, 周杰仕, 林仁鴻. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <fstream>

#include "LogHandle.h"

TEST(LOGHANDLE_TEST, RecordError) {
  std::string time, ip, user, status_code, message;
  std::string test_log_path = "../log/log_test.log";
  LogHandle* logger = LogHandle::GetInstance();
  logger->SetLogPath(test_log_path);

  int result = logger->RecordLog(time, ip, user, status_code, message);
  ASSERT_EQ(0, result);

  std::fstream fd(test_log_path, std::fstream::out);
  ASSERT_TRUE(fd);
  std::string record = time + ip + user + status_code + message;
  std::string output;
  getline(fd, output);
  EXPECT_EQ(record, output);

  std::remove(test_log_path.c_str());
  EXPECT_FALSE(std::ifstream(test_log_path));  // check test_log deleted
}
