#ifndef THREAD_H
#define THREAD_H

#import "Game.h"

class Thread: public mg::Game {
  public:
    Thread() : mg::Game("Thread", 800, 600) {};
};

#endif