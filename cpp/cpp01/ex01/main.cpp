#include "Zombie.hpp"


int main(void)
{
    Zombie *AAA;

    int N = 4;
    AAA = zombieHorde(N, "AAA");
    for (int i = 0; i < N; i++)
		AAA[i].announce();
    delete [] AAA;

    Zombie *BBB;

    N = 1;
    BBB = zombieHorde(N, "BBB");
    for (int i = 0; i < N; i++)
		BBB[i].announce();
    delete [] BBB;

    Zombie *CCC;

    N = 3;
    CCC = zombieHorde(N, "CCC");
    for (int i = 0; i < N; i++)
		CCC[i].announce();
    delete [] CCC;
}