#pragma once

#include <Windows.h>
#include "ServiceBase.h"

class CSampleService : public CServiceBase
{
public:

	CSampleService(PWSTR pszServiceName,
		BOOL fCanStop = TRUE,
		BOOL fCanShutdown = TRUE,
		BOOL fCanPauseContinue = FALSE);

	virtual ~CSampleService();
};

