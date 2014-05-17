#ifndef PMTVDAQMANAGER_H
#define PMTVDAQMANAGER_H

#include <string>
class PMTVDaqManager
{
public:
    PMTVDaqManager();
    PMTVDaqManager(const char* name);
    virtual ~PMTVDaqManager(){}

//daq functions
    virtual int Initialize() = 0;
    virtual int Connect() = 0;
    virtual int Disconnect() = 0;
    virtual void DaqStart() = 0;
    virtual void DaqStop() = 0;
    virtual int Reset() = 0;
    virtual int Clear() = 0;
//utility set functions
    inline void SetRawFileName(const char* filename);
    inline void SetRawFileName(const std::string filename);
    inline void SetLogFileName(const char* filename);
    inline void SetLogFileName(std::string filename);
    inline std::string GetRawFileName();
    inline std::string GetLogFileName();
//utility get functions
    inline void SetDaqType(const char* type);
    inline void SetDaqType(std::string type);
    inline std::string GetDaqType();
    inline void ResetPacketNum();
    inline int GetPacketNum();

protected:
    int fPacketNum;
    std::string fDaqName;
    std::string fDaqType;
    std::string fRawFilename;
    std::string fLogFilename;
};

#endif // PMTVDAQMANAGER_H
