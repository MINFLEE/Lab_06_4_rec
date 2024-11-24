// Lab_06_4_rec

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void InitArray(double* a, int size, int index = 0);
void PrintArray(double* a, int size, int index = 0);
double ProductOfPositiveElements(double* a, int size, int index = 0, double product = 1, bool hasPositive = false);
double SumBeforeMinElement(double* a, int size, int index = 0, double minElement = INT_MAX, int minIndex = -1, double sum = 0);
void SortEvenOddIndexes(double* a, int size, int startIndex);

int main()
{
    srand((unsigned)time(NULL));
    int n;
    cout << "n = ";
    cin >> n;
    cout << endl;

    double* a = new double[n];

    InitArray(a, n);
    cout << "Array:";
    PrintArray(a, n);
    cout << endl;

    // 1.1
    double product = ProductOfPositiveElements(a, n);
    cout << "Product of positive elements: " << product << endl;
    cout << endl;

    // 1.2
    double sum = SumBeforeMinElement(a, n);
    cout << "Sum of elements before the minimum: " << sum << endl;
    cout << endl;

    // 2
    SortEvenOddIndexes(a, n, 0);
    SortEvenOddIndexes(a, n, 1);
    cout << "Array after sorting even and odd elements: ";
    PrintArray(a, n);

    return 0;
}

void InitArray(double* a, int size, int index)
{
    if (index == size)
        return;
    a[index] = rand() % 21 - 10;
    InitArray(a, size, index + 1);
}

void PrintArray(double* a, int size, int index)
{
    if (index == size)
    {
        cout << endl;
        return;
    }
    cout << setw(4) << a[index] << " ";
    PrintArray(a, size, index + 1);
}

double ProductOfPositiveElements(double* a, int size, int index, double product, bool hasPositive)
{
    if (index == size)
        return hasPositive ? product : 0;

    if (a[index] > 0)
        return ProductOfPositiveElements(a, size, index + 1, product * a[index], true);

    return ProductOfPositiveElements(a, size, index + 1, product, hasPositive);
}

double SumBeforeMinElement(double* a, int size, int index, double minElement, int minIndex, double sum)
{
    if (index == minIndex)
        return sum;

    if (index < size)
    {
        sum += a[index];
        return SumBeforeMinElement(a, size, index + 1, minElement, minIndex, sum);
    }

    return sum;
}

void SortEvenOddIndexes(double* a, int size, int startIndex)
{
    if (startIndex >= size)
        return;

    int minIndex = startIndex;

    if (startIndex + 2 < size)
    {
        int nextMinIndex = startIndex + 2;

        if (a[nextMinIndex] < a[minIndex])
        {
            minIndex = nextMinIndex;
        }

        SortEvenOddIndexes(a, size, startIndex + 2);
    }

    if (minIndex != startIndex)
    {
        double temp = a[startIndex];
        a[startIndex] = a[minIndex];
        a[minIndex] = temp;
    }

    SortEvenOddIndexes(a, size, startIndex + 2);
}