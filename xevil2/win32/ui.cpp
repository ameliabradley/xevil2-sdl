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

// "ui.C"
// TAG: UI
// Also has class Panel.

#include "stdafx.h"
// Include Files
#include "utils.h"

#include <iostream>
#include <strstream>

#include "xdata.h"
#include "coord.h"
#include "world.h"
#include "locator.h"
#include "id.h"
#include "physical.h"
#include "ui.h"
#include "uiplayer.h"



Ui::Ui() {
  settingsChanges = UInone;
}



Ui::~Ui() {
}



int Ui::getWindowList(CTypedPtrList<CPtrList,CWnd *>&p_windowlist) {
  return 0;
}



int Ui::get_viewports_num() {
  return 0;
}



int Ui::get_dpy_max(){
  return 0;
}



UImask Ui::get_settings(UIsettings &s) {
  s = settings; 
  UImask tmp = settingsChanges;
  settingsChanges = UInone;
  return tmp;
}



void Ui::set_humans_num(int val)
{
  settings.humansNum=val;
}



void Ui::set_enemies_num(int val)
{
  settings.enemiesNum = val;
}



void Ui::set_enemies_refill(BOOL val)
{
  settings.enemiesRefill = val;
}



void Ui::set_sound_onoff(BOOL val)
{
  settings.sound=val;
}



void Ui::set_sound_volume(int val)
{
  settings.soundvol=val;
}



void Ui::set_track_volume(int val)
{
  settings.trackvol=val;
}



void Ui::set_world_rooms(const Rooms &r)
{
  settings.worldRooms=r;
}



void Ui::set_style(GameStyleType style)
{
  settings.style = style;
}



void Ui::set_quanta(Quanta quanta)
{
  settings.quanta = quanta;
}



void Ui::set_humans_playing(int val)
{
}

void Ui::set_cooperative(Boolean p_bool)
{
  settings.cooperative=p_bool;
}

void Ui::set_musictype(UIsettings::SOUNDTRACKTYPE val)
{
  settings.musictype=val;
}

void Ui::set_pause(BOOL val)
{
}


void Ui::set_enemies_playing(int){}

void Ui::set_level(const char *){}

void Ui::set_screen_mode(Xvars::SCREENMODE p_mode){}

Boolean Ui::other_input(){return FALSE;}

void Ui::set_input(int vNum,UIinput input){}

void Ui::set_keyset(int dpyNum,UIkeyset keyset){}
void Ui::set_keyset(int dpyNum,UIkeyset basis,
                    char right[UI_KEYS_MAX][2],
                    char left[UI_KEYS_MAX][2]){}

void Ui::set_prompt_difficulty(){}

// This needs to be fixed.
int Ui::get_difficulty(){return 0;}



void Ui::set_difficulty(int){}



int Ui::add_viewport(){return 0;}
void Ui::del_viewport(){}
void Ui::register_intel(int n, IntelP intel){}
void Ui::unregister_intel(int n){}
IntelP Ui::get_intel(int n){return NULL;}
void Ui::demo_reset(){}
void Ui::reset(){}
void Ui::reset_graphics(Xvars::SCREENMODE p_newmode){}
void Ui::set_redraw_arena(){}
Boolean Ui::process_event(int dpyNum,CMN_EVENTDATA eventdata){return FALSE;}
void Ui::set_role_type(RoleType){}



IViewportInfo* Ui::get_viewport_info() {
  return UiPlayer::get_viewport_info();
}



void Ui::check_num_lock() {
  // Ask user to turn on num lock.
  SHORT val = GetKeyState(VK_NUMLOCK);
  if (!(LOBYTE(val) & 0x1)) {
    AfxMessageBox("Turn on \"Num Lock\" if you want to use the numeric keypad.");
  }
}



void Ui::set_reduce_draw(Boolean val) {
  Xvars::set_reduce_draw(val);
}



Boolean Ui::initGraphics = TRUE;



