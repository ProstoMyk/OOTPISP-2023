#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow> //210665
#include <QVBoxLayout>//210665
QT_BEGIN_NAMESPACE//210665
namespace Ui { class MainWindow; } //210665
QT_END_NAMESPACE//210665
class MainWindow : public QMainWindow //210665
{ //210665
    Q_OBJECT
public: //210665
    MainWindow(QWidget *parent = nullptr); //210665
    ~MainWindow(); //210665
private: //210665
    Ui::MainWindow *ui; //210665
}; //210665
#endif // MAINWINDOW_H //210665
