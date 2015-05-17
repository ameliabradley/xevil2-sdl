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

#include "coord.h"

// Difficulty.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDifficulty dialog

class CDifficulty : public CDialog
{
// Construction
public:
	CDifficulty(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDifficulty)
	enum { IDD = IDD_DIFFICULTY };
	int		m_difficulty;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDifficulty)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDifficulty)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
  int m_Ddifficulty;
public:
  void setDifficulty(int p_diff){m_Ddifficulty=p_diff;}
  int getDifficulty(){return m_Ddifficulty;}
};
