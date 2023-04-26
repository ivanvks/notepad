#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>

#include "htmlparser.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

private:
    QGridLayout *mainGrid; 
    QPushButton *push_button_1;
    
    Html_pars *html_pars;

 public slots:

    void push_button_1_clicked();
   
};
#endif // MAINWINDOW_H
