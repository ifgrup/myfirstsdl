//
//  Enemy.h
//  myfirstsdl
//
//  Created by rrodriguez on 30/01/14.
//  Copyright (c) 2014 EveronGames. All rights reserved.
//

#ifndef __myfirstsdl__Enemy__
#define __myfirstsdl__Enemy__

#include <iostream>
#include "GameObject.h"
#include "SDLGameObject.h"
#include "GameObject.h"
#include "LoaderParams.h"

class Enemy : public SDLGameObject
{
public:
    Enemy(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
};



#endif /* defined(__myfirstsdl__Enemy__) */
