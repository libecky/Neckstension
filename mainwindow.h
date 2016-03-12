#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include "instructionwindow.h"

namespace Ui {
class MainWindow;
}
/**
 * @brief The MainWindow class
 * represents the title screen
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setGame(Game* g);
    void setInstruction(InstructionWindow* i);

private slots:

    // Button functions

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_2_clicked(bool checked);

    void on_radioButton_clicked(bool checked);

    void on_radioButton_3_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    Game* game;
    InstructionWindow* instruction;
};

#endif // MAINWINDOW_H
