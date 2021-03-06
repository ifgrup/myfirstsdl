//
//  main.cpp
//  myfirstsdl
//
//  Created by rrodriguez on 08/12/13.
//  Copyright (c) 2013 EveronGames. All rights reserved.
//

#include <iostream>
#include "Game.h"

 Game* g_game = 0;



int main(int argc, const char * argv[])
{
    std::cout << "game init attempt...\n";
  
    if(TheGame::Instance()->init("RR Game", 100, 100, 800, 600,true))
    {
        std::cout << "game init success!\n";
        while(TheGame::Instance()->running())
        {
            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();
            SDL_Delay(10);
        }
    } else {
        std::cout << "game init failure - " << SDL_GetError() << "\n";
        return -1;
       
    }
    std::cout << "game closing...\n";
    TheGame::Instance()->clean();
    return 0;
    
   }

