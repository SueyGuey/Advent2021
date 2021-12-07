#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    string fileName = argv[1];
    ifstream myfile(fileName);

    string direction;
    string amount;

    int downAmount = 0;
    int downAmountAim = 0;
    int forwardAmount = 0;
    int aim = 0;
    while (myfile >> direction >> amount)
    {
        int intAmount = stoi(amount);
        if (direction == "down")
        {
            downAmount += intAmount;
            aim += intAmount;
        }
        else if (direction == "up")
        {
            downAmount -= intAmount;
            aim -= intAmount;
        }
        else
        {
            forwardAmount += intAmount;
            downAmountAim += intAmount * aim;
        }
    }

    cout << "Puzzle 1: " << forwardAmount * downAmount << endl;
    cout << "Puzzle 2: " << forwardAmount * downAmountAim << endl;

    return EXIT_SUCCESS;
}