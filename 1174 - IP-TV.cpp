#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>

class edge
{
public:
    int to;
    int cost;

    edge()
    {
        to = -1;
        cost = -1;
    }

    edge(int _to, int _cost)
    {
        to = _to;
        cost = _cost;
    }

    bool operator<(const edge &x) const
    {
        return (cost > x.cost);
    }
};

class node
{
public:
    int index;
    bool connected;
    std::vector<edge> edges;

    node()
    {
        index = -1;
        connected = false;
    }

    node(int _index)
    {
        index = _index;
        connected = false;
    }
};

int main()
{
    int tests;
    std::cin >> tests;

    while (tests--)
    {
        int m, n, cityIndex = 0;
        ;
        std::cin >> m >> n;

        std::vector<node> nodes;
        std::unordered_map<std::string, int> cities;

        for (int i = 0; i < n; i++)
        {
            int cost;
            std::string first, second;
            std::cin >> first >> second >> cost;

            if (cities.find(first) == cities.end())
            {
                nodes.push_back(node(cityIndex));
                cities[first] = cityIndex++;
            }

            if (cities.find(second) == cities.end())
            {
                nodes.push_back(node(cityIndex));
                cities[second] = cityIndex++;
            }

            nodes[cities[first]].edges.push_back(edge(cities[second], cost));
            nodes[cities[second]].edges.push_back(edge(cities[first], cost));
        }

        int connected = 0, cost = 0;
        std::priority_queue<edge> edgesQueue;

        nodes[0].connected = true;
        connected++;

        for (unsigned int i = 0; i < nodes[0].edges.size(); i++)
        {
            edgesQueue.push(nodes[0].edges[i]);
        }

        while (connected != m)
        {
            edge cheapest = edgesQueue.top();
            edgesQueue.pop();

            if (nodes[cheapest.to].connected)
            {
                continue;
            }

            nodes[cheapest.to].connected = true;
            cost += cheapest.cost;
            connected++;

            for (unsigned int i = 0; i < nodes[cheapest.to].edges.size(); i++)
            {
                if (!nodes[nodes[cheapest.to].edges[i].to].connected)
                {
                    edgesQueue.push(nodes[cheapest.to].edges[i]);
                }
            }
        }

        std::cout << cost << std::endl;

        if (tests != 0)
        {
            std::cout << std::endl;
        }
    }
}