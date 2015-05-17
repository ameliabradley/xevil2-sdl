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

// KeyHitDlg.cpp : implementation file


#include "stdafx.h"
#include "xevil.h"
#include "KeyHitDlg.h"

/*#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif*/

HHOOK KeyHitDlg::m_hhk;
KeyHitDlg * KeyHitDlg::m_hack;

/////////////////////////////////////////////////////////////////////////////
// KeyHitDlg dialog


KeyHitDlg::KeyHitDlg(CWnd* pParent /*=NULL*/)
: CDialog(KeyHitDlg::IDD, pParent)
{
  //{{AFX_DATA_INIT(KeyHitDlg)
  //}}AFX_DATA_INIT
}


void KeyHitDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(KeyHitDlg)
  //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(KeyHitDlg, CDialog)
//{{AFX_MSG_MAP(KeyHitDlg)
ON_WM_KEYUP()
ON_WM_KEYDOWN()
ON_WM_CHAR()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// KeyHitDlg message handlers

void KeyHitDlg::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
  // TODO: Add your message handler code here and/or call default
  m_Dchar=nChar;
  CDialog::OnKeyUp(nChar, nRepCnt, nFlags);
  EndDialog(IDOK);
}

void KeyHitDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
  // TODO: Add your message handler code here and/or call default
  m_Dchar=nChar;
  EndDialog(IDOK);
  CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL KeyHitDlg::OnInitDialog() 
{
  CDialog::OnInitDialog();

  // TODO: Add extra initialization here
  SetFocus();
  SetCapture();
  m_hack=this;
  m_hhk=SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)KeyhitKeyboardProc,
    AfxGetInstanceHandle(),AfxGetThread()->m_nThreadID);
 

  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION: OCX Property Pages should return FALSE
}

void KeyHitDlg::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
  // TODO: Add your message handler code here and/or call default
  m_Dchar=nChar;
  EndDialog(IDOK);
  CDialog::OnChar(nChar, nRepCnt, nFlags);
}



void KeyHitDlg::keyHit(WPARAM wParam, LPARAM lParam)
{
  m_Dchar=(unsigned char)wParam;
  EndDialog(IDOK);
}



LRESULT CALLBACK 
KeyHitDlg::KeyhitKeyboardProc(int code,	WPARAM wParam, LPARAM lParam)
{
  UnhookWindowsHookEx(m_hhk);
  m_hack->keyHit(wParam,lParam);
  return ::CallNextHookEx(m_hhk,code,	wParam,lParam); 
}
