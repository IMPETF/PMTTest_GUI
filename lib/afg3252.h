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
    std::string IPaddr;
};

#endif // AFG3252_H
