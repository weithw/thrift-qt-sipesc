PROJECT(org.ssdut.plugin.helloworld)

CMAKE_MINIMUM_REQUIRED(VERSION 2.4.0)
IF(COMMAND CMAKE_POLICY)
    CMAKE_POLICY(SET CMP0003 NEW)
ENDIF(COMMAND CMAKE_POLICY)

FILE(TO_CMAKE_PATH $ENV{HOME} HOME_PATH)
SET(CMAKE_MODULE_PATH "${HOME_PATH}/.sipesc/share/cmake")

FIND_PACKAGE(Qt4 REQUIRED)
FIND_PACKAGE(MExtManagerCore REQUIRED)

SET(QT_DONT_USE_QTGUI 1)
INCLUDE(${QT_USE_FILE})
INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../plugin
    ${MEXTMGR_CORE_INCLUDE_DIRS}
)

SET(org_ssdut_plugin_helloworld_src_files    
    src/messageproviderimpl.cxx
    src/messagereceiverimpl.cxx
    src/org.ssdut.plugin.helloworld.cxx
)

SET(org_ssdut_plugin_helloworld_hdr_files
    inc/org.ssdut.plugin.helloworld.h
)

SET(org_ssdut_plugin_helloworld_qui_files
)

MEXTMGR_WRAP_UI(
    org_ssdut_plugin_helloworld_uis_files
    ${org_ssdut_plugin_helloworld_qui_files}
)
MEXTMGR_WRAP_XML(
    org_ssdut_plugin_helloworld_xml_files
    org.ssdut.plugin.helloworld.sipplugin
)
MEXTMGR_ADD_RESOURCES(
    org_ssdut_plugin_helloworld_qrc_files
    qrc/org.ssdut.plugin.helloworld.qrc
)
MEXTMGR_GEN_PLUGINHEADER(
    org_ssdut_plugin_helloworld_phd_files
    org.ssdut.plugin.helloworld.sipplugin
    ${CMAKE_CURRENT_BINARY_DIR}/plugin
)
MEXTMGR_GEN_PLUGINFEATURE(
    org_ssdut_plugin_helloworld_pfm_files
    org.ssdut.plugin.helloworld.sipplugin
)
MEXTMGR_ADD_TRANSLATION(
    org_ssdut_plugin_helloworld_qms_files
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    qrc/org.ssdut.plugin.helloworld_zh_CN.ts
    ${org_ssdut_plugin_helloworld_src_files}
    ${org_ssdut_plugin_helloworld_xml_files}
    ${org_ssdut_plugin_helloworld_qui_files}
)

ADD_LIBRARY(
    org.ssdut.plugin.helloworld_1.0.0 SHARED
    ${org_ssdut_plugin_helloworld_src_files}
    ${org_ssdut_plugin_helloworld_xml_files}
    ${org_ssdut_plugin_helloworld_qms_files}
    ${org_ssdut_plugin_helloworld_phd_files}
    ${org_ssdut_plugin_helloworld_pfm_files}
    ${org_ssdut_plugin_helloworld_xml_files}
    ${org_ssdut_plugin_helloworld_qrc_files}
    ${org_ssdut_plugin_helloworld_hdr_files}
    ${org_ssdut_plugin_helloworld_uis_files}
)
SET_TARGET_PROPERTIES(
    org.ssdut.plugin.helloworld_1.0.0 PROPERTIES
    POSTFIX "" PREFIX "" SUFFIX ".sep" AUTOMOC "1"
)
IF(WIN32)
    SET_TARGET_PROPERTIES(
        org.ssdut.plugin.helloworld_1.0.0
        PROPERTIES LINK_FLAGS "-mthreads"
        COMPILE_FLAGS "-frtti -fexceptions -mthreads"
    )
ENDIF(WIN32)
TARGET_LINK_LIBRARIES(
    org.ssdut.plugin.helloworld_1.0.0
    ${QT_LIBRARIES}
    ${MEXTMGR_CORE_LIBRARIES}
)

### Install
INSTALL(
    TARGETS org.ssdut.plugin.helloworld_1.0.0
    RUNTIME DESTINATION lib/plugins/${CMAKE_BUILD_TYPE}
    LIBRARY DESTINATION lib/plugins/${CMAKE_BUILD_TYPE}
    ARCHIVE DESTINATION lib/plugins/${CMAKE_BUILD_TYPE}
)
MESSAGE(STATUS "NOW path CMAKE_CURRENT_BINARY_DIR:${CMAKE_CURRENT_BINARY_DIR}")
MESSAGE(STATUS "NOW path CMAKE_CURRENT_BINARY_DIR:${CMAKE_CURRENT_SOURCE_DIR}")
INSTALL(
    DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/plugin
    DESTINATION include
    FILES_MATCHING PATTERN "org.ssdut.plugin.helloworld.feature.*.h"
)
INSTALL(
    DIRECTORY qrc/
    DESTINATION share/translations/zh_CN
    FILES_MATCHING PATTERN "*_zh_CN.qm"
    PATTERN ".svn" EXCLUDE
)
INSTALL(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/org.ssdut.plugin.helloworld.features
    DESTINATION share/features
)
