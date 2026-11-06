#include "lib.h"
#include <iostream>
#include <string>

namespace Lib {

// ---------- Time private ----------
// 修改date信息
void Time::dataModify(const TimeData &tmp) { data = tmp; }

// 错误处理函数
void Time::info_err(std::string text) {
    std::cerr << "Lib::Time Error:" << std::endl;
    std::cerr << "  From " << text << std::endl;
    std::cerr << "  All Initialization Zero" << std::endl;
    data = TimeData{};
}

void Time::day_calculate(const short &year, const short &month,
                         const short &day) {
    // 计算月份是否规范
    bool leap =
        (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); // 润年判断
    int daysInMonth = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else if (month == 2) {
        daysInMonth = leap ? 29 : 28;
    }
    if (day == 0 || day > daysInMonth)
        info_err("day");
}
// --------------- End Time private ---

// ---------- Time public ----------

Time::Time(const unsigned short &year, const unsigned short &month,
           const unsigned short &day, const unsigned short &hour,
           const unsigned short &minutes, const unsigned short &second,
           const unsigned short &millisecond) {

    // 判断规范
    if (year > 9999)
        info_err("year");
    if (month > 12)
        info_err("month");
    if (hour > 24)
        info_err("hour");
    if (minutes > 64)
        info_err("minutes");
    if (second > 64)
        info_err("second");
    if (millisecond > 100)
        info_err("millisecond");
    day_calculate(year, month, day);
    TimeData tmp{year, month, day, hour, minutes, second, millisecond};
    dataModify(tmp);
}
Time::Time(const unsigned short &year, const unsigned short &month,
           const unsigned short &day) {
    if (year > 9999)
        info_err("year");
    if (month > 12)
        info_err("month");
    day_calculate(year, month, day);
    TimeData tmp{year, month, day, 0, 0, 0, 0};
    dataModify(tmp);
}
Time::Time() {
    TimeData tmp = {
        0, 0, 0, 0, 0, 0, 0,
    };
    dataModify(tmp);
}
// --------------- End Time public ---
} // End namespace Lib
