PROJECT(p0010196)

SET( p0010196_HDRS
)

SET( p0010196_SRCS
	main_p0010196.cpp
	main_p0010196_v2.cpp
	main_p0010196_v3.cpp
)

ADD_LIBRARY( p0010196 main_p0010196 ) #By default will add lib
ADD_EXECUTABLE( p0010196exe main_p0010196 )

ADD_LIBRARY( p0010196_v2 main_p0010196_v2 ) #By default will add lib
ADD_EXECUTABLE( p0010196_v2exe main_p0010196_v2 )

ADD_LIBRARY( p0010196_v3 main_p0010196_v3 ) #By default will add lib
ADD_EXECUTABLE( p0010196_v3exe main_p0010196_v3 )

# TARGET_LINK_LIBRARIES( )
