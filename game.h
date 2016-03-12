#ifndef GAME_H
#define GAME_H

#include <QGraphicsItemGroup>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "giraffe.h"
#include "score.h"
#include "lives.h"
#include "gameoverwindow.h"
#include "neck.h"

/**
 * @brief The Game class adds objects to window/ scene
 */
class Game: public QGraphicsView{
public:
    Game(QWidget * parent = 0);

    // Functions
    void start();
    void gameOver();

    void setGameOver(GameOverWindow* o);

    // Public variables
    QGraphicsScene * scene;
    QGraphicsItemGroup * group;
    Giraffe * giraffe;
    Neck * neck;
    Score * score;
    Lives * lives;

    // Keeps track of radio button difficulty selection
    int difficulty;

    GameOverWindow* over;

    // Used to move Necky up and down
    void keyPressEvent(QKeyEvent * event);
};

#endif // GAME_H
