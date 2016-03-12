/**
  Becky Li
  UCLA: PIC 10C
  Professor DeSalvo
  Winter 2016

    Welcome to Neckstension!

    Necky the giraffe just escaped from the local zoo and happened to gallop past a elementary school food fight!
    Help Necky eat as much as she can by using the up and down arrow key to extend her neck. Avoid eating strange-
    smelling chocolate yogurty swirls and the occasional bird. You will start out with three lives. Every time you
    miss a food-item or eat a non-food item, you will lose a life. Every time you consume a food-item, you gain one
    point to your score.

    Necky the giraffe's front facing head portion is represented by the Giraffe class while the rest of her body is
    represented by the Neck class. This is to distinguish her head from the rest of her body when keeping track of
    collisions. The food is represented by the food class and is randomized for both location at spawn and object type
    (food vs non-food). Lives are represented by the Lives class and the score is represented by the Score class.

    There are three windows. The first window is the title screen with two buttons: the "START" button starts the game,
    and the "Instructions" button opens up the instructions window. The last window, the "donezo" window, opens when
    the player loses all three lives.

    Game art designed and created by my incredibly talented friend Michael Chiou. You can find him on Tumblr at
    smilequotas.tumblr.com for commission information and general inquiries.

*/

#include <QApplication>
#include "game.h"
#include "mainwindow.h"
#include "instructionwindow.h"
#include "gameoverwindow.h"

//game object is global for access
Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create all the windows in main

    MainWindow myMain;
    InstructionWindow myInstruction;
    GameOverWindow myGameOver;

    game = new Game();
    myMain.setGame(game);
    myMain.setInstruction(&myInstruction);
    game->setGameOver(&myGameOver);

    // Display main

    myMain.show();

    return a.exec();
}
