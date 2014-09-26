#include "VISASystemManager.h"
#include "VISAInstrument.h"
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
    */
    VISAInstrument* instr1=new VISAInstrument("Serial_Test_1","ASRL5::INSTR");
    VISAInstrument* instr2=new VISAInstrument("Serial_Test_2","ASRL4::INSTR");
    VISAInstrument* instr3=new VISAInstrument("Serial_Test_3","ASRL3::INSTR");
    /*
    if(instr.Status() && visamanager->Status()){
        cout<< "Success" <<endl;
    }
    else{
        cout << "Fail" << endl;
    }
    */
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

    return 0;
}
