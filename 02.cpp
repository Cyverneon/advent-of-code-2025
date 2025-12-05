#include <iostream>
#include <vector>
#include "FileReader.h"

class Day02
{
public:
    Day02() {}
    ~Day02() {}

    void sumInvalidIDs(std::string input_filename, bool part2)
    {
        std::vector<long long> ids = readIdsFromInput(input_filename);
        long long sum = 0;
        for (int id_index = 0; id_index < ids.size(); id_index+=2)
        {
            for (long long i = ids[id_index]; i <= ids[id_index+1]; i++)
            {
                std::string id_string = std::to_string(i);
                if (part2)
                {
                    for (int j = 2; j <= id_string.length(); j++)
                    {
                        if (id_string.length()%j == 0)
                        {
                            int substring_length = id_string.length()/j;
                            std::string comp = id_string.substr(0, substring_length);
                            bool repeating = true;
                            for (int k = 1; k < j; k++)
                            {
                                if (id_string.substr(substring_length*k, substring_length) != comp)
                                    repeating = false;
                            }
                            if (repeating)
                            {
                                sum += i;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    if (id_string.substr(0, id_string.length()/2) == id_string.substr(id_string.length()/2, std::string::npos))
                        sum += i;
                }
            }
        }
        std::cout << sum << std::endl;
    }

private:
    std::vector<long long> readIdsFromInput(std::string input_filename)
    {
        FileReader file(input_filename);
        std::string input = file.getLines()[0];

        std::vector<long long> ids;

        int current_pos = 0;
        int split_pos;
        while((split_pos = input.find_first_of("-,", current_pos)) != std::string::npos)
        {
            if (split_pos > current_pos)
                ids.push_back(stoll(input.substr(current_pos, split_pos-current_pos)));
            current_pos = split_pos+1;
        }
        ids.push_back(stoll(input.substr(current_pos, std::string::npos)));

        return ids;
    }
};

int main()
{
    Day02 day02;
    day02.sumInvalidIDs("02_input.txt", false);
    day02.sumInvalidIDs("02_input.txt", true);
    return 0;
}