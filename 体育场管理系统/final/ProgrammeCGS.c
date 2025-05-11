/****************************************************************************************

尊敬的老师：
    
    很荣幸能由您来审核我们的小程序。我将这些注释放在最前面，是想借此总体来说说我们的小程序。

    首先，我们写的是体育场馆的综合管理系统。作为综合管理系统，我们认为有两点是重中之重：
1.更加人性化的交互机制，方便用户使用
2.更加标准化的代码书写，方便开发人员后期维护、更新。

    然而，在实践中我们发现，这两点很难被同时满足。越是开发方便用户的功能，其源代码就会越复杂；
越是书写简单易懂的代码，用户可用的功能就会越少。面对这种矛盾的情况，我小组决定“以人为本”，在
尽量保证代码的可读性的同时，我们尽可能多的模拟真实情况，为用户提供更多便捷的操作。

    最后，我们做出如下承诺：
*我们没有任何一行代码是抄袭他人劳动成果。
*我们尽力完成了每一项规定要求。
*我们尽最大努力优化代码、标注注释，并且尽量用相似的方式区处理类似的问题，以求代码符合规范标准。

                                                小组全体成员：茅行之，莫家瑞，王子轩，尹承泽，卢轲舰
                                                                2023年9月6日夜

****************************************************************************************/


/*我们小组一共分出了4个C源文件和一个C源头文件分别是：

    总框架：                                 ComprehensiveGymSys.c      
    用户端框架和其下设的几乎所有功能：         User_By_Raleigh.c
    管理员端框架及其下设部分功能：             Manager_By_Gerry.c  
    各种功能性函数合集：                      Basic.c
    各类结构定义，全局定义，宏定义：           Basic.h

*/

#include "Manager_By_Gerry.c"//我们确定的引用规则是：  ComprehensiveGymSys.c --> Manager_By_Gerry.c --> User_By_Raleigh.c --> Basic.c --> Basic.h

/*
   
 __          __      __
 \ \        / /     |  |
  \ \  /\  / / ____ |  | ____  _____  __  ___  ____    ____
   \ \/  \/ /   __ \   |/ ____/  _  \|  '__  ' __  \ /  __ \
    \  /\  /    ___/|  | (___|  ( )  |  |  |  |  |  |   ___/
     \/  \/  \_____ |__|\_____\_____/|__|  |__|  |__|\____ 
   
*/



//主菜单函数及其下设功能函数的声明
void MainMenu();                          //主菜单   
void UserMenu();                          //用户菜单
void ManagerLogin();                      //管理员登陆
void ManagerRegister();                   //调试函数，录入文件


int main(void)
{
    CLEAR;//我们写的一个清屏的宏定义，详见Basic.h
    delet_Rsv();//根据当前日期，删除掉过期的场馆预约信息
    printf(" __          __      __\n");
    printf(" \\ \\        / /     |  |\n");
    printf("  \\ \\  /\\  / / ____ |  | ____  _____  __  ___  ____    ____\n");
    printf("   \\ \\/  \\/ /   __ \\   |/ ____/  _  \\|  '__  ' __  \\ /  __ \\ \n");
    printf("    \\  /\\  /    ___/|  | (___|  ( )  |  |  |  |  |  |   ___/\n");
    printf("     \\/  \\/  \\_____ |__|\\_____\\_____/|__|  |__|  |__|\\_____ \n");
    printf("\n\n欢迎使用综合体育场管理系统(ComprehensiveGymSys)\n");
    printf("为了确保您的使用体验, 您需要了解:\n");
    printf("1.请您全程使用美式键盘, 否则无法体验“按任意键继续”的功能。\n");
    printf("2.在任何情况下都不要输入汉字, 因编码问题可能导致您的信息无法保存。\n");
    printf("3.本程序尚处测试阶段, 未投入商业化使用。管理员注册许可码为123456。用户充值的礼品码详见相关界面。\n");
    printf("祝您生活愉快!\n");
    printf("(按任意键继续)\n");
    fflush(stdin);
    getch();
    CLEAR
    MainMenu(); 
    CLEAR
    printf("程序已结束\n");
    return 0;
}

void MainMenu()//主菜单函数
{
    char str[2]={'\000', '\000'};    //使用数组str[]记录用户的输入。选用数组是为了防止用户输入字符串。正常情况下，用户的输入存在str[0]
    printf("******欢迎进入体育馆综合管理系统******\n\n提示: 请输入数字1~4\n");
    printf("1.用户界面\n");
    printf("2.管理员登陆\n");
    printf("3.管理员注册\n");
    printf("4.结束程序\n");

    while(1)
    {
        while(1)            //检查用户输入是否为单个字符
        {
            
            fflush(stdin);
            str[1]='\000';
            scanf("%s",str);
            fflush(stdin);
            if(str[1]=='\000')
                break;
            CLEAR
            printf("******欢迎进入体育馆综合管理系统******\n\n提示: 输入有误, 请输入数字1~4\n");
            printf("1.用户界面\n");
            printf("2.管理员登陆\n");
            printf("3.管理员注册\n");
            printf("4.结束程序\n");
            fflush(stdin);
        }
        switch (str[0])
        {
        case '1':
            UserMenu();
            break; 

        case '2':
            ManagerLogin();         
            break;
        
        case '3':
            ManagerRegister();           
            break;

        case '4':
            return;

        default:
            CLEAR
            printf("******欢迎进入体育馆综合管理系统******\n\n提示: 输入有误, 请输入数字1~4\n");
            printf("1.用户界面\n");
            printf("4.管理员登陆\n");
            printf("4.管理员注册\n");
            printf("5.结束程序\n");
            break;
        }
    }
}

/*以上是我们最常用的一个获取用户输入的循环结构，您会在后面多次看到它。我们在这里做统一的说明：
    
    我们利用str[2]数组记录用户输入，用index01控制外层循环（这里没有用到index01）；我们用了一个while循环，里面嵌套了一个while循环和switch语句
采用str[]数组记录输入，是为了避免用户输入字符串。内部嵌套的第一个循环将检测是否输入单个字符。后面的switch语句将读取用户的输入
    
    之所采用循环套用循环，是为了让用户输入错误后能够快捷的再次输入本次需要键入的信息。在之后的注册等环节，每一次键入信息都采用了这样
的结构，使得用户一个信息输入错误，不需要受到重新全部输入的惩罚

    这个结构的模式是：
                    printf(用户本次需要键入的信息)
                    index01=1
                    while(index01)
                    {
                        while(1)
                        {
                            ....
                        }
                        switch(str[0])
                        {
                            ...
                        }
                    }
    您以后再次看到这个结构，便能理解这是一个用户键入数据的结构，并且您能知道用户应该键入什么数据
*/


void UserMenu()//用户菜单函数
{
    FILE* fp;                     //变量声明
    char str[2]={'\000', '\000'};    
    index00=0;//是一个全域变量，声明放在了Basic.h 。其功能是判定用户有没有成功登陆/注册
    RsvInfo test;
    CLEAR
    UserLogin();
    if(index00==0)//若为0，则未成功登陆/注册，返回主菜单函数
        return;
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
     
    while(1)
    {
        str[1]='\000';
        scanf("%s",str);
        fflush(stdin);  
        while(1)
        {
            if(str[1]=='\000')
                break;
            CLEAR
            printf("尊敬的 %s ",YOU.name);
            if(YOU.gender==1)
                printf("先生");
            if(YOU.gender==2)
                printf("女士");
            printf(", 您已登陆账户 %s \n\n提示: ", YOU.id);
            printf("输入有误! 请输入数字0~6\n");
            printf("0.退出登陆\n");
            printf("1.查看个人信息\n");
            printf("2.修改个人信息\n");
            printf("3.查询个人订单\n");
            printf("4.查询场馆信息: 精准查找单个场馆\n");
            printf("5.查询场馆信息: 对比所有场馆预约信息\n");
            printf("6.场馆预约\n");
            printf("7.余额查询/充值\n");
            str[1]='\000';
            fflush(stdin);
            scanf("%s",str);
            fflush(stdin);
        }
        switch (str[0])
        {
        case '0':
            CLEAR
            printf("******欢迎进入体育馆综合管理系统******\n\n提示: 请输入数字1~4\n");
            printf("1.用户界面\n");
            printf("2.管理员登陆\n");
            printf("3.管理员注册\n");
            printf("4.结束程序\n");
            return;//返回主菜单函数

        case '1':
            CLEAR
            printf("请仔细核对您的信息, 按任意键退出当前界面\n\n");
            printf("用户名: %s\n姓名: %s\n", YOU.id, YOU.name);
            if(YOU.gender==1)
                printf("性别: 男\n");
            if(YOU.gender==2)
                printf("性别: 女\n");
            printf("年龄: %d\n邮箱: %s\n电话: %s\n地址: ", YOU.age, YOU.mail, YOU.tel);//YOU是一个全域变量，类型是struct _Userinfo（详见Basic.h)，用户成功登陆后，YOU将储存用户的信息
            if(YOU.address==1)
                printf("海淀区\n");
            if(YOU.address==2)
                printf("丰台区\n");
            if(YOU.address==3)
                printf("西城区\n");
            if(YOU.address==4)
                printf("其它\n");
            printf("爽约记录: %d次\n余额: %.2lf\n", YOU.timez, YOU.val);
            fflush(stdin);
            printf("按任意键继续");
            getch();
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
            break;

        case '2':
            Userchangeinfo();
            break;

        case '3':
            UserAfterRsv();
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
            break;
            
        case '4':
            CLEAR
            UserPreRsv1();
            break;

        case '5':
            CLEAR
            UserPreRsv2();
            break;

        case '6':
            UserRsv();
            CLEAR
            break;

        case '7':
            Recharge();
            break;

        default:
            CLEAR
            printf("尊敬的 %s ",YOU.name);
            if(YOU.gender==1)
                printf("先生");
            if(YOU.gender==2)
                printf("女士");
            printf(", 您已登陆账户 %s \n\n提示: ", YOU.id);
            printf("输入有误! 请输入数字0~6\n");
            printf("0.退出登陆\n");
            printf("1.查看个人信息\n");
            printf("2.修改个人信息\n");
            printf("3.查询个人订单\n");
            printf("4.查询场馆信息: 精准查找单个场馆\n");
            printf("5.查询场馆信息: 对比所有场馆预约信息\n");
            printf("6.场馆预约\n");
            printf("7.余额查询/充值\n");
            break;
        }   
    }
}