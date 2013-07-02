#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <iostream>
#include <sstream>
#include <string>

#include "Lottonumgen.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_generate_clicked();

public slots:
    void updateLottoNumbersOnGui();

private:
    Ui::MainWindow *ui;
    LottoNumGen *numberGen;
    int numArray[6];
};

#endif // MAINWINDOW_H
