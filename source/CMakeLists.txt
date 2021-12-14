#限定只支持Windows系统
IF (NOT(${CMAKE_SYSTEM_NAME} MATCHES "Windows"))
    message(FATAL_ERROR "${root_dir_name_}: only support windows system !")
ENDIF()

#添加宏定义
add_definitions(-D_CRT_SECURE_NO_WARNINGS -DPB_FIELD_16BIT)

#获取所有源文件
file(GLOB_RECURSE cpp_files_ *.c *.cxx *.cpp)
FOREACH(file ${cpp_files_}) 
  #message(STATUS add: ${file})
ENDFOREACH(file)

#获取所有头文件
file(GLOB_RECURSE header_files_ *.h *.hxx *.hpp)
FOREACH(file ${header_files_}) 
  #message(STATUS add: ${file})
ENDFOREACH(file)

#获取qt的ui文件
file(GLOB_RECURSE ui_files_ *.ui)
FOREACH(file ${ui_files_}) 
  #message(STATUS add: ${file})
ENDFOREACH(file)

#获取qt的qrc文件
file(GLOB_RECURSE qrc_files_ *.qrc)
FOREACH(file ${qrc_files_}) 
  #message(STATUS add: ${file})
ENDFOREACH(file)

#获取其他文件
file(GLOB_RECURSE other_files_ *.qss)
FOREACH(file ${other_files_}) 
  #message(STATUS add: ${file})
ENDFOREACH(file)

#以目录的方式组织vc工程结构
source_group(TREE ${CMAKE_SOURCE_DIR} FILES 
  ${header_files_} 
  ${cpp_files_} 
  ${resource_files_}
  ${ui_files_}
  ${qrc_files_}
  ${other_files_}
 ) 

#添加主项目
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

#启用qt的moc uic rcc功能
#set_property(GLOBAL PROPERTY AUTOGEN_SOURCE_GROUP "auto-gen/qt")
set_property(TARGET ${root_dir_name_} PROPERTY AUTOMOC ON)
set_property(TARGET ${root_dir_name_} PROPERTY AUTOUIC ON)
set_property(TARGET ${root_dir_name_} PROPERTY AUTORCC ON)

#添加项目依赖
   #查找qt5
  find_package(Qt5 5.9.7 COMPONENTS Core Gui Charts REQUIRED)
  #qt5_wrap_ui(ui_FILES ${ui_files_})
  #qt5_add_resources(qrc_FILES ${qrc_files_})

    #添加头文件路径
  target_include_directories(${root_dir_name_} 
    PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}
      #${CMAKE_CURRENT_BINARY_DIR}
      ${CMAKE_SOURCE_DIR}/../3rd_party
      ${autogen_out_dir}
  )
    #添加依赖库路径
    target_link_directories(${root_dir_name_} 
    PUBLIC
      ${CMAKE_SOURCE_DIR}/../3rd_party
  )
    #添加依赖库
  target_link_libraries(${root_dir_name_} 
  PUBLIC 
    Qt5::Core Qt5::Gui Qt5::Charts
)

#设置运行时依赖库路径
set(3rd_party_binary_prefix_ "${CMAKE_SOURCE_DIR}/../3rd_party/")
set(runtime_depends_path_ "PATH=%PATH%;${Qt5_ROOT}/bin;")
set_property(TARGET ${root_dir_name_} PROPERTY VS_DEBUGGER_ENVIRONMENT "${runtime_depends_path_}")

#制定安装脚本
install(TARGETS ${root_dir_name_}
        CONFIGURATIONS Release
        RUNTIME DESTINATION bin)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/log.cfg
              ${CMAKE_CURRENT_SOURCE_DIR}/wave_name_mapping.ini
        DESTINATION ${CMAKE_INSTALL_BINDIR}/
)