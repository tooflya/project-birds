#ifndef _DATE_TIME_H_
#define _DATE_TIME_H_

#include <ctime>
#include <cstdio>
#include <cstring>

/**
 * @class CCDate
 *
 * @brief 
 */
class CCDate
{
    public:
    CCDate()
    {
		time_ = ::time(NULL); 
		::localtime_r(&time_, &tm_); 
    }
	
    CCDate(const CCDate &dt)
    {
		time_ = dt.time_; 
		tm_ = dt.tm_;
    }
	
    CCDate(const struct tm &tm_val)
    {
		tm_ = tm_val; 
		time_ = ::mktime(&tm_); 
    }
	
    explicit CCDate(const time_t tt)
    {
		time_ = tt; 
		::localtime_r(&time_, &tm_); 
    }
	
    // Override operator
    inline CCDate& operator = (const CCDate &dt)
    {
		if (this != &dt)
		{
			this->time_ = dt.time_;
			this->tm_   = dt.tm_;
		}
		return *this;
    }
    inline CCDate operator - (const CCDate &dt) const
    {
		return CCDate(this->time_ - dt.time_);
    }
    inline CCDate operator - (const CCDate &dt)
    {
		return CCDate(this->time_ - dt.time_);
    }
    inline CCDate operator + (const CCDate &dt) const
    {
		return CCDate(this->time_ + dt.time_);
    }
    inline CCDate operator + (const CCDate &dt)
    {
		return CCDate(this->time_ + dt.time_);
    }
	
    inline bool operator < (const CCDate &dt) const
    {
		return this->time_ < dt.time_;
    }
    inline bool operator < (const CCDate &dt)
    {
		return this->time_ < dt.time_;
    }
    inline bool operator <=(const CCDate &dt) const
    {
		return *this < dt || *this == dt;
    }
    inline bool operator <=(const CCDate &dt)
    {
		return *this < dt || *this == dt;
    }
    inline bool operator ==(const CCDate &dt) const
    {
		return this->time_ == dt.time_;
    }
    inline bool operator ==(const CCDate &dt)
    {
		return this->time_ == dt.time_;
    }
    inline bool operator !=(const CCDate &dt) const
    {
		return this->time_ != dt.time_;
    }
    inline bool operator !=(const CCDate &dt)
    {
		return this->time_ != dt.time_;
    }
	
    inline int year  (void) const { return this->tm_.tm_year + 1900; }
    inline int month (void) const { return this->tm_.tm_mon  + 1; }
    inline int wday  (void) const { return this->tm_.tm_wday ; }
    inline int mday  (void) const { return this->tm_.tm_mday ; }
    inline int hour  (void) const { return this->tm_.tm_hour ; }
    inline int min   (void) const { return this->tm_.tm_min ;  }
    inline int sec   (void) const { return this->tm_.tm_sec ;  }
	
    inline void year(const int nyear)
    {
		this->tm_.tm_year = nyear - 1900;
		this->time_ = ::mktime(&this->tm_);
    }
    inline void month(const int nmon)
    {
		this->tm_.tm_mon = nmon - 1;
		this->time_ = ::mktime(&this->tm_); 
    }
    inline void mday(const int nday)
    {
		this->tm_.tm_mday = nday; 
		this->time_ = ::mktime(&this->tm_); 
    }
    inline void hour(const int nhou)
    {
		this->tm_.tm_hour = nhou;
		this->time_ = ::mktime(&this->tm_); 
    }
    inline void min(const int nmin)
    {
		this->tm_.tm_min  = nmin;
		this->time_ = ::mktime(&this->tm_); 
    }
    inline void sec(const int nsec)
    {
		this->tm_.tm_sec  = nsec; 
		this->time_ = ::mktime(&this->tm_); 
    }
	
    // get time
    inline time_t time(void) const
    {
		return this->time_;
    }
    // get date value. convert string will be "2008-12-12 00:00:00"
    time_t date(void) const
    {
		struct tm stm;
		::localtime_r(&this->time_, &stm);
		stm.tm_hour = stm.tm_min = stm.tm_sec = 0;
		return ::mktime(&stm);
    }
	
    // format date and time to "2008-12-12 23:23:23"
    inline char *to_str(char *str, int len)
    {
		if (len < 20) return str;
		::strftime(str, len, "%Y-%m-%d %H:%M:%S", &this->tm_);
		/*
		 ::sprintf(str, "%04d-%02d-%02d %02d:%02d:%02d",
		 this->tm_.tm_year + 1900, this->tm_.tm_mon + 1, 
		 this->tm_.tm_mday, this->tm_.tm_hour, 
		 this->tm_.tm_min, this->tm_.tm_sec);
		 */
		if (len > 20) // length of "2000-12-12 23:23:23" = 19
			len = 20;
		str[len - 1] = '\0';
		return str;
    }
	
    // format date to "2008-12-12"
    inline char *date_to_str(char *str, int len)
    {
		if (len < 11) return str;
		::strftime(str, len, "%Y-%m-%d", &this->tm_);
		if (len > 11) // length of "2000-12-12" = 10
			len = 11;
		str[len-1] = '\0';
		return str;
    }
	
    // format time to "23:23:23"
    inline char *time_to_str(char *str, int len)
    {
		if (len < 9) return str;
		::strftime(str, len, "%H:%M:%S", &this->tm_);
		if (len > 9) // length of "23:23:23" = 8
			len = 9;
		str[len-1] = '\0';
		return str;
    }
	
    // convert str to datetime. "2008-12-12 23:23:23"
    inline time_t str_to_datetime(const char *str)
    {
		if (str == 0) return 0;
		::memset(&this->tm_, 0, sizeof(this->tm_));
		::strptime(str, "%Y-%m-%d %H:%M:%S", &this->tm_);
		this->time_ = ::mktime(&this->tm_); 
		return this->time_;
    }
    // convert str to datetime. "23:23:23"
    inline time_t str_to_time(const char *str)
    {
		if (str == 0) return 0;
		this->time_ = 0;
		::localtime_r(&this->time_, &this->tm_);
		::strptime(str, "%H:%M:%S", &this->tm_);
		this->time_ = ::mktime(&this->tm_); 
		return this->time_;
    }
    // convert str to datetime. "2008-12-12"
    inline time_t str_to_date(const char *str)
    {
		if (str == 0) return 0;
		::memset(&this->tm_, 0, sizeof(this->tm_));
		::strptime(str, "%Y-%m-%d", &this->tm_);
		this->time_ = ::mktime(&this->tm_); 
		return this->time_;
    }
	
    // get current date and time
    inline time_t update(void)
    {
		this->time_ = ::time(NULL); 
		::localtime_r(&this->time_, &this->tm_); 
		return this->time_;
    }
	
    // set date and time
    inline time_t update(time_t dtime)
    {
		this->time_ = dtime;
		::localtime_r(&this->time_, &this->tm_); 
		return this->time_;
    }
protected:
    time_t    time_;
    struct tm tm_;
};

#endif // _DATE_TIME_H_

