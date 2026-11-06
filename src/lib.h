#include <string>

namespace Lib {

class Time {
  private:
    struct TimeData {
        unsigned short year;
        unsigned short month;
        unsigned short day;
        unsigned short hour;
        unsigned short minutes;
        unsigned short second;
        unsigned short millisecond;
    };
    TimeData data{};
    void dataModify(const TimeData &tmp);
    void info_err(std::string text);
    void day_calculate(const short &year, const short &month, const short &day);

  public:
    Time(const unsigned short &year, const unsigned short &month,
         const unsigned short &day, const unsigned short &hour,
         const unsigned short &minutes, const unsigned short &second,
         const unsigned short &millisecond);
    Time(const unsigned short &year, const unsigned short &month,
         const unsigned short &day);
    Time();
}; // End class Time

} // End namespace Lib
