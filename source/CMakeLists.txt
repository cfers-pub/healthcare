#
#   Copyright 2021 ChenFei
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#

#闄愬畾鍙敮鎸乄indows绯荤粺
IF (NOT(${CMAKE_SYSTEM_NAME} MATCHES "Windows"))
    message(FATAL_ERROR "${root_dir_name_}: only support windows system !")
ENDIF()

#娣诲姞瀹忓畾涔?
add_definitions(-D_CRT_SECURE_NO_WARNINGS -DPB_FIELD_16BIT)

#鑾峰彇鎵€鏈夋簮鏂囦欢
file(GLOB_RECURSE cpp_files_ *.c *.cxx *.cpp)
FOREACH(file ${cpp_files_}) 
  #message(STATUS add: ${file})
ENDFOREACH(file)

#鑾峰彇鎵€鏈夊ご鏂囦欢
file(GLOB_RECURSE header_files_ *.h *.hxx *.hpp)
FOREACH(file ${header_files_}) 
  #message(STATUS add: ${file})
ENDFOREACH(file)

#鑾峰彇qt鐨剈i鏂囦欢
file(GLOB_RECURSE ui_files_ *.ui)
FOREACH(file ${ui_files_}) 
  #message(STATUS add: ${file})
ENDFOREACH(file)

#鑾峰彇qt鐨剄rc鏂囦欢
file(GLOB_RECURSE qrc_files_ *.qrc)
FOREACH(file ${qrc_files_}) 
  #message(STATUS add: ${file})
ENDFOREACH(file)

#鑾峰彇鍏朵粬鏂囦欢
file(GLOB_RECURSE other_files_ *.qss)
FOREACH(file ${other_files_}) 
  #message(STATUS add: ${file})
ENDFOREACH(file)

#浠ョ洰褰曠殑鏂瑰紡缁勭粐vc宸ョ▼缁撴瀯
source_group(TREE ${CMAKE_SOURCE_DIR} FILES 
  ${header_files_} 
  ${cpp_files_} 
  ${resource_files_}
  ${ui_files_}
  ${qrc_files_}
  ${other_files_}
 ) 

#娣诲姞涓婚」鐩?
add_executable(${root_dir_name_} WIN32   
  ${header_files_} 
  ${cpp_files_} 
#  ${protobuf_files_}  
#  ${protobuf_option_files_}
  ${resource_files_}
  ${ui_files_}
  ${qrc_files_}
  ${other_files_}
  ${protobuf_out_files_}
)

#鍚敤qt鐨刴oc uic rcc鍔熻兘
#set_property(GLOBAL PROPERTY AUTOGEN_SOURCE_GROUP "auto-gen/qt")
set_property(TARGET ${root_dir_name_} PROPERTY AUTOMOC ON)
set_property(TARGET ${root_dir_name_} PROPERTY AUTOUIC ON)
set_property(TARGET ${root_dir_name_} PROPERTY AUTORCC ON)

#娣诲姞椤圭洰渚濊禆
   #鏌ユ壘qt5
  find_package(Qt5 5.9.7 COMPONENTS Core Gui Charts REQUIRED)
  #qt5_wrap_ui(ui_FILES ${ui_files_})
  #qt5_add_resources(qrc_FILES ${qrc_files_})

    #娣诲姞澶存枃浠惰矾寰?
  target_include_directories(${root_dir_name_} 
    PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}
      #${CMAKE_CURRENT_BINARY_DIR}
      ${CMAKE_SOURCE_DIR}/../3rd_party
      ${autogen_out_dir}
  )
    #娣诲姞渚濊禆搴撹矾寰?
    target_link_directories(${root_dir_name_} 
    PUBLIC
      ${CMAKE_SOURCE_DIR}/../3rd_party
  )
    #娣诲姞渚濊禆搴?
  target_link_libraries(${root_dir_name_} 
  PUBLIC 
    Qt5::Core Qt5::Gui Qt5::Charts
)

#璁剧疆杩愯鏃朵緷璧栧簱璺緞
set(3rd_party_binary_prefix_ "${CMAKE_SOURCE_DIR}/../3rd_party/")
set(runtime_depends_path_ "PATH=%PATH%;${Qt5_ROOT}/bin;")
set_property(TARGET ${root_dir_name_} PROPERTY VS_DEBUGGER_ENVIRONMENT "${runtime_depends_path_}")

#鍒跺畾瀹夎鑴氭湰
install(TARGETS ${root_dir_name_}
        CONFIGURATIONS Release
        RUNTIME DESTINATION bin)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/log.cfg
              ${CMAKE_CURRENT_SOURCE_DIR}/wave_name_mapping.ini
        DESTINATION ${CMAKE_INSTALL_BINDIR}/
)