#ifndef VISASYSTEMMANAGER_H
#define VISASYSTEMMANAGER_H
#include <string>
#include <map>
#include "visa.h"
#include "VISAInstrument.h"

class VISASystemManager
{
public:
    static VISASystemManager* GetInstance();
    static void Register(VISAInstrument* instr);
    static void DeRegister(VISAInstrument* instr);
    static void Clean();

    bool Status();
private:
    VISASystemManager();

private:
    ViSession fDefaultRM;
    std::map<std::string,std::string> fActiveInstruments;
};

#endif // VISASYSTEMMANAGER_H
