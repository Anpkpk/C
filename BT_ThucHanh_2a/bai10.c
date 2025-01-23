#include<stdio.h>

// Kiem tra nam nhuan
int isLeapYear(int year){
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        return 1;
    } else return 0;
}
// So ngay trong thang
int daysInMonth(int month, int year){
    switch (month)
    {
    case 4: case 6: case 9: case 11:
        return 30;
        break;
    case 2:
        return (isLeapYear(year) ? 29 : 28);
        break;
    default:
        return 31;
        break;
    }
}
// So ngay tu dau nam den ngay
int daysToMonth(int month, int year){
    int days = 0;
    for (int i = 1; i < month; ++i){
        days += daysInMonth(i, year);
    }
    return days;
}
//So ngay giua hai khoang thoi gian
int daysBetween(int day1, int month1, int year1, int day2, int month2, int year2){
    int days = 0;
    for (int i = year1; i < year2; ++i){
        days += isLeapYear(i) ? 366 : 365;
    }
    days -= daysToMonth(month1, year1) + day1;
    days += daysToMonth(month2, year2) + day2;
    return days;
}

int main(){
    int day1, day2, month1, month2, year1, year2;
    scanf("%d%d%d%d%d%d", &day1, &month1, &year1, &day2, &month2, &year2);
    int days;
    days = daysBetween(day1, month1, year1, day2, month2, year2);
    printf("%d", days);
}