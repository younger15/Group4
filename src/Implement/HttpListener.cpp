// Copyright (c) 2021, 鍾淯丞, 周杰仕, 林仁鴻. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "HttpListener.h"
HttpListener* HttpListener::only_http_listener = nullptr;
/*namespcae{

    HttpListener::HttpListener only_http_listener = nullptr;
}*/

void HttpListener::InitInstance(std::function<void(const int&, const std::string&)> callback, const int &port_num){

    this->callback = callback;
    this->BindPort(port_num);
}

//Singleton code convention, must bind with mainManager obj and require listening port
HttpListener* HttpListener::GetInstance(){

    if(only_http_listener == nullptr){

        only_http_listener = new HttpListener();
    }
    return only_http_listener;
};

//listen specific port
void HttpListener::BindPort(const int &port_num){

    this->server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in socket_info;

    if (this->server_fd == -1){

        printf("Fail to create a socket.");
        return;
    }
    bzero((struct sockaddr *)&socket_info , sizeof(socket_info));
    socket_info.sin_family = PF_INET;
    socket_info.sin_addr.s_addr = INADDR_ANY;
    socket_info.sin_port = htons(port_num);
    bind(this->server_fd, (struct sockaddr *)&socket_info, (socklen_t)sizeof(socket_info));
    listen(this->server_fd, 1);
};

void HttpListener::ThreadListen(){

    struct sockaddr_in client_socket_info;
    socklen_t addr_len = sizeof(client_socket_info);
    while(start_listen){
        char client_buffer[2048];
        this->client_fd = accept(this->server_fd, (struct sockaddr *)&client_socket_info, &addr_len);
        recv(this->client_fd, client_buffer, sizeof(client_buffer), 0);
        this->callback(this->client_fd, client_buffer);
    }
}


void HttpListener::StartListen(){

    this->start_listen = true;
    //std::thread tmp_listen_thread(this->ThreadListen);
    //this->listen_thread = tmp_listen_thread;
    this->listen_thread = std::make_shared<std::thread>(&HttpListener::ThreadListen, this);
}

void HttpListener::EndListen(){
    this->start_listen = false;
    this->listen_thread->join();
}

//Singleton code convention 
HttpListener::HttpListener(){
    this->start_listen = false;
};




