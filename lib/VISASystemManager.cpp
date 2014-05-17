#include "VISASystemManager.h"
#include "VISAInstrument.h"

VISASystemManager* VISASystemManager::fInstance = 0;
ViSession VISASystemManager::fDefaultRM=0;
ViStatus VISASystemManager::fStatus=VI_STATE_UNKNOWN;

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
    std::string deviceName=instr->GetName();
    std::pair<std::map<std::string,VISAInstrument*>::iterator,bool> ret;
    ret=GetInstance()->insert(std::pair<std::string,VISAInstrument*>(deviceName,instr));
    return ret.second;
}

void VISASystemManager::DeRegister(std::string deviceName)
{
    iterator it;
    VISASystemManager* self=GetInstance();
    //auto it=fActiveInstruments.find(deviceName);
    it=self->find(deviceName);
    if(it!=self->end()){
        it->second->Close();
        self->erase(it);
    }
}

void VISASystemManager::Clean()
{
    iterator it;
    VISASystemManager* self=GetInstance();
    for(it=self->begin();it!=self->end();++it){
        it->second->Close();
        //delete it->second;
    }
    self->clear();
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
