#include "Hero.h"
//
Hero::Hero()
{
	this->Ten = "";
	this->ThuocTinh = "";
	this->Mau = 0.0;
	this->Cong = 0.0;
	this->Thu= 0.0;
	this->TocDo= 0.0;
}
Hero::Hero(const Hero& x)
{
	this->Ten = x.Ten;
	this->ThuocTinh = x.ThuocTinh;
	this->Mau = x.Mau;
	this->Cong = x.Cong;
	this->Thu = x.Thu;
	this->TocDo = x.TocDo;
}
//
Hero::Hero(string ten, string thuocTinh, double mau, double cong, double thu, double tocDo)
{
	this->Ten = ten;
	this->ThuocTinh = thuocTinh;
	this->Mau = mau;
	this->Cong = cong;
	this->Thu = thu;
	this->TocDo = tocDo;
}
//
Hero::~Hero()
{
	this->Ten = "";
	this->ThuocTinh = "";
	this->Mau = 0.0;
	this->Cong = 0.0;
	this->Thu = 0.0;
	this->TocDo = 0.0;
}
//
void Hero::setName(string ten)
{
	this->Ten = ten;
}
//
void Hero::setProperties(string thuocTinh)
{
	this->ThuocTinh = thuocTinh;
}
//
void Hero::setBlood(double mau)
{
	this->Mau = mau;
}
//
void Hero::setDamage(double cong)
{
	this->Cong = cong;
}
//
void Hero::setDefend(double thu)
{
	this->Thu = thu;
}
//
void Hero::setSpeed(double tocDo)
{
	this->TocDo = tocDo;
}
//
string Hero::getName()
{
	return string(this->Ten);
}
//
string Hero::getProperties()
{
	return string(this->ThuocTinh);
}
//
double Hero::getBlood()
{
	return this->Mau;
}
//
double Hero::getDamage()
{
	return this->Cong;
}
//
double Hero::getDefend()
{
	return this->Thu;
}
//
double Hero::getSpeed()
{
	return this->TocDo;
}