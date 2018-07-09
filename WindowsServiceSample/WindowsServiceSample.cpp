// WindowsServiceSample.cpp : Defines the entry point for the console application.
//

#pragma region Includes
#include "stdafx.h"
#include <Windows.h>
#include "ServiceBase.h"
#include "SampleService.h"
#include "WindowsServiceSample.h"
#pragma endregion

// 
// Settings of the service
// 

// Internal name of the service
#define SERVICE_NAME             L"CppWindowsService"

// Displayed name of the service
#define SERVICE_DISPLAY_NAME     L"CppWindowsService Sample Service"

// Service start options.
#define SERVICE_START_TYPE       SERVICE_DEMAND_START

// List of service dependencies - "dep1\0dep2\0\0"
#define SERVICE_DEPENDENCIES     L""

// The name of the account under which the service should run
#define SERVICE_ACCOUNT          L"NT AUTHORITY\\LocalService"

// The password to the service account name
#define SERVICE_PASSWORD         NULL

int main()
{
	CSampleService service(SERVICE_NAME);
	
	if (!CServiceBase::Start(service))
	{
		wprintf(L"Service failed to run w/err 0x%08lx\n", GetLastError());
	}
	
	return 0;
}

