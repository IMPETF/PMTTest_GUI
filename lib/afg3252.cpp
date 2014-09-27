#include "afg3252.h"

using namespace std;

AFG3252::AFG3252()
{

}

AFG3252::AFG3252(const char* name,const char* IP) :
    IPaddr(IP)
{
    string rsrc="TCPIP0::";
    rsrc.append(IP);
    rsrc.append("::inst0::INSTR");
    VISAInstrument(name,rsrc.c_str());
}

