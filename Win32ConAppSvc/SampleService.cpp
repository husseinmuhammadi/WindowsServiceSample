#include "stdafx.h"
#include "SampleService.h"

CSampleService::CSampleService(PWSTR pszServiceName, BOOL fCanStop, BOOL fCanShutdown, BOOL fCanPauseContinue)
{
}


CSampleService::~CSampleService()
{
}

void CSampleService::OnStart(DWORD dwArgc, PWSTR * pszArgv)
{
	// Log a service start message to the Application log.
	WriteEventLogEntry(L"CppWindowsService in OnStart",
		EVENTLOG_INFORMATION_TYPE);

	// Queue the main service function for execution in a worker thread.
	CThreadPool::QueueUserWorkItem(&CSampleService::ServiceWorkerThread, this);

}

void CSampleService::OnStop()
{
	// Log a service stop message to the Application log.
	WriteEventLogEntry(L"CppWindowsService in OnStop",
		EVENTLOG_INFORMATION_TYPE);

	// Indicate that the service is stopping and wait for the finish of the 
	// main service function (ServiceWorkerThread).
	m_fStopping = TRUE;
	if (WaitForSingleObject(m_hStoppedEvent, INFINITE) != WAIT_OBJECT_0)
	{
		throw GetLastError();
	}
}

void CSampleService::ServiceWorkerThread(void)
{
	// Periodically check if the service is stopping.
	while (!m_fStopping)
	{
		// Perform main service function here...

		::Sleep(2000);  // Simulate some lengthy operations.
	}

	// Signal the stopped event.
	SetEvent(m_hStoppedEvent);
}
