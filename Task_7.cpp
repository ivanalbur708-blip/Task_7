#include <iostream>


using namespace std;

void SumAndProduct(const int* array, int size, int* sum, long long* product)
{
    *sum = 0;
    *product = 1;
    for (int i = 0; i < size; i++)
    {
        *sum += *(array + i);
        *product *= *(array + i);
    }
}

void CountSigns(const int* array, int size, int* negative, int* positive, int* zero)
{
    *negative = 0;
    *positive = 0;
    *zero = 0;

    for (int i = 0; i < size; i++)
    {
        if (*(array + i) < 0) (*negative)++;
        else if (*(array + i) > 0) (*positive)++;
        else (*zero)++;
    }
}

int* FindSubset(int* arrayA, int sizeA, int* arrayB, int sizeB)
{
    for (int begin = 0; begin <= sizeA - sizeB; begin++)
    {
        bool equal = true;
        for (int i = 0; i < sizeB; i++)
        {
            if (*(arrayA + begin + i) != *(arrayB + i)) equal = false;
        }
        if (equal) return arrayA + begin;
    }
    return 0;
}

int* RemoveNegative(const int* array, int size, int* newSize)
{
    *newSize = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) >= 0) (*newSize)++;
    }

    int* result = new int[*newSize];
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) >= 0) result[index++] = *(array + i);
    }
    return result;
}

int* AppendBlock(const int* array, int size, const int* block, int blockSize)
{
    int* result = new int[size + blockSize];
    for (int i = 0; i < size; i++) result[i] = array[i];
    for (int i = 0; i < blockSize; i++) result[size + i] = block[i];
    return result;
}

int* InsertBlock(const int* array, int size, const int* block, int blockSize, int index)
{
    int* result = new int[size + blockSize];
    for (int i = 0; i < index; i++) result[i] = array[i];
    for (int i = 0; i < blockSize; i++) result[index + i] = block[i];
    for (int i = index; i < size; i++) result[i + blockSize] = array[i];
    return result;
}

int* DeleteBlock(const int* array, int size, int index, int blockSize)
{
    int* result = new int[size - blockSize];
    for (int i = 0; i < index; i++) result[i] = array[i];
    for (int i = index + blockSize; i < size; i++) result[i - blockSize] = array[i];
    return result;
}

void PrintArray(const int* array, int size)
{
    for (int i = 0; i < size; i++) cout << array[i] << ' ';
    cout << '\n';
}

int main()
{


    int array[7] = { 4, -2, 0, 7, -5, 9, 1 };
    const int size = 7;
    // Task 1
    int sum;
    long long product;
    SumAndProduct(array, size, &sum, &product);
    cout << "Sum: " << sum << "\nProduct: " << product << '\n';
    // Task 2
    int negative;
    int positive;
    int zero;
    CountSigns(array, size, &negative, &positive, &zero);
    cout << "Negative: " << negative << "\nPositive: " << positive
        << "\nZero: " << zero << '\n';
    // Task 3
    int subset[3] = { 0, 7, -5 };
    int* found = FindSubset(array, size, subset, 3);

    if (found != 0) cout << "Subset begins at index " << found - array << '\n';
    else cout << "Subset not found.\n";
    // Task 4
    int nonNegativeSize;
    int* nonNegative = RemoveNegative(array, size, &nonNegativeSize);

    PrintArray(nonNegative, nonNegativeSize);
    // Task 5
    int block[2] = { 100, 200 };
    int* appended = AppendBlock(array, size, block, 2);

    PrintArray(appended, size + 2);
    // Task 6
    int* inserted = InsertBlock(array, size, block, 2, 3);

    PrintArray(inserted, size + 2);
    // Task 7
    int* shortened = DeleteBlock(array, size, 2, 3);

    PrintArray(shortened, size - 3);

    delete[] nonNegative;
    delete[] appended;
    delete[] inserted;
    delete[] shortened;

    return 0;
}

