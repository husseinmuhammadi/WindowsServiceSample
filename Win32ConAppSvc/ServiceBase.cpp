#include "stdafx.h"
#include "ServiceBase.h"


CServiceBase::CServiceBase(PWSTR pszServiceName,
	BOOL fCanStop = TRUE,
	BOOL fCanShutdown = TRUE,
	BOOL fCanPauseContinue = FALSE)
{
}


CServiceBase::~CServiceBase()
{
}

BOOL CServiceBase::Run(CServiceBase & service)
{
	return 0;
}


void CServiceBase::Stop()
{
}

