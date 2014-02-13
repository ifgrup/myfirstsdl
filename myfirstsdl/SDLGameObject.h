//
//  SDLGameObject.h
//  myfirstsdl
//
//  Created by rrodriguez on 11/02/14.
//  Copyright (c) 2014 EveronGames. All rights reserved.
//

#ifndef __myfirstsdl__SDLGameObject__
#define __myfirstsdl__SDLGameObject__



#include <iostream>
#include <string>

#include "GameObject.h"


class SDLGameObject : public GameObject
{
public:
    SDLGameObject(const LoaderParams* pParams);
    virtual void draw();
    virtual void update(){};
    virtual void clean(){};
protected:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    int m_currentRow;
    int m_currentFrame;
    std::string m_textureID;
};





#endif /* defined(__myfirstsdl__SDLGameObject__) */
