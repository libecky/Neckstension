#include "food.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <giraffe.h>
#include <ctime>
#include <random>
#include <chrono>
#include <QMediaPlayer>

// Used for random number generator
#define SEED (unsigned int)std::chrono::system_clock::now().time_since_epoch().count()
#define DEFAULT std::default_random_engine
#define DUNIF(T) std::uniform_int_distribution<T>

extern Game * game;

/**
 * @brief Food::Food
 * The food class represents the flying-objects moving towards the left.
 * @param parent
 */

Food::Food(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent){

    DEFAULT random_number(SEED);
    DUNIF(int) unif(100,500); // Generates height distribution for positioning food item

    // Randomly positions food height
    setPos(875,unif(random_number)); //(x,y)

    DUNIF(int) randomfood(0,6); // Generate distribution for random food graphics
    randomfud = randomfood(random_number); // Generate random number for food graphics

    // Depending on random number generated, use different image for food-object
    if(randomfud == 0){
            setPixmap(QPixmap(":/image/burger.png")); // Burger
    }
    if(randomfud ==1){
            setPixmap(QPixmap(":/image/donut.png")); // Donut
    }
    if(randomfud == 2){
            setPixmap(QPixmap(":/image/hotdog.png")); // Hotdog
    }
    if(randomfud == 3){
            setPixmap(QPixmap(":/image/onigiri.png")); // Onigiri / Rice-ball
    }
    if(randomfud == 4){
            setPixmap(QPixmap(":/image/soda.png")); // Soda
    }
    if(randomfud == 5){
            setPixmap(QPixmap(":/image/birb.png")); // Bird--eating this loses a life
    }
    else if (randomfud == 6){
            setPixmap(QPixmap(":/image/poop.png")); // Poop--eating this loses a life
    }

    // Connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50); // Move every 50 milliseconds
}

/**
 * @brief Food::move
 * Moves food to the left
 * Tracks collisions in order to decrease lives or increase score
 */
void Food::move(){
    // If food collides with giraffe's head, destroy food
    // Holds all colliding items
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n;++i){
        if (typeid(*(colliding_items[i])) == typeid(Giraffe)){

            // If colliding object is bird or poop(5&6), lose a life
            if(randomfud == 5 || randomfud ==6){

                game->lives->decrease();
                // Remove item from the scene at collision
                scene()->removeItem(this);
                // Free memory & delete
                delete this;
                return;
            }

            //Increase score for all other colliding objects
            else {
                game->score->increase();

                // Remove item from scene at collision
                scene()->removeItem(this);
                //Free memory on heap & deletes food
                delete this;
                return;
            }
        }
    }

    // If food position is past the giraffe's head, lose a life, exclude poop and bird item (5&6)
    if(pos().x()<0 && randomfud < 5){
    game->lives->decrease();

    // Remove the food from the scene
    scene()->removeItem(this);

    //Free memory on heap & deletes food
    delete this;
    return;
    }

    // Move food left

    // If medium difficulty, change move speed to 10
    if(game->difficulty == 2){
        setPos(x()-10,y());
    }
    // If hard difficulty, change move speed to 15
    if(game->difficulty == 3) {

        setPos(x()-15, y());
    }
    // Default / easy difficulty move speed to 7
    else setPos(x()-7,y());
    }
