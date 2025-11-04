#include "mainwindow.h"
#include "ui_mainwindow.h"

const int d = 70;
const int h = 5;
int cir_x, cir_y;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(800, 600));
    this->statusBar()->setSizeGripEnabled(false);
    cir_x = width() / 2 - d;
    cir_y = height() / 2 - d;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Right) cir_x+=h;
    if (event->key() == Qt::Key_Left) cir_x-=h;
    if (event->key() == Qt::Key_Down) cir_y+=h;
    if (event->key() == Qt::Key_Up) cir_y-=h;
    if (event->key() == Qt::Key_Escape) this->close();
    update();
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter;

    QPen pen;
    pen.setColor(Qt::white);
    pen.setWidth(2);

    QBrush brush;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);

    painter.begin(this);

    painter.setBrush(brush);
    painter.drawRect(0, 0, width(), height());
    painter.setPen(pen);
    painter.drawEllipse(cir_x, cir_y, d, d);

    painter.end();
}
