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

// RunServerDlg.h : header file
//
#include "utils.h"

/////////////////////////////////////////////////////////////////////////////
// CRunServerDlg dialog

class CRunServerDlg : public CDialog
{
// Construction
public:
	CRunServerDlg(CWnd* pParent = NULL);   // standard constructor

  Boolean get_local_human();
  CMN_PORT get_port() {return m_port;}
  const char* get_name() {return m_name;}

// Dialog Data
	//{{AFX_DATA(CRunServerDlg)
	enum { IDD = IDD_RUNSERVER };
	CEdit	m_nameControl;
	UINT	m_port;
	int		m_playerObserver;
	CString	m_name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRunServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
private:

	// Generated message map functions
	//{{AFX_MSG(CRunServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPlayer();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

  void UpdateEnabled();
};
