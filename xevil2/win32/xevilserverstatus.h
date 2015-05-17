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

// XEvilServerStatus.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CXEvilServerStatus dialog

#include "specialcontrols.h"



class CXEvilServerStatus : public CWnd 
{
   DECLARE_DYNAMIC( CXEvilServerStatus )
// Construction
    static ATOM atom;

public:
    enum {SERVER_VIEW_WIDTH=230,SERVER_VIEW_HEIGHT=36,SERVER_VIEW_HEIGHT_BIG=300};
	CXEvilServerStatus();   // standard constructor


    BOOL Create(CRect &p_rect,CWnd *p_parent);
    LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam){return CWnd::DefWindowProc(message,wParam,lParam);}
    BOOL getClose(){return m_close;}
    void setClose(BOOL p_close){m_close=p_close;}
    int getWindowList(CTypedPtrList<CPtrList,CWnd *>&p_windowlist);
    void toggleDisplay();
    void getMessage(CString &p_string);
    void clearMessage();
    void addLog(const CString &p_string);
    void clearLog();
    void setTimeSpan(CString &p_string);
    void setNumPlayers(int t_numplayers);
    //superwndinterface
    LRESULT SuperWindowProc( UINT message, WPARAM wParam, LPARAM lParam ){return CWnd::WindowProc(message,wParam,lParam);}
    
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXEvilServerStatus)
	protected:
	//}}AFX_VIRTUAL

// Implementation
protected:
    CPicturePushButton m_startserver;
    CPicturePushButton m_stopserver;
    CPicturePushButton m_settings;
    CStatic m_numberofplayers;
    CStatic m_timeconnected;
    CSpecialButton m_moredisplaycontrol;

    CSpecialEdit m_editcontrol;
    CSpecialEdit m_messagecontrol;
    CFont m_font;
    BOOL m_close;
    HCURSOR m_cursor;
    HCURSOR m_oldcursor;
    CStatic m_static1;
    CStatic m_static2;

    enum TOGGLE_STATE{SMALL=0,BIG=1}  m_togglestate;
	// Generated message map functions
	//{{AFX_MSG(CXEvilServerStatus)
	afx_msg void OnDisplay();
	afx_msg void OnStartserver();
	afx_msg void OnStopserver();
	afx_msg void OnSettings();
	afx_msg void OnClose( );
    afx_msg void OnLButtonDown( UINT nFlags, CPoint point );
    afx_msg void OnLButtonUp( UINT nFlags, CPoint point );
    afx_msg void OnPaint();
    afx_msg BOOL OnSetCursor( CWnd*, UINT, UINT );
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
