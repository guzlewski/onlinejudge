#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

enum class status
{
	AC,
	WA,
	TLE,
	MLE
};

class turing_machine
{
private:
	class rule
	{
	public:
		int state;
		int letter;
		int nextState;
		int nextLetter;
		int head_move;

		rule(int _state = 0, int _letter = 0, int _nextState = 0, int _nextLetter = 0, int _move = 0)
		{
			state = _state;
			letter = _letter;
			nextState = _nextState;
			nextLetter = _nextLetter;
			head_move = _move;
		}

		~rule() {}
	};

	int *tape;
	int tapeSize, head;
	std::vector<rule> rules;

	rule *find_rule(int state, int letter)
	{
		for (auto &rule : rules)
		{
			if (rule.state == state && rule.letter == letter)
			{
				return &rule;
			}
		}

		return NULL;
	}

	bool validate_output(int expected_output)
	{
		int sum = 0;

		for (int i = 0; i < tapeSize; i++)
		{
			if (tape[i] == 0)
			{
				break;
			}

			sum += tape[i];
		}

		return sum == expected_output;
	}

public:
	turing_machine(int _tapeSize)
	{
		tape = new int[_tapeSize];
		tapeSize = _tapeSize;
		head = 0;
	}

	~turing_machine()
	{
		delete[] tape;
	}

	void add_rule(int state, int letter, int nextState, int nextLetter, char head_move)
	{
		rules.push_back(rule(state, letter, nextState, nextLetter, head_move == 'R' ? 1 : -1));
	}

	status run(int input, int output)
	{
		head = 0;
		memset(tape, 0, tapeSize * sizeof(int));

		for (int i = 0; i < input; i++)
		{
			tape[i] = 1;
		}

		rule *current = find_rule(0, tape[head]);

		for (int i = 0; i < 10000; i++)
		{
			if (current == NULL)
			{
				return validate_output(output) ? status::AC : status::WA;
			}

			tape[head] = current->nextLetter;
			head += current->head_move;

			if (head < 0 || head >= tapeSize)
			{
				return status::MLE;
			}

			current = find_rule(current->nextState, tape[head]);
		}

		return status::TLE;
	}
};

int main()
{
	int rules, tests;

	while (std::cin >> rules >> tests && rules != 0 && tests != 0)
	{
		turing_machine machine(1000);

		for (int i = 0; i < rules; i++)
		{
			char head_move;
			int state, letter, nextState, nextLetter;
			std::cin >> state >> letter >> nextState >> nextLetter >> head_move;

			machine.add_rule(state, letter, nextState, nextLetter, head_move);
		}

		for (int i = 0; i < tests; i++)
		{
			int input, output;
			std::cin >> input >> output;

			switch (machine.run(input, output))
			{
			case status::AC:
				std::cout << "AC" << std::endl;
				break;
			case status::WA:
				std::cout << "WA" << std::endl;
				break;
			case status::TLE:
				std::cout << "TLE" << std::endl;
				break;
			case status::MLE:
				std::cout << "MLE" << std::endl;
				break;
			default:
				break;
			}
		}
	}
}