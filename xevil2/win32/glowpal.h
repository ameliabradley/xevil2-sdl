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

class GlowPalette: public PaletteModifier
{
public:
  enum {GLOW_UPPERLIMIT=50, GLOW_LOWERLIMIT=-50, GLOW_AMOUNT=5};
  GlowPalette(ColorPalette &p_palette);
  virtual ~GlowPalette(){}
  virtual void clock();
  ColorPalette m_fogholdingpalette;
  int m_amount;
  char m_dir;
};
