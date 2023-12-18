#include <iostream>
#include <assert.h>

class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        if (numRows <= 1)
        {
            return s;
        }

        int row = 0;
        bool down = true;
        std::string array[numRows];
        for (int i = 0; i < numRows; i++)
            array[i] = "";
        for (int i = 0; i < s.length(); i++)
        {
            array[row] += s[i];
            if (!row)
                down = true;
            else if (row == numRows - 1)
                down = false;

            down ? row++ : row--;
        }

        std::string answer = "";
        for (int i = 0; i < numRows; i++)
            answer += array[i];

        return answer;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    assert(solution.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    assert(solution.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    return 0;
}