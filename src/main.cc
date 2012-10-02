#include "Thread.h"

#include <iostream>
using namespace std;

int main(int argc, char** argv) {

  Thread game;
  game.init();
  game.run();

  return 0;
}