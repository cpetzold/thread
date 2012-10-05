#import "Thread.h"

#include <iostream>
using namespace std;

void Thread::init() {
  mg::Game::init();

  mg::Color gray(20, 20, 20);
  this->setBackgroundColor(gray);

  this->player = new Player(Vec(150.0, 100.0));
  this->terrain = new Terrain(800, 600);

  this->layers[0].push_back(this->terrain);
  this->layers[1].push_back(this->player);
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

void Thread::draw(double dt) {
  mg::Game::draw(dt);
}