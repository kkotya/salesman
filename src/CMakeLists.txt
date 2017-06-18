set( SALESMAN_SOURCE salesman.cpp )
add_library( SALESMAN_LIB SHARED ${SALESMAN_SOURCE} )

add_subdirectory(command_line_app)
add_subdirectory(performance)