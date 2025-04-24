#pragma once

#include <QMainWindow>
#include <prac/QTimer>
#include <prac/QMediaPlayer>
#include <prac/QTime>
#include <prac/QDateTime>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QDateTime GetAlarmMoment() const {
        return alarm_moment_;
    }

private slots:
    // Тут объявите слоты.
    void on_pb_start_stop_clicked();

private:
    void ChangeAudio();
    void OnTimer();
    void ProcessAlarm();
    QString TimeToString(QTime time);
    QString TimeToString(std::chrono::milliseconds ms);

private:
    Ui::MainWindow *ui;
    QDateTime alarm_moment_;
    prac::QTimer timer_one_sec_{this};
    prac::QMediaPlayer player_{this};
    QAudioOutput audio_output_{this};
};
