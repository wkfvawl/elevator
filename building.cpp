#include <iostream>
#include <string>
#include "windows.h"
#include "elevator.h"
using namespace std;
building::building(int mf)
{
    MF=mf;
}

building::~building()
{

}

int building::get_mf()
{
    return MF;
}


void building::dis_b()
{
    int i;
    cout<<"\n";
    cout<<"   ******电梯系统******"<<endl;
    cout<<"\n";
    for(i=9; i>=1; i--)
    {
        cout<<"   ===================="<<endl;//20
        if(E.get_now()==i)//到达的楼层设置为红色
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
              cout<<"   |*******电梯*******|"<<endl;
            cout<<i<<"  |******************|";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原为白色
            if(E.get_out(i)==1)//该楼层有向上的请求
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
                cout<<i<<"上"<<endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原为白色
            }
            else if(E.get_out(i)==2)//该楼层有向下的请求
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
                cout<<i<<"下"<<endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原为白色
            }
            else if(E.get_out(i)==3)//该楼层既有向下的请求，又有向上的请求
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
                cout<<i<<"上-下"<<endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原为白色
            }
            else
            {
                cout<<endl;
            }
        }
        else
        {
            cout<<"   |                  |"<<endl;
            cout<<i<<"  |                  |";
            if(E.get_out(i)==1)//该楼层有向上的请求
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
                cout<<i<<"上"<<endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原为白色
            }
            else if(E.get_out(i)==2)//该楼层有向下的请求
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
                cout<<i<<"下"<<endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原为白色
            }
            else if(E.get_out(i)==3)//该楼层既有向下的请求，又有向上的请求
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
                cout<<i<<"上-下"<<endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原为白色
            }
            else
            {
                cout<<endl;
            }
        }

    }
    cout<<"   ===================="<<endl<<endl;//20
}
void building::dis_vew()
{
    cout<<"    ****电梯内按钮****"<<endl;
    cout<<"       ===========";
    if(E.get_status()==1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
        cout<<" 上"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原为白色
    }
    else
    {
        cout<<" 上"<<endl;
    }
    if(E.get_button(1)==1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
        cout<<"        1  ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原为白色
    }
    else
    {
        cout<<"        1  ";
    }
    if(E.get_button(2)==1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
        cout<<"2  ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原为白色
    }
    else
    {
        cout<<"2  ";
    }
    if(E.get_button(3)==1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
        cout<<"3  "<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原为白色
    }
    else
    {
        cout<<"3  "<<endl;
    }
    if(E.get_button(4)==1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
        cout<<"        4  ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原为白色
    }
    else
    {
        cout<<"        4  ";
    }
    if(E.get_button(5)==1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
        cout<<"5  ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原为白色
    }
    else
    {
        cout<<"5  ";
    }
    if(E.get_button(6)==1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
        cout<<"6  "<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原为白色
    }
    else
    {
        cout<<"6  "<<endl;
    }
    if(E.get_button(7)==1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
        cout<<"        7  ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原为白色
    }
    else
    {
        cout<<"        7  ";
    }
    if(E.get_button(8)==1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
        cout<<"8  ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原为白色
    }
    else
    {
        cout<<"8  ";
    }
    if(E.get_button(9)==1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
        cout<<"9  "<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原为白色
    }
    else
    {
        cout<<"9  "<<endl;
    }
    cout<<"       ===========";
    if(E.get_status()==2)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
        cout<<" 下"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原为白色
    }
    else
    {
        cout<<" 下"<<endl;
    }
    cout<<"   ===================="<<endl;//20
    int i;
    for(i=1; i<=E.counts; i++)
    {
        if(E.p[i].in_floor==1)
        {
            cout<<"   ";
            cout<<E.p[i].id<<" from "<<E.p[i].from_floor<<" -> "<<E.p[i].to_floor<<endl;
        }
    }
    cout<<"   ===================="<<endl;//20
}
