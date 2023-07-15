aux_source_directory(../ SRC_LIST1)
aux_source_directory(. SRC_LIST2)

include_directories(../../include)
include_directories(../../include/model)

add_executable(server_main ${SRC_LIST1} ${SRC_LIST2})

SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)