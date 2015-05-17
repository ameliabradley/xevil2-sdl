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

// "id.h" Object locator id.

#ifndef ID_H
#define ID_H

#if X11
	#ifndef NO_PRAGMAS
	#pragma interface
	#endif
#endif

#include "streams.h"

class Identifier {
 public:
  void read(InStreamP in);
  static int get_write_length();
  void write(OutStreamP out) const;

  Boolean operator == (const Identifier &other) const;
  Boolean operator != (const Identifier &other) const;
  /* NOTE: Two INVALID Identifiers are not equal to each other. */

  void invalidate() {index = INVALID;}
  /* EFFECTS: Guarantees that the Identifier is invalid. */


#ifndef PROTECTED_IS_PUBLIC 
protected:  
#endif
  Identifier();
  Identifier(InStreamP in) {read(in);}

  enum {INVALID = -1};
  int index; 
  int unique;
};



class Id: public Identifier {
  friend class Locator;
public:
  Id() {}
  Id(InStreamP in) : Identifier(in) {}
};



class IntelId: public Identifier {
  friend class Locator;
public:
  IntelId() {}
  IntelId(InStreamP in) : Identifier(in) {}
};



class MoverId: public Identifier {
  friend class World;
public:
  MoverId() {}
  MoverId(InStreamP in) : Identifier(in) {}
};

typedef u_int CompositeId;
#define COMPOSITE_ID_NONE 0xffffffff;

#endif
