#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->dylatacja,SIGNAL(clicked()),ui->widget,SLOT(slot_dylatacja()));
    connect(ui->erozja,SIGNAL(clicked()),ui->widget,SLOT(slot_erozja()));
    connect(ui->domkniecie,SIGNAL(clicked()),ui->widget,SLOT(slot_domkniecie()));
    connect(ui->otwarcie,SIGNAL(clicked()),ui->widget,SLOT(slot_otwarcie()));

    connect(ui->slider_promien, SIGNAL(valueChanged(int)), ui->widget, SLOT(slot_promien(int)));
    connect(ui->spinBox_promien, SIGNAL(valueChanged(int)), ui->widget, SLOT(slot_promien(int)));
    connect(ui->slider_promien,  &QSlider::valueChanged, ui->spinBox_promien, &QSpinBox::setValue);
    connect(ui->spinBox_promien, QOverload<int>::of(&QSpinBox::valueChanged), ui->slider_promien, &QSlider::setValue);

    ui->slider_promien->setRange(1, 10);
    ui->spinBox_promien->setRange(1, 10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

