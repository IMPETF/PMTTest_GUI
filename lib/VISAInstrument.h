#ifndef VISAInstrument_H
#define VISAInstrument_H

class VISAInstrument
{
public:
    VISAInstrument(const char* name);

public:
    inline void SetResourceName(const char* rcname);
    inline std::string GetResourceName();

private:
    std::string fRsrcName;
};

#endif // VISAInstrument_H
