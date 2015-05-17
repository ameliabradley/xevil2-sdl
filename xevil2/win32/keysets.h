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

// KeySets.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKeySets dialog

class CKeySets : public CDialog
{
// Construction
public:
	CKeySets(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CKeySets)
	enum { IDD = IDD_KEYSETS };
	CButton	m_weaponusebutton;
	CButton	m_weapondropbutton;
	CButton	m_weaponchangebutton;
	CButton	m_upperrightbutton;
	CButton	m_upperbutton;
	CButton	m_upperleftbutton;
	CButton	m_rightbutton;
	CButton	m_lowerrightbutton;
	CButton	m_lowerleftbutton;
	CButton	m_leftbutton;
	CButton	m_itemusebutton;
	CButton	m_itemdropbutton;
	CButton	m_itemchangebutton;
	CButton	m_downbutton;
	CButton	m_centerbutton;
	CButton	m_chatbutton;
	CString	m_playerstaticvalue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeySets)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
private:
	char  m_Dweaponusechar;
	char	m_Dweapondropchar;
	char	m_Dweaponchangechar;
	char	m_Dupperrightchar;
	char	m_Dupperchar;
	char	m_Dupperleftchar;
	char	m_Drightchar;
	char	m_Dlowerrightchar;
	char	m_Dlowerleftchar;
	char	m_Dleftchar;
	char	m_Ditemusechar;
	char	m_Ditemdropchar;
	char	m_Ditemchangechar;
	char	m_Ddownchar;
	char	m_Dcenterchar;
	char	m_Dchatchar;
	CString	m_Dplayerstaticvalue;
  CString translateChar(unsigned char p_char);

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CKeySets)
	afx_msg void OnUp();
	afx_msg void OnUr();
	afx_msg void OnWeaponchange();
	afx_msg void OnWeaponuse();
	afx_msg void OnWeapondrop();
	virtual void OnOK();
	afx_msg void OnCenter();
	afx_msg void OnDown();
	afx_msg void OnItemchange();
	afx_msg void OnItemdrop();
	afx_msg void OnItemuse();
	afx_msg void OnL();
	afx_msg void OnLl();
	afx_msg void OnLr();
	afx_msg void OnR();
	afx_msg void OnUl();
	afx_msg void OnChat();
	virtual BOOL OnInitDialog();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
  void setUpChar(char p_char);
  void setUpLeftChar(char p_char);
  void setUpRightChar(char p_char);
  void setLeftChar(char p_char);
  void setRightChar(char p_char);
  void setCenterChar(char p_char);
  void setDownChar(char p_char);
  void setDownLeftChar(char p_char);
  void setDownRightChar(char p_char);
  void setWeaponUse(char p_char);
  void setWeaponChange(char p_char);
  void setWeaponDrop(char p_char);
  void setItemUse(char p_char);
  void setItemChange(char p_char);
  void setItemDrop(char p_char);
  void setChat(char p_char);
  void setIndex(int p_index){m_index=p_index;}

  int getIndex(){return m_index;}
  char getUpChar();
  char getUpLeftChar();
  char getUpRightChar();
  char getLeftChar();
  char getRightChar();
  char getCenterChar();
  char getDownChar();
  char getDownLeftChar();
  char getDownRightChar();
  char getWeaponUse();
  char getWeaponChange();
  char getWeaponDrop();
  char getItemUse();
  char getItemChange();
  char getItemDrop();
  char getChat();

  void setText(CString &p_string){m_Dplayerstaticvalue=p_string;}

  BOOL getChanged(){return m_changed;};
private:
  CButton *m_pbutton;
  char *m_pchar;
  BOOL m_changed;
  int m_index;//used for player 0,1 needed for modaless input, trust me
};
