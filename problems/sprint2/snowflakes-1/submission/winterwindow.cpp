#include "winterwindow.h"
#include "ui_winterwindow.h"
#include <QColorDialog>
#include <QPaintEvent>

WinterWindow::WinterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WinterWindow)
{
    ui->setupUi(this);
}

WinterWindow::~WinterWindow()
{
    delete ui;
}

void WinterWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    prac::QPainter painter(this);
    painter.setPen(Qt::black);
    double size = double(ui->sld_size->value());

    SnowFlakeParams flake_params{
        flake_params.center = {width() / 2., height() / 2.},
        flake_params.color = color_,
        flake_params.size = size,
        flake_params.line_width = ui->sld_line->value() / 15.,
        flake_params.rotation = double(ui->sld_rotation->value())
    };

    // Создайте снежинку (объект класса SnowFlake) и нарисуйте её методом Draw.
    SnowFlake snowflake(flake_params);
    snowflake.Draw(painter);

    QRect rect(10, 10, width() - 20, height() - 20);

    QFont font("Verdana", 12);
    painter.setFont(font);
    painter.setPen(Qt::white);

    // Получите описание снежинки из метода GetDescription,
    // напечатайте этот текст в прямоугольнике rect.
    QString description = snowflake.GetDescription();
    painter.drawText(rect, Qt::AlignTop | Qt::AlignLeft, description);
}

void WinterWindow::on_btn_color_clicked()
{
    QColorDialog dialog{color_};
    dialog.exec();
    color_ = dialog.selectedColor();
    update();
}
