if( CF_BUILD_CF_TOOL OR CF_BUILD_CF_LIB )
	find_package( Poco REQUIRED Foundation XML JSON Util )
	if( Poco_FOUND )
		include_directories( ${Poco_INCLUDE_DIRS} )
	else()
		message( FATAL_ERROR "-- ${CMAKE_PROJECT_NAME} -- No Poco C++ Libraries found!" )
	endif()

	include_directories( ${CMAKE_SOURCE_DIR}/include )

	add_subdirectory( cfetchlib )
endif()

if( CF_BUILD_CF_TOOL )
	add_subdirectory( cfetch )
endif()
