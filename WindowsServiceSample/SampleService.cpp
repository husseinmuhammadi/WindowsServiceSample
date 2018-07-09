#include "stdafx.h"
#include "SampleService.h"


CSampleService::CSampleService(PWSTR pszServiceName, BOOL fCanStop, BOOL fCanShutdown, BOOL fCanPauseContinue)
	: CServiceBase(pszServiceName, fCanStop, fCanShutdown, fCanPauseContinue)
{
}


CSampleService::~CSampleService()
{
}
