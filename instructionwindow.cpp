#include "instructionwindow.h"
#include "ui_instructionwindow.h"


/**
 * @brief InstructionWindow::InstructionWindow
 * Sets up gui for the instruction screen
 * @param parent
 */
InstructionWindow::InstructionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InstructionWindow)
{
    ui->setupUi(this);

}

/**
 * @brief InstructionWindow::~InstructionWindow
 * Deletes from memory/ Destructor
 */
InstructionWindow::~InstructionWindow()
{
    delete ui;
}
