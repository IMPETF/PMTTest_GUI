#include <string.h>
#include "SY1527.h"

using namespace std;
/////////SYX527_Module/////////////////////////////
SYX527_Module::SYX527_Module(SY1527 *controller, int slot_num, HVChannels &channels):
    fCrate(controller),fSlot(slot_num),fChNum(channels.size()),
    fVSet(0),fISet(25.0),fRUp(30.0),fRDWn(30.0)
{
    //
    fChList.resize(fChNum);
    fPChList=&fChList[0];

    fChSetName.resize(fChNum);

    for(int i=0;i<fChNum;i++){
        fChList[i]=channels[i].ch_id;
        fChSetName[i]=channels[i].ch_name;
    }
    //
    fState.resize(fChNum);
    fPState=&fState[0];

    fV0Set.resize(fChNum);
    fPV0Set=&fV0Set[0];

    fI0Set.resize(fChNum);
    fPI0Set=&fI0Set[0];

    fVMon.resize(fChNum);
    fPVMon=&fVMon[0];

    fIMon.resize(fChNum);
    fPIMon=&fIMon[0];

    fPChName=new char[fChNum][MAX_CH_NAME];
}

SYX527_Module::~SYX527_Module()
{
    delete fPChName;
}

bool SYX527_Module::updateChName()
{
    //update
    if(!fCrate->connect())
        return false;
    else{
        for(int i=0;i<fChNum;i++){
            if(!fCrate->setChName(fSlot,fChList[i],fChSetName[i].c_str()))
                return false;
        }
    }
    //confirm
    if(!fCrate->getChName(fSlot,fChNum,fPChList,fPChName))
        return false;
    else{
        string tempstr;
        for(int i=0;i<fChNum;i++){
            tempstr=fPChName[i];
            if(tempstr != fChSetName[i])
                return false;
        }
    }
    return fCrate->disConnect();
}

bool SYX527_Module::updateVSet()
{
    //update
    if(!fCrate->connect())
        return false;
    else{
        if(!fCrate->SetV0(fSlot,fChNum,fPChList,fVSet))
            return false;
    }
    //confirm
    if(!fCrate->GetV0(fSlot,fChNum,fPChList,fPV0Set))
        return false;
    else{
        for(int i=0;i<fChNum;i++){
            if(fV0Set[i] != fVSet)
                return false;
        }
    }
    return fCrate->disConnect();
}

bool SYX527_Module::updateISet()
{
    //update
    if(!fCrate->connect())
        return false;
    else{
        if(!fCrate->SetI0(fSlot,fChNum,fPChList,fISet))
            return false;
    }
    //confirm
    if(!fCrate->GetI0(fSlot,fChNum,fPChList,fPI0Set))
        return false;
    else{
        for(int i=0;i<fChNum;i++){
            if(fI0Set[i] != fISet)
                return false;
        }
    }
    return fCrate->disConnect();
}


bool SYX527_Module::updateRampUp()
{
    //update
    if(!fCrate->connect())
        return false;
    else{
        if(!fCrate->SetRampUp(fSlot,fChNum,fPChList,fRUp))
            return false;
    }

    return fCrate->disConnect();
}

bool SYX527_Module::updateRampDown()
{
    if(!fCrate->connect())
        return false;
    else{
        if(!fCrate->SetRampDown(fSlot,fChNum,fPChList,fRDWn))
            return false;
    }

    return fCrate->disConnect();
}

bool SYX527_Module::getState()
{
    if(!fCrate->connect())
        return false;
    else{
        if(!fCrate->GetState(fSlot,fChNum,fPChList,fPState))
            return false;
    }
    return fCrate->disConnect();
}

bool SYX527_Module::getV0Set()
{
    if(!fCrate->connect())
        return false;
    else{
        if(!fCrate->GetV0(fSlot,fChNum,fPChList,fPV0Set))
            return false;
    }
    return fCrate->disConnect();
}

bool SYX527_Module::getI0Set()
{
    if(!fCrate->connect())
        return false;
    else{
        if(!fCrate->GetI0(fSlot,fChNum,fPChList,fPI0Set))
            return false;
    }
    return fCrate->disConnect();
}

bool SYX527_Module::getVMon()
{
    if(!fCrate->connect())
        return false;
    else{
        if(!fCrate->GetVMon(fSlot,fChNum,fPChList,fPVMon))
            return false;
    }
    return fCrate->disConnect();
}

bool SYX527_Module::getIMon()
{
    if(!fCrate->connect())
        return false;
    else{
        if(!fCrate->GetIMon(fSlot,fChNum,fPChList,fPIMon))
            return false;
    }
    return fCrate->disConnect();
}

bool SYX527_Module::getChName()
{
    if(!fCrate->connect())
        return false;
    else{
        if(!fCrate->getChName(fSlot,fChNum,fPChList,fPChName))
            return false;
    }
    return fCrate->disConnect();
}

bool SYX527_Module::PowerOn()
{
    if(!fCrate->connect())
        return false;
    else{
        if(!fCrate->TurnOn(fSlot,fChNum,fPChList))
            return false;
    }
    return fCrate->disConnect();
}

bool SYX527_Module::PowerOff()
{
    if(!fCrate->connect())
        return false;
    else{
        if(!fCrate->TurnOff(fSlot,fChNum,fPChList))
            return false;
    }
    return fCrate->disConnect();
}

bool SYX527_Module::update(HVChannels &channels)
{
    if(!fCrate->connect())
        return false;
    else{
        if(!fCrate->GetState(fSlot,fChNum,fPChList,fPState))
            return false;
        if(!fCrate->GetV0(fSlot,fChNum,fPChList,fPV0Set))
            return false;
        if(!fCrate->GetI0(fSlot,fChNum,fPChList,fPI0Set))
            return false;
        if(!fCrate->GetVMon(fSlot,fChNum,fPChList,fPVMon))
            return false;
        if(!fCrate->GetIMon(fSlot,fChNum,fPChList,fPIMon))
            return false;
        if(!fCrate->getChName(fSlot,fChNum,fPChList,fPChName))
            return false;

        if(channels.size() != fChNum){
            channels.resize(fChNum);
        }
        for(int i=0;i<fChNum;i++){
            channels[i].slot=fSlot;
            channels[i].ch_id=fChList[i];
            strncpy(channels[i].ch_name,fPChName+i,MAX_CH_NAME);
            channels[i].V0Set=fV0Set[i];
            channels[i].I0Set=fI0Set[i];
            channels[i].VMon=fVMon[i];
            channels[i].IMon=fIMon[i];
            channles[i].state=fState[i];
        }

    }

    return fCrate->disConnect();
}

//////////SY1527///////////////////////////////////
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

bool SY1527::SetRampUp(unsigned short slot, unsigned short chnum, const unsigned short *chlist, float RUp)
{
    return setChParam(slot,"RUp",chnum,chlist,&RUp);
}

bool SY1527::SetRampDown(unsigned short slot, unsigned short chnum, const unsigned short *chlist, float RDwn)
{
    return setChParam(slot,"RDWn",chnum,chlist,&RDwn);
}

bool SY1527::SetV0(unsigned short slot, unsigned short chnum, const unsigned short *chlist, float V)
{
    return setChParam(slot,"V0Set",chnum,chlist,&V);
}

bool SY1527::SetI0(unsigned short slot, unsigned short chnum, const unsigned short *chlist, float I)
{
    return setChParam(slot,"I0Set",chnum,chlist,&I);
}

bool SY1527::GetState(unsigned short slot, unsigned short chnum, const unsigned short *chlist, float *parvallist)
{
    return getChParam(slot,"Pw",chnum,chlist,parvallist);
}

bool SY1527::GetV0(unsigned short slot, unsigned short chnum, const unsigned short *chlist, float *parvallist)
{
    return getChParam(slot,"V0Set",chnum,chlist,parvallist);
}

bool SY1527::GetI0(unsigned short slot, unsigned short chnum, const unsigned short *chlist, float *parvallist)
{
    return getChParam(slot,"I0Set",chnum,chlist,parvallist);
}

bool SY1527::GetVMon(unsigned short slot, unsigned short chnum, const unsigned short *chlist, float *parvallist)
{
    return getChParam(slot,"VMon",chnum,chlist,parvallist);
}

bool SY1527::GetIMon(unsigned short slot, unsigned short chnum, const unsigned short *chlist, float *parvallist)
{
    return getChParam(slot,"IMon",chnum,chlist,parvallist);
}

bool SY1527::GetRampUp(unsigned short slot, unsigned short chnum, const unsigned short *chlist, float *parvallist)
{
    return getChParam(slot,"RUp",chnum,chlist,parvallist);
}

bool SY1527::GetRampDown(unsigned short slot, unsigned short chnum, const unsigned short *chlist, float *parvallist)
{
    return getChParam(slot,"RDWn",chnum,chlist,parvallist);
}
