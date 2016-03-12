#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject> //Any class using signals and slots must derive from QObject

/**
 * @brief The Food class
 * represents the flying objects in the game--both friend and enemy. Food graphics
 * are randomized using randomfud. move() moves the food objects.
 */
class Food: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    /**
     * @brief Food
     * @param parent
     */
    Food(QGraphicsItem * parent = 0);

    // Used to randomize food graphics
    int randomfud;

    // Used to randomize foodspeed--might not use
    int foodspeed;

public slots:

    /**
     * @brief move - moves food objects
     */
    void move();
};

#endif // FOOD_H
