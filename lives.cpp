#include "lives.h"
#include <QFont>
#include "game.h"
#include "score.h"

/**
 * @brief Lives::Lives
 * Keeps track of lives and writes on window
 * @param parent
 */
Lives::Lives(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Initialize lives to 3
    lives=3;
    // Draw the text
    setPlainText("Lives: " + QString::number(lives));
    setFont(QFont("fixedsys", 12)); // Name of family of font, seize of font

}

/**
 * @brief Lives::setGame
 * @param g
 */
void Lives::setGame(Game* g) {
    game = g;
}

/**
 * @brief Lives::decrease
 * Subtracts 1 from the lives
 */
 void Lives::decrease(){
lives--;

// Game over!
if (lives < 1) {
    game->gameOver();
}
// Writes number of lives to game
setPlainText("Lives: " + QString::number(lives));

}

 /**
 * @brief Lives::getLives
 * @return
 */
int Lives::getLives(){
    return lives;
}
