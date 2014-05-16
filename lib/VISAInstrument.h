#ifndef VISAInstrument_H
#define VISAInstrument_H

#include <string>
#include "visa.h"

class VISAInstrument
{
public:
    VISAInstrument(const char* deviceName,const char* rsrcName);
    ~VISAInstrument();
public:
    inline void SetName(const char* name)
    { fDeviceName = name; }
    inline std::string GetName()
    { return fDeviceName; }
    inline void SetResourceString(const char* rcname)
    { fRsrcName=rcname; }
    inline std::string GetResourceString()
    { return fRsrcName; }

    bool Initialize();
    void Close();
    bool Status();
    std::string ErrorCode();

protected:
    std::string fErrorCode;

private:
    std::string fDeviceName;//Unique Name idetify the intrument
    std::string fRsrcName;//Rsrc string
    ViSession   fDefaultRM;
    ViSession   fViSession;//ViSession
    ViStatus    fStatus;
};

#endif // VISAInstrument_H
