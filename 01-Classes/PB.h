#pragma once

class DigitalPiggyBank 
{
private:
	float currentMoney;
public:
	void deposit(float net);
	float withdraw();
	float balance() const;
}