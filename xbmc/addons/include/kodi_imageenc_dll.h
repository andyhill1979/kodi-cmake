/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include <stdint.h>
#include "xbmc_addon_dll.h"
#include "kodi_imageenc_types.h"

extern "C"
{
  //! \copydoc AudioDecoder::Init
  void* LoadImage(unsigned char* buffer, unsigned int bufSize,
                  unsigned int* width, unsigned int* height);

  bool Decode(void* image, unsigned char* pixels,
              unsigned int width, unsigned int height,
              unsigned int pitch, unsigned int format);

  bool CreateThumbnail(unsigned char* bufferin,
                       unsigned int width,
                       unsigned int height,
                       unsigned int pitch,
                       unsigned int format,
                       const char* destFile);

  void Close(void* image);

  // function to export the above structure to Kodi
  void __declspec(dllexport) get_addon(struct ImageEncoder* pEnc)
  {
    pEnc->LoadImage = LoadImage;
    pEnc->Decode = Decode;
    pEnc->CreateThumbnail = CreateThumbnail;
    pEnc->Close = Close;
  };
};
