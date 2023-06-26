#pragma once
#include <iostream>
#include <string>
using namespace std;
class Hero
{
private:
    string Ten, ThuocTinh;
    double Mau, Cong, Thu, TocDo;
public:
    /// <summary>
    /// Constructor
    /// </summary>
    Hero();
    Hero(const Hero& x);
    Hero(string ten, string thuocTinh, double mau, double cong, double thu, double tocDo);
    /// <summary>
    /// DESTRUCTOR
    /// </summary>
    virtual ~Hero();
    /// <summary>
    /// Hàm cài đặt tên Hero
    /// </summary>
    /// <param name="ten"></param>
    void setName(string ten);
    /// <summary>
    /// Hàm cài đặt thuộc tính Hero
    /// </summary>
    /// <param name="ten"></param>
    void setProperties(string thuocTinh);
    /// <summary>
    /// Hàm cài đặt chỉ số máu Hero
    /// </summary>
    /// <param name="ten"></param>
    void setBlood(double mau);
    /// <summary>
    /// Hàm cài đặt chỉ số tấn công Hero
    /// </summary>
    /// <param name="ten"></param>
    void setDamage(double cong);
    /// <summary>
    /// Hàm cài đặt chỉ số phòng thủ Hero
    /// </summary>
    /// <param name="ten"></param>
    void setDefend(double thu);
    /// <summary>
    /// Hàm cài đặt chỉ số tốc độ ra đòn của Hero
    /// </summary>
    /// <param name="ten"></param>
    void setSpeed(double tocDo);
    /// <summary>
    /// Hàm đọc tên Hero
    /// </summary>
    /// <param name="ten"></param>
    string getName();
    /// <summary>
    /// Hàm đọc thuộc tính Hero
    /// </summary>
    /// <param name="ten"></param>
    string getProperties();
    /// <summary>
    /// Hàm đọc chỉ số máu của Hero
    /// </summary>
    /// <param name="ten"></param>
    double getBlood();
    /// <summary>
    /// Hàm đọc chỉ số tấn công của Hero
    /// </summary>
    /// <param name="ten"></param>
    double getDamage();
    /// <summary>
    /// Hàm đọc chỉ số phòng thủ của Hero
    /// </summary>
    /// <param name="ten"></param>
    double getDefend();
    /// <summary>
    /// Hàm đọc chỉ số tốc độ của Hero
    /// </summary>
    /// <param name="ten"></param>
    double getSpeed();
    /// <summary>
    /// Operator '<<', xuất đối tượng Hero
    /// </summary>
    /// <param name="out"></param>
    /// <param name="x"></param>
    /// <returns></returns>
    friend ostream& operator<<(ostream& out, Hero x)
    {
        out << "\n- Name: " << x.getName();
        out << "\n- Properties: " << x.getProperties();
        out << "\n- Damage: " << x.getDamage();
        out << "\n- Defend: " << x.getDefend();
        out << "\n- Blood: " << x.getBlood();
        out << "\n- Speed: " << x.getSpeed();
        out << endl;
        return out;
    }
};