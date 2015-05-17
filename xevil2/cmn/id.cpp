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

// "id.cpp"

#if X11
	#ifndef NO_PRAGMAS
	#pragma implementation "id.h"
	#endif
#endif
#include "stdafx.h"


#include <limits.h>

#include "utils.h"
#include "id.h"



// Lame-o HP compiler won't let this be inline.
Identifier::Identifier() {
  invalidate();
}



void Identifier::read(InStreamP in) {
  u_short val = in->read_short(); 
  if (val == 0xffff) {
    index = INVALID;
  }
  else {
    index = val;
  }
  unique = in->read_int();
}



int Identifier::get_write_length() {
  return sizeof(short) + sizeof(int);
}



void Identifier::write(OutStreamP out) const {
  u_short val;
  if (index == INVALID) {
    val = 0xffff;
  }
  else {
    assert(index < USHRT_MAX);  // strictly less than to avoid 0xffff
    val = (u_short)index;
  }

  out->write_short(val); 
  out->write_int(unique);
}



Boolean Identifier::operator == (const Identifier &other) const {
  return (index != INVALID) && (other.index == index) 
    && (other.unique == unique);
}



Boolean Identifier::operator != (const Identifier &other) const {
  return (index == INVALID) || (other.index != index) 
    || (other.unique != unique);
}
