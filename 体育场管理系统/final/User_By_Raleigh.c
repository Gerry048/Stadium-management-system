#include "Basic.c"
/*
该文件User_By_Raleigh.c包含用户框架和用户功能。除了用户修改个人信息和充值余额两个涉及修改文件内信息的功能，全部内容由Raleigh全权开发
*/


//用户注册函数。该函数被用户登陆函数调用，输入用户id环节便在该函数，若该用户名未被注册，则调用本函数
void UserRegister(char* userid)
{
    
//本函数用到的变量声明：
    FILE *fp;
    UserInfo u;              //用于储存用户输入的个人信息。注册成功后令全局变量YOU=u(前者也是UserInfo类型的)
    int index01=1;          //两个标准化使用的变量，详见ComprehensiveGymsys.c里的相关·介绍
    char str[2]={'\000', '\000'};
    int idot, iat, count; //写入邮箱时使用。idot和iat分别指代“.”和“@”所在位置。count是“@”和“.”一共出现的次数
    int index03=0;       //一个计数变量，用户键入电话号码，用它
    int index05=0;      //一个计数变量，用于识别"again"。详见后
    char ch;           //中间变量
    int fscval;       //fscanf()函数的返回值，详见后
    char str2[6]="again";
    str2[5]='\000';//最后一位为空，原因见后
    strcpy(u.id, userid);
//打开用户信息文件
    fp = fopen("Test_UserInfo05", "a+");
    if(fp == NULL)
    {
        printf("error: UserInfo文件打开失败\n");
        exit(1);
    }
//键入用户密码
    CLEAR
    printf("************您已进入用户注册界面***********\n\n提示: 您输入的用户名未经注册, 已跳转至注册页面。输入again返回登陆界面并重新输入用户名\n");
    printf("请输入您的用户名: %s\n", u.id);
    printf(" 请输入您的密码 : ");
    while(1)
    {
        scanf("%s",u.password);
        for(int i=0; i<6; i++) //for循环和后面的if语句用于识别"again"，识别成功则按照用户的请求，返回上一级。
        {
            if(str2[i]==u.password[i])
                index05++;
            if(index05==6)
            {
                fclose(fp);
                return;
            }
        }
        fflush(stdin);
        if(check_string(u.password))//检查密码格式是否合规，若合规，跳出当前循环。否则要求用户重新输入密码。
            break;
        CLEAR
        printf("************您正在进行用户注册************\n\n提示: 密码包含特殊字符或密码太长, 请重新输入\n");
        printf("请输入您的用户名: %s\n",userid);
        printf(" 请输入您的密码 : \n");
    }

//键入姓名
    CLEAR
    printf("************您正在进行用户注册************\n\n提示: 姓名不能包含汉字及其他特殊字符\n");
    printf("请输入您的用户名: %s\n",userid);
    printf(" 请输入您的密码 : %s\n", u.password);
    printf(" 请输入您的姓名 : ");
    for(int i=0;i<32;i++)//先清空u.name[]
        u.name[i]='\000';
    while(1)
    {
        scanf("%s", u.name);
        if(check_string(u.name))//检查姓名是否合规
            break;
        CLEAR
        for(int i=0;i<64;i++)
            u.name[i]='\000';
        printf("************您正在进行用户注册************\n\n提示: 您输入的姓名包含特殊字符或姓名太长, 请重新输入!\n");
        printf("请输入您的用户名: %s\n",u.id);
        printf("请输入您的密码: %s\n",u.password);
        printf(" 请输入您的姓名 : ");
    }
    

//键入性别
    index01=1;
    printf("请输入您的性别(1.男, 2.女): ");
    while(index01)
    {
        while(1)
        {
            scanf("%s",str);
            fflush(stdin);
            if(str[1]=='\000')
                break;
            CLEAR
            printf("************您正在进行用户注册************\n\n提示: 输入有误, 请输入数字1或2\n");
            printf("请输入您的用户名: %s\n",u.id);
            printf("请输入您的密码: %s\n",u.password);
            printf(" 请输入您的姓名 : %s\n", u.name);
            printf("请输入您的性别(1.男, 2.女): ");
            str[1]='\000';
        }

        switch (str[0])
        {
        case '1':
            u.gender=1;//我们用整型储存性别信息。男1女2。
            index01=0;
            break;

        case '2':
            u.gender=2;
            index01=0;
            break;

        default:
            CLEAR
            printf("************您正在进行用户注册************\n\n提示: 输入有误, 请输入数字1或2\n");
            printf("请输入您的用户名: %s\n",u.id);
            printf("请输入您的密码: %s\n",u.password);
            printf(" 请输入您的姓名 : %s\n", u.name);
            printf("请输入您的性别(1.男, 2.女): ");
            break;
        }
    }

//键入年龄
    printf(" 请输入您的年龄 : ");
    while(1)
    {
        scanf("%d",&u.age);
        fflush(stdin);
        if(0<u.age && u.age<101)//年龄必须在
            break;
        CLEAR
        printf("************您正在进行用户注册************\n\n提示: 年龄输入有误,请输入1~100的数字\n");
        printf("请输入您的用户名: %s\n",u.id);
        printf(" 请输入您的密码 : %s\n",u.password);
        printf(" 请输入您的姓名 : %s\n", u.name);
        printf("请输入您的性别(1.男, 2.女): %d\n", u.gender);
        printf(" 请输入您的年龄 : ");
    }

//键入邮箱
    printf(" 请输入您的邮箱 : ");
    while(1)
    {
        for(int i=0;i<64;i++)//清空u.mail[]
            u.mail[i]='\000';
        scanf("%s",u.mail);
        fflush(stdin);
        if(u.mail[63]!='\000')//说明邮箱太长了
        {
            CLEAR
            printf("************您正在进行用户注册************\n\n提示: 邮箱输入太长啦。请重新输入\n");
            printf("请输入您的用户名: %s\n",u.id);
            printf(" 请输入您的密码 : %s\n",u.password);
            printf(" 请输入您的姓名 : %s\n", u.name);
            printf("请输入您的性别(1.男, 2.女): %d\n", u.gender);
            printf(" 请输入您的年龄 : %d\n",u.age);
            printf(" 请输入您的邮箱 : ");
            continue;
        }
        iat=0;
        idot=0;
        count=0;
        for(int i=0; i<64; i++)
        {
            if(u.mail[i]=='@')
            {
                iat=i;
                count++;
            }
        }
        for(int i=0; i<64; i++)
        {
            if(u.mail[i]=='.')
            {
                idot=i;
                count++;
            }
        }
        if(count==2 && idot!=0 && (iat+1)<idot && iat!=0 && u.mail[iat+1]!='\000')//符合邮箱格式：各存在一个“.”和“@”，并且它们不在开头和某位
            break;
        CLEAR
        
        printf("************您正在进行用户注册************\n\n提示: 邮箱格式有误! 输入正确的邮箱\n");
        printf("请输入您的用户名: %s\n",u.id);
        printf(" 请输入您的密码 : %s\n",u.password);
        printf(" 请输入您的姓名 : %s\n", u.name);
        printf("请输入您的性别(1.男, 2.女): %d\n", u.gender);
        printf(" 请输入您的年龄 : %d\n",u.age);
        printf(" 请输入您的邮箱 : ");
    }

    //写入电话号码
    printf("请输入您的电话号码: ");
    while(1)
    {
        scanf("%s",u.tel);
        fflush(stdin);
        for(int i=0;i<11;i++)
        {
            if(u.tel[i]>57 || u.tel[i]<48)//确保是数字
                index03++;
        }
        if(u.tel[11]=='\000' && index03==0)//只有11位
            break;

        CLEAR
        printf("************您正在进行用户注册************\n\n提示: 电话号码格式有误!请输入11位数字!\n");
        printf("请输入您的用户名: %s\n",u.id);
        printf(" 请输入您的密码 : %s\n",u.password);
        printf(" 请输入您的姓名 : %s\n", u.name);
        printf("请输入您的性别(1.男, 2.女): %d\n", u.gender);
        printf(" 请输入您的年龄 : %d\n",u.age);
        printf(" 请输入您的邮箱 : %s\n",u.mail);
        printf("请输入您的电话号码: ");
        u.tel[11]='\000';
    }

    
    index01=1;
    printf(" 请输入您的地址 :\n");
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
            printf("************您正在进行用户注册************\n\n提示: 地址信息太长,请重新输入!\n");
            printf("请输入您的用户名: %s\n",u.id);
            printf("请输入您的密码: %s\n",u.password);
            printf(" 请输入您的姓名 : %s\n", u.name);
            printf("请输入您的性别(1.男, 2.女): %d\n", u.gender);
            printf(" 请输入您的年龄 : %d\n",u.age);
            printf(" 请输入您的邮箱 : %s\n",u.mail);
            printf("请输入您的电话号码: %s\n",u.tel);
            printf(" 请输入您的地址 :\n");
            printf("1.海淀区  2.丰台区  3.西城区  4.其他  ");
            str[1]='\000';
        }

        switch (str[0])
        {
        case '1':
            u.address=1;
            index01=0;
            break;

        case '2':
            u.address=2;
            index01=0;
            break;

        case '3':
            u.address=3;
            index01=0;
            break;

        case '4':
            u.address=4;
            index01=0;
            break;

        default:
            CLEAR
            printf("************您正在进行用户注册************\n\n提示: 地址信息太长,请重新输入!\n");
            printf("请输入您的用户名: %s\n",u.id);
            printf("请输入您的密码: %s\n",u.password);
            printf(" 请输入您的姓名 : %s\n", u.name);
            printf("请输入您的性别(1.男, 2.女): %d\n", u.gender);
            printf(" 请输入您的年龄 : %d\n",u.age);
            printf(" 请输入您的邮箱 : %s\n",u.mail);
            printf("请输入您的电话号码: %s\n",u.tel);
            printf(" 请输入您的地址 :\n");
            printf("1.海淀区  2.丰台区  3.西城区  4.其他  ");
            break;
        }
    }
    
//存入文件
    fprintf(fp, "%s %s %s %d %d %s %s %d %d %.2lf\n", userid, u.password, u.name, u.gender, u.age, u.mail, u.tel, u.address, 0, 0.00);
    fclose(fp);
    index00=1;
    u.timez=0;
    u.val=0.00;
    YOU=u;
    printf("尊敬的 %s ",u.name);
    if(u.gender==1)
        printf("先生");
    if(u.gender==2)
        printf("女士");
    printf(", 您已完成注册, 请仔细核对您的个人信息。\n(按任意键结束注册并登陆您的账户)\n");
    fflush(stdin);
    getch();
    fflush(stdin);
    CLEAR
    return;
}
void UserLogin()
{
    FILE *fp;
    UserInfo v, test;                //v是遍历时候用，test记录用户输入
    int index06=0;                  //index06是一个中间变量，用于检查输入的用户名是否被注册过
    
    int index04=0, index05=0;     //这两组计数变量和数组是用于实现 顾客退出“用户登陆” 和 用户名重复时重新选择用户名 的功能   
    char str1[5]="exit";
    char str2[6]="again";
    
    str1[4]='\000';
    str2[5]='\000';
    
//打开文件  先用a+打开，若无，可自动生成一个文件。
    fp = fopen("Test_UserInfo05", "a+");
    if(fp == NULL)
    {
        printf("error:FILE000\n文件打开失败!\n");
        exit(1);
    }
    fclose(fp);
    while(1)
    {   
        Label1:
        //打开文件
        fp = fopen("Test_UserInfo05", "r");
        if(fp == NULL)
        {
            printf("error:FILE003\n文件打开失败!\n");
            exit(1);
        }

        CLEAR
        printf("********您已进入用户登陆/注册界面********\n\n提示: 输入未注册的用户名将自动为您注册,如需返回主菜单请输入exit\n");
        printf("请输入您的用户名: ");
        test.id[4]='\000';
        scanf("%s",test.id);
        
        index04=0;
        for(int i=0; i<5; i++)  //for循环用于识别"exit"
        {
            if(str1[i]==test.id[i])
                index04++;
        if(index04==5)
            {
                fclose(fp);
                CLEAR
                printf("******欢迎进入体育馆综合管理系统******\n\n提示: 请输入数字1~4\n");
                printf("1.用户界面\n");
                printf("2.管理员登陆\n");
                printf("3.管理员注册\n");
                printf("4.结束程序\n");
                return;
            }
        }
        
        while(1)//检查用户格式
        {
            
            if(check_username(test.id))
                break;
            printf("*********您正在进行用户登陆/注册*********\n\n提示: 输入有误, 用户名包含特殊字符或长度有误, 请输入6~11位数字和字母\n");
            printf("请输入您的用户名: \n");
            scanf("%s",test.id);
            fflush(stdin);
        }
    //检查用户名是否注册
        index06=0;
        while(fscanf(fp, "%s %s %s %d %d %s %s %d %d %lf",v.id, v.password, v.name, &v.gender, &v.age, v.mail, v.tel, &v.address, &v.timez, &v.val)!=EOF)
        {
            if(strcmp(v.id, test.id)==0)
            {
                index06=1;
                break;
            }
        }
                
        if(index06==0)   //index06为0说明该用户名未注册，则进入注册界面
        {
            fclose(fp);
            UserRegister(test.id);
            if(index00==1)        //说明注册成功，准许登陆
                return;
            goto Label1;
        }
        fclose(fp);
        CLEAR
        printf("*********您正在进行用户登陆/注册*********\n\n提示: 该用户名已被注册!(输入again可选择新的用户名)\n");
        printf("请输入您的用户名: %s\n", test.id);
        printf(" 请输入您的密码 : ");
        test.password[5]='\000';
        fflush(stdin);

        scanf("%s", test.password);
        index05=0;
        for(int i=0; i<6; i++) //for循环和后面的if语句用于识别"again"
        {
            if(str2[i]==test.password[i])
                index05++;
        }
        if(index05==6)
        {
            fclose(fp);
            continue;
        }

        while(1)
        {        
            if(strcmp(v.password, test.password)==0)
            {                    
                index00=1;
                YOU=v;
                CLEAR
                printf("尊敬的 %s ",v.name);
                if(v.gender==1)
                    printf("先生");
                if(v.gender==2)
                    printf("女士");
                printf(", 欢迎\n(按任意键继续)\n");
                fflush(stdin);
                getch();
                fflush(stdin);
                return;
            }
            index04=0;
            index05=0;
            test.password[4]='\000';
            test.password[5]='\000';                    
            CLEAR
            printf("*********您正在进行用户登陆/注册*********\n\n提示: 密码错误! 输入again用新的用户名登陆/注册, 输入exit返回主菜单\n");
            printf("请输入您的用户名: %s\n", test.id);
            printf(" 请输入您的密码 : ");
            scanf("%s",test.password);

            for(int i=0; i<6; i++) //for循环和后面的if语句用于识别"again"
            {
                if(str2[i]==test.password[i])
                    index05++;
            }
            if(index05==6)
                break;
            
            for(int i=0; i<5; i++)  //for循环用于识别"exit"
            {
                if(str1[i]==test.password[i])
                    index04++;
                if(index04==5)
                {
                    CLEAR
                    printf("******欢迎进入体育馆综合管理系统******\n\n提示: 请输入数字1~4\n");
                    printf("1.用户界面\n");
                    printf("2.管理员登陆\n");
                    printf("3.管理员注册\n");
                    printf("4.结束程序\n");
                    return;
                }
            }
        }
    }
}

void UserRsv()
{
    char dustbin[64];
    time_t timer00, timer01, timer02, timerx;
    struct tm currentTime0, currentTime1, currentTime2, currentTimex;//用于获取时间信息
    int Count=0;
    RsvInfo w, test, test2;
    w.client=YOU;
    FILE* fp;
    char str[2]={'\000','\000'};
    int index01=1;  //index01变量用于继续/终止登陆界面的循环。初始化为1,使得登陆界面一直进行。只有输入0才能使其值变为0，以终止循环，结束程序。
    
    int tiMez=0;
    int tiMe[3]={'\000', '\000', '\000'};
    FieldInfo f[5];
    PlaceInfo p[3];

    int ii=0;
    int numz=0;
    CLEAR
    
    //打开文件，先用a+打开，防止文件不存在导致报错
    fp = fopen("Test_RsvInfo01", "a+");
    if(fp == NULL)
    {
        printf("error:FILE002\n文件打开失败!\n");
        exit(1);
    }
    fclose(fp);

    //检查爽约次数
    if(w.client.timez>3)
    {
        printf("尊敬的 %s ",w.client.name);
            if(w.client.gender==1)
                printf("先生");
            if(w.client.gender==2)
                printf("女士");
        printf(",\n    很抱歉, 由于您的之前已有超过三次不良预约记录, 您当前无法进行体育场馆预约。\n\n(按任意键继续)\n");
        fflush(stdin);
        getch();
        CLEAR
        return;
    }
    
    CLEAR
    //询问用户本次预约几个场馆
    printf("******您正在进行场馆预约******\n\n");
    printf("您一次至多预约三个场地, 请输入本次预约场地的数量(输入数字1~3): ");
    while(index01)
    {
        
        while(1)
        {
            scanf("%s",str);
            fflush(stdin);
            if(str[1]=='\000')
                break;
            CLEAR
            printf("******您正在进行场馆预约******\n\n提示: 输入有误。请输入数字1~3\n");
            printf("您一次至多预约三个场地, 请输入本次预约场地的数量(输入数字1~3): ");
            str[1]='\000';
        }

        switch (str[0])
        {
        case '1':
            tiMez=1;
            index01=0;
            break;

        case '2':
            tiMez=2;
            index01=0;
            break;

        case '3':
            tiMez=3;
            index01=0;
            break;
        
        default:
            CLEAR
            printf("******您正在进行场馆预约******\n\n提示: 输入有误。请输入数字1~3\n");
            printf("您一次至多预约三个场地, 请输入本次预约场地的数量(输入数字1~3): ");
            break;
        }
    }

    //第一个场馆信息
    index01=1;
    printf("请输入您要预约的第一个场馆(1.健身房, 2.标准游泳馆, 3.足球场): ");
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
            printf("******您正在进行场馆预约******\n\n提示: 输入有误。请输入数字1~3\n");
            printf("请输入您要预约的第一个场馆(1.健身房, 2.标准游泳馆, 3.足球场): ");
            str[1]='\000';
        }

        switch (str[0])
        {
        case '1':
            tiMe[0]=1;
            index01=0;
            break;

        case '2':
            tiMe[0]=2;
            index01=0;
            break;

        case '3':
            tiMe[0]=3;
            index01=0;
            break;

        default:
            CLEAR
            printf("******您正在进行场馆预约******\n\n提示: 输入有误。请输入数字1~3\n");
            printf("请输入您要预约的第一个场馆(1.健身房, 2.标准游泳馆, 3.足球场): ");
            break;
        }
    }
    
    //第二个场馆信息
    printf("请输入您要预约的第二个场馆(1.健身房, 2.标准游泳馆, 3.足球场): ");
    index01=1;
    while(index01)
    {
        
        while(1)
        {   
            if(tiMez<2)
            {
                printf("无\n");
                break;
            }
            str[0]='\000';
            str[1]='\000';
            scanf("%s",str);
            fflush(stdin);
            if(str[1]=='\000')
                break;
            CLEAR
            printf("******您正在进行场馆预约******\n\n提示: 输入有误。请输入数字1~3\n");
            printf("请输入您要预约的第一个场馆(1.健身房, 2.标准游泳馆, 3.足球场): %d", tiMe[0]);
            printf("请输入您要预约的第二个场馆(1.健身房, 2.标准游泳馆, 3.足球场): ");
            str[1]='\000';
        }

        switch (str[0])
        {
        case '1':
            tiMe[1]=1;
            index01=0;
            break;

        case '2':
            tiMe[1]=2;
            index01=0;
            break;

        case '3':
            tiMe[1]=3;
            index01=0;
            break;

        default:
            CLEAR
            printf("******您正在进行场馆预约******\n\n提示: 输入有误。请输入数字1~3\n");
            printf("请输入您要预约的第一个场馆(1.健身房, 2.标准游泳馆, 3.足球场): %d", tiMe[0]);
            printf("请输入您要预约的第2个场馆(1.健身房, 2.标准游泳馆, 3.足球场): ");
            break;
        }
    }

    //第三个场馆信息
    printf("请输入您要预约的第三个场馆(1.健身房, 2.标准游泳馆, 3.足球场): ");
    index01=1;
    while(index01)
    {
        
        while(1)
        {   
            if(tiMez<3)
            {
                printf("无\n");
                break;
            }
            str[0]='\000';
            str[1]='\000';
            scanf("%s",str);
            fflush(stdin);
            if(str[1]=='\000')
                break;
            CLEAR
            printf("******您正在进行场馆预约******\n\n提示: 输入有误。请输入数字1~3\n");
            printf("请输入您要预约的第一个场馆(1.健身房, 2.标准游泳馆, 3.足球场): %d", tiMe[0]);
            printf("请输入您要预约的第二个场馆(1.健身房, 2.标准游泳馆, 3.足球场): %d", tiMe[1]);
            printf("请输入您要预约的第三个场馆(1.健身房, 2.标准游泳馆, 3.足球场): ");
            str[1]='\000';
        }

        switch (str[0])
        {
        case '1':
            tiMe[2]=1;
            index01=0;
            break;

        case '2':
            tiMe[2]=2;
            index01=0;
            break;

        case '3':
            tiMe[2]=3;
            index01=0;
            break;

        default:
            CLEAR
            printf("******您正在进行场馆预约******\n\n提示: 输入有误。请输入数字1~3\n");
            printf("请输入您要预约的第一个场馆(1.健身房, 2.标准游泳馆, 3.足球场): %d", tiMe[0]);
            printf("请输入您要预约的第二个场馆(1.健身房, 2.标准游泳馆, 3.足球场): %d", tiMe[1]);
            printf("请输入您要预约的第三个场馆(1.健身房, 2.标准游泳馆, 3.足球场): ");
            break;
        }
    }
    printf("\n(按任意键继续)");
    fflush(stdin);
    getch();
    CLEAR
    str[0]='\000';
    str[1]='\000';
    index01=1;
    
    //本次打开place文件是为了获知当前各个场馆下设几个场地
    fp = fopen("Test_Place01", "a+");
    if(fp == NULL)
    {
        printf("error:FILE005\n文件打开失败!\n");
        exit(1);
    }
    for(int i=0; i<3; i++)
        fscanf(fp, "%d %d", &p[i].ICcode1, &p[i].num);
    fclose(fp);
    
    label2:

    if(tiMe[Count]==1)
    {
        fp = fopen("Test_Field101", "a+");
        if(fp == NULL)
        {
            printf("error:FILE005\n文件打开失败!\n");
            exit(1);
        }
        for(int i=0; i<p[0].num; i++)    
            fscanf(fp, "%d %s %d %d %d %lf", &f[i].ICcode2, f[i].name, &f[i].EntranceAge, &f[i].MaxNum, &f[i].Area, &f[i].prize);

        fclose(fp);
        w.place.ICcode1=1;
    }
    if(tiMe[Count]==2)
    {
        fp = fopen("Test_Field201", "a+");
        if(fp == NULL)
        {
            printf("error:FILE005\n文件打开失败!\n");
            exit(1);
        }
        for(int i=0; i<p[1].num; i++)   
            fscanf(fp, "%d %s %d %d %d %lf", &f[i].ICcode2, f[i].name, &f[i].EntranceAge, &f[i].MaxNum, &f[i].Area, &f[i].prize);
        
        fclose(fp);
        w.place.ICcode1=2;
    }
    if(tiMe[Count]==3)
    {
        fp = fopen("Test_Field301", "a+");
        if(fp == NULL)
        {
            printf("error:FILE005\n文件打开失败!\n");
            exit(1);
        }
        for(int i=0; i<p[2].num; i++)   
            fscanf(fp, "%d %s %d %d %d %lf", &f[i].ICcode2, f[i].name, &f[i].EntranceAge, &f[i].MaxNum, &f[i].Area, &f[i].prize);
        
        fclose(fp);
        w.place.ICcode1=3;
    }

    str[0]='\000';
    str[1]='\000';
    index01=1;
    printf("******您正在进行场馆预约******\n\n");
    printf("您一共要求了%d次场馆预约, 正在为您处理第%d项预约\n", tiMez, Count+1);
    printf("您的第%d项预约场馆是在: ", Count+1);
    if(tiMe[Count]==1)
        printf("健身馆\n");
    if(tiMe[Count]==2)
        printf("游泳馆\n");
    if(tiMe[Count]==3)
        printf("足球馆\n");
    printf("请选择场地(");
    for(int i=0; i<p[tiMe[Count]-1].num; i++)
        printf("%d.%s  ", i+1, f[i].name);
    printf("): ");
    while(index01)
    {
        
        while(1)
        {
            scanf("%s",str);
            fflush(stdin);
            if(str[1]=='\000')
                break;
            str[1]='\000';
            CLEAR
            printf("******您正在进行场馆预约******\n\n");
            printf("提示: 输入有误, 请输入相应数字\n");
            printf("您的第一项预约场馆是在: ");
            if(tiMe[Count]==1)
                printf("健身馆\n");
            if(tiMe[Count]==2)
                printf("游泳馆\n");
            if(tiMe[Count]==3)
                printf("足球馆\n");
            printf("请选择场地(");
            for(int i=0; i<p[tiMe[Count]-1].num; i++)
                printf("%d.%s  ", i+1, f[i].name);
            printf("): ");
        }

        for(int i=0; i<p[tiMe[Count]-1].num; i++)
        {
            if(str[0]-'0'==f[i].ICcode2)
            {
                index01=0;
                w.field.ICcode2=f[i].ICcode2;
                break;
            }
        }
        CLEAR
        printf("******您正在进行场馆预约******\n\n");
        printf("提示: 输入有误, 请输入相应数字\n");
        printf("您的第一项预约场馆是在: ");
        if(tiMe[Count]==1)
            printf("健身馆\n");
        if(tiMe[Count]==2)
            printf("游泳馆\n");
        if(tiMe[Count]==3)
            printf("足球馆\n");
        printf("请选择场地(");
        for(int i=0; i<p[tiMe[Count]-1].num; i++)
            printf("%d.%s  ", i+1, f[i].name);
        printf("): ");
    }
    
    CLEAR
    printf("******您正在进行场馆预约******\n\n");
    printf("您一要求了%d次场馆预约, 正在为您处理第1项预约\n");
    printf("您的第一项预约场馆是在: ");
    if(tiMe[Count]==1)
        printf("健身馆\n");
    if(tiMe[Count]==2)
        printf("游泳馆\n");
    if(tiMe[Count]==3)
        printf("足球馆\n");
    printf("请选择场地(");
    for(int i=0; i<p[tiMe[Count]-1].num; i++)
        printf("%d.%s  ", i+1, f[i].name);
    printf("): ");
    printf("%d\n", w.field.ICcode2);

    timer00=time(NULL);
    timer00+=3600*8;
    gmtime_s(&currentTime0, &timer00);        //当前时间
    timer01=timer00+604800;
    timer02=timer00+604800*2;
    gmtime_s(&currentTime1, &timer01);   //一周后的时间
    gmtime_s(&currentTime2, &timer02);   //两周后的时间
    CLEAR
    printf("******您正在选择预约日期******\n\n提示: 请输入数字1~7\n");
    printf("现在是%d年%d月%d日, 您可以选择%d年%d月%d日至%d年%d月%d日之间的日期进行预约。\n", currentTime0.tm_year+1900, currentTime0.tm_mon+1, currentTime0.tm_mday, currentTime1.tm_year+1900, currentTime1.tm_mon+1, currentTime1.tm_mday+1, currentTime2.tm_year+1900, currentTime2.tm_mon+1, currentTime2.tm_mday);
    printf("请输入您需要预约的日期: \n");
    timerx=timer00;
    for(int i=1; i<8; i++)
    {
        timerx+=3600*24;
        gmtime_s(&currentTimex, &timerx);
        printf("%d.%d年%d月%d日\n", i, currentTimex.tm_year+1900, currentTimex.tm_mon+1, currentTimex.tm_mday);
    }

    //输入日期
    index01=1;
    while(index01)
    {
        while(1)
        {
            str[1]='\000';
            scanf("%s",str);
            fflush(stdin);
            if(str[1]=='\000')
                break;
            CLEAR
            printf("******您正在选择预约日期******\n\n提示: 输入有误, 请输入数字1~7\n");
            printf("\n现在是%d年%d月%d日, 您可以选择%d年%d月%d日至%d年%d月%d日之间的日期进行预约。\n", currentTime0.tm_year+1900, currentTime0.tm_mon+1, currentTime0.tm_mday, currentTime1.tm_year+1900, currentTime1.tm_mon+1, currentTime1.tm_mday+1, currentTime2.tm_year+1900, currentTime2.tm_mon+1, currentTime2.tm_mday);
            printf("请输入您需要预约的日期: \n");
            timerx=timer00;
            for(int i=1; i<8; i++)
            {
                timerx+=3600*24;
                gmtime_s(&currentTimex, &timerx);
                printf("%d.%d年%d月%d日\n", i, currentTimex.tm_year+1900, currentTimex.tm_mon+1, currentTimex.tm_mday);
            }
        }

        switch (str[0])
        {
        case '1':
            timerx=timer00+1*24*3600;
            gmtime_s(&currentTimex, &timerx);
            w.ExpTime.year=currentTimex.tm_year+1900;
            w.ExpTime.month=currentTimex.tm_mon+1;
            w.ExpTime.daym=currentTimex.tm_mday;
            index01=0;
            break;

        case '2':
            timerx=timer00+2*24*3600;
            gmtime_s(&currentTimex, &timerx);
            w.ExpTime.year=currentTimex.tm_year+1900;
            w.ExpTime.month=currentTimex.tm_mon+1;
            w.ExpTime.daym=currentTimex.tm_mday;
            index01=0;
            break;

        case '3':
            timerx=timer00+3*24*3600;
            gmtime_s(&currentTimex, &timerx);
            w.ExpTime.year=currentTimex.tm_year+1900;
            w.ExpTime.month=currentTimex.tm_mon+1;
            w.ExpTime.daym=currentTimex.tm_mday;
            index01=0;
            break;
        
        case '4':
            timerx=timer00+4*24*3600;
            gmtime_s(&currentTimex, &timerx);
            w.ExpTime.year=currentTimex.tm_year+1900;
            w.ExpTime.month=currentTimex.tm_mon+1;
            w.ExpTime.daym=currentTimex.tm_mday;
            index01=0;
            break;

        case '5':
            timerx=timer00+5*24*3600;
            gmtime_s(&currentTimex, &timerx);
            w.ExpTime.year=currentTimex.tm_year+1900;
            w.ExpTime.month=currentTimex.tm_mon+1;
            w.ExpTime.daym=currentTimex.tm_mday;
            index01=0;
            break;

        case '6':
            timerx=timer00+6*24*3600;
            gmtime_s(&currentTimex, &timerx);
            w.ExpTime.year=currentTimex.tm_year+1900;
            w.ExpTime.month=currentTimex.tm_mon+1;
            w.ExpTime.daym=currentTimex.tm_mday;
            index01=0;
            break;

        case '7':
            timerx=timer00+7*24*3600;
            gmtime_s(&currentTimex, &timerx);
            w.ExpTime.year=currentTimex.tm_year+1900;
            w.ExpTime.month=currentTimex.tm_mon+1;
            w.ExpTime.daym=currentTimex.tm_mday;
            index01=0;
            break;

        default:
            CLEAR
            printf("******您正在选择预约日期******\n\n提示: 输入有误, 请输入数字1~7\n");
            printf("\n现在是%d年%d月%d日, 您可以选择%d年%d月%d日至%d年%d月%d日之间的日期进行预约。\n", currentTime0.tm_year+1900, currentTime0.tm_mon+1, currentTime0.tm_mday, currentTime1.tm_year+1900, currentTime1.tm_mon+1, currentTime1.tm_mday+1, currentTime2.tm_year+1900, currentTime2.tm_mon+1, currentTime2.tm_mday);
            printf("请输入您需要预约的日期: \n");
            timerx=timer00;
            for(int i=1; i<8; i++)
            {
                timerx+=3600*24;
                gmtime_s(&currentTimex, &timerx);
                printf("%d.%d年%d月%d日\n", i, currentTimex.tm_year+1900, currentTimex.tm_mon+1, currentTimex.tm_mday);
            }
            break;
        }
    }

    //输入时间
    CLEAR
    printf("******您正在选择预约时间******\n\n提示: 请输入字母a~p\n");
    printf("场馆开放时间为6:00~22:00, 请告诉我们您期望几点开始使用场馆: \n\n");
    printf("a.六  点      e.十  点      i.十四点      m.十八点\n");
    printf("b.七  点      f.十一点      j.十五点      n.十九点\n");
    printf("c.八  点      g.十二点      k.十六点      o.二十点\n");
    printf("d.九  点      h.十三点      l.十七点      p.廿一点\n\n(只能选择整点, 如有不便, 敬请谅解)");
    index01=1;
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
            printf("******您正在选择预约时间******\n\n提示: 输入有误, 请输入字母a~p\n");
            printf("场馆开放时间为6:00~22:00, 请告诉我们您期望几点开始使用场馆: \n\n");
            printf("a.六  点      e.十  点      i.十四点      m.十八点\n");
            printf("b.七  点      f.十一点      j.十五点      n.十九点\n");
            printf("c.八  点      g.十二点      k.十六点      o.二十点\n");
            printf("d.九  点      h.十三点      l.十七点      p.廿一点\n\n(只能选择整点, 如有不便, 敬请谅解)");
            str[1]='\000';
        }

        switch (str[0])
        {
        case 'A':
        case 'a':
            w.ExpTime.hour=6;
            index01=0;
            break;

        case 'B':
        case 'b':
            w.ExpTime.hour=7;
            index01=0;
            break;

        case 'C':
        case 'c':
            w.ExpTime.hour=8;
            index01=0;
            break;

        case 'D':
        case 'd':
            w.ExpTime.hour=9;
            index01=0;
            break;

        case 'E':
        case 'e':
            w.ExpTime.hour=10;
            index01=0;
            break;

        case 'F':
        case 'f':
            w.ExpTime.hour=11;
            index01=0;
            break;

        case 'G':
        case 'g':
            w.ExpTime.hour=12;
            index01=0;
            break;

        case 'H':
        case 'h':
            w.ExpTime.hour=13;
            index01=0;
            break;

        case 'I':
        case 'i':
            w.ExpTime.hour=14;
            index01=0;
            break;

        case 'J':
        case 'j':
            w.ExpTime.hour=15;
            index01=0;
            break;

        case 'K':
        case 'k':
            w.ExpTime.hour=16;
            index01=0;
            break;

        case 'L':
        case 'l':
            w.ExpTime.hour=17;
            index01=0;
            break;

        case 'M':
        case 'm':
            w.ExpTime.hour=18;
            index01=0;
            break;

        case 'N':
        case 'n':
            w.ExpTime.hour=19;
            index01=0;
            break;

        case 'O':
        case 'o':
            w.ExpTime.hour=20;
            index01=0;
            break;

        case 'P':
        case 'p':
            w.ExpTime.hour=21;
            index01=0;
            break;

        default:
            CLEAR
            printf("******您正在选择预约时间******\n\n提示: 输入有误, 请输入字母a~p\n");
            printf("场馆开放时间为6:00~22:00, 请告诉我们您期望几点开始使用场馆: \n\n");
            printf("a.六  点      e.十  点      i.十四点      m.十八点\n");
            printf("b.七  点      f.十一点      j.十五点      n.十九点\n");
            printf("c.八  点      g.十二点      k.十六点      o.二十点\n");
            printf("d.九  点      h.十三点      l.十七点      p.廿一点\n\n(只能选择整点, 如有不便, 敬请谅解)");
            break;
        }
    }
    
    
    fp = fopen("Test_RsvInfo01", "a+");
    if(fp == NULL)
    {
        printf("error:FILE005\n文件打开失败!\n");
        exit(1);
    }
    fclose(fp);
    
    
    //输入时长
    int count=0, countN1=0, countN2=0, countN3=0, countN4=0;
    CLEAR
    printf("******您正在选择预约时长******\n\n提示: 请输入数字1~4\n");
    printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
    index01=1;
    while(index01)
    {
        while(1)
        {
            str[0]='\000';
            str[1]='\000';
            fflush(stdin);
            scanf("%s",str);
            fflush(stdin);
            if(str[1]=='\000')
                break;
            CLEAR
            printf("******您正在选择预约时长******\n\n提示: 输入有误, 请输入数字0~4\n");
            printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
            str[1]='\000';
        }

        switch (str[0])
        {
        case '1':
            if(w.ExpTime.hour+1>22)
            {
                CLEAR
                printf("******您正在选择预约时长******\n\n提示: 所选时长不可用, 预约结束时间不可超过22点\n");
                printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
                break;
            }
            w.duration=1;
            fp = fopen("Test_RsvInfo01", "r");
            if(fp == NULL)
            {
                printf("error:FILE005\n文件打开失败!\n");
                exit(1);
            }
            for(int i=0; fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒", test2.client.id, &test2.place.ICcode1, &test2.field.ICcode2, &test2.duration, &test2.ExpTime.year, &test2.ExpTime.month, &test2.ExpTime.daym, &test2.ExpTime.hour, &test2.RsvTime.year, &test2.RsvTime.month, &test2.RsvTime.daym, &test2.RsvTime.hour, &test2.RsvTime.min, &test2.RsvTime.sec)!=EOF; i++)
            {
                if(strcmp(test2.client.id, w.client.id)==0)
                {
                    if(w.ExpTime.daym==test2.ExpTime.daym)
                    {
                        if(w.ExpTime.hour+w.duration>test2.ExpTime.hour || test2.ExpTime.hour+test2.duration>w.ExpTime.hour)
                            {
                                count++;
                                break;
                            }
                    }
                }
            }
            fclose(fp);
            if(count!=0)
            {
                count=0;
                CLEAR
                printf("******您正在选择预约时长******\n\n提示: 检查到该预约与之前已有的预订有时间冲突, 请您换一个时长或者取消本次预约\n");
                printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
                break;
            }
            
            fp = fopen("Test_RsvInfo01", "r");
            if(fp == NULL)
            {
                printf("error:FILE005\n文件打开失败!\n");
                exit(1);
            }
            for(int i=0; fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒", test2.client.id, &test2.place.ICcode1, &test2.field.ICcode2, &test2.duration, &test2.ExpTime.year, &test2.ExpTime.month, &test2.ExpTime.daym, &test2.ExpTime.hour, &test2.RsvTime.year, &test2.RsvTime.month, &test2.RsvTime.daym, &test2.RsvTime.hour, &test2.RsvTime.min, &test2.RsvTime.sec)!=EOF; i++)
            {
                if(w.place.ICcode1==test2.place.ICcode1 && w.field.ICcode2==test2.field.ICcode2)
                {
                    if(w.ExpTime.year==test2.ExpTime.year && w.ExpTime.month==test2.ExpTime.month && w.ExpTime.daym==test2.ExpTime.daym)
                    {
                        if(test2.duration==1 && test2.ExpTime.hour==w.ExpTime.hour)
                            countN1++;
                        if(test2.duration==2 && (test2.ExpTime.hour==w.ExpTime.hour || test2.ExpTime.hour+1==w.ExpTime.hour))
                            countN1++;
                        if(test2.duration==3 && (test2.ExpTime.hour==w.ExpTime.hour || test2.ExpTime.hour+1==w.ExpTime.hour || test2.ExpTime.hour+2==w.ExpTime.hour))
                            countN1++;
                        if(test2.duration==4 && (test2.ExpTime.hour==w.ExpTime.hour || test2.ExpTime.hour+1==w.ExpTime.hour || test2.ExpTime.hour+2==w.ExpTime.hour || test2.ExpTime.hour+3==w.ExpTime.hour))
                            countN1++;
                    }
                }
            }
            fclose(fp);
            if(countN1>f[w.field.ICcode2-1].MaxNum-1)
            {
                CLEAR
                printf("******您正在选择预约时长******\n\n提示: 检查到该场馆当日%d时至%d时人数已满, 请您换一个时长或者取消本次预约\n", w.ExpTime.hour, w.ExpTime.hour+1);
                printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
                break;
            }

            if(w.client.val<w.duration*f[w.field.ICcode2-1].prize)
            {
                CLEAR
                printf("尊敬的 %s ",w.client.name);
                if(w.client.gender==1)
                    printf("先生");
                if(w.client.gender==2)
                    printf("女士");
                printf(",    很抱歉, 您的余额不足以完成本次支付。\n    本次预约需要花费:%.2lf元, 您的余额为:%.2lf元。\n\n(按任意键继续)", w.duration*f[w.field.ICcode2-1].prize, w.client.val);
                fflush(stdin);
                getch();
                fflush(stdin);
                CLEAR
                index01=0;
                countN1=0, countN2=0, countN3=0, countN4=0;
                break;
            }
            w.client.val-=w.duration*f[w.field.ICcode2-1].prize;
            YOU.val=w.client.val;
            countN1=0, countN2=0, countN3=0, countN4=0;
            index01=0;
            break;

        case '2':
            if(w.ExpTime.hour+2>22)
            {
                CLEAR
                printf("******您正在选择预约时长******\n\n提示: 所选时长不可用, 预约结束时间不可超过22点\n");
                printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
                break;
            }
            w.duration=2;

            fp = fopen("Test_RsvInfo01", "r");
            if(fp == NULL)
            {
                printf("error:FILE005\n文件打开失败!\n");
                exit(1);
            }
            for(int i=0; fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒", test2.client.id, &test2.place.ICcode1, &test2.field.ICcode2, &test2.duration, &test2.ExpTime.year, &test2.ExpTime.month, &test2.ExpTime.daym, &test2.ExpTime.hour, &test2.RsvTime.year, &test2.RsvTime.month, &test2.RsvTime.daym, &test2.RsvTime.hour, &test2.RsvTime.min, &test2.RsvTime.sec)!=EOF; i++)
            {
                if(strcmp(test2.client.id, w.client.id)==0)
                {
                    if(w.ExpTime.daym==test2.ExpTime.daym)
                    {
                        if(w.ExpTime.hour+w.duration>test2.ExpTime.hour || test2.ExpTime.hour+test2.duration>w.ExpTime.hour)
                            {
                                count++;
                                break;
                            }
                    }
                }
            }
            fclose(fp);
            if(count!=0)
            {
                count=0;
                CLEAR
                printf("******您正在选择预约时长******\n\n提示: 检查到该预约与之前已有的预订有时间冲突, 请您换一个时长或者取消本次预约\n");
                printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
                break;
            }
            
            fp = fopen("Test_RsvInfo01", "r");
            if(fp == NULL)
            {
                printf("error:FILE005\n文件打开失败!\n");
                exit(1);
            }
            for(int i=0; fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒", test2.client.id, &test2.place.ICcode1, &test2.field.ICcode2, &test2.duration, &test2.ExpTime.year, &test2.ExpTime.month, &test2.ExpTime.daym, &test2.ExpTime.hour, &test2.RsvTime.year, &test2.RsvTime.month, &test2.RsvTime.daym, &test2.RsvTime.hour, &test2.RsvTime.min, &test2.RsvTime.sec)!=EOF; i++)
            {
                if(w.place.ICcode1==test2.place.ICcode1 && w.field.ICcode2==test2.field.ICcode2)
                {
                    if(w.ExpTime.year==test2.ExpTime.year && w.ExpTime.month==test2.ExpTime.month && w.ExpTime.daym==test2.ExpTime.daym)
                    {
                        if(test2.duration==1 && test2.ExpTime.hour==w.ExpTime.hour)
                            countN1++;
                        if(test2.duration==2 && (test2.ExpTime.hour==w.ExpTime.hour || test2.ExpTime.hour+1==w.ExpTime.hour))
                            countN1++;
                        if(test2.duration==3 && (test2.ExpTime.hour==w.ExpTime.hour || test2.ExpTime.hour+1==w.ExpTime.hour || test2.ExpTime.hour+2==w.ExpTime.hour))
                            countN1++;
                        if(test2.duration==4 && (test2.ExpTime.hour==w.ExpTime.hour || test2.ExpTime.hour+1==w.ExpTime.hour || test2.ExpTime.hour+2==w.ExpTime.hour || test2.ExpTime.hour+3==w.ExpTime.hour))
                            countN1++;
                        if(test2.duration==1 && test2.ExpTime.hour==w.ExpTime.hour+1)
                            countN2++;
                        if(test2.duration==2 && (test2.ExpTime.hour==w.ExpTime.hour+1 || test2.ExpTime.hour+1==w.ExpTime.hour+1))
                            countN2++;
                        if(test2.duration==3 && (test2.ExpTime.hour==w.ExpTime.hour+1 || test2.ExpTime.hour+1==w.ExpTime.hour+1 || test2.ExpTime.hour+2==w.ExpTime.hour+1))
                            countN2++;
                        if(test2.duration==4 && (test2.ExpTime.hour==w.ExpTime.hour+1 || test2.ExpTime.hour+1==w.ExpTime.hour+1 || test2.ExpTime.hour+2==w.ExpTime.hour+1 || test2.ExpTime.hour+3==w.ExpTime.hour+1))
                            countN2++;
                    }
                }
            }
            fclose(fp);
            if(countN1>f[w.field.ICcode2-1].MaxNum-1)
            {
                CLEAR
                printf("******您正在选择预约时长******\n\n提示: 检查到该场馆当日%d时至%d时人数已满, 请您换一个时长或者取消本次预约\n", w.ExpTime.hour, w.ExpTime.hour+1);
                printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
                break;
            }
            if(countN2>f[w.field.ICcode2-1].MaxNum-1)
            {
                CLEAR
                printf("******您正在选择预约时长******\n\n提示: 检查到该场馆当日%d时至%d时人数已满, 请您换一个时长或者取消本次预约\n", w.ExpTime.hour+1, w.ExpTime.hour+2);
                printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
                break;
            }
            if(w.client.val<w.duration*f[w.field.ICcode2-1].prize)
            {
                CLEAR
                printf("尊敬的 %s ",w.client.name);
                if(w.client.gender==1)
                    printf("先生");
                if(w.client.gender==2)
                    printf("女士");
                printf(",    很抱歉, 您的余额不足以完成本次支付。\n    本次预约需要花费:%.2lf元, 您的余额为:%.2lf元。\n\n(按任意键继续)", w.duration*f[w.field.ICcode2-1].prize, w.client.val);
                fflush(stdin);
                getch();
                fflush(stdin);
                CLEAR
                index01=0;
                countN1=0, countN2=0, countN3=0, countN4=0;
                break;
            }
            
            countN1=0, countN2=0, countN3=0, countN4=0;
            index01=0;
            w.client.val-=w.duration*f[w.field.ICcode2-1].prize;
            YOU.val=w.client.val;
            break;

        case '3':
            if(w.ExpTime.hour+3>22)
            {
                CLEAR
                printf("******您正在选择预约时长******\n\n提示: 所选时长不可用, 预约结束时间不可超过22点\n");
                printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
                break;
            }
            w.duration=3;

            fp = fopen("Test_RsvInfo01", "r");
            if(fp == NULL)
            {
                printf("error:FILE005\n文件打开失败!\n");
                exit(1);
            }
            for(int i=0; fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒", test2.client.id, &test2.place.ICcode1, &test2.field.ICcode2, &test2.duration, &test2.ExpTime.year, &test2.ExpTime.month, &test2.ExpTime.daym, &test2.ExpTime.hour, &test2.RsvTime.year, &test2.RsvTime.month, &test2.RsvTime.daym, &test2.RsvTime.hour, &test2.RsvTime.min, &test2.RsvTime.sec)!=EOF; i++)
            {
                if(strcmp(test2.client.id, w.client.id)==0)
                {
                    if(w.ExpTime.daym==test2.ExpTime.daym)
                    {
                        if(w.ExpTime.hour+w.duration>test2.ExpTime.hour || test2.ExpTime.hour+test2.duration>w.ExpTime.hour)
                            {
                                count++;
                                break;
                            }
                    }
                }
            }
            fclose(fp);
            if(count!=0)
            {
                count=0;
                CLEAR
                printf("******您正在选择预约时长******\n\n提示: 检查到该预约与之前已有的预订有时间冲突, 请您换一个时长或者取消本次预约\n");
                printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
                break;
            }
            
            fp = fopen("Test_RsvInfo01", "r");
            if(fp == NULL)
            {
                printf("error:FILE005\n文件打开失败!\n");
                exit(1);
            }
            for(int i=0; fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒", test2.client.id, &test2.place.ICcode1, &test2.field.ICcode2, &test2.duration, &test2.ExpTime.year, &test2.ExpTime.month, &test2.ExpTime.daym, &test2.ExpTime.hour, &test2.RsvTime.year, &test2.RsvTime.month, &test2.RsvTime.daym, &test2.RsvTime.hour, &test2.RsvTime.min, &test2.RsvTime.sec)!=EOF; i++)
            {
                if(w.place.ICcode1==test2.place.ICcode1 && w.field.ICcode2==test2.field.ICcode2)
                {
                    if(w.ExpTime.year==test2.ExpTime.year && w.ExpTime.month==test2.ExpTime.month && w.ExpTime.daym==test2.ExpTime.daym)
                    {
                        if(test2.duration==1 && test2.ExpTime.hour==w.ExpTime.hour)
                            countN1++;
                        if(test2.duration==2 && (test2.ExpTime.hour==w.ExpTime.hour || test2.ExpTime.hour+1==w.ExpTime.hour))
                            countN1++;
                        if(test2.duration==3 && (test2.ExpTime.hour==w.ExpTime.hour || test2.ExpTime.hour+1==w.ExpTime.hour || test2.ExpTime.hour+2==w.ExpTime.hour))
                            countN1++;
                        if(test2.duration==4 && (test2.ExpTime.hour==w.ExpTime.hour || test2.ExpTime.hour+1==w.ExpTime.hour || test2.ExpTime.hour+2==w.ExpTime.hour || test2.ExpTime.hour+3==w.ExpTime.hour))
                            countN1++;
                        if(test2.duration==1 && test2.ExpTime.hour==w.ExpTime.hour+1)
                            countN2++;
                        if(test2.duration==2 && (test2.ExpTime.hour==w.ExpTime.hour+1 || test2.ExpTime.hour+1==w.ExpTime.hour+1))
                            countN2++;
                        if(test2.duration==3 && (test2.ExpTime.hour==w.ExpTime.hour+1 || test2.ExpTime.hour+1==w.ExpTime.hour+1 || test2.ExpTime.hour+2==w.ExpTime.hour+1))
                            countN2++;
                        if(test2.duration==4 && (test2.ExpTime.hour==w.ExpTime.hour+1 || test2.ExpTime.hour+1==w.ExpTime.hour+1 || test2.ExpTime.hour+2==w.ExpTime.hour+1 || test2.ExpTime.hour+3==w.ExpTime.hour+1))
                            countN2++;
                        if(test2.duration==1 && test2.ExpTime.hour==w.ExpTime.hour+2)
                            countN3++;
                        if(test2.duration==2 && (test2.ExpTime.hour==w.ExpTime.hour+2 || test2.ExpTime.hour+1==w.ExpTime.hour+2))
                            countN3++;
                        if(test2.duration==3 && (test2.ExpTime.hour==w.ExpTime.hour+2 || test2.ExpTime.hour+1==w.ExpTime.hour+2 || test2.ExpTime.hour+2==w.ExpTime.hour+2))
                            countN3++;
                        if(test2.duration==4 && (test2.ExpTime.hour==w.ExpTime.hour+2 || test2.ExpTime.hour+1==w.ExpTime.hour+2 || test2.ExpTime.hour+2==w.ExpTime.hour+2 || test2.ExpTime.hour+3==w.ExpTime.hour+2))
                            countN3++;
                    }
                }
            }
            fclose(fp);
            if(countN1>f[w.field.ICcode2-1].MaxNum-1)
            {
                CLEAR
                printf("******您正在选择预约时长******\n\n提示: 检查到该场馆当日%d时至%d时人数已满, 请您换一个时长或者取消本次预约\n", w.ExpTime.hour, w.ExpTime.hour+1);
                printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
                break;
            }
            if(countN2>f[w.field.ICcode2-1].MaxNum-1)
            {
                CLEAR
                printf("******您正在选择预约时长******\n\n提示: 检查到该场馆当日%d时至%d时人数已满, 请您换一个时长或者取消本次预约\n", w.ExpTime.hour+1, w.ExpTime.hour+2);
                printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
                break;
            }
            if(countN3>f[w.field.ICcode2-1].MaxNum-1)
            {
                CLEAR
                printf("******您正在选择预约时长******\n\n提示: 检查到该场馆当日%d时至%d时人数已满, 请您换一个时长或者取消本次预约\n", w.ExpTime.hour+2, w.ExpTime.hour+3);
                printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
                break;
            }
            if(w.client.val<w.duration*f[w.field.ICcode2-1].prize)
            {
                CLEAR
                printf("尊敬的 %s ",w.client.name);
                if(w.client.gender==1)
                    printf("先生");
                if(w.client.gender==2)
                    printf("女士");
                printf(",    很抱歉, 您的余额不足以完成本次支付。\n    本次预约需要花费:%.2lf元, 您的余额为:%.2lf元。\n\n(按任意键继续)", w.duration*f[w.field.ICcode2-1].prize, w.client.val);
                fflush(stdin);
                getch();
                fflush(stdin);
                CLEAR
                index01=0;
                countN1=0, countN2=0, countN3=0, countN4=0;
                break;
            }
            

            countN1=0, countN2=0, countN3=0, countN4=0;

            index01=0;
            w.client.val-=w.duration*f[w.field.ICcode2-1].prize;
            YOU.val=w.client.val;
            break;

        case '4':
            if(w.ExpTime.hour+4>22)
            {
                CLEAR
                printf("******您正在选择预约时长******\n\n提示: 所选时长不可用, 预约结束时间不可超过22点\n");
                printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
                break;
            }
            w.duration=4;

            fp = fopen("Test_RsvInfo01", "r");
            if(fp == NULL)
            {
                printf("error:FILE005\n文件打开失败!\n");
                exit(1);
            }
            for(int i=0; fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒", test2.client.id, &test2.place.ICcode1, &test2.field.ICcode2, &test2.duration, &test2.ExpTime.year, &test2.ExpTime.month, &test2.ExpTime.daym, &test2.ExpTime.hour, &test2.RsvTime.year, &test2.RsvTime.month, &test2.RsvTime.daym, &test2.RsvTime.hour, &test2.RsvTime.min, &test2.RsvTime.sec)!=EOF; i++)
            {
                if(strcmp(test2.client.id, w.client.id)==0)
                {
                    if(w.ExpTime.daym==test2.ExpTime.daym)
                    {
                        if(w.ExpTime.hour+w.duration>test2.ExpTime.hour || test2.ExpTime.hour+test2.duration>w.ExpTime.hour)
                            {
                                count++;
                                break;
                            }
                    }
                }
            }
            fclose(fp);
            if(count!=0)
            {
                count=0;
                CLEAR
                printf("******您正在选择预约时长******\n\n提示: 检查到该预约与之前已有的预订有时间冲突, 请您换一个时长或者取消本次预约\n");
                printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
                break;
            }
            
            fp = fopen("Test_RsvInfo01", "r");
            if(fp == NULL)
            {
                printf("error:FILE005\n文件打开失败!\n");
                exit(1);
            }
            for(int i=0; fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒", test2.client.id, &test2.place.ICcode1, &test2.field.ICcode2, &test2.duration, &test2.ExpTime.year, &test2.ExpTime.month, &test2.ExpTime.daym, &test2.ExpTime.hour, &test2.RsvTime.year, &test2.RsvTime.month, &test2.RsvTime.daym, &test2.RsvTime.hour, &test2.RsvTime.min, &test2.RsvTime.sec)!=EOF; i++)
            {
                if(w.place.ICcode1==test2.place.ICcode1 && w.field.ICcode2==test2.field.ICcode2)
                {
                    if(w.ExpTime.year==test2.ExpTime.year && w.ExpTime.month==test2.ExpTime.month && w.ExpTime.daym==test2.ExpTime.daym)
                    {
                        if(test2.duration==1 && test2.ExpTime.hour==w.ExpTime.hour)
                            countN1++;
                        if(test2.duration==2 && (test2.ExpTime.hour==w.ExpTime.hour || test2.ExpTime.hour+1==w.ExpTime.hour))
                            countN1++;
                        if(test2.duration==3 && (test2.ExpTime.hour==w.ExpTime.hour || test2.ExpTime.hour+1==w.ExpTime.hour || test2.ExpTime.hour+2==w.ExpTime.hour))
                            countN1++;
                        if(test2.duration==4 && (test2.ExpTime.hour==w.ExpTime.hour || test2.ExpTime.hour+1==w.ExpTime.hour || test2.ExpTime.hour+2==w.ExpTime.hour || test2.ExpTime.hour+3==w.ExpTime.hour))
                            countN1++;
                        if(test2.duration==1 && test2.ExpTime.hour==w.ExpTime.hour+1)
                            countN2++;
                        if(test2.duration==2 && (test2.ExpTime.hour==w.ExpTime.hour+1 || test2.ExpTime.hour+1==w.ExpTime.hour+1))
                            countN2++;
                        if(test2.duration==3 && (test2.ExpTime.hour==w.ExpTime.hour+1 || test2.ExpTime.hour+1==w.ExpTime.hour+1 || test2.ExpTime.hour+2==w.ExpTime.hour+1))
                            countN2++;
                        if(test2.duration==4 && (test2.ExpTime.hour==w.ExpTime.hour+1 || test2.ExpTime.hour+1==w.ExpTime.hour+1 || test2.ExpTime.hour+2==w.ExpTime.hour+1 || test2.ExpTime.hour+3==w.ExpTime.hour+1))
                            countN2++;
                        if(test2.duration==1 && test2.ExpTime.hour==w.ExpTime.hour+2)
                            countN3++;
                        if(test2.duration==2 && (test2.ExpTime.hour==w.ExpTime.hour+2 || test2.ExpTime.hour+1==w.ExpTime.hour+2))
                            countN3++;
                        if(test2.duration==3 && (test2.ExpTime.hour==w.ExpTime.hour+2 || test2.ExpTime.hour+1==w.ExpTime.hour+2 || test2.ExpTime.hour+2==w.ExpTime.hour+2))
                            countN3++;
                        if(test2.duration==4 && (test2.ExpTime.hour==w.ExpTime.hour+2 || test2.ExpTime.hour+1==w.ExpTime.hour+2 || test2.ExpTime.hour+2==w.ExpTime.hour+2 || test2.ExpTime.hour+3==w.ExpTime.hour+2))
                            countN3++;
                        if(test2.duration==1 && test2.ExpTime.hour==w.ExpTime.hour+3)
                            countN4++;
                        if(test2.duration==2 && (test2.ExpTime.hour==w.ExpTime.hour+3 || test2.ExpTime.hour+1==w.ExpTime.hour+3))
                            countN4++;
                        if(test2.duration==3 && (test2.ExpTime.hour==w.ExpTime.hour+3 || test2.ExpTime.hour+1==w.ExpTime.hour+3 || test2.ExpTime.hour+2==w.ExpTime.hour+3))
                            countN4++;
                        if(test2.duration==4 && (test2.ExpTime.hour==w.ExpTime.hour+3 || test2.ExpTime.hour+1==w.ExpTime.hour+3 || test2.ExpTime.hour+2==w.ExpTime.hour+3 || test2.ExpTime.hour+3==w.ExpTime.hour+3))
                            countN4++;
                    }
                }
            }
            fclose(fp);
            if(countN1>f[w.field.ICcode2-1].MaxNum-1)
            {
                CLEAR
                printf("******您正在选择预约时长******\n\n提示: 检查到该场馆当日%d时至%d时人数已满, 请您换一个时长或者取消本次预约\n", w.ExpTime.hour, w.ExpTime.hour+1);
                printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
                break;
            }
            if(countN2>f[w.field.ICcode2-1].MaxNum-1)
            {
                CLEAR
                printf("******您正在选择预约时长******\n\n提示: 检查到该场馆当日%d时至%d时人数已满, 请您换一个时长或者取消本次预约\n", w.ExpTime.hour+1, w.ExpTime.hour+2);
                printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
                break;
            }
            if(countN3>f[w.field.ICcode2-1].MaxNum-1)
            {
                CLEAR
                printf("******您正在选择预约时长******\n\n提示: 检查到该场馆当日%d时至%d时人数已满, 请您换一个时长或者取消本次预约\n", w.ExpTime.hour+2, w.ExpTime.hour+3);
                printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
                break;
            }
            if(countN4>f[w.field.ICcode2-1].MaxNum-1)
            {
                CLEAR
                printf("******您正在选择预约时长******\n\n提示: 检查到该场馆当日%d时至%d时人数已满, 请您换一个时长或者取消本次预约\n", w.ExpTime.hour+3, w.ExpTime.hour+4);
                printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
                break;
            }
            if(w.client.val<w.duration*f[w.field.ICcode2-1].prize)
            {
                CLEAR
                printf("尊敬的 %s ",w.client.name);
                if(w.client.gender==1)
                    printf("先生");
                if(w.client.gender==2)
                    printf("女士");
                printf(",    很抱歉, 您的余额不足以完成本次支付。\n    本次预约需要花费:%.2lf元, 您的余额为:%.2lf元。\n\n(按任意键继续)", w.duration*f[w.field.ICcode2-1].prize, w.client.val);
                fflush(stdin);
                getch();
                fflush(stdin);
                CLEAR
                index01=0;
                countN1=0, countN2=0, countN3=0, countN4=0;
                break;
            }
            
            countN1=0, countN2=0, countN3=0, countN4=0;

            index01=0;
            w.client.val-=w.duration*f[w.field.ICcode2-1].prize;
            YOU.val=w.client.val;
            break;

        case '0':
            goto label3;
            break;

        default:
            CLEAR
            printf("******您正在选择预约时长******\n\n提示: 输入有误, 请输入数字0~4\n");
            printf("每次预约时长最大4个小时, 请选择您的预约时长(输入0取消本次预定): ");
            break;
        }

    }
    
    fp = fopen("Test_RsvInfo01", "a+");
    if(fp == NULL)
    {
        printf("error:FILE005\n文件打开失败!\n");
        exit(1);
    }
    fprintf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒\n", w.client.id, w.place.ICcode1, w.field.ICcode2, w.duration, w.ExpTime.year, w.ExpTime.month, w.ExpTime.daym, w.ExpTime.hour, currentTime0.tm_year+1900, currentTime0.tm_mon+1, currentTime0.tm_mday, currentTime0.tm_hour, currentTime0.tm_min, currentTime0.tm_sec);
    //用户id  场馆编号  场地编号  时常  预约日期年月日时  下单时间年月日时分秒
    fclose(fp);
    label3:
    CLEAR
    printf("您已完成%d/%d项预约! (按任意键继续)", Count+1, tiMez);
    fflush(stdin);
    getch();
    CLEAR
    if(tiMez==2 && Count<1)
    {
        Count++;
        goto label2;
    }
    if(tiMez==3 && Count<2)
    {
        Count++;
        goto label2;
    }
    YOU.val=w.client.val;
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
    fflush(stdin);   //有时scanf会扫描进换行符，因此我们倾向于“滥用”fflush()函数以清空缓冲区
    str[1]='\000';
    scanf("%s",str);
    fflush(stdin);  
    UserInfo* test3;
    int index08=0, index09=0;
    test3 = (UserInfo*)malloc(MAX_RECORDS*sizeof(UserInfo));
    fp=fopen("Test_UserInfo05", "r");
    for(int i=0; fscanf(fp, "%s %s %s %d %d %s %s %d %d %lf", test3[i].id, test3[i].password,test3[i].name, &test3[i].gender,&test3[i].age,test3[i].mail,test3[i].tel, &test3[i].address, &test3[i].timez, &test3[i].val)!=EOF; i++)
    {
        if(strcmp(test3[i].id, YOU.id)==0)
            index08=i;
        index09++;
    }
    test3[index08].val=YOU.val;
    fp=fopen("Test_UserInfo05", "w");
    for(int i=0; i<index09; i++)
        fprintf(fp, "%s %s %s %d %d %s %s %d %d %lf\n", test3[i].id, test3[i].password,test3[i].name, test3[i].gender, test3[i].age, test3[i].mail, test3[i].tel, test3[i].address, test3[i].timez, test3[i].val);
    fclose(fp);
    return;

}

void UserPreRsv1()
{
    CLEAR

    RsvInfo p, tempo;
    p.client=YOU;
    time_t timer00, timer01, timer02, timerx;
    struct tm currentTime0, currentTime1, currentTime2, currentTimex;//用于获取时间信息
    PlaceInfo place[3];
    FILE* fp;
    int pl, fi;
    int number[18];
    char addressTrans[3][5][32];

    char str[2]={'\000', '\000'};
    int index01=1;
    
    label4:
    //本次打开place文件是为了获知当前各个场馆下设几个场地
    fp = fopen("Test_Place01", "a+");
    if(fp == NULL)
    {
        printf("error:FILE005\n文件打开失败!\n");
        exit(1);
    }
    for(int i=0; i<3; i++)
        fscanf(fp, "%d %d", &place[i].ICcode1, &place[i].num);
    fclose(fp);
    

    fp = fopen("Test_Field101", "a+");
    if(fp == NULL)
    {
        printf("error:FILE005\n文件打开失败!\n");
        exit(1);
    }
    for(int i=0; i<place[0].num; i++)    
    {
        fscanf(fp, "%d %s %d %d %d %lf", &place[0].field[i].ICcode2, place[0].field[i].name, &place[0].field[i].EntranceAge, &place[0].field[i].MaxNum, &place[0].field[i].Area, &place[0].field[i].prize);
        place[0].field[i].currentNum=0;
    }
    fclose(fp);

    fp = fopen("Test_Field201", "a+");
    if(fp == NULL)
    {
        printf("error:FILE005\n文件打开失败!\n");
        exit(1);
    }
    for(int i=0; i<place[1].num; i++)   
    {    
        fscanf(fp, "%d %s %d %d %d %lf", &place[1].field[i].ICcode2, place[1].field[i].name, &place[1].field[i].EntranceAge, &place[1].field[i].MaxNum, &place[1].field[i].Area, &place[1].field[i].prize);
        place[1].field[i].currentNum=0;
    }    
    fclose(fp);
   
    fp = fopen("Test_Field301", "a+");
    if(fp == NULL)
    {
        printf("error:FILE005\n文件打开失败!\n");
        exit(1);
    }
    for(int i=0; i<place[2].num; i++)   
    {    
        fscanf(fp, "%d %s %d %d %d %lf", &place[2].field[i].ICcode2, place[2].field[i].name, &place[2].field[i].EntranceAge, &place[2].field[i].MaxNum, &place[2].field[i].Area, &place[2].field[i].prize);
        place[2].field[i].currentNum=0;
        place[1].field[i].currentNum=0;
    }    
    fclose(fp);


    index01=1;
    printf("请输入您要查询的场馆(1.健身房, 2.游泳馆, 3.足球场, 4.返回用户菜单): ");
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
            printf("******您正在进行场馆查询******\n\n提示: 输入有误。请输入数字1~3\n");
            printf("请输入您要预约的第一个场馆(1.健身房, 2.游泳馆, 3.足球场, 4.返回用户菜单): ");
            str[1]='\000';
        }

        switch (str[0])
        {
        case '1':
            pl=1;
            index01=0;
            break;

        case '2':
            pl=2;
            index01=0;
            break;

        case '3':
            pl=3;
            index01=0;
            break;

        case '4':
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
            fflush(stdin);   //有时scanf会扫描进换行符，因此我们倾向于“滥用”fflush()函数以清空缓冲区
            return;

        default:
            CLEAR
            printf("******您正在进行场馆查询******\n\n提示: 输入有误。请输入数字1~3\n");
            printf("请输入您要预约的第一个场馆(1.健身房, 2.游泳馆, 3.足球场, 4.返回用户菜单): ");
            break;
        }
    }

    printf("请选择场地(");
    for(int i=0; i<place[pl-1].num; i++)
        printf("%d.%s  ", i+1, place[pl-1].field[i].name);
    printf("): ");
    index01=1;
    while(index01)
    {
        
        while(1)
        {
            fflush(stdin);
            scanf("%s",str);
            fflush(stdin);
            if(str[1]=='\000')
                break;
            CLEAR
            str[1]='\000';
            printf("******您正在进行场馆查询******\n\n提示: 输入有误。请输入数字1~3\n");
            printf("请输入您要预约的第一个场馆(1.健身房, 2.游泳馆, 3.足球场): %d\n", pl);
            printf("请选择场地(");
            for(int i=0; i<place[pl-1].num; i++)
                printf("%d.%s  ", i+1, place[pl-1].field[i].name);
            printf("): ");
            for(int i=0; i<place[pl-1].num; i++)
                printf("%d.%s  ", i+1, place[pl-1].field[i].name);
            printf("): ");
        }

        for(int i=0; i<place[pl-1].num; i++)
        {
            if(str[0]-'0'==place[pl-1].field[i].ICcode2)
            {
                index01=0;
                fi=place[pl-1].field[i].ICcode2;
                break;
            }
        }
        CLEAR
        printf("******您正在进行场馆查询******\n\n提示: 输入有误。请输入数字1~3\n");
        printf("请输入您要预约的第一个场馆(1.健身房, 2.游泳馆, 3.足球场): %d\n", pl);
        printf("请选择场地(");
        for(int i=0; i<place[pl-1].num; i++)
            printf("%d.%s  ", i+1, place[pl-1].field[i].name);
        printf("): ");
    }
    
    
    timer00=time(NULL);
    timer00+=3600*8;
    gmtime_s(&currentTime0, &timer00);        //当前时间
    timer01=timer00+604800;
    timer02=timer00+604800*2;
    gmtime_s(&currentTime1, &timer01);   //一周后的时间
    gmtime_s(&currentTime2, &timer02);   //两周后的时间
    timerx=timer00;
    CLEAR
    if(pl==1)
        printf("******您正在查询健身馆-");
    if(pl==2)
        printf("******您正在查询游泳馆-");
    if(pl==3)
        printf("******您正在查询足球馆-");
    printf("%s", place[pl-1].field[fi-1].name);
    printf("******\n\n提示: 请输入数字1~7\n");
    printf("现在是%d年%d月%d日, 您可以选择%d年%d月%d日至%d年%d月%d日之间的日期进行查询。\n", currentTime0.tm_year+1900, currentTime0.tm_mon+1, currentTime0.tm_mday, currentTime1.tm_year+1900, currentTime1.tm_mon+1, currentTime1.tm_mday+1, currentTime2.tm_year+1900, currentTime2.tm_mon+1, currentTime2.tm_mday);
    printf("请输入您需要查询的日期: \n");
    for(int i=1; i<8; i++)
    {
        timerx+=3600*24;
        gmtime_s(&currentTimex, &timerx);
        printf("%d.%d年%d月%d日\n", i, currentTimex.tm_year+1900, currentTimex.tm_mon+1, currentTimex.tm_mday);
    }
    printf("8.进行预约\n9.返回用户菜单\n");
    //输入日期
    index01=1;
    while(index01)
    {
        for(int i=0; i<18; i++)
            number[i]=0;
        while(1)
        {
            str[1]='\000';
            scanf("%s",str);
            fflush(stdin);
            if(str[1]=='\000')
                break;
            CLEAR
            if(pl==1)
                printf("******您正在查询健身馆-");
            if(pl==2)
                printf("******您正在查询游泳馆-");
            if(pl==3)
                printf("******您正在查询足球馆-");
            printf("%s", place[pl-1].field[fi-1].name);
            printf("******\n\n提示: 请输入数字1~7\n");
            printf("现在是%d年%d月%d日, 您可以选择%d年%d月%d日至%d年%d月%d日之间的日期进行查询。\n", currentTime0.tm_year+1900, currentTime0.tm_mon+1, currentTime0.tm_mday, currentTime1.tm_year+1900, currentTime1.tm_mon+1, currentTime1.tm_mday+1, currentTime2.tm_year+1900, currentTime2.tm_mon+1, currentTime2.tm_mday);
            printf("请输入您需要查询的日期: \n");
            for(int i=1; i<8; i++)
            {
                timerx+=3600*24;
                gmtime_s(&currentTimex, &timerx);
                printf("%d.%d年%d月%d日\n", i, currentTimex.tm_year+1900, currentTimex.tm_mon+1, currentTimex.tm_mday);
            }
            printf("8.进行预约\n9.返回用户菜单\n");
            timerx=timer00;
            for(int i=1; i<8; i++)
            {
                timerx+=3600*24;
                gmtime_s(&currentTimex, &timerx);
                printf("%d.%d年%d月%d日\n", i, currentTimex.tm_year+1900, currentTimex.tm_mon+1, currentTimex.tm_mday);
            }
        }

        switch (str[0])
        {
        case '1':
            timerx=timer00+1*24*3600;
            gmtime_s(&currentTimex, &timerx);
            p.ExpTime.year=currentTimex.tm_year+1900;
            p.ExpTime.month=currentTimex.tm_mon+1;
            p.ExpTime.daym=currentTimex.tm_mday;
            for(int i=0; i<18; i++)
            {
                fp = fopen("Test_RsvInfo01", "a+");
                if(fp == NULL)
                {
                    printf("error:FILE005\n文件打开失败!\n");
                    exit(1);
                }
                while(fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒", tempo.client.id, &tempo.place.ICcode1, &tempo.field.ICcode2, &tempo.duration, &tempo.ExpTime.year, &tempo.ExpTime.month, &tempo.ExpTime.daym, &tempo.ExpTime.hour, &tempo.RsvTime.year, &tempo.RsvTime.month, &tempo.RsvTime.daym, &tempo.RsvTime.hour, &tempo.RsvTime.min, &tempo.RsvTime.sec)!=EOF)
                {
                    
                    if(tempo.ExpTime.year==p.ExpTime.year && tempo.ExpTime.month==p.ExpTime.month && tempo.ExpTime.daym==p.ExpTime.daym)
                    {
                        if(tempo.ExpTime.hour<=(10+i) && tempo.ExpTime.hour+tempo.duration>=(11+i))
                            number[i]++;
                    }
                }
                fclose(fp);
            }
            
            CLEAR
            if(pl==1)
                printf("以下是健身馆-");
            if(pl==2)
                printf("以下是游泳馆-");
            if(pl==3)
                printf("以下是足球馆-");
            printf("%s的具体信息:\n", place[pl-1].field[fi-1].name);
            printf("             准入年龄%2d岁  最大容纳%3d人  租金%4.2lf元/小时  位于", place[pl-1].field[fi-1].EntranceAge, place[pl-1].field[fi-1].MaxNum, place[pl-1].field[fi-1].prize, addressTrans[pl-1][fi-1]);
            if(place[pl-1].field[fi-1].Area==1)
                printf("海淀区\n\n");
            if(place[pl-1].field[fi-1].Area==2)
                printf("丰台区\n\n");
            if(place[pl-1].field[fi-1].Area==3)
                printf("西城区\n\n");
            printf("以下该场馆%d年%d月%d日各时间段预约人数:\n", p.ExpTime.year, p.ExpTime.month, p.ExpTime.daym);
            for(int i=0; i<19; i++)
                printf("%2d:00~%2d:00  已经预约%3d人, 还可以预约%3d人\n", 10+i, 11+i, number[i], place[pl-1].field[fi-1].MaxNum-number[i]);
            fflush(stdin);
            printf("\n(按任意键继续)");
            getch();
            CLEAR
            goto label4;
            break;

        case '2':
            timerx=timer00+2*24*3600;
            gmtime_s(&currentTimex, &timerx);
            p.ExpTime.year=currentTimex.tm_year+1900;
            p.ExpTime.month=currentTimex.tm_mon+1;
            p.ExpTime.daym=currentTimex.tm_mday;
            for(int i=0; i<18; i++)
            {
                fp = fopen("Test_RsvInfo01", "a+");
                if(fp == NULL)
                {
                    printf("error:FILE005\n文件打开失败!\n");
                    exit(1);
                }
                while(fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒", tempo.client.id, &tempo.place.ICcode1, &tempo.field.ICcode2, &tempo.duration, &tempo.ExpTime.year, &tempo.ExpTime.month, &tempo.ExpTime.daym, &tempo.ExpTime.hour, &tempo.RsvTime.year, &tempo.RsvTime.month, &tempo.RsvTime.daym, &tempo.RsvTime.hour, &tempo.RsvTime.min, &tempo.RsvTime.sec)!=EOF)
                {
                    
                    if(tempo.ExpTime.year==p.ExpTime.year && tempo.ExpTime.month==p.ExpTime.month && tempo.ExpTime.daym==p.ExpTime.daym)
                    {
                        if(tempo.ExpTime.hour<=(10+i) && tempo.ExpTime.hour+tempo.duration>=(11+i))
                            number[i]++;
                    }
                }
                fclose(fp);
            }
            
            CLEAR
            if(pl==1)
                printf("以下是健身馆-");
            if(pl==2)
                printf("以下是游泳馆-");
            if(pl==3)
                printf("以下是足球馆-");
            printf("%s的具体信息:\n", place[pl-1].field[fi-1].name);
            printf("             准入年龄%2d岁  最大容纳%3d人  租金%4.2lf元/小时  位于", place[pl-1].field[fi-1].EntranceAge, place[pl-1].field[fi-1].MaxNum, place[pl-1].field[fi-1].prize, addressTrans[pl-1][fi-1]);
            if(place[pl-1].field[fi-1].Area==1)
                printf("海淀区\n\n");
            if(place[pl-1].field[fi-1].Area==2)
                printf("丰台区\n\n");
            if(place[pl-1].field[fi-1].Area==3)
                printf("西城区\n\n");
            printf("以下该场馆%d年%d月%d日各时间段预约人数:\n", p.ExpTime.year, p.ExpTime.month, p.ExpTime.daym);
            for(int i=0; i<19; i++)
                printf("%2d:00~%2d:00  已经预约%3d人, 还可以预约%3d人\n", 10+i, 11+i, number[i], place[pl-1].field[fi-1].MaxNum-number[i]);
            fflush(stdin);
            printf("\n(按任意键继续)");
            getch();
            CLEAR
            goto label4;
            break;


        case '3':
            timerx=timer00+3*24*3600;
            gmtime_s(&currentTimex, &timerx);
            p.ExpTime.year=currentTimex.tm_year+1900;
            p.ExpTime.month=currentTimex.tm_mon+1;
            p.ExpTime.daym=currentTimex.tm_mday;
            for(int i=0; i<18; i++)
            {
                fp = fopen("Test_RsvInfo01", "a+");
                if(fp == NULL)
                {
                    printf("error:FILE005\n文件打开失败!\n");
                    exit(1);
                }
                while(fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒", tempo.client.id, &tempo.place.ICcode1, &tempo.field.ICcode2, &tempo.duration, &tempo.ExpTime.year, &tempo.ExpTime.month, &tempo.ExpTime.daym, &tempo.ExpTime.hour, &tempo.RsvTime.year, &tempo.RsvTime.month, &tempo.RsvTime.daym, &tempo.RsvTime.hour, &tempo.RsvTime.min, &tempo.RsvTime.sec)!=EOF)
                {
                    
                    if(tempo.ExpTime.year==p.ExpTime.year && tempo.ExpTime.month==p.ExpTime.month && tempo.ExpTime.daym==p.ExpTime.daym)
                    {
                        if(tempo.ExpTime.hour<=(10+i) && tempo.ExpTime.hour+tempo.duration>=(11+i))
                            number[i]++;
                    }
                }
                fclose(fp);
            }
            
            CLEAR
            if(pl==1)
                printf("以下是健身馆-");
            if(pl==2)
                printf("以下是游泳馆-");
            if(pl==3)
                printf("以下是足球馆-");
            printf("%s的具体信息:\n", place[pl-1].field[fi-1].name);
            printf("             准入年龄%2d岁  最大容纳%3d人  租金%4.2lf元/小时  位于", place[pl-1].field[fi-1].EntranceAge, place[pl-1].field[fi-1].MaxNum, place[pl-1].field[fi-1].prize, addressTrans[pl-1][fi-1]);
            if(place[pl-1].field[fi-1].Area==1)
                printf("海淀区\n\n");
            if(place[pl-1].field[fi-1].Area==2)
                printf("丰台区\n\n");
            if(place[pl-1].field[fi-1].Area==3)
                printf("西城区\n\n");
            printf("以下该场馆%d年%d月%d日各时间段预约人数:\n", p.ExpTime.year, p.ExpTime.month, p.ExpTime.daym);
            for(int i=0; i<19; i++)
                printf("%2d:00~%2d:00  已经预约%3d人, 还可以预约%3d人\n", 10+i, 11+i, number[i], place[pl-1].field[fi-1].MaxNum-number[i]);
            fflush(stdin);
            printf("\n(按任意键继续)");
            getch();
            CLEAR
            goto label4;
            break;
        
        case '4':
            timerx=timer00+4*24*3600;
            gmtime_s(&currentTimex, &timerx);
            p.ExpTime.year=currentTimex.tm_year+1900;
            p.ExpTime.month=currentTimex.tm_mon+1;
            p.ExpTime.daym=currentTimex.tm_mday;
            for(int i=0; i<18; i++)
            {
                fp = fopen("Test_RsvInfo01", "a+");
                if(fp == NULL)
                {
                    printf("error:FILE005\n文件打开失败!\n");
                    exit(1);
                }
                while(fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒", tempo.client.id, &tempo.place.ICcode1, &tempo.field.ICcode2, &tempo.duration, &tempo.ExpTime.year, &tempo.ExpTime.month, &tempo.ExpTime.daym, &tempo.ExpTime.hour, &tempo.RsvTime.year, &tempo.RsvTime.month, &tempo.RsvTime.daym, &tempo.RsvTime.hour, &tempo.RsvTime.min, &tempo.RsvTime.sec)!=EOF)
                {
                    
                    if(tempo.ExpTime.year==p.ExpTime.year && tempo.ExpTime.month==p.ExpTime.month && tempo.ExpTime.daym==p.ExpTime.daym)
                    {
                        if(tempo.ExpTime.hour<=(10+i) && tempo.ExpTime.hour+tempo.duration>=(11+i))
                            number[i]++;
                    }
                }
                fclose(fp);
            }
            
            CLEAR
            if(pl==1)
                printf("以下是健身馆-");
            if(pl==2)
                printf("以下是游泳馆-");
            if(pl==3)
                printf("以下是足球馆-");
            printf("%s的具体信息:\n", place[pl-1].field[fi-1].name);
            printf("             准入年龄%2d岁  最大容纳%3d人  租金%4.2lf元/小时  位于", place[pl-1].field[fi-1].EntranceAge, place[pl-1].field[fi-1].MaxNum, place[pl-1].field[fi-1].prize, addressTrans[pl-1][fi-1]);
            if(place[pl-1].field[fi-1].Area==1)
                printf("海淀区\n\n");
            if(place[pl-1].field[fi-1].Area==2)
                printf("丰台区\n\n");
            if(place[pl-1].field[fi-1].Area==3)
                printf("西城区\n\n");
            printf("以下该场馆%d年%d月%d日各时间段预约人数:\n", p.ExpTime.year, p.ExpTime.month, p.ExpTime.daym);
            for(int i=0; i<19; i++)
                printf("%2d:00~%2d:00  已经预约%3d人, 还可以预约%3d人\n", 10+i, 11+i, number[i], place[pl-1].field[fi-1].MaxNum-number[i]);
            fflush(stdin);
            printf("\n(按任意键继续)");
            getch();
            CLEAR
            goto label4;
            break;

        case '5':
            timerx=timer00+5*24*3600;
            gmtime_s(&currentTimex, &timerx);
            p.ExpTime.year=currentTimex.tm_year+1900;
            p.ExpTime.month=currentTimex.tm_mon+1;
            p.ExpTime.daym=currentTimex.tm_mday;
            for(int i=0; i<18; i++)
            {
                fp = fopen("Test_RsvInfo01", "a+");
                if(fp == NULL)
                {
                    printf("error:FILE005\n文件打开失败!\n");
                    exit(1);
                }
                while(fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒", tempo.client.id, &tempo.place.ICcode1, &tempo.field.ICcode2, &tempo.duration, &tempo.ExpTime.year, &tempo.ExpTime.month, &tempo.ExpTime.daym, &tempo.ExpTime.hour, &tempo.RsvTime.year, &tempo.RsvTime.month, &tempo.RsvTime.daym, &tempo.RsvTime.hour, &tempo.RsvTime.min, &tempo.RsvTime.sec)!=EOF)
                {
                    
                    if(tempo.ExpTime.year==p.ExpTime.year && tempo.ExpTime.month==p.ExpTime.month && tempo.ExpTime.daym==p.ExpTime.daym)
                    {
                        if(tempo.ExpTime.hour<=(10+i) && tempo.ExpTime.hour+tempo.duration>=(11+i))
                            number[i]++;
                    }
                }
                fclose(fp);
            }
            
            CLEAR
            if(pl==1)
                printf("以下是健身馆-");
            if(pl==2)
                printf("以下是游泳馆-");
            if(pl==3)
                printf("以下是足球馆-");
            printf("%s的具体信息:\n", place[pl-1].field[fi-1].name);
            printf("             准入年龄%2d岁  最大容纳%3d人  租金%4.2lf元/小时  位于", place[pl-1].field[fi-1].EntranceAge, place[pl-1].field[fi-1].MaxNum, place[pl-1].field[fi-1].prize, addressTrans[pl-1][fi-1]);
            if(place[pl-1].field[fi-1].Area==1)
                printf("海淀区\n\n");
            if(place[pl-1].field[fi-1].Area==2)
                printf("丰台区\n\n");
            if(place[pl-1].field[fi-1].Area==3)
                printf("西城区\n\n");
            printf("以下该场馆%d年%d月%d日各时间段预约人数:\n", p.ExpTime.year, p.ExpTime.month, p.ExpTime.daym);
            for(int i=0; i<19; i++)
                printf("%2d:00~%2d:00  已经预约%3d人, 还可以预约%3d人\n", 10+i, 11+i, number[i], place[pl-1].field[fi-1].MaxNum-number[i]);
            fflush(stdin);
            printf("\n(按任意键继续)");
            getch();
            CLEAR
            goto label4;
            break;

        case '6':
            timerx=timer00+6*24*3600;
            gmtime_s(&currentTimex, &timerx);
            p.ExpTime.year=currentTimex.tm_year+1900;
            p.ExpTime.month=currentTimex.tm_mon+1;
            p.ExpTime.daym=currentTimex.tm_mday;
            for(int i=0; i<18; i++)
            {
                fp = fopen("Test_RsvInfo01", "a+");
                if(fp == NULL)
                {
                    printf("error:FILE005\n文件打开失败!\n");
                    exit(1);
                }
                while(fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒", tempo.client.id, &tempo.place.ICcode1, &tempo.field.ICcode2, &tempo.duration, &tempo.ExpTime.year, &tempo.ExpTime.month, &tempo.ExpTime.daym, &tempo.ExpTime.hour, &tempo.RsvTime.year, &tempo.RsvTime.month, &tempo.RsvTime.daym, &tempo.RsvTime.hour, &tempo.RsvTime.min, &tempo.RsvTime.sec)!=EOF)
                {
                    
                    if(tempo.ExpTime.year==p.ExpTime.year && tempo.ExpTime.month==p.ExpTime.month && tempo.ExpTime.daym==p.ExpTime.daym)
                    {
                        if(tempo.ExpTime.hour<=(10+i) && tempo.ExpTime.hour+tempo.duration>=(11+i))
                            number[i]++;
                    }
                }
                fclose(fp);
            }
            
            CLEAR
            if(pl==1)
                printf("以下是健身馆-");
            if(pl==2)
                printf("以下是游泳馆-");
            if(pl==3)
                printf("以下是足球馆-");
            printf("%s的具体信息:\n", place[pl-1].field[fi-1].name);
            printf("             准入年龄%2d岁  最大容纳%3d人  租金%4.2lf元/小时  位于", place[pl-1].field[fi-1].EntranceAge, place[pl-1].field[fi-1].MaxNum, place[pl-1].field[fi-1].prize, addressTrans[pl-1][fi-1]);
            if(place[pl-1].field[fi-1].Area==1)
                printf("海淀区\n\n");
            if(place[pl-1].field[fi-1].Area==2)
                printf("丰台区\n\n");
            if(place[pl-1].field[fi-1].Area==3)
                printf("西城区\n\n");
            printf("以下该场馆%d年%d月%d日各时间段预约人数:\n", p.ExpTime.year, p.ExpTime.month, p.ExpTime.daym);
            for(int i=0; i<19; i++)
                printf("%2d:00~%2d:00  已经预约%3d人, 还可以预约%3d人\n", 10+i, 11+i, number[i], place[pl-1].field[fi-1].MaxNum-number[i]);
            fflush(stdin);
            printf("\n(按任意键继续)");
            getch();
            CLEAR
            goto label4;
            break;


        case '7':
            timerx=timer00+7*24*3600;
            gmtime_s(&currentTimex, &timerx);
            p.ExpTime.year=currentTimex.tm_year+1900;
            p.ExpTime.month=currentTimex.tm_mon+1;
            p.ExpTime.daym=currentTimex.tm_mday;
            for(int i=0; i<18; i++)
            {
                fp = fopen("Test_RsvInfo01", "a+");
                if(fp == NULL)
                {
                    printf("error:FILE005\n文件打开失败!\n");
                    exit(1);
                }
                while(fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒", tempo.client.id, &tempo.place.ICcode1, &tempo.field.ICcode2, &tempo.duration, &tempo.ExpTime.year, &tempo.ExpTime.month, &tempo.ExpTime.daym, &tempo.ExpTime.hour, &tempo.RsvTime.year, &tempo.RsvTime.month, &tempo.RsvTime.daym, &tempo.RsvTime.hour, &tempo.RsvTime.min, &tempo.RsvTime.sec)!=EOF)
                {
                    
                    if(tempo.ExpTime.year==p.ExpTime.year && tempo.ExpTime.month==p.ExpTime.month && tempo.ExpTime.daym==p.ExpTime.daym)
                    {
                        if(tempo.ExpTime.hour<=(10+i) && tempo.ExpTime.hour+tempo.duration>=(11+i))
                            number[i]++;
                    }
                }
                fclose(fp);
            }
            
            CLEAR
            if(pl==1)
                printf("以下是健身馆-");
            if(pl==2)
                printf("以下是游泳馆-");
            if(pl==3)
                printf("以下是足球馆-");
            printf("%s的具体信息:\n", place[pl-1].field[fi-1].name);
            printf("             准入年龄%2d岁  最大容纳%3d人  租金%4.2lf元/小时  位于", place[pl-1].field[fi-1].EntranceAge, place[pl-1].field[fi-1].MaxNum, place[pl-1].field[fi-1].prize, addressTrans[pl-1][fi-1]);
            if(place[pl-1].field[fi-1].Area==1)
                printf("海淀区\n\n");
            if(place[pl-1].field[fi-1].Area==2)
                printf("丰台区\n\n");
            if(place[pl-1].field[fi-1].Area==3)
                printf("西城区\n\n");
            printf("以下该场馆%d年%d月%d日各时间段预约人数:\n", p.ExpTime.year, p.ExpTime.month, p.ExpTime.daym);
            for(int i=0; i<19; i++)
                printf("%2d:00~%2d:00  已经预约%3d人, 还可以预约%3d人\n", 10+i, 11+i, number[i], place[pl-1].field[fi-1].MaxNum-number[i]);
            fflush(stdin);
            printf("\n(按任意键继续)");
            getch();
            CLEAR
            goto label4;
            break;

        case '8':
            CLEAR
            UserRsv();
            return;

        case '9':
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
            fflush(stdin);   //有时scanf会扫描进换行符，因此我们倾向于“滥用”fflush()函数以清空缓冲区
            str[1]='\000';
            scanf("%s",str);
            fflush(stdin);  
            return;

        default:
            CLEAR
            if(pl==1)
                printf("******您正在查询健身馆-");
            if(pl==2)
                printf("******您正在查询游泳馆-");
            if(pl==3)
                printf("******您正在查询足球馆-");
            printf("%s", place[pl-1].field[fi-1].name);
            printf("******\n\n提示: 请输入数字1~7\n");
            printf("现在是%d年%d月%d日, 您可以选择%d年%d月%d日至%d年%d月%d日之间的日期进行查询。\n", currentTime0.tm_year+1900, currentTime0.tm_mon+1, currentTime0.tm_mday, currentTime1.tm_year+1900, currentTime1.tm_mon+1, currentTime1.tm_mday+1, currentTime2.tm_year+1900, currentTime2.tm_mon+1, currentTime2.tm_mday);
            printf("请输入您需要查询的日期: \n");
            for(int i=1; i<8; i++)
            {
                timerx+=3600*24;
                gmtime_s(&currentTimex, &timerx);
                printf("%d.%d年%d月%d日\n", i, currentTimex.tm_year+1900, currentTimex.tm_mon+1, currentTimex.tm_mday);
            }
            printf("8.进行预约\n9.返回用户菜单\n");
            timerx=timer00;
            for(int i=1; i<8; i++)
            {
                timerx+=3600*24;
                gmtime_s(&currentTimex, &timerx);
                printf("%d.%d年%d月%d日\n", i, currentTimex.tm_year+1900, currentTimex.tm_mon+1, currentTimex.tm_mday);
            }
            break;
        }
    }

    fclose(fp);

}

void UserPreRsv2()
{
    
    char str[2]={'\000', '\000'};
    int index01=1;
    RsvInfo p, tempo;
    p.client=YOU;
    time_t timer00, timer01, timer02, timerx;
    struct tm currentTime0, currentTime1, currentTime2, currentTimex;//用于获取时间信息
    FieldInfo lineup[16];
    PlaceInfo place[3];
    FILE* fp;
    label4:
    //本次打开place文件是为了获知当前各个场馆下设几个场地
    fp = fopen("Test_Place01", "a+");
    if(fp == NULL)
    {
        printf("error:FILE005\n文件打开失败!\n");
        exit(1);
    }
    for(int i=0; i<3; i++)
        fscanf(fp, "%d %d", &place[i].ICcode1, &place[i].num);
    fclose(fp);
    

    fp = fopen("Test_Field101", "a+");
    if(fp == NULL)
    {
        printf("error:FILE005\n文件打开失败!\n");
        exit(1);
    }
    for(int i=0; i<place[0].num; i++)    
    {
        fscanf(fp, "%d %s %d %d %d %lf", &place[0].field[i].ICcode2, place[0].field[i].name, &place[0].field[i].EntranceAge, &place[0].field[i].MaxNum, &place[0].field[i].Area, &place[0].field[i].prize);
        place[0].field[i].currentNum=0;
    }
    fclose(fp);

    fp = fopen("Test_Field201", "a+");
    if(fp == NULL)
    {
        printf("error:FILE005\n文件打开失败!\n");
        exit(1);
    }
    for(int i=0; i<place[1].num; i++)   
    {    
        fscanf(fp, "%d %s %d %d %d %lf", &place[1].field[i].ICcode2, place[1].field[i].name, &place[1].field[i].EntranceAge, &place[1].field[i].MaxNum, &place[1].field[i].Area, &place[1].field[i].prize);
        place[1].field[i].currentNum=0;
    }    
    fclose(fp);
   
    fp = fopen("Test_Field301", "a+");
    if(fp == NULL)
    {
        printf("error:FILE005\n文件打开失败!\n");
        exit(1);
    }
    for(int i=0; i<place[2].num; i++)   
    {    
        fscanf(fp, "%d %s %d %d %d %lf", &place[2].field[i].ICcode2, place[2].field[i].name, &place[2].field[i].EntranceAge, &place[2].field[i].MaxNum, &place[2].field[i].Area, &place[2].field[i].prize);
        place[2].field[i].currentNum=0;
    }    
    fclose(fp);

    fp = fopen("Test_RsvInfo01", "a+");
    if(fp == NULL)
    {
        printf("error:FILE005\n文件打开失败!\n");
        exit(1);
    }
    


    timer00=time(NULL);
    timer00+=3600*8;
    gmtime_s(&currentTime0, &timer00);        //当前时间
    timer01=timer00+604800;
    timer02=timer00+604800*2;
    gmtime_s(&currentTime1, &timer01);   //一周后的时间
    gmtime_s(&currentTime2, &timer02);   //两周后的时间
    timerx=timer00;
    CLEAR
    printf("******您正在进行场地查询******\n\n提示: 请输入数字1~7\n");
    printf("现在是%d年%d月%d日, 您可以选择%d年%d月%d日至%d年%d月%d日之间的日期进行预约。\n", currentTime0.tm_year+1900, currentTime0.tm_mon+1, currentTime0.tm_mday, currentTime1.tm_year+1900, currentTime1.tm_mon+1, currentTime1.tm_mday+1, currentTime2.tm_year+1900, currentTime2.tm_mon+1, currentTime2.tm_mday);
    printf("请输入您需要查询的日期: \n");
    for(int i=1; i<8; i++)
    {
        timerx+=3600*24;
        gmtime_s(&currentTimex, &timerx);
        printf("%d.%d年%d月%d日\n", i, currentTimex.tm_year+1900, currentTimex.tm_mon+1, currentTimex.tm_mday);
    }
    //输入日期
    index01=1;
    while(index01)
    {
        while(1)
        {
            str[1]='\000';
            scanf("%s",str);
            fflush(stdin);
            if(str[1]=='\000')
                break;
            CLEAR
            printf("********您正在进行场地查询********\n\n提示: 输入有误, 请输入数字1~7\n");
            printf("\n现在是%d年%d月%d日, 您可以选择%d年%d月%d日至%d年%d月%d日之间的日期进行预约。\n", currentTime0.tm_year+1900, currentTime0.tm_mon+1, currentTime0.tm_mday, currentTime1.tm_year+1900, currentTime1.tm_mon+1, currentTime1.tm_mday+1, currentTime2.tm_year+1900, currentTime2.tm_mon+1, currentTime2.tm_mday);
            printf("请输入您需要预约的日期: \n");
            timerx=timer00;
            for(int i=1; i<8; i++)
            {
                timerx+=3600*24;
                gmtime_s(&currentTimex, &timerx);
                printf("%d.%d年%d月%d日\n", i, currentTimex.tm_year+1900, currentTimex.tm_mon+1, currentTimex.tm_mday);
            }
        }

        switch (str[0])
        {
        case '1':
            timerx=timer00+1*24*3600;
            gmtime_s(&currentTimex, &timerx);
            p.ExpTime.year=currentTimex.tm_year+1900;
            p.ExpTime.month=currentTimex.tm_mon+1;
            p.ExpTime.daym=currentTimex.tm_mday;
            index01=0;
            break;

        case '2':
            timerx=timer00+2*24*3600;
            gmtime_s(&currentTimex, &timerx);
            p.ExpTime.year=currentTimex.tm_year+1900;
            p.ExpTime.month=currentTimex.tm_mon+1;
            p.ExpTime.daym=currentTimex.tm_mday;
            index01=0;
            break;

        case '3':
            timerx=timer00+3*24*3600;
            gmtime_s(&currentTimex, &timerx);
            p.ExpTime.year=currentTimex.tm_year+1900;
            p.ExpTime.month=currentTimex.tm_mon+1;
            p.ExpTime.daym=currentTimex.tm_mday;
            index01=0;
            break;
        
        case '4':
            timerx=timer00+4*24*3600;
            gmtime_s(&currentTimex, &timerx);
            p.ExpTime.year=currentTimex.tm_year+1900;
            p.ExpTime.month=currentTimex.tm_mon+1;
            p.ExpTime.daym=currentTimex.tm_mday;
            index01=0;
            break;

        case '5':
            timerx=timer00+5*24*3600;
            gmtime_s(&currentTimex, &timerx);
            p.ExpTime.year=currentTimex.tm_year+1900;
            p.ExpTime.month=currentTimex.tm_mon+1;
            p.ExpTime.daym=currentTimex.tm_mday;
            index01=0;
            break;

        case '6':
            timerx=timer00+6*24*3600;
            gmtime_s(&currentTimex, &timerx);
            p.ExpTime.year=currentTimex.tm_year+1900;
            p.ExpTime.month=currentTimex.tm_mon+1;
            p.ExpTime.daym=currentTimex.tm_mday;
            index01=0;
            break;

        case '7':
            timerx=timer00+7*24*3600;
            gmtime_s(&currentTimex, &timerx);
            p.ExpTime.year=currentTimex.tm_year+1900;
            p.ExpTime.month=currentTimex.tm_mon+1;
            p.ExpTime.daym=currentTimex.tm_mday;
            index01=0;
            break;

        default:
            CLEAR
            printf("********您正在进行场地查询********\n\n提示: 输入有误, 请输入数字1~7\n");
            printf("\n现在是%d年%d月%d日, 您可以选择%d年%d月%d日至%d年%d月%d日之间的日期进行预约。\n", currentTime0.tm_year+1900, currentTime0.tm_mon+1, currentTime0.tm_mday, currentTime1.tm_year+1900, currentTime1.tm_mon+1, currentTime1.tm_mday+1, currentTime2.tm_year+1900, currentTime2.tm_mon+1, currentTime2.tm_mday);
            printf("请输入您需要预约的日期: \n");
            timerx=timer00;
            for(int i=1; i<8; i++)
            {
                timerx+=3600*24;
                gmtime_s(&currentTimex, &timerx);
                printf("%d.%d年%d月%d日\n", i, currentTimex.tm_year+1900, currentTimex.tm_mon+1, currentTimex.tm_mday);
            }
            break;
        }
    }

//输入时间
    CLEAR
    printf("******您正在进行场地查询******\n\n提示: 请输入字母a~p\n");
    printf("场馆开放时间为6:00~22:00, 请告诉我们您期望几点开始使用场馆: \n\n");
    printf("a.六  点      e.十  点      i.十四点      m.十八点\n");
    printf("b.七  点      f.十一点      j.十五点      n.十九点\n");
    printf("c.八  点      g.十二点      k.十六点      o.二十点\n");
    printf("d.九  点      h.十三点      l.十七点      p.廿一点\n\n(只能选择整点, 如有不便, 敬请谅解)");
    index01=1;
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
            printf("******您正在进行场地查询******\n\n提示: 输入有误, 请输入字母a~p\n");
            printf("场馆开放时间为6:00~22:00, 请告诉我们您期望几点开始使用场馆: \n\n");
            printf("a.六  点      e.十  点      i.十四点      m.十八点\n");
            printf("b.七  点      f.十一点      j.十五点      n.十九点\n");
            printf("c.八  点      g.十二点      k.十六点      o.二十点\n");
            printf("d.九  点      h.十三点      l.十七点      p.廿一点\n\n(只能选择整点, 如有不便, 敬请谅解)");
            str[1]='\000';
        }

        switch (str[0])
        {
        case 'A':
        case 'a':
            p.ExpTime.hour=6;
            index01=0;
            break;

        case 'B':
        case 'b':
            p.ExpTime.hour=7;
            index01=0;
            break;

        case 'C':
        case 'c':
            p.ExpTime.hour=8;
            index01=0;
            break;

        case 'D':
        case 'd':
            p.ExpTime.hour=9;
            index01=0;
            break;

        case 'E':
        case 'e':
            p.ExpTime.hour=10;
            index01=0;
            break;

        case 'F':
        case 'f':
            p.ExpTime.hour=11;
            index01=0;
            break;

        case 'G':
        case 'g':
            p.ExpTime.hour=12;
            index01=0;
            break;

        case 'H':
        case 'h':
            p.ExpTime.hour=13;
            index01=0;
            break;

        case 'I':
        case 'i':
            p.ExpTime.hour=14;
            index01=0;
            break;

        case 'J':
        case 'j':
            p.ExpTime.hour=15;
            index01=0;
            break;

        case 'K':
        case 'k':
            p.ExpTime.hour=16;
            index01=0;
            break;

        case 'L':
        case 'l':
            p.ExpTime.hour=17;
            index01=0;
            break;

        case 'M':
        case 'm':
            p.ExpTime.hour=18;
            index01=0;
            break;

        case 'N':
        case 'n':
            p.ExpTime.hour=19;
            index01=0;
            break;

        case 'O':
        case 'o':
            p.ExpTime.hour=20;
            index01=0;
            break;

        case 'P':
        case 'p':
            p.ExpTime.hour=21;
            index01=0;
            break;

        default:
            CLEAR
            printf("******您正在进行场地查询******\n\n提示: 输入有误, 请输入字母a~p\n");
            printf("场馆开放时间为6:00~22:00, 请告诉我们您期望几点开始使用场馆: \n\n");
            printf("a.六  点      e.十  点      i.十四点      m.十八点\n");
            printf("b.七  点      f.十一点      j.十五点      n.十九点\n");
            printf("c.八  点      g.十二点      k.十六点      o.二十点\n");
            printf("d.九  点      h.十三点      l.十七点      p.廿一点\n\n(只能选择整点, 如有不便, 敬请谅解)");
            break;
        }
    }

    for(int i=0; i<place[0].num; i++)
        place[0].field[i].ifprint=0;
    for(int i=0; i<place[1].num; i++)
        place[1].field[i].ifprint=0;
    for(int i=0; i<place[2].num; i++)
        place[2].field[i].ifprint=0;

    while(fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒", tempo.client.id, &tempo.place.ICcode1, &tempo.field.ICcode2, &tempo.duration, &tempo.ExpTime.year, &tempo.ExpTime.month, &tempo.ExpTime.daym, &tempo.ExpTime.hour, &tempo.RsvTime.year, &tempo.RsvTime.month, &tempo.RsvTime.daym, &tempo.RsvTime.hour, &tempo.RsvTime.min, &tempo.RsvTime.sec)!=EOF)
    {
        if(tempo.ExpTime.year==p.ExpTime.year && tempo.ExpTime.month==p.ExpTime.month && tempo.ExpTime.daym==p.ExpTime.daym && tempo.ExpTime.hour==p.ExpTime.hour)
            place[tempo.place.ICcode1-1].field[tempo.field.ICcode2-1].currentNum++;
    }
    fclose(fp);

    //是否过滤
    index01=1;
    CLEAR
    printf("******您正在进行场地查询******\n\n提示: 请输入数字1或2");
    printf("是否需要过滤已经预约满的场地?\n");
    printf("1.是   2.否   ");
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
            printf("******您正在进行场地查询******\n\n提示: 输入有误, 请输入数字1或2");
            printf("是否需要过滤已经预约满的场地?\n");
            printf("1.是   2.否   ");
            str[1]='\000';
        }

        switch (str[0])
        {
        case '1':
            for(int i=0; i<place[0].num; i++)
            {
                if(place[0].field[i].currentNum==place[0].field[i].MaxNum)
                    place[0].field[i].ifprint=1;
            }
            for(int i=0; i<place[1].num; i++)
            {
                if(place[1].field[i].currentNum==place[1].field[i].MaxNum)
                    place[1].field[i].ifprint=1;
            }
            for(int i=0; i<place[2].num; i++)
            {
                if(place[2].field[i].currentNum==place[2].field[i].MaxNum)
                    place[2].field[i].ifprint=1;
            }
            index01=0;
            break;

        case '2':
            index01=0;
            break;

        default:
            CLEAR
            printf("******您正在进行场地查询******\n\n提示: 输入有误, 请输入数字1或2");
            printf("是否需要过滤已经预约满的场地?\n");
            printf("1.是   2.否   ");
            break;
        }
    }




    CLEAR
    printf("******您正在进行场地查询******\n\n提示: 请输入数字1~9\n");
    printf("请选择您期望的查询方式: \n");
    printf("1.默认排序方式展示所有场馆信息     2.根据租金价格查询\n");
    printf("3.根据场地剩余可预约人数查询       4.根据热门程度(已预约人数)查询\n");
    printf("5.根据准入年龄查询                6.根据场地所在区域查询\n");
    printf("7.重新选择时间      8.开始预约    9.返回用户界面\n");

    index01=1;
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
            printf("******您正在进行场地查询******\n\n");
            printf("提示: 输入有误, 请输入数字1~8\n");
            printf("1.默认排序方式展示所有场馆信息     2.根据租金价格查询\n");
            printf("3.根据场地剩余可预约人数查询       4.根据热门程度(已预约人数)查询\n");
            printf("5.根据准入年龄查询                6.根据场地所在区域查询\n");
            printf("7.重新选择时间      8.开始预约    9.返回用户界面\n");
            str[1]='\000';
        }

        switch (str[0])
        {
        case '1':
            CLEAR
            for(int i=0; i<place[0].num; i++)
            {    
                if(place[0].field[i].ifprint)
                    continue;
                printf("健身馆-%s:\n             准入年龄%2d岁  最大容纳%3d人  已预约%3d人  尚可预约%3d人  租金%4.2lf元/小时  位于", place[0].field[i].name, place[0].field[i].EntranceAge, place[0].field[i].MaxNum, place[0].field[i].currentNum, place[0].field[i].MaxNum-place[0].field[i].currentNum, place[0].field[i].prize);
                if(place[0].field[i].Area==1)
                    printf("海淀区\n\n");
                if(place[0].field[i].Area==2)
                    printf("丰台区\n\n");
                if(place[0].field[i].Area==3)
                    printf("西城区\n\n");
            }
            for(int i=0; i<place[1].num; i++)
            {    
                if(place[1].field[i].ifprint)
                    continue;
                printf("游泳馆-%s:\n             准入年龄%2d岁  最大容纳%3d人  已预约%3d人  尚可预约%3d人  租金%4.2lf元/小时  位于", place[1].field[i].name, place[1].field[i].EntranceAge, place[1].field[i].MaxNum, place[1].field[i].currentNum, place[1].field[i].MaxNum-place[1].field[i].currentNum, place[1].field[i].prize);
                if(place[1].field[i].Area==1)
                    printf("海淀区\n\n");
                if(place[1].field[i].Area==2)
                    printf("丰台区\n\n");
                if(place[1].field[i].Area==3)
                    printf("西城区\n\n");
            }
            for(int i=0; i<place[2].num; i++)
            {    
                if(place[2].field[i].ifprint)
                    continue;
                printf("足球馆-%s:\n             准入年龄%2d岁  最大容纳%3d人  已预约%3d人  尚可预约%3d人  租金%4.2lf元/小时  位于", place[2].field[i].name, place[2].field[i].EntranceAge, place[2].field[i].MaxNum, place[2].field[i].currentNum, place[2].field[i].MaxNum-place[2].field[i].currentNum, place[2].field[i].prize);
                if(place[2].field[i].Area==1)
                    printf("海淀区\n\n");
                if(place[2].field[i].Area==2)
                    printf("丰台区\n\n");
                if(place[2].field[i].Area==3)
                    printf("西城区\n\n");
            }
            printf("如需关闭“过滤满员场地”功能, 在查询菜单选择“7.重新选择时间”\n");
            printf("(按任意键返回查询菜单)");
            fflush(stdin);
            getch();
            CLEAR
            printf("******您正在进行场地查询******\n\n");
            printf("提示: 输入有误, 请输入数字1~8\n");
            printf("1.默认排序方式展示所有场馆信息     2.根据租金价格查询\n");
            printf("3.根据场地剩余可预约人数查询       4.根据热门程度(已预约人数)查询\n");
            printf("5.根据准入年龄查询                6.根据场地所在区域查询\n");
            printf("7.重新选择时间      8.开始预约    9.返回用户界面\n");
            break;

        case '2':
            CLEAR
            for(int i=0; i<place[0].num; i++)
            {    
                lineup[i]=place[0].field[i];
                lineup[i].ICcode1=1;
            }
            for(int i=place[0].num; i<place[0].num+place[1].num; i++)
            {    
                lineup[i]=place[1].field[i-place[0].num];
                lineup[i].ICcode1=2;
            }
            for(int i=place[0].num+place[1].num; i<place[0].num+place[1].num+place[2].num; i++)
            {    
                lineup[i]=place[2].field[i-place[0].num-place[1].num];
                lineup[i].ICcode1=3;
            }

            for(int i=0; i<place[0].num+place[1].num+place[2].num-1;)
            {
                if(lineup[i].prize>lineup[i+1].prize)
                {
                    lineup[15]=lineup[i];
                    lineup[i]=lineup[i+1];
                    lineup[i+1]=lineup[15];
                    i=0;
                    continue;
                }
                i++;
            }

            CLEAR
            printf("各场地已按照 价格 从低到高排序\n\n");
            for(int i=0; i<place[0].num+place[1].num+place[2].num; i++)
            {
                if(lineup[i].ifprint)
                    continue;
                if(lineup[i].ICcode1==1)
                    printf("健身馆-");
                if(lineup[i].ICcode1==2)
                    printf("游泳馆-");
                if(lineup[i].ICcode1==3)
                    printf("足球馆-");
                printf("%s:\n             准入年龄%2d岁  最大容纳%3d人  已预约%3d人  尚可预约%3d人  租金%4.2lf元/小时  位于", lineup[i].name, lineup[i].EntranceAge, lineup[i].MaxNum, lineup[i].currentNum, lineup[i].MaxNum-lineup[i].currentNum, lineup[i].prize);
                if(lineup[i].Area==1)
                    printf("海淀区\n\n");
                if(lineup[i].Area==2)
                    printf("丰台区\n\n");
                if(lineup[i].Area==3)
                    printf("西城区\n\n");
            }
            printf("如需关闭“过滤满员场地”功能, 在查询菜单选择“7.重新选择时间”\n");
            printf("(按任意键返回查询菜单)");
            fflush(stdin);
            getch();
            CLEAR
            printf("******您正在进行场地查询******\n\n");
            printf("提示: 输入有误, 请输入数字1~8\n");
            printf("1.默认排序方式展示所有场馆信息     2.根据租金价格查询\n");
            printf("3.根据场地剩余可预约人数查询       4.根据热门程度(已预约人数)查询\n");
            printf("5.根据准入年龄查询                6.根据场地所在区域查询\n");
            printf("7.重新选择时间      8.开始预约    9.返回用户界面\n");
            break;

        case '3':
            
            CLEAR
            for(int i=0; i<place[0].num; i++)
            {    
                lineup[i]=place[0].field[i];
                lineup[i].ICcode1=1;
            }
            for(int i=place[0].num; i<place[0].num+place[1].num; i++)
            {    
                lineup[i]=place[1].field[i-place[0].num];
                lineup[i].ICcode1=2;
            }
            for(int i=place[0].num+place[1].num; i<place[0].num+place[1].num+place[2].num; i++)
            {    
                lineup[i]=place[2].field[i-place[0].num-place[1].num];
                lineup[i].ICcode1=3;
            }

            for(int i=0; i<place[0].num+place[1].num+place[2].num-1;)
            {
                if((lineup[i].MaxNum-lineup[i].currentNum)<(lineup[i+1].MaxNum-lineup[i+1].currentNum))
                {
                    lineup[15]=lineup[i];
                    lineup[i]=lineup[i+1];
                    lineup[i+1]=lineup[15];
                    i=0;
                    continue;
                }
                i++;
            }

            CLEAR
            printf("各场地已按照 热门程度(已预约人数) 从高到低排序\n\n");
            for(int i=0; i<place[0].num+place[1].num+place[2].num; i++)
            {
                if(lineup[i].ifprint)
                    continue;
                if(lineup[i].ICcode1==1)
                    printf("健身馆-");
                if(lineup[i].ICcode1==2)
                    printf("游泳馆-");
                if(lineup[i].ICcode1==3)
                    printf("足球馆-");
                printf("%s:\n             准入年龄%2d岁  最大容纳%3d人  已预约%3d人  尚可预约%3d人  租金%4.2lf元/小时  位于", lineup[i].name, lineup[i].EntranceAge, lineup[i].MaxNum, lineup[i].currentNum, lineup[i].MaxNum-lineup[i].currentNum, lineup[i].prize);
                if(lineup[i].Area==1)
                    printf("海淀区\n\n");
                if(lineup[i].Area==2)
                    printf("丰台区\n\n");
                if(lineup[i].Area==3)
                    printf("西城区\n\n");
            }
            printf("如需关闭“过滤满员场地”功能, 在查询菜单选择“7.重新选择时间”\n");
            printf("(按任意键返回查询菜单)");
            fflush(stdin);
            getch();
            break;
        case '4':
            
            CLEAR
            for(int i=0; i<place[0].num; i++)
            {    
                lineup[i]=place[0].field[i];
                lineup[i].ICcode1=1;
            }
            for(int i=place[0].num; i<place[0].num+place[1].num; i++)
            {    
                lineup[i]=place[1].field[i-place[0].num];
                lineup[i].ICcode1=2;
            }
            for(int i=place[0].num+place[1].num; i<place[0].num+place[1].num+place[2].num; i++)
            {    
                lineup[i]=place[2].field[i-place[0].num-place[1].num];
                lineup[i].ICcode1=3;
            }

            for(int i=0; i<place[0].num+place[1].num+place[2].num-1;)
            {
                if(lineup[i].currentNum<lineup[i+1].currentNum)
                {
                    lineup[15]=lineup[i];
                    lineup[i]=lineup[i+1];
                    lineup[i+1]=lineup[15];
                    i=0;
                    continue;
                }
                i++;
            }

            CLEAR
            printf("各场地已按照 剩余可预约人数 从高到低排序\n\n");
            for(int i=0; i<place[0].num+place[1].num+place[2].num; i++)
            {
                if(lineup[i].ifprint)
                    continue;
                if(lineup[i].ICcode1==1)
                    printf("健身馆-");
                if(lineup[i].ICcode1==2)
                    printf("游泳馆-");
                if(lineup[i].ICcode1==3)
                    printf("足球馆-");
                printf("%s:\n             准入年龄%2d岁  最大容纳%3d人  已预约%3d人  尚可预约%3d人  租金%4.2lf元/小时  位于", lineup[i].name, lineup[i].EntranceAge, lineup[i].MaxNum, lineup[i].currentNum, lineup[i].MaxNum-lineup[i].currentNum, lineup[i].prize);
                if(lineup[i].Area==1)
                    printf("海淀区\n\n");
                if(lineup[i].Area==2)
                    printf("丰台区\n\n");
                if(lineup[i].Area==3)
                    printf("西城区\n\n");
            }
            printf("如需关闭“过滤满员场地”功能, 在查询菜单选择“7.重新选择时间”\n");
            printf("(按任意键返回查询菜单)");
            fflush(stdin);
            getch();
            CLEAR
            printf("******您正在进行场地查询******\n\n");
            printf("提示: 输入有误, 请输入数字1~8\n");
            printf("1.默认排序方式展示所有场馆信息     2.根据租金价格查询\n");
            printf("3.根据场地剩余可预约人数查询       4.根据热门程度(已预约人数)查询\n");
            printf("5.根据准入年龄查询                6.根据场地所在区域查询\n");
            printf("7.重新选择时间      8.开始预约    9.返回用户界面\n");
            break;

        case '5':
            
            CLEAR
            for(int i=0; i<place[0].num; i++)
            {    
                lineup[i]=place[0].field[i];
                lineup[i].ICcode1=1;
            }
            for(int i=place[0].num; i<place[0].num+place[1].num; i++)
            {    
                lineup[i]=place[1].field[i-place[0].num];
                lineup[i].ICcode1=2;
            }
            for(int i=place[0].num+place[1].num; i<place[0].num+place[1].num+place[2].num; i++)
            {    
                lineup[i]=place[2].field[i-place[0].num-place[1].num];
                lineup[i].ICcode1=3;
            }

            for(int i=0; i<place[0].num+place[1].num+place[2].num-1;)
            {
                if(lineup[i].EntranceAge>lineup[i+1].EntranceAge)
                {
                    lineup[15]=lineup[i];
                    lineup[i]=lineup[i+1];
                    lineup[i+1]=lineup[15];
                    i=0;
                    continue;
                }
                i++;
            }

            CLEAR
            printf("各场地已按照 准入年龄 从低到高排序\n\n");
            for(int i=0; i<place[0].num+place[1].num+place[2].num; i++)
            {
                if(lineup[i].ifprint)
                    continue;
                if(lineup[i].ICcode1==1)
                    printf("健身馆-");
                if(lineup[i].ICcode1==2)
                    printf("游泳馆-");
                if(lineup[i].ICcode1==3)
                    printf("足球馆-");
                printf("%s:\n             准入年龄%2d岁  最大容纳%3d人  已预约%3d人  尚可预约%3d人  租金%4.2lf元/小时  位于", lineup[i].name, lineup[i].EntranceAge, lineup[i].MaxNum, lineup[i].currentNum, lineup[i].MaxNum-lineup[i].currentNum, lineup[i].prize);
                if(lineup[i].Area==1)
                    printf("海淀区\n\n");
                if(lineup[i].Area==2)
                    printf("丰台区\n\n");
                if(lineup[i].Area==3)
                    printf("西城区\n\n");
            }
            printf("如需关闭“过滤满员场地”功能, 在查询菜单选择“7.重新选择时间”\n");
            printf("(按任意键返回查询菜单)");
            fflush(stdin);
            getch();
            CLEAR
            printf("******您正在进行场地查询******\n\n");
            printf("提示: 输入有误, 请输入数字1~8\n");
            printf("1.默认排序方式展示所有场馆信息     2.根据租金价格查询\n");
            printf("3.根据场地剩余可预约人数查询       4.根据热门程度(已预约人数)查询\n");
            printf("5.根据准入年龄查询                6.根据场地所在区域查询\n");
            printf("7.重新选择时间      8.开始预约    9.返回用户界面\n");
            break;

        case '6':
            CLEAR
            for(int i=0; i<place[0].num; i++)
            {    
                lineup[i]=place[0].field[i];
                lineup[i].ICcode1=1;
            }
            for(int i=place[0].num; i<place[0].num+place[1].num; i++)
            {    
                lineup[i]=place[1].field[i-place[0].num];
                lineup[i].ICcode1=2;
            }
            for(int i=place[0].num+place[1].num; i<place[0].num+place[1].num+place[2].num; i++)
            {    
                lineup[i]=place[2].field[i-place[0].num-place[1].num];
                lineup[i].ICcode1=3;
            }

            for(int i=0; i<place[0].num+place[1].num+place[2].num-1;)
            {
                if(lineup[i].Area>lineup[i+1].Area)
                {
                    lineup[15]=lineup[i];
                    lineup[i]=lineup[i+1];
                    lineup[i+1]=lineup[15];
                    i=0;
                    continue;
                }
                i++;
            }
            CLEAR
            printf("各场地已按照 所在地区 依次罗列\n\n");
            for(int i=0; i<place[0].num+place[1].num+place[2].num; i++)
            {
                if(lineup[i].ifprint)
                    continue;
                if(lineup[i].ICcode1==1)
                    printf("健身馆-");
                if(lineup[i].ICcode1==2)
                    printf("游泳馆-");
                if(lineup[i].ICcode1==3)
                    printf("足球馆-");
                printf("%s:\n             准入年龄%2d岁  最大容纳%3d人  已预约%3d人  尚可预约%3d人  租金%4.2lf元/小时  位于", lineup[i].name, lineup[i].EntranceAge, lineup[i].MaxNum, lineup[i].currentNum, lineup[i].MaxNum-lineup[i].currentNum, lineup[i].prize);
                if(lineup[i].Area==1)
                    printf("海淀区\n\n");
                if(lineup[i].Area==2)
                    printf("丰台区\n\n");
                if(lineup[i].Area==3)
                    printf("西城区\n\n");
            }
            printf("如需关闭“过滤满员场地”功能, 在查询菜单选择“7.重新选择时间”\n");
            printf("(按任意键返回查询菜单)");
            fflush(stdin);
            getch();
            CLEAR
            printf("******您正在进行场地查询******\n\n");
            printf("提示: 输入有误, 请输入数字1~8\n");
            printf("1.默认排序方式展示所有场馆信息     2.根据租金价格查询\n");
            printf("3.根据场地剩余可预约人数查询       4.根据热门程度(已预约人数)查询\n");
            printf("5.根据准入年龄查询                6.根据场地所在区域查询\n");
            printf("7.重新选择时间      8.开始预约    9.返回用户界面\n");
            break;

        case '7':
            goto label4;

        case '8':
            UserRsv();
            index01=0;
            return;

        case '9':
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
            fflush(stdin);   //有时scanf会扫描进换行符，因此我们倾向于“滥用”fflush()函数以清空缓冲区 
            return;

        default:
            CLEAR
            printf("******您正在进行场地查询******\n\n");
            printf("提示: 输入有误, 请输入数字1~8\n");
            printf("1.默认排序方式展示所有场馆信息     2.根据租金价格查询\n");
            printf("3.根据场地剩余可预约人数查询       4.根据热门程度(已预约人数)查询\n");
            printf("5.根据准入年龄查询                6.根据场地所在区域查询\n");
            printf("7.重新选择时间      8.开始预约    9.返回用户界面\n");
            break;
        }
    }

}

void UserAfterRsv()
{
    time_t timer00, timer01;
    struct tm currentTime0, currentTime1;//用于获取时间信息
    PlaceInfo place[3];
    RsvInfo* test;
    FILE* fp;
    int rtval, count=0, num=0, choice=1;
    test = (RsvInfo*)malloc(MAX_RECORDS*sizeof(UserInfo));
    timer00=time(NULL);
    timer00+=3600*8+3600*24;                   //为了消除东八区的影响，并且得到当前时间的后一天的时间信息
    gmtime_s(&currentTime0, &timer00);        //当前时间
    //本次打开place文件是为了获知当前各个场馆下设几个场地
    fp = fopen("Test_Place01", "r");
    if(fp == NULL)
    {
        printf("error:FILE005\n文件打开失败!\n");
        exit(1);
    }
    for(int i=0; i<3; i++)
        fscanf(fp, "%d %d", &place[i].ICcode1, &place[i].num);
    fclose(fp);
    

    fp = fopen("Test_Field101", "r");
    if(fp == NULL)
    {
        printf("error:Field1文件打开失败!\n");
        exit(1);
    }
    for(int i=0; i<place[0].num; i++)    
    {
        fscanf(fp, "%d %s %d %d %d %lf", &place[0].field[i].ICcode2, place[0].field[i].name, &place[0].field[i].EntranceAge, &place[0].field[i].MaxNum, &place[0].field[i].Area, &place[0].field[i].prize);
        place[0].field[i].currentNum=0;
    }
    fclose(fp);

    fp = fopen("Test_Field201", "r");
    if(fp == NULL)
    {
        printf("error:Field2文件打开失败!\n");
        exit(1);
    }
    for(int i=0; i<place[1].num; i++)   
    {    
        fscanf(fp, "%d %s %d %d %d %lf", &place[1].field[i].ICcode2, place[1].field[i].name, &place[1].field[i].EntranceAge, &place[1].field[i].MaxNum, &place[1].field[i].Area, &place[1].field[i].prize);
        place[1].field[i].currentNum=0;
    }    
    fclose(fp);
   
    fp = fopen("Test_Field301", "r");
    if(fp == NULL)
    {
        printf("error:Field3文件打开失败!\n");
        exit(1);
    }
    for(int i=0; i<place[2].num; i++)   
    {    
        fscanf(fp, "%d %s %d %d %d %lf", &place[2].field[i].ICcode2, place[2].field[i].name, &place[2].field[i].EntranceAge, &place[2].field[i].MaxNum, &place[2].field[i].Area, &place[2].field[i].prize);
        place[2].field[i].currentNum=0;
        place[1].field[i].currentNum=0;
    }    
    fclose(fp);
    CLEAR
    printf("以下是您的订单:\n\n");
    fopen("Test_RsvInfo01", "r");
    for(int i=0; fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒", test[i].client.id, &test[i].place.ICcode1, &test[i].field.ICcode2, &test[i].duration, &test[i].ExpTime.year, &test[i].ExpTime.month, &test[i].ExpTime.daym, &test[i].ExpTime.hour, &test[i].RsvTime.year, &test[i].RsvTime.month, &test[i].RsvTime.daym, &test[i].RsvTime.hour, &test[i].RsvTime.min, &test[i].RsvTime.sec)!=EOF; i++)
    {
        if(strcmp(YOU.id, test[i].client.id)==0)
        {
            count++;
            if(test[i].place.ICcode1==1)
                printf("%2d.健身馆-", count);
            if(test[i].place.ICcode1==2)
                printf("%2d.游泳馆-", count);
            if(test[i].place.ICcode1==3)
                printf("%3d.足球馆-", count);
            printf("%s: %d年%d月%d日%d时至%d时\n订单编号%s%d%d%d%d%d%d  序列号%d\n\n", place[test[i].place.ICcode1-1].field[test[i].field.ICcode2-1].name, test[i].ExpTime.year, test[i].ExpTime.month, test[i].ExpTime.daym, test[i].ExpTime.hour, test[i].ExpTime.hour+test[i].ExpTime.hour, test[i].client.id, test[i].RsvTime.year, test[i].RsvTime.month, test[i].RsvTime.daym, test[i].RsvTime.hour, test[i].RsvTime.min, test[i].RsvTime.sec, i+1);
        }
        num++;
    }
    fclose(fp);
    if(count==0)
    {
        CLEAR
        free(test);
        printf("您当前没有任何预定, 按任意键返回用户菜单");
        fflush(stdin);
        getch();
        return;
    }
    
    printf("如需取消订单, 请输入订单序列号(如需返回则输入0):");
    count=-1;
    rtval=scanf("%d", &count);
    fflush(stdin);
    if(count==0)
    {
        printf("按任意键返回用户菜单\n");
        fflush(stdin);
        getch();
        free(test);
        return;
    }
    if(rtval!=1 || count>num)
    {
        CLEAR
        printf("由于您输入了错误的序列号, 即将返回用户菜单\n");
        printf("(按任意键返回用户菜单)\n");
        fflush(stdin);
        getch();
        free(test);
        return;
    }
        
    if(strcmp(test[count-1].client.id, YOU.id)==0)
    {
        currentTime1.tm_year=test[count-1].ExpTime.year-1900;
        currentTime1.tm_mon=test[count-1].ExpTime.month-1;
        currentTime1.tm_mday=test[count-1].ExpTime.daym;
        currentTime1.tm_hour=0;
        currentTime1.tm_min=0;
        currentTime1.tm_sec=0;
        timer01=mktime(&currentTime1);
        if(timer00+24*3600>timer01)
        {
            free(test);
            CLEAR
            printf("必须要提前一天才能取消预定, 您选择的订单不符合取消预定的条件。");
            printf("(按任意键继续)");
            fflush(stdin);
            getch();
            return;
        }
        CLEAR
        printf("您即将取消以下订单:\n");
        if(test[count-1].place.ICcode1==1)
            printf("%2d.健身馆-", count);
        if(test[count-1].place.ICcode1==2)
            printf("%2d.游泳馆-", count);
        if(test[count-1].place.ICcode1==3)
            printf("%3d.足球馆-", count);
        printf("%s: %d年%d月%d日%d时至%d时 订单编号%s%d%d%d%d%d%d\n\n", place[test[count-1].place.ICcode1-1].field[test[count-1].field.ICcode2-1].name, test[count-1].ExpTime.year, test[count-1].ExpTime.month, test[count-1].ExpTime.daym, test[count-1].ExpTime.hour, test[count-1].ExpTime.hour+test[count-1].ExpTime.hour, test[count-1].client.id, test[count-1].RsvTime.year, test[count-1].RsvTime.month, test[count-1].RsvTime.daym, test[count-1].RsvTime.hour, test[count-1].RsvTime.min, test[count-1].RsvTime.sec);
        printf("取消订单是不可撤回的操作, 请您输入数字0确认取消, 其他无效输入将让您返回用户菜单: ");
        scanf("%d", &choice);
        fflush(stdin);
        if(choice!=0)
        {
            free(test);
            CLEAR
            printf("由于您没有输入数字0, 该订单未被取消\n");
            printf("(按任意键继续)");
            fflush(stdin);
            getch();
            return;
        }
        for(int i=count-1; i<num-1; i++)
            test[i]=test[i+1];
        fp=fopen("Test_RsvInfo01", "w");
        for(int i=0; i<num-1; i++)
            fprintf(fp, "%s %d %d %d %d年%d月%d日%d时 %d年%d月%d日%d时%d分%d秒\n", test[i].client.id, test[i].place.ICcode1, test[i].field.ICcode2, test[i].duration, test[i].ExpTime.year, test[i].ExpTime.month, test[i].ExpTime.daym, test[i].ExpTime.hour, test[i].RsvTime.year, test[i].RsvTime.month, test[i].RsvTime.daym, test[i].RsvTime.hour, test[i].RsvTime.min, test[i].RsvTime.sec);
        free(test);
        fclose(fp);
        printf("您已删除该订单!\n\n");
        printf("按任意键继续");
        fflush(stdin);
        getch();
    }
    else
    {
        CLEAR
        printf("由于您输入了错误的序列号, 即将返回用户菜单\n");
        printf("(按任意键返回用户菜单)\n");
        fflush(stdin);
        getch();
        free(test);
        return;
    }
    

    free(test);
    fclose(fp);
    fflush(stdin);
    getch();
}
//error:FILE00x 报警：001在UserRegister函数；002在预约场馆；003在UserLogin函数；005在用户注册打开场馆信息文件