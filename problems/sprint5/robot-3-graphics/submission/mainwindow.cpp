#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Game& game, Controller& controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , game_(game)
    , controller_(controller)
{
    ui->setupUi(this);

    controller_.SetRedrawCallback([this, last_draw = std::optional<std::chrono::steady_clock::time_point>{}]() mutable {
        repaint();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
