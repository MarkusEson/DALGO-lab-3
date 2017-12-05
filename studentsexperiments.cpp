

// Utför dina 9 körexperiment här (se uppdragshäftet)

#include <QElapsedTimer>
#include <QTimer>
#include <iostream>

#include "studentsexperiments.h"

using namespace std;


// Denna funktion används bara av min exempelkod som avser att
// demonstrera hur man använder QElapsedTimer

long int dumFunktionSomTarLiteTid(){
    long int bigNumber = 1000000000;

    long int theSum = 0;
    for (long int i= 0 ; i<bigNumber ; i+=1)
        theSum += (i % 10);
    return theSum;
}


void nineRuntimeExperiments(){


    // Samla in det data som du sedan skall redovisa i en pdf!

    // Se till så att du kör i "Release mode" när du utför dessa experiment!


    // Nedanstående kod visar hur man mäter tid med hjälp av QElapsedTimer
    // När du förstått detta kan du sudda ut koden.


    QElapsedTimer myTimer;

    myTimer.start();
    long int theSum = dumFunktionSomTarLiteTid();
    cout << "det tog " << myTimer.elapsed() << " ms  att beräkna summan " << theSum << endl;

    // Vi gör samma experimenyt igen. Tror du att det tar lika lång tid?

    myTimer.start();
    theSum = dumFunktionSomTarLiteTid();
    cout << "Nu tog det " << myTimer.elapsed() << " ms  att beräkna summan " << theSum << endl;

    // Vi gör samma experiment en tredje gång. Tror du att det tar lika lång tid?

    myTimer.start();
    theSum = dumFunktionSomTarLiteTid();
    cout << "Nu tog det " << myTimer.elapsed() << " ms  att beräkna summan." << endl;


}


