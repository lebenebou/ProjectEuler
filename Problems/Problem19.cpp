
#include <iostream>
#include <map>
using namespace std;

const bool is_leap(const short& year){

    bool answer = false;

    if(year%4==0){

        if(year%100==0 && year%400!=0) return false;
        return true;
    }
    return false;
}

int main(){

    short week_day = 1;
    short month_day = 1;
    short month = 1;
    short year = 1900;
    map<short, short> month_days;

    month_days[1] = 31; month_days[3] = 31; month_days[4] = 31; month_days[5] = 31; month_days[7] = 31; month_days[8] = 31; month_days[10] = 31; month_days[12] = 31;
    month_days[9] = 30; month_days[6] = 30; month_days[11] = 30;
    month_days[2] = 28;

    unsigned short answer = 0;

    while(year < 2001){

        if(week_day==7 && month_day==1){
            
            cout << "Sunday " << month_day << "/" << month << "/" << year << endl;
            answer++;
        }

        if(week_day<7){
            week_day++;
        } else {
            week_day = 1;
        }

        if(month_day < (month==2 && is_leap(year) ? 29:month_days[month])){
            month_day++;
        } else {
            month_day = 1;
            
            if(month<12){
                month++;
            } else {
                month = 1;
                year++;
            }
        }
    }

    cout << answer << endl;

    return 0;
}