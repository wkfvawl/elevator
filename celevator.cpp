#include <iostream>
#include <string>
#include "elevator.h"
using namespace std;

elevator::elevator(int mf)
{
    int i;
    maxfloor=mf;
    run_status=0;//电梯初始状态在第一层
    now_floor=1;
    counts=1;
    for(i=1; i<=mf; i++)
    {
        button[i]=0;
        floor[i]=0;
        eout[i]=0;
    }
}
elevator::~elevator()
{
}
void elevator::set_status(int flag)
{
    run_status=flag;
}
void elevator::set_now(int fl)
{
    now_floor=fl;
}
void elevator::set_button(int i,int flag)
{
    button[i]=flag;
}
void elevator::set_out(int i,int flag)//1向上走，2向下走
{
    elevator::eout[i]=flag;
}
void elevator::set_floor(int i,int flag)
{
    elevator::floor[i]=flag;
}
int elevator::get_status()
{
    return run_status;
}
int elevator::get_now()
{
    return now_floor;
}
int elevator::get_out(int i)
{
    return elevator::eout[i];
}

int elevator::get_button(int i)
{
    return button[i];
}
int elevator::get_floor(int i)
{
    return elevator::floor[i];
}

void elevator::inoperate(int i)
{
    int fl;
    cout<<"请进到电梯内乘客按下所要到达的楼层！"<<endl;
    cout<<"多个楼层中间用空格隔开，结束输入请按0：";
    while(1)
    {
        cin>>fl;
        if(fl==0)
        {
            break;
        }
        p[counts].from_floor=i;
        p[counts].to_floor=fl;
        p[counts].in_floor=1;
        p[counts].id='A'+counts-1;
        counts++;
        elevator::set_floor(fl,1);//要到达的楼层
        set_button(fl,1);//设置电梯内的显示按钮
    }

}


void elevator::outoperate()//在电梯外部发送请求时，还没有乘客上电梯
{
    int fl;
    cout<<"请电梯外部乘客按下所在楼层的上楼信号！"<<endl;
    cout<<"多个楼层用空格隔开，结束输入请按0：";
    while(1)
    {
        cin>>fl;
        if(fl==0)
        {
            break;
        }
        if(elevator::get_out(fl)==2)//若已经有了向下的信号
        {
            elevator::set_out(fl,3);
        }
        else
        {
            elevator::set_out(fl,1);//1向上走
        }
    }
    cout<<"请电梯外部乘客按下所在楼层的下楼信号！"<<endl;
    cout<<"多个楼层用空格隔开，结束输入请按0：";
    while(1)
    {
        cin>>fl;
        if(fl==0)
        {
            break;
        }
        if(elevator::get_out(fl)==1)//若已经有了向上的信号
        {
            elevator::set_out(fl,3);
        }
        else
        {
            elevator::set_out(fl,2);//2向下走
        }
    }
}

