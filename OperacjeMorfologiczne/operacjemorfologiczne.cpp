#include "operacjemorfologiczne.h"

#include <QPainter>

OperacjeMorfologiczne::OperacjeMorfologiczne(QWidget *parent) : QWidget{parent} {
    im1 = QImage(p_width, p_height, QImage::Format_RGB32);
    im_org.load("C:/Users/rosia/OneDrive/Pulpit/Studia/OperacjeMorfologiczne/OperacjeMorfologiczne/image.png");
    im1=im_org;
    im2=im_org;
}

void OperacjeMorfologiczne::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.fillRect(0, 0, width(), height(), Qt::white);
    p.drawImage(0, 0, im1);
}

void OperacjeMorfologiczne::drawPixel(QPoint p, QColor color) {
    if(p.x()<im1.width() && p.x()>=0 && p.y()<im1.height() && p.y()>=0){
        uchar *pix = im1.scanLine(p.y())+4*p.x();
        pix[0]=color.blue();
        pix[1]=color.green();
        pix[2]=color.red();
    }
}

QColor OperacjeMorfologiczne::readColor(QPoint p){
    uchar *pix = im2.scanLine(p.y())+4*p.x();
    return QColor(pix[2], pix[1], pix[0]);
}

void OperacjeMorfologiczne::dylatacja() {
    for (int y = 0; y < p_height; y++) {
        for (int x = 0; x < p_width; x++) {
            if (readColor(QPoint(x, y)) == Qt::white) {
                for (int i = -promien; i <= promien; i++) {
                    for (int j = -promien; j <= promien; j++)
                        drawPixel(QPoint(x+j, y+i), Qt::white);
                }
            }
        }
    }
    im2 = im1;
    update();
}

void OperacjeMorfologiczne::erozja() {
    for (int y = 0; y < p_height; y++) {
        for (int x = 0; x < p_width; x++) {
            if (readColor(QPoint(x, y)) == Qt::black) {
                for (int i = -promien; i <= promien; i++) {
                    for (int j = -promien; j <= promien; j++)
                        drawPixel(QPoint(x+j, y+i), Qt::black);
                }
            }
        }
    }
    im2 = im1;
    update();
}

void OperacjeMorfologiczne::otwarcie(){
    erozja();
    dylatacja();
}

void OperacjeMorfologiczne::domkniecie(){
    dylatacja();
    erozja();
}

void OperacjeMorfologiczne::slot_dylatacja() {
    dylatacja();
}

void OperacjeMorfologiczne::slot_erozja() {
    erozja();
}

void OperacjeMorfologiczne::slot_domkniecie() {
    domkniecie();
}

void OperacjeMorfologiczne::slot_otwarcie() {
    otwarcie();
}

void OperacjeMorfologiczne::slot_promien(int r) {
    promien=r;
}
