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

#include "palmod.h"
#include "utils.h"

class FirePalette: public PaletteModifier
{
public:
  enum {FIRE_UPPERLIMIT=50, FIRE_LOWERLIMIT=0, FIRE_AMOUNT=4};
  FirePalette(ColorPalette &p_palette);
  virtual ~FirePalette(){}
  virtual void clock();
  ColorPalette m_fireholdingpalette;
  int m_amount;
  char m_dir;
};
