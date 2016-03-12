#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include <QMainWindow>

namespace Ui {

class GameOverWindow;
}

/**
 * @brief class GameOverWindow
 * represents the window that pops up when the game is over.
 */
class GameOverWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameOverWindow(QWidget *parent = 0);
    ~GameOverWindow();

private slots:
    /**
     * @brief on_pushButton_clicked
     */
    void on_pushButton_clicked();

private:
    Ui::GameOverWindow *ui;
};

#endif // GAMEOVERWINDOW_H
