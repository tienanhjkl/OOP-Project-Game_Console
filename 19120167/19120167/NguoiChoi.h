#pragma once
#include "Hero.h"

class NguoiChoi
{
protected:
	string TenNguoiChoi;
	Hero Hero_One;
	Hero Hero_Two;
	Hero Hero_Three;
public:
	/// <summary>
	/// CONSTRUCTOR
	/// </summary>
	NguoiChoi();
	NguoiChoi(const NguoiChoi& a);
	NguoiChoi(string tenNguoiChoi);
	/// <summary>
	/// DESTRUCTOR
	/// </summary>
	virtual ~NguoiChoi();
	/// <summary>
	/// Hàm cài đặt tên người chơi
	/// </summary>
	/// <param name="tenNguoiChoi"></param>
	void setTenNguoiChoi(string tenNguoiChoi);
	/// <summary>
	/// Hàm cài đặt danh sách Hero cho người chơi
	/// </summary>
	/// <param name="x"></param>
	/// <param name="thuTu"></param>
	void setListHero(Hero x, int thuTu);
	/// <summary>
	/// Hàm đọc tên người chơi
	/// </summary>
	/// <returns></returns>
	string getTenNguoiChoi();
	/// <summary>
	/// Hàm đọc (lấy ra) một Hero, truyền vào biến thứ tự để lấy cụ thể Hero thứ mấy
	/// </summary>
	/// <param name="thuTu"></param>
	/// <returns></returns>
	Hero& getHero(int thuTu);
	/// <summary>
	/// Hàm xử lý các thuộc tính của 2 Hero khi đối kháng với nhau
	/// </summary>
	/// <param name="may"></param>
	/// <param name="thuTuHero"></param>
	/// <returns></returns>
	bool DoiKhang(Hero& may, int thuTuHero);
	/// <summary>
	/// Hàm hiển thị các Hero cua người chơi
	/// </summary>
	void HienThiTeamHero();
	//
	friend bool CungDoi(Hero& hero_1, Hero& hero_2, Hero& hero_3);
};
/// <summary>
/// Hàm xử lý các thuộc tính của Hero khi cùng 1 đội
/// </summary>
/// <param name="hero_1"></param>
/// <param name="hero_2"></param>
/// <param name="hero_3"></param>
/// <returns></returns>
bool CungDoi(Hero& hero_1, Hero& hero_2, Hero& hero_3);