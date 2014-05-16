#include "VISAInstrument.h"
#include "VISASystemManager.h"

VISAInstrument::VISAInstrument(const char *deviceName, const char *rsrcName)
{
    fDeviceName=deviceName;
    fRsrcName=rsrcName;
    fDefaultRM=VISASystemManager::GetInstance()->GetDefaultRM();

    Initialize();
}

VISAInstrument::~VISAInstrument()
{
    Close();
}

bool VISAInstrument::Initialize()
{
    char desc[256];
    char error_desc[512];
    //check visa system status
    if(!VISASystemManager::Status()){
        fErrorCode="Can't Initialize VISA system";
        return false;
    }
    //find exactly the unique specified instr,no findlist
    fStatus = viFindRsrc(fDefaultRM,fRsrcName.data(),VI_NULL,VI_NULL,desc);
    if(fStatus < VI_SUCCESS){
        viStatusDesc(fViSession,fStatus,error_desc);
        fErrorCode=error_desc;
        return false;
    }
    //viopen,default timeout 2s,default access mode
    fStatus = viOpen(fDefaultRM,desc,VI_NULL,VI_NULL,&fViSession);
    if(fStatus < VI_SUCCESS){
        viStatusDesc(fViSession,fStatus,error_desc);
        fErrorCode=error_desc;
        return false;
    }
    //register this instrument
    VISASystemManager::GetInstance()->Register(this);

    return true;
}

void VISAInstrument::Close()
{
    VISASystemManager::GetInstance()->DeRegister(this);
}
