#ifndef PSDUSBINTERFACE_H
#define PSDUSBINTERFACE_H
#include "VISAInstrument.h"

class PSDUSBInterface : public VISAInstrument
{
public:
    PSDUSBInterface();
    PSDUSBInterface(const char* deviceName,const char* rsrcName,ViAccessMode accessMode=VI_NULL,ViUInt32 openTimeout=VI_NULL);
    virtual ~PSDUSBInterface();

    bool StartAcq();
    bool StopAcq();
    bool SoftReset();
    bool FEESet(int M,int N);
    bool EnableFEEChn(int FEEID);
    bool DisableFEEChn(int FEEID);
    bool EnableFEECmdChn(int FEEID);
    bool DisableFEECmdChn(int FEEID);
    bool SelectMasterFEEChn(int FEEID);
    bool SelectBackupFEEChn(int FEEID);
    bool SelectMasterCOMChn(int FEEID);
    bool SelectBackupCOMChn(int FEEID);
    bool SelectTrigMode(int Mode);
    bool OpenTrig();
    bool CloseTrig();
    bool CalibInternal(int Time);
    bool StartCalib();
    bool ClearFIFO();
    bool SetFIFO();

private:
    bool SendCommand(unsigned char* command);

};

#endif // PSDUSBINTERFACE_H
