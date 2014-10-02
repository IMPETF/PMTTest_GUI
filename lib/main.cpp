#include "SY1527.h"
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
        sprintf(channel.ch_name,"PPMT%2d",i+1);
        channels.push_back(channel);
    }

    SYX527_Module module(sy1527,13,channels);
    module.setVSet(40);
    module.setISet(30);
    module.setRampUp(20);
    module.setRampDown(20);

    if(!module.updateChName()){
        cout<<"can't setname"<<endl;
        return false;
    }

    delete sy1527;

    return 0;
}
