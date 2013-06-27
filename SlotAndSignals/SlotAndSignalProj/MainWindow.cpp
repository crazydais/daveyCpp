#include "MainWindow.h"
#include "ui_MainWindow.h"


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(sig, SIGNAL(sendASignal()), this, SLOT(on_sendASignal()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::on_sendASignal()
{
    cout << "mainwindow received the signal" << endl;
}

