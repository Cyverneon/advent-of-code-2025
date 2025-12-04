#include <iostream>
#include <vector>
#include "FileReader.h"

class Day01
{
public:
    Day01() {}
    ~Day01() {}

    void calculatePassword(std::string input_filename)
    {
        std::vector<int> rotations = getRotationsFromInput(input_filename);
        std::cout << "part one: " << countZeros(rotations, false) << std::endl;
        std::cout << "part two: " << countZeros(rotations, true) << std::endl;
    }

private:
    std::vector<int> getRotationsFromInput(std::string filename)
    {
        FileReader file(filename);
        std::vector<std::string> input_lines = file.getLines();
        std::vector<int> rotations;

        for (int i = 0; i < input_lines.size(); i++)
        {
            if (input_lines[i].substr(0, 1) == "R")
                rotations.push_back(stoi(input_lines[i].substr(1)));
            else
                rotations.push_back(-stoi(input_lines[i].substr(1)));
        }

        return rotations;
    }

    int countZeros(std::vector<int> rotations, bool includeOverlaps)
    {
        int dial_pos = 50;
        int zero_counter = 0;
        for (int i = 0; i < rotations.size(); i++)
        {
            int val;
            if (rotations[i] < 0)
            {
                if (dial_pos == 0)
                    dial_pos = 100;
                val = (100-dial_pos) - rotations[i];
                dial_pos = 100 - (val % 100);
                if (dial_pos == 100)
                    dial_pos = 0;
            }
            else
            {
                val = dial_pos + rotations[i];
                dial_pos = val % 100;
            }
            if (includeOverlaps)
                zero_counter += val / 100;
            else
                zero_counter += (dial_pos == 0);
        }
        return zero_counter;
    }
};

int main()
{
    Day01 day01;
    day01.calculatePassword("01_input.txt");
    return 0;
}