#include "Thread.h"
#include <iostream>

Thread::Thread()
{
}

void Thread::Init()
{
	hThread = CreateThread(NULL, 0, ThreadProc, (void*)this, 0, &threadId);
	if (hThread == NULL)
	{
		std::cout << "Error creating the Thread." << std::endl;
		return;
	}

	return;
}

DWORD Thread::ThreadProc(LPVOID lpParam)
{
	Thread* pThread = (Thread*)lpParam;
	pThread->OnThread();

	return 0;
}
