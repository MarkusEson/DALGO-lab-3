#include "ragnarstest.h"
#include "studentssortings.h"

#include <iostream>
#include <string>

using namespace std;



typedef void(*sortFunction)(float* pBegin,  float* pEnd);



/**************************************************************
ANROP:     swap((a),(b));
VERSION:   2005-10-05 NORA
UPPGIFT:   Byter a mot b.
**************************************************************/
static void swap(float &a, float &b)
{
    float tmp = a;
    a = b;
    b = tmp;
}// swap


// Testar om angiven sorteringsalgoritm fungerar.
// Felutskrift om så inte är fallet.
// Returnerar true omm ok.
bool testAlgorithm(sortFunction simpleSort, string name){

    const int size = 100;
    // skapa en sekvens (seq) av slumptal sorterad i stigande ordn.
    float seq[size];
    seq[0] = -10; // size;
    for (int i = 1; i<size; ++i)
    {
        float d = (float)rand() / RAND_MAX;
        seq[i] = seq[i - 1] + d; // - d;
    }

    // låt mixed innehålla samma tal men i slumpordning
    // pÂ varje sida utanför arrayen ligger det en 1a, som
    // ej får ändras av sorteringsalgoritmenn

    float mixedExtraLarge[size + 2];
    float *mixed = &mixedExtraLarge[1]; // -1...size
    for (int i = 0; i<size; ++i)
        mixed[i] = seq[i];
    for (int i = 0; i<size; ++i)
        swap((mixed[i]), (mixed[rand() % size]));
    mixed[-1] = 1;
    mixed[size] = 1;
    // testa att simpleSort fungerar
    simpleSort( &mixed[0], &mixed[size]);

    bool ok = true;
    if (mixed[-1] != 1 || mixed[size] != 1){
        cout << "BUG: Algoritmen " << name << " skriver utanför (array)minnet!\7\n";
        ok = false;
    }

    if (ok)
        for (int i = 0; i<size; ++i)
            if (mixed[i] != seq[i])
            {
                cout << "BUG: i algoritm " << name <<  " mixed[" << i << "]==" << mixed[i] <<" != " << seq[i] << endl;
                ok = false;
            }

    return ok;

}

//***********************************************************************
// ANROP:   ragnarsTest( myIdentity );
// VERSION: 2010-01-15
// UPPFIFT: Testar en eller flera rutiner som studenten har skrivit.
//***********************************************************************
bool ragnarsTest(const string& myIdentity){
    setlocale(LC_ALL, "Swedish" );
    if (myIdentity.find("Homer")!=string::npos){
        std::cerr << "Felaktig identitet : " << myIdentity << "\7\7\n";
        std::cerr << "Använd DITT förnamn och de sista 4 siffrorna i DITT personnunmmer!!\n";
        system("pause");
        exit( 0 );
    }

    bool ok =   testAlgorithm(bubbleSort, "bubbleSort")
            && testAlgorithm(insertSort, "insertSort");


    if (ok)
        cout << "Grattis, självtesten lyckades!!!" << endl;


    return ok;
}// ragnarsTest
