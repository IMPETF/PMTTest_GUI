#include "SY1527.h"

using namespace std;

SY1527::SY1527():
    fStatus(CAENHV_OK)
{

}

SY1527::SY1527(const char *IP, const char *usrName, const char *pssWord):
    fIPAddr(IP),fUserName(usrName),fPassWord(pssWord),handle(0),fSatus(CAENHV_OK)
{

}

SY1527::~SY1527()
{

}

bool SY1527::status()
{
    if(fStatus == CAENHV_OK)
        return true;
    else
        return false;
}

string SY1527::getErrorDesc()
{
    return fErrorDesc;
}

bool SY1527::connect()
{
    fStatus=CAENHV_InitSystem(SY1527,LINKTYPE_TCPIP,fIPAddr.c_str(),
                              fUserName.c_str(),fPassWord.c_str(),&fHandle);
    if(fStatus != CAENHV_OK){
        fErrorDesc="Can't connect SY1527";
        return false;
    }
    else
        return true;
}

bool SY1527::disConnect()
{
    fStatus=CAENHV_DeinitSystem(fHandle);
    if(fStatus != CAENHV_OK){
        fErrorDesc="Can't disconnect SY1527";
        return false;
    }
    else
        return true;
}

bool SY1527::setChName(unsigned short slot, unsigned short chnum, const unsigned short *chlist, const char *chname)
{
    fStatus=CAENHV_SetChName(fHandle,slot,chnum,chlist,chname);
    if(fStatus != CAENHV_OK){
        fErrorDesc=CAENHV_GetError(fHandle);
        return false;
    }
    else
        return true;
}

bool SY1527::setChName(unsigned short slot, unsigned short ch_id, const char *chname)
{
    fStatus=CAENHV_SetChName(fHandle,slot,1,&ch_id,chname);
    if(fStatus != CAENHV_OK){
        fErrorDesc=CAENHV_GetError(fHandle);
        return false;
    }
    else
        return true;
}

bool SY1527::setChName(const HVChannels &channels)
{
    HVChannels::iterator it;
    for(it=channels.begin();it!=channels.end();it++){
        if(!setChName(*it))
            return false;
    }
    return true;
}

bool SY1527::setChName(const HVChannel &channel)
{
    fStatus=CAENHV_SetChName(fHandle,channel.slot,1,&(channel.ch_id),channel.ch_name);
    if(fStatus != CAENHV_OK){
        fErrorDesc=CAENHV_GetError(fHandle);
        return false;
    }
    else
        return true;
}

bool SY1527::getChName(unsigned short slot, unsigned short ch_num, const unsigned short *chlist, char (*chname)[])
{
    fStatus=CAENHV_GetChName(fHandle,slot,ch_num,chlist,chname);
    if(fStatus != CAENHV_OK){
        fErrorDesc=CAENHV_GetError(fHandle);
        return false;
    }
    else
        return true;
}

bool SY1527::getChName(unsigned short slot, unsigned short ch_id, char *chname)
{
    return getChName(slot,1,&ch_id,chname);
}

bool SY1527::getChName(HVChannel &channel)
{
    return getChName(channel.slot,channel.ch_id,channel.ch_name);
}

bool SY1527::getChName(HVChannels &channels)
{
    HVChannels::iterator it;
    for(it=channels.begin();it!=channels.end();it++){
        if(!getChName(*it))
            return false;
    }
    return true;
}

bool SY1527::setChParam(unsigned short slot, const char *param, unsigned short chnum, const unsigned short *chlist, void *parvalue)
{
    fStatus=CAENHV_SetChParam(fHandle,slot,param,chnum,chlist,parvalue);
    if(fStatus != CAENHV_OK){
        fErrorDesc=CAENHV_GetError(fHandle);
        return false;
    }
    else
        return true;
}

bool SY1527::getChParam(unsigned short slot, const char *param, unsigned short chnum, const unsigned short *chlist, void *parvallist)
{
    fStatus=CAENHV_GetChParam(fHandle,slot,param,chnum,chlist,parvallist);
    if(fStatus != CAENHV_OK){
        fErrorDesc=CAENHV_GetError(fHandle);
        return false;
    }
    else
        return true;
}

bool SY1527::TurnOn(unsigned short slot, unsigned short chnum, const unsigned short *chlist)
{
    unsigned long Pw=1;
    return setChParam(slot,"Pw",chnum,chlist,&Pw);
}

bool SY1527::TurnOff(unsigned short slot, unsigned short chnum, const unsigned short *chlist)
{
    unsigned long Pw=0;
    return setChParam(slot,"Pw",chnum,chlist,&Pw);
}
