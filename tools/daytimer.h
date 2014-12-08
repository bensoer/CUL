#ifndef _TIME_H_
#define _TIME_H_

#include <string>
#include <sstream>
#include <iostream>

using namespace std;


/**
* DayTimer keeps track of time during a single day. Returns time in 24 and 12 hour time, determines AM and PM postfix.
* By default DayTimer assumes it is midnight when it it initialized unless specified otherwise. DayTimer counts the time
* in units of seconds. DayTimer can increment/decrement in Hours and Minutes
*
* DayTimer also has simple overloads of the ++ -- and << operators. ++/-- both change the time by 1 minute. The <<
* operator outputs the data in 12 hour format by default
*
* Midnight = 00:00am
* Mid-day = 12:00pm
*
* After 11:59pm DayTimer will wrap around to 00:00am for Midnight
*/
class DayTimer{

public:
    DayTimer(int timeInSeconds){
        this->timeInSeconds = timeInSeconds;
    }
    DayTimer()
    {
        this->timeInSeconds = 0;
    }

    void SetInsertionTimeFormat(bool TwentyFourHourFormat){
        this->TwentyForHourFormat = TwentyFourHourFormat;
    }

    void IncrementMinute(){
        this->timeInSeconds += (60);
        this->ValidateTime();
    }
    void SetMinute(const int minutes){
        this->timeInSeconds = (minutes * 60);
    }

    void IncrementSecond(){
        this->timeInSeconds += 1;
        this->ValidateTime();
    }
    void IncrementHour(){
        this->timeInSeconds += (60*60); //60 seconds in 60 minutes = 1 hr
        this->ValidateTime();
    }
    void SetHour(const int hours){
        this->timeInSeconds = (hours * 60 * 60);
    }


    int GetRawTime(){
        return this->timeInSeconds;
    }

    string Get24HourTime(){
        int hours = this->timeInSeconds / 60*60;
        int totalMinutes = this->timeInSeconds / 60;
        int minutes = totalMinutes - (hours*60);

        return this->FormatData(hours, minutes, true);
        /*stringstream ss;
        ss << hours << ":" << minutes;
        return ss.str();*/
    }
    string Get12HourTime(){
        int hours = this->timeInSeconds / (60*60);
        int totalMinutes = this->timeInSeconds / 60;
        int minutes = totalMinutes - (hours*60);

        return this->FormatData(hours, minutes, false);
    }

    /* ----OVERLOADS---- */

    DayTimer & operator++(){ //prefix
        this->IncrementMinute();
        this->ValidateTime();
        return *this;
    }
    DayTimer & operator--(){ //prefix
        this->timeInSeconds -= (60);
        this->ValidateTime();
        return *this;

    }
    DayTimer operator++(int){ //postfix
        DayTimer temp(*this);
        ++(*this);
        return temp;
    }
    DayTimer operator--(int){ //postfix
        DayTimer temp(*this);
        --(*this);
        return temp;
    }

    friend ostream & operator<<(ostream & os, DayTimer & dt){
        if(dt.TwentyFourHourFormat){
            os << dt.Get24HourTime();
        }else{
            os << dt.Get12HourTime();
        }

        return os;
    }



private:
    int timeInSeconds;
    const int LastSecondOfDay = 86280;
    bool TwentyFourHourFormat = false;

    void ValidateTime(){
        if(this->timeInSeconds > this->LastSecondOfDay){
            this->timeInSeconds = 0 ;
        }
    }

    string FormatData(int hours, int minutes, bool is24){
        stringstream ss;
        bool isAfternoon = false;

        if(!is24 && hours > 12){
            hours -= 12;
            isAfternoon = true;
        }


        if(hours == 0)
        {
            ss << "00";
        }else if(hours < 10)
        {
            ss << "0" << hours;
        }else{
            ss << hours;
        }

        ss << ":";

        if(minutes == 0)
        {
            ss << "00";
        }else if(minutes < 10)
        {
            ss << "0" << minutes;
        }else{
            ss << minutes;
        }

        if(!is24){
            if(isAfternoon){
                ss << "pm";
            }else{
                ss << "am";
            }
        }

        return ss.str();
    }

};

#endif