#include <QApplication> //210665_88
#include "customwidget.h"//210665_8
int main(int argc, char *argv[]) //210665_88
{ //210665_88
    QApplication a(argc, argv); //210665_88
    CustomWidget w; //210665_88
    w.show(); //210665_8_88
    return a.exec(); //210665_88
} //210665_88
