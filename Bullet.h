#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QTimer>

class Bullet: public QObject, public QGraphicsRectItem{

  Q_OBJECT

public:
  Bullet(QGraphicsItem *parent=0);

public slots:
  void move();

private:
  QTimer *timer;

};



#endif // BULLET_H
