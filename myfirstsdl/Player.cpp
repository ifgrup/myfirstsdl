//
//  Player.cpp
//  myfirstsdl
//
//  Created by rrodriguez on 28/01/14.
//  Copyright (c) 2014 EveronGames. All rights reserved.
//

#include "Player.h"

Player::Player(const LoaderParams* pParams) :SDLGameObject(pParams)
{
    
}
/*
void Player::load(int x, int y, int width, int height, std::string textureID)
{
    GameObject::load(x, y, width, height, textureID);
}*/

void Player::draw()
{
    SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update()
{
    //generate a simple move
   // m_x -= 1;
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
void Player::clean()
{
    
}