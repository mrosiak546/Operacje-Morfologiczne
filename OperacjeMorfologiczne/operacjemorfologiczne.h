#ifndef OPERACJEMORFOLOGICZNE_H
#define OPERACJEMORFOLOGICZNE_H

#include <QWidget>

class OperacjeMorfologiczne : public QWidget
{
    Q_OBJECT
public:
    explicit OperacjeMorfologiczne(QWidget *parent = nullptr);
private:
    void paintEvent(QPaintEvent *);
    void drawPixel(QPoint p, QColor color);
    QColor readColor(QPoint p);

    void dylatacja();
    void erozja();
    void otwarcie();
    void domkniecie();

    QImage im1, im2, im_org;
    int promien;
    int p_width=500, p_height=500;

signals:
public slots:
    void slot_dylatacja();
    void slot_erozja();
    void slot_domkniecie();
    void slot_otwarcie();
    void slot_reset();
    void slot_promien(int r);
};

#endif // OPERACJEMORFOLOGICZNE_H
