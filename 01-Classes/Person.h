#pragma once

class Person 
{
private:
	float Level;
	float Strength;
	float Intelligence;
	float Dexterity;
public:
	float levelUp();
	float StrCheck(float Str);
	float IntCheck(float Int);
	float DexCheck(float Dex);
};