/****************************** Module Header ******************************\
* Module Name:  ServiceBase.h
* Project:      CppWindowsService
* Copyright (c) Microsoft Corporation.
*
* Provides a base class for a service that will exist as part of a service
* application. CServiceBase must be derived from when creating a new service
* class.
*
* This source is subject to the Microsoft Public License.
* See http://www.microsoft.com/en-us/openness/resources/licenses.aspx#MPL.
* All other rights reserved.
*
* THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
* EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
\***************************************************************************/

#pragma once

class CServiceBase 
{
public:

	// Service object constructor. The optional parameters (fCanStop, 
	// fCanShutdown and fCanPauseContinue) allow you to specify whether the 
	// service can be stopped, paused and continued, or be notified when 
	// system shutdown occurs.
	CServiceBase(PWSTR pszServiceName,
		BOOL fCanStop = TRUE,
		BOOL fCanShutdown = TRUE,
		BOOL fCanPauseContinue = FALSE);

	// Service object destructor. 
	virtual ~CServiceBase(void);

	// Register the executable for a service with the Service Control Manager 
	// (SCM). After you call Start(ServiceBase), the SCM issues a Start command, 
	// which results in a call to the OnStart method in the service. This 
	// method blocks until the service has stopped.
	static BOOL Start(CServiceBase &service);

private:

	// The singleton service instance.
	static CServiceBase *service;

	// Entry point for the service. It registers the handler function for the 
	// service and starts the service.
	static void WINAPI ServiceMain(DWORD dwArgc, LPWSTR *lpszArgv);

	// The function is called by the SCM whenever a control code is sent to 
	// the service.
	static void WINAPI ServiceCtrlHandler(DWORD dwCtrl);


private:
	// The name of the service
	PWSTR m_Name;

	// The status of the service
	SERVICE_STATUS m_Status;

	// The service status handle
	SERVICE_STATUS_HANDLE m_StatusHandle;


private:
	// Start the service.
	void Start(DWORD dwArgc, PWSTR *pszArgv);

	// Stop the service.
	void Stop();

	// Pause the service.
	void Pause();

	// Resume the service after being paused.
	void Continue();

	// Execute when the system is shutting down.
	void Shutdown();

};

