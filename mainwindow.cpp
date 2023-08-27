#include <QString>
#include <QMessageBox>
#include <QApplication>
#include <QClipboard>
#include <QWidget>
#include <QToolTip>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "util.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mediaPlayer(new QMediaPlayer)
{
    ui->setupUi(this);

    connect(mediaPlayer, &QMediaPlayer::stateChanged, this, [=](QMediaPlayer::State state){
        if(state == QMediaPlayer::StoppedState){
            mediaPlayer->stop();
            mediaPlayer->setPosition(0);
        }
    });

	// 遍历widget下所有QPushButton控件
	QList<QPushButton *> buttons = this->findChildren<QPushButton *>();
	foreach(QPushButton *button, buttons) {
		connect(button, &QPushButton::clicked, this, [=]() {
            /*
            auto nowTime = QDateTime::currentDateTime();
            if(clickTime.isValid())
            {
                qint64 elapsedTime = clickTime.msecsTo(nowTime);
                if(elapsedTime < 500)
                {
                    //没满500毫秒，不能2次点击
                    return;
                }
            }
            clickTime = nowTime;
            */

			QString buttonText = button->text();
			QString buttonName = button->objectName();
			
			//播放语音
            if(mediaPlayer->state() == QMediaPlayer::PlayingState) mediaPlayer->stop();
            QUrl url = QUrl(QString("qrc:/audio/%1.mp3").arg(buttonName));
            if (mediaPlayer->media().canonicalUrl() != url) {
                mediaPlayer->setMedia(url);
            }
            mediaPlayer->play();

			//复制到剪贴板
			QClipboard *clip = QApplication::clipboard();
			clip->setText(buttonText);
			//第一次提示一下
            ShowMessageBox(QString("text has been copied to the clipboard (notification will only appear once)"), true);
		});
	}
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mediaPlayer;
}

