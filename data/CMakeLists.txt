add_library(showbyte showbyte.c)
target_include_directories(showbyte PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_library(islittleendian SHARED isLittleEndian.c)
target_include_directories(islittleendian PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(mergeLastByte MergeLastByte.c)

add_executable(replaceByte ReplaceByte.c)
target_link_libraries(replaceByte PRIVATE showbyte islittleendian)

add_executable(homework homework.c)
target_link_libraries(homework PRIVATE showbyte islittleendian)
