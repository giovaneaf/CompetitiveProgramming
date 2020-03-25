#include <iostream>
using namespace std;

int main ()
{
	int players, rounds;
	cin >> players >> rounds;
	int score[players];
	int index, max, points, i, j;
	for (i = 0; i < players; i++)
		score[i] = 0;
	for (i = 0; i < rounds; i++)
	{
		for (j = 0; j < players; j++)
		{
			cin >> points;
			score[j] += points;
		}
	}
	max = score[0];
	index = 0;
	for (i = 1; i < players; i++)
	{
		if (score [i] >= max)
		{
			max = score[i];
			index = i;
		}
	}
	cout << index+1 << endl;
}
