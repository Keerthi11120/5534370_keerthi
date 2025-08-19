#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isLeap(int y) {
    if (y % 400 == 0) return 1;
    if (y % 100 == 0) return 0;
    return (y % 4 == 0);
}

int daysInMonth(int m, int y) {
    int mdays[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2) return mdays[2] + (isLeap(y) ? 1 : 0);
    return mdays[m];
}

void nextDate(int *d, int *m, int *y) {
    (*d)++;
    if (*d > daysInMonth(*m, *y)) {
        *d = 1;
        (*m)++;
        if (*m > 12) {
            *m = 1;
            (*y)++;
        }
    }
}

int sameDate(int d1, int m1, int y1, int d2, int m2, int y2) {
    return (d1 == d2 && m1 == m2 && y1 == y2);
}

int isLucky(int d, int m, int y) {
    long long num = d;
    num = num * 100 + m;
    num = num * 10000 + y;
    return (num % 4 == 0) || (num % 7 == 0);
}

int main() {
    char s1[11], s2[11];
    scanf("%s %s", s1, s2);

    int d1 = (s1[0]-'0')*10 + (s1[1]-'0');
    int m1 = (s1[3]-'0')*10 + (s1[4]-'0');
    int y1 = (s1[6]-'0')*1000 + (s1[7]-'0')*100 + (s1[8]-'0')*10 + (s1[9]-'0');

    int d2 = (s2[0]-'0')*10 + (s2[1]-'0');
    int m2 = (s2[3]-'0')*10 + (s2[4]-'0');
    int y2 = (s2[6]-'0')*1000 + (s2[7]-'0')*100 + (s2[8]-'0')*10 + (s2[9]-'0');

    int cnt = 0;
    while (1) {
        if (isLucky(d1,m1,y1)) cnt++;
        if (sameDate(d1,m1,y1,d2,m2,y2)) break;
        nextDate(&d1,&m1,&y1);
    }

    printf("%d\n", cnt);
    return 0;
}
