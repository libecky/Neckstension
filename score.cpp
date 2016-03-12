#include "score.h"
#include <QFont>
#include "lives.h"

/**
 * @brief Score::Score
 * Keeps track of the score
 * @param parent
 */
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Initialize score to 0
    score=0;
    // Draw the text
    setPlainText("Score: " + QString::number(score));
    setFont(QFont("fixedsys", 12)); //Name of family of font, seize of font
    //setPos(450, 0);

}

/**
 * @brief Score::increase
 * Increments score and sets text
 */
void Score::increase(){
score++; // Increases score by 1
setPlainText("Score: " + QString::number(score));
}

/**
 * @brief Score::getScore
 * Getter function
 * @return
 */
int Score::getScore(){
    return score;
}
