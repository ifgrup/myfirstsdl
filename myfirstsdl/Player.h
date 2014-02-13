//
//  Player.h
//  myfirstsdl
//
//  Created by rrodriguez on 28/01/14.
//  Copyright (c) 2014 EveronGames. All rights reserved.
//

#ifndef __myfirstsdl__Player__
#define __myfirstsdl__Player__

#include <iostream>
#include "GameObject.h"

#include "LoaderParams.h"

#include "SDLGameObject.h"

class Player : public SDLGameObject
{

    
public:
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
};
#endif /* defined(__myfirstsdl__Player__) */
