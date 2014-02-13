//
//  GameObject.h
//  myfirstsdl
//
//  Created by rrodriguez on 28/01/14.
//  Copyright (c) 2014 EveronGames. All rights reserved.
//

#ifndef __myfirstsdl__GameObject__
#define __myfirstsdl__GameObject__

#include <iostream>
#include <string>
#include <map>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "TextureManager.h"
#include "LoaderParams.h"



class GameObject
{
public:
    virtual void draw()=0;
    virtual void update()=0;
    virtual void clean()=0;
protected:
    GameObject(const LoaderParams* pParams) {}
    virtual ~GameObject() {}
};





#endif /* defined(__myfirstsdl__GameObject__) */
