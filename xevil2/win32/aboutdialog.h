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
// AboutDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AboutDialog dialog

class AboutDialog : public CDialog
{
// Construction
public:
	AboutDialog(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(AboutDialog)
	enum { IDD = IDD_ABOUTBOX };
	CButton	m_drawbackgroundcontrol;
	CButton	m_rejectcontrol;
	CEdit	m_licensetextcontrol;
	CButton	m_fullscreencontrol;
	BOOL	m_fullscreenvalue;
	CString	m_versionvalue;
	CString	m_licensetextvalue;
	BOOL	m_drawbackgroundvalue;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AboutDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AboutDialog)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
  afx_msg void OnSetfocusLicensetext();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
  BOOL m_Dfullscreenmode;
  BOOL m_Denablefullscreen;
  BOOL m_Ddrawbackground;
  BOOL m_Denabledrawbackground;
  BOOL m_Denablereject;
    
public:
  void enableFullScreenButton(BOOL p_bool){m_Denablefullscreen=p_bool;}
  void setFullScreenMode(BOOL p_fullscreenon){m_Dfullscreenmode=p_fullscreenon;}
  BOOL getFullScreenMode(){return m_Dfullscreenmode;}
  void enableReduceDraw(BOOL p_bool){m_Denabledrawbackground=p_bool;}

  void setReduceDraw(BOOL p_val){m_Ddrawbackground = !p_val;}
  BOOL getReduceDraw(){return !m_Ddrawbackground;}
  /* NOTE: Negate the value to convert to/from reduceDraw from/to 
     drawBackground. */

  void setVersionString(const char*);
  void setLicenseText(const char*);
  void setReject(BOOL p_bool = TRUE){m_Denablereject = p_bool;}
};


