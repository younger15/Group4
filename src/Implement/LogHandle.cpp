// Copyright (c) 2021, 鍾淯丞, 周杰仕, 林仁鴻. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "LogHandle.h"

#include <fstream>

LogHandle *LogHandle::only_log_handle = nullptr;
std::string LogHandle::log_path = "../log/log.log";

LogHandle *LogHandle::GetInstance() {
  if (only_log_handle == nullptr) {
    only_log_handle = new LogHandle();
  }
  return only_log_handle;
}

int LogHandle::RecordLog(const std::string &time, const std::string &ip,
                         const std::string &user,
                         const std::string &status_code,
                         const std::string &message) {
  std::string lockfile = log_path + ".lock";
  std::fstream lock(lockfile, std::fstream::in);
  while (!lock.fail()) {
    lock.close();
    lock.open(lockfile, std::fstream::in);
  }

  lock.open(lockfile, std::fstream::out);
  lock.close();

  std::fstream fd;
  fd.open(log_path, std::fstream::app);
  if (!fd) {
    return 1;
  }
  std::string record = time + ip + user + status_code + message + '\n';
  fd.write(record.c_str(), record.length());
  fd.close();
  std::remove(lockfile.c_str());
  return 0;
}

void LogHandle::SetLogPath(std::string path) { log_path = path; }

LogHandle::LogHandle() {}
