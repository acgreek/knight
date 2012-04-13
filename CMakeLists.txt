cmake_minimum_required (VERSION 2.6)
project (Knights)

find_package(PkgConfig)
pkg_check_modules (EXTREMECUNIT ExtremeCUnit)
add_executable(Knights knights.cc)

target_link_libraries(Knights
	${EXTREMECUNIT_LIBRARIES}
)
add_definitions("-ldl  -fPIC `pkg-config --cflags ExtremeCUnit` -Wl,--rpath,. ")
set(CMAKE_EXE_LINKER_FLAGS " -pie  -Wl,--rpath,.,--rpath,dist -rdynamic  ")

