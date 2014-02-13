//
//  Game.h
//  myfirstsdl
//
//  Created by rrodriguez on 09/12/13.
//  Copyright (c) 2013 EveronGames. All rights reserved.
//

#ifndef myfirstsdl_Game_h
#define myfirstsdl_Game_h

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "CoreFoundation/CoreFoundation.h"
#include "stdint.h"

#include <iostream>
#include <cstring>
#include <vector>
#include "unistd.h"
#include "TextureManager.h"
#include "GameObject.h"


class Game
{
public:
    
    static Game* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new Game();
            return s_pInstance;
        }
        return s_pInstance;
    }

   
    ~Game() {}
    // simply set the running variable to true
   bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    // init();
    void render();
    void update();
    void handleEvents();
    void clean();
    // a function to access the private running variable
    bool running() { return m_bRunning; }
  
    SDL_Renderer* getRenderer() const { return m_pRenderer; }
    
private:
    
    Game(){
        
    };
    
    // create the s_pInstance member variable
    static Game* s_pInstance;
    // create the typedef
   
    
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    SDL_Texture* m_pTexture; // the new SDL_Texture variable
    SDL_Rect m_sourceRectangle; // the first rectangle
    SDL_Rect m_destinationRectangle; // another rectangle
    bool m_bRunning;
    void pathfolder();
    int m_currentFrame;
    
 
    
    
    std::vector<GameObject*> m_gameObjects;
 
protected:
};
typedef Game TheGame;

#endif
