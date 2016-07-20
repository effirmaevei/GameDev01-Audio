#include <QApplication>
#include "Game.h"


// Provides global pointer for the program.
Game *game;

int main(int argc, char *argv[])
{
  //Scene has infinited size by default but is a rectangle that can be set   
    QApplication a(argc, argv);

    game = new Game();
    game -> show();


    return a.exec();
}
