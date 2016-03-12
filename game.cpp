#include "giraffe.h"
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include "game.h"
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include "food.h"
#include "lives.h"
#include "neck.h"
#include <QImage>
#include <QMediaPlayer>

/**
 * @brief Game::Game
 * Game class, adds objects to window/ scene
 * @param parent
 */
Game::Game(QWidget *parent){}

/**
 * @brief Game::start
 * Starts the scene
 */
void Game::start() {
    // Create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,900,600);

    // Set background image
    setBackgroundBrush(QImage(":/image/background.png"));
    setScene(scene);

    // Remove scroll bars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // View is widget and therefore invisible until show
    setFixedSize(900,600);

    // Create Necky's head to be put into the scene
    giraffe = new Giraffe();
    //Set at 0 x and 0 y coordinate, then width x height
    giraffe->setPos(38, 287);
    // Create the neck to be added to the scene
    neck = new Neck();
    neck->setPos(0,300);

    // Use QGraphicsItemGroup to group Necky and her neck in order for objects to move simultaneously
    group = new QGraphicsItemGroup;
    group->addToGroup(giraffe); // Add Necky to group
    group->addToGroup(neck); // Add neck to group
    group->setFlag(QGraphicsItem::ItemIsFocusable); // Make group focusable in order for successful key press
    group->setFocus(); // Set the focus to the group object

    // Add the group to the scene
    scene->addItem(group);

    // Create the score
    score = new Score();
    scene->addItem(score);

    // Create the lives
    lives = new Lives();
    lives->setGame(this);
    lives->setPos(lives->x(), lives->y()+40);
    scene->addItem(lives);


    // Spawn food
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),giraffe, SLOT(spawn()));

    // If difficulty is medium, spawn food every 1 second
    if(difficulty == 2){
        timer->start(1000);
    }
    // If difficulty is hard, spawn food every 0.5 a second
    else if(difficulty == 3){
        timer->start(800);
    }
    // Default to spawning every 2 seconds for easy mode & if things go horribly wrong
    else {timer->start(2000);}

    // Play music
    QMediaPlayer * moosic = new QMediaPlayer();

    // Set music file
    moosic->setMedia(QUrl("qrc:/sound/beepbeep.wav"));

    // Add timer to loop music
    QTimer * moosictimer = new QTimer();
    moosic->play();

    // Loop music
    QObject::connect(moosictimer, SIGNAL(timeout()), moosic, SLOT(play()));
    moosictimer->start(10);

    // Show everything
    show();
}

/**
 * @brief Game::gameOver
 * Shows gameover, aka "game donezo" window
 */
void Game::gameOver() {
    over->show(); // Show game over window
    hide(); // Hide game
}

/**
 * @brief Game::setGameOver
 * Sets private game pointer to the one passed in
 * @param o
 */
void Game::setGameOver(GameOverWindow* o) {
    over = o;
}

/**
 * @brief Game::keyPressEvent
 * Moves the QGraphicsItemGroup up and down, allows for head and neck to move simultaneously
 * @param event is the up or down key press
 */
void Game::keyPressEvent(QKeyEvent * event){
    if(event->key()== Qt::Key_Up){
        // Upper bound
        if(group->pos().y()>-225){
        group->moveBy(0,-10); // 10 pixels up for every up-arrow key press
        }
    }
    else if(event->key()== Qt::Key_Down){
        // Lower bound
        if(group->pos().y()<200){
            group->moveBy(0,10); // 10 pixels down for every down-arrow key press
        }
    }
}

