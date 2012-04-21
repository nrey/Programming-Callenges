PROJECT(p0000706)

SET( p0000706_HDRS
)

SET( p0000706_SRCS
	main_p0000706.cpp
	main_p0000706_v2.cpp
# 	main_p0000706_v3.cpp
)

ADD_LIBRARY( p0000706 main_p0000706 ) #By default will add lib
ADD_EXECUTABLE( p0000706exe main_p0000706 )

ADD_LIBRARY( p0000706_v2 main_p0000706_v2 ) #By default will add lib
ADD_EXECUTABLE( p0000706_v2exe main_p0000706_v2 )

# ADD_LIBRARY( p0000706_v3 main_p0000706_v3 ) #By default will add lib
# ADD_EXECUTABLE( p0000706_v3exe main_p0000706_v3 )

# TARGET_LINK_LIBRARIES( )
