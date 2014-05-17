#include "VISASystemManager.h"
#include "VISAInstrument.h"
#include <iostream>

using namespace std;
int main(int argc,char* argv[])
{

    VISAInstrument instr("Serial_Test","ASRL3::INSTR");
    if(instr.Status() && VISASystemManager::GetInstance()->Status()){
        cout<< "Success" <<endl;
    }
    else{
        cout << "Fail" << endl;
    }

    //std::cout << "Hello World" <<std::endl;
    return 0;
}
