// Copyright (c) 2021, 鍾淯丞, 周杰仕, 林仁鴻. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "DownloadStream.h"

#include <fstream>
#include <string>

DownloadStream::DownloadStream(const std::string &filename,
                               const unsigned long &chunk_size)
    : filename(filename), chunk_size(chunk_size) {
  fd.open(filename, std::fstream::in);
}

int DownloadStream::ReadChunk(unsigned long &pos, std::string *const binary) {
  if (fd.fail()) {
    return 0;
  }

  fd.seekg(pos * chunk_size, std::ios::beg);
  char buffer[chunk_size + 1];
  buffer[chunk_size] = '\0';
  fd.read(buffer, chunk_size);
  *binary = buffer;
  if (fd.eof()) {
    return 2;
  }
  return 1;
}
