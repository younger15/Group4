// Copyright (c) 2021, 鍾淯丞, 周杰仕, 林仁鴻. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "./OperateData.h"
#include "./APIHandler.h"

class ResponseHandler
{

public:
    void Send();

private:
    OperateData *data;
    OperateData *header;
    std::string response;
};