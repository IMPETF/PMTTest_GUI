cmake_minimum_required(VERSION 2.8)

project(libPMT CXX)

#set(VISA_DIR "D:/Program Files" CACHE PATH "choose the NI-VISA install directory")
set(VISA_INCLUDE_DIR "C:/Program Files/IVI Foundation/VISA/WinNT/include" CACHE PATH "choose the dir where visa.h is included")
include_directories(${VISA_INCLUDE_DIR})
set(VISA_LIBRARIES "C:/Program Files/IVI Foundation/VISA/WinNT/lib/msc/visa32.lib" CACHE FILEPATH
"choose the file visa32.lib")

set(SRC VISASystemManager.cpp VISAInstrument.cpp PMTVDaqManager.cpp)
add_library(libPMT ${SRC})
target_link_libraries(libPMT ${VISA_LIBRARIES})

add_executable(testdemo main.cpp)
#set_target_properties(testdemo PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(testdemo libPMT)

