#ifndef LOTTONUMGEN_H
#define LOTTONUMGEN_H

#include <QThread>
#include <QtCore>
class LottoNumGen : public QThread
{
    Q_OBJECT
public:
    explicit LottoNumGen(QObject *parent = 0);

    //  Constrctor declarations
    LottoNumGen(int *numArray = 0);

    //  Destructor declaration
    ~LottoNumGen();

    //  Setter/Getters

    //  Function Declarations
    int generateNumber(int);
    void run();     //  override QThread run() function...

private:

    int *tempArray;
    
signals:

    //  Call a slot on the mainwindow class to update the gui when the number gen has finished
    void updateLottoNumbersOnGui();
    
public slots:
    
};

#endif // LOTTONUMGEN_H
