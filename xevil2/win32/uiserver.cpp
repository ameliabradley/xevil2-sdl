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

#include "stdafx.h"
#include "ui.h"
#include "uiserver.h"
#include "resource.h"
#include "optionsdlg.h"
#include "aboutdialog.h"

UiServer::UiServer(LocatorP p_locator)
{
    locator=p_locator;
    if (!m_serverwnd.Create(CRect(10,10,0,0),NULL))
        m_serverwnd.setClose(TRUE);
    else
    {
        CRect t_clientrect;
        CRect t_windowrect;
        int t_ydiff;
        int t_xdiff;
        m_serverwnd.GetClientRect(t_clientrect);
        m_serverwnd.GetWindowRect(t_windowrect);
        t_ydiff=CXEvilServerStatus::SERVER_VIEW_HEIGHT-t_clientrect.Height();
        t_xdiff=CXEvilServerStatus::SERVER_VIEW_WIDTH-t_clientrect.Width();
        m_serverwnd.SetWindowPos(NULL,0,0,t_windowrect.Width()+t_xdiff,t_windowrect.Height()+t_ydiff,SWP_NOZORDER|SWP_NOMOVE|SWP_NOREDRAW);
        m_serverwnd.ShowWindow(SW_SHOWNORMAL);
//        settingsChanges = UIpause;
//        settings.pause=TRUE;
    }
    m_starttime=CTime::GetCurrentTime();
    m_serverwnd.SetTimer(ID_TIMER,1000,NULL);
}



UiServer::~UiServer()
{
}


void UiServer::pre_clock()
{
  if (m_serverwnd.getClose())
    settingsChanges |= UIquit;
  char *arenaMsg;
  Boolean exclusive;
  do {
    CString t_output;
    IntelId msgTarget;
    IntelP  inteltarget;
    Quanta time;
    Boolean propagate;
    exclusive = locator->arena_message_deq(&arenaMsg,msgTarget,time,propagate);
    if (arenaMsg)
    {
      // Go through all viewports, setting message on appropriate ones.
        if (exclusive)
        {
            inteltarget=locator->lookup(msgTarget);
            if (inteltarget)
            {
                t_output+="(";
                t_output+=inteltarget->get_name();
                t_output+=")  ";
            }
        }
        t_output+=arenaMsg;
        m_serverwnd.addLog(t_output);
      delete arenaMsg;
    }
  } while(arenaMsg);
}



void UiServer::post_clock() {
}



int
UiServer::getWindowList(CTypedPtrList<CPtrList,CWnd *>&p_windowlist)
{
  p_windowlist.RemoveAll();
  p_windowlist.AddTail(&m_serverwnd);
  return p_windowlist.GetCount();         
}




Boolean ///break in event handling. False== stop checking
UiServer::process_event(int dpyNum,CMN_EVENTDATA eventdata)//change dpynum to vnum test for WM_ messages
{
  CRect t_updaterect;
  CWnd *t_wnd=CWnd::FromHandle(eventdata.m_event.hwnd);

  switch(eventdata.m_event.message) {
  case WM_LBUTTONDOWN:
      if (t_wnd->IsKindOf( RUNTIME_CLASS( CSpecialButton ) ) )
      {
          CPoint t_point(LOWORD(eventdata.m_event.lParam),HIWORD(eventdata.m_event.lParam));
          ((CSpecialButton *)t_wnd)->SpecialOnLButtonDown( eventdata.m_event.wParam, t_point );
          t_wnd->SetFocus();
      }
      else if (t_wnd->IsKindOf( RUNTIME_CLASS( CSpecialEdit ) ) )
      {
        t_wnd->SendMessage(eventdata.m_event.message, eventdata.m_event.wParam, eventdata.m_event.lParam);
      }
      else
        ::DefWindowProc(eventdata.m_event.hwnd,eventdata.m_event.message, eventdata.m_event.wParam, eventdata.m_event.lParam);
      break;
  case WM_LBUTTONUP:
      if (t_wnd->IsKindOf( RUNTIME_CLASS( CSpecialButton ) ) )
      {
          CPoint t_point(LOWORD(eventdata.m_event.lParam),HIWORD(eventdata.m_event.lParam));
          ((CSpecialButton *)t_wnd)->SpecialOnLButtonUp( eventdata.m_event.wParam, t_point );
      }
      else if (t_wnd->IsKindOf( RUNTIME_CLASS( CSpecialEdit ) ) )
      {
        t_wnd->SendMessage(eventdata.m_event.message, eventdata.m_event.wParam, eventdata.m_event.lParam);
/*          CPoint t_point(LOWORD(eventdata.m_event.lParam),HIWORD(eventdata.m_event.lParam));
          ((CSpecialEdit *)t_wnd)->SpecialOnLButtonUp( eventdata.m_event.wParam, t_point );*/
      }
      else
        ::DefWindowProc(eventdata.m_event.hwnd,eventdata.m_event.message, eventdata.m_event.wParam, eventdata.m_event.lParam);

      break;
  case WM_MOUSEMOVE:

      if (t_wnd->IsKindOf( RUNTIME_CLASS( CSpecialButton ) ) )
      {
          CPoint t_point(LOWORD(eventdata.m_event.lParam),HIWORD(eventdata.m_event.lParam));
          ((CSpecialButton *)t_wnd)->SpecialOnMouseMove( eventdata.m_event.wParam, t_point );
      }
      else if (t_wnd->IsKindOf( RUNTIME_CLASS( CSpecialEdit ) ) )
      {
        t_wnd->SendMessage(eventdata.m_event.message, eventdata.m_event.wParam, eventdata.m_event.lParam);
      }
      else
        ::DefWindowProc(eventdata.m_event.hwnd,eventdata.m_event.message, eventdata.m_event.wParam, eventdata.m_event.lParam);
      break;
  case WM_KEYDOWN:
    if (TranslateMessage(&eventdata.m_event))
      break;
  case WM_CHAR:
      if (t_wnd->IsKindOf( RUNTIME_CLASS( CSpecialEdit ) ) )
      {
          if ((TCHAR)eventdata.m_event.wParam=='\r')
          {
              if (t_wnd->GetOwner())
                  t_wnd->GetOwner()->PostMessage(WM_COMMAND,t_wnd->GetDlgCtrlID());
              break;
          }
      }
  case WM_KEYUP:
  case WM_SETCURSOR:
      t_wnd->SendMessage(eventdata.m_event.message,eventdata.m_event.wParam, eventdata.m_event.lParam);
  case WM_TIMER:
      {
          CTime t_time=CTime::GetCurrentTime();
          CTimeSpan t_timespan=t_time-m_starttime;
          CString t_formattedstring=t_timespan.Format("%D:%H:%M:%S");
          m_serverwnd.setTimeSpan(t_formattedstring);
          m_serverwnd.setNumPlayers(locator->humans_playing());
      }
    break;
  case WM_PAINT:
    if (IsIconic(eventdata.m_parent))
    {
      SendMessage(eventdata.m_parent,WM_PAINT,NULL,NULL);
      return TRUE;
    }
    t_wnd->SendMessage(WM_PAINT,eventdata.m_event.wParam,eventdata.m_event.lParam);
    break;
  case WM_SETFOCUS:
    t_wnd->SetFocus();
    break;
/*  case WM_ACTIVATE:
      ::SendMessage(eventdata.m_parent,WM_ACTIVATE,eventdata.m_event.wParam,eventdata.m_event.lParam);
      break;*/
  case WM_CLOSE: case WM_DESTROY:    
    settingsChanges |= UIquit;
    break;
  case WM_COMMAND:
    switch (LOWORD(eventdata.m_event.wParam))
    {
      case IDC_SETTINGS:
      {
        OptionsDlg t_options;
        t_options.setStyle(settings.style);

        // Will always be R_SERVER.
        t_options.setRoleType(R_SERVER);

        t_options.setNumHumans(settings.humansNum);
        t_options.setNumMachines(settings.enemiesNum);
        t_options.setRefillMachines(settings.enemiesRefill);
        t_options.setRoomsWide(settings.worldRooms.acrossMax);
        t_options.setRoomsHigh(settings.worldRooms.downMax);
        t_options.setCooperative(settings.cooperative);
        if (settings.quanta>100)
          settings.quanta=100;
        t_options.setSndTrkVolume(settings.trackvol);
        t_options.setEffectsVolume(settings.soundvol);
        t_options.setGameSpeed(settings.quanta);
        t_options.setMusicType(settings.musictype);
        t_options.setSoundOnOff(settings.sound);
        if (t_options.DoModal()==IDOK)
        {
          if (t_options.getStyle()!= settings.style)
            settingsChanges |= UIstyle;
          if (t_options.getNumMachines()!= settings.enemiesNum)
            settingsChanges |= UIenemiesNum;
          if (t_options.getRefillMachines()!= settings.enemiesRefill)
            settingsChanges |= UIenemiesRefill;
          if (t_options.getNumHumans()!= settings.humansNum)
            settingsChanges |= UIhumansNum;
          if (t_options.getRoomsWide()!= settings.worldRooms.acrossMax)
            settingsChanges |= UIrooms;
          if (t_options.getRoomsHigh()!= settings.worldRooms.downMax)
            settingsChanges |= UIrooms;
          if (t_options.getGameSpeed()!= settings.quanta)
            settingsChanges |= UIquanta;
          if (t_options.getEffectsVolume()!= settings.soundvol)
            settingsChanges |= UIsoundvol;
          if (t_options.getSndTrkVolume()!= settings.trackvol)
            settingsChanges |= UItrackvol;
          if (t_options.getMusicType()!= settings.musictype)
            settingsChanges |= UImusictype;
          if (t_options.getSoundOnOff() != settings.sound)
            settingsChanges |= UIsound;
          if (t_options.getCooperative() != settings.cooperative)
            settingsChanges |= UIcooperative;
          settings.sound = t_options.getSoundOnOff();
          settings.style = t_options.getStyle();
          settings.humansNum=t_options.getNumHumans();
          settings.enemiesNum=t_options.getNumMachines();
          settings.enemiesRefill=t_options.getRefillMachines();
          settings.worldRooms.acrossMax=t_options.getRoomsWide();
          settings.worldRooms.downMax=t_options.getRoomsHigh();
          settings.quanta=t_options.getGameSpeed();/*0-100*/
          settings.soundvol=t_options.getEffectsVolume();
          settings.trackvol=t_options.getSndTrkVolume();
          settings.musictype=t_options.getMusicType();
          settings.cooperative=t_options.getCooperative();
        }
        SendMessage(eventdata.m_event.hwnd,WM_PAINT,0,0);
        m_serverwnd.SetFocus();
        break;			
      }
      case ID_APP_EXIT :
        settingsChanges |= UIquit;
        break;
      case ID_APP_ABOUT :
        {
          AboutDialog t_about;
          t_about.DoModal();
          m_serverwnd.SetFocus();
          break;
        }
      case IDC_STARTSERVER:
        settingsChanges |= UInewGame;
//        settingsChanges |= UIpause;
//        settings.pause=FALSE;
        break;
      case IDC_STOPSERVER:
#if 0
        // We probably don't want to pause, 
        // really want a UIendGame that std::ends the game 
        // without starting a new one.
        settingsChanges |= UIpause;
        settings.pause=TRUE;
#endif
        settingsChanges |= UIquit;
        break;
      case IDC_DISPLAY:
        m_serverwnd.toggleDisplay();
        break;
      case IDC_MESSAGEDISPLAY:
        {
            //send another message...
            CString t_string;
            m_serverwnd.getMessage(t_string);
            m_serverwnd.addLog(t_string);
            m_serverwnd.clearMessage();
        }
        break;
      default :
        assert(FALSE);
        return FALSE;
    }


    default:
//      if (t_wnd->IsKindOf( RUNTIME_CLASS( CSpecialEdit ) ) )
//      {
//        t_wnd->SendMessage(eventdata.m_event.message, eventdata.m_event.wParam, eventdata.m_event.lParam);
//      }
//      else
        ::DefWindowProc(eventdata.m_event.hwnd,eventdata.m_event.message, eventdata.m_event.wParam, eventdata.m_event.lParam);
        break;
  }
    return TRUE;
}



void UiServer::set_level(const char *p_levelname)
{
#if 0
    CString t_string("### NEW LEVEL ###\r\n");
    m_serverwnd.addLog(t_string);
#endif
}


