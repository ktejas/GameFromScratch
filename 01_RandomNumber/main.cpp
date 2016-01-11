#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main()
{
	mt19937 randomGenerator(time(NULL));
	uniform_int_distribution<int> diceRoll(1, 6);

	for (int i = 0; i < 10; i++)
		cout << "I am rolling a " << diceRoll(randomGenerator) << endl;

	system("PAUSE");
	return 0;
}