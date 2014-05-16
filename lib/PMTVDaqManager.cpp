#include "PMTVDaqManager.h"

PMTVDaqManager::PMTVDaqManager(const char* name)
{
    fDaqName=name;
    fPacketNum=0;
    fDaqType="NULL";
    fRawFilename="NULL";
    fLogFilename="NULL";
}

inline void PMTVDaqManager::SetRawFileName(const char *filename)
{
    fRawFilename=filename;
}

inline void PMTVDaqManager::SetRawFileName(const std::string filename)
{
    fRawFilename=filename;
}

inline void PMTVDaqManager::SetLogFileName(const char* filename)
{
    fLogFilename=filename;
}

inline void PMTVDaqManager::SetLogFileName(std::string filename)
{
    fLogFilename=filename;
}

inline std::string PMTVDaqManager::GetRawFileName()
{
    return fRawFilename;
}

inline std::string PMTVDaqManager::GetLogFileName()
{
    return fLogFilename;
}

//utility get functions
inline void PMTVDaqManager::SetDaqType(const char* type)
{
    fDaqType=type;
}

inline void PMTVDaqManager::SetDaqType(std::string type)
{
    fDaqType=type;
}

inline std::string PMTVDaqManager::GetDaqType()
{
    return fDaqType;
}

inline void PMTVDaqManager::ResetPacketNum()
{
    fPacketNum=0;
}

inline int PMTVDaqManager::GetPacketNum()
{
    return fPacketNum;
}
