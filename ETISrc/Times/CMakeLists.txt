message(STATUS "Times This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "Times This is SOURCE dir " ${PROJECT_SOURCE_DIR})

include_directories(../../include)

aux_source_directory(. ROOT)
#aux_source_directory(ETISrc/Times SRCDIR)
