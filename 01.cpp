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
        std::cout << makeRotations(rotations);
    }

private:
    int mod(int k, int n)
    {
        return ((k%n)+n)%n;
    }

    std::vector<int> getRotationsFromInput(std::string filename)
    {
        FileReader file(filename);
        std::vector<std::string> input_lines = file.getLines();
        std::vector<int> rotations;

        for (int i = 0; i < input_lines.size(); i++)
        {
            if (input_lines[i].substr(0, 1) == "R")
            {
                rotations.push_back(stoi(input_lines[i].substr(1)));
            }
            else
            {
                rotations.push_back(-stoi(input_lines[i].substr(1)));
            }
        }

        return rotations;
    }

    int makeRotations(std::vector<int> rotations)
    {
        int dial_pos = 50;
        int zero_counter = 0;
        for (int i = 0; i < rotations.size(); i++)
        {
            //c++'s modulus operator is really a remainder operator and cannot cap negative values to within the desired range
            // so left rotations which might produce negative results are converted to right rotations 
            if (rotations[i] < 0)
                dial_pos += (100+rotations[i]);
            else
                dial_pos += rotations[i];

            dial_pos %= 100;
            if (dial_pos == 0)
                zero_counter++;
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