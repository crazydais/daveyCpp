#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Lottonumgen.h"


using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //  Create an instance of Lottonumgen and pass it the numArray by casting it as an int pointer 'int *'
    numberGen = new LottoNumGen((int*) numArray);

    //  Then we can connect our signals and slots
    connect(numberGen, SIGNAL(updateLottoNumbersOnGui()), this, SLOT(updateLottoNumbersOnGui()));

    //  Call 'on_pushButton_generate_clicked()' to generate numbers on startup...
    MainWindow::on_pushButton_generate_clicked();



    /*      Programmatically Set the Alignment of a 'label'...
        ui->label_1->setAlignment(Qt::AlignCenter);
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_generate_clicked()
{
    for(int i = 0; i < 6; i++)
    {
        numArray[i] = 0;
    }





    numberGen->start();


    // ui->pushButton_generate->setEnabled(false);

    //  This sleep will allow enough time for the thread to run so the GUI thread can update the label values...
    //sleep(1);
    cout << " ---- " << endl;
}

void MainWindow::updateLottoNumbersOnGui()
{
    cout << "update gui..." << endl;

    stringstream ss;

    ss << numArray[0] << endl;
    ui->label_num_01->setText(QString::fromStdString(ss.str()));
    ss.str(std::string());      //  clears the contents of a stringstream
    ss.clear();                 //   set any "eofbit" (end-of-file) error state back to "goodbit" (no error).

    ss << numArray[1] << endl;
    ui->label_num_02->setText(QString::fromStdString(ss.str()));
    ss.str(std::string());
    ss.clear();

    ss << numArray[2] << endl;
    ui->label_num_03->setText(QString::fromStdString(ss.str()));
    ss.str(std::string());
    ss.clear();

    ss << numArray[3] << endl;
    ui->label_num_04->setText(QString::fromStdString(ss.str()));
    ss.str(std::string());
    ss.clear();

    ss << numArray[4] << endl;
    ui->label_num_05->setText(QString::fromStdString(ss.str()));
    ss.str(std::string());
    ss.clear();

    ss << numArray[5] << endl;
    ui->label_num_06->setText(QString::fromStdString(ss.str()));
    ss.str(std::string());
    ss.clear();
}


