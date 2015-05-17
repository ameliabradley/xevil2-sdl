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

class FogPalette: public PaletteModifier
{
public:
  enum {FOG_UPPERLIMIT=50,FOG_LOWERLIMIT=-50, FOG_AMOUNT=5};
  FogPalette::FogPalette(ColorPalette &p_palette);
  virtual ~FogPalette(){}
  virtual void clock();
  ColorPalette m_fogholdingpalette;
  int m_amount;
  char m_dir;
};
