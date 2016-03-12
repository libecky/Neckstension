#ifndef INSTRUCTIONWINDOW_H
#define INSTRUCTIONWINDOW_H

#include <QMainWindow>


namespace Ui {


class InstructionWindow;
}

/**
 * @brief class InstructionWindow
 * represents the instruction window. This pops up if you click the
 * "Instructions" button on the title screen.
 */
class InstructionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InstructionWindow(QWidget *parent = 0);
    ~InstructionWindow();

private:
    Ui::InstructionWindow *ui;
};

#endif // INSTRUCTIONWINDOW_H
