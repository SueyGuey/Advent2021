#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <math.h>

using namespace std;

int main(int argc, const char *argv[])
{
    string fileName = argv[1];
    ifstream myfile(fileName);

    string start, end, arrow;
    unordered_map<string, int> freq;
    unordered_map<string, int> diagFreq;
    while (myfile >> start >> arrow >> end)
    {
        int x1, y1, x2, y2;
        stringstream ss(start);
        string substr;
        getline(ss, substr, ',');
        x1 = stoi(substr);
        getline(ss, substr, ',');
        y1 = stoi(substr);

        stringstream ss2(end);
        getline(ss2, substr, ',');
        x2 = stoi(substr);
        getline(ss2, substr, ',');
        y2 = stoi(substr);

        if (x1 == x2)
        {
            for (int i = min(y1, y2); i <= max(y1, y2); i++)
            {
                string stringified = to_string(x1) + " | ";
                stringified += to_string(i);
                freq[stringified]++;
                diagFreq[stringified]++;
            }
        }
        else if (y1 == y2)
        {
            for (int i = min(x1, x2); i <= max(x1, x2); i++)
            {
                string stringified = to_string(i) + " | ";
                stringified += to_string(y1);
                freq[stringified]++;
                diagFreq[stringified]++;
            }
        }
        else
        {
            int range = abs(x1 - x2);
            for (int i = 0; i <= range; i++)
            {
                diagFreq[to_string(x1) + " | " + to_string(y1)]++;
                if (x1 > x2 && y1 > y2)
                {
                    x1--;
                    y1--;
                }
                else if (x1 < x2 && y1 < y2)
                {
                    x1++;
                    y1++;
                }
                else if (x1 > x2 && y1 < y2)
                {
                    x1--;
                    y1++;
                }
                else
                {
                    x1++;
                    y1--;
                }
            }
        }
    }

    int overlaps = 0;
    for (auto coords : freq)
    {
        if (coords.second > 1)
        {
            overlaps++;
        }
    }

    cout << "Puzzle 1: " << overlaps << endl;

    overlaps = 0;
    for (auto coords : diagFreq)
    {
        if (coords.second > 1)
        {
            overlaps++;
        }
    }

    cout << "Puzzle 2: " << overlaps << endl;

    return EXIT_SUCCESS;
}