#include "VISAInstrument.h"

VISAInstrument::VISAInstrument(const char* name)
{

}

inline void VISAInstrument::SetResourceName(const char *rcname)
{
    fRsrcName=rcname;
}

inline std::string VISAInstrument::GetResourceName()
{
    return fRsrcName;
}
