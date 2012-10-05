#ifndef PLAYER_H
#define PLAYER_H

#import "mage.h"
using namespace mg;

class Player: public Sprite {
  public:
    Vec acc, vel, grav, damp;

    Player(Vec pos) : Sprite(pos) {
      this->acc = Vec();
      this->vel = Vec();
      this->grav = Vec(0, 9.8);
      this->damp = Vec(0, 0.99);
    };

    virtual void update(GLdouble dt);
    virtual void draw(GLdouble dt) const;
};

#endif