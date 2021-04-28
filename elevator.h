#ifndef ELEVATOR_H_INCLUDED
#define ELEVATOR_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;
class cpassenger
{
public:
    int from_floor;//所在楼层
    int to_floor;//要去楼层
    int in_floor;//是否在电梯中,1在，0不在
    char id;//编号
};


class elevator
{
public:
    elevator(int mf=9);//构造函数，默认9层
    ~elevator();
    void set_status(int flag);//设置电梯当前的运行状态
    void set_now(int flag);//设置当前电梯所在的楼层
    void set_button(int i,int flag);//设置电梯内按钮的明灭
    void set_floor(int i,int flag);//1有，0没有
    void set_out(int i,int flag);//1向上走，2向下走.3既有向上又有向下
    int get_floor(int i);//获得第i层是否有乘客到达的消息
    int get_out(int i);//获得第i层的请求消息
    int get_status();//获得电梯当前的状态
    int get_now();//获得电梯当前的位置
    int get_button(int i);
    void inoperate(int i);//电梯内部输入
    void outoperate();
    cpassenger p[100];//要乘坐电梯的乘客
    int counts;//乘坐该电梯乘客数
private:
    int maxfloor;//共有maxfloor层
    int run_status;//电梯运行状态，1向上，2向下,0停止
    int now_floor;//电梯当前所在楼层
    int button[10];//楼层按钮，1按下，0未按
    int floor[10];//消息队列,静态数据成员
    int eout[10];//标记来自电梯外所在的楼层
};

class building
{
public:
    building(int mf=9);
    ~building();
    elevator E;
    void dis_b();//打印模拟的电梯时刻运行
    void dis_vew();//打印电梯内部以及电梯内部的按钮
    int get_mf();
private:
    int MF;//9层楼
};

#endif // ELEVATOR_H_INCLUDED






