#pragma once

#include <Windows.h>

class CServiceBase
{
public:
	// This is the constructor of the service class. The optional parameters 
	// (fCanStop, fCanShutdown and fCanPauseContinue) allow you to specify 
	// whether the service can be stopped, paused and continued, or be 
	// notified when system shutdown occurs.
	CServiceBase(PWSTR pszServiceName,
		BOOL fCanStop = TRUE,
		BOOL fCanShutdown = TRUE,
		BOOL fCanPauseContinue = FALSE);

	// This is the virtual destructor of the service class.
	virtual ~CServiceBase();

	// It register the executable for a service with SCM.
	static BOOL Run(CServiceBase & service);

	// Funtion that stops the service.
	void Stop();

protected:	

	// When implemented in a derived class, executes when a Start command is 
	// sent to the service by the SCM or when the operating system starts 
	// (for a service that starts automatically). Specifies actions to take 
	// when the service starts.
	virtual void OnStart(DWORD dwArgc, PWSTR *pszArgv);

	// When implemented in a derived class, executes when a Stop command is 
	// sent to the service by the SCM. Specifies actions to take when a 
	// service stops running.
	virtual void OnStop();

	// When implemented in a derived class, executes when a Pause command is 
	// sent to the service by the SCM. Specifies actions to take when a 
	// service pauses.
	virtual void OnPause();

	// When implemented in a derived class, OnContinue runs when a Continue 
	// command is sent to the service by the SCM. Specifies actions to take 
	// when a service resumes normal functioning after being paused.
	virtual void OnContinue();

	// When implemented in a derived class, executes when the system is 
	// shutting down. Specifies what should occur immediately prior to the 
	// system shutting down.
	virtual void OnShutdown();

	// Set the service status and report the status to the SCM.
	void SetServiceStatus(DWORD dwCurrentState,
		DWORD dwWin32ExitCode = NO_ERROR,
		DWORD dwWaitHint = 0);

	// Log a message to the Application event log.
	void WriteEventLogEntry(PWSTR pszMessage, WORD wType);

	// Log an error message to the Application event log.
	void WriteErrorLogEntry(PWSTR pszFunction,
		DWORD dwError = GetLastError());
};

