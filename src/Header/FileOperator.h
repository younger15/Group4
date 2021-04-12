// Copyright (c) 2021, 鍾淯丞, 周杰仕, 林仁鴻. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "./ResponseHandler.h"
#include "./OperateData.h"
#include <string>

class FileOperator
{

public:
    void Upload(std::string path, std::string filename);
    std::string Download(std::string path);
    void Update(std::string path, OperateData updateInfo);

private:
    ResponseHandler response;
};