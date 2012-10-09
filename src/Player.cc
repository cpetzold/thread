#include "Player.h"

#include <iostream>
using namespace std;

void Player::update(GLdouble dt) {
  if (Input::mouseDown(GLFW_MOUSE_BUTTON_LEFT) || Input::keyDown(GLFW_KEY_SPACE)) {
    this->acc.y -= 20;
  }

  this->vel += (this->acc * dt);
  this->vel *= this->damp;

  this->pos += this->vel;

  this->acc = this->grav;
}

void Player::draw(GLdouble dt) const {
  draw::rect(this->pos.x, this->pos.y, 4.0f, 2.0f, Color(255, 255, 255));
}