#include "SYX527.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc,char* argv[])
{
    SYX527* sy1527=new SYX527("192.168.1.105","user","user");
    if(!sy1527->connect()){
        cout<<"can't connect"<<endl;
        return false;
    }
    if(!sy1527->disConnect()){
        cout<<"can't disconnect"<<endl;
        return false;
    }

    HVChannels channels;
    HVChannel channel;
    for(int i=0;i<5;i++){
        channel.slot=13;
        channel.ch_id=i;
        sprintf(channel.ch_name,"PP%d",i+1);
        channels.push_back(channel);
    }

    SYX527_Module module(sy1527,13,channels);
    module.setVSet(40);
    module.setISet(20);
    module.setRampUp(10);
    module.setRampDown(10);
    module.updateChName();
    module.updateVSet();
    module.updateISet();
    module.updateRampUp();
    module.updateRampDown();

    module.PowerOn();

    for(int j=0;j<10;j++){
        Sleep(1000);
    module.update(channels);

    for(unsigned int i=0;i<channels.size();i++){
        cout<<channels[i].ch_name<<"\t";
        cout<<channels[i].slot<<"_"<<channels[i].ch_id<<"\t";
        cout<<channels[i].V0Set<<"\t";
        cout<<channels[i].I0Set<<"\t";
        cout<<channels[i].VMon<<"\t";
        cout<<channels[i].IMon<<"\t";//<<endl;
        cout<<channels[i].state<<endl;
    }
    cout<<endl;
}
/*
    if(!module.updateChName()){
        cout<<"can't setname"<<endl;
        return false;
    }

    sy1527->connect();
    char temp[50];
    if(!sy1527->setChName(13,5,"P06")){
        cout<<"can't set single chname"<<endl;
        return false;
    }
    sy1527->getChName(13,6,temp);
    //cout<< temp <<endl;
    sy1527->disConnect();

    if(!module.updateVSet()){
        cout<<"can't setvset"<<endl;
        return false;
    }

    if(!module.updateISet()){
        cout<<"can't setIset"<<endl;
        return false;
    }

    if(!module.updateRampUp()){
        cout<<"can't rup"<<endl;
        return false;
    }

    if(!module.updateRampDown()){
        cout<<"can't rdwn"<<endl;
        return false;
    }
*/


    delete sy1527;

    return 0;
}
