#include "Basic.h"
    typedef struct
 {
    int math;
    char name[15];
    int people; 
    int number1;
    int number;
    double val;
  }field;

typedef struct _Record{
    char name[50];
    int place1;
    int place2;
    int duration;
    int year;
    int month;
    int day;
    int hour;
    char myear[400];
}Record;
struct Record{
    char name[50];
    int place1;
    int place2;
    int duration;
    int year;
    int month;
    int day;
    int hour;
    char myear[400];
};
int check_username(char *username)           //函数功能：传入需要检查的用户名，若符合，返回1；不符合，返回0
{
    int len = strlen(username);
    if(len > MAX_LENGTH || len < 6)
        return 0; //用户名小于6位，大于11位
    for(int i = 0; i < len; i++)
    {
        if(!isalpha(username[i]) && !isdigit(username[i]))
            return 0; //用户名存在汉字或者特殊符号
    }
    return 1; 
}
int check_string(char *string)          //函数功能：传入需要检查的密码，若符合，返回1；不符合，返回0
{
    int len = strlen(string);
    if(len > 31)
        return 0; 
    for(int i = 0; i < len; i++)
    {
        if(!isalpha(string[i]) && !isdigit(string[i]))
            return 0; //密码之中不存在汉字或者特殊符号
    }
    return 1; 
}


void change1()


{
     typedef struct
 {
    int math;
    char name[15];
    int people; 
    int area;
    int number;
    double val;
  }field;
typedef struct 
  {
    int name; 
    int number;
   }place;
    
    field *u;
    u = (field*)malloc(100*sizeof(field));
    int num_records = 0;
    FILE* fp = fopen("Test_Field101", "r");
    if (fp == NULL) {
        printf("1");
        printf("无法打开Test_FieldInfo101\n");
        return ;
    }

    // 读取文件内容
    while (fscanf(fp, "%d %s %d %d %d %lf", &u[num_records].math, u[num_records].name, &u[num_records].people, &u[num_records].number,&u[num_records].area,&u[num_records].val) != EOF) 
    {
        num_records++;
    }
    free(u);
    fclose(fp);

    place *c;
    c = (place*)malloc(100*sizeof(place));
    int num_record = 0;
    FILE* fa = fopen("Test_Place01", "r");
    if (fa == NULL)
     {
        printf("无法打开Test_Place101\n");
        return ;
    }
    // 读取文件内容
    while (fscanf(fa, "%d %d", &c[num_record].name, &c[num_record].number) != EOF) {
        num_record++;
    }

c[0].number = num_records;
     fa = fopen("Test_Place01", "w");
    if (fp == NULL) {
        printf("未找到文件Test_Place01\n");
        return;
    }
    for (int i = 0; i < num_record; i++) {
         fprintf(fa,"%d %d\n", c[i].name, c[i].number);
    }
    free(c);
    fclose(fa);

    printf("修改成功.\n");

}
void change2()
{
      typedef struct
 {
    int math;
    char name[15];
    int people; 
    int number;
    int area;
    double val;
  }field;
typedef struct 
  {
    int name; 
    int number;
   }place;
    
    field *u;
    u = (field*)malloc(100*sizeof(field));
    int num_records = 0;
    FILE* fp = fopen("Test_Field201", "a+");
    if (fp == NULL) {
        printf("1");
        printf("无法打开Test_Field201\n");
        return ;
    }

    // 读取文件内容
    while (fscanf(fp, "%d %s %d %d %d %lf", &u[num_records].math, u[num_records].name, &u[num_records].people, &u[num_records].number,&u[num_records].area,&u[num_records].val) != EOF) 
    {
        num_records++;
    }
    free(u);
    fclose(fp);

    place *c;
    c = (place*)malloc(100*sizeof(place));
    int num_record = 0;
    FILE* fa = fopen("Test_Place01", "r");
    if (fa == NULL)
     {
        printf("无法打开Test_Place01\n");
        return ;
    }
    // 读取文件内容
    while (fscanf(fa, "%d %d", &c[num_record].name, &c[num_record].number) != EOF) {
        num_record++;
    }

c[1].number = num_records;
     fa = fopen("Test_Place01", "w");
    if (fp == NULL) {
        printf("未找到文件Test_Place01\n");
        return ;
    }
    for (int i = 0; i < num_record; i++) {
         fprintf(fa,"%d %d\n", c[i].name, c[i].number);
    }
    free(c);
    fclose(fa);

    printf("修改成功.\n");
    return;
}
void change3()
{
      typedef struct
 {
    int math;
    char name[15];
    int people; 
    int number;
    int area;
    double val;
  }field;
typedef struct 
  {
    int name; 
    int number;
   }place;
    
    field *u;
    u = (field*)malloc(100*sizeof(field));
    int num_records = 0;
    FILE* fp = fopen("Test_Field301", "a+");
    if (fp == NULL) {
        printf("1");
        printf("无法打开Test_Field301\n");
        return ;
    }

    // 读取文件内容
    while (fscanf(fp, "%d %s %d %d %d %lf", &u[num_records].math, u[num_records].name, &u[num_records].people, &u[num_records].number,&u[num_records].area,&u[num_records].val) != EOF) 
    {
        num_records++;
    }
    free(u);
    fclose(fp);

    place *c;
    c = (place*)malloc(100*sizeof(place));
    int num_record = 0;
    FILE* fa = fopen("Test_Place01", "r");
    if (fa == NULL)
     {
        printf("无法打开Test_Place01\n");
        return ;
    }
    // 读取文件内容
    while (fscanf(fa, "%d %d", &c[num_record].name, &c[num_record].number) != EOF) {
        num_record++;
    }

c[2].number = num_records;
     fa = fopen("Test_Place01", "w");
    if (fp == NULL) {
        printf("未找到文件Test_Place01\n");
        return ;
    }
    for (int i = 0; i < num_record; i++) {
         fprintf(fa,"%d %d\n", c[i].name, c[i].number);
    }
    free(c);
    fclose(fa);

    printf("修改成功.\n");
    return;
}

void Userchangeinfo() 
{
    FILE* fp;
    UserInfo *u;
    UserInfo test;
    u = (UserInfo*)malloc(MAX_RECORDS*sizeof(UserInfo));
    char str[2], STR[2];
    int iat, idot, count, index01, index03, index06=0;
    int num_records = 0;
    char search_name[MAX_NAME_LEN];
    
    strcpy(search_name, YOU.id);
    
    fp = fopen("Test_UserInfo05", "r");
    if (fp == NULL) 
    {
        printf("无法打开 %s\n", "Test_UserInfo05");
        exit(1);
    }

    // 读取文件内容
    while (fscanf(fp, "%s %s %s %d %d %s %s %d %d %.2lf", u[num_records].id, u[num_records].password, u[num_records].name, &u[num_records].gender,&u[num_records].age,u[num_records].mail,u[num_records].tel, &u[num_records].address,&u[num_records].timez, &u[num_records].val) != EOF)
        num_records++;
    
    fclose(fp);

    
    // 寻找匹配的用户名
    int index = -1;
    for (int i = 0; i <= num_records; i++)
    {
        if (strcmp(u[i].id, search_name) == 0)
        {
            index = i;
            break;
        }
    }
    if(index==-1)
    {
        printf("error!");
        exit(1);
    }

    CLEAR
    printf("******您正在修改个人信息******\n\n提示: 请输入数字1~9\n");
    printf("您当前的可修改类信息如下:\n");
    printf("用户名: %s\n", u[index].id);
    printf("密码: %s\n", u[index].password);
    printf("姓名: %s\n", u[index].name);
    if(u[index].gender==1)
        printf("性别: 男\n");
    if (u[index].gender==2)
        printf("性别：女\n");
    printf("年龄: %d\n", u[index].age);
    printf("邮箱: %s\n", u[index].mail);
    printf("电话: %s\n", u[index].tel);
    printf("地址: ");
    if(u[index].address==1)
        printf("海淀区\n");
    if(u[index].address==2)
        printf("丰台区\n");
    if(u[index].address==3)
        printf("西城区\n");
    if(u[index].address==4)
        printf("其它\n");
    printf("请选择您要修改的信息\n(1.用户名, 2.密码, 3.姓名, 4.性别, 5.年龄, 6.邮箱, 7.电话, 8.地址, 9.退出当前界面): ");
    while(1)
    {
        label5:
        fflush(stdin);   //有时scanf会扫描进换行符，因此我们倾向于“滥用”fflush()函数以清空缓冲区
        scanf("%s",str);
        fflush(stdin);
        while(1)
        {
            if(str[1]=='\000')
                break;
            CLEAR
            printf("******您正在修改个人信息******\n\n提示: 输入有误, 请输入数字1~9\n");
            printf("您当前的可修改类信息如下:\n");
            printf("用户名: %s\n", u[index].id);
            printf("密码: %s\n", u[index].password);
            printf("姓名: %s\n", u[index].name);
            if(u[index].gender==1)
                printf("性别: 男\n");
            if (u[index].gender==2)
                printf("性别：女\n");
            printf("年龄: %d\n", u[index].age);
            printf("邮箱: %s\n", u[index].mail);
            printf("电话: %s\n", u[index].tel);
            printf("地址: ");
            if(u[index].address==1)
                printf("海淀区\n");
            if(u[index].address==2)
                printf("丰台区\n");
            if(u[index].address==3)
                printf("西城区\n");
            if(u[index].address==4)
                printf("其它\n");
            printf("请选择您要修改的信息\n(1.用户名, 2.密码, 3.姓名, 4.性别, 5.年龄, 6.邮箱, 7.电话, 8.地址, 9.退出当前界面): ");
            
            str[1]='\000';
            fflush(stdin);
            scanf("%s",str);
            fflush(stdin);
        }
        switch (str[0])
        {

        case '1':
            CLEAR
            printf("******您正在修改个人信息******\n\n提示: 您正在修改您的用户名\n");
            printf("请输入修改后的用户名: ");
            while(1)
            {
                index06=0;
                for(int i=0; i<15; i++)
                    u[index].id[i]='\000';
                scanf("%s",u[index].id);
                fflush(stdin);
                fp=fopen("Test_UserInfo05","r");
                while(fscanf(fp, "%s %s %s %d %d %s %s %d %d %lf",test.id, test.password, test.name, &test.gender, &test.age, test.mail, test.tel, &test.address, &test.timez, &test.val)!=EOF)
                {
                    if(strcmp(u[index].id, test.id)==0 && strcmp(u[index].id, YOU.id)!=0)
                    {
                        index06++;
                        break;
                    }
                }
                if(index06!=0)
                {
                    CLEAR
                    printf("******您正在修改个人信息******\n\n提示: 该用户名已被注册, 请重新输入\n");
                    printf("请输入修改后的密码: ");
                    continue;
                }
                if(check_username(u[index].id))//检查密码格式是否合规，若合规，跳出当前循环。否则要求用户重新输入密码。
                    break;
                CLEAR
                printf("******您正在修改个人信息******\n\n提示: 输入有误, 用户名包含特殊字符或长度有误, 请输入6~11位数字和字母\n");
                printf("请输入修改后的密码: ");
                
            }
            break;

        case '2':
            CLEAR
            printf("******您正在修改个人信息******\n\n提示: 您正在修改您的密码\n");
            printf("请输入修改后的密码: ");
            while(1)
            {
                for(int i=0; i<20; i++)
                    u[index].password[i]='\000';
                scanf("%s",u[index].password);
                fflush(stdin);
                if(check_string(u[index].password))//检查密码格式是否合规，若合规，跳出当前循环。否则要求用户重新输入密码。
                    break;
                CLEAR
                printf("******您正在修改个人信息******\n\n提示: 密码包含特殊字符或密码太长, 请重新输入\n");
                printf("请输入修改后的密码: ");
            }
            printf("修改成功\n");
            printf("\n(按任意键继续)\n");
            fflush(stdin);
            getch();
            CLEAR
            printf("密码是登陆账户的唯一凭证, 请您再次核对您当前的密码:\n");
            printf("%s\n", u[index].password);
            break;

        case '3':
            CLEAR
            printf("******您正在修改个人信息******\n\n提示: 您正在修改您的姓名\n");
            printf("请输入修改后的姓名: ");
            while(1)
            {
                for(int i=0;i<32;i++)
                    u[index].name[i]='\000';
                scanf("%s", u[index].name);
                if(check_string(u[index].name))//检查姓名是否合规
                    break;
                CLEAR
                printf("******您正在修改个人信息******\n\n提示: 您输入的姓名包含特殊字符或姓名太长, 请重新输入!\n");
                printf("请输入修改后的姓名: ");
            }
                break;

        case '4':
            index01=1;
            CLEAR
            printf("******您正在修改个人信息******\n\n提示: 您正在修改您的性别\n");
            printf("请输入修改后的性别(1.男, 2.女): ");
            while(index01)
            {
                while(1)
                {
                    STR[1]='\000';
                    scanf("%s",STR);
                    fflush(stdin);
                    if(STR[1]=='\000')
                        break;
                    CLEAR
                    printf("******您正在修改个人信息******\n\n提示: 输入有误, 请输入数字1或2\n");
                    printf("请输入修改后的性别(1.男, 2.女): ");
                    STR[1]='\000';
                }

                switch (STR[0])
                {
                case '1':
                    u[index].gender=1;//我们用整型储存性别信息。男1女2。
                    index01=0;
                    break;

                case '2':
                    u[index].gender=2;
                    index01=0;
                    break;

                default:
                    CLEAR
                    printf("请输入您的性别(1.男, 2.女): ");
                    break;
                }
            }
            break;

        case '5':
            CLEAR
            printf("******您正在修改个人信息******\n\n提示: 您正在修改您的年龄\n");
            printf("请输入修改后的年龄: ");
            while(1)
            {
                scanf("%d",&u[index].age);
                fflush(stdin);
                if(1<u[index].age && u[index].age<101)//年龄必须在
                    break;
                CLEAR
                printf("******您正在修改个人信息******\n\n提示: 输入有误, 请输入1~100\n");
                printf("请输入修改后的年龄: ");
            }
            break;

        case '6':
            CLEAR
            printf("******您正在修改个人信息******\n\n提示: 您正在修改您的邮箱\n");
            printf("请输入修改后的邮箱: ");
            while(1)
            {
                for(int i=0;i<64;i++)//清空u.mail[]
                    u[index].mail[i]='\000';
                scanf("%s",u[index].mail);
                fflush(stdin);
                if(u[index].mail[63]!='\000')//说明邮箱太长了
                {
                    CLEAR
                    printf("******您正在修改个人信息******\n\n提示: 您的邮箱太长啦, 请换一个邮箱号\n");
                    printf("请输入修改后的邮箱: ");
                    continue;
                }
                iat=0;
                idot=0;
                count=0;
                for(int i=0; i<64; i++)
                {
                    if(u[index].mail[i]=='@')
                    {
                        iat=i;
                        count++;
                    }
                }
                for(int i=0; i<64; i++)
                {
                    if(u[index].mail[i]=='.')
                    {
                        idot=i;
                        count++;
                    }
                }
                if(count==2 && idot!=0 && (iat+1)<idot && iat!=0 && u[index].mail[iat+1]!='\000')
                    break;
                CLEAR
                printf("******您正在修改个人信息******\n\n提示: 您的邮箱太长啦, 请换一个邮箱号\n");
                printf("请输入修改后的邮箱: ");
                continue;
            }
            break;
        
        case '7':
            CLEAR
            printf("******您正在修改个人信息******\n\n提示: 您正在修改您的电话号码\n");
            printf("请输入修改后的电话号码: ");
            while(1)
            {
                for(int i=0; i<15; i++)
                    u[index].tel[i]='\000';
                scanf("%s", u[index].tel);
                fflush(stdin);
                index03=0;
                for(int i=0;i<11;i++)
                {
                    if(u[index].tel[i]>57 || u[index].tel[i]<48)
                        index03++;
                }
                if(YOU.tel[11]=='\000' && index03==0)
                    break;
                CLEAR
                printf("******您正在修改个人信息******\n\n提示: 请输入11位数字\n");
                printf("请输入修改后的电话号码: ");
            }
            break;

        case '8':

            index01=1;
            printf("******您正在修改个人信息******\n\n提示: 您正在修改您的地址\n");
            printf("请输入修改后的地址:\n");
            printf("1.海淀区  2.丰台区  3.西城区  4.其他  ");
            while(index01)
            {
        
                while(1)
                {
                    str[0]='\000';
                    str[1]='\000';
                    scanf("%s",str);
                    fflush(stdin);
                    if(str[1]=='\000')
                        break;
                    CLEAR
                    printf("1.海淀区  2.丰台区  3.西城区  4.其他  ");
                    str[1]='\000';
                }

                switch (str[0])
                {
                case '1':
                    u[index].address=1;
                    index01=0;
                    break;

                case '2':
                    u[index].address=2;
                    index01=0;
                    break;

                case '3':
                    u[index].address=3;
                    index01=0;
                    break;

                case '4':
                    u[index].address=4;
                    index01=0;
                    break;

                default:
                    CLEAR
                    printf("1.海淀区  2.丰台区  3.西城区  4.其他  ");
                    break;
                }
            }

        case '9':
            CLEAR
            printf("以下是您当前的个人信息:\n");
            printf("用户名: %s\n", u[index].id);
            printf("密码: %s\n", u[index].password);
            printf("姓名: %s\n", u[index].name);
            if(u[index].gender==1)
                printf("性别: 男\n");
            if (u[index].gender==0)
                printf("性别：女\n");
            printf("年龄: %d\n", u[index].age);
            printf("邮箱: %s\n", u[index].mail);
            printf("电话: %s\n", u[index].tel);
            printf("地址: ");
            if(u[index].address==1)
                printf("海淀区\n");
            if(u[index].address==2)
                printf("丰台区\n");
            if(u[index].address==3)
                printf("西城区\n");
            if(u[index].address==4)
                printf("其它\n");
            printf("\n按任意键继续\n");
            fflush(stdin);
            getch();
            CLEAR
            printf("您可以随时再来修改个人信息, 按任意键返回用户菜单");

             //重新写入
            fp = fopen("Test_UserInfo05", "w+");
            if (fp == NULL)
            {
                printf("未找到文件 %s\n", "Test_UserInfo05");
                exit(1);
            }
            for (int i = 0; i < num_records; i++)
                fprintf(fp, "%s %s %s %d %d %s %s %d %d %.2lf\n", u[i].id, u[i].password, u[i].name, u[i].gender, u[i].age, u[i].mail, u[i].tel, u[i].address, u[i].timez, u[i].val);
            YOU=u[index];
            free (u);
            fclose(fp);

            CLEAR
            printf("尊敬的 %s ",YOU.name);
            if(YOU.gender==1)
                printf("先生");
            if(YOU.gender==2)
                printf("女士");
            printf(", 您已登陆账户 %s \n\n提示: ", YOU.id);
            printf("请输入数字0~6\n");
            printf("0.退出登陆\n");
            printf("1.查看个人信息\n");
            printf("2.修改个人信息\n");
            printf("3.查询场馆信息: 精准查找单个场馆\n");
            printf("4.查询场馆信息: 对比所有场馆预约信息\n");
            printf("5.场馆预约\n");
            printf("6.余额查询/充值\n");
            fflush(stdin);   //有时scanf会扫描进换行符，因此我们倾向于“滥用”fflush()函数以清空缓冲区
            return;

        default:
            CLEAR
            printf("******您正在修改个人信息******\n\n提示: 输入有误, 请输入数字1~9\n");
            printf("您当前的可修改类信息如下:\n");
            printf("用户名: %s\n", u[index].id);
            printf("密码: %s\n", u[index].password);
            printf("姓名: %s\n", u[index].name);
            if(u[index].gender==1)
                printf("性别: 男\n");
            if (u[index].gender==2)
                printf("性别：女\n");
            printf("年龄: %d\n", u[index].age);
            printf("邮箱: %s\n", u[index].mail);
            printf("电话: %s\n", u[index].tel);
            printf("地址: ");
            if(u[index].address==1)
                printf("海淀区\n");
            if(u[index].address==2)
                printf("丰台区\n");
            if(u[index].address==3)
                printf("西城区\n");
            if(u[index].address==4)
                printf("其它\n");
            printf("请选择您要修改的信息\n(1.用户名, 2.密码, 3.姓名, 4.性别, 5.年龄, 6.邮箱, 7.电话, 8.地址, 9.退出当前界面): ");
            goto label5;
            break;
        }
        printf("\n(按任意键继续)\n");
        fflush(stdin);
        getch();
        CLEAR
        printf("******您正在修改个人信息******\n\n提示: 请输入数字1~9\n");
        printf("您当前的可修改类信息如下:\n");
        printf("用户名: %s\n", u[index].id);
        printf("密码: %s\n", u[index].password);
        printf("姓名: %s\n", u[index].name);
        if(u[index].gender==1)
            printf("性别: 男\n");
        if (u[index].gender==2)
            printf("性别：女\n");
        printf("年龄: %d\n", u[index].age);
        printf("邮箱: %s\n", u[index].mail);
        printf("电话: %s\n", u[index].tel);
        printf("地址: ");
        if(u[index].address==1)
            printf("海淀区\n");
        if(u[index].address==2)
            printf("丰台区\n");
        if(u[index].address==3)
            printf("西城区\n");
        if(u[index].address==4)
            printf("其它\n");
        printf("请选择您要修改的信息\n(1.用户名, 2.密码, 3.姓名, 4.性别, 5.年龄, 6.邮箱, 7.电话, 8.地址, 9.退出当前界面): ");
    }

   
}
void Recharge()
{
    UserInfo *u;
    u = (UserInfo*)malloc(MAX_RECORDS*sizeof(UserInfo));
    int count=0, num_records=0;
    int index = -1;
    char string[7];
    char code1[]="vivo50";
    char code2[]="vivo100";
    char code3[]="vivo500";
    //UserInfo u;
    //struct UserInfo u[MAX_RECORDS];

    FILE* fp = fopen("Test_UserInfo05", "r");
    if (fp == NULL) {
        printf("无法打开 %s\n", "Test_UserInfo05");
        exit(1);
    }
    // 读取文件内容
    while (fscanf(fp, "%s %s %s %d %d %s %s %d %d %lf", u[num_records].id, u[num_records].password, u[num_records].name, &u[num_records].gender,&u[num_records].age,u[num_records].mail,u[num_records].tel, &u[num_records].address, &u[num_records].timez, &u[num_records].val) != EOF)
        num_records++;
    fclose(fp);
    // 寻找匹配的用户名
    for (int i = 0; i < num_records; i++)
    {
        if (strcmp(u[i].id, YOU.id) == 0)
        {
            index = i;
            break;
        }
    }
    if (index == -1) 
    {
        printf("用户名不存在或错误\n");
        exit(1);
    }
    CLEAR
    printf("******您正在进行余额充值******\n\n");
    printf("测试阶段充值代码如下\n");
    printf("充值代码   金额\n");
    printf("vivo50      100\n");
    printf("vivo100     200\n");
    printf("vivo500     300\n\n");
    printf("您的余额: %.2lf\n", u[index].val);
    printf("请输入充值卡代码: ");
    scanf("%s", string);
    if(strcmp(code1, string)==0)
    {    
        YOU.val+=50;
        count=1;
    }
    if(strcmp(code2, string)==0)
    {    
        YOU.val+=100;
        count=1;
    }

    if(strcmp(code3, string)==0)
    {    
        YOU.val+=500;
        count=1;
    }
    u[index].val=YOU.val;
    printf("您现在的余额为%f\n",u[index].val);
    //重新写入
    fp = fopen("Test_UserInfo05", "w");
    if (fp == NULL)
    {
        printf("未找到文件 %s\n", "Test_UserInfo05");
        exit(1);
    }
    for (int i = 0; i < num_records; i++)
         fprintf(fp, "%s %s %s %d %d %s %s %d %d %.2lf\n", u[i].id, u[i].password, u[i].name, u[i].gender, u[i].age, u[i].mail, u[i].tel, u[i].address, u[i].timez, u[i].val);
    free (u);
    fclose(fp);

    CLEAR
    if(count)
    {
        printf("充值成功! \n");
        printf("目前您的账户余额为: %.2lf\n\n", YOU.val);
        printf("(按任意键继续)\n");
        fflush(stdin);
        getch();
        fflush(stdin);
    }
    else
    {
        printf("充值失败! \n");
        printf("目前您的账户余额为: %.2lf\n\n", YOU.val);
        printf("(按任意键继续)\n");
        fflush(stdin);
        getch();
        fflush(stdin);
    }    

    CLEAR
    printf("尊敬的 %s ",YOU.name);
    if(YOU.gender==1)
        printf("先生");
    if(YOU.gender==2)
        printf("女士");
    printf(", 您已登陆账户 %s \n\n提示: ", YOU.id);
    printf("请输入数字0~6\n");
    printf("0.退出登陆\n");
    printf("1.查看个人信息\n");
    printf("2.修改个人信息\n");
    printf("3.查询个人订单\n");
    printf("4.查询场馆信息: 精准查找单个场馆\n");
    printf("5.查询场馆信息: 对比所有场馆预约信息\n");
    printf("6.场馆预约\n");
    printf("7.余额查询/充值\n");

    return;
 }
void del()
{
   UserInfo *u;
    u = (UserInfo*)malloc(MAX_RECORDS*sizeof(UserInfo));
    //UserInfo u;
    //struct UserInfo u[MAX_RECORDS];
    int num_records = 0;//计数变量，用于计算用户信息文件里有多少位用户

    char search_name[MAX_NAME_LEN];

    FILE* fp = fopen("Test_UserInfo05.txt", "r");
    if (fp == NULL)
     {
        printf("无法打开 Test_UserInfo05");
        return;
        
    }

//读取用户信息文件内容
    while (fscanf(fp, "%s %s %s %d %d %s %s %d %d %lf", u[num_records].id, u[num_records].password, u[num_records].name, &u[num_records].gender,&u[num_records].age,u[num_records].mail,u[num_records].tel, &u[num_records].address, &u[num_records].timez, &u[num_records].val) != EOF) 
        num_records++;
    fclose(fp);

    CLEAR
    for (int i = 0; i < num_records; i++) //打印出所有用户名
        printf("%s\n",u[i].id);
    
    printf("以上是所有用户的id，请输入需要删除的用户名: ");
    scanf("%s", search_name);
    int index = -1;
    for (int i = 0; i < num_records; i++) 
    {
        if (strcmp(u[i].id, search_name) == 0)
         {
            index = i;
            break;
        }
    }
    if(index==-1)
        printf("用户名不存在或错误 %s\n", search_name);
             
    else
    {
        printf("目标用户信息:\n");
        printf("用户名: %s\n", u[index].id);
        printf("密码: %s\n", u[index].password);
        printf("姓名: %s\n", u[index].name);
        if(u[index].gender==1)
            printf("性别: 男\n");
        if (u[index].gender==0)
            printf("性别：女\n");
        printf("年龄: %d\n", u[index].age);
        printf("邮箱: %s\n", u[index].mail);
        printf("电话: %s\n", u[index].tel);
        printf("地址: ");
        if(u[index].address==1)
            printf("海淀区\n");
        if(u[index].address==2)
            printf("丰台区\n");
        if(u[index].address==3)
            printf("西城区\n");
        if(u[index].address==4)
            printf("其它\n");


        for(int i=index; i<(num_records)-2; i++)
            u[i]=u[i+1];
        

       (num_records)--;
        printf("用户信息已经删除。\n");
        
    }
    for (int i = 0; i < num_records; i++) 
        printf("%s\n",u[i].id);
    fp = fopen("Test_UserInfo05.txt", "w");
    if (fp == NULL)
    {
        printf("无法打开 Test_UserInfo05");
        exit(1);
    }

    for (int i = 0; i < num_records; i++) 
        fprintf(fp, "%s %s %s %d %d %s %s %d %d %lf\n", u[i].id, u[i].password, u[i].name, u[i].gender, u[i].age,u[i].mail,u[i].tel, u[i].address, u[i].timez, u[i].val);
    fclose(fp);
    return ;
}


void Statisticstime()                         /***********统计最受欢迎的时间段********/
{
    CLEAR 
    char str[2];    //使用数组str[]记录用户的输入。选用数组是为了防止用户输入字符串。正常情况下，用户的输入存在str[0]
    str[1]='\000';
    int index01=1;  //index01变量用于继续/终止登陆界面的循环。初始化为1,使得登陆界面一直进行。只有输入0才能使其值变为0，以终止循环，结束程序。
    RsvInfo *u;
    u = (RsvInfo*)malloc(MAX_RECORDS*sizeof(RsvInfo));
    
    //UserInfo u;
    //struct UserInfo u[MAX_RECORDS];
    //定义变量
    int num_records= 0;
    char filename[] = "Test_RsvInfo01";
    char search_name[MAX_NAME_LEN];
    char choice;
    //打开文件
    FILE* fp = fopen("Test_RsvInfo01", "r");
    if (fp == NULL) {
        printf("无法打开 %s\n", "Test_RsvInfo01");
        return ;
    }

    // 读取文件内容num_records
    while (fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d",u[num_records].client.id, &u[num_records].place.ICcode1, &u[num_records].field.ICcode2, &u[num_records].duration, &u[num_records].ExpTime.year, &u[num_records].ExpTime.month, &u[num_records].ExpTime.daym, &u[num_records].ExpTime.hour,  &u[num_records].code)!= EOF)
     {
        
       // printf("%s %d %d %d %d年%d月%d日%d时 %d",u[num_records].client.id, u[num_records].place.ICcode1, u[num_records].field.ICcode2, u[num_records].duration, u[num_records].ExpTime.year, u[num_records].ExpTime.month, u[num_records].ExpTime.daym, u[num_records].ExpTime.hour,  u[num_records].code);
        num_records++;
    }
   
        CLEAR
        
        printf("请输入对应数字进行选择场馆\n");
        printf("1.健身馆\n");
        printf("2.游泳馆\n");
        printf("3.足球场\n");
        fflush(stdin);
        //容错如若输入的不是数字重新进入循环
        int b;
        b=1;
        while(b)
        {
        scanf("%s",str);
        fflush(stdin);
        while(index01)            //检查用户输入是否为单个字符
        {
            if(str[1]=='\000')
                break;
            CLEAR
            
            printf("输入有误! 请输入数字\n");
            printf("请输入对应数字选择要查询的场馆\n");
            printf("1.健身馆\n");
            printf("2.游泳馆\n");
            printf("3.足球场\n");

            str[1]='\000';
            scanf("%s",str);
            fflush(stdin);
        }
        /********定义变量********/
        int gym1,gym2,gym3,max,sec;
        float total;
        int a[24]={0};
        gym1=gym2=gym3=max=sec=0;
        total=0;
        int i;
        //功能
        switch (str[0])
    {
        case '1':
            CLEAR
            /*******将订单的预定时间导入相对应的数组中*********/
            for ( i = 0; i < num_records; i++) {
            if (u[i].place.ICcode1=1) {
                for(int count=0;count<24;count++)
                {
            if(u[i].ExpTime.hour==count){
            a[count]++;
            }
            
        }
            }
            }
            /**********排序选出最热门的时间*/
        max=sec=a[0];
        for(i=0;i<24;i++)
        {
        if(max<a[i]){
            max=a[i];
            sec=i;
        }
        }
        
    
        printf("健身房的最热门预定时间为为%d点\n",sec);
         b=0;
            break;
        case '2':
        /*******将订单的预定时间导入相对应的数组中*********/
       CLEAR
            for ( i = 0; i < num_records; i++) {
            if (u[i].place.ICcode1==2) {
                for(int count=0;count<24;count++)
                {
            if(u[i].ExpTime.hour==count){
            a[count]++;
            }
            
        }
            }
            }
            /**********排序选出最热门的时间*/
        max=sec=a[0];
        for(i=0;i<24;i++)
        {
        if(max<a[i]){
            max=a[i];
            sec=i;
        }
        }
        
    
        printf("游泳馆的最热门预定时间为为%d点\n",sec);
            break;
        case '3':
            CLEAR
            /*******将订单的预定时间导入相对应的数组中*********/
            for ( i = 0; i < num_records; i++) {
            if (u[i].place.ICcode1==3) {
                for(int count=0;count<24;count++)
                {
            if(u[i].ExpTime.hour==count){
            a[count]++;
            }
            
        }
            }
            }
            /**********排序选出最热门的时间*******************/
        max=sec=a[0];
        for(i=0;i<24;i++)
        {
        if(max<a[i]){
            max=a[i];
            sec=i;
        }
        }
        
    
        printf("足球场的最热门预定时间为为%d点\n",sec);
         b=0;
            break;
            /****************防止用户输入字符*************/
        default:
            CLEAR
            printf("输入有误! 请输入数字\n");
            printf("请输入对应数字选择要查询的场馆\n");
            printf("1.健身馆\n");
            printf("2.游泳馆\n");
            printf("3.足球场\n");
            b=1;
            break;
    }
        }
    
    
  
    return ;
}
void Statisticsage()                            /******************统计不同场馆的年龄段********************/
{
    CLEAR 
    char str[2];    //使用数组str[]记录用户的输入。选用数组是为了防止用户输入字符串。正常情况下，用户的输入存在str[0]
    str[1]='\000';
    int index01=1;  //index01变量用于继续/终止登陆界面的循环。初始化为1,使得登陆界面一直进行。只有输入0才能使其值变为0，以终止循环，结束程序。
    RsvInfo *u;
    char dustbin[256];
    //自动分配内存
    u = (RsvInfo*)malloc(MAX_RECORDS*sizeof(RsvInfo));
    UserInfo *v;
    v = (UserInfo*)malloc(MAX_RECORDS*sizeof(UserInfo));
    //UserInfo u;
    //struct UserInfo u[MAX_RECORDS];
    
    int num_records,num_records2= 0;
    char filename[] = "Test_RsvInfo01";
    char search_name[MAX_NAME_LEN];
    char choice;
    FILE* fp = fopen("Test_RsvInfo01", "r");
    if (fp == NULL) {
        printf("无法打开 %s\n", "Test_RsvInfo01");
        return ;
    }

    // 读取订单内容
    while (fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %s",u[num_records].client.id, &u[num_records].place.ICcode1, &u[num_records].field.ICcode2, &u[num_records].duration, &u[num_records].ExpTime.year, &u[num_records].ExpTime.month, &u[num_records].ExpTime.daym, &u[num_records].ExpTime.hour,  dustbin)!= EOF)
     {//printf("%s %d %d %d %d年%d月%d日%d时 %d",u[num_records].client.id, u[num_records].place.ICcode1, u[num_records].field.ICcode2, u[num_records].duration, u[num_records].ExpTime.year, u[num_records].ExpTime.month, u[num_records].ExpTime.daym, u[num_records].ExpTime.hour,  u[num_records].code);
        num_records++;
    }
     FILE* fp1 = fopen("Test_UserInfo05", "r");
    if (fp1 == NULL) {
        printf("无法打开 %s\n", "Test_UserInfo05");
        return ;
    }

    // 读取用户内容
    while (fscanf(fp1, "%s %s  %s %d %d %s %s %d %d %lf", v[num_records2].id, v[num_records2].password, v[num_records2].name, &v[num_records2].gender,&v[num_records2].age,v[num_records2].mail,v[num_records2].tel,&v[num_records].address,&v[num_records].timez, &v[num_records].val) != EOF) {
        //printf("%s %s  %s %d %d %s %s %s %d %d", v[num_records2].id, v[num_records2].password, v[num_records2].name, v[num_records2].gender,v[num_records2].age,v[num_records2].mail,v[num_records2].tel,v[num_records].address,v[num_records].val,v[num_records].timez); 
        num_records2++;

    }

    fclose(fp);
    int i;
   int index = -1;
   /************把用户的信息传到订单编号中**********/
    for (int i = 0; i < num_records; i++) {
        for (int m = 0; m < num_records2; m++){
        if (strcmp(v[m].id, u[i].client.id) == 0) {
            u[i].client.age=v[m].age;
            u[i].client.gender=v[m].gender;
            
        }
        }
    }
        
        
        printf("请输入对应数字进行选择场馆\n");
        printf("1.健身馆\n");
        printf("2.游泳馆\n");
        printf("3.足球场\n");
        fflush(stdin);
        //容错防止用户输入其他字符
        int b;
        b=1;
        while(b)
        {
        scanf("%s",str);
        fflush(stdin);
        while(index01)            //检查用户输入是否为单个字符
        {
            if(str[1]=='\000')
                break;
            CLEAR
            
            printf("输入有误! 请输入数字\n");
            printf("请输入对应数字进行选择场馆\n");
            printf("1.健身馆\n");
            printf("2.游泳馆\n");
            printf("3.足球场\n");

            str[1]='\000';
            scanf("%s",str);
            fflush(stdin);
        }
        /*定义变量一遍后面计算*/
        int gym1,gym2,gym3,max,sec;
        float total;
        int a[24];
        gym1=gym2=gym3=max=sec=0;
        int child,young,old;
        child=young=old=0;
        total=0;
        
        switch (str[0])
    {
        case '1':
            CLEAR
            /*********for循环是所有的订单受判断**************/
            for ( i = 0; i < num_records; i++) {
                //判断顾客的年龄
            if (u[i].place.ICcode1==1) 
            {
            if(u[i].client.age<=18){
            child++;
            }else if(u[i].client.age>18&&u[i].client.age<60)
            {
                young++;
            }
            else{
                old++;
            }
            
        
            }
            }
        
        
    
        printf("健身房的小孩有%d个\n",child);
        printf("健身房的年轻人有%d个\n",young);
        printf("健身房的老人有%d个\n",old);
         b=0;
            break;
        case '2':
        /*********for循环是所有的订单受判断**************/
        CLEAR
            for ( i = 0; i < num_records; i++) {
                //判断顾客的年龄
            if (u[i].place.ICcode1==2) 
            {
            if(u[i].client.age<18){
            child++;
            }else if(u[i].client.age>18&&u[i].client.age<60)
            {
                young++;
            }
            else{
                old++;
            }
            
        
            }
            }
        
        
    
        printf("游泳馆的小孩有%d个\n",child);
        printf("游泳馆的年轻人有%d个\n",young);
        printf("游泳馆的老人有%d个\n",old);
           b=0;
            break ;
        case '3':
            CLEAR
            //for循环是所有的订单受判断

            for ( i = 0; i < num_records; i++) 
            {
                //判断顾客的年龄
            if (u[i].place.ICcode1==3) 
            {
            if(u[i].client.age<18){
            child++;
            }else if(u[i].client.age>18&&u[i].client.age<60)
            {
                young++;
            }
            else{
                old++;
            }
            
        
            }
            }
        
        
    
        printf("足球场的小孩有%d个\n",child);
        printf("足球场的年轻人有%d个\n",young);
        printf("足球场的老人有%d个\n",old);
        b=0;
        break;
        //容错输入非123的数字或其他字符可以重新进入函数
         default:
            CLEAR
            printf("输入有误! 请输入数字\n");
            printf("请输入对应数字选择要查询的场馆\n");
            printf("1.健身馆\n");
            printf("2.游泳馆\n");
            printf("3.足球场\n");
            b=1;
            break;
    }
        } 
    return ;

}
void StatisticsGender()                            /*统计男女受欢迎的运动*/

{
    CLEAR 
    char str[2];    //使用数组str[]记录用户的输入。选用数组是为了防止用户输入字符串。正常情况下，用户的输入存在str[0]
    str[1]='\000';
    int index01=1;  //index01变量用于继续/终止登陆界面的循环。初始化为1,使得登陆界面一直进行。只有输入0才能使其值变为0，以终止循环，结束程序。
    //自动分配内存
    RsvInfo *u;
    u = (RsvInfo*)malloc(MAX_RECORDS*sizeof(RsvInfo));
    UserInfo *v;
    v = (UserInfo*)malloc(MAX_RECORDS*sizeof(UserInfo));
    //UserInfo u;
    //struct UserInfo u[MAX_RECORDS];
    
    int num_records,num_records2= 0;
    char filename[] = "Test_RsvInfo01";
    char search_name[MAX_NAME_LEN];
    char choice;
    FILE* fp = fopen("Test_RsvInfo01", "r");
    if (fp == NULL) {
        printf("无法打开 %s\n", "Test_RsvInfo01");
        return ;
    }

    // 读取订单内容
    while (fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d",u[num_records].client.id, &u[num_records].place.ICcode1, &u[num_records].field.ICcode2, &u[num_records].duration, &u[num_records].ExpTime.year, &u[num_records].ExpTime.month, &u[num_records].ExpTime.daym, &u[num_records].ExpTime.hour,  &u[num_records].code)!= EOF)
     {//printf("%s %d %d %d %d年%d月%d日%d时 %d",u[num_records].client.id, u[num_records].place.ICcode1, u[num_records].field.ICcode2, u[num_records].duration, u[num_records].ExpTime.year, u[num_records].ExpTime.month, u[num_records].ExpTime.daym, u[num_records].ExpTime.hour,  u[num_records].code);
        num_records++;
    }
     FILE* fp1 = fopen("Test_UserInfo05", "r");
    if (fp1 == NULL) {
        printf("无法打开 %s\n", "Test_UserInfo05");
        return ;
    }

    // 读取文件内容
    while (fscanf(fp1, "%s %s  %s %d %d %s %s %s %d %d", v[num_records2].id, v[num_records2].password, v[num_records2].name, &v[num_records2].gender,&v[num_records2].age,v[num_records2].mail,v[num_records2].tel,v[num_records].address,&v[num_records].val,&v[num_records].timez) != EOF) {
        //printf("%s %s  %s %d %d %s %s %s %d %d", v[num_records2].id, v[num_records2].password, v[num_records2].name, v[num_records2].gender,v[num_records2].age,v[num_records2].mail,v[num_records2].tel,v[num_records].address,v[num_records].val,v[num_records].timez); 
        num_records2++;

    }

    fclose(fp);
    int i;
   int index = -1;
   /*************将用户信息传到订单中用户的结构体*******************/
    for (int i = 0; i < num_records; i++) {
        for (int m = 0; m < num_records2; m++){
        if (strcmp(v[m].id, u[i].client.id) == 0) {
            u[i].client.age=v[m].age;
            u[i].client.gender=v[m].gender;
            
        }
        }
    }
       
        
        printf("请输入对应数字进行选择\n");
        printf("1.查看受男性欢迎的运动\n");
        printf("2.查看受女性欢迎的运动\n");
       
        fflush(stdin);
         //容错防止用户输入其他字符
        int b;
        b=1;
        while(b)
        {
        scanf("%s",str);
        fflush(stdin);
        while(index01)            //检查用户输入是否为单个字符
        {
            if(str[1]=='\000')
                break;
            CLEAR
            
            printf("输入有误! 请输入数字\n");
            printf("请输入对应数字进行选择\n");
            printf("1.查看受男性欢迎的运动\n");
            printf("2.查看受女性欢迎的运动\n");

            str[1]='\000';
            scanf("%s",str);
            fflush(stdin);
        }
        /*************定义变量************/
        int gym1,gym2,gym3,max,sec;
        float total;
        int a[24];
        gym1=gym2=gym3=max=sec=0;
        int swim1,swim2,football1,football2;
        int child,young,old;
        child=young=old=0;
        total=0;
        swim1=swim2=football1=football2=0;
        switch (str[0])
    {
        case '1':
            CLEAR
            /*将订单信息中的用户分类*/
            for ( i = 0; i < num_records; i++) {
            if (u[i].client.gender==1) 
            {
                 if (u[i].place.ICcode1==1){
                    gym1++;
                 }
           if (u[i].place.ICcode1==2){
                    swim1++;
                 }
                 if (u[i].place.ICcode1==3){
                    football1++;
                 }
            
        
            }
            }
            /*比较最欢迎的运动*/
        if(gym1>swim1&&gym1> football1){
                printf("受男性欢迎的运动是健身\n");
        }
        if(swim1>gym1&&swim1> football1){
                printf("受男性欢迎的运动是游泳\n");
        }
        if(football1>gym1&&football1> swim1){
                printf("受男性欢迎的运动是足球\n");
        }
        if(swim1==gym1&&swim1==football1){
                printf("健身，游泳，足球三者受女性欢迎程度相同\n");
                }
       
    b=0;
        
            break;
        case '2':
        /*将订单信息中的用户分类*/
        CLEAR
             for ( i = 0; i < num_records; i++) {
            if (u[i].client.gender==2) 
            {
                 if (u[i].place.ICcode1==1){
                    gym1++;
                 }
           if (u[i].place.ICcode1==2){
                    swim1++;
                 }
                 if (u[i].place.ICcode1==3){
                    football1++;
                 }
            
        
            }
            }
            /*比较最欢迎的运动*/
        if(gym1>swim1&&gym1> football1){
                printf("受女性欢迎的运动是健身\n");
        }
        if(swim1>gym1&&swim1> football1){
                printf("受女性欢迎的运动是游泳\n");
        }
        if(football1>gym1&&football1> swim1){
                printf("受女性欢迎的运动是足球\n");
        }
           if(gym1==swim1&&gym1> football1){
                printf("受女性欢迎的运动是健身，游泳\n");
           }

                if(swim1==gym1&&swim1==football1){
                printf("健身，游泳，足球三者受女性欢迎程度相同\n");
                }
                b=0;
            break ;
                     default:
                     /*防止用户输入错误*/
            CLEAR
            printf("输入有误! 请输入数字\n");
            printf("请输入对应数字进行选择\n");
            printf("1.查看受男性欢迎的运动\n");
            printf("2.查看受女性欢迎的运动\n");
            b=1;
            break;
    }
        } 
    return ;
}

void save_records(struct Record records[], int count, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %d %d %d %d??%d??%d??%d?? %s\n", records[i].name, records[i].place1, records[i].place2, records[i].duration, records[i].year, records[i].month, records[i].day, records[i].hour, records[i].myear);
    }
    fclose(fp);
}

int load_records(struct Record records[], int max_count, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return 0;
    }
    int count = 0;
    while (fscanf(fp, "%s %d %d %d %d??%d??%d??%d?? %s\n", records[count].name, &records[count].place1, &records[count].place2, &records[count].duration, &records[count].year, &records[count].month, &records[count].day, &records[count].hour, records[count].myear) != EOF) {
        count++;
        if (count >= max_count) {
            break;
        }
    }
    fclose(fp);
    return count;
}

void delete_old_records(struct Record records[], int *count) {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    int current_year = tm_now->tm_year + 1900;
    int current_month = tm_now->tm_mon + 1;
    int current_day = tm_now->tm_mday;
    int i = 0;
    while (i < *count) {
        if (records[i].year < current_year ||
            (records[i].year == current_year && records[i].month < current_month) ||
            (records[i].year == current_year && records[i].month == current_month && records[i].day < current_day)) {
            for (int j = i; j < *count - 1; j++) {
                records[j] = records[j + 1];
            }
            (*count)--;
        } else {
            i++;
        }
    }
}

void delet_Rsv() 
{
   struct Record records[1000];
    int count = 0;

    // 从文件中读取记录
    count = load_records(records, 1000, "gym.txt");

    // 删除旧记??
    delete_old_records(records, &count);
    
    // 保存记录到文??
    save_records(records, count, "gym.txt");
    
}


void swimfielddel()
  { 
     FieldInfo *u;
    u = (FieldInfo*)malloc(MAX_RECORDS*sizeof(FieldInfo));
    
    int num_records = 0;
    int search_num;
    FILE* fp = fopen("Test_Field201", "r");
     while (fscanf(fp, "%d %s %d %d %d %lf",&u[num_records].ICcode2, u[num_records].name, &u[num_records].EntranceAge, &u[num_records].MaxNum, &u[num_records].Area, &u[num_records].prize) != EOF) 
    {
        num_records++;
        
    }
    fclose(fp);
   
    
     for (int i = 0; i < num_records; i++) 
    {
        printf("%s %d\n",u[i].name,u[i].ICcode2);
     
    }
    fflush(stdin);
    printf("请输入需要删除的场地的ICcode2:");

 
    fscanf(stdin, "%d", &search_num);

    

    int index = -1;
    for (int i = 0; i < num_records; i++) 
    {
        if (u[i].ICcode2==search_num)
         {
            index = i;
            break;
        }
    }

    if(index==-1)
     {
            printf("用户名不存在或错误 %s\n", search_num);
             return;
            
     }

      else
      
      {

        printf("游泳馆目标场地信息:\n");
        printf("ICcode2: %d\n ",u[index].ICcode2);
        printf("场地名: %s\n",u[index].name);
        printf("准入年龄：%d \n",u[index].EntranceAge);
        printf("最大人数：%d\n",u[index].MaxNum);
        printf("面积：%d\n",u[index].Area);
        printf("价格：%.2f\n",u[index].prize);

          for(int i =index;i<(num_records)-1;i++)
       {
              u[i]=u[i+1];
          
        }
            (num_records)--;
             printf("场地信息已经删除。\n");


         for (int i = 0; i < num_records; i++) 
    {
        printf("%s\n",u[i].name);
       
    }
    fp = fopen("Test_Field201", "w");
    for (int i = 0; i < num_records; i++) 
    {
       fprintf(fp, "%d %s %d %d %d %lf",i + 1, u[i].name, u[i].EntranceAge, u[i].MaxNum, u[i].Area, u[i].prize);

       
    }
     fclose(fp);
     return;

}

 }
void footballfielddel()
  {       

    FieldInfo *u;
    u = (FieldInfo*)malloc(MAX_RECORDS*sizeof(FieldInfo));
    
    int num_records = 0;
  
    int search_num =0;
    FILE* fp = fopen("Test_Field301", "r");
     while (fscanf(fp, "%d %s %d %d %d %lf",&u[num_records].ICcode2, u[num_records].name, &u[num_records].EntranceAge, &u[num_records].MaxNum, &u[num_records].Area, &u[num_records].prize) != EOF) 
    {
        num_records++;
        
    }
    fclose(fp);
   
    
     for (int i = 0; i < num_records; i++) 
    {
        printf("%s %d\n",u[i].name,u[i].ICcode2);
     
    }
    printf("请输入需要删除的场地的ICcode2: ");
    scanf("%d", &search_num);
    int index = -1;
    for (int i = 0; i < num_records; i++) 
    {   
        if (u[i].ICcode2==search_num)
         {
            index = i;
            break;
        }
    }

    if(index==-1)
     {
            printf("场馆不存在或错误 %s\n", search_num);
             return;
            
     }

      else
      
      {

        printf("足球馆目标场地信息:\n");
        printf("ICcode2: %d\n ",u[index].ICcode2);
        printf("场地名: %s\n",u[index].name);
        printf("准入年龄：%d \n",u[index].EntranceAge);
        printf("最大人数：%d\n",u[index].MaxNum);
        printf("面积：%d\n",u[index].Area);
        printf("价格：%.2f\n",u[index].prize);

          for(int i =index;i<(num_records)-1;i++)
       {
              u[i]=u[i+1];
          
        }
            (num_records)--;
             printf("场地信息已经删除。\n");


         for (int i = 0; i < num_records; i++) 
    {
        printf("%s\n",u[i].name);
       
    }
    fp = fopen("Test_Field301", "w");
    for (int i = 0; i < num_records; i++) 
    {
       fprintf(fp, "%d %s %d %d %d %lf\n",i + 1, u[i].name, u[i].EntranceAge, u[i].MaxNum, u[i].Area, u[i].prize);

       
    }
     fclose(fp);
     return;

}


    
 }
void  gymfielddel()
{   
  
FieldInfo* u;    
u = (FieldInfo*)malloc(MAX_RECORDS*sizeof(FieldInfo));    
int num_records = 0;
int search_num;
FILE* fp = fopen("Test_Field101", "r");
while (fscanf(fp,"%d %s %d %d %d %lf",&u[num_records].ICcode2, u[num_records].name, &u[num_records].EntranceAge, &u[num_records].MaxNum, &u[num_records].Area, &u[num_records].prize) != EOF) 
num_records++;
fclose(fp);
for (int i = 0; i < num_records; i++) 
printf("%s %d\n",u[i].name,u[i].ICcode2);
printf("请输入需要删除的场地的ICcode2: ");
scanf("%d",&search_num);
int index = -1;
for (int i = 0; i < num_records; i++) 
{
 if (u[i].ICcode2==search_num)
 {
    index = i;
    break;
 }
}

if(index==-1)
{
    printf("用户名不存在或错误 %s\n", search_num);
    return;
            
}
else{
         
        printf("健身房目标场地信息:\n");
        printf("ICcode2: %d\n ",u[index].ICcode2);
        printf("场地名: %s\n",u[index].name);
        printf("准入年龄：%d \n",u[index].EntranceAge);
        printf("最大人数：%d\n",u[index].MaxNum);
        printf("面积：%d\n",u[index].Area);
        printf("价格：%.2f\n",u[index].prize);

        for(int i =index;i<(num_records)-1;i++)
            u[i]=u[i+1];
            (num_records)--;
            printf("场地信息已经删除。\n");


        for (int i = 0; i < num_records; i++) 
            printf("%s\n",u[i].name);
        fclose(fp);
        fp = fopen("Test_Field101", "w");
        for (int i = 0; i < num_records; i++) 
        fprintf(fp,"%d %s %d %d %d %.2lf\n",i + 1, u[i].name, u[i].EntranceAge, u[i].MaxNum, u[i].Area, u[i].prize);
        fclose(fp);
        return ;

}
}
void fielddel()
{
 
int num_records = 0;

char search_name[30];
char str[2];
str[1]='\000';
while(1)
{
  
     printf("请选择想要删除场地的场馆\n");
     printf("输入1进入健身房删除界面\n");
     printf("输入2进入游泳馆场地删除界面\n");
     printf("输入3进入足球场场地删除界面\n");
     printf("输入0可退出该界面");
     scanf("%s",str);
     fflush(stdin);
     switch(str[0])
     {
       case '1' :
          printf("您已经进入健身房场地删除界面\n");
          gymfielddel();
          break;
        

       case '2':
          printf("您已经进入游泳馆场地删除界面\n");
          swimfielddel();
          break;


        case '3':
        printf("您已经进入足球场场地删除界面\n");
        footballfielddel();
        break;

        case '0':
            return;

        default:
        CLEAR;
        printf("输入错误!!请输入1,2,3或0\n");
        break;

 }

}
 
}



void footballchange()
{
  typedef struct _FieldInfo
{
    char name[32];       //场馆名称
    int ICcode2;
    int EntranceAge;     //准入年龄
    int MaxNum;          //最大人数
    int Area;           //面积
    double prize;      //价格
}FieldInfo;


    FieldInfo *u;
    u = (FieldInfo*)malloc(10000*sizeof(FieldInfo));
   
    //struct UserInfo u[MAX_RECORDS];
    int num_records = 0;
    char search_name[64];
    int choice;
    int search_num;
   FILE* fp = fopen("Test_Field301", "r");
    if (fp == NULL)
     {
        printf("无法打开 Test_Field301\n");
        return;
    }

    // 读取文件内容
         while (fscanf(fp,"%d %s %d %d %d %lf",&u[num_records].ICcode2, u[num_records].name, &u[num_records].EntranceAge, &u[num_records].MaxNum, &u[num_records].Area, &u[num_records].prize) != EOF) 
        {
            num_records++;
        }
         fclose(fp);
      for(int i=0;i<num_records;i++)
      {

         printf("场地名称: %s   场地编号： %d \n",u[i].name,u[i].ICcode2);

      }

    printf("输入场地编号ICcode2: ");
    scanf("%d", &search_num);
    // 寻找匹配的用户ICcode2
    int index = -1;
    for (int i = 0; i < num_records; i++)
     {
        if (u[i].ICcode2==search_num) 
        {
            index = i;
            break;
        }
    }
    if (index == -1)
     {
        printf("场地ICcode2不存在或错误 %d\n", search_num);
        return;
     }
        printf("足球馆目标场地信息:\n");
        printf("ICcode2: %d\n ",u[index].ICcode2);
        printf("场地名: %s\n",u[index].name);
        printf("准入年龄：%d \n",u[index].EntranceAge);
        printf("最大人数：%d\n",u[index].MaxNum);
        printf("面积：%d\n",u[index].Area);
        printf("价格：%.2f\n",u[index].prize);

    printf("请输入按键进行修改 (1 = ICcode2, 2 = 场地名, 3 = 准入年龄， 4 = 最大容量， 5 = 面积， 6 = 价格\n");
   scanf("%d",&choice);
    switch (choice) {
        case 1:
            printf("输入新的ICcode2: ");
            scanf("%d", &u[index].ICcode2);
            break;
        case 2:
            printf("输入新的场地名: ");
            scanf("%s", u[index].name);
            break;
        case 3:
            printf("输入新的准入年龄: ");
            scanf("%d", &u[index].EntranceAge);
            break;
         case 4:
         printf("请输入新的最大容量：");
         scanf("%d",&u[index].MaxNum);
         break;
         case 5:
         printf("请输入新的面积：");
         scanf("%d",&u[index].Area);
         break;
         case 6:
         printf("请输入新的价格：");
         scanf("%lf",&u[index].prize);
         break;
         
        default:
            printf("错误输入\n");
            return;
    }
    int i;
    /*for(i=0;i<num_records;i++)
    {
        printf("%d %s %d %d %d %.2lf",u[num_records].ICcode2, u[num_records].name, u[num_records].EntranceAge, u[num_records].MaxNum, u[num_records].Area, u[num_records].prize);
    }*/
    //重新写入
    fp = fopen("Test_Field301", "w");
    if (fp == NULL) {
        printf("未找到文件Test_Field301" );
        return;
    }
    for (int i = 0; i < num_records; i++) {
        fprintf(fp, "%d %s %d %d %d %.2lf\n",u[i].ICcode2, u[i].name, u[i].EntranceAge, u[i].MaxNum, u[i].Area, u[i].prize);

    }
    free (u);
    fclose(fp);

    printf("修改成功.\n");

    return;



}
void gymchange()//修改场地信息
{
    typedef struct _FieldInfo
{
    char name[32];       //场馆名称
    int ICcode2;
    int EntranceAge;     //准入年龄
    int MaxNum;          //最大人数
    int Area;           //面积
    double prize;      //价格
}FieldInfo;


    FieldInfo *u;
    u = (FieldInfo*)malloc(10000*sizeof(FieldInfo));
   
    //struct UserInfo u[MAX_RECORDS];
    int num_records = 0;
    char search_name[64];
    int choice;
    int search_num;
   FILE* fp = fopen("Test_Field101", "r");
    if (fp == NULL)
     {
        printf("无法打开 Test_Field101\n");
        return;
    }

    // 读取文件内容
         while (fscanf(fp,"%d %s %d %d %d %lf",&u[num_records].ICcode2, u[num_records].name, &u[num_records].EntranceAge, &u[num_records].MaxNum, &u[num_records].Area, &u[num_records].prize) != EOF) 
        {
            num_records++;
        }
         fclose(fp);
      for(int i=0;i<num_records;i++)
      {

         printf("场地名称: %s   场地编号： %d \n",u[i].name,u[i].ICcode2);

      }

    printf("输入场地编号ICcode2: ");
    scanf("%d", &search_num);
    // 寻找匹配的用户ICcode2
    int index = -1;
    for (int i = 0; i < num_records; i++)
     {
        if (u[i].ICcode2==search_num) 
        {
            index = i;
            break;
        }
    }
    if (index == -1)
     {
        printf("场地ICcode2不存在或错误 %d\n", search_num);
        return;
     }
        printf("健身房目标场地信息:\n");
        printf("ICcode2: %d\n ",u[index].ICcode2);
        printf("场地名: %s\n",u[index].name);
        printf("准入年龄：%d \n",u[index].EntranceAge);
        printf("最大人数：%d\n",u[index].MaxNum);
        printf("面积：%d\n",u[index].Area);
        printf("价格：%.2f\n",u[index].prize);

    printf("请输入按键进行修改 (1 = ICcode2, 2 = 场地名, 3 = 准入年龄， 4 = 最大容量， 5 = 面积， 6 = 价格\n");
   scanf("%d",&choice);
    switch (choice) {
        case 1:
            printf("输入新的ICcode2: ");
            scanf("%d", &u[index].ICcode2);
            break;
        case 2:
            printf("输入新的场地名: ");
            scanf("%s", u[index].name);
            break;
        case 3:
            printf("输入新的准入年龄: ");
            scanf("%d", &u[index].EntranceAge);
            break;
         case 4:
         printf("请输入新的最大容量：");
         scanf("%d",&u[index].MaxNum);
         break;
         case 5:
         printf("请输入新的面积：");
         scanf("%d",&u[index].Area);
         break;
         case 6:
         printf("请输入新的价格：");
         scanf("%lf",&u[index].prize);
         break;
         
        default:
            printf("错误输入\n");
            return;
    }
    int i;
    /*for(i=0;i<num_records;i++)
    {
        printf("%d %s %d %d %d %.2lf",u[num_records].ICcode2, u[num_records].name, u[num_records].EntranceAge, u[num_records].MaxNum, u[num_records].Area, u[num_records].prize);
    }*/
    //重新写入
    fp = fopen("Test_Field101", "w");
    if (fp == NULL) {
        printf("未找到文件Test_Field101" );
        return;
    }
    for (int i = 0; i < num_records; i++) {
        fprintf(fp, "%d %s %d %d %d %.2lf\n",u[i].ICcode2, u[i].name, u[i].EntranceAge, u[i].MaxNum, u[i].Area, u[i].prize);

    }
    free (u);
    fclose(fp);

    printf("修改成功.\n");

    return;
}
void swimchange()
    {
        typedef struct _FieldInfo
{
    char name[32];       //场馆名称
    int ICcode2;
    int EntranceAge;     //准入年龄
    int MaxNum;          //最大人数
    int Area;           //面积
    double prize;      //价格
}FieldInfo;


    FieldInfo *u;
    u = (FieldInfo*)malloc(10000*sizeof(FieldInfo));
   
    //struct UserInfo u[MAX_RECORDS];
    int num_records = 0;
    char search_name[64];
    int choice;
    int search_num;
   FILE* fp = fopen("Test_Field201", "r");
    if (fp == NULL)
     {
        printf("无法打开 Test_Field201\n");
        return;
    }

    // 读取文件内容
         while (fscanf(fp,"%d %s %d %d %d %lf",&u[num_records].ICcode2, u[num_records].name, &u[num_records].EntranceAge, &u[num_records].MaxNum, &u[num_records].Area, &u[num_records].prize) != EOF) 
        {
            num_records++;
        }
         fclose(fp);
      for(int i=0;i<num_records;i++)
      {

         printf("场地名称: %s   场地编号： %d \n",u[i].name,u[i].ICcode2);

      }

    printf("输入场地编号ICcode2: ");
    scanf("%d", &search_num);
    // 寻找匹配的用户ICcode2
    int index = -1;
    for (int i = 0; i < num_records; i++)
     {
        if (u[i].ICcode2==search_num) 
        {
            index = i;
            break;
        }
    }
    if (index == -1)
     {
        printf("场地ICcode2不存在或错误 %d\n", search_num);
        return;
     }
        printf("游泳馆目标场地信息:\n");
        printf("ICcode2: %d\n ",u[index].ICcode2);
        printf("场地名: %s\n",u[index].name);
        printf("准入年龄：%d \n",u[index].EntranceAge);
        printf("最大人数：%d\n",u[index].MaxNum);
        printf("面积：%d\n",u[index].Area);
        printf("价格：%.2f\n",u[index].prize);

    printf("请输入按键进行修改 (1 = ICcode2, 2 = 场地名, 3 = 准入年龄， 4 = 最大容量， 5 = 面积， 6 = 价格\n");
   scanf("%d",&choice);
    switch (choice) {
        case 1:
            printf("输入新的ICcode2: ");
            scanf("%d", &u[index].ICcode2);
            break;
        case 2:
            printf("输入新的场地名: ");
            scanf("%s", u[index].name);
            break;
        case 3:
            printf("输入新的准入年龄: ");
            scanf("%d", &u[index].EntranceAge);
            break;
         case 4:
         printf("请输入新的最大容量：");
         scanf("%d",&u[index].MaxNum);
         break;
         case 5:
         printf("请输入新的面积：");
         scanf("%d",&u[index].Area);
         break;
         case 6:
         printf("请输入新的价格：");
         scanf("%lf",&u[index].prize);
         break;
         
        default:
            printf("错误输入\n");
            return;
    }
    int i;
    /*for(i=0;i<num_records;i++)
    {
        printf("%d %s %d %d %d %.2lf",u[num_records].ICcode2, u[num_records].name, u[num_records].EntranceAge, u[num_records].MaxNum, u[num_records].Area, u[num_records].prize);
    }*/
    //重新写入
    fp = fopen("Test_Field201", "w");
    if (fp == NULL) {
        printf("未找到文件Test_Field201" );
        return;
    }
    for (int i = 0; i < num_records; i++) {
        fprintf(fp, "%d %s %d %d %d %.2lf\n",u[i].ICcode2, u[i].name, u[i].EntranceAge, u[i].MaxNum, u[i].Area, u[i].prize);

    }
    free (u);
    fclose(fp);

    printf("修改成功.\n");

    return;

    }


void changepla()
{
   char str[2];
 str[1]='\000';
    while(1)
{
  
     printf("请选择想要修改场地的场馆\n");
     printf("输入1进入健身房修改界面\n");
     printf("输入2进入游泳馆场地修改界面\n");
     printf("输入3进入足球场场地修改界面\n");
     scanf("%s",str);
     fflush(stdin);
     switch(str[0])
     {
       case '1' :
          printf("您已经进入健身房场地修改界面\n");
          gymchange();
          break;
        

       case '2':
          printf("您已经进入游泳馆场地修改界面\n");
          swimchange();
          break;


        case '3':
        printf("您已经进入足球场场地修改界面\n");
        footballchange();
        break;


        default:
        CLEAR;
        printf("输入错误!!请输入1,2,3\n");
        break;

 }

}
 


return ;
}

