#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int mostFreq(const vector<string> &binary, int index)
{
    int oneFreq = 0;
    for (int i = 0; i < binary.size(); i++)
    {
        if (binary[i][index] == '1')
        {
            oneFreq++;
        }
    }
    return oneFreq >= binary.size() - oneFreq;
}

int binaryToInt(string &binary)
{
    int ret = 0;
    for (int i = 0; i < binary.size(); i++)
    {
        ret += binary[i] - '0' == 1 ? pow(2, binary.size() - i - 1) : 0;
    }
    return ret;
}

int main(int argc, const char *argv[])
{
    string fileName = argv[1];
    ifstream myfile(fileName);

    string line;
    vector<string> input;
    while (myfile >> line)
    {
        input.push_back(line);
    }

    vector<int> freq(input[0].size(), 0);
    for (string binary : input)
    {
        for (int i = 0; i < binary.size(); i++)
        {
            if (binary[i] == '1')
            {
                freq[i]++;
            }
        }
    }

    int gamma = 0;
    int epsilon = 0;
    for (int i = 0; i < freq.size(); i++)
    {
        if (freq[i] > input.size() / 2)
        {
            gamma += pow(2, freq.size() - i - 1);
        }
        else
        {
            epsilon += pow(2, freq.size() - i - 1);
        }
    }

    cout << "Puzzle 1: " << gamma * epsilon << endl;

    vector<string> copy(input);
    for (int i = 0; i < input[0].size(); i++)
    {
        int oxy = mostFreq(input, i);
        int co2 = mostFreq(copy, i);

        //remove oppsite
        if (oxy == 1)
        {
            oxy = 0;
        }
        else
        {
            oxy = 1;
        }

        input.erase(remove_if(input.begin(), input.end(), [i, oxy](string &a)
                              { return a[i] == '0' + oxy; }),
                    input.end());

        if (copy.size() != 1)
        {
            copy.erase(remove_if(copy.begin(), copy.end(), [i, co2](string &a)
                                 { return a[i] == '0' + co2; }),
                       copy.end());
        }
    }

    cout << "Puzzle 2: " << binaryToInt(input[0]) * binaryToInt(copy[0]) << endl;
    return EXIT_SUCCESS;
}