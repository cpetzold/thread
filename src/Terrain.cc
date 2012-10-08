#include "Terrain.h"

#include <math.h>
#include <cstdlib>
#include <iostream>
using namespace std;

void Terrain::resize(GLint w, GLint h) {
  this->width = w;
  this->height = h;
}

void Terrain::update(GLdouble dt) {
  for (GLint i = 0; i < 3; i++) {
    GLfloat topPoint = 100.0 + this->perlinNoise(this->topStep++, 0.015, 200.0);
    GLfloat bottomPoint = 100.0 + this->perlinNoise(this->bottomStep++, 0.015, 200.0);

    this->topPoints.push_back(topPoint);
    this->bottomPoints.push_back(bottomPoint);

    if (this->topPoints.size() > this->width) {
      this->topPoints.pop_front();
    }
    if (this->bottomPoints.size() > this->width) {
      this->bottomPoints.pop_front();
    }
  }
}

void Terrain::draw(GLdouble dt) const {
  glPushMatrix();
  glTranslatef(this->pos.x, this->pos.y, 0);
  glColor4f(1, 1, 1, 1);

  // Draw top
  glBegin(GL_TRIANGLE_STRIP);
  for (int i = 0; i < this->topPoints.size(); i++) {
    glVertex2f(i, this->topPoints[i]);
    glVertex2f(i, 0);
  }
  glEnd();

  // Draw bottom
  glBegin(GL_TRIANGLE_STRIP);
  for (int i = 0; i < this->bottomPoints.size(); i++) {
    glVertex2f(i, this->bottomPoints[i] + this->height - 200);
    glVertex2f(i, this->height);
  }
  glEnd();

  glPopMatrix();
}

GLfloat Terrain::noise(GLint x) { 
 x = (x<<13) ^ x;
 return (GLfloat)( 1.0 - ( (x * (x * x * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0);  
}

GLfloat Terrain::smoothedNoise(GLfloat x) {
  return this->noise(x) / 2 + this->noise(x - 1) / 4 + this->noise(x + 1) / 4;
}

GLfloat Terrain::interpolatedNoise(GLfloat x) {
  GLint ix = x;
  GLfloat fx = x - ix;

  GLfloat v1 = this->smoothedNoise(ix);
  GLfloat v2 = this->smoothedNoise(ix + 1);

  return this->interpolate(v1, v2, fx);
}

GLfloat Terrain::interpolate(GLfloat v1, GLfloat v2, GLfloat x) {
  GLfloat ft = x * 3.14159265;
  GLfloat f = (1 - cos(ft)) * 0.5;

  return v1 * (1 - f) + (v2 * f);
}

GLfloat Terrain::perlinNoise(GLfloat x, GLfloat f, GLfloat a) {
  return this->interpolatedNoise(x * f) * a;
}