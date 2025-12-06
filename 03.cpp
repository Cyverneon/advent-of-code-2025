#include <iostream>
#include <vector>
#include "FileReader.h"

class Day03
{
public:
    Day03() {}
    ~Day03() {}

    int calculateMaxOutputVoltage(std::string input_filename, int batteries)
    {
        FileReader file(input_filename);
        std::vector<std::string> battery_banks = file.getLines();
        int total = 0;
        for (int i = 0; i < battery_banks.size(); i++)
        {
            int highest_pos = getPosOfHighestDigit(battery_banks[i].substr(0, battery_banks[i].size()-1));
            std::string joltage = battery_banks[i].substr(highest_pos, 1);
            int next_highest_pos = getPosOfHighestDigit(battery_banks[i].substr(highest_pos+1));
            joltage.append(battery_banks[i].substr(highest_pos + next_highest_pos + 1, 1));
            total += stoi(joltage);
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
    std::cout << day03.calculateMaxOutputVoltage("03_input.txt");

    return 0;
}