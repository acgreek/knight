cmake_minimum_required (VERSION 2.6)
project (Knights)

find_package(PkgConfig)
pkg_check_modules (EXTREMECUNIT ExtremeCUnit)

string(REPLACE ";" " " EXTREMECUNIT_LDFLAGS2 "${EXTREMECUNIT_LDFLAGS}" )
string(REPLACE ";" " " EXTREMECUNIT_CFLAGS2 "${EXTREMECUNIT_CFLAGS}" )
message(STATUS "CFLAGS=" ${EXTREMECUNIT_CFLAGS2})

add_definitions("-Wall -ggdb3 ${EXTREMECUNIT_CFLAGS2}")

set(CMAKE_EXE_LINKER_FLAGS "${EXTREMECUNIT_LDFLAGS2} -pie")

add_library(Knights SHARED knights.cc)
target_link_libraries(Knights
	${EXTREMECUNIT_LIBRARIES}
)

add_executable(knights_test knights_test.cc)
target_link_libraries(knights_test
	${EXTREMECUNIT_LIBRARIES} Knights
)
