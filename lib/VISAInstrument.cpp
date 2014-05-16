#include "VISAInstrument.h"
#include "VISASystemManager.h"

VISAInstrument::VISAInstrument()
    :fStatus(VI_STATE_UNKNOWN),fViSession(VI_NULL),fDefaultRM(VI_NULL),
      fErrorCode("NULL"),fAccessMode(VI_NULL),fOpenTimeout(VI_NULL)
{
}

VISAInstrument::VISAInstrument(const char *deviceName, const char *rsrcName,ViAccessMode accessMode=VI_NULL,ViUInt32 openTimeout=VI_NULL)
    :fAccessMode(accessMode),fOpenTimeout(openTimeout)
{
    fDeviceName=deviceName;
    fRsrcName=rsrcName;
    fDefaultRM=VISASystemManager::GetInstance()->GetDefaultRM();

    Initialize();
}

VISAInstrument::~VISAInstrument()
{
    VISASystemManager::GetInstance()->DeRegister(fDeviceName);
}

bool VISAInstrument::Initialize()
{
    char desc[256];
    char error_desc[512];
    //check visa system status
    if(!VISASystemManager::Status()){
        fErrorCode="Can't Initialize VISA system";
        fStatus=VI_STATE_UNKNOWN;
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
    fStatus = viOpen(fDefaultRM,desc,fAccessMode,fOpenTimeout,&fViSession);
    if(fStatus < VI_SUCCESS){
        viStatusDesc(fViSession,fStatus,error_desc);
        fErrorCode=error_desc;
        return false;
    }
    //register this instrument
    if(!VISASystemManager::GetInstance()->Register(this)){
        fStatus=VI_STATE_UNKNOWN;
        fErrorCode="Error! DeviceName Duplication.Please Choose Another DeviceName";
        return false;
    }

    return true;
}

void VISAInstrument::Close()
{
    if(fStatus >= VI_SUCCESS)
        viClose(fViSession);
}

bool VISAInstrument::Status()
{
    if(fStatus < VI_SUCCESS)
        return false;
    else
        return true;
}

