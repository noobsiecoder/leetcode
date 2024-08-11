#include <vector>
#include <string>
#include <cassert>

#include <iostream>

// Runtime: 6ms; Beats 65.54% of users with C++
// Memory:  12.24MB; Beats 60.05% of users with C++
class Solution
{
private:
    std::vector<int> unionFind;
    size_t len;

    int _find(int i)
    {
        if (i != unionFind[i])
            unionFind[i] = _find(unionFind[i]);
        return unionFind[i];
    }

    void _union(int i, int j)
    {
        int p = _find(i);
        int q = _find(j);
        unionFind[p] = q;
    }

public:
    int regionsBySlashes(std::vector<std::string> &grid)
    {
        this->len = grid.size();
        this->unionFind.resize(this->len * this->len * 4);

        for (size_t i = 0; i < this->len * this->len * 4; i++)
            this->unionFind[i] = i;

        for (size_t i = 0; i < this->len; i++)
        {
            for (size_t j = 0; j < this->len; j++)
            {
                char ch = grid[i][j];
                size_t idx = i * 4 * this->len + j * 4;
                switch (ch)
                {
                case ' ':
                    this->_union(idx, idx + 1);
                    this->_union(idx + 1, idx + 2);
                    this->_union(idx + 2, idx + 3);
                    break;
                case '/':
                    this->_union(idx, idx + 3);
                    this->_union(idx + 1, idx + 2);
                    break;
                case '\\':
                    this->_union(idx, idx + 1);
                    this->_union(idx + 2, idx + 3);
                    break;
                }
                if (i + 1 < this->len)
                    this->_union(idx + 2, idx + 4 * this->len);
                if (j + 1 < this->len)
                    this->_union(idx + 1, idx + 4 + 3);
            }
        }

        int res = 0;
        for (size_t i = 0; i < this->len * this->len * 4; i++)
            if (unionFind[i] == i)
                res++;

        return res;
    }
};

int main(int argv, char **argc)
{
    Solution *solution = new Solution();
    std::vector<std::string> grid = {"/\\", "\\/"};
    int res = solution->regionsBySlashes(grid);
    assert(res == 5);
}