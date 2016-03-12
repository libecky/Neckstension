#include "neck.h"
#include <QKeyEvent>
#include "giraffe.h"\
#include <QDebug>
#include <iostream>

/**
 * @brief Neck::Neck
 * Sets image for Necky's body, which has to be a different class than the head to
 * not count for collisions
 * @param parent
 */
Neck::Neck(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent){
    // Sets image for Necky's body
    setPixmap(QPixmap(":/image/Neck.png"));
}
