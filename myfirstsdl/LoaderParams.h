//
//  LoaderParams.h
//  myfirstsdl
//
//  Created by rrodriguez on 30/01/14.
//  Copyright (c) 2014 EveronGames. All rights reserved.
//

#ifndef __myfirstsdl__LoaderParams__
#define __myfirstsdl__LoaderParams__

#include <iostream>

class LoaderParams
{
public:
    LoaderParams(int x, int y, int width, int height, std::string
                 textureID) : m_x(x), m_y(y), m_width(width), m_height(height),
    m_textureID(textureID)
    {
    }
    int getX() const { return m_x; }
    int getY() const { return m_y; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    std::string getTextureID() const { return m_textureID; }
private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    std::string m_textureID;
};




#endif /* defined(__myfirstsdl__LoaderParams__) */
