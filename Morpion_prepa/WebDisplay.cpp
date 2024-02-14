#include "WebDisplay.h"

int WebDisplay::init()
{
    if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0) {
        std::cerr << "Failed to initialize Winsock." << std::endl;
        return 1;
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listen_socket == INVALID_SOCKET) {
        std::cerr << "Failed to create socket." << std::endl;
        WSACleanup();
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(80);

    if (bind(listen_socket, reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr)) == SOCKET_ERROR) {
        std::cerr << "Failed to bind socket." << std::endl;
        closesocket(listen_socket);
        WSACleanup();
        return 1;
    }

    if (listen(listen_socket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Failed to listen on socket." << std::endl;
        closesocket(listen_socket);
        WSACleanup();
        return 1;
    }

    std::cout << "Server running on port 80..." << std::endl;
}

int WebDisplay::start(std::vector<char>* grid) {
    for (;;) {
        sockaddr_in client_addr;
        int client_addr_size = sizeof(client_addr);
        SOCKET client_socket = accept(listen_socket, reinterpret_cast<sockaddr*>(&client_addr), &client_addr_size);
        if (client_socket == INVALID_SOCKET) {
            std::cerr << "Failed to accept client connection." << std::endl;
            closesocket(listen_socket);
            WSACleanup();
            return 1;
        }

        handle_request(client_socket, *grid);
    }

    closesocket(listen_socket);
    WSACleanup();
    return 0;
}

std::string WebDisplay::generateTicTacToeHTML(std::vector<char> grid) {
    std::string html = "<table>";
    for (int i = 0; i < 3; ++i) {
        html += "<tr>";
        for (int j = 0; j < 3; ++j) {
            html += "<td>";
            char symbol = grid[i * 3 + j];
            switch (symbol)
            {
            case 'x':
                html += "<img src = https://www.shutterstock.com/image-vector/letter-x-logogrunge-cross-sign-600nw-1187594722.jpg / >";
                break;

            case 'o':
                html += "<img src = https://www.lettresadhesives.net/storage/stickers/rond%20vide%202.png / >";
                break;

            case 'n':
                html += "&nbsp";
                break;

            default:
                break;
            }
            html += "</td>";
        }
        html += "</tr>";
    }
    html += "</table>";
    return html;
}

void WebDisplay::handle_request(SOCKET client_socket, std::vector<char> grid) {
    std::cout << "Request web : ";
    std::string html = generateTicTacToeHTML(grid);

    std::string response = "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: " + std::to_string(html.size()) + "\r\n"
        "\r\n" + html;

    send(client_socket, response.c_str(), response.size(), 0);
    closesocket(client_socket);
    std::cout << "Done";
}