#include <iostream>
#include <vector>
#include "FileReader.h"

class Day04
{
public:
    Day04(std::string filename)
    {
        FileReader file(filename);
        input_lines = file.getLines();
    }
    ~Day04() {}

    int countAccessibleRolls()
    {
        int count = 0;
        for (int i = 0; i < input_lines.size(); i++)
        {
            for (int j = 0; j < input_lines[i].length(); j++)
            {
                if (input_lines[i][j] == roll_char)
                    if (checkAdjacentPos(i, j) < 4)
                    {
                        rolls_pending_removal.push_back({i, j});
                        count++;
                    }
            }
        }
        return count;
    }

    void removeRolls()
    {
        for (int i = 0; i < rolls_pending_removal.size(); i++)
        {
            input_lines[rolls_pending_removal[i].first][rolls_pending_removal[i].second] = '.';
        }
        rolls_pending_removal.clear();
    }

private:
    int checkAdjacentPos(int y, int x)
    {
        int count = 0;
        int yboundary = input_lines.size();
        int xboundary = input_lines[0].size();

        for (int yoffset = -1; yoffset <= 1; yoffset++)
        {
            for (int xoffset = -1; xoffset <=1; xoffset++)
            {
                if (xoffset==0 && yoffset == 0)
                    continue;
                if (y+yoffset < 0 || y+yoffset >= yboundary)
                    continue;
                if (x+xoffset < 0 || x+xoffset >= xboundary)
                    continue;
                if (input_lines[y+yoffset][x+xoffset] == roll_char)
                    count++;
            }
        }
        return count;
    }

    std::vector<std::string> input_lines;
    std::vector<std::pair<int, int>> rolls_pending_removal;
    char roll_char = '@';
};

int main()
{
    Day04 day04("04_input.txt");

    int total_removable_rolls = day04.countAccessibleRolls();
    std::cout << "part 1: " << total_removable_rolls << std::endl;

    bool more_to_remove = true;
    while (more_to_remove)
    {
        day04.removeRolls();
        int removable_rolls = day04.countAccessibleRolls();
        if (removable_rolls == 0)
            more_to_remove = false;
        else
            total_removable_rolls += removable_rolls;
    }

    std::cout << "part 2: " << total_removable_rolls << std::endl;

    return 0;
}