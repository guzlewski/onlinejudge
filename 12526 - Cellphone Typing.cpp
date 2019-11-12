#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Node
{
public:
	char value = 0;
	vector<Node> children;
	int FindChild(char value);
};

int Node::FindChild(char value)
{
	for (int i = 0; i < children.size(); i++)
		if (children[i].value == value) return i;

	return -1;
}

class Trie
{
public:
	void Add(string word);
	int Solve();

private:
	Node root;
	void AddRecursively(Node& node, string word, int index);
	int SolveRecursively(Node& node, int count);
};

void Trie::Add(string word)
{
	AddRecursively(root, word, 0);
}

int Trie::Solve()
{
	if (root.children.size() < 2) return SolveRecursively(root, 1);
	else return SolveRecursively(root, 0);
}

void Trie::AddRecursively(Node& node, string word, int index)
{
	if (index > word.size()) return;

	char value;
	if (index == word.size()) value = '\0';
	else value = word[index];

	int next = node.FindChild(value);

	if (next != -1)
	{
		AddRecursively(node.children[next], word, index + 1);
		return;
	}

	Node n;
	n.value = value;
	node.children.push_back(n);

	AddRecursively(node.children[node.children.size() - 1], word, index + 1);
}

int Trie::SolveRecursively(Node& node, int count)
{
	if (node.children.size() == 0) return count;
	else if (node.children.size() == 1) return SolveRecursively(node.children[0], count);
	else
	{
		int partialsum = 0;
		for (int i = 0; i < node.children.size(); i++)
		{
			if (node.children[i].value != '\0') partialsum += SolveRecursively(node.children[i], count + 1);
			else partialsum += SolveRecursively(node.children[i], count);
		}

		return partialsum;
	}
}

int main()
{
	int count;
	while (cin >> count)
	{
		Trie trie;

		string temp;
		for (int i = 0; i < count; i++)
		{
			cin >> temp;
			trie.Add(temp);
		}

		cout << setprecision(2) << fixed << trie.Solve() / (double)count << endl;
	}

	return 0;
}