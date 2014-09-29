#ifndef SY1527_H
#define SY1527_H
#include <string>
#include <vector>
#include <map>
#include "caenhvwrapper/include/CAENHVWrapper.h"

struct HVChannel
{
    int slot;
    ushort ch_id;
    char ch_name[MAX_CH_NAME];
    float V0Set;
    float I0Set;
    float VMon;
    float IMon;
};
typedef std::vector<HVChannel> HVChannels;
typedef std::map<int,HVChannels> HVGroup;

class SYX527_Module
{
public:
    SYX527_Module(int slot,HVChannels& group);
    ~SYX527_Module();

public:
    inline void setVSet(float vset) {fVset=vset;}
    inline void setISet(float iset) {fISet=iset;}
    inline void setfRUp(float rup) {fRUp=rup;}
    inline void setfRDWn(float rdown) {fRDWn=rdown;}

private:
    int slot;
    ushort fChNum;
    ushort *fChList;
    std::string *fChSetName;

    //input
    float fVSet;
    float fISet;
    //ushort fPw;
    float fRUp;
    float fRDWn;

    //output
    float *fV0Set;
    float *fI0Set;
    float *fVMon;
    float *fIMon;
    char (*fChName)[MAX_CH_NAME];

};

class SY1527
{
public:
    SY1527();
};

#endif // SY1527_H
