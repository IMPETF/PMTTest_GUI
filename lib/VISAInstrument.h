#ifndef VISAInstrument_H
#define VISAInstrument_H

#include <string>
#include "visa.h"

class VISAInstrument
{
public:
    VISAInstrument();
    VISAInstrument(const char* deviceName,const char* rsrcName,ViAccessMode accessMode=VI_NULL,ViUInt32 openTimeout=VI_NULL);
    virtual ~VISAInstrument();
public:
    inline void SetName(const char* name)
    { fDeviceName = name; }
    inline std::string GetName()
    { return fDeviceName; }
    inline void SetResourceString(const char* rcname)
    { fRsrcName=rcname; }
    inline std::string GetResourceString()
    { return fRsrcName; }
    inline std::string ErrorCode()
    { return fErrorCode; }

    bool Status();

protected:
    bool Initialize();
    void Close();

    std::string fErrorCode;

private:
    std::string fDeviceName;//Unique Name idetify the intrument
    std::string fRsrcName;//Rsrc string
    ViSession   fDefaultRM;
    ViSession   fViSession;//ViSession
    ViStatus    fStatus;
    ViAccessMode fAccessMode;
    ViUInt32     fOpenTimeout;
};

#endif // VISAInstrument_H
