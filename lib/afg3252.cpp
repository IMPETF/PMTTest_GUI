#include "afg3252.h"

using namespace std;

AFG3252::AFG3252()
{

}

AFG3252::AFG3252(const char* name,const char* IP):
    IPaddr(IP)
{
    string rsrc="TCPIP0::";
    rsrc.append(IP);
    rsrc.append("::inst0::INSTR");
    SetResourceString(rsrc.c_str());
    SetName(name);
    Initialize();
}

void AFG3252::SetIP(const char *ip)
{
    IPaddr=ip;
    string rsrc="TCPIP0::";
    rsrc.append(IPaddr);
    rsrc.append("::inst0::INSTR");
    SetResourceString(rsrc.c_str());
}

string AFG3252::GetIP()
{
    return IPaddr;
}
