#include <QGraphicsTextItem>
#include <QFont>
#include <QTimer>
#include <QMediaPlayer>
#include "Player.h"
#include "Constants.h"
#include "Game.h"

Game::Game(QWidget *parent)
{
  // Initialize scene member
  scene = new QGraphicsScene();
  scene->setSceneRect(0,0,resWidth,resHeight);

  // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
  // it can be used to visualize scenes)
  setScene(scene);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setFixedSize(resWidth,resHeight);

  // Initialize player member
  player = new Player();
  player->setRect(0,0,100,100);
  player->setPos(width()/2 - player->rect().width()/2 , height()-player->rect().height());
  //make player focusable
  player->setFlag(QGraphicsItem::ItemIsFocusable);
  player->setFocus();
  // add the player to the scene
  scene->addItem(player);

  // create the score/health
  score = new Score();
  scene->addItem(score);
  health = new Health();
  health->setPos(health->x(),health->y()+25);
  scene->addItem(health);

  // spawn enemies
  QTimer *timer = new QTimer();
  QObject::connect( timer, SIGNAL(timeout()), player, SLOT(spawn()) );
  //means an enemy will be created every 2 sec
  timer->start(2000);

  //play background music
  QMediaPlayer *music = new QMediaPlayer(this);
  music->setMedia(QUrl("qrc:/sounds/bgm0.mp3"));
  music->play();

  show();
}
