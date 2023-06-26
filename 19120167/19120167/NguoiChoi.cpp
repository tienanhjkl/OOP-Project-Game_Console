#include "NguoiChoi.h"
//
NguoiChoi::NguoiChoi()
{
	this->TenNguoiChoi = "";
}
//
NguoiChoi::NguoiChoi(const NguoiChoi& a)
{
	this->TenNguoiChoi = a.TenNguoiChoi;
}
//
NguoiChoi::NguoiChoi(string tenNguoiChoi)
{
	this->TenNguoiChoi = tenNguoiChoi;
}
//
NguoiChoi::~NguoiChoi()
{
	this->TenNguoiChoi = "";
	this->Hero_One.~Hero();
	this->Hero_Two.~Hero();
	this->Hero_Three.~Hero();
}
//
void NguoiChoi::setTenNguoiChoi(string tenNguoiChoi)
{
	this->TenNguoiChoi = tenNguoiChoi;
}
//
void NguoiChoi::setListHero(Hero x, int thuTu)
{
	if (thuTu == 1)
		this->Hero_One = x;
	else if (thuTu == 2)
		this->Hero_Two = x;
	else
		this->Hero_Three = x;
}
//
string NguoiChoi::getTenNguoiChoi()
{
	return string(this->TenNguoiChoi);
}
//
Hero& NguoiChoi::getHero(int thuTu)
{
	if (thuTu == 1)
		return Hero_One;
	else if (thuTu == 2)
		return Hero_Two;
	else
		return Hero_Three;
}
//
bool CungDoi(Hero& hero_1, Hero& hero_2, Hero& hero_3)
{
	int x[3];
	// Hero 1
	if (hero_1.getProperties() == "Wood")
		x[0] = 1;
	else if (hero_1.getProperties() == "Earth")
		x[0] = 2;
	else if (hero_1.getProperties() == "Water")
		x[0] = 3;
	else if (hero_1.getProperties() == "Fire")
		x[0] = 4;
	else if (hero_1.getProperties() == "Metal")
		x[0] = 5;
	// Hero 2
	if (hero_2.getProperties() == "Wood")
		x[1] = 1;
	else if (hero_2.getProperties() == "Earth")
		x[1] = 2;
	else if (hero_2.getProperties() == "Water")
		x[1] = 3;
	else if (hero_2.getProperties() == "Fire")
		x[1] = 4;
	else if (hero_2.getProperties() == "Metal")
		x[1] = 5;
	// Hero 3
	if (hero_3.getProperties() == "Wood")
		x[2] = 1;
	else if (hero_3.getProperties() == "Earth")
		x[2] = 2;
	else if (hero_3.getProperties() == "Water")
		x[2] = 3;
	else if (hero_3.getProperties() == "Fire")
		x[2] = 4;
	else if (hero_3.getProperties() == "Metal")
		x[2] = 5;
	// Tuong Khac Hero 1
	if (x[0] == 1 && (x[1] == 5 || x[2] == 5))
	{
		hero_1.setSpeed(hero_1.getSpeed() * 1.1);
		if(x[1] == 5 && x[2] == 5)
			hero_1.setSpeed(hero_1.getSpeed() * 1.1);
	}
	else if (x[0] - 1 == x[1] || x[0] - 1 == x[2])
	{
		hero_1.setSpeed(hero_1.getSpeed() * 1.1);
		if(x[0] - 1 == x[1] && x[0] - 1 == x[2])
			hero_1.setSpeed(hero_1.getSpeed() * 1.1);
	}
	//Tuong Khac Hero 2
	if (x[1] == 1 && (x[0] == 5 || x[2] == 5))
	{
		hero_2.setSpeed(hero_2.getSpeed() * 1.1);
		if(x[0] == 5 && x[2] == 5)
			hero_2.setSpeed(hero_2.getSpeed() * 1.1);
	}
	else if (x[1] - 1 == x[0] || x[1] - 1 == x[2])
	{
		hero_2.setSpeed(hero_2.getSpeed() * 1.1);
		if(x[1] - 1 == x[0] && x[1] - 1 == x[2])
			hero_2.setSpeed(hero_2.getSpeed() * 1.1);
	}
	// Tuong Khac Hero 3
	if (x[2] == 1 && (x[1] == 5 || x[0] == 5))
	{
		hero_3.setSpeed(hero_3.getSpeed() * 1.1);
		if(x[1] == 5 && x[0] == 5)
			hero_3.setSpeed(hero_3.getSpeed() * 1.1);
	}
	else if (x[2] - 1 == x[1] || x[2] - 1 == x[0])
	{
		hero_3.setSpeed(hero_3.getSpeed() * 1.1);
		if(x[2] - 1 == x[1] && x[2] - 1 == x[0])
			hero_3.setSpeed(hero_3.getSpeed() * 1.1);
	}
	// Tuong Sinh Hero 1
	if (x[0] == 1 && (x[1] == 3 || x[2] == 3))
	{
		hero_1.setBlood(hero_1.getBlood() * 1.15);
		if(x[1] == 3 && x[2] == 3)
			hero_1.setBlood(hero_1.getBlood() * 1.15);
	}
	else if (x[0] % 2 == 0)
	{
		if (x[0] == 2)
		{
			if (x[1] == 4 || x[2] == 4)
			{
				hero_1.setBlood(hero_1.getBlood() * 1.15);
				if(x[1] == 4 && x[2] == 4)
					hero_1.setBlood(hero_1.getBlood() * 1.15);
			}
		}
		else
		{
			if (x[1] ==1 || x[2] == 1)
			{
				hero_1.setBlood(hero_1.getBlood() * 1.15);
				if (x[1] == 1 && x[2] == 1)
					hero_1.setBlood(hero_1.getBlood() * 1.15);
			}
		}
	}
	else
	{
		if (x[0] == 3)
		{
			if (x[1] == 5 || x[2] == 5)
			{
				hero_1.setBlood(hero_1.getBlood() * 1.15);
				if(x[1] == 5 && x[2] == 5)
					hero_1.setBlood(hero_1.getBlood() * 1.15);
			}
		}
		else
		{
			if (x[1] == 2 || x[2] == 2)
			{
				hero_1.setBlood(hero_1.getBlood() * 1.15);
				if (x[1] == 2 && x[2] == 2)
					hero_1.setBlood(hero_1.getBlood() * 1.15);
			}
		}
	}
	// Tuong Sinh Hero 2
	if (x[1] == 1 && (x[0] == 3 || x[2] == 3))
	{
		hero_2.setBlood(hero_2.getBlood() * 1.15);
		if (x[0] == 3 && x[2] == 3)
			hero_2.setBlood(hero_2.getBlood() * 1.15);
	}
	else if (x[1] % 2 == 0)
	{
		if (x[1] == 2)
		{
			if (x[0] == 4 || x[2] == 4)
			{
				hero_2.setBlood(hero_2.getBlood() * 1.15);
				if (x[0] == 4 && x[2] == 4)
					hero_2.setBlood(hero_2.getBlood() * 1.15);
			}
		}
		else
		{
			if (x[0] == 1 || x[2] == 1)
			{
				hero_2.setBlood(hero_2.getBlood() * 1.15);
				if (x[0] == 1 && x[2] == 1)
					hero_2.setBlood(hero_2.getBlood() * 1.15);
			}
		}
	}
	else
	{
		if (x[1] == 3)
		{
			if (x[0] == 5 || x[2] == 5)
			{
				hero_2.setBlood(hero_2.getBlood() * 1.15);
				if (x[0] == 5 && x[2] == 5)
					hero_2.setBlood(hero_2.getBlood() * 1.15);
			}
		}
		else
		{
			if (x[0] == 2 || x[2] == 2)
			{
				hero_2.setBlood(hero_2.getBlood() * 1.15);
				if (x[0] == 2 && x[2] == 2)
					hero_2.setBlood(hero_2.getBlood() * 1.15);
			}
		}
	}
	// Tuong Sinh Hero 1
	if (x[2] == 1 && (x[1] == 3 || x[2] == 3))
	{
		hero_3.setBlood(hero_3.getBlood() * 1.15);
		if (x[1] == 3 && x[0] == 3)
			hero_3.setBlood(hero_3.getBlood() * 1.15);
	}
	else if (x[2] % 2 == 0)
	{
		if (x[2] == 2)
		{
			if (x[1] == 4 || x[0] == 4)
			{
				hero_3.setBlood(hero_3.getBlood() * 1.15);
				if (x[1] == 4 && x[0] == 4)
					hero_3.setBlood(hero_3.getBlood() * 1.15);
			}
		}
		else
		{
			if (x[1] == 1 || x[0] == 1)
			{
				hero_3.setBlood(hero_3.getBlood() * 1.15);
				if (x[1] == 1 && x[0] == 1)
					hero_3.setBlood(hero_3.getBlood() * 1.15);
			}
		}
	}
	else
	{
		if (x[2] == 3)
		{
			if (x[1] == 5 || x[0] == 5)
			{
				hero_3.setBlood(hero_3.getBlood() * 1.15);
				if (x[1] == 5 && x[0] == 5)
					hero_3.setBlood(hero_3.getBlood() * 1.15);
			}
		}
		else
		{
			if (x[1] == 2 || x[0] == 2)
			{
				hero_3.setBlood(hero_3.getBlood() * 1.15);
				if (x[1] == 2 && x[0] == 2)
					hero_3.setBlood(hero_3.getBlood() * 1.15);
			}
		}
	}
	return true;
}
//
bool NguoiChoi::DoiKhang(Hero& may, int thuTuHero)
{
	int x = 0, y = 0;
	if (may.getProperties() == "Wood")
		x = 1;
	else if (may.getProperties() == "Earth")
		x = 2;
	else if (may.getProperties() == "Water")
		x = 3;
	else if (may.getProperties() == "Fire")
		x = 4;
	else if (may.getProperties() == "Metal")
		x = 5;
	//
	if (this->getHero(thuTuHero).getProperties() == "Wood")
		y = 1;
	else if (this->getHero(thuTuHero).getProperties() == "Earth")
		y = 2;
	else if (this->getHero(thuTuHero).getProperties() == "Water")
		y = 3;
	else if (this->getHero(thuTuHero).getProperties() == "Fire")
		y = 4;
	else if (this->getHero(thuTuHero).getProperties() == "Metal")
		y = 5;
	//
	if (x == y)
		return true;
	if (x == 1 && y == 5)
	{
		may.setDefend(may.getDefend() * 0.5);
		this->getHero(thuTuHero).setDamage(this->getHero(thuTuHero).getDamage() * 1.1);
	}
	else if (x - 1 == y)
	{
		may.setDefend(may.getDefend() * 0.5);
		this->getHero(thuTuHero).setDamage(this->getHero(thuTuHero).getDamage() * 1.1);
	}
	//
	if (x == 5 && y == 1)
	{
		this->getHero(thuTuHero).setDefend(this->getHero(thuTuHero).getDefend() * 0.5);
		may.setDamage(may.getDamage() * 1.1);
	}
	else if (y - 1 == x)
	{
		this->getHero(thuTuHero).setDefend(this->getHero(thuTuHero).getDefend() * 0.5);
		may.setDamage(may.getDamage() * 1.1);
	}
	return true;
}
//
void NguoiChoi::HienThiTeamHero()
{
	cout << "----- " << this->getTenNguoiChoi() << " Team -----\n";
	cout << "\t- 1 -" << this->Hero_One;
	cout << "\n\t- 2 -" << this->Hero_Two;
	cout << "\n\t- 3 -" << this->Hero_Three;
}
