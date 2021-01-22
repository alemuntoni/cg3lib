CONFIG += CG3_CORE CG3_DATA_STRUCTURES CG3_MESHES CG3_CGAL CG3_LIBIGL CG3_STATIC CG3_VIEWER

include(../../cg3.pri)

#use these on ubuntu 20.04, which has new cgal version
#DEFINES += CGAL_HEADER_ONLY
#CONFIG += c++14 

DEFINES += SOURCE_PATH=$$PWD

SOURCES += main.cpp
