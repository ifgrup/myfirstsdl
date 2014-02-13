//
//  Enemy.cpp
//  myfirstsdl
//
//  Created by rrodriguez on 30/01/14.
//  Copyright (c) 2014 EveronGames. All rights reserved.
//

#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams):SDLGameObject(pParams)
{
    
}

void Enemy::draw()
{
    SDLGameObject::draw(); // we now use SDLGameObject
}


void Enemy::update()
{
    //generate a simple move
   // m_y += 1;
   // m_x += 1;
    m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
}

void Enemy::clean()
{
    
}