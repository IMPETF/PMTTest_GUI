#include "VISASystemManager.h"

VISASystemManager::VISASystemManager()
{
    fStatus = viOpenDefaultRM(&fDefaultRM);
}

VISASystemManager::~VISASystemManager()
{
    Clean();
}
VISASystemManager* VISASystemManager::GetInstance()
{
    static VISASystemManager visamanager;
    if(!fInstance){
        fInstance=&visamanager;
    }
    return fInstance;
}

bool VISASystemManager::Register(VISAInstrument *instr)
{

}

void VISASystemManager::DeRegister(VISAInstrument *instr)
{

}

void VISASystemManager::Clean()
{

}

ViSession VISASystemManager::GetDefaultRM()
{
    return fDefaultRM;
}

ViStatus VISASystemManager::ReInit()
{
    fStatus=viOpenDefaultRM(&fDefaultRM);
    return fStatus;
}

bool VISASystemManager::Status()
{
    if(fStatus < VI_SUCCESS)
        return false;
    else
        return true;
}
