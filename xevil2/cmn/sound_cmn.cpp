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

#if X11
#ifndef NO_PRAGMAS
#pragma implementation "sound_cmn.h"
#endif
#endif

#include "stdafx.h"

#include "utils.h"
#include "streams.h"
#include "sound_cmn.h"
#if WIN32
#include "resource.h"
#endif

#include "bitmaps/sound_cmn/sound_cmn.bitmaps"


void SoundRequest::read(InStreamP in) {
  pos.read(in);
  soundName = (SoundName)in->read_int();
}



int SoundRequest::get_write_length() {
  return Pos::get_write_length() +
    sizeof(u_int);
}



void SoundRequest::write(OutStreamP out) const {
  pos.write(out);
  out->write_int((u_int)soundName);
}



// unnecessary
#if 0
SoundRequest &
SoundRequest::operator=(const SoundRequest& req) {
  id = req.id;
  soundName = req.soundName;
	return *this;
}
#endif



unsigned int SoundNames::lookup(SoundName name) {
#if X11
  // Avoid stupid compiler warnings.
  name = name;
#endif
#if WIN32
  if (name >= 0 && name < SOUND_MAX) {
    return names[name];
  }
#endif
  return 0;
}
