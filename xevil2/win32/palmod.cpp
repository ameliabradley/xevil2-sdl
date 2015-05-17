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
#include "palmod.h"
#include "xdata.h"


/*passed a palette,  does some modification on it and makes a lpdirectdrawpalette
keeps pointer to old palette to return it to normal.*/

PaletteModifier::PaletteModifier(ColorPalette &p_palette)
{
  m_applied=FALSE;
  m_ddpalette=NULL;
  m_oldpalette=NULL;
  m_surface=NULL;
  m_hpal=NULL;
}



PaletteModifier::PaletteModifier()
{
  m_applied=FALSE;
  m_ddpalette=NULL;
  m_oldpalette=NULL;
  m_surface=NULL;
  m_hpal=NULL;
}



PaletteModifier::~PaletteModifier()
{
    HRESULT t_result;
    if (m_applied)
        t_result=m_surface->SetPalette( m_oldpalette);

    if (m_ddpalette)
        m_ddpalette->Release();
    if (m_hpal)
      ::DeleteObject(m_hpal);

}



HRESULT
PaletteModifier::applyPalette(HDC p_hdc,LPDIRECTDRAWSURFACE p_surface, LPDIRECTDRAW p_lpDD)
{
    if (m_applied)
        return DD_OK;

    
/*    ::SelectPalette(p_hdc,m_hpal,FALSE);//false is to force us to use our own palette!
    UINT t_uint=::RealizePalette(p_hdc);
    t_uint=::GetSystemPaletteEntries(p_hdc,0,PALENTRIES,m_palette.palentries);*/

    HRESULT t_result=p_lpDD->CreatePalette( DDPCAPS_ALLOW256|DDPCAPS_8BIT, m_palette.palentries, &m_ddpalette,NULL);
    DHRESULT(t_result,return t_result);


    m_surface=p_surface;
    t_result=m_surface->GetPalette( &m_oldpalette);
    DHRESULT(t_result,return t_result);
    t_result=m_surface->SetPalette( m_ddpalette);
    DHRESULT(t_result,return t_result);
    m_applied=TRUE;
    return DD_OK;
}



HRESULT
PaletteModifier::removePalette()
{
    if (!m_applied)
        return DD_OK;
    HRESULT t_result=DD_OK;
    if (m_applied)
        t_result=m_surface->SetPalette( m_oldpalette);
    m_applied=FALSE;
    return t_result;
}


