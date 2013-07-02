#ifndef LOTTONUMBERGENERATOR_H      //  This is an include guard. It states that,
#define LOTTONUMBERGENERATOR_H      //  IF lottonumbergenerator is NOT DEFINED, the DEFINE it.

//  include required headers for the class
#include <QObject>
#include <QThread>


class LottoNumberGenerator : public QThread
{
    Q_OBJECT

    public:
        //  Constrctor declarations
        LottoNumberGenerator(QObject *parent = 0);
        LottoNumberGenerator(int *numArray = 0);

        //  Destructor declaration
        ~LottoNumberGenerator();

        //  setter/getters declarations

        //  Function declarations
        int generateNumber(int);

        void run();     //  override QThread run() function...

    protected:


    private:

        int *tempArray;

    signals:

        //  Call a slot on the mainwindow class to update the gui when the number gen has finished
        void updateLottoNumbersOnGui();

    public slots:

};


#endif // LOTTONUMBERGENERATOR_H
