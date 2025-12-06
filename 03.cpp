#include <iostream>
#include <vector>
#include "FileReader.h"

class Day03
{
public:
    Day03() {}
    ~Day03() {}

    long long calculateMaxOutputVoltage(std::string input_filename, int batteries)
    {
        FileReader file(input_filename);
        std::vector<std::string> battery_banks = file.getLines();
        long long total = 0;
        for (int i = 0; i < battery_banks.size(); i++)
        {
            int highest_pos = 0;
            std::string joltage = "";
            for (int j = 0; j < batteries; j++)
            {
                highest_pos = highest_pos + getPosOfHighestDigit(battery_banks[i].substr(highest_pos, battery_banks[i].size() - batteries - highest_pos + j + 1));
                joltage.append(battery_banks[i].substr(highest_pos, 1));
                highest_pos++;
            }
            total += stoll(joltage);
        }
        return total;
    }

private:
    int getPosOfHighestDigit(std::string str)
    {
        int highest_pos = 0;
        int highest = str[0];
        for (int i = 1; i < str.length(); i++)
        {
            if (str[i] > highest)
            {
                highest = str[i];
                highest_pos = i;
            }
        }
        return highest_pos;
    }
};

int main()
{
    Day03 day03;
    std::cout << "part 1: " << day03.calculateMaxOutputVoltage("03_input.txt", 2) << std::endl;
    std::cout << "part 2: " << day03.calculateMaxOutputVoltage("03_input.txt", 12) << std::endl;
    return 0;
}