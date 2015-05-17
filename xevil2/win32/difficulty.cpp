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

// Difficulty.cpp : implementation file
//

#include "stdafx.h"
#include "xevil.h"
#include "Difficulty.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDifficulty dialog


CDifficulty::CDifficulty(CWnd* pParent /*=NULL*/)
	: CDialog(CDifficulty::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDifficulty)
	m_difficulty = -1;
	//}}AFX_DATA_INIT
  m_Ddifficulty=DIFF_NORMAL;
}


void CDifficulty::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDifficulty)
	DDX_Radio(pDX, IDC_DIFFICULTY1, m_difficulty);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDifficulty, CDialog)
	//{{AFX_MSG_MAP(CDifficulty)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDifficulty message handlers

void CDifficulty::OnOK() 
{
  UpdateData(TRUE);
	switch (m_difficulty)
  {
    case 0:m_Ddifficulty=DIFF_TRIVIAL;   break;
    case 1:m_Ddifficulty=DIFF_NORMAL;    break;
    case 2:m_Ddifficulty=DIFF_HARD;      break;
    case 3:m_Ddifficulty=DIFF_BEND_OVER; break;
    default: m_Ddifficulty=DIFF_NORMAL;assert(0);break;
  }
#ifdef MODELESS_DIALOGS
  PostMessage(WM_COMMAND,IDOK,0);
#else
  CDialog::OnOK();
#endif
}



void CDifficulty::OnCancel() 
{
#ifdef MODELESS_DIALOGS
  PostMessage(WM_COMMAND,IDCANCEL,0);
#else
  CDialog::OnCancel();
#endif
}



BOOL CDifficulty::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	switch (m_Ddifficulty)
  {
    case DIFF_TRIVIAL: m_difficulty=0; break;
    case DIFF_NORMAL: m_difficulty=1;  break;
    case DIFF_HARD: m_difficulty=2;  break;
    case DIFF_BEND_OVER: m_difficulty=3;  break;
    default: m_difficulty=0;assert(0);break;
  }
  UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

