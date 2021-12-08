#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Board
{
public:
    Board() : grid(5, vector<int>(5, 0)), rows(5, 0), columns(5, 0), marked(5, vector<bool>(5, false)) {}
    bool CrossOff(int num)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (grid[i][j] == num)
                {
                    marked[i][j] = true;
                    rows[i]++;
                    columns[j]++;
                    if (rows[i] == 5 || columns[j] == 5)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    void addNum(string strNum)
    {
        int num = stoi(strNum);
        grid[i][j] = num;

        if (j == 4)
        {
            i++;
            j = 0;
        }
        else
        {
            j++;
        }
    };
    int unmarkedSum()
    {
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (!marked[i][j])
                {
                    sum += grid[i][j];
                }
            }
        }
        return sum;
    }

private:
    int i = 0;
    int j = 0;

    //maintaining count
    vector<int> rows;
    vector<int> columns;
    vector<vector<int> > grid;
    vector<vector<bool> > marked;
};

int main(int argc, const char *argv[])
{
    string fileName = argv[1];
    ifstream myfile(fileName);

    string line;

    vector<int> numbers;
    myfile >> line;
    stringstream ss(line);

    //split by comma
    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        numbers.push_back(stoi(substr));
    }

    vector<Board> boards;
    Board board = Board();
    int count = 0;
    while (myfile >> line)
    {
        count++;
        board.addNum(line);
        if (count == 25)
        {
            boards.push_back(board);
            board = Board();
            count = 0;
        }
    }

    vector<Board> copyBoard(boards);

    bool stop = false;
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = 0; j < boards.size(); j++)
        {
            if (boards[j].CrossOff(numbers[i]))
            {
                cout << "Puzzle 1: " << numbers[i] * boards[j].unmarkedSum() << endl;
                stop = true;
                break;
            }
        }
        if (stop)
        {
            break;
        }
    }

    stop = false;
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = 0; j < copyBoard.size(); j++)
        {
            if (copyBoard[j].CrossOff(numbers[i]))
            {
                if (copyBoard.size() == 1)
                {
                    cout << "Puzzle 2: " << numbers[i] * copyBoard[j].unmarkedSum() << endl;
                    stop = true;
                    break;
                }
                copyBoard.erase(copyBoard.begin() + j);
                j--;
            }
        }
        if (stop)
        {
            break;
        }
    }

    return EXIT_SUCCESS;
}