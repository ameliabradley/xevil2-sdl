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
#include "fogpal.h"

FogPalette::FogPalette(ColorPalette &p_palette)
:PaletteModifier(p_palette)
{
  int t_int=0;
  m_amount=0;
  m_dir=-1*FOG_AMOUNT;
  for (int i=0;i<PALENTRIES;i++)//first 10 and last 10 are reserved
  {

    t_int=p_palette.palentries[i].peRed*p_palette.palentries[i].peRed;
    t_int+=p_palette.palentries[i].peGreen*p_palette.palentries[i].peGreen;
    t_int+=p_palette.palentries[i].peBlue*p_palette.palentries[i].peBlue;
    t_int= t_int/3;
    t_int= (int)sqrt((float)t_int);
    m_palette.palentries[i].peRed=t_int;

    m_palette.palentries[i].peGreen=t_int;
    m_palette.palentries[i].peBlue=t_int;
  }

  m_palette.palversion=0x300; //default of windows
  m_palette.numentries=PALENTRIES;//256
  m_fogholdingpalette=m_palette;
  m_hpal= ::CreatePalette((LOGPALETTE *)&m_palette);//create a global palette
}



void FogPalette::clock()
{
  m_palette=  m_fogholdingpalette;
  m_amount+=m_dir;
  if (m_amount>FOG_UPPERLIMIT)
  {
    m_amount=FOG_UPPERLIMIT;
    m_dir=-1*FOG_AMOUNT;
  }
  if (m_amount<FOG_LOWERLIMIT)
  {
    m_amount=FOG_LOWERLIMIT;
    m_dir=FOG_AMOUNT;
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
    if (((int)m_palette.palentries[i].peGreen+m_amount)>255)
      m_palette.palentries[i].peGreen=255;
    else
      if (((int)m_palette.palentries[i].peGreen+m_amount)<0)
        m_palette.palentries[i].peGreen=0;
    else
      m_palette.palentries[i].peGreen+=m_amount;
    if (((int)m_palette.palentries[i].peBlue+m_amount)>255)
      m_palette.palentries[i].peBlue=255;
    else
      if (((int)m_palette.palentries[i].peBlue+m_amount)<0)
        m_palette.palentries[i].peBlue=0;
    else
      m_palette.palentries[i].peBlue+=m_amount;
  }
  m_ddpalette->SetEntries(0,0,255,m_palette.palentries);
}


