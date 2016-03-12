#ifndef LIVES_H
#define LIVES_H

#include <QGraphicsTextItem>

class Game;

/**
 * @brief class Lives
 * keeps track of the number of lives a player has. The function decrease subtracts 1 from
 * the total number of lives the player has.
 */
class Lives: public QGraphicsTextItem{
public:
    Lives(QGraphicsItem * parent = 0); //Default no parent but you can choose to pass one in
    void decrease(); // Decreases lives by 1
    int getLives(); // Getter
    void setGame(Game* g);

private:
    int lives; // Keeps track of number of lives/ number of starting lives
    Game* game;
};

#endif // LIVES_H
