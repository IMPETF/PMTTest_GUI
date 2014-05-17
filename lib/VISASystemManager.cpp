#include "VISASystemManager.h"

VISASystemManager* VISASystemManager::fInstance = 0;
ViSession VISASystemManager::fDefaultRM=0;
ViStatus VISASystemManager::fStatus=VI_STATE_UNKNOWN;
std::map<std::string,VISAInstrument*> VISASystemManager::fActiveInstruments;

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
    ret=fActiveInstruments.insert(std::pair<std::string,VISAInstrument*>(deviceName,instr));
    return ret.second;
}

void VISASystemManager::DeRegister(std::string deviceName)
{
    std::map<std::string,VISAInstrument*>::iterator it;
    it=fActiveInstruments.find(deviceName);
    if(it!=fActiveInstruments.end()){
        fActiveInstruments.erase(it);
        it->second->Close();
    }
}

void VISASystemManager::Clean()
{
    std::map<std::string,VISAInstrument*>::iterator it;
    for(it=fActiveInstruments.begin();it!=fActiveInstruments.end();++it){
        it->second->Close();
    }
    fActiveInstruments.clear();
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
