#pragma once

#pragma comment(lib, "ws2_32.lib")

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <ws2tcpip.h>

#include <Windows.h>

#define MAX_LOADSTRING 100

#define WM_CONNECTION_NOTIFY WM_USER + 1 
#define WM_MESSAGE_NOTIFY WM_USER + 2 