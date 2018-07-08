#pragma once
#include "ServiceBase.h"
class CSampleService : public CServiceBase
{
public:

	CSampleService(PWSTR pszServiceName,
		BOOL fCanStop = TRUE,
		BOOL fCanShutdown = TRUE,
		BOOL fCanPauseContinue = FALSE);

	virtual ~CSampleService();

protected:

	virtual void OnStart(DWORD dwArgc, PWSTR *pszArgv);

	virtual void OnStop();

	void ServiceWorkerThread(void);

};

