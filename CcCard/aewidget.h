#ifndef AEWIDGET_H
#define AEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QDir>
#include <QFileInfoList>


class AEWidget  : public QWidget
{
    Q_OBJECT
 public:
     explicit AEWidget(QString strImgDir,QSize size,QWidget *parent = nullptr);

     void setImgDir(QString strImgDir); //传入图片文件夹路径  就会自动开始播放 50ms刷一帧
     void closeAE(); //关闭动画显示  停止刷新
     void startAE(){m_nTimerId = startTimer(50);}
     void stopAE();
 private:

 protected:
     void paintEvent(QPaintEvent *event);
     void timerEvent(QTimerEvent *event);
 private:
     QTimer *m_pTimer = nullptr;
     QString m_strImgDir = "";
     QStringList m_strListImg;
     QSize imgSize;
     int m_nIndex = 0;
     int m_nTimerId = 0;
};

#endif // AEWIDGET_H
