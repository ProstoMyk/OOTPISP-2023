#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QPushButton"
#include "QSpinBox"
#include "QLabel"
#include "QSlider"
#include "QPlainTextEdit"
#include "QTextEdit"
#include "QSize"
#include "QStyle"
#include "QCommonStyle"
#include "QFormLayout"
#include "QPlainTextEdit"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setColor();

    QSpinBox* sb1;
    QSpinBox* sb2;
    QSpinBox* sb3;

    QSlider* sl1;
    QSlider* sl2;
    QSlider* sl3;

    int r_{0};
    int g_{0};
    int b_{0};

    QPlainTextEdit* txtEdit;

private:
    Ui::MainWindow *ui;

public slots:
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);
};
#endif // MAINWINDOW_H
