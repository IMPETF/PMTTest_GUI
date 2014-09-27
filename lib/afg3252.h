#ifndef AFG3252_H
#define AFG3252_H
#include <string>
#include "VISAInstrument.h"

class AFG3252 : public VISAInstrument
{
public:
    AFG3252();
    AFG3252(const char* IP);
    ~AFG3252();

private:
    //copy control, declared but not implemented,users should not copy an VISAInstrument
    AFG3252(const AFG3252&);
    AFG3252& operator =(const AFG3252& rhs);

public:
    void SetIP(const char* ip);
    std::string GetIP();

    bool PowerOn(int channel);
    bool PowerOff(int channel);
private:
    std::string IPaddr;
};

#endif // AFG3252_H
