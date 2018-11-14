#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
	unordered_set<int> numbers;
	unordered_set<int>::iterator it;
	numbers.insert(1);
	numbers.insert(10);
	numbers.insert(20);
	for(it=numbers.begin(),it!=numbers.end(),it++)
		cout(*it);
}
