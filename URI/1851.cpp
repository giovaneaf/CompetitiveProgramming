#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
	priority_queue< tuple <double, int, int, unsigned long long int> > pq;
	int Ti, Fi;
	unsigned long long int day = 0;
	bool training = false;
	unsigned long long int time, arrival, price;
	unsigned long long int cost = 0;
	while(cin >> Ti >> Fi)
	{
		day++;
		pq.push(make_tuple(((double)Fi/Ti), Ti, Fi, day));
		if(!training)
		{
			training = true;
			time = get<1>(pq.top());
			price = get<2>(pq.top());
			arrival = get<3>(pq.top());
			cost += ((day - arrival)*price);
			pq.pop();
		}
		if(time == 1)
			training = false;
		time--;
	}
	day += time+1;
	while(pq.size())
	{
		time = get<1>(pq.top());
		price = get<2>(pq.top());
		arrival = get<3>(pq.top());
		cost += ((day - arrival)*price);
		day += time;
		pq.pop();
	}
	cout << cost << endl;
	return 0;
}
