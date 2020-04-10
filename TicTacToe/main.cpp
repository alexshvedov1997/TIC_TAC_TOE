//#include "mainwindow.h"
#include "create_game.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  //  MainWindow w;
  //  w.show();
    CreateGame game;
    game.show();

    return a.exec();
}
