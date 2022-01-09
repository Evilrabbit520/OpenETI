message(STATUS "ETIScr This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "ETIScr This is SOURCE dir " ${PROJECT_SOURCE_DIR})

add_subdirectory(EncryptionAlgorithm)
add_subdirectory(Times)

aux_source_directory(./EncryptionAlgorithm EA)
aux_source_directory(./Times TA)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_library(OpenETI SHARED ${EA} ${TA})
