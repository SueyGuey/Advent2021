#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

int main(int argc, const char *argv[])
{
    string fileName = argv[1];
    ifstream myfile(fileName);
    string line;
    myfile >> line;
    stringstream ss(line);

    vector<int> input;
    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        input.push_back(stoi(substr));
    }

    sort(input.begin(), input.end());

    int med;
    if (input.size() % 2 == 0)
    {
        med = (input[input.size() / 2] + input[input.size() / 2 + 1]) / 2;
        cout << med << endl;
    }
    else
    {
        med = input[input.size() / 2];
    }

    /*
    double avg = 0;
    for (int i = 0; i < input.size(); i++)
    {
        avg += input[i];
    }
    avg = avg / input.size();
    avg = round(avg);*/
    cout << med;

    int fuel = 0;
    for (int i = 0; i < input.size(); i++)
    {
        fuel += abs(input[i] - med);
    }

    cout << "Puzzle 1: " << fuel << endl;

    return EXIT_SUCCESS;
}