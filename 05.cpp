#include <iostream>
#include <vector>
#include "FileReader.h"

class Day05
{
public:
    Day05(std::string filename)
    {
        parseInput(filename);
    }
    ~Day05() {}

    int countFreshIds()
    {
        int count = 0;

        for (int i = 0; i < ids.size(); i++)
        {
            for (int j = 0; j < ranges.size(); j++)
            {
                if (ids[i] >= ranges[j].first && ids[i] <= ranges[j].second)
                {
                    count++;
                    break;
                }
            }
        }

        return count;
    }

private:
    void parseInput(std::string filename)
    {
        FileReader file_reader(filename);
        std::vector<std::string> lines = file_reader.getLines();

        bool first_section = true;
        for (int i = 0; i < lines.size(); i++)
        {
            // indicator to move to second section of input
            if (lines[i] == "")
            {
                first_section = false;
                continue;
            }

            if (first_section)
            {
                int range_separator = lines[i].find('-');
                ranges.push_back({
                    stoll(lines[i].substr(0, range_separator)),
                    stoll(lines[i].substr(range_separator+1))
                    });
            }
            else
            {
                ids.push_back(stoll(lines[i]));
            }
        }
    }

    std::vector<std::pair<long long, long long>> ranges;
    std::vector<long long> ids;
};

int main()
{
    Day05 day05("05_input.txt");
    std::cout << day05.countFreshIds() << std::endl;
    return 0;
}