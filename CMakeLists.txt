CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
PROJECT (hap_scene_osg)


FIND_PACKAGE(OpenSceneGraph REQUIRED)

IF(NOT OPENSCENEGRAPH_FOUND)
    MESSAGE(FATAL_ERROR "Open Scene Graph could not be found")
ENDIF(NOT OPENSCENEGRAPH_FOUND)

INCLUDE_DIRECTORIES(${OPENSCENEGRAPH_INCLUDE_DIRS})
LINK_DIRECTORIES(${OPENSCENEGRAPH_LIBRARY_DIRS})


FILE(GLOB SCENE_OSG_SOURCES src/*.cxx)
ADD_LIBRARY(hap_scene_osg SHARED ${SCENE_OSG_SOURCES})

TARGET_LINK_LIBRARIES(hap_scene_osg ${OPENSCENEGRAPH_LIBRARIES})
