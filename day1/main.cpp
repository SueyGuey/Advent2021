#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    string fileName = argv[1];
    ifstream myfile(fileName);

    string line;
    vector<int> nums;
    while (myfile >> line)
    {
        nums.push_back(stoi(line));
    }

    int increasesP1 = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        increasesP1 += nums[i] > nums[i - 1];
    }
    cout << "Puzzle 1: " << increasesP1 << endl;

    int increasesP2 = 0;

    int sum = nums[0] + nums[1] + nums[2];
    for (int i = 3; i < nums.size(); i++)
    {
        int prevSum = sum;
        sum += nums[i] - nums[i - 3];
        increasesP2 += sum > prevSum;
    }
    cout << "Puzzle 2: " << increasesP2 << endl;

    return EXIT_SUCCESS;
}