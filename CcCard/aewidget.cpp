#include "aewidget.h"
#include <QDebug>
#include <QPainter>


AEWidget::AEWidget(QString strImgDir, QSize size, QWidget *parent): QWidget(parent)
{
setAttribute(Qt::WA_TranslucentBackground, true);
    this->resize(size);
    imgSize=size;
    setImgDir(strImgDir);
}



void AEWidget::setImgDir(QString strImgDir)
{
    if(m_strImgDir == strImgDir)
            return ;
        else
            m_strImgDir = strImgDir;


        stopAE();
        QDir tmpDir(m_strImgDir);
        QFileInfoList listInfo = tmpDir.entryInfoList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot,QDir::Name);
        if(listInfo.isEmpty()){
            qWarning()<<"AE Dir is Empty!";
            return ;
        }

        m_strListImg.clear();
        foreach(QFileInfo strFileInfo,listInfo){
            m_strListImg.append(strFileInfo.filePath());
        }

//        this->resize(QImage(m_strListImg.first()).size());
//        this->show();
//        startAE();
}

void AEWidget::closeAE()
{
    m_strImgDir = "";
       stopAE();
       this->hide();
}

void AEWidget::stopAE()
{
    if(0 == m_nTimerId)
           return ;

       killTimer(m_nTimerId);
       m_nTimerId = 0;
}

void AEWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
        if(m_nIndex > (m_strListImg.size() - 1))
            return ;

        QPainter painter(this);
        QImage image(m_strListImg[m_nIndex]);
        image=image.scaled(imgSize);
        painter.drawImage(QPointF(0,0),image);

        m_nIndex++;
        m_nIndex = (m_nIndex)%m_strListImg.size();
}

void AEWidget::timerEvent(QTimerEvent *event)
{

    Q_UNUSED(event)
    this->update();
}
