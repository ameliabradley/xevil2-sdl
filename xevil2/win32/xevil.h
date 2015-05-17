/*
 *  XEvil(TM) Copyright (C) 1994,1999  Steve Hardt and Michael Judge
 *  
 *  The file, license.txt, distributed along with this source code contains
 *  the license agreement for the XEvil source code and executable.
 *  If you do not have this file, obtain a copy from 
 *  http://www.xevil.com/docs/license.txt
 * 
 *  http://www.xevil.com
 *  satan@xevil.com
 */

// XEvil.h : main header file for the XEVIL application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CXEvilApp:
// See XEvil.cpp for the implementation of this class
//
class Game;

class CXEvilApp : public CWinApp
{
public:
	CXEvilApp();
	virtual ~CXEvilApp();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXEvilApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual void StartSDL();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CXEvilApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
    BOOL timeStampcheck();
    void prepareCommandLine(const CString &p_commandline,int &p_argc, char **&p_argv);
	Game *m_game;
};


/////////////////////////////////////////////////////////////////////////////

extern CXEvilApp theApp;
