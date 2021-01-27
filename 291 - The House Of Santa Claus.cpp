#include <iostream>
#include <vector>
#include <queue>

struct node
{
	int value;
	std::vector<node*> connected;
};

void init(node nodes[6])
{
	for (int i = 0; i < 6; i++)
	{
		nodes[i].value = i;
	}

	nodes[0].connected.push_back(&nodes[1]);
	nodes[0].connected.push_back(&nodes[2]);
	nodes[0].connected.push_back(&nodes[4]);

	nodes[1].connected.push_back(&nodes[0]);
	nodes[1].connected.push_back(&nodes[2]);
	nodes[1].connected.push_back(&nodes[4]);

	nodes[2].connected.push_back(&nodes[0]);
	nodes[2].connected.push_back(&nodes[1]);
	nodes[2].connected.push_back(&nodes[3]);
	nodes[2].connected.push_back(&nodes[4]);

	nodes[3].connected.push_back(&nodes[2]);
	nodes[3].connected.push_back(&nodes[4]);

	nodes[4].connected.push_back(&nodes[0]);
	nodes[4].connected.push_back(&nodes[1]);
	nodes[4].connected.push_back(&nodes[2]);
	nodes[4].connected.push_back(&nodes[3]);
}

bool isline(int x, int y, std::vector<node*>& nodes)
{
	if (x == y || nodes.size() < 2)
	{
		return false;
	}

	for (int i = 0; i < (int)nodes.size() - 1; i++)
	{
		if ((nodes[i]->value == x && nodes[i + 1]->value == y) || (nodes[i]->value == y && nodes[i + 1]->value == x))
		{
			return true;
		}
	}

	return false;
}

int main()
{
	node nodes[6];
	init(nodes);

	std::queue<std::vector<node*>> pending;
	pending.push(std::vector<node*>{&nodes[0]});

	while (!pending.empty())
	{
		auto current = pending.front();
		pending.pop();

		for (auto& child : current.back()->connected)
		{
			if (!isline(child->value, current.back()->value, current))
			{
				auto n = current;
				n.push_back(child);
				pending.push(n);
			}
		}

		if (current.size() == 9)
		{
			for (auto& node : current)
			{
				std::cout << node->value + 1;
			}
			std::cout << std::endl;
		}
	}
}