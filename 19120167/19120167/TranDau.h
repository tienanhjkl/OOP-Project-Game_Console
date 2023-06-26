#pragma once
#include "NguoiChoi.h"
#include <fstream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <Windows.h>
using namespace std::chrono;
using namespace std::literals::chrono_literals;
/// <summary>
/// Struct lấy thời gian hiện thời của hệ thống
/// </summary>
struct ttm {
    int tm_sec; // seconds of minutes from 0 to 61
    int tm_min; // minutes of hour from 0 to 59
    int tm_hour; // hours of day from 0 to 24
    int tm_mday; // day of month from 1 to 31
    int tm_mon; // month of year from 0 to 11
    int tm_year; // year since 1900
    int tm_wday; // days since sunday
    int tm_yday; // days since January 1st
    int tm_isdst; // hours of daylight savings time
};
class TranDau
{
public:
    /// <summary>
    /// Hàm trả về chỉ số thuộc tính của Hero được truyền vào
    /// </summary>
    /// <param name="x"></param>
    /// <returns></returns>
    int getPropertiesHero(Hero x);
    /// <summary>
    /// Hàm đọc file ListHero.txt
    /// </summary>
    /// <param name="fileName"></param>
    /// <param name="list"></param>
    void DocFile_ListHero(Hero list[]);
    /// <summary>
    /// Hàm chọn Hero cho Đội User
    /// </summary>
    /// <param name="x"></param>
    /// <param name="list"></param>
    void ChonHero(NguoiChoi& x, Hero list[]);
    /// <summary>
    /// Hàm chọn ngẫu nhiên Hero cho Đội NPC
    /// </summary>
    /// <param name="NPC"></param>
    /// <param name="list"></param>
    void NPCHero(Hero NPC[], Hero list[]);
    /// <summary>
    /// Hàm xử lý hành động 2 Hero tấn công nhau trong 1 hiệp đấu
    /// </summary>
    /// <param name="x"></param>
    /// <param name="pc"></param>
    int MoiTruong(NguoiChoi& x, Hero NPC[]);
    /// <summary>
    /// 
    /// </summary>
    /// <param name="x"></param>
    /// <param name="pc"></param>
    void HiepDau(Hero& x, Hero& pc);
    /// <summary>
    /// Hàm kiểm tra đội thắng trong một hiệp đấu và trả về kết quả cho trận đấu
    /// </summary>
    /// <param name="Person"></param>
    /// <param name="PC"></param>
    /// <param name="winPerson"></reference>
    /// <param name="winNPC"></reference>
    /// <returns></1. for TEAM User Victory/ 2. for TEAM NPC Victory/0. for DRAW to 2 TEAM>
    int is_Victory(Hero Person, Hero PC, int& winPerson, int& winNPC);
    /// <summary>
    /// Thông báo kết quả ra màn hình Console
    /// </summary>
    /// <param name="x"></param>
    /// <param name="NPC"></param>
    /// <param name="RESULT"></param>
    void Result(NguoiChoi& x, Hero NPC[], int RESULT);
    /// <summary>
    /// Ghi kết quả trận đấu vào file LOG.txt
    /// </summary>
    /// <param name="x"></param>
    /// <param name="NPC"></param>
    void GhiFile_LOG(NguoiChoi& x, Hero NPC[], tm* tlm, int winPerson, int winNPC);
    /// <summary>
    /// Hàm đọc file LOG.txt
    /// </summary>
    /// <param name="hiepDau"></param>
    /// <param name="i"></param>
    void DocFile_LOG(string hiepDau[], size_t& i);
    /// <summary>
    /// Hàm hiển thị thông tin cua một trận đấu
    /// </summary>
    /// <param name="hiepDau"></param>
    /// <param name="LOG_thoiGian"></param>
    /// <returns></returns>
    bool HienThiHiepDau(string hiepDau, string LOG_thoiGian);
    /// <summary>
    /// Hàm thực thi toàn bộ chương trình
    /// </summary>
    /// <param name="tranDau"></param>
    /// <param name="TRANDAU"></param>
    friend void Program(TranDau& tranDau, string TRANDAU[]);
};
/// <summary>
/// Hàm di chuyên vị trí con trỏ tại màn hình Console
/// </summary>
/// <param name="posX"></param>
/// <param name="posY"></param>
void GoTo(SHORT posX, SHORT posY);