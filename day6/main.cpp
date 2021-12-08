#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, const char *argv[])
{
    string fileName = argv[1];
    ifstream myfile(fileName);
    string line;
    myfile >> line;
    stringstream ss(line);

    vector<unsigned long long> input(9, 0);
    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        input[stoul(substr)]++;
    }

    for (int i = 0; i < 80; i++)
    {
        unsigned long long dayZero = input[0];
        for (int j = 1; j < 9; j++)
        {
            input[j - 1] = input[j];
            input[j] = 0;
        }
        input[6] += dayZero;
        input[8] += dayZero;
    }

    int total = 0;
    for (int i = 0; i < input.size(); i++)
    {
        total += input[i];
    }

    cout << "Puzzle 1: " << total << endl;

    for (int i = 80; i < 256; i++)
    {
        unsigned long long dayZero = input[0];
        for (int j = 1; j < 9; j++)
        {
            input[j - 1] = input[j];
            input[j] = 0;
        }
        input[6] += dayZero;
        input[8] += dayZero;
    }

    unsigned long long sum = 0;
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << endl;
        sum += input[i];
    }

    cout << "Puzzle 2: " << sum << endl;

    return EXIT_SUCCESS;
}