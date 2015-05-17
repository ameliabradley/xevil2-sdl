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

// KeyHitDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// KeyHitDlg dialog

class KeyHitDlg : public CDialog
{
// Construction
public:
	KeyHitDlg(CWnd* pParent = NULL);   // standard constructor
    unsigned char getChar(){return m_Dchar;}
// Dialog Data
	//{{AFX_DATA(KeyHitDlg)
	enum { IDD = IDD_KEYHIT };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(KeyHitDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(KeyHitDlg)
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL OnInitDialog();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
    unsigned char m_Dchar;
    static LRESULT CALLBACK KeyhitKeyboardProc(int code,	WPARAM wParam, LPARAM lParam);
    void keyHit(WPARAM wParam, LPARAM lParam);
    static HHOOK m_hhk;
    static KeyHitDlg *m_hack;
};
