/*
 * INSTRUCTIONS:
 *     This is the starting C++ code for hw6_1.
 *     Note that the current filename is "main.cpp". 
 *     When you finish your development, copy the file.
 *     Then, rename the copied file to "main_hw6_1.cpp".
 *     After that, upload the renamed file to Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Quick Sort and Insertion Sort
 * Abstract: Asks for input of list size. Then asks for whether the user wants ascending order, descending order, or random order ints in range of 0 to list size.
 * Then it asks if the user wants to run insertion sort, then if they want to run median of three quick sort. The program then outputs numbers generated,
 * quick sort result and insertion and median results if the user said yes to them if input was 20 or less. Then the program outputs the amount of time it took
 * to run each sorting algorithm in milliseconds then ranks them in terms of speed.
 * ID: 9908
 * Name: Jackie Luc
 * Date: 03/25/2025
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ratio>

int partition(std::vector<int>& v, int left, int right)
{
    int pivot = v[left], i = left, j = right+1;
    do
    {
        do
        {
            ++i;

        }while(v[i] < pivot);
        do
        {
            --j;

        }while(v[j] > pivot);

        std::swap(v[i], v[j]);

    }while(i < j);

    std::swap(v[i], v[j]);
    std::swap(v[left], v[j]);
    // std::cout << "j: " << j << "\n" ;
    return j;
}

int medianOfThreePartition(std::vector<int>& v, int left, int right)
{
    int pivot, i = left, j = right, pivotIndex = ((right-left)/2)+left;
    pivot = v[pivotIndex];
    //get the index of the min and max
    int minIndex, maxIndex;
    if(v[left] < v[right])
    {
        minIndex = left;
        maxIndex = right;
    }
    else
    {
        minIndex = right;
        maxIndex = left;
    }
    if(v[pivotIndex] < v[minIndex])
    {
        minIndex = pivotIndex;
    }
    if(v[pivotIndex] > v[maxIndex])
    {
        maxIndex = pivotIndex;
    }
    // int min = std::min(pivot, std::min(v[i], v[j])), max = std::max(pivot, std::max(v[i], v[j]));
    std::swap(v[minIndex], v[i]); std::swap(v[maxIndex], v[j]);
    std::swap(v[i+1], v[pivotIndex]);// swap middle value with index after left
    ++i;
    int p = partition(v, i, right);
    return p;
}

void medianOfThreeQuickSort(std::vector<int>& v, int left, int right)
{
    if(left < right)
    {
        int s = medianOfThreePartition(v, left, right);
        medianOfThreeQuickSort(v, left, s-1);
        medianOfThreeQuickSort(v, s+1, right);
    }
}

void quickSort(std::vector<int>& v, int left, int right)
{
    if(left < right)
    {
        int s = partition(v, left, right);
        quickSort(v, left, s-1);
        quickSort(v, s+1, right);
    }
}

void insertionSort(std::vector<int> &v)
{
    for(int i=1; i<v.size(); ++i)
    {
        int x = v[i], j = i-1;
        while(j>=0 && v[j]>x)
        {
            v[j+1] = v[j];
            --j;
        }
        v[j+1] = x;
    }
}

int main() 
{
    srand(time(0));
    std::vector<int> v;
    int size, option;
    char iSort, mot;
    std::cout << "Enter input size: ";
    std::cin >> size;
    std::cout << "========== Select Option for Input Numbers ==========\n   1. Ascending Order\n   2. Descending Order\n   3. Random Order\nChoose option: ";
    std::cin >> option;
    std::cout << "\n" << "Run insertion sort(y/n)? ";
    std::cin >> iSort;
    std::cout << "Run quick sort with Median of Three(y/n)? ";
    std::cin >> mot;
    // std::cout << "\n";

    for(int i=0; i<size; ++i)
    {
        int temp = rand() % ((size*10)+1);
        v.push_back(temp);
    }
    v.push_back(INT32_MAX);
    std::vector<int> quick = v, median = v, insert = v;

    if(option == 1 || option == 2)
    {
        quickSort(v, 0, v.size()-2);
        v.pop_back();
        if(option == 2)
        {
            std::reverse(v.begin(), v.end());
        }
    }
    std::chrono::time_point qStart = std::chrono::high_resolution_clock::now();
    quickSort(quick, 0, quick.size()-2);
    std::chrono::time_point qEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> qDuration = qEnd-qStart;

    std::chrono::time_point iStart = std::chrono::high_resolution_clock::now(), iEnd = std::chrono::high_resolution_clock::now(),
    mStart = std::chrono::high_resolution_clock::now(), mEnd = std::chrono::high_resolution_clock::now();

    if(size <= 20)
    {
        std::cout << "\nNumbers generated: ";
        for(int i=0; i<v.size()-1; ++i)
        {
            std::cout << v[i] << " ";
        }
        std::cout << "\nQuick sort result: ";
        for(int i=0; i<quick.size()-1; ++i)
        {
            std::cout << quick[i] << " ";
        }
        if(std::tolower(iSort) == 'y')
        {
            iStart = std::chrono::high_resolution_clock::now();
            insertionSort(insert);
            iEnd = std::chrono::high_resolution_clock::now();
            std::cout << "\nInsertion sort result: ";
            for(int i=0; i<insert.size()-1; ++i)
            {
                std::cout << insert[i] << " ";
            }
        }
        if(std::tolower(mot) == 'y')
        {
            mStart = std::chrono::high_resolution_clock::now();
            medianOfThreeQuickSort(median, 0, median.size()-2);
            mEnd = std::chrono::high_resolution_clock::now();
            std::cout << "\nQuick Sort (Median of Three): ";
            for(int i=0; i<median.size()-1; ++i)
            {
                std::cout << insert[i] << " ";
            }
        }
        std::cout << "\n";
    }
    std::chrono::duration<double, std::milli> iDuration = iEnd-iStart, mDuration = mEnd - mStart;
    std::cout << "\n==================== Execution Result ====================\n";

    std::vector<double> ranks = {qDuration.count()};

    std::cout << "Quick Sort: " << qDuration.count() << " milliseconds\n";
    if(std::tolower(iSort) == 'y')
    {
        if(size > 20)
        {
            iStart = std::chrono::high_resolution_clock::now();
            insertionSort(insert);
            iEnd = std::chrono::high_resolution_clock::now();
            iDuration = iEnd-iStart;
        }
        std::cout << "Insertion Sort: " << iDuration.count() << " milliseconds\n";
        ranks.push_back(iDuration.count());
    }
    if(std::tolower(mot) == 'y')
    {
        if(size > 20)
        {
            mStart = std::chrono::high_resolution_clock::now();
            medianOfThreeQuickSort(median, 0, median.size()-2);
            mEnd = std::chrono::high_resolution_clock::now();
            mDuration = mEnd - mStart;
        }
        std::cout << "Quick Sort (Median of Three): " << mDuration.count() << " milliseconds\n";
        ranks.push_back(mDuration.count());
    }
    std::cout << "============================================================\n";
    std::cout << "\n========================== Ranking =========================\n";
    std::sort(ranks.begin(), ranks.end());
    for(int i=0; i<ranks.size(); ++i)
    {
        std::cout << "(" << i+1 << ") ";
        if(ranks[i] == qDuration.count())
            std::cout << "Quick Sort\n";
        else if(ranks[i] == iDuration.count())
            std::cout << "Insertion Sort\n";
        else if(ranks[i] == mDuration.count())
            std::cout << "Quick Sort (Median of Three)\n";
    }
    std::cout << "============================================================\n";
    return 0;
}

