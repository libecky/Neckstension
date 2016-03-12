#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

/**
 * @brief MainWindow::MainWindow
 * Sets up gui for title screen
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
/**
 * @brief MainWindow::~MainWindow
 * Destructor
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::setGame
 * Sets private game pointer to the one passed in
 * @param g
 */
void MainWindow::setGame(Game* g) {
    game = g;
}

/**
 * @brief MainWindow::setInstruction
 * Sets private game pointer to the one passed in
 * @param i
 */
void MainWindow::setInstruction(InstructionWindow* i) {
    instruction = i;
}


/**
 * @brief MainWindow::on_pushButton_clicked
 * Starts the game, hides title screen
 */
void MainWindow::on_pushButton_clicked()
{
    game->start();
    hide();
}

/**
 * @brief MainWindow::on_pushButton_2_clicked
 * Opens instruction window
 */
void MainWindow::on_pushButton_2_clicked()
{
   instruction->show();
}

/**
 * @brief MainWindow::on_radioButton_2_clicked
 * Sets difficulty to 1 (int) if checked
 * @param checked
 */
void MainWindow::on_radioButton_2_clicked(bool checked)
{
    game->difficulty = 1;
}

/**
 * @brief MainWindow::on_radioButton_clicked
 * Sets difficulty to 2
 * @param checked
 */
void MainWindow::on_radioButton_clicked(bool checked)
{
    game->difficulty = 2;
}

/**
 * @brief MainWindow::on_radioButton_3_clicked
 * Sets difficulty to 3
 * @param checked
 */
void MainWindow::on_radioButton_3_clicked(bool checked)
{
    game->difficulty = 3;
}
