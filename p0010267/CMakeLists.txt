PROJECT(p0010267)

SET( p0010267_HDRS
)

SET( p0010267_SRCS
	main_p0010267.cpp
	main_p0010267_v2.cpp
	main_p0010267_v3.cpp
)

ADD_LIBRARY( p0010267 main_p0010267 ) #By default will add lib
ADD_EXECUTABLE( p0010267exe main_p0010267 )

ADD_LIBRARY( p0010267_v2 main_p0010267_v2 ) #By default will add lib
ADD_EXECUTABLE( p0010267_v2exe main_p0010267_v2 )

ADD_LIBRARY( p0010267_v3 main_p0010267_v3 ) #By default will add lib
ADD_EXECUTABLE( p0010267_v3exe main_p0010267_v3 )

# TARGET_LINK_LIBRARIES( )
