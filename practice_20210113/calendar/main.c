#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "common.h"

// マネージャ
int manager_calendar(int argc, CalParameter *cal_display_data_p);

// パラメータチェック
int check_parameters(int argc, CalParameter *cal_display_data_p);

// カレンダー計算
int calculate_calendar(CalParameter* cal_display_data_p, int* nMonth_p, CalMonth* month_data_p);

// うるう年判定
int check_leap_year(int year);

// カレンダー表示
// int view_calendar(CalMonth *month_data_p, int *nMonth_p);



// char* itoa(int val, int base);

// 計算
// int calculate_calendar(
//     CalParameter* cal_display_data_p,
//     int* nMonth_p,
//     CalMonth* month_data_p
// );

int main(int argc, char *argv[]){


    if(argc<=1 || 5<=argc){
        printf("エラー1 \n usage: MyCal year [month[num]] \n 1〜3このパラメータを指定してください\n");
        exit(EXIT_FAILURE);
    }

    int year,month,num;

    year = atoi(argv[1]);

    if(argv[2] != NULL){
        month = atoi(argv[2]);
    }

    if(argv[3] != NULL){
        num = atoi(argv[3]);
    }

    printf("年%d\n",year);
    printf("月%d\n",month);
    printf("月の個数%d\n",num);

    CalParameter cal_display_data;
    CalParameter *cal_display_data_p;
    cal_display_data_p = &cal_display_data;

    cal_display_data_p->year = year;
    cal_display_data_p->month = month;
    cal_display_data_p->num = num;

    

    manager_calendar(argc,cal_display_data_p);

}


int manager_calendar(int argc, CalParameter *cal_display_data_p){

    check_parameters(argc, cal_display_data_p);


    CalMonth month_data[12];
    CalMonth *month_data_p;
    month_data_p = month_data;

    int nMonth;
    int *nMonth_p;
    nMonth_p = &nMonth;
    

    if(argc==2){
        nMonth = 12;
    }else if(argc==3){
        nMonth = 1;
    }else if(argc==4){
        nMonth = cal_display_data_p->num;
    }

    calculate_calendar(cal_display_data_p, nMonth_p, month_data_p);

    // month_data_p ->start_wday = 5;
    // month_data_p ->ndays = 31;
    // month_data_p ->year = 2020;
    // month_data_p ->month = 1;
    

    // view_calendar(month_data_p, nMonth_p);
    return 0;
}


int check_parameters(int argc,CalParameter *cal_display_data_p){

    int year, month, num;

    year = cal_display_data_p->year;
    month = cal_display_data_p->month;
    num = cal_display_data_p->num;

    if(year <= 1999 || 10000 <= year){
        printf("エラー2\n usage: MyCal year [month[num]] \n yearは2000-9999で指定してください\n");
        exit(EXIT_FAILURE);
    }
    if(3 <= argc && month <= 0 || 13 <= month){
        printf("エラー3\n usage: MyCal year [month[num]] \n monthは1-12で指定してください\n");
        exit(EXIT_FAILURE);
    }
    if(4 <= argc && num <= 0 || 13 <= num){
        printf("エラー4\n usage: MyCal year [month[num]] \n numは1-12で指定してください\n");
        exit(EXIT_FAILURE);

    }


    return 0;

}



int calculate_calendar(CalParameter* cal_display_data_p, int* nMonth_p, CalMonth* month_data_p){

    int start_wday,ndays,year,month;
    int sum_days_from_1996 = 0;

    int month_days_data[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int month_days_data_leap[12]={31,29,31,30,31,30,31,31,30,31,30,31};

    int sum_years_from_1996;
    sum_years_from_1996 = cal_display_data_p->year - 1996;

    int current_year=1996;
    for(int i=0; i<sum_years_from_1996; i++){
        if(check_leap_year(current_year) == 0){
            sum_days_from_1996 = sum_days_from_1996 + 365;
        }else if(check_leap_year(current_year)==1){
            sum_days_from_1996 = sum_days_from_1996 + 366;
        }
        current_year = current_year + 1;
    }

    int sum_months_from_Jan;
    sum_months_from_Jan = cal_display_data_p->month-1;

    int whether_leap_year;

    whether_leap_year = check_leap_year(cal_display_data_p->year);
    if(whether_leap_year==0){
        for(int i=0; i<sum_months_from_Jan; i++){
            sum_days_from_1996 = sum_days_from_1996 + month_days_data[i];
        }
    }else if(whether_leap_year == 1){
        for(int i=0; i<sum_months_from_Jan; i++){
            sum_days_from_1996 = sum_days_from_1996 + month_days_data_leap[i];
        }
    }

    month_data_p->start_wday = (sum_days_from_1996 + 1)%7;

    whether_leap_year = check_leap_year(cal_display_data_p->year);
    if(whether_leap_year == 0){
        month_data_p->ndays = month_days_data[cal_display_data_p->month-1];
    }else if(whether_leap_year==1){
        month_data_p->ndays = month_days_data_leap[cal_display_data_p->month-1];
        
    }
    month_data_p->year = cal_display_data_p->year;
    month_data_p->month = cal_display_data_p->month;

    printf("曜日：%d\n",month_data_p->start_wday);
    printf("日数：%d\n",month_data_p->ndays);
    printf("年：%d\n",month_data_p->year);
    printf("月：%d\n",month_data_p->month);



    return 1;
}



int check_leap_year(int year){
    if(year%400 == 0){
        return 1;
    }
    else if(year%4 == 0 && year%100 != 0){
        return 1;
    }
    return 0;
}


// int view_all_calendar(CalMonth *month_data_p, int *nMonth_p, int argc){
//     printf("月の個数：%d\n",*nMonth_p);
//     int nMonth;
//     nMonth = *nMonth_p;

//     // 一年間分表示
//     if(argc==2){
//         for(int i=0; i<12; i++){
//         }

//     }
//     // 一ヶ月分表示
//     else if(argc==3){

//     }
//     // 指定された月の数だけ表示
//     else if(argc==4){

//     }


// }


// int view_calendar(CalMonth *month_data_p){
//     int start_wday,ndays,year,month;
//     // char moji[25];
//     int a[6][7]={0};
//     start_wday = month_data_p -> start_wday;
//     ndays = month_data_p -> ndays;
//     year = month_data_p -> year;
//     month = month_data_p -> month;


//     int current_day=1;
//     for(int i=0; i<6 ; i++){
//         if(i==0){
//             for(int j=start_wday; j<7; j++){
//                 a[i][j] = current_day;
//                 current_day=current_day +1;
//             }
//         }
//         else{
//             for(int j=0; j<7;j++){
//                 if( ndays < current_day ){
//                     break;
//                 }
//                 a[i][j] = current_day;
//                 current_day=current_day +1;
//             }
//         }
//     }



//     for(int i=0; i<6 ; i++){
//         printf("%2d %2d %2d %2d %2d %2d %2d\n", a[i][0],a[i][1],a[i][2],a[i][3],a[i][4],a[i][5],a[i][6]);
    
//     }

//     return 0;
// }

