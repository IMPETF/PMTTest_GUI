#include "PSDUSBInterface.h"

PSDUSBInterface::PSDUSBInterface()
{
}

PSDUSBInterface::PSDUSBInterface(const char *deviceName, const char *rsrcName, ViAccessMode accessMode, ViUInt32 openTimeout)
    :VISAInstrument(deviceName,rsrcName,accessMode,openTimeout)
{

}

PSDUSBInterface::~PSDUSBInterface()
{

}

bool PSDUSBInterface::SendCommand(unsigned char *command)
{
    int n;
    char error_desc[512];
    if(Status())
        fStatus=viWrite(fViSession,command,2,&n);
    else
        return false;

    if(fStatus == VI_SUCCESS){
        return true;
    }
    else{
        viStatusDesc(fViSession,fStatus,error_desc);
        fErrorCode=error_desc;
        return false;
    }
}

bool PSDUSBInterface::StartAcq()
{
    unsigned char Command[2];
    Command[0]=0x00;
    Command[1]=0x01;
    return SendCommand(Command);
}

bool PSDUSBInterface::StopAcq()
{
    unsigned char Command[2];
    Command[0]=0x00;
    Command[1]=0x02;
    return SendCommand(Command);
}

bool PSDUSBInterface::SoftReset()
{
    unsigned char Command[2];
    Command[0]=0x00;
    Command[1]=0x0f;
    return SendCommand(Command);
}

bool PSDUSBInterface::FEESet(int M, int N)
{
    unsigned char Command[2];
    Command[0]=0x20+M;
    Command[1]=N;
    return SendCommand(Command);
}

bool PSDUSBInterface::EnableFEEChn(int FEEID)
{
    unsigned char Command[2];
    Command[0]=0x00;
    Command[1]=0x10+FEEID;
    return SendCommand(Command);
}

bool PSDUSBInterface::DisableFEEChn(int FEEID)
{
    unsigned char Command[2];
    Command[0]=0x00;
    Command[1]=0x20+FEEID;
    return SendCommand(Command);
}

bool PSDUSBInterface::EnableFEECmdChn(int FEEID)
{
    unsigned char Command[2];
    Command[0]=0x00;
    Command[1]=0x90+FEEID;
    return SendCommand(Command);
}

bool PSDUSBInterface::DisableFEECmdChn(int FEEID)
{
    unsigned char Command[2];
    Command[0]=0x00;
    Command[1]=0xa0+FEEID;
    return SendCommand(Command);
}

bool PSDUSBInterface::SelectMasterFEEChn(int FEEID)
{
    unsigned char Command[2];
    Command[0]=0x00;
    Command[1]=0x30+FEEID;
    return SendCommand(Command);
}

bool PSDUSBInterface::SelectBackupFEEChn(int FEEID)
{
    unsigned char Command[2];
    Command[0]=0x00;
    Command[1]=0x40+FEEID;
    return SendCommand(Command);
}

bool PSDUSBInterface::SelectMasterCOMChn(int FEEID)
{
    unsigned char Command[2];
    Command[0]=0x00;
    Command[1]=0x80+FEEID;
    return SendCommand(Command);
}

bool PSDUSBInterface::SelectBackupCOMChn(int FEEID)
{
    unsigned char Command[2];
    Command[0]=0x00;
    Command[1]=0x90+FEEID;
    return SendCommand(Command);
}

bool PSDUSBInterface::SelectTrigMode(int Mode)
{
    unsigned char Command[2];
    Command[0]=0x00;
    Command[1]=0x50+(0x01<<(Mode));
    return SendCommand(Command);
}

bool PSDUSBInterface::OpenTrig()
{
    unsigned char Command[2];
    Command[0]=0x00;
    Command[1]=0x51;
    return SendCommand(Command);
}

bool PSDUSBInterface::CloseTrig()
{
    unsigned char Command[2];
    Command[0]=0x00;
    Command[1]=0x52;
    return SendCommand(Command);
}

bool PSDUSBInterface::CalibInternal(int Time)
{
    unsigned char Command[2];
    int LowBits, HighBits;
    LowBits=Time&0xff;
    HighBits=(Time>>8)&0x0f;
    Command[0]=HighBits+0x10;
    Command[1]=LowBits;
    return SendCommand(Command);
}

bool PSDUSBInterface::StartCalib()
{
    unsigned char Command[2];
    Command[0]=0x00;
    Command[1]=0x03;
    return SendCommand(Command);
}

bool PSDUSBInterface::ClearFIFO()
{
    unsigned char Command[2];
    Command[0]=0x00;
    Command[1]=0xa0;
    return SendCommand(Command);
}

bool PSDUSBInterface::SetFIFO()
{
    unsigned char Command[2];
    Command[0]=0x00;
    Command[1]=0xb0;
    return SendCommand(Command);
}
