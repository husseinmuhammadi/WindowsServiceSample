#include "stdafx.h"
#include <assert.h>
#include "ServiceBase.h"


// Initialize the singleton service instance.
CServiceBase *CServiceBase::service = NULL;

//
//   FUNCTION: CServiceBase::CServiceBase(PWSTR, BOOL, BOOL, BOOL)
//
//   PURPOSE: The constructor of CServiceBase. It initializes a new instance 
//   of the CServiceBase class. The optional parameters (fCanStop, 
///  fCanShutdown and fCanPauseContinue) allow you to specify whether the 
//   service can be stopped, paused and continued, or be notified when system 
//   shutdown occurs.
//
//   PARAMETERS:
//   * pszServiceName - the name of the service
//   * fCanStop - the service can be stopped
//   * fCanShutdown - the service is notified when system shutdown occurs
//   * fCanPauseContinue - the service can be paused and continued
//
CServiceBase::CServiceBase(PWSTR pszServiceName,
	BOOL fCanStop,
	BOOL fCanShutdown,
	BOOL fCanPauseContinue)
{
	// Service name must be a valid string and cannot be NULL.
	m_Name = (pszServiceName == NULL) ? L"" : pszServiceName;

	m_StatusHandle = NULL;

	// The service runs in its own process.
	m_Status.dwServiceType = SERVICE_WIN32_OWN_PROCESS;

	// The service is starting.
	m_Status.dwCurrentState = SERVICE_START_PENDING;

	// The accepted commands of the service.
	DWORD dwControlsAccepted = 0;
	if (fCanStop)
		dwControlsAccepted |= SERVICE_ACCEPT_STOP;
	if (fCanShutdown)
		dwControlsAccepted |= SERVICE_ACCEPT_SHUTDOWN;
	if (fCanPauseContinue)
		dwControlsAccepted |= SERVICE_ACCEPT_PAUSE_CONTINUE;
	m_Status.dwControlsAccepted = dwControlsAccepted;

	m_Status.dwWin32ExitCode = NO_ERROR;
	m_Status.dwServiceSpecificExitCode = 0;
	m_Status.dwCheckPoint = 0;
	m_Status.dwWaitHint = 0;
}

CServiceBase::~CServiceBase()
{
}

BOOL CServiceBase::Start(CServiceBase & service)
{
	return 0;
}

void CServiceBase::ServiceMain(DWORD dwArgc, LPWSTR *pszArgv)
{
	assert(service != NULL);

	// Register the handler function for the service
	service->m_StatusHandle = RegisterServiceCtrlHandler(
		service->m_Name, ServiceCtrlHandler);

	if (service->m_StatusHandle == NULL)	
		throw GetLastError();

	// Start the service.
	service->Start(dwArgc, pszArgv);
}

void CServiceBase::ServiceCtrlHandler(DWORD dwCtrl)
{
	switch (dwCtrl)
	{
	case SERVICE_CONTROL_STOP: 
		service->Stop(); 
		break;
	case SERVICE_CONTROL_PAUSE: 
		service->Pause(); 
		break;
	case SERVICE_CONTROL_CONTINUE: 
		service->Continue(); 
		break;
	case SERVICE_CONTROL_SHUTDOWN: 
		service->Shutdown(); 
		break;
	case SERVICE_CONTROL_INTERROGATE: 
		break;
	default: 
		break;
	}
}

void CServiceBase::Start(DWORD dwArgc, PWSTR *pszArgv)
{
}

//
//   FUNCTION: CServiceBase::Stop()
//
//   PURPOSE: The function stops the service. It calls the OnStop virtual 
//   function in which you can specify the actions to take when the service 
//   stops. If an error occurs, the error will be logged in the Application 
//   event log, and the service will be restored to the original state.
//
void CServiceBase::Stop() 
{
}

void CServiceBase::Pause()
{
}

void CServiceBase::Continue()
{
}

void CServiceBase::Shutdown()
{
}
