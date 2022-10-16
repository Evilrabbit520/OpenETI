include_directories(.)
add_compile_options(-std=c++11)

aux_source_directory(. INCROOT)
aux_source_directory(../ MAIN)
#aux_source_directory(ETISrc/Times SRCDIR)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

add_executable(server ${INCROOT} ${MAIN} ${JSONMAIN})

