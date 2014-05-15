#ifndef PMTVDAQMANAGER_H
#define PMTVDAQMANAGER_H

#include <string>
class PMTVDaqManager
{
public:
    PMTVDaqManager();
    virtual ~PMTVDaqManager();

//daq functions
    virtual int Connect() = 0;
    virtual int Disconnect() = 0;
    virtual void DaqStart() = 0;
    virtual void DaqStop() = 0;
    virtual int Reset() = 0;
    virtual int Clear() = 0;
//utility set functions
    void SetRawFileName(const char* filename);
    void SetLogFileName(const char* filename);
//utility get functions
    virtual std::string GetDaqType();

protected:
    std::string daqtype;
    std::string raw_filename;
    std::string log_filename;
};

#endif // PMTVDAQMANAGER_H
