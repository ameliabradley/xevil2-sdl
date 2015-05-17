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

// AboutDialog.cpp : implementation file
//

#include "stdafx.h"
#include "XEvil.h"
#include "AboutDialog.h"
#include "l_agreement.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AboutDialog dialog


AboutDialog::AboutDialog(CWnd* pParent /*=NULL*/)
	: CDialog(AboutDialog::IDD, pParent)
{
  //{{AFX_DATA_INIT(AboutDialog)
  m_fullscreenvalue = FALSE;
	m_versionvalue = _T("");
	m_licensetextvalue = _T("");
	m_drawbackgroundvalue = FALSE;
	//}}AFX_DATA_INIT
  m_Dfullscreenmode=FALSE;
  m_Denablefullscreen=FALSE;
  m_Ddrawbackground=TRUE;
  m_Denabledrawbackground=FALSE;
  m_Denablereject = TRUE;
}


void AboutDialog::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(AboutDialog)
	DDX_Control(pDX, IDC_DRAWBACKGROUND, m_drawbackgroundcontrol);
	DDX_Control(pDX, IDCANCEL, m_rejectcontrol);
	DDX_Control(pDX, IDC_LICENSETEXT, m_licensetextcontrol);
  DDX_Control(pDX, IDC_FULLSCREEN, m_fullscreencontrol);
  DDX_Check(pDX, IDC_FULLSCREEN, m_fullscreenvalue);
	DDX_Text(pDX, IDC_VERSION, m_versionvalue);
	DDX_Text(pDX, IDC_LICENSETEXT, m_licensetextvalue);
	DDX_Check(pDX, IDC_DRAWBACKGROUND, m_drawbackgroundvalue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AboutDialog, CDialog)
  //{{AFX_MSG_MAP(AboutDialog)
	ON_EN_SETFOCUS(IDC_LICENSETEXT, OnSetfocusLicensetext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// AboutDialog message handlers

BOOL AboutDialog::OnInitDialog() 
{
  CDialog::OnInitDialog();

  CenterWindow();
  m_fullscreencontrol.EnableWindow(m_Denablefullscreen);
  m_fullscreenvalue=m_Dfullscreenmode;
  m_drawbackgroundcontrol.EnableWindow(m_Denabledrawbackground);
  m_drawbackgroundvalue=m_Ddrawbackground;
  m_rejectcontrol.EnableWindow(m_Denablereject);
  UpdateData(FALSE);

  return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void AboutDialog::OnOK() 
{
  UpdateData(TRUE);
	m_Dfullscreenmode=m_fullscreenvalue;
  m_Ddrawbackground=m_drawbackgroundvalue;
#ifdef MODELESS_DIALOGS
  if (!m_Denablefullscreen)
    PostMessage(WM_COMMAND,IDOK,0);
#else
	CDialog::OnOK();
#endif
}


void AboutDialog::OnCancel() 
{
  m_licensetextcontrol.SetSel(-1,0,TRUE);
	CDialog::OnCancel();
}



void AboutDialog::setVersionString(const char* version) {
  m_versionvalue = "XEvil(TM) ";
  m_versionvalue += version;
//  m_versionvalue += "  (Shareware)";
}



void AboutDialog::setLicenseText(const char* text) {
  m_licensetextvalue = "";

  // Parse the text into fixed width columns of lines of text.
  // 80 column.
  Line::set_text_columns(80);
  // Do the parse.
  Page thePage(NULL,text);
  // Recreate the license text from the parsed text.
  const PtrList& lines = thePage.get_lines();
  for (int n = 0; n < lines.length(); n++) {
    int length;
    const char* txt = ((Line*)lines.get(n))->get_text(length);
    CString cstr(txt,length);
    m_licensetextvalue += cstr;
    if (n < lines.length() - 1) {
      m_licensetextvalue += "\r\n";
    }
  }
}

void AboutDialog::OnSetfocusLicensetext() 
{
  m_licensetextcontrol.SetSel(-1,0);
}
