#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <malloc.h>

#define MAX_NAME_LEN 32
#define MAX_EMAIL_LEN 64
#define MAX_PHONE_LEN 15
#define MAX_RECORDS 10000
#define MAX_LENGTH 11

//宏定义
#define CLEAR printf("\e[1;1H\e[2J");//清屏

char username[MAX_LENGTH+1], password[MAX_LENGTH+1];

//全局变量
int index00=1;         //全局变量index00，用于控制MainMenu函数的循环。当用户选择退出时，赋值0，终止循环，结束程序。
char username[MAX_LENGTH+1], password[MAX_LENGTH+1];

typedef struct _TimeIngo
{
    int year;
    int month;
    int daym;
    int dayw;
    int hour;
    int min;
    int sec;
}TimeInfo;

typedef struct _ManagerInfo
{
    char id[15];
    char password[20];
    char name[20];
    int gender;
    char mail[15];
    char tel[15];
    int permi[15];
    int type;
}ManagerInfo;

typedef struct _UserInfo
{
    char id[15];
    char password[20];
    char name[32];
    int gender; //未知为0，男1女2
    int age;
    char mail[64];
    char tel[15];
    int address;
    int timez;
    double val;
}UserInfo;

typedef struct _FieldInfo
{
    char name[32];       //场馆名称
    int ICcode1;
    int ICcode2;
    int EntranceAge;     //准入年龄
    int MaxNum;          //最大人数
    int Area;
    double prize;      //价格
    int currentNum;
    int ifprint;      //0打印，1不打印
    int order;
}FieldInfo;

typedef struct _PlaceInfp
{
    char name[32];       
    int ICcode1;          //场馆编号
    int num;
    FieldInfo field[5];
}PlaceInfo;
//场馆编号  下设场地数量 
//场地编号  场地名称   准入年龄  最大人数  区域编号 价格 


typedef struct _ReservationInfo
{
    UserInfo client;
    PlaceInfo place;
    FieldInfo field;
    int duration;
    TimeInfo ExpTime;
    TimeInfo RsvTime;
    char code[128];
}RsvInfo;

UserInfo YOU;

//用户id  场馆编号  场地编号  时常  预约日期年月日时  下单时间年月日时分秒
