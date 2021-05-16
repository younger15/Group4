// Copyright (c) 2021, 鍾淯丞, 周杰仕, 林仁鴻. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GROUP4_SRC_OPERATEDATA_H_
#define GROUP4_SRC_OPERATEDATA_H_

#include <string>
#include <unordered_map>

// This class is a self-defined data structure containing header and body.
// User should choose to use only as request data or response data
// OperateData newData;
// new_data["key"] = "value";
class OperateData {
 public:
  OperateData();
  OperateData(OperateData &right);
  // Besides HTTP headers, HTTP request method, Request URL, Status Code
  // would store in the header variable.
  std::unordered_map<std::string, std::string> header;
  // Only contain HTTP body.
  std::unordered_map<std::string, std::string> body;
  // only used to access body data
  std::string &operator[](std::string body_key);
};

#endif
