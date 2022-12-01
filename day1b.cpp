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

void sort(int size)
{
	bool swapped; //were any nodes swapped on this pass?

	for (int i = 0; i < size; i++) //repeat for a maximum of how many nodes there are in the list
	{
		swapped = false;
		elf *temp = head;
		elf *ahead = head->next;
		while (temp != NULL && ahead != NULL) //while there are nodes left in the list
		{
			if (temp->cals < ahead->cals) //if the number is less than the next one, swap the nodes
			{
				int bufferCals = temp->cals;
				temp->cals = ahead->cals;
				ahead->cals = bufferCals;
				swapped = true;
			}
			temp = temp->next;
			ahead = ahead->next;
		}
		if (!swapped) //if we didn't need to swap any, the list is sorted
		{
			break;
		}
	}
}

int main(int argc, char *argv[])
{
	int size = 0; //holds size of elf list
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
				size++; //track # of nodes
			}
			else //line is a number
			{
				int calories = stoi(line); //convert string to integer
				total += calories; //append calories to total for this elf
			}
		}
	}
	
	//add the highest three elves and output the result
	sort(size); //sort the list in order of cals
	elf *temp = head;
	int result = 0;
	for (int i = 0; i < 3; i++)
	{
		if (temp == NULL)
		{
			cout << "Error: Not enough elves in the list!" << endl;
		}
		else //the elf node exists
		{
			result += temp->cals;
		}
		temp = temp->next;
	}
	
	cout << "The Three Elves with the most calories have: " << result << " calories!!" << endl;
	return 0;
}
