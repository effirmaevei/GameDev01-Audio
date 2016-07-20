#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Constants.h"
#include "Enemy.h"
#include "Game.h"

extern Game *game;

Enemy::Enemy(QGraphicsItem *parent) : QObject(), QGraphicsRectItem(parent){
  //Set random starting position
  int random_number = rand() % (resWidth-100);
  setPos(random_number, 0);

  //Create and set base size
  setRect(0,0,50,50);

  // connect
  timer = new QTimer(this);
  connect(timer,SIGNAL(timeout()),this,SLOT(move()));

  //set timer time to 50 milliseconds. This defines how long it takes for the enemy to move/die.
  timer->start(30);

}

void Enemy::move(){
    //behaviour for each enemy to execute every timeout
    setPos(x(), y() + 5);
    if (pos().y() + rect().height() > resHeight){
        timer->stop();
        //decrease health
        game->health->decrease();
        scene()->removeItem(this);
        this->deleteLater();
      }
}
