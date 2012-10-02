#import "Thread.h"
#include <iostream>
using namespace std;

void Thread::update(double dt) {
  mg::Game::update(dt);
  
  if (mg::Input::keyPressed(GLFW_KEY_ESC)) {
    this->quit(0);
  }
}