//
//  Game.cpp
//  myfirstsdl
//
//  Created by rrodriguez on 16/12/13.
//  Copyright (c) 2013 EveronGames. All rights reserved.
//



// pdf singleton página 61 ... continuará

#include "Game.h"
#include "Player.h"
#include "Enemy.h"
//using namespace std;
Game* Game::s_pInstance = 0;



bool Game::init(const char* title, int xpos, int ypos, int width,int height, bool fullscreen)
{
   
    int flags = 0;
    if(fullscreen)
    {
      //flags = SDL_WINDOW_FULLSCREEN;
        flags= SDL_WINDOW_RESIZABLE;
    }
    
    
    // attempt to initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n";
        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos,width, height, flags);
    
    
        
        if(m_pWindow != 0) // window init success
        {
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if(m_pRenderer != 0) // renderer init success
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer,255,255,255,255);
            } else {
                std::cout << "renderer init fail\n";
                return false; // renderer init fail
            }
        } else {
            std::cout << "window init fail\n";
            return false; // window init fail
        }
    } else {
        std::cout << "SDL init fail\n";
        return false; // SDL init fail
    }
    std::cout << "init success\n";
   
    pathfolder();
 
    
    m_bRunning = true; // everything inited successfully,start the main loop
    
    
    
    
   
    
    //Load image in a dictionary
    if(!TheTextureManager::Instance()->load("img/animate-alpha.png","animate", m_pRenderer))
    {
        return false;
    }
    
    //Load 2 image in a dictionary
    if(!TheTextureManager::Instance()->load("img/enemy.png","enemy", m_pRenderer))
    {
        return false;
    }
    
    
    
    m_gameObjects.push_back(new Player(new LoaderParams(0, 0, 128, 82,"animate")));
   m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 64, 64,"enemy")));
    
    return true;
    
}
void Game::render()
{

    SDL_RenderClear(m_pRenderer);
  
    TheTextureManager::Instance()->drawFrame("enemy", 50,300, 64, 64,3, m_currentFrame, m_pRenderer);
    
      //Polymorphism
    for(std::vector<GameObject*>::size_type i = 0; i !=
        m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
    
    
    SDL_RenderPresent(m_pRenderer);
}
void Game::handleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                m_bRunning = false;
                break;
            default:
            break;
        }
    }
}


void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::update()
{
   
    m_currentFrame = int(((SDL_GetTicks() / 300) % 4));
  
    for(std::vector<GameObject*>::size_type i = 0; i !=
        m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
    
}
void Game::pathfolder()
{
   
    
}


