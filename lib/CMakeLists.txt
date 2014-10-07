cmake_minimum_required(VERSION 2.8)

project(libPMT CXX)

#set(VISA_DIR "D:/Program Files" CACHE PATH "choose the NI-VISA install directory")
set(VISA_INCLUDE_DIR "C:/Program Files/IVI Foundation/VISA/WinNT/include" CACHE PATH "choose the dir where visa.h is included")
set(VISA_LIBRARIES "C:/Program Files/IVI Foundation/VISA/WinNT/lib/msc/visa32.lib" CACHE FILEPATH
"choose the file visa32.lib")
include_directories(${VISA_INCLUDE_DIR})

set(CAENHV_DIR ${PROJECT_SOURCE_DIR}/caenhvwrapper)
set(CAENHV_INCLUDE_DIR ${CAENHV_DIR}/include)
set(CAENHV_LIBRARIES ${CAENHV_DIR}/lib/CAENHVWrapper.lib)
include_directories(${CAENHV_INCLUDE_DIR})

set(PTHREAD_DIR ${PROJECT_SOURCE_DIR}/pthread_win32)
set(PTHREAD_INCLUDE_DIR ${PTHREAD_DIR}/include)
set(PTHREAD_LIBRARIES ${PTHREAD_DIR}/lib/pthreadVC2.lib)
set(PTHREAD_DLLS ${PTHREAD_DIR}/dll/pthreadVC2.dll)
include_directories(${PTHREAD_INCLUDE_DIR})

set(SRC VISASystemManager.cpp VISAInstrument.cpp PMTVDaqManager.cpp AFG3252.cpp SYX527.cpp)
add_library(libPMT ${SRC})
target_link_libraries(libPMT ${VISA_LIBRARIES} ${CAENHV_LIBRARIES} ${PTHREAD_LIBRARIES})

add_executable(testdemo main.cpp)
#set_target_properties(testdemo PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(testdemo libPMT)
file(COPY ${PTHREAD_DLLS} DESTINATION ${PROJECT_BINARY_DIR})

