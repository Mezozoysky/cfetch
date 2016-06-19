# LIB

#
# Build cfetch lib
#
set( CF_LIB_HEADERS "" )
set( CF_LIB_SOURCES "" )

# =========================
# ==== cfetchlib group ====
# =========================
set(GROUP_HEADERS
	${CMAKE_SOURCE_DIR}/include/cfetchlib/Config.hpp
	${CMAKE_SOURCE_DIR}/include/cfetchlib/Fetch.hpp
)
set(GROUP_SOURCES
	${CMAKE_SOURCE_DIR}/src/cfetchlib/Fetch.cpp
)
source_group( "cfetchlib" FILES ${GROUP_HEADERS} ${GROUP_SOURCES} )
set( CF_LIB_HEADERS ${CF_LIB_HEADERS} ${GROUP_HEADERS} )
set( CF_LIB_SOURCES ${CF_LIB_SOURCES} ${GROUP_SOURCES} )

add_library( cfetchlib STATIC
	${CF_LIB_HEADERS}
	${CF_LIB_SOURCES}
)
set_target_properties( cfetchlib PROPERTIES LINKER_LANGUAGE CXX )

if( CF_BUILD_CF_LIB )
	install(
		TARGETS cfetchlib
		ARCHIVE DESTINATION lib
	)
	install(
		FILES ${CF_LIB_HEADERS}
		DESTINATION include/cfetchlib
	)
endif()
