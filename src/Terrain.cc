#include "Terrain.h"

#include <math.h>
#include <cstdlib>
#include <iostream>
using namespace std;

void Terrain::update(GLdouble dt) {

  GLfloat point = 100.0 + this->perlinNoise(this->pos.x++, 0.1, 100.0);

  // cout << this->pos.x << 'x' << point << endl;

  this->points.push_back(point);

  if (this->points.size() > this->width) {
    this->points.pop_front();
  }
}

void Terrain::draw(GLdouble dt) const {
  glPushMatrix();

  glBegin(GL_TRIANGLE_STRIP);
  glColor4f(1, 1, 1, 1);

  for (int i = 0; i < this->points.size(); i++) {
    glVertex2f(i*3, this->points[i]);
    glVertex2f(i*3, 0);
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