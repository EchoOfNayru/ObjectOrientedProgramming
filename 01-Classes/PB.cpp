#include "PB.h"

void DigitalPiggyBank::deposit(float net)
{
	currentMoney = currentMoney + net;
}

float DigitalPiggyBank::withdraw()
{
	float placeholder = currentMoney;
	currentMoney = 0;
	return placeholder;
}

float DigitalPiggyBank::balance() const
{
	return currentMoney;
}
