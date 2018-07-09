
#pragma region Includes
#include "stdafx.h"
#include <Windows.h>
#include "ServiceBase.h"
#include "SampleService.h"
#pragma endregion

CSampleService::CSampleService(PWSTR pszServiceName, BOOL fCanStop, BOOL fCanShutdown, BOOL fCanPauseContinue)
	: CServiceBase(pszServiceName, fCanStop, fCanShutdown, fCanPauseContinue)
{
}


CSampleService::~CSampleService()
{
}
