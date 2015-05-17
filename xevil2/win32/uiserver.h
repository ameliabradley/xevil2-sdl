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

#ifndef _UISERVER_H
#define _UISERVER_H

#include "xevilserverstatus.h"
// Class Declarations
class UiServer: public Ui {
public:
  enum {SOUNDTRACKTIMER_CD=666,SOUNDTRACKTIMER_MIDI=667};
  UiServer(LocatorP);  
  ~UiServer();

  void pre_clock();
  /* EFFECTS: Follows the object of the registered intel if any and redraws 
  the world and locator. */

  void post_clock();

  int getWindowList(CTypedPtrList<CPtrList,CWnd *>&p_windowlist);
  Boolean process_event(int dpyNum,CMN_EVENTDATA eventdata);//return if handled
  void set_level(const char *p_levelname);
private:
    CXEvilServerStatus m_serverwnd;
    LocatorP locator;
    CTime m_starttime;
};

#endif //_UISERVER_H

