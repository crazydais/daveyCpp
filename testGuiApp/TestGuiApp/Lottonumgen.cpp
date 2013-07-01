#include "Lottonumgen.h"
#include "mainwindow.h"


using namespace std;


LottoNumGen::LottoNumGen(QObject *parent) :
    QThread(parent)
{

}

LottoNumGen::LottoNumGen(int *numArray)
{
    //  Assign the local pointer 'tempArray' to be equal to the numArray. Since the address of both pointers is the same, numArray in the MainWindow class
    //  will automatically have access to all the values stored in each index of numArray.
    tempArray = numArray;

    //  srand is a global function.  We will only want one instance of this. Originally, this was part of the generateNumber() function, but that was
    //  slowing down the program.
    srand((unsigned)time(NULL));
}

LottoNumGen::~LottoNumGen()
{
    //  nothing     -   destructor
}


int LottoNumGen::generateNumber()
{
    int x = 0;

            //  To win the Irish lotto jackpot, you must match the first six numbers drawn (1 to 45).
            //  Will print out a random number from 0 - 45 (ie, rand()%46)
            x = rand()%46;

            //  0 is not a valid lotto number, so it can't be used
            if(x != 0)
            {
                //cout << x << endl;
            }
            else
            {
                //cout << x + rand()%46 + 1 << endl;
                x = x + 1;
            }

    return x;
}

void LottoNumGen::run()
{

    cout << "Thread running..." << endl;

    //  Create a temp int var 'i' and init it to 0
    int i = 0;

    //  Populate our tempArray with six unique numbers...
    for(int j = 0; j < 6; j++)
    {
        //  Assign a new random value to i by calling the function generateNumber()
        i = this->generateNumber();

        if(j > 0)
        {
            //  To prevent duplicate numbers.  If a number already exsits in the array, get another number...
            //  This for loop will only check up to the current length of the array. Eg, no point in check the whole array if only 3 out of 6 numbers have been entered.
            for(int k = 0; k < j; k++)
            {
                //  This condition checks if the current value of i is the same as the number stored in the current index of the array...
                if(i == tempArray[k])
                {
                    //  if it is the same, generate a new number for i and start checking from index 0 all over again...
                    cout << "caught duplicate" << endl;
                    i = this->generateNumber();
                    k = 0;
                }
            }
        }

        //  if the random number generated for i is not the same as any of the numbers stored in the array, then add the number to the array at that point...
        tempArray[j] = i;
    }

    //  After the tempArray has been filled with unique numbers, call the updateLottoNumbersOnGui() function on the MainWindow to update the labels...
    emit updateLottoNumbersOnGui();
}

