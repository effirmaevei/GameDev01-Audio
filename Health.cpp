#include "Health.h"
#include <QString>
#include <QFont>

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent){
  //initialize score to zero
  health = 0;
  //draw the score (text)
  setPlainText(QString("Health: ") + QString::number(health));
  setDefaultTextColor(Qt::red);
  setFont(QFont("times", 16));

}

void Health::decrease(){
  health--;
  setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth(){
  return health;
}
