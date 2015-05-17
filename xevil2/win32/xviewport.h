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

//XViewPort.h
#ifndef _XEVILPORTH
#define _XEVILPORTH
#include <afxext.h>//for status bar
#include "intel.h"



class CXEvilButton :public CButton
{
public:
        CXEvilButton(){}
private:
        virtual void DrawItem(LPDRAWITEMSTRUCT);
};



class CXEvilIndentedButton :public CButton
{
public:
        CXEvilIndentedButton(){}
private:
        virtual void DrawItem(LPDRAWITEMSTRUCT);
};



// Used for both full-screen and windowed mode.
class CXEvilWnd:public CWnd
{
  BOOL m_redrawflag;
  BOOL m_valid;
  int m_timerid;
  static ATOM atom;
  BOOL m_fullscreen;
  int m_activated;
  BOOL m_querynewpalette;

public:
  enum {WMNONE=0,WMACTIVATED,WMINACTIVE};
  CXEvilWnd(){m_activated=WMNONE;m_redrawflag=FALSE;m_valid=FALSE;m_timerid=-1;}
  virtual ~CXEvilWnd();
  BOOL needRedraw(){return m_redrawflag;}
  void setRedraw(BOOL p_bool){m_redrawflag=p_bool;}
  BOOL isValid(){return m_valid;}
  int  getTimerId(){return m_timerid;}
  void setTimerId(int p_id){m_timerid=p_id;}
  int getActivated(){return m_activated;}
  void setActivated(int p_activated){m_activated=p_activated;}

  void setQueryNewPalette(BOOL p_bool){m_querynewpalette=p_bool;}
  BOOL getQueryNewPalette(){return m_querynewpalette;}


  BOOL Create(CRect &p_rect,CWnd *p_parent,unsigned char p_viewportnum, BOOL p_fullscreen);
  LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam){return CWnd::DefWindowProc(message,wParam,lParam);}

//  void draw_level_string(const char *,HDC hdc);

//message maps
	afx_msg void OnDestroy( );
	afx_msg void OnClose( );
	afx_msg void OnPaint( );
	afx_msg void OnTimer( UINT );
	afx_msg void OnSetFocus( CWnd * );
  afx_msg void OnActivateApp( BOOL bActive, DWORD hTask );
  afx_msg BOOL OnQueryNewPalette( );
//end message maps
  DECLARE_MESSAGE_MAP( )
};



// There is only one StatusWnd now.  So I removed the abstract interface
// to avoid having to change it all the time.

#endif

