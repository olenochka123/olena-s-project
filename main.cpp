//
//  main.cpp
//  Lab5
//
//  Created by Олена Фітьо on 11/4/19.
//  Copyright © 2019 Олена Фітьо. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#define n 5

using namespace std;

class Array
{
private:
    double dArr[n];
public:
    friend void InputArray(Array arr[]);
    friend void OutputArray(Array arr[]);
    friend void SortArray(Array arr[]);
    friend void CalcArray(Array arr[]);
};
void InputArray(Array  arr[])
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cout << "[" << i + 1 << "][" << j + 1  << "] = ";
            cin >> arr[i].dArr[j];
        }
}
void OutputArray(Array  arr[])
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << arr[j].dArr[i] << "\t";
        }
        cout << endl;
    }
}


void SortArray(Array  arr[])
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
                    if (arr[LeftBorder + LeftBlockIterator].dArr[i] > arr[MidBorder + RightBlockIterator].dArr[i])
                    {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator].dArr[i];
                        LeftBlockIterator++;
                    }
                    else
                    {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator].dArr[i];
                        RightBlockIterator++;
                    }
                }
                while (LeftBorder + LeftBlockIterator < MidBorder)
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator].dArr[i];
                    LeftBlockIterator++;
                }
                while (MidBorder + RightBlockIterator < RightBorder)
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator].dArr[i];
                    RightBlockIterator++;
                }
                
                for (int MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
                {
                    arr[LeftBorder + MergeIterator].dArr[i] = SortedBlock[MergeIterator];
                }
                delete[] SortedBlock;
                
            }
            
        }
    }
}


void CalcArray(Array arr[])
{
    int max = arr[4].dArr[0];

    for (int i = 0; i < 4; i++) {
        cout << arr[4].dArr[i] << endl;
        if(max<arr[4].dArr[i]){
            max = arr[4].dArr[i];
        }
    }
    cout <<"max: "<< max << endl;
    }


int main()
{
    cout << "Enter elements of matrix:\n" << endl;
    Array  arr[n];
    InputArray(arr);
    cout << "\nYour matrix:\n" << endl;
    OutputArray(arr);
    SortArray(arr);
    cout << "\nSorted matrix:\n" << endl;
    OutputArray(arr);
    cout << "\nCalculations:\n" << endl;
    CalcArray(arr);
}

