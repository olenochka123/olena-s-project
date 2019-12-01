//
//  main.cpp
//  NewLab5
//
//  Created by Олена Фітьо on 12/1/19.
//  Copyright © 2019 Олена Фітьо. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#define n 5

using namespace std;

class Array
{
private:
    double dArray[n];
public:
    friend void InputArray(Array array[]);
    friend void OutputArray(Array array[]);
    friend void SortArray(Array array[]);
    friend void CalcArray(Array array[]);
};
void InputArray(Array  array[])
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cout << "[" << i + 1 << "][" << j + 1  << "] = ";
            cin >> array[i].dArray[j];
        }
}
void OutputArray(Array  array[])
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << array[j].dArray[i] << "\t";
        }
        cout << endl;
    }
}


void SortArray(Array  array[])
{
    for (int i = 0; i < n; ++i)
    {
        for (int BlockSizeIterator = 1; BlockSizeIterator < n; BlockSizeIterator *= 2)
        {
            for (int BlockIterator = 0; BlockIterator < n - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
            {
                int LeftBlockIterator = 0;
                int RightBlockIterator = 0;
                int LeftBorder = BlockIterator;
                int MidBorder = BlockIterator + BlockSizeIterator;
                int RightBorder = BlockIterator + 2 * BlockSizeIterator;
                RightBorder = (RightBorder < n) ? RightBorder : n;
                int* SortedBlock = new int[RightBorder - LeftBorder];
                
                while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
                {
                    if (array[LeftBorder + LeftBlockIterator].dArray[i] > array[MidBorder + RightBlockIterator].dArray[i])
                    {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = array[LeftBorder + LeftBlockIterator].dArray[i];
                        LeftBlockIterator++;
                    }
                    else
                    {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = array[MidBorder + RightBlockIterator].dArray[i];
                        RightBlockIterator++;
                    }
                }
                while (LeftBorder + LeftBlockIterator < MidBorder)
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = array[LeftBorder + LeftBlockIterator].dArray[i];
                    LeftBlockIterator++;
                }
                while (MidBorder + RightBlockIterator < RightBorder)
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = array[MidBorder + RightBlockIterator].dArray[i];
                    RightBlockIterator++;
                }
                
                for (int MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
                {
                    array[LeftBorder + MergeIterator].dArray[i] = SortedBlock[MergeIterator];
                }
                delete[] SortedBlock;
                
            }
            
        }
    }
}


void CalcArray(Array array[])
{
    int max = array[4].dArray[0];

    for (int i = 0; i < 4; i++) {
        cout << array[4].dArray[i] << endl;
        if(max<array[4].dArray[i]){
            max = array[4].dArray[i];
        }
    }
    cout <<"max: "<< max << endl;
    }


int main()
{
    cout << "Enter elements of matrix:\n" << endl;
    Array  array[n];
    InputArray(array);
    cout << "\nYour matrix:\n" << endl;
    OutputArray(array);
    SortArray(array);
    cout << "\nSorted matrix:\n" << endl;
    OutputArray(array);
    cout << "\nCalculations:\n" << endl;
    CalcArray(array);
}


