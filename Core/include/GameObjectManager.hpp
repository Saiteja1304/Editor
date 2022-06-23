#ifndef GAMEOBJECTMANAGER_HPP
#define GAMEOBJECTMANAGER_HPP

#include "Components/GameObject.hpp"
class GameObjectManager {
public:
  unsigned short int mainGroupSize = 5;
  Group *mainGroup = new Group(5);
  static GameObjectManager &GMGetInstance() {
    static GameObjectManager GMInstance;
    return GMInstance;
  }

private:
  GameObjectManager() {}
  void operator=(GameObjectManager const &);
  GameObjectManager(GameObjectManager const &);
};

#endif