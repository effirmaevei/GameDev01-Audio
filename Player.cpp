#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"


Player::Player(QGraphicsItem *parent) : QGraphicsRectItem(parent){
  bulletSound = new QMediaPlayer(this);
  bulletSound->setMedia(QUrl("qrc:/sounds/beep0.wav"));
}

void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + rect().width() < scene()->width())
        setPos(x()+10,y());
    }    
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

        //play item sound
        if(bulletSound->state() == QMediaPlayer::PlayingState){
            bulletSound->setPosition(0);
        }
        else if(bulletSound->state() == QMediaPlayer::StoppedState){
          bulletSound->play();
        }
    }
}

void Player::spawn()
{
  //creates an enemy
  Enemy *enemy = new Enemy();
  scene()->addItem(enemy);

}
