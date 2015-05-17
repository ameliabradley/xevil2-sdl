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

// TimeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "XEvil.h"
#include "TimeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// TimeStampFailedDlg dialog


TimeStampFailedDlg::TimeStampFailedDlg(CWnd* pParent /*=NULL*/)
	: CDialog(TimeStampFailedDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(TimeStampFailedDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void TimeStampFailedDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TimeStampFailedDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TimeStampFailedDlg, CDialog)
	//{{AFX_MSG_MAP(TimeStampFailedDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TimeStampFailedDlg message handlers


void TimeStampFailedDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	MessageBox("Yeah, right.");
	CDialog::OnCancel();
}
