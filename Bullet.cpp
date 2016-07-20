#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>

extern Game *game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){
  //Create and set base size
  setRect(0,0,10,50);

  // connect
  timer = new QTimer(this);
  connect(timer,SIGNAL(timeout()),this,SLOT(move()));

  //set timer time to 50 milliseconds
  timer->start(50);

}

void Bullet::move(){
    //if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            //increase the score
            game->score->increase();
            //remove from scene both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete both from heap
            delete colliding_items[i];
            delete this;

            //because all the code below referes to unexisting bullet
            return;
          }
      }


    //behaviour for each bullet to trigger every timeout
    setPos(x(), y()-10);
    if (pos().y() + rect().height() < 0){
        timer->stop();
        scene()->removeItem(this);
        this->deleteLater();
      }
}
