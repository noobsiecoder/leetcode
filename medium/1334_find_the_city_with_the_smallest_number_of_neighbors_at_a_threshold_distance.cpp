#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>

// type alias for integer pair
using IntPair = std::pair<int, int>;
// type alias for a vector of type T
template <class T>
using VectorType = std::vector<T>;
// type alias for a vector in a vector of type Q
template <class Q>
using DoubleVectorType = std::vector<std::vector<Q>>;

// Store edge value and distance between the nodes
struct Node
{
    int edge;
    int dist;
    // default constructor to store value
    Node(int edge, int dist)
        : edge(edge), dist(dist) {}
};

// Runtime: 183ms; Beats 5.01% of users with C++
// Memory:  57.96MB; Beats 5.01% of users with C++
class Solution
{
private:
    // return shortest distance
    int dijsktra(int idx, std::map<int, VectorType<Node>> edge_map, int distanceThreshold)
    {
        std::priority_queue<IntPair, VectorType<IntPair>, std::greater<IntPair>> pq; // priority queue to store pairs in ascending order

        pq.push(IntPair(0, idx));
        std::set<int> visit;
        while (pq.size())
        {
            IntPair value = pq.top();
            pq.pop();
            if (visit.find(value.second) != visit.end()) // value.second exists
            {
                continue;
            }
            visit.insert(value.second);
            for (auto field : edge_map[value.second])
            {
                int tot_dist = value.first + field.dist;
                if (tot_dist <= distanceThreshold)
                {
                    pq.push(IntPair(tot_dist, field.edge));
                }
            }
        }

        return visit.size() - 1;
    }

public:
    int findTheCity(int n, DoubleVectorType<int> &edges, int distanceThreshold)
    {
        std::map<int, std::vector<Node>> edge_map;
        for (auto edge : edges)
        {
            Node *node = new Node(edge[1], edge[2]);
            int origin1 = edge[0];
            int origin2 = edge[1];
            edge_map[origin1].push_back(*node);

            node = new Node(edge[0], edge[2]);
            edge_map[origin2].push_back(*node);
        }

        int result = -1;
        int min_count = n;
        for (int i = 0; i < n; i++)
        {
            int count = dijsktra(i, edge_map, distanceThreshold);
            if (count <= min_count)
            {
                result = i;
                min_count = count;
            }
        }

        return result;
    }
};

int main(int argv, char **args)
{
    DoubleVectorType<int> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    Solution *solution = new Solution;
    int result = solution->findTheCity(4, edges, 4);
    std::cout << result << std::endl;

    edges = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
    result = solution->findTheCity(5, edges, 2);
    std::cout << result << std::endl;
    return 0;
}