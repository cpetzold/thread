#ifndef TERRAIN_H
#define TERRAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#import <deque>

#import "mage.h"
using namespace mg;

class Terrain: public Sprite {
  public:
    GLint width, height;
    std::deque<GLfloat> points;

    Terrain(GLint w, GLint h) : Sprite(), width(w), height(h) {
      srand(time(0));
    };

    virtual void update(GLdouble dt);
    virtual void draw(GLdouble dt) const;

    // Based on http://freespace.virgin.net/hugo.elias/models/m_perlin.htm
    GLfloat noise(GLint x);
    GLfloat smoothedNoise(GLfloat x);
    GLfloat interpolatedNoise(GLfloat x);
    GLfloat interpolate(GLfloat v1, GLfloat v2, GLfloat x);
    GLfloat perlinNoise(GLfloat x, GLfloat f, GLfloat a);
};

#endif