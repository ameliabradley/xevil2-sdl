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

#ifndef _SPECIALCONTROLS_H
#define _SPECIALCONTROLS_H

class CSpecialEdit:public CEdit
{
   DECLARE_DYNAMIC( CSpecialEdit )
public:
    CSpecialEdit(){};
    virtual void SpecialOnLButtonDown( UINT nFlags, CPoint &point ){CEdit::OnLButtonDown(nFlags,point);}
    virtual void SpecialOnLButtonUp( UINT nFlags, CPoint &point ){CEdit::OnLButtonUp(nFlags,point);}
    virtual void SpecialOnKeyDown( UINT nChar, UINT nRepCnt, UINT nFlags ){CEdit::OnKeyDown(nChar,nRepCnt,nFlags );}
    virtual void SpecialOnKeyUp( UINT nChar, UINT nRepCnt, UINT nFlags ){CEdit::OnKeyUp(nChar,nRepCnt,nFlags );}
    virtual void SpecialOnChar( UINT nChar, UINT nRepCnt, UINT nFlags ){CEdit::OnChar(nChar,nRepCnt,nFlags );}
protected:
};


class CSpecialButton :public CButton
{
   DECLARE_DYNAMIC( CSpecialButton )
public:
    CSpecialButton();
	//{{AFX_MSG(CPicturePushButton)
    afx_msg void OnLButtonDown( UINT nFlags, CPoint point );
    afx_msg void OnLButtonUp( UINT nFlags, CPoint point );
    afx_msg void OnMouseMove( UINT nFlags, CPoint point );
	//}}AFX_MSG
    virtual void SpecialOnLButtonDown( UINT nFlags, CPoint &point ){OnLButtonDown(nFlags,point);}
    virtual void SpecialOnLButtonUp( UINT nFlags, CPoint &point ){OnLButtonUp(nFlags,point);}
    virtual void SpecialOnMouseMove( UINT nFlags, CPoint &point ){OnMouseMove(nFlags,point);}
protected:
    BOOL m_state;
    DECLARE_MESSAGE_MAP( )
};

class CPicturePushButton :public CSpecialButton
{
public:
    CPicturePushButton();
    void setPictureId(UINT p_resourceid){m_pictureid=p_resourceid;}
	//{{AFX_MSG(CPicturePushButton)
    afx_msg void OnLButtonDown( UINT nFlags, CPoint point );
    afx_msg void OnLButtonUp( UINT nFlags, CPoint point );
    afx_msg void OnMouseMove( UINT nFlags, CPoint point );
	//}}AFX_MSG
    virtual void SpecialOnLButtonDown( UINT nFlags, CPoint &point ){OnLButtonDown(nFlags,point);}
    virtual void SpecialOnLButtonUp( UINT nFlags, CPoint &point ){OnLButtonUp(nFlags,point);}
    virtual void SpecialOnMouseMove( UINT nFlags, CPoint &point ){OnMouseMove(nFlags,point);}
private:
    virtual void DrawItem(LPDRAWITEMSTRUCT);
    UINT m_pictureid;
    CBitmap m_bitmap;
    BOOL m_init;
    DECLARE_MESSAGE_MAP( )
};

#endif //_SPECIALCONTROLS_H


