#include "mainwindow.h"
//#include "QPushbutton"
#include <QApplication>
// #include <QPalette>

// class MyWidget : public QPushButton
// {
//     Q_OBJECT

// public:
//     MyWidget(QWidget *parent = nullptr) : QPushButton(parent)
//     {
//         connect(this, &QPushButton::pressed, this, &MyWidget::onButtonPressed);
//         connect(this, &QPushButton::released, this, &MyWidget::onButtonReleased);
//     }

// private slots:
//     void onButtonPressed()
//     {
//         // Change color when pressed
//         QPalette palette = this->palette();
//         palette.setColor(QPalette::Button, Qt::red);
//         this->setPalette(palette);
//     }

//     void onButtonReleased()
//     {
//         // Change color back when released
//         QPalette palette = this->palette();
//         palette.setColor(QPalette::Button, Qt::blue);
//         this->setPalette(palette);
//     }
// };


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
