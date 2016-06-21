# TOOL

#
# OS-specific libs
#
set( CF_TOOL_OS_SPECIFIC_LIBS "" )

if( CF_OS_LINUX )
    find_library( PTHREAD_LIBRARY NAMES pthread )
    set( CF_TOOL_OS_SPECIFIC_LIBS ${CF_TOOL_OS_SPECIFIC_LIBS}
        ${PTHREAD_LIBRARY}
    )
endif()

if( CF_OS_OSX )
    set( CF_TOOL_OS_SPECIFIC_LIBS ${CF_TOOL_OS_SPECIFIC_LIBS}
    )
endif()

if( CF_OS_WINDOWS )
    set( CF_TOOL_OS_SPECIFIC_LIBS ${CF_TOOL_OS_SPECIFIC_LIBS}
    )
endif()

#
# Build cfetch tool
#
set( CF_TOOL_HEADERS "" )
set( CF_TOOL_SOURCES "" )

# ======================
# ==== cfetch group ====
# ======================
set(GROUP_HEADERS
	${CMAKE_SOURCE_DIR}/src/cfetch/Application.hpp
)
set(GROUP_SOURCES
	${CMAKE_SOURCE_DIR}/src/cfetch/main.cpp
	${CMAKE_SOURCE_DIR}/src/cfetch/Application.cpp
)
source_group( "cfetch" FILES ${GROUP_HEADERS} ${GROUP_SOURCES} )
set( CF_TOOL_HEADERS ${CF_TOOL_HEADERS} ${GROUP_HEADERS} )
set( CF_TOOL_SOURCES ${CF_TOOL_SOURCES} ${GROUP_SOURCES} )

add_executable( cfetch WIN32 MACOSX_BUNDLE
    ${CF_TOOL_HEADERS}
    ${CF_TOOL_SOURCES}
)
# set_target_properties( cfetch PROPERTIES LINKER_LANGUAGE CXX )

target_link_libraries( cfetch cfetchlib )
target_link_libraries( cfetch
	${Poco_Util_LIBRARY}
	${Poco_XML_LIBRARY}
	${Poco_JSON_LIBRARY}  
	${Poco_Foundation_LIBRARY}
)
target_link_libraries( cfetch ${CF_TOOL_OS_SPECIFIC_LIBS} )

# add_custom_command(
#     TARGET cfetch POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_directory
#     ${CMAKE_SOURCE_DIR}/assets/app $<TARGET_FILE_DIR:cfetch>
# )

install(
    TARGETS cfetch
    BUNDLE DESTINATION bin
    RUNTIME DESTINATION bin
)
