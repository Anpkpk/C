#include <stdio.h>

int dayOfWeek(int day, int month, int year){
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12*a - 2;
    int d = (day + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;
    return d;
}
int main(){
    int day, month, year;
    scanf("%d%d%d", &day, &month, &year);
    int days = dayOfWeek(day, month, year);
    switch (days)
    {
    case 0:
        printf("SUNDAY");
        break;
    case 1:
        printf("MONDAY");
        break;
    case 2:
        printf("TUESDAY");
        break;
    case 3:
        printf("WEDNESDAY");
        break;
    case 4:
        printf("THURDAY");
        break;
    case 5:
        printf("FRIDAY");
        break;
    case 6:
        printf("SATURDAY");
        break;
    default:
    printf("ERROR!");
        break;
    }
}