#import "Thread.h"
#include <iostream>
using namespace std;

void Thread::init() {
  mg::Game::init();

  mg::Color gray(20, 20, 20);
  this->setBackgroundColor(gray);
}

void Thread::handleInput(double dt) {
  if (mg::Input::keyPressed('P')) {
    this->togglePause();
  }

  if (mg::Input::keyPressed(GLFW_KEY_ESC)) {
    this->quit(0);
  }
}

void Thread::update(double dt) {
  mg::Game::update(dt);
}