PROJECT(p0010137)

SET( p0010137_HDRS
)

SET( p0010137_SRCS
	main_p0010137.cpp
	main_p0010137_v2.cpp
# 	main_p0010137_v3.cpp
)

ADD_LIBRARY( p0010137 main_p0010137 ) #By default will add lib
ADD_EXECUTABLE( p0010137exe main_p0010137 )

ADD_LIBRARY( p0010137_v2 main_p0010137_v2 ) #By default will add lib
ADD_EXECUTABLE( p0010137_v2exe main_p0010137_v2 )

# ADD_LIBRARY( p0010137_v3 main_p0010137_v3 ) #By default will add lib
# ADD_EXECUTABLE( p0010137_v3exe main_p0010137_v3 )

# TARGET_LINK_LIBRARIES( )
