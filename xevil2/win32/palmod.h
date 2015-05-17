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

#ifndef PALMOD_H
#define PALMOD_H

#include "xdata.h"

class PaletteModifier
{
public:
    PaletteModifier(ColorPalette &p_palette);
    PaletteModifier();
    virtual ~PaletteModifier();
    virtual HRESULT applyPalette(HDC p_hdc, LPDIRECTDRAWSURFACE p_suface, LPDIRECTDRAW p_lpDD);
    virtual HRESULT removePalette();
    virtual void clock()=0;
protected:
    LPDIRECTDRAWPALETTE m_ddpalette;
    LPDIRECTDRAWPALETTE m_oldpalette;
    LPDIRECTDRAWSURFACE m_surface;
    HPALETTE m_hpal;
    ColorPalette m_palette;
    BOOL m_applied;
};

/*passed a palette,  does some modification on it and makes a lpdirectdrawpalette
keeps pointer to old palette to return it to normal.*/

class DefaultModifier:public PaletteModifier
{
public:
    DefaultModifier(){}
    virtual ~DefaultModifier(){}
    virtual HRESULT applyPalette(HDC p_hdc, LPDIRECTDRAWSURFACE p_suface, LPDIRECTDRAW p_lpDD){return DD_OK;}
    virtual HRESULT removePalette(){return DD_OK;}
    virtual void clock(){}
};

#endif //PALMOD_H

