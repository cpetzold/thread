#include "Player.h"

#include <iostream>
using namespace std;

void Player::update(GLdouble dt) {
  if (mg::Input::keyDown(GLFW_KEY_SPACE)) {
    this->pos.x++;
  }
}

void Player::draw(GLdouble dt) const {
  mg::draw::rect(this->pos.x, this->pos.y, 100.0f, 100.0f, mg::Color(255, 0, 0));
}