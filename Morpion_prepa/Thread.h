#pragma once

#include <Windows.h>

class Thread
{
public:
	Thread();
	~Thread() {};

	// INIT 
	void Init();
	HANDLE GetHandle() const { return hThread; };

	// THREAD
	virtual void OnThread() {};

protected:
	HANDLE hThread;
	DWORD threadId;
	static DWORD WINAPI ThreadProc(LPVOID lpParam);
};