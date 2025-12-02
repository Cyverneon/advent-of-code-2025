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
        
        for (int i = 0; i < rotations.size(); i++)
        {
            std::cout << rotations[i] << std::endl;
        }
    }

private:
    std::vector<int> getRotationsFromInput(std::string filename)
    {
        FileReader file(filename);
        std::vector<std::string> input_lines = file.getLines();
        std::vector<int> rotations;

        for (int i = 0; i < input_lines.size(); i++)
        {
            if (input_lines[i].substr(0, 1) == "L")
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
};

int main()
{
    Day01 day01;
    day01.calculatePassword("test_input.txt");

    return 0;
}