#ifndef THREAD_H
#define THREAD_H

#import "mage.h"

class Thread: public mg::Game {
  public:
    Thread() : mg::Game("Thread", 800, 600) {};

    virtual void update(double dt);
};

#endif