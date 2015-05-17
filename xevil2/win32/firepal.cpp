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
#include "firepal.h"

#define FIRE_MOD 1.3


FirePalette::FirePalette(ColorPalette &p_palette)
:PaletteModifier(p_palette)
{
  int t_int=0;
  m_amount=0;
  m_dir=-1*FIRE_AMOUNT;
  for (int i=0;i<PALENTRIES;i++)//first 10 and last 10 are reserved
  {
	  m_palette.palentries[i].peRed=p_palette.palentries[i].peRed; //min(255,(unsigned char)(p_palette.palentries[i].peRed*FIRE_MOD+p_palette.palentries[i].peGreen*FIRE_MOD+p_palette.palentries[i].peBlue*FIRE_MOD)/3);
	  m_palette.palentries[i].peGreen=p_palette.palentries[i].peGreen; //p_palette.palentries[i].peGreen/2;
	  m_palette.palentries[i].peBlue=p_palette.palentries[i].peBlue;//p_palette.palentries[i].peBlue/2;
  }

  m_palette.palversion=0x300; //default of windows
  m_palette.numentries=PALENTRIES;//256
  m_fireholdingpalette=m_palette;
  m_hpal= ::CreatePalette((LOGPALETTE *)&m_palette);//create a global palette
}



void FirePalette::clock()
{
  m_palette=  m_fireholdingpalette;
  m_amount+=m_dir;
  if (m_amount>FIRE_UPPERLIMIT)
  {
    m_amount=FIRE_UPPERLIMIT;
    m_dir=-1*FIRE_AMOUNT;
  }
  if (m_amount<FIRE_LOWERLIMIT)
  {
    m_amount=FIRE_LOWERLIMIT;
    m_dir=FIRE_AMOUNT;
  }

  for (int i=0;i<PALENTRIES;i++)
  {
    if (((int)m_palette.palentries[i].peRed+m_amount)>255)
      m_palette.palentries[i].peRed=255;
    else
      if (((int)m_palette.palentries[i].peRed+m_amount)<0)
        m_palette.palentries[i].peRed=0;
    else
      m_palette.palentries[i].peRed+=m_amount;
    if (((int)m_palette.palentries[i].peGreen-m_amount)>255)
      m_palette.palentries[i].peGreen=255;
    else
      if (((int)m_palette.palentries[i].peGreen-m_amount)<0)
        m_palette.palentries[i].peGreen=0;
    else
      m_palette.palentries[i].peGreen-=m_amount;
    if (((int)m_palette.palentries[i].peBlue-m_amount)>255)
      m_palette.palentries[i].peBlue=255;
    else
      if (((int)m_palette.palentries[i].peBlue-m_amount)<0)
        m_palette.palentries[i].peBlue=0;
    else
      m_palette.palentries[i].peBlue-=m_amount;
  }
  m_ddpalette->SetEntries(0,0,255,m_palette.palentries);
}


