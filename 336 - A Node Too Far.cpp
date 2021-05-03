#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

int main()
{
	int caseNr = 0, nc;

	while (std::cin >> nc && nc != 0)
	{
		std::unordered_map<int, std::vector<int>> nodes;

		for (int i = 0; i < nc; i++)
		{
			int left, right;
			std::cin >> left >> right;

			nodes[left].push_back(right);
			nodes[right].push_back(left);
		}

		int n, ttl;
		while (std::cin >> n >> ttl && (n != 0 || ttl != 0))
		{
			std::queue<int> pending;
			std::unordered_map<int, bool> visited;

			pending.push(n);

			for (int i = 0; i < ttl; i++)
			{
				std::queue<int> temp;

				while (!pending.empty())
				{
					int current = pending.front();

					pending.pop();
					visited[current] = true;

					for (auto &x : nodes[current])
					{
						if (!visited[x])
						{
							temp.push(x);
						}
					}
				}

				pending = temp;
			}

			if (ttl == 0 && nodes.find(n) != nodes.end())
			{
				visited[n] = true;
			}

			std::cout << "Case " << ++caseNr << ": " << nodes.size() - visited.size() << " nodes not reachable from node " << n << " with TTL = " << ttl << "." << std::endl;
		}
	}
}