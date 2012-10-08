#import "Thread.h"

#include <iostream>
using namespace std;

void Thread::init() {
  Game::init();

  Color gray(20, 20, 20);
  this->setBackgroundColor(gray);

  this->player = new Player(Vec(150.0, 100.0));
  this->terrain = new Terrain(800, 600);

  this->layers[0].push_back(this->terrain);
  this->layers[1].push_back(this->player);
}

void Thread::handleInput(double dt) {
  if (Input::keyPressed('P')) {
    this->togglePause();
  }

  if (Input::keyPressed(GLFW_KEY_ESC)) {
    this->quit(0);
  }
}

void Thread::handleResize(GLint w, GLint h) {
  Game::handleResize(w, h);

  if (this->terrain) {
    this->terrain->resize(w, h);
  }
}

void Thread::update(double dt) {
  Game::update(dt);
}

void Thread::draw(double dt) {
  Game::draw(dt);
}