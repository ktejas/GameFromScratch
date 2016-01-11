#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main()
{
	int numOfHumans, numOfZombies;
	int humansLeft, zombiesLeft;
	
	int humanHealth = 100, zombieHealth = 50;
	int humanAttack, zombieAttack;

	mt19937 randomGenerator(time(NULL));
	uniform_real_distribution<float> attackDamage(0.0f, 1.0f);

	cout << "****Humans vs Zombies!****" << endl << endl;
	cout << "Input the number of humans:" << endl;
	cin >> numOfHumans;
	cout << "Input the number of zombies:" << endl;
	cin >> numOfZombies;

	humansLeft = numOfHumans;
	zombiesLeft = numOfZombies;

	cout << "Beginning Combat!" << endl << endl;
	cout << "(Combat Noises)" << endl << endl;

	while (humansLeft != 0 && zombiesLeft != 0)
	{
		humanAttack = 10 * attackDamage(randomGenerator);
		zombieAttack = 10 * attackDamage(randomGenerator);

		humanHealth -= zombieAttack;
		if (humanHealth <= 0)
		{
			humansLeft--;
			if(humansLeft != 0)
				humanHealth = 100;
		}
		zombieHealth -= humanAttack;
		if (zombieHealth <= 0)
		{
			zombiesLeft--;
			if(zombiesLeft != 0)
				zombieHealth = 50;
		}
	}

	cout << "Combat ended." << endl << endl;

	if (humansLeft == 0)
	{
		cout << "Zombies Win!" << endl;
		cout << "There are " << zombiesLeft << " zombies left." << endl;
	}
	else if(zombiesLeft == 0)
	{
		cout << "Humans Win!" << endl << endl;
		cout << "There are " << humansLeft << " humans left." << endl;
	}

	cout << numOfHumans - humansLeft << " humans and " << numOfZombies - zombiesLeft << " zombies lost their lives. RIP :(" << endl;

	system("PAUSE");
	return 0;
}