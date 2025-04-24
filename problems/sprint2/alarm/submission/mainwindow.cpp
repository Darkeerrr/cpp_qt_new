#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <prac/QFileDialog>
#include <QFileInfo>
#include <chrono>

QString MainWindow::TimeToString(QTime time) {
    return QString("%1:%2:%3").arg(time.hour(), 2, 10, QChar('0')).arg(time.minute(), 2, 10, QChar('0')).arg(time.second(), 2, 10, QChar('0'));
}

QString MainWindow::TimeToString(std::chrono::milliseconds ms) {
    return TimeToString(QTime::fromMSecsSinceStartOfDay(ms.count() + 500));
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player_.setAudioOutput(&audio_output_);
    audio_output_.setVolume(10);

    timer_one_sec_.setSingleShot(true);
    connect(&timer_one_sec_, &prac::QTimer::timeout, this, &MainWindow::OnTimer);
    OnTimer();
    connect(ui->action_load_file, &QAction::triggered, this, &MainWindow::ChangeAudio);
    connect(ui->action_close, &QAction::triggered, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnTimer() {
    auto now = prac::QTime::currentTime();
    ui->lbl_now->setText(TimeToString(now));

    ProcessAlarm();

    int delay = 1000 - now.msec();
    timer_one_sec_.start(delay);
}

void MainWindow::ProcessAlarm() {
    if (alarm_moment_ == prac::QDateTime()) {
        ui->lbl_timeout->setText("Установите будильник");
        return;
    }

    auto now = prac::QDateTime::currentDateTime();
    if (now >= alarm_moment_) {
        ui->lbl_timeout->setText("Пора вставать");
        if (player_.playbackState() != prac::QMediaPlayer::PlayingState) {
            player_.play();
        }
    } else {
        // Используем chrono для точности
        const auto msecs_to_alarm = std::chrono::milliseconds(now.msecsTo(alarm_moment_));

        // Используем вашу функцию форматирования
        ui->lbl_timeout->setText(TimeToString(msecs_to_alarm));
    }
}

void MainWindow::ChangeAudio() {
    QString file_name = prac::QFileDialog::getOpenFileName(this,
                                                     QString::fromUtf8("Открыть файл"),
                                                     QDir::currentPath(),
                                                     "*.wav;*.mp3");
    if (!file_name.isEmpty()) {
        player_.setSource(file_name);
        ui->lbl_melody->setText(QFileInfo(file_name).fileName());
    }
}

void MainWindow::on_pb_start_stop_clicked() {
    if (alarm_moment_ == QDateTime()) {
        auto now = prac::QDateTime::currentDateTime();
        QTime alarm_time(ui->sb_hour->value(), ui->sb_min->value(), ui->sb_sec->value());
        alarm_moment_ = QDateTime(now.date(), alarm_time);

        if (alarm_moment_ < now) {
            alarm_moment_ = alarm_moment_.addDays(1);
        }

        ui->pb_start_stop->setText("Стоп");
    } else {
        alarm_moment_ = QDateTime();
        player_.stop();
        ui->pb_start_stop->setText("Старт");
    }

    ProcessAlarm();
}
