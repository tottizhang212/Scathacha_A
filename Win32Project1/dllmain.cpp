// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"

#include "proc.h"



HANDLE hThread;
pFunc Hook = (pFunc)(0x0042A730);
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		DWORD threadID;
		//HANDLE hThread;
		loadCodes(hModule);

	
		hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, &threadID); // 创建线程
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

DWORD hookTest(DWORD para) {
	printf("hookTest!");

	return Hook(para);


}