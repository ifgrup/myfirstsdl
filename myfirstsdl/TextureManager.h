//
//  TextureManager.h
//  myfirstsdl
//
//  Created by rrodriguez on 17/12/13.
//  Copyright (c) 2013 EveronGames. All rights reserved.
//

#ifndef myfirstsdl_TextureManager_h
#define myfirstsdl_TextureManager_h
#include <iostream>
#include <string>
#include <map>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
//#include "CoreFoundation/CoreFoundation.h"
class TextureManager {
    
    
public:
    static TextureManager* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }
        
        return s_pInstance;
    }
    //Load a texture
    bool load(std::string fileName,std::string id,SDL_Renderer* pRenderer);
    bool load(std::string fileName,std::string id,SDL_Renderer* pRenderer,bool noalphachanel);
    // draw
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    // drawframe
    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    private:
    TextureManager(){}
  
    std::map <std::string, SDL_Texture*> m_textureMap;
    std::map <int,SDL_Texture*> m_intTextureMap;
    std::string localpath="/Users/robertorodriguezgallardo/Desktop/openglking/xcodesdlprojects/myfirstsdl/myfirstsdl/";
    static TextureManager* s_pInstance;
   
};

 typedef TextureManager TheTextureManager;
#endif
