#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "Score.h"
#include "Player.h"
#include "Health.h"
#include "Constants.h"

class Game : public QGraphicsView{
public:
  Game(QWidget *parent=0);

  //Provides the pointers to data other files in the program will need
  QGraphicsScene *scene;
  Player *player;
  Score *score;
  Health *health;

};

#endif // GAME_H
