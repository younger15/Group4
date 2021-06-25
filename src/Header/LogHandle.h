// Copyright (c) 2021, 鍾淯丞, 周杰仕, 林仁鴻. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GROUP4_HEADER_LogHandle_H_
#define GROUP4_HEADER_LogHandle_H_

#include <string>

// write error message to local file
class LogHandle {
 public:
  // singleton code convention method.
  static LogHandle *GetInstance();

  // record these information of error event to file. If it run successfully, it
  // will return 1 else 0.
  static int RecordLog(const std::string &time, const std::string &ip,
                       const std::string &user, const std::string &status_code,
                       const std::string &message);

  // set log_path
  void SetLogPath(std::string path);

  // non copyable
  LogHandle(LogHandle &cpy) = delete;
  LogHandle &operator=(LogHandle &cpy) = delete;

 private:
  // singleton code convention method.
  LogHandle();
  static LogHandle *only_log_handle;
  static std::string log_path;
};

#endif
