#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->l_result->setText("0");
    ui->l_memory->setText("");
    ui->l_formula->setText("");
}

MainWindow::~MainWindow() {
    delete ui;
}

QString RemoveTrailingZeroes(const QString &text) {
    for (qsizetype i = 0; i < text.size(); ++i) {
        if (text[i] != '0') {
            return text.mid(i);
        }
    }
    return "";
}

QString NormalizeNumber(const QString &text) {
    if (text.isEmpty()) {
        return "0";
    }
    if (text.startsWith('.')) {
        // Рекурсивный вызов.
        return NormalizeNumber("0" + text);
    }
    if (text.startsWith('-')) {
        // Рекурсивный вызов.
        return "-" + NormalizeNumber(text.mid(1));
    }
    if (text.startsWith('0') && !text.startsWith("0.")) {
        return NormalizeNumber(RemoveTrailingZeroes(text));
    }
    return text;
}

QString OpToString(Operation op) {
    switch(op) {
    case Operation::NO_OPERATION: return "";
    case Operation::ADDITION: return "+";
    case Operation::DIVISION: return "÷";
    case Operation::MULTIPLICATION: return "×";
    case Operation::SUBTRACTION: return "−";
    case Operation::POWER: return "^";
    }
}

void MainWindow::SetText(const QString& text) {
    input_number_ = NormalizeNumber(text);
    ui->l_result->setText(input_number_);
    active_number_ = input_number_.toDouble();
}

void MainWindow::AddText(const QString& suffix) {
    input_number_ += suffix;
    SetText(input_number_);
}

void MainWindow::on_tb_zero_clicked()
{
    AddText("0");
}


void MainWindow::on_tb_one_clicked()
{
    AddText("1");
}


void MainWindow::on_tb_two_clicked()
{
    AddText("2");
}


void MainWindow::on_tb_three_clicked()
{
    AddText("3");
}


void MainWindow::on_tb_four_clicked()
{
    AddText("4");
}


void MainWindow::on_tb_five_clicked()
{
    AddText("5");
}


void MainWindow::on_tb_six_clicked()
{
    AddText("6");
}


void MainWindow::on_tb_seven_clicked()
{
    AddText("7");
}


void MainWindow::on_tb_eight_clicked()
{
    AddText("8");
}


void MainWindow::on_tb_nine_clicked()
{
    AddText("9");
}


void MainWindow::on_tb_comma_clicked()
{
    if (!input_number_.contains('.')) {
        AddText(".");
    }
}


void MainWindow::on_tb_backspace_clicked()
{
    if (!input_number_.isEmpty()) {
        input_number_.chop(1);
        SetText(input_number_);
    }
}


void MainWindow::on_tb_add_clicked()
{
    input_number_ = "0";
    current_operation_ = Operation::ADDITION;
    QString operation = OpToString(current_operation_);
    Number left_number = active_number_;
    calculator_.SetLeftOperand(left_number);
    ui->l_formula->setText(QString("%1 %2 =").arg(left_number).arg(operation));
}


void MainWindow::on_tb_substract_clicked()
{
    input_number_ = "0";
    current_operation_ = Operation::SUBTRACTION;
    QString operation = OpToString(current_operation_);
    Number left_number = active_number_;
    calculator_.SetLeftOperand(left_number);
    ui->l_formula->setText(QString("%1 %2 =").arg(left_number).arg(operation));
}


void MainWindow::on_tb_multiplicate_clicked()
{
    input_number_ = "0";
    current_operation_ = Operation::MULTIPLICATION;
    QString operation = OpToString(current_operation_);
    Number left_number = active_number_;
    calculator_.SetLeftOperand(left_number);
    ui->l_formula->setText(QString("%1 %2 =").arg(left_number).arg(operation));
}


void MainWindow::on_tb_divide_clicked()
{
    input_number_ = "0";
    current_operation_ = Operation::DIVISION;
    QString operation = OpToString(current_operation_);
    Number left_number = active_number_;
    calculator_.SetLeftOperand(left_number);
    ui->l_formula->setText(QString("%1 %2 =").arg(left_number).arg(operation));
}


void MainWindow::on_tb_power_clicked()
{
    input_number_ = "0";
    current_operation_ = Operation::POWER;
    QString operation = OpToString(current_operation_);
    Number left_number = active_number_;
    calculator_.SetLeftOperand(left_number);
    ui->l_formula->setText(QString("%1 %2 =").arg(left_number).arg(operation));
}


void MainWindow::on_tb_negate_clicked()
{
    if (input_number_.startsWith("-")) {
        SetText(input_number_.mid(1));
    } else {
        SetText("-" + input_number_);
    }
}


void MainWindow::on_tb_reset_clicked()
{
    input_number_ = "0";
    active_number_ = 0;
    ui->l_result->setText("0");
    ui->l_formula->setText("");
}


void MainWindow::on_tb_ms_clicked()
{
    memory_value_ = active_number_;
    has_memory_ = true;
    ui->l_memory->setText("M");
}


void MainWindow::on_tn_mr_clicked()
{
    if (has_memory_) {
        SetText(QString::number(memory_value_));
    }
}


void MainWindow::on_tb_mc_clicked()
{
    has_memory_ = false;
    memory_value_ = 0;
    ui->l_memory->clear();
}


void MainWindow::on_tb_equal_clicked()
{
    if (current_operation_ == Operation::NO_OPERATION){
        ui->l_result->setText("0");
        ui->l_formula->setText("");
        return;
    } else {
        Number right_number = input_number_.toDouble();
        calculator_.SetRightOperand(right_number);
        Number result;

        switch (current_operation_) {
        case Operation::ADDITION:
            result = calculator_.Add();
            break;
        case Operation::SUBTRACTION:
            result = calculator_.Sub();
            break;
        case Operation::MULTIPLICATION:
            result = calculator_.Mul();
            break;
        case Operation::DIVISION:
            result = calculator_.Div();
            break;
        case Operation::POWER:
            result = calculator_.Pow();
            break;
        default:
            return;
        }

        QString left_str = QString::number(calculator_.GetLeftOperand());
        QString right_str = QString::number(right_number);
        QString result_str = QString::number(result);
        QString operation_str = OpToString(current_operation_);

        ui->l_result->setText(result_str);
        ui->l_formula->setText(QString("%1 %2 %3 =").arg(left_str).arg(operation_str).arg(right_str));

        input_number_ = "0";
        active_number_ = result;
        current_operation_ = Operation::NO_OPERATION;
    }
}

