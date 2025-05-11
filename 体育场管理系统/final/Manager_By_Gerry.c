#include "User_By_Raleigh.c"

void Draw(int TYPE);//绘制管理员界面,TYPE是管理场馆的类型为后面做判断使用
void add();//增加用户
void del();//删除用户
void changeuser();//修改用户信息
void readall();//查找所有用户
void addpla(int TYPE);//增加场场地
void add1();//增加场地的小模块
void add2();
void add3();
void allbill();//统计营业额
void sort();//预定量排序
void ManagerLogin()//管理员登录
{
    int TYPE=0;
    
    
   
    ManagerInfo test;
    

    FILE *fp;
    fp=fopen("Test_ManagerInfo","a+");
    rewind(fp);
    if(fp == NULL)
    {
        printf("error:FILE003\n文件打开失败!\n");
        exit(1);
    }
    char maid[50],maco[50];
   
    printf("请输入管理员账号：");
    while(1)
    {
        scanf("%s",maid);
        
        if(check_username(maid))
            break;
        CLEAR
        printf("输入格式有误请重新输入：");
    }
    while(fscanf(fp, "%s %s %d %d %s",test.id, test.password, &test.gender, &test.type, test.mail)!=EOF)
    {
        
        //忘记密码自动爆炸！！！！！！
        if(strcmp(test.id, maid)==0)
        {
            printf("查询成功账户存在");
            TYPE=test.type;
            while(1)
            {
                char maco[50];
                printf("请输入密码:");
                scanf("%s",maco);
                fflush(stdin);
                if(strcmp(maco, test.password)==0)
                {
                    CLEAR
                    printf("登陆成功！按回车键继续\n");
                    fflush(stdin);
                    getch();
                    Draw(TYPE);
                    CLEAR
                    printf("欢迎进入体育馆综合管理系统\n"); 
                    printf("1.用户界面\n");
                    printf("2.管理员登陆\n");
                    printf("3.管理员注册\n");
                    printf("4.结束程序\n");
                    return;
                }
            printf("密码错误");
            }
            CLEAR
        }
    }
        
        
        printf("账号未被注册，请退回主菜单自行注册\n");
        fflush(stdin);
        getch();
        CLEAR
        printf("欢迎进入体育馆综合管理系统\n"); 
        printf("1.用户界面\n");
        printf("2.管理员登陆\n");
        printf("3.管理员注册\n");
        printf("4.结束程序\n");
        return;
        }
void ManagerRegister()//管理员注册
{
    CLEAR
    char ch;//中间变量
    int index03=0;
    int IC=0;
    int permi=0;
    int type=0;
    int kind=0;
    FILE *fp;
    ManagerInfo m, test;
    int idot, iat, count;
    while(1)//检查permi
    {
        printf("请输入您许可代码: ");
        IC=scanf("%d",&permi);
        fflush(stdin);
        if(permi==123456)
            break;

        CLEAR
        printf("准许代码输入有误,请重新输入,或者按回车键返回主菜单\n");
        
    }
    //打开文件
    fp = fopen("Test_ManagerInfo", "a+");
    if(fp == NULL)
    {
        printf("error:FILE004\n文件打开失败!\n");
        exit(1);
    }
    //输入用户名
   printf("请输入您的用户名: ");
    while(1)
    {
        scanf("%s",m.id);
        fflush(stdin);
        if(check_username(m.id))
            break;
        CLEAR
        printf("用户名格式有误,请重新输入!\n");
        printf("请输入您的用户名: ");
    }
    //检查是否有重复用户
   
    while(fscanf(fp, "%s %s %d %d %s",test.id, test.password, &test.gender, &test.type, test.mail)!=EOF)
    {
         
        if(strcasecmp(m.id, test.id)==0)
        {
            printf("该用户名已注册! 按回车健返回主菜单!");
            getch();
            CLEAR
            printf("******欢迎进入体育馆综合管理系统******\n\n");
            printf("1.用户界面\n");
            printf("2.管理员登陆\n");
            printf("3.管理员注册\n");
            printf("4.结束程序\n");
            return;
        }
        
    }

    fclose(fp);

    //写入密码
    printf("请输入您的密码: ");
    while(1)
    {
        scanf("%s",m.password);
        fflush(stdin);
        if(check_string(m.password))
            break;
        CLEAR
        printf("密码格式有问题，请重新输入\n");
        printf("请输入您的用户名: %s\n",m.id);
        printf("请输入您的密码: ");
    }

    
    
    
    //写入性别
        
    char str[2]={'\000', '\000'};   
    int index01=1;
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
            printf("输入有误, 请输入数字1或2\n");
            printf("请输入您的用户名: %s\n",m.id);
            printf("请输入您的密码: %s\n",m.password);
            printf("请输入您的性别(1.男, 2.女): ");
            str[1]='\000';
        }

        switch (str[0])
        {
        case '1':
            m.gender=1;
            index01=0;
            break;

        case '2':
            m.gender=2;
            index01=0;
            break;

        default:
            CLEAR
            printf("输入有误, 请输入数字1或2\n");
            printf("请输入您的用户名: %s\n",m.id);
            printf("请输入您的密码: %s\n",m.password);
            printf("请输入您的性别(1.男, 2.女): ");
            break;
        }
    }

  
    //写入场馆信息1健身房2游泳馆3足球场
    printf("请选择管理的健身房健身房2游泳馆3足球场");
        scanf("%c",&kind);    
        switch(kind)
        {
        case '1':
        m.type=1;
        break;
        case '2':
        m.type=2;
        break;
        case '3':
        m.type=3;
        break;
        default:
        CLEAR
        printf("输入有误，请重新输入");
        break;
        }
    //写入邮箱
    printf("请输入您的邮箱:");
    while(1)
    {
        for(int i=0;i<64;i++)
            m.mail[i]='\000';
        scanf("%s",m.mail);
        fflush(stdin);
        if(m.mail[63]!='\000')
        {
            CLEAR
            printf("邮箱太长了\n");
            printf("请输入您ICcode: ",m.type);
            printf("请输入您的用户名: %s\n",m.id);
            printf("请输入您的密码: %s\n",m.password);
            printf("请输入您的性别(M或F,可跳过): %d\n",m.gender);
            printf("请输入您的邮箱: ");
            continue;
        }
        iat=0;
        idot=0;
        count=0;
        for(int i=0; i<64; i++)
        {
            if(m.mail[i]=='@')
            {
                iat=i;
                count++;
                break;
            }
        }
        for(int i=0; i<64; i++)
        {
            if(m.mail[i]=='.')
            {
                idot=i;
                count++;
                break;
            }
        }

        if(count==2 && (iat+1)<idot && iat!=0 && m.mail[iat+1]!='\000')
            break;
        CLEAR
        
            printf("邮箱格式有误\n");
            printf("请输入您ICcode: %d",m.type);
            printf("请输入您的用户名: %s\n",m.id);
            printf("请输入您的密码: %s\n",m.password);
            printf("请输入您的性别(M或F,可跳过): %d\n",m.gender);
            printf("请输入您的邮箱: ");
    }

   

    
    //写入文件
    fp = fopen("Test_ManagerInfo", "a+");
    if(fp == NULL)
    {
        printf("error:FILE002\n文件打开失败!\n");
        exit(1);
    }

    fprintf(fp, "%s %s %d %d %s\n",m.id, m.password, m.gender, m.type,m.mail);
    
    printf("注册成功! 请仔细核对个人信息!\n");
    fclose(fp);
    printf("按任意键退出注册\n");
    getch();
    fflush(stdin);
    CLEAR
    printf("欢迎进入体育馆综合管理系统\n"); 
    printf("1.用户界面\n");
    printf("2.管理员登陆\n");
    printf("3.管理员注册\n");
    printf("4.结束程序\n");
    return;
}
void Draw(int TYPE)//管理员界面
{
    
    while(1)
    {
        char str[2];    //使用数组str[]记录用户的输入。选用数组是为了防止用户输入字符串。正常情况下，用户的输入存在str[0]
        str[1]='\000';
    
        int index01=1;  //index01变量用于继续/终止登陆界面的循环。初始化为1,使得登陆界面一直进行。只有输入3才能使其值变为0，以终止循环，结束程序。

        printf("欢迎进入管理员菜单界面\n"); 
        printf("a.用户增加\n");//add函数
        printf("b.用户删除\n");//del函数
        printf("c.修改用户改信息\n");//change函数
        printf("d.增加场地\n");//addpla函数
        printf("e.删除场地\n");//delpla函数
        printf("f.修改场地信息\n");//chanpla函数
        printf("g.统计用户年龄\n");
        printf("h.统计男女最喜欢的运动\n");
        printf("i.统计受用户欢迎的时间\n");
        printf("j.统计营业额\n");//bill函数
        printf("k.预约数量排序\n");//sorth函数
        printf("l.退出系统\n");

        scanf("%s",str);
        fflush(stdin);
        while(index01)            //检查用户输入是否为单个字符
        {
        
           
            if(str[1]=='\000')
                break;
            CLEAR
            printf("输入有误! 请输入字母a——l\n");
            printf("a.用户增加\n");
            printf("b.用户删除\n");
            printf("c.修改用户信息\n");
            printf("d.增加场馆\n");
            printf("e.删除场馆\n");
            printf("f.修改场馆信息\n");
            printf("g.统计用户年龄\n");
            printf("h.统计男女最喜欢的运动\n");
            printf("i.统计受用户欢迎的时间\n");
            printf("j.统计营业额\n");
            printf("k.预约数量排序\n");
            printf("l.退出系统\n");
            str[1]='\000';
            scanf("%s",str);
            fflush(stdin);
        }
        switch (str[0])
        {
        case 'a':
            add();
            index01=0;
            break; 

        case 'b':
            del();    
            index01=0;          
            break;
        
        case 'c':
            changeuser(); 
            index01=0;             
            break;

        case 'd':
            addpla(TYPE);
            index01=0;   
            break;
           CLEAR
        case 'e':
            fielddel();
            index01=0;   
            break;
        case 'f':
            changepla();
            index01=0;   
            break;
       
        case 'g':
            Statisticsage();
            index01=0;   
            break;
        case 'h':
            StatisticsGender();
            index01=0;   
            break;
        case 'i':
            Statisticstime();
            index01=0;   
            break;
        case 'j':
            allbill();
            index01=0;   
            break;
        case 'k':
            sort();
            index01=0;   
            break;
        case 'l':
            return;
        default:
            CLEAR
            printf("输入有误! 请输入字母a——l\n");
            printf("a.用户增加\n");
            printf("b.用户删除\n");
            printf("c.修改用户信息\n");
            printf("d.增加场馆\n");
            printf("e.删除场馆\n");
            printf("f.修改场馆信息\n");
            printf("g.统计用户年龄\n");
            printf("h.统计男女最喜欢的运动\n");
            printf("i.统计受用户欢迎的时间\n");
            printf("j.统计营业额\n");
            printf("k.预约数量排序\n");
            printf("l.退出系统\n");
            break;
        }
    }
}
void changeuser()//修改用户信息
{
    #define MAX_PHONE_LEN 15
    UserInfo *u;
    u = (UserInfo*)malloc(MAX_RECORDS*sizeof(UserInfo));
    //UserInfo u;
    //struct UserInfo u[MAX_RECORDS];
    int num_records = 0;
    char filename[100];
    char search_name[MAX_NAME_LEN];
    int choice;
    FILE* fp = fopen("Test_UserInfo05.txt", "r");
    if (fp == NULL) 
    {
        printf("无法打开 Test_UserInfo05)\n");
        return;
    }

    // 读取文件内容
    while (fscanf(fp, "%s %s  %s %d %d %s %s %s %d %d", u[num_records].id, u[num_records].password, u[num_records].name, &u[num_records].gender,&u[num_records].age,u[num_records].mail,u[num_records].tel,u[num_records].address,&u[num_records].val,&u[num_records].timez) != EOF) {
        num_records++;
    }

    fclose(fp);

    printf("输入用户名: ");
    scanf("%s", search_name);
    // 寻找匹配的用户名
    int index = -1;
    for (int i = 0; i < num_records; i++) {
        if (strcmp(u[i].id, search_name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("用户名不存在或错误 %s\n", search_name);
        return;
    }
    //printf("%s\n",contacts[index].id);
    printf("目标用户信息:\n");
    printf("用户名: %s\n", u[index].id);
    printf("密码: %s\n", u[index].password);
    printf("姓名: %s\n", u[index].name);
    if(u[index].gender==1){
        printf("性别: 女\n");
    }else if (u[index].gender==0){
        printf("性别：男\n");
    }else{
        printf("性别：保密\n");
    };
    printf("年龄: %d\n", u[index].age);
    printf("邮箱: %s\n", u[index].mail);
    printf("电话: %s\n", u[index].tel);
    printf("地址: %s\n", u[index].address);
    printf("余额: %d\n", u[index].val);
    printf("违约次数: %d\n", u[index].timez);
    printf("请输入按键进行修改 (1 = 用户名, 2 = 密码, 3 = 姓名， 4 = 性别， 5 = 年龄， 6 = 邮箱， 7 = 电话， 8 = 地址， 9 = 余额， 10 = 违约次数): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("输入新的用户名: ");
            scanf("%s", u[index].id);
            break;
        case 2:
            printf("输入新的密码: ");
            scanf("%s", u[index].password);
            break;
        case 3:
            printf("输入新的姓名: ");
            scanf("%s", u[index].name);
            break;
         case 4:
         printf("请输入新的性别：");
         scanf("%d",&u[index].gender);
         break;
         case 5:
         printf("请输入新的年龄：");
         scanf("%d",&u[index].age);
         break;
         case 6:
         printf("请输入新的邮箱：");
         scanf("%s",u[index].mail);
         break;
         case 7:
         printf("请输入新的电话：");
         scanf("%s",u[index].tel);
         break;
         case 8:
         printf("请输入新的地址：");
         scanf("%s",u[index].address);
         break;
         case 9:
         printf("请输入新的余额：");
         scanf("%d",&u[index].val);
         break;
         case 10:
         printf("请输入新的违约次数：");
         scanf("%d",&u[index].timez);
         break;
        default:
            printf("错误输入\n");
            return;
    }
    //重新写入
    fp = fopen("Test_UserInfo05", "w");
    if (fp == NULL) {
        printf("未找到文件");
        return;
    }
    for (int i = 0; i < num_records; i++) {
         fprintf(fp, "%s %s %s %d %d %s %s %s %d %d\n", u[i].id, u[i].password, u[i].name, u[i].gender, u[i].age, u[i].mail, u[i].tel, u[i].address, u[i].val, u[i].timez);
    }
    free (u);
    fclose(fp);

    printf("修改成功.\n");
    printf("按任意键回到上一级\n");
    getch();
    CLEAR
            printf("欢迎进入管理员菜单界面\n"); 
            printf("a.用户增加\n");
            printf("b.用户删除\n");
            printf("c.修改用户信息\n");
            printf("d.增加场馆\n");
            printf("e.删除场馆\n");
            printf("f.修改场馆信息\n");
            printf("g.统计用户年龄\n");
            printf("h.统计男女最喜欢的运动\n");
            printf("i.统计受用户欢迎的时间\n");
            printf("j.统计营业额\n");
            printf("k.预约数量排序\n");
            printf("l.退出系统\n");
    return;
}
void readall()//读取所有用户的信息
{
    #define F_PATH "Test_UserInfo05"

    char c;



    FILE*fp=NULL;

    fp=fopen(F_PATH,"r");
    while(fscanf(fp,"%c",&c)!=EOF) printf("%c",c); 
    fclose(fp);
    fp=NULL;  
    
}  
void add()//增加用户的信息
{
    int index03=0;
    int index05=0;
    char str[2]={'\000', '\000'};
    char str2[6]="again";
    UserInfo u,test;
    str2[5]='\000';
    int tag=1;
    int i = 0;
    FILE *fp;
    char ch;
    fp = fopen("Test_UserInfo05.txt","a+");//打开文件
    if(fp == NULL)
    {
        printf("error:FILE003\n文件打开失败!\n");
        exit(1);
    }
        printf("*********您正在进行用户增加*********\n\n");
        printf(" 请输入用户名：");
        u.id[4]='\000';
        scanf("%s",u.id);
        while(1)//检查用户格式
        {
            
            if(check_username(u.id))
                break;
            CLEAR
            printf("*********您正在进行用户增加*********\n\n提示: 用户名格式有误,请重新输入!\n");
            printf(" 请输入您的用户名: ");
            scanf("%s",u.id);
            fflush(stdin);
        }
        printf(" 请输入您的密码 : ");
        while(1)
        {
            scanf("%s",u.password);
         for(int i=0; i<6; i++) //for循环和后面的if语句用于识别"again"
        {
            if(str2[i]==u.password[i])
                index05++;
        }
        if(index05==6)
        {
            fclose(fp);
            return;
        }
        
        fflush(stdin);
        if(check_string(u.password))
            break;
        CLEAR
        printf("************您正在进行用户注册************\n\n提示: 密码格式有问题，请重新输入\n");
        printf(" 请输入您的用户名: %s\n",u.id);
        printf(" 请输入您的密码 : \n");
    }
        //写入姓名
    printf(" 请输入您的姓名 : ");
    for(int i=0;i<64;i++)
        u.name[i]='\000';
    while(1)
    {
        scanf("%s", u.name);
        if(u.name[63]=='\000')
            break;
        CLEAR
        for(int i=0;i<64;i++)
            u.name[i]='\000';
        printf("************您正在进行用户注册************\n\n提示: 您输入的姓名太长,请重新输入!\n");
        printf(" 请输入您的用户名: %s\n",u.id);
        printf(" 请输入您的密码: %s\n",u.password);
        printf(" 请输入您的姓名 : ");
    }
    

    //写入性别
    int g=1;
    printf("请输入您的性别(1.男, 2.女): ");
    while(g)
    {
        while(1)
        {
            scanf("%s",str);
            fflush(stdin);
            if(str[1]=='\000')
                break;
            CLEAR
            printf("************您正在进行用户增加************\n\n提示: 输入有误, 请输入数字1或2\n");
            printf(" 请输入您的用户名: %s\n",u.id);
            printf(" 请输入您的密码: %s\n",u.password);
            printf(" 请输入您的姓名 : %s\n", u.name);
            printf(" 请输入您的性别(1.男, 2.女): ");
            str[1]='\000';
        }

        switch (str[0])
        {
        case '1':
            u.gender=1;//我们用整型储存性别信息。男1女2。
            g=0;
            break;

        case '2':
            u.gender=2;
            g=0;
            break;

        default:
            CLEAR
            printf("************您正在进行用户注册************\n\n提示: 输入有误, 请输入数字1或2\n");
            printf(" 请输入您的用户名: %s\n",u.id);
            printf(" 请输入您的密码: %s\n",u.password);
            printf(" 请输入您的姓名 : %s\n", u.name);
            printf(" 请输入您的性别(1.男, 2.女): ");
            break;
        }
    }
    
    
    //写入年龄
    printf(" 请输入您的年龄 : ");
    while(1)
    {
        index03=scanf("%d",&u.age);
        fflush(stdin);
        if(index03==1 && u.age<101 && u.age>1)
            break;

        CLEAR
        printf("************您正在进行用户注册************\n\n提示: 年龄输入有误,请输入1~100的数字\n");
        printf(" 请输入您的用户名: %s\n",u.id);
        printf(" 请输入您的密码 : %s\n",u.password);
        printf(" 请输入您的姓名 : %s\n", u.name);
        printf(" 请输入您的性别 : 1.先生 2.女士 3.跳过(请输入1,2或3): %d\n", u.gender);
        printf(" 请输入您的年龄 : ");
    }
    
    //写入邮箱
    printf(" 请输入您的邮箱 : ");
    while(1)
    {
    int iat=0;
    int idot=0;
    int count=0;
    for(int i=0;i<64;i++)//清空u.mail[]
            u.mail[i]='\000';
        scanf("%s",u.mail);
        fflush(stdin);
        if(u.mail[63]!='\000')//说明邮箱太长了
        {
        CLEAR
        printf("************您正在进行用户增加************\n\n提示:  邮箱输入太长了，请重新输入\n");
        printf(" 请输入您的用户名: %s\n",u.id);
        printf(" 请输入您的密码 : %s\n",u.password);
        printf(" 请输入您的姓名 : %s\n", u.name);
        printf(" 请输入您的性别 : 1.先生 2.女士 (请输入1,2)%d\n", u.gender);
        printf(" 请输入您的年龄 : %d\n",u.age);
        printf(" 请输入您的邮箱 : ");
        continue;
        }
        for(int i=0; i<64; i++)
        {
            if(u.mail[i]=='@')
            {
                iat=i;
                count++;
                break;
            }
        }
        for(int i=0; i<64; i++)
        {
            if(u.mail[i]=='.')
            {
                idot=i;
                count++;
                break;
            }
        }

        if(count==2 && (iat+1)<idot && iat!=0 && u.mail[iat+1]!='\000')
            break;
        CLEAR
        
        printf("************您正在进行用户注册************\n\n提示:邮箱格式有误，请重新输入！\n");
        printf(" 请输入您的用户名: %s\n",u.id);
        printf(" 请输入您的密码 : %s\n",u.password);
        printf(" 请输入您的姓名 : %s\n", u.name);
        printf(" 请输入您的性别 : 1.先生 2.女士 (请输入1,2)%d\n", u.gender);
        printf(" 请输入您的年龄 : %d\n",u.age);
        printf(" 请输入您的邮箱 : ");
        
      }
    
        
    printf(" 请输入您的电话号码: ");
    while(1)
    {
        index03=0;
        scanf("%s",u.tel);
        fflush(stdin);
        for(int i=0;i<11;i++)
        {
            if(u.tel[i]>57 || u.tel[i]<48)
                index03++;
        }
        if(u.tel[11]=='\000' && index03==0)
            break;

        CLEAR
        printf("************您正在进行用户注册************\n\n提示: 电话号码格式有误!请输入11位数字!\n");
        printf(" 请输入您的用户名: %s\n",u.id);
        printf(" 请输入您的密码 : %s\n",u.password);
        printf(" 请输入您的姓名 : %s\n", u.name);
        printf(" 请输入您的性别 : 1.先生 2.女士 3.跳过(请输入1,2或3): %d\n", u.gender);
        printf(" 请输入您的年龄 : %d\n",u.age);
        printf(" 请输入您的邮箱 : %s\n",u.mail);
        printf(" 请输入您的电话号码: ");
    }

    //写入地址
    int index01=1;
    
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
            printf(" 请输入您的用户名: %s\n",u.id);
            printf(" 请输入您的密码: %s\n",u.password);
            printf(" 请输入您的姓名 : %s\n", u.name);
            printf(" 请输入您的性别(1.男, 2.女): %d\n", u.gender);
            printf(" 请输入您的年龄 : %d\n",u.age);
            printf(" 请输入您的邮箱 : %s\n",u.mail);
            printf(" 请输入您的电话号码: %s\n",u.tel);
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
            printf(" 请输入您的用户名: %s\n",u.id);
            printf(" 请输入您的密码: %s\n",u.password);
            printf(" 请输入您的姓名 : %s\n", u.name);
            printf(" 请输入您的性别(1.男, 2.女): %d\n", u.gender);
            printf(" 请输入您的年龄 : %d\n",u.age);
            printf(" 请输入您的邮箱 : %s\n",u.mail);
            printf(" 请输入您的电话号码: %s\n",u.tel);
            printf(" 请输入您的地址 :\n");
            printf("1.海淀区  2.丰台区  3.西城区  4.其他  ");
            break;
        }
    }
  

    fprintf(fp, "%s %s %s %d %d %s %s %d %d %.2lf\n", u.id, u.password, u.name, u.gender, u.age, u.mail, u.tel, u.address, 0, 0.00);
    fclose(fp);
    index00=1;
    printf("您已为%s完成注册, 请仔细核个人信息。\n(按任意键结束注册并登陆您的账户)\n",u.name);
    
    fclose(fp);
    fflush(stdin);
    getch();
    fflush(stdin);
    CLEAR
    return;
}


void addpla(int TYPE)//场馆信息包括场馆类型 准入年龄 开放时间 总人数`
{
    FILE *fp;
    
    PlaceInfo p;
    switch (TYPE)//在管理员注册函数已经存储了每一个管理员对应的场馆类型，并且传到addpla()函数，使得每个管理员智能打开对应的场馆
    {
    case 1:
    printf("你管理的场馆是健身房\n");
    add1();   
        break;
    case 2:
    printf("你管理的场馆是游泳馆\n");
    add2();   
        break;
    case 3:
    printf("你管理的场馆是足球场\n");
    add3();   
    default:
    printf("管理类型出错，请检查注册时添加的场馆类型");
        break;
    }
   
    
    
}
void add1()//健身房增加场地的函数
{
    
    int index01;
    FILE *fp;
    PlaceInfo p;
    FieldInfo f;
    printf("每次只能输入一个场地\n");
    printf("请输入场地名称:");
    for(int i=0;i<32;i++)
       p.field->name[i]='\000';
       
    while(1)
       {
        scanf("%s",p.field->name);
        
        if(p.field->name[31]=='\000')
            break;
        CLEAR   
        for(int i=0;i<32;i++)
            p.field->name[i]='\000';
            printf("输入的名字太长请重新输入:");
       }


    //写入准入年龄
    printf("请输入场地的准入年龄:");
    while(1)
    {
        
        scanf("%d",&p.field->EntranceAge);
        fflush(stdin);
        if(p.field->EntranceAge<101 && p.field->EntranceAge>1)
            break;
        CLEAR
        printf("输入的最大年龄有误，请重新输入：\n");
        printf("请输入场地的准入年龄:");
    }
    //写入最大人数
    printf("请输入场地的最大人数:");
    while(1)
    {
        int max=999;
        scanf("%d",&p.field->MaxNum);
        fflush(stdin);
        if(p.field->MaxNum < max)
        break;
        CLEAR
        printf("格式有误，请重新输入");
        CLEAR
        printf("请输入最大人数");
        return;    
    }
    printf("请输入区域：");
    while(1)
    {
        scanf("%d",&p.field->Area);
        fflush(stdin);
        if(p.field->Area>0&&p.field->Area<7)
            break;
        printf("输入错误，请重新输入：");

    }
    //写入价格
    printf("请输入场地的价格，按小时计算:");
    while(1)
    {
       
        scanf("%lf",&p.field->prize);
        fflush(stdin);
        
        if(p.field->prize>0.0 && p.field->prize<999.0)
            break;
        
        CLEAR
        printf("输入的价格有误，请重新输入：");
    }
    //显示场地编号
    field *q;
    q = (field*)malloc(100*sizeof(field));
    int num_records = 0;

    FILE* fa = fopen("Test_Field101", "r");
    if (fa == NULL) {
       
        printf("无法打开Test_Field101\n");
    }

    // 读取文件内容，计算之前一共有几个场地，并且将新添加的场地命名
    while (fscanf(fa, "%d %s %d %d %d %lf", &q[num_records].math, q[num_records].name, &q[num_records].people, &q[num_records].number, &q[num_records].number1,&q[num_records].val) != EOF) 
    {
        num_records++;
        if (num_records==5)
        {
        printf("超出最大限制，自动退出");
        break;
        }
    }
    free(q);
    fclose(fa);
    //告诉管理员场地编号
    printf("场地编号为%d\n",num_records+1);
     fclose(fp);
     int iccode;
    iccode=num_records+1;
    //将场地信息写入文件
    fp = fopen("Test_Field101", "a+");
    if(fp == NULL)
    {
        printf("error:FILE001\n文件打开失败!\n");
        exit(1);
    }
    fprintf(fp, "%d %s %d %d %d %.2lf\n",iccode,p.field->name,p.field->EntranceAge,p.field->MaxNum,p.field->Area,p.field->prize);
    fclose(fp);
    printf("添加场地成功！自动返回上一界面\n");
    //将Test_place101的数量进行修改 
    
    change1();
    return;
}
void add2()//游泳馆增加场地的函数
{ 
    int  index01;
    FILE *fp;
    PlaceInfo p;
    FieldInfo f;
    printf("每次只能输入一个场地\n");
    printf("请输入场地名称:");
    for(int i=0;i<32;i++)
       p.field->name[i]='\000';
       
    while(1)
       {
        scanf("%s",p.field->name);
        
        if(p.field->name[31]=='\000')
            break;
        CLEAR   
        for(int i=0;i<32;i++)
            p.field->name[i]='\000';
            printf("输入的名字太长请重新输入:");
       }


    
    printf("请输入场地的准入年龄:");
    while(1)
    {
        
        scanf("%d",&p.field->EntranceAge);
        fflush(stdin);
        if(p.field->EntranceAge<101 && p.field->EntranceAge>1)
            break;
        CLEAR
        printf("输入的最大年龄有误，请重新输入：\n");
        printf("请输入场地的准入年龄:");
    }
    
    printf("请输入场地的最大人数:");
    while(1)
    {
        int max=999;
        scanf("%d",&p.field->MaxNum);
        fflush(stdin);
        if(p.field->MaxNum < max)
        break;
        CLEAR
        printf("格式有误，请重新输入");
        CLEAR
        printf("请输入最大人数");
        return;    
    }
    printf("请输入区域：");
    while(1)
    {
        scanf("%d",&p.field->Area);
        fflush(stdin);
        if(p.field->Area>0&&p.field->Area<7)
            break;
        printf("输入错误，请重新输入：");

    }
    
    printf("请输入场地的价格，按小时计算:");
    while(1)
    {
       
        scanf("%lf",&p.field->prize);
        fflush(stdin);
        
        if(p.field->prize>0.0 && p.field->prize<999.0)
            break;
        
        CLEAR
        printf("输入的价格有误，请重新输入：");
    }
    //显示场地编号


    field *q;
    q = (field*)malloc(100*sizeof(field));
    int num_records = 0;
    FILE* fa = fopen("Test_Field201", "r");
    if (fa == NULL) {
       
        printf("error:FILE001\n文件打开失败!\n");
    }

    // 读取文件内容
    while (fscanf(fa, "%d %s %d %d %d %lf", &q[num_records].math, q[num_records].name, &q[num_records].people, &q[num_records].number, &q[num_records].number1,&q[num_records].val) != EOF) 
    {
        num_records++;
        if (num_records==5)
        {
        printf("超出最大限制，自动退出");
        break;
        }
    }
    free(q);
    fclose(fa);

    printf("场地编号为%d\n",num_records+1);
     fclose(fp);
     int iccode;
    iccode=num_records+1;
    fp = fopen("Test_Field201", "a+");
    if(fp == NULL)
    {
        printf("error:FILE001\n文件打开失败!\n");
        exit(1);
    }
    fprintf(fp, "%d %s %d %d %d %.2lf\n",iccode,p.field->name,p.field->EntranceAge,p.field->MaxNum,p.field->Area,p.field->prize);
    fclose(fp);
    printf("添加场地成功！自动返回上一界面");
    
    
    change2();
    return;
}
void add3()//足球场增加场地的函数
{
      int index01;
    FILE *fp;
    PlaceInfo p;
    FieldInfo f;
    printf("每次只能输入一个场地\n");
    printf("请输入场地名称:");
    for(int i=0;i<32;i++)
       p.field->name[i]='\000';
       
    while(1)
       {
        scanf("%s",p.field->name);
        
        if(p.field->name[31]=='\000')
            break;
        CLEAR   
        for(int i=0;i<32;i++)
            p.field->name[i]='\000';
            printf("输入的名字太长请重新输入:");
       }


    
    printf("请输入场地的准入年龄:");
    while(1)
    {
        
        scanf("%d",&p.field->EntranceAge);
        fflush(stdin);
        if(p.field->EntranceAge<101 && p.field->EntranceAge>1)
            break;
        CLEAR
        printf("输入的最大年龄有误，请重新输入：\n");
        printf("请输入场地的准入年龄:");
    }
    
    printf("请输入场地的最大人数:");
    while(1)
    {
        int max=999;
        scanf("%d",&p.field->MaxNum);
        fflush(stdin);
        if(p.field->MaxNum < max)
        break;
        CLEAR
        printf("格式有误，请重新输入");
        CLEAR
        printf("请输入最大人数");
        return;    
    }
    printf("请输入区域：");
    while(1)
    {
        scanf("%d",&p.field->Area);
        fflush(stdin);
        if(p.field->Area>0&&p.field->Area<7)
            break;
        printf("输入错误，请重新输入：");

    }
    
    printf("请输入场地的价格，按小时计算:");
    while(1)
    {
       
        scanf("%lf",&p.field->prize);
        fflush(stdin);
        
        if(p.field->prize>0.0 && p.field->prize<999.0)
            break;
        
        CLEAR
        printf("输入的价格有误，请重新输入：");
    }
    //显示场地编号

    field *q;
    q = (field*)malloc(100*sizeof(field));
    int num_records = 0;
    FILE* fa = fopen("Test_Field301", "r");
    if (fa == NULL) {
       
        printf("error:FILE001\n文件打开失败!\n");
    }

    // 读取文件内容
    while (fscanf(fa, "%d %s %d %d %d %lf", &q[num_records].math, q[num_records].name, &q[num_records].people, &q[num_records].number, &q[num_records].number1,&q[num_records].val) != EOF) 
    {
        num_records++;
        if (num_records==5)
        {
        printf("超出最大限制，自动退出");
        break;
        }
    }
    free(q);
    fclose(fa);

    printf("场地编号为%d\n",num_records+1);
     fclose(fp);
     int iccode;
    iccode=num_records+1;
    fp = fopen("Test_Field301", "a+");
    if(fp == NULL)
    {
        printf("error:FILE001\n文件打开失败!\n");
        exit(1);
    }
    fprintf(fp, "%d %s %d %d %d %.2lf\n",iccode,p.field->name,p.field->EntranceAge,p.field->MaxNum,p.field->Area,p.field->prize);
    fclose(fp);
    printf("添加场地成功！自动返回上一界面");
    
    
    change3();
    return;
}
void allbill()//统计营业额
{
    while(1)
    {
     FILE *fa;
    FieldInfo fia[100];
    int num_record1 = 0;
    int i;

    // 打开文件
    fa = fopen("Test_Field101", "r");
    if (fa == NULL) 
    {
        printf("无法打开文件Test_Field101\n");
        exit(1);
    }

    // 读取文件内容到结构体数组中
    while (fscanf(fa, "%d %s %d %d %d %lf", &fia[num_record1].ICcode2, fia[num_record1].name, &fia[num_record1].EntranceAge, &fia[num_record1].MaxNum, &fia[num_record1].Area, &fia[num_record1].prize) != EOF) {
        num_record1++;
    }
    // 关闭文件
    fclose(fa);

   FILE *fb;
    FieldInfo fib[100];
    int num_record2 = 0;

    // 打开文件
    fb = fopen("Test_Field201", "r");
    if (fb == NULL) {
        printf("无法打开文件\n");
        exit(1);
    }

    // 读取文件内容到结构体数组中
    while (fscanf(fb, "%d %s %d %d %d %lf", &fib[num_record2].ICcode2, fib[num_record2].name, &fib[num_record2].EntranceAge, &fib[num_record2].MaxNum, &fib[num_record2].Area, &fib[num_record2].prize) != EOF) {
        num_record2++;
    }

    // 关闭文件
    fclose(fb);

    FILE *fc;
    FieldInfo fic[100];
    int num_record3 = 0;

    // 打开文件
    fc = fopen("Test_Field301", "r");
    if (fc == NULL) {
        printf("无法打开文件\n");
        exit(1);
    }

    // 读取文件内容到结构体数组中
    while (fscanf(fc, "%d %s %d %d %d %lf", &fic[num_record3].ICcode2, fic[num_record3].name, &fic[num_record3].EntranceAge, &fic[num_record3].MaxNum, &fic[num_record3].Area, &fic[num_record3].prize) != EOF) {
        num_record3++;
    }

    // 关闭文件
    fclose(fc);


   Record *records;
   records = (Record*)malloc(10000*sizeof(Record));
   FILE *fp = fopen("Test_RsvInfo01", "r");
    if (fp == NULL)
    {
        printf("Failed to open file Test_RsvInfo01.txt\n");
        return;
    }
    int count1 = 0;
    while (fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %s\n", records[count1].name, &records[count1].place1, &records[count1].place2, &records[count1].duration, &records[count1].year, &records[count1].month, &records[count1].day, &records[count1].hour, records[count1].myear) != EOF) {
        count1++;
    }
    fclose(fp);
    long bill1[num_record1];
    long bill2[num_record2];
    long bill3[num_record3];
    int a;
    int b;
    for(i=0;i<5;i++)
    {   
        bill1[i] = 0;
        bill2[i] = 0;
        bill3[i] = 0;
    }
    double money1;
    double money2;
    double money3;
    for(b=0;b < count1;b++){
        if(records[b].place1 == 1){
            if(records[b].place2 == 1){
                bill1[0] = bill1[0] + records[b].duration*fia[0].prize;
            }else if(records[b].place2 == 2){
                bill1[1] = bill1[1] + records[b].duration*fia[1].prize;
            }else if(records[b].place2 == 3){
                bill1[2] = bill1[2] + records[b].duration*fia[2].prize;
            }else if(records[b].place2 == 4){
                bill1[3] = bill1[3] + records[b].duration*fia[3].prize;
            }else if(records[b].place2 == 5){
                bill1[4] = bill1[4] + records[b].duration*fia[4].prize;
            }
        }else if(records[b].place1 == 2){
            if(records[b].place2 == 1){
                bill2[0] = bill2[0] + records[b].duration*fib[0].prize;
            }else if(records[b].place2 == 2){
                bill2[1] = bill2[1] + records[b].duration*fib[1].prize;
            }else if(records[b].place2 == 3){
                bill2[2] = bill2[2] + records[b].duration*fib[2].prize;
            }else if(records[b].place2 == 4){
                bill2[3] = bill2[3] + records[b].duration*fib[3].prize;
            }else if(records[b].place2 == 5){
                bill2[4] = bill2[4] + records[b].duration*fib[4].prize;
            }
        }else if(records[b].place1 == 3){
            if(records[b].place2 == 1){
                bill3[0] = bill3[0] + records[b].duration*fic[0].prize;
            }else if(records[b].place2 == 2){
                bill3[1] = bill3[1] + records[b].duration*fic[1].prize;
            }else if(records[b].place2 == 3){
                bill3[2] = bill3[2] + records[b].duration*fic[2].prize;
            }else if(records[b].place2 == 4){
                bill3[3] = bill3[3] + records[b].duration*fic[3].prize;
            }else if(records[b].place2 == 5){
                bill3[4] = bill3[4] + records[b].duration*fic[4].prize;
            }
        }
    }
    money1 = bill1[0] + bill1[1] + bill1[2] + bill1[3] + bill1[4];
    money2 = bill2[0] + bill2[1] + bill2[2] + bill2[3] + bill2[4];
    money3 = bill3[0] + bill3[1] + bill3[2] + bill3[3] + bill3[4];
    printf("健身房营业额: %.2lf\n",money1);
    printf("游泳馆营业额: %.2lf\n",money2);
    printf("足球场营业额: %.2lf\n",money3);
    
  if (money1 == money2 && money2 == money3) {
        printf("游泳馆=足球场=健身房\n");
    } else if (money1 == money2 && money1 > money3) {
        printf("健身房=游泳馆>足球场\n");
    } else if (money1 == money3 && money1 > money2) {
        printf("健身房=足球场>游泳馆\n");
    } else if (money2 == money3 && money2 > money1) {
        printf("游泳馆=足球场>健身房\n");
    } else if (money1 > money2 && money2 > money3) {
        printf("健身房>游泳馆>足球场\n");
    } else if (money1 > money3 && money3 > money2) {
        printf("健身房>足球场>游泳馆\n");
    } else if (money2 > money3 && money3 > money1) {
        printf("游泳馆>足球场>健身房\n");
    }else if (money2 > money1 && money1 > money3) {
        printf("健身房>游泳馆>足球场\n");
    }else if (money3 > money1 && money1 > money2) {
        printf("足球场>健身房>游泳馆\n");
    }else if (money3 > money2 && money2 > money1) {
        printf("足球场>游泳馆>健身房\n");
    }
    printf("输入任意键回到管理员菜单\n");
    getch();
    CLEAR
    break;
    }

}
void sort()//预定量排序
{
    while(1)
    {
     Record *records;
   records = (Record*)malloc(10000*sizeof(Record));
   FILE *fp = fopen("Test_RsvInfo01", "r");
    if (fp == NULL)
    {
        printf("Failed to open file Test_RsvInfo01.txt\n");
        return;
    }
    int count1 = 0;
    while (fscanf(fp, "%s %d %d %d %d年%d月%d日%d时 %s\n", records[count1].name, &records[count1].place1, &records[count1].place2, &records[count1].duration, &records[count1].year, &records[count1].month, &records[count1].day, &records[count1].hour, records[count1].myear) != EOF) {
        count1++;
    }
    fclose(fp);
    int i;
    int j;
    long gym1 [5];
    long gym12 [5];
    long gym2 [5];
    long gym22 [5];
    long gym3 [5];
    long gym32 [5];
     for(i=0;i<5;i++)
    {   
     gym1 [i] = 0;
     gym12 [i] = 0;
     gym2 [i] = 0;
     gym22 [i] = 0;
     gym3 [i] = 0;
     gym32 [i] = 0;
    }
    for(i=0;i<count1;i++){
        if(records[i].place1 == 1){
            if(records[i].place2 == 1){
                gym1[0]++;
                gym12[0]++;
            }else if(records[i].place2 == 2){
                gym1[1]++;
                gym12[1]++;
            }else if(records[i].place2 == 3){
                gym1[2]++;
                gym12[2]++;
            }else if(records[i].place2 == 4){
                gym1[3]++;
                gym12[3]++;
            }else if(records[i].place2 == 5){
                gym1[4]++;
                gym12[4]++;
            }
        }else if(records[i].place1 == 2){
            if(records[i].place2 == 1){
                gym2[0]++;
                gym22[0]++;
            }else if(records[i].place2 == 2){
                gym2[1]++;
                gym22[1]++;
            }else if(records[i].place2 == 3){
                gym2[2]++;
                gym22[2]++;
            }else if(records[i].place2 == 4){
                gym2[3]++;
                gym22[3]++;
            }else if(records[i].place2 == 5){
                gym2[4]++;
                gym22[4]++;
            }
        }else if(records[i].place1 == 3){
            if(records[i].place2 == 1){
                gym3[0]++;
                gym32[0]++;
            }else if(records[i].place2 == 2){
                gym3[1]++;
                gym32[1]++;
            }else if(records[i].place2 == 3){
                gym3[2]++;
                gym32[2]++;
            }else if(records[i].place2 == 4){
                gym3[3]++;
                gym32[3]++;
            }else if(records[i].place2 == 5){
                gym3[4]++;
                gym32[4]++;
            }
        }
    }
    int max;
    
    int a;
    int b;
    for(i=0;i<5;i++) 
    {
        for(j=i+1;j<5;j++)
        {
          if(gym1[i]<gym1[j])
            {
              max=gym1[i];
              gym1[i]=gym1[j];
              gym1[j]=max;
            }   
        }
    }
    for(i=0;i<5;i++) 
    {
        for(j=i+1;j<5;j++)
        {
          if(gym2[i]<gym2[j])
            {
              max=gym2[i];
              gym2[i]=gym2[j];
              gym2[j]=max;
            }   
        }
    }
    for(i=0;i<5;i++) 
    {
        for(j=i+1;j<5;j++)
        {
          if(gym3[i]<gym3[j])
            {
              max=gym3[i];
              gym3[i]=gym3[j];
              gym3[j]=max;
            }   
        }
    }
    
    printf("健身房场地排序：\n");
    for(i=0;i<5;i++){
        for(a=0;a<5;a++){
            if(gym1[i] != 0 &&gym12[a] != 0){
            if(gym1[i] == gym12[a]){
                printf("场地%d\n",a+1);
            }
            }
        }
    }
    printf("游泳馆场地排序：\n");
    for(i=0;i<5;i++){
        for(a=0;a<5;a++){
            if(gym2[i] != 0 &&gym22[a] != 0){
            if(gym2[i] == gym22[a]){
                printf("场地%d\n",a+1);
            }
            }
        }
    }
    printf("足球场场地排序：\n");
    for(i=0;i<5;i++){
        for(a=0;a<5;a++){
            if(gym3[i] != 0 &&gym32[a] != 0){
            if(gym3[i] == gym32[a]){
                printf("场地%d\n",a+1);
            }
            }
        }
    }
    int vgym1;
    int vgym2;
    int vgym3;
    vgym1 = gym1[0] + gym1[1] + gym1[2] + gym1[3] + gym1[4];
    vgym2 = gym2[0] + gym2[1] + gym2[2] + gym2[3] + gym2[4];
    vgym3 = gym3[0] + gym3[1] + gym3[2] + gym3[3] + gym3[4];
    printf("场馆总预订量排序：\n");
    if (vgym1 == vgym2 && vgym2 == vgym3) {
        printf("游泳馆=足球场=健身房\n");
    } else if (vgym1 == vgym2 && vgym1 > vgym3) {
        printf("健身房=游泳馆>足球场\n");
    } else if (vgym1 == vgym2 && vgym1 > vgym3) {
        printf("健身房=游泳馆>足球场\n");
    }else if (vgym1 == vgym3 && vgym1 < vgym2) {
        printf("健身房=足球场>游泳馆\n");
    }else if (vgym1 == vgym3 && vgym1 > vgym2) {
        printf("健身房=足球场>游泳馆\n");
    } else if (vgym2 == vgym3 && vgym2 > vgym1) {
        printf("游泳馆=足球场>健身房\n");
    } else if (vgym2 == vgym3 && vgym2 < vgym1) {
        printf("游泳馆=足球场<健身房\n");
    } else if (vgym1 > vgym2 && vgym2 > vgym3) {
        printf("健身房>游泳馆>足球场\n");
    } else if (vgym1 > vgym3 && vgym3 > vgym2) {
        printf("健身房>足球场>游泳馆\n");
    } else if (vgym2 > vgym3 && vgym3 > vgym1) {
        printf("游泳馆>足球场>健身房\n");
    }else if (vgym2 > vgym1 && vgym1 > vgym3) {
        printf("健身房>游泳馆>足球场\n");
    }else if (vgym3 > vgym1 && vgym1 > vgym2) {
        printf("足球场>健身房>游泳馆\n");
    }else if (vgym3 > vgym2 && vgym2 > vgym1) {
        printf("足球场>游泳馆>健身房\n");
    }
    printf("输入任意键回到管理员菜单\n");
    getch();
    CLEAR
    break;

    }
}