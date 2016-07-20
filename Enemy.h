#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsItem>

class Enemy : public QObject, public QGraphicsRectItem{
  Q_OBJECT
public:
  Enemy(QGraphicsItem *parent=0);
public slots:
  void move();
private:
  QTimer *timer;
};

#endif // ENEMY_H
