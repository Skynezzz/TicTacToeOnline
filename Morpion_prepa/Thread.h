#pragma once

#include "pch.h"

class Thread
{
public:
	Thread();
	~Thread() {};

	// INIT 
	void Init();

	// THREAD
	virtual void OnThread() {};

protected:
	HANDLE hThread;
	DWORD threadId;
	static DWORD WINAPI ThreadProc(LPVOID lpParam);
};