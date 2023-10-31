#ifndef FORM1_H
#define FORM1_H

#include <QMainWindow>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class form1 : public QMainWindow
{
    Q_OBJECT
public:
    form1(QWidget *parent = nullptr);
    ~form1();
private:
    QMainWindow *ui;
signals:

};

#endif // FORM1_H
