#include "form1.h"
#include "ui_form1.h"

form1::form1(QWidget *parent)
    : QMainWindow{parent}
{

}

form1::~form1()
{
    delete ui;
}
