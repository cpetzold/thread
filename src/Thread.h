#ifndef THREAD_H
#define THREAD_H

#import "mage.h"

#import "Player.h"

class Thread: public mg::Game {
  public:
    Thread() : mg::Game("Thread", 800, 600) {};

    virtual void init();
    virtual void handleInput(double dt);
    virtual void update(double dt);
    virtual void draw(double dt);

  private:
    Player* player;
};

#endif