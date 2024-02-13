#pragma once
#include <iostream>
#include <string>
#include <winsock2.h>
#include <vector>

#pragma comment(lib, "ws2_32.lib")

class WebDisplay
{
private:
    std::string generateTicTacToeHTML(std::vector<char> grid);
    void handle_request(SOCKET client_socket, std::vector<char> grid);

    WSADATA wsa_data;
    SOCKET listen_socket;
    sockaddr_in server_addr;

public:
    int init();
    int start(std::vector<char> grid);
};