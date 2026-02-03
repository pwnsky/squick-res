set(ProjectName "sqkctl")

include_directories(
	minizip
	tinyxml2
	zlib)

set(SolutionDir ${PROJECT_SOURCE_DIR}/../../..)
set(CMAKE_CXX_STANDARD 17)

include_directories(
	${SolutionDir}
	${SolutionDir}/src/
	${SolutionDir}/third_party/
	${SolutionDir}/third_party/build/include
	${SolutionDir}/third_party/zlib
	)

file(GLOB sqkctl_cc *.cc)
file(GLOB sqkctl_h *.h)


file(GLOB sqkctl_excel_minizip_c ${SolutionDir}/third_party/minizip/ioapi.c ${SolutionDir}/third_party/minizip/ioapi_mem.c ${SolutionDir}/third_party/minizip/unzip.c)
file(GLOB sqkctl_excel_minizip_h ${SolutionDir}/third_party/minizip/*.h)
source_group("minizip" FILES ${sqkctl_excel_minizip_c})
source_group("minizip" FILES ${sqkctl_excel_minizip_h})


file(GLOB sqkctl_excel_zlib_c ${SolutionDir}/third_party/zlib/*.c)
file(GLOB sqkctl_excel_zlib_h ${SolutionDir}/third_party/zlib/*.h)
source_group("zlib" FILES ${sqkctl_excel_zlib_c})
source_group("zlib" FILES ${sqkctl_excel_zlib_h})


file(GLOB sqkctl_third_party_common_hpp ${SolutionDir}/third_party/common/*.hpp)
source_group("common" FILES ${sqkctl_third_party_common_hpp})

file(GLOB sqkctl_excel_cc ./excel/*.cc)
file(GLOB sqkctl_excel_h ./excel/*.h)
source_group("excel" FILES ${sqkctl_excel_cc})
source_group("excel" FILES ${sqkctl_excel_h})

add_executable(${ProjectName}
	${sqkctl_cc}
	${sqkctl_h}

	${sqkctl_excel_cc}
	${sqkctl_excel_h}
	${sqkctl_excel_minizip_c} 
	${sqkctl_excel_minizip_h}
	${sqkctl_excel_zlib_c} 
	${sqkctl_excel_zlib_h}
	
	${sqkctl_third_party_common_hpp}
	)


# 工程输出
macro(SquickOut proName outFolder outPath outName)
set_target_properties( ${proName} PROPERTIES OUTPUT_NAME ${outName} )
set_target_properties( ${proName} PROPERTIES PREFIX "")
set_target_properties( ${proName} PROPERTIES 
	FOLDER ${outFolder}
	RUNTIME_OUTPUT_DIRECTORY ${outPath}
	RUNTIME_OUTPUT_DIRECTORY ${outPath}
	ARCHIVE_OUTPUT_DIRECTORY ${outPath}
	ARCHIVE_OUTPUT_DIRECTORY ${outPath}
	LIBRARY_OUTPUT_DIRECTORY ${outPath}
	LIBRARY_OUTPUT_DIRECTORY ${outPath}
	RUNTIME_OUTPUT_DIRECTORY_DEBUG ${outPath}
	RUNTIME_OUTPUT_DIRECTORY_RELEASE ${outPath}
	ARCHIVE_OUTPUT_DIRECTORY_DEBUG  ${outPath}
	ARCHIVE_OUTPUT_DIRECTORY_RELEASE  ${outPath}
	LIBRARY_OUTPUT_DIRECTORY_DEBUG ${outPath}
	LIBRARY_OUTPUT_DIRECTORY_RELEASE ${outPath}
)
endmacro(SquickOut)

if (UNIX)
	SET ( CMAKE_CXX_FLAGS "-g" )
else()
	set_property ( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${ProjectName} )
	set_target_properties(${ProjectName} PROPERTIES
		VS_DEBUGGER_COMMAND_ARGUMENTS "./Xlsx ./XlsxGen"
		VS_DEBUGGER_WORKING_DIRECTORY "${SolutionDir}/res"
	)
endif()

SquickOut(${ProjectName} ${ProjectName} ${SolutionDir}/res/Tools ${ProjectName})
add_definitions(
	-D_CRT_SECURE_NO_WARNINGS
	-D_CRT_NONSTDC_NO_DEPRECATE
)
