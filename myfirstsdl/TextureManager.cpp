//
//  TextureManager.cpp
//  myfirstsdl
//
//  Created by rrodriguez on 17/12/13.
//  Copyright (c) 2013 EveronGames. All rights reserved.
//

#include "TextureManager.h"


TextureManager* TextureManager::s_pInstance = 0;

 bool TextureManager:: load(std::string fileName,std::string id,SDL_Renderer* pRenderer)
{
    std::string s=localpath+fileName;
   
     SDL_Surface* pTempSurface = IMG_Load(s.c_str());
   
    if(pTempSurface == 0)
    {
          std::cout << "No load Image - ";
        return false;
    }
    
    
    
    
    
    
    SDL_Texture* pTexture =SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
   
    SDL_FreeSurface(pTempSurface);
    // everything went ok, add the texture to our list
    if(pTexture != 0)
    {
        m_textureMap[id] = pTexture;
        return true;
    }
    // reaching here means something went wrong
    return false;
}



bool TextureManager:: load(std::string fileName,std::string id,SDL_Renderer* pRenderer,bool noalphachanel)
{
    SDL_Color coloralpha;
    SDL_PixelFormat *fmt;
    Uint8 index;
    Uint32 temp, pixel;
    Uint8 red, green, blue, alpha;
    
    coloralpha.r=0x7f;
    coloralpha.g=0x79;
    coloralpha.b=0xdb;
    
    std::string s=localpath+fileName;
    
    SDL_Surface* pTempSurface = IMG_Load(s.c_str());
    
    if(pTempSurface == 0)
    {
        std::cout << "No load Image - ";
        return false;
    }
    
   
    
    fmt = pTempSurface->format;
    SDL_LockSurface(pTempSurface);
    pixel = *((Uint32*)pTempSurface->pixels);
    SDL_UnlockSurface(pTempSurface);
    
    /* Get Red component */
    temp = pixel & fmt->Rmask;  /* Isolate red component */
    temp = temp >> fmt->Rshift; /* Shift it down to 8-bit */
    temp = temp << fmt->Rloss;  /* Expand to a full 8-bit number */
    red = (Uint8)temp;
    
    /* Get Green component */
    temp = pixel & fmt->Gmask;  /* Isolate green component */
    temp = temp >> fmt->Gshift; /* Shift it down to 8-bit */
    temp = temp << fmt->Gloss;  /* Expand to a full 8-bit number */
    green = (Uint8)temp;
    
    /* Get Blue component */
    temp = pixel & fmt->Bmask;  /* Isolate blue component */
    temp = temp >> fmt->Bshift; /* Shift it down to 8-bit */
    temp = temp << fmt->Bloss;  /* Expand to a full 8-bit number */
    blue = (Uint8)temp;
    
    /* Get Alpha component */
    temp = pixel & fmt->Amask;  /* Isolate alpha component */
    temp = temp >> fmt->Ashift; /* Shift it down to 8-bit */
    temp = temp << fmt->Aloss;  /* Expand to a full 8-bit number */
    alpha = (Uint8)temp;
    
    printf("Pixel Color -> R: %d,  G: %d,  B: %d,  A: %d\n", red, green, blue, alpha);
    
    
    // SDL_SetColorKey(pTempSurface, SDL_TRUE, SDL_MapRGB( pTempSurface->format, 128, 121, 221 ) );
    
    //SDL_SetColorKey(pTempSurface, SDL_RLEACCEL,SDL_MapRGB( pTempSurface->format,128 ,121 , 221 ));
    
   
    SDL_Texture* pTexture =SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    // everything went ok, add the texture to our list
    if(pTexture != 0)
    {
        m_textureMap[id] = pTexture;
        return true;
    }
    // reaching here means something went wrong
    return false;
}



void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer,SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = 0;
    srcRect.y = 0;
    
    // same size
    //srcRect.w = destRect.w = width;
    //srcRect.h = destRect.h = height;

    
    // show twice the  texture size
    srcRect.w = width;
    srcRect.h = height;
    destRect.w = width*2;
    destRect.h = height*2;
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,&destRect, 0, 0, flip);
    
}
void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame,SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    
    //srcRect.w = destRect.w = width;
    //srcRect.h = destRect.h = height;
    srcRect.w = width;
    srcRect.h = height;
    destRect.w = width*2;
    destRect.h = height*2;
    
    
    
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
                     &destRect, 0, 0, flip);
}