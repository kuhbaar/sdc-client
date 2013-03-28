cmake_minimum_required(VERSION 2.6) 
project (sdc_client)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

#begin snippet
#next lines are for creating .h & .cpp files out of .ice Files
set(out_dir "${CMAKE_CURRENT_BINARY_DIR}")
set(out_file "${out_dir}/SecureDistributedChat.cpp")

add_custom_command(OUTPUT
"${out_file}"
COMMAND "${ZeroCIce_slice2cpp_BIN}"
  --add-header=cstddef
  -I /usr/share/Ice/slice/
  -I /usr/share/Ice-3.4.1/slice/
  -I /usr/share/slice/
  --stream
  --output-dir "${out_dir}"
  "${CMAKE_CURRENT_SOURCE_DIR}/SecureDistributedChat.ice"
)

set( EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR} )
#end snippet

add_executable(sdc_client sdc_client.cpp ${out_file} Chat.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${ZeroCIce_INCLUDE_DIR})
find_package(ZeroCIce REQUIRED)
find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})


target_link_libraries(sdc_client ${QT_QTDECLARATIVE_LIBRARY})
target_link_libraries(sdc_client ${QT_LIBRARIES})
target_link_libraries(sdc_client boost_program_options)
target_link_libraries(sdc_client ${ZeroCIceCore_LIBRARY})
target_link_libraries(sdc_client ${ZeroCIceUtil_LIBRARY})
target_link_libraries(sdc_client ${ZeroCIceSSL_LIBRARY})