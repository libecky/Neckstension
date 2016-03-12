#include "gameoverwindow.h"
#include "ui_gameoverwindow.h"
#include <QFont>
#include "game.h"
#include "score.h"
#include <QGraphicsTextItem>
#include <QApplication>
#include <QProcess>
#include "mainwindow.h"

// Game over window, aka "game donezo" window
/**
 * @brief GameOverWindow::GameOverWindow
 * Sets up gui for the game over window
 * @param parent
 */
GameOverWindow::GameOverWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameOverWindow)
{
    ui->setupUi(this);
}
/**
 * @brief GameOverWindow::~GameOverWindow
 * Removes from memory/ Destructor
 */
GameOverWindow::~GameOverWindow()
{
    delete ui;
}

/**
 * @brief GameOverWindow::on_pushButton_clicked
 * Restarts game from title screen
 */
void GameOverWindow::on_pushButton_clicked()
{
qApp->quit();
QProcess::startDetached(qApp->arguments()[0], qApp->arguments());

}
