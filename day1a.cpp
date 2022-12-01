#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class elf {
	public:
		int cals;
		elf *next = nullptr;

		elf(){}
};

elf *head;

int main (int argc, char *argv[])
{
	//open input file
	ifstream input;
	input.open(argv[1]);
	if (!input.is_open())
	{
		cout << "Error openning input file: \"" << argv[1] << "\"" << endl;
		return 1;
	}
	else //file is good, construct a list of totals for each elf
	{
		string line; //will hold value of one line at a time
		int total = 0; //will hold running total of elf's calories
		while (input.good())
		{
			getline(input, line);
			if (line.empty())
			{
				//insert total value into linked list
				elf *temp = new elf();
				temp->cals = total;
				temp->next = head;
				head = temp;
				
				total = 0; //reset value to begin again
			}
			else //line is a number
			{
				int calories = stoi(line); //convert string to integer
				total += calories; //append calories to total for this elf
			}
		}
	}
	
	//search for elf with highest calories and output result
	elf *temp = head;
	int result = 0;
	while (temp != NULL)
	{
		if (result < temp->cals)
		{
			result = temp->cals;
		}
		temp = temp->next;
	}
	cout << "The Elf with the most calories has: " << result << " calories!!" << endl;
	return 0;
}
