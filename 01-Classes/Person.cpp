#include "Person.h"

float Person::levelUp()
{
	Level++;
	Strength+= 2;
	Intelligence+= 1;
	Dexterity+= 1;
	return 0.0f;
}

float Person::StrCheck(float Str)
{
	if (Strength >= Str) 
	{
		return 1.0f;
	}
	else 
	{
		return 0.0f;
	}
}

float Person::IntCheck(float Int)
{
	if (Intelligence >= Int)
	{
		return 1.0f;
	}
	else
	{
		return 0.0f;
	}
}

float Person::DexCheck(float Dex)
{
	if (Dexterity >= Dex)
	{
		return 1.0f;
	}
	else
	{
		return 0.0f;
	}
}
