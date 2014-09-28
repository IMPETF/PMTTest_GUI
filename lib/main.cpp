#include "afg3252.h"
#include <iostream>

using namespace std;
int main(int argc,char* argv[])
{

    /*
    VISASystemManager* visamanager=VISASystemManager::GetInstance();
    if(!visamanager->Status()){
        cout<<"can't initialize VISA system"<<endl;
        return -1;
    }

    VISAInstrument* instr1=new VISAInstrument("Serial_Test_1","ASRL5::INSTR");
    VISAInstrument* instr2=new VISAInstrument("Serial_Test_2","ASRL4::INSTR");
    VISAInstrument* instr3=new VISAInstrument("Serial_Test_3","ASRL3::INSTR");

    if(instr.Status() && visamanager->Status()){
        cout<< "Success" <<endl;
    }
    else{
        cout << "Fail" << endl;
    }

    VISASystemManager* visamanager=VISASystemManager::GetInstance();
    cout<< "VISA Active Instruments:"<<endl;
    cout<<"Total Num: "<<visamanager->size()<<endl;
    if(visamanager->size()){
        int i=0;
        VISASystemManager::iterator it;
        for(it=visamanager->begin();it!=visamanager->end();++it){
            cout<< i+1 <<") "<< it->second->GetName()<<", "<< it->second->GetResourceString()<<", "<< it->second->GetRsrcDesc() <<endl;
        }
    }
*/

    char buffer1[256],buffer2[256];
    AFG3252* led=new AFG3252("led_pulser","192.168.1.102");
    led->TurnOnFrqConcurrent(1);
    led->PhaseInitiate();
    led->SetShape(1);led->SetShape(2);

    cout<<"Item\t"<<"CH1\t"<<"CH2"<<endl;

    led->SetFrequency(1,1000,"Hz");
    led->GetFrequency(1,buffer1);led->GetFrequency(2,buffer2);
    cout<<"Frq\t"<<buffer1<<"\t"<<buffer2<<endl;

    led->SetPulseWidth(1,40);
    led->GetPulseWidth(1,buffer1);
    cout<<"Width\t"<<buffer1<<endl;

    led->SetVoltageLow(1,0);
    led->SetVoltageHigh(1,3.55);
    led->GetVoltageHigh(1,buffer1);led->GetVoltageHigh(2,buffer2);
    cout<<"Volt\t"<<buffer1<<"\t"<<buffer2<<endl;

    led->SetPulseDelay(2,30);
    led->GetPulseDelay(1,buffer1);led->GetPulseDelay(2,buffer2);
    cout<<"Delay\t"<<buffer1<<"\t"<<buffer2<<endl;

    delete led;
    return 0;
}
