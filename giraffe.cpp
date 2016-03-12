#include "giraffe.h"
#include "food.h"
#include "neck.h"
#include <QKeyEvent>
#include "game.h"

extern Game * game;
/**
 * @brief Giraffe::Giraffe
 * Sets image for Necky's collidable head
 * @param parent
 */
Giraffe::Giraffe(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent){

    // Set image for Necky's front facing head
    setPixmap(QPixmap(":/image/Giraffe.png"));

}

/**
 * @brief Giraffe::spawn
 * Spawns food and adds to scene
 */
void Giraffe::spawn(){
    // Create food
    Food * food = new Food();
    // Add food to scene
    scene()->addItem(food);
}
