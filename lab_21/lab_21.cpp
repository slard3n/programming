#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

const int SIZE = 6;
using Matrix = long long[SIZE][SIZE];

bool readMatrix(ifstream& input, Matrix matrix)
{
    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            if (!(input >> matrix[row][col]))
                return false;

    return true;
}

void clearMatrix(Matrix matrix)
{
    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            matrix[row][col] = 0;
}

void multiply(const Matrix left, const Matrix right, Matrix result)
{
    clearMatrix(result);

    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            for (int index = 0; index < SIZE; index++)
                result[row][col] += left[row][index] * right[index][col];
}

void subtract(const Matrix left, const Matrix right, Matrix result)
{
    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            result[row][col] = left[row][col] - right[row][col];
}

void multiplyByNumber(const Matrix matrix, long long number, Matrix result)
{
    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            result[row][col] = matrix[row][col] * number;
}

void power(const Matrix matrix, int exponent, Matrix result)
{
    Matrix current{};
    Matrix temporary{};
    Matrix identity{};

    for (int i = 0; i < SIZE; i++)
        identity[i][i] = 1;

    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            current[row][col] = identity[row][col];

    for (int i = 0; i < exponent; i++)
    {
        multiply(current, matrix, temporary);
        for (int row = 0; row < SIZE; row++)
            for (int col = 0; col < SIZE; col++)
                current[row][col] = temporary[row][col];
    }

    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            result[row][col] = current[row][col];
}

void writeMatrix(ofstream& output, const Matrix matrix)
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
            output << setw(10) << matrix[row][col];
        output << endl;
    }
}

int main()
{
    Matrix A{}, B{}, AB{}, twoAB{}, B4{}, C{};
    ifstream inputA("a.txt");
    ifstream inputB("b.txt");
    ofstream output("c.txt");

    if (!inputA.is_open() || !inputB.is_open() || !output.is_open())
    {
        cout << "Не вдалося відкрити один із файлів." << endl;
        return 1;
    }

    if (!readMatrix(inputA, A) || !readMatrix(inputB, B))
    {
        cout << "Файли повинні містити матриці розміром 6x6." << endl;
        return 1;
    }

    multiply(A, B, AB);
    multiplyByNumber(AB, 2, twoAB);
    power(B, 4, B4);
    subtract(twoAB, B4, C);

    output << "Матриця C = 2AB - B^4" << endl;
    writeMatrix(output, C);

    cout << "Матрицю C = 2AB - B^4 записано у файл c.txt." << endl;
    return 0;
}
