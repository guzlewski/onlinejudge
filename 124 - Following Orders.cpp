#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Node
{
public:
	bool used = false;
	char value = 0;
	vector<Node*> parents;
	vector<Node*> children;

	static bool Compare(const Node* n1, const Node* n2);
};

bool Node::Compare(const Node* n1, const Node* n2)
{
	return n1->value < n2->value;
}

class Graph
{
public:
	vector<Node> nodes;

	void AddEdge(char a, char b);
	void Solve();

private:
	vector<Node*> parentless;

	Graph Clone();
	int FindInNodes(char x);
	int FindInVector(vector<Node*>& n, char x);
	bool IsParentless(vector<Node*>& parents);
	void SolveRecursively(string order);
	void ReloadParentless();
};

Graph Graph::Clone()
{
	Graph g;

	for (int i = 0; i < nodes.size(); i++)
	{
		Node n;
		n.used = nodes[i].used;
		n.value = nodes[i].value;
		g.nodes.push_back(n);
	}

	for (int i = 0; i < nodes.size(); i++)
	{
		for (int j = 0; j < nodes[i].children.size(); j++)
			g.nodes[i].children.push_back(&g.nodes[FindInNodes(nodes[i].children[j]->value)]);

		for (int j = 0; j < nodes[i].parents.size(); j++)
			g.nodes[i].parents.push_back(&g.nodes[FindInNodes(nodes[i].parents[j]->value)]);
	}

	g.ReloadParentless();

	return g;
}

void Graph::SolveRecursively(string order)
{
	if (parentless.size() == 0)
	{
		cout << order << endl;
	}
	else if (parentless.size() == 1)
	{
		char value = parentless[0]->value;
		parentless[0]->used = true;

		ReloadParentless();
		SolveRecursively(order + value);
	}
	else
	{
		for (int j = 0; j < parentless.size(); j++)
		{
			char value = parentless[j]->value;
			Graph g = Clone();
			g.parentless[j]->used = true;

			g.ReloadParentless();
			g.SolveRecursively(order + value
			);
		}
	}
}

int Graph::FindInNodes(char x)
{
	for (int i = 0; i < nodes.size(); i++)
		if (nodes[i].value == x) return i;

	return -1;
}

int Graph::FindInVector(vector<Node*>& n, char x)
{
	for (int i = 0; i < n.size(); i++)
		if (n[i]->value == x) return i;

	return -1;
}

void Graph::AddEdge(char a, char b)
{
	int first = FindInNodes(a), second = FindInNodes(b);
	Node* nfirst = &nodes[first], * nsecond = &nodes[second];

	if (FindInVector(nfirst->children, nsecond->value) == -1) nfirst->children.push_back(nsecond);
	if (FindInVector(nsecond->parents, nfirst->value) == -1) nsecond->parents.push_back(nfirst);
}

bool Graph::IsParentless(vector<Node*>& parents)
{
	for (int i = 0; i < parents.size(); i++)
		if (parents[i]->used == false) return false;

	return true;
}

void Graph::ReloadParentless()
{
	parentless.clear();
	for (int i = 0; i < nodes.size(); i++)
		if (nodes[i].used == false && IsParentless(nodes[i].parents))
			parentless.push_back(&nodes[i]);

	sort(parentless.begin(), parentless.end(), Node::Compare);
}

void Graph::Solve()
{
	ReloadParentless();
	SolveRecursively("");
}

int main()
{
	bool firstinput = true;
	string line;
	while (getline(cin, line))
	{
		stringstream ss;
		ss << line;

		char temp;
		vector<Node> nodes;

		while (ss >> temp)
		{
			Node n;
			n.value = temp;
			nodes.push_back(n);
		}

		getline(cin, line);
		ss.clear();
		ss << line;

		Graph graph;
		graph.nodes = nodes;

		char first, second;
		while (ss >> first >> second)
			graph.AddEdge(first, second);

		if (firstinput) firstinput = false;
		else cout << endl;

		graph.Solve();
	}

	return 0;
}