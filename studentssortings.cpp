#include "studentssortings.h"

#include <algorithm>
#include <iostream>
#include <QDebug>

using namespace std;


static void swap(float &a, float &b){
    float x = a;
    a = b;
    b = x;
}


/**********************************************************************************
 * ANROP:   bubbleSort( pBegin, pEnd);
 * UPPGIFT: pBegin och pEnd definierar en array av element (pBegin pekar på det
 *          första elementet och pEnd EFTER det sista).
 *          Funktionen sorterar arrayen så att det minsta elementet hamnar först.
 *
 *          Algoritmen som används måste vara den version av bubbleSort som
 *          beskrivs i uppdragshäftet!!
 * ********************************************************************************/
void bubbleSort(float *pBegin, float *pEnd){

    // minst <---> störst
    float size = pEnd - pBegin;

    while(size > 0)
    {
        for(int i = 0; i < size-1; i++)
        {
            float *val1 = pBegin + i;
            float *val2 = pBegin + i + 1;

            if(*val1 > *val2)
            {
                swap(*val1, *val2);
            }
        }
        size--;
    }
}


/**********************************************************************************
 * ANROP:   insertSort( pBegin, pEnd);
 * UPPGIFT: pBegin och pEnd definierar en array av element (pBegin pekar på det
 *          första elementet och pEnd EFTER det sista).
 *          Funktionen sorterar arrayen så att det minsta elementet hamnar först.
 *
 *          Algoritmen som används måste vara den version av insertSort som
 *          beskrivs i uppdragshäftet!!
 * ********************************************************************************/
void insertSort(float *pBegin, float *pEnd){

    float size = pEnd - pBegin;


    for(int i = 1; i <= size-1; i++ )
    {
        for(int j = i; j > 0; j--)
        {
            float *val1 = pBegin + j;
            float *val2 = pBegin + j - 1;

            if(*val2 < *val1)
                break;

            swap(*val1, *val2);

        }
    }
}



void dinaEgnaTester(){

    // testa själv bubble- och insert- sort här!
    float arr[] = {5, 8, 22, 15, 9, 18, 3, 6, 4};
    float arr2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    float arr3[] = {9, 1, 2, 3, 4, 5, 6,7,8 ,1};


    // sortera här
    bubbleSort(&arr[0], &arr[9]);
    insertSort(&arr3[0], &arr3[9]);

    // printa sorterade arrayen
    qDebug() << "printa min bubblade arr: " << endl;
    for(int i = 0; i < 9; ++i)
        cout << arr[i] << " ";
    cout << endl << endl;

    qDebug() << "printa min insertsorterade arr: " << endl;
    for(int i = 0; i < 9; ++i)
        cout << arr3[i] << " ";
    cout << endl;




}
