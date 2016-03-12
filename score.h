#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

/**
 * @brief The Score class
 * keeps track of the score. It increases every time Necky consumes a food-object.
 */

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent = 0); //Default no parent but you can choose to pass one in
    void increase(); // Increases score by one point
    int getScore(); //Getter

private:
    int score; // Keeps track of score/ starts at 0

};

#endif // SCORE_H
