cmake_minimum_required(VERSION 2.8)

project(libPMT CXX)

set(VISA_INCLUDE_DIR "C:/Program Files (x86)/IVI Foundation/VISA/WinNT/include")
include_directories(${VISA_INCLUDE_DIR})
set(VISA_LIBRARIES "C:/Program Files (x86)/IVI Foundation/VISA/WinNT/lib/msc/visa32.lib")

set(SRC VISASystemManager.cpp VISAInstrument.cpp PMTVDaqManager.cpp)
add_library(libPMT ${SRC})
target_link_libraries(libPMT ${VISA_LIBRARIES})

