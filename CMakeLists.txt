cmake_minimum_required (VERSION 2.8)
file(GLOB SOURCE_FILES "*.cpp" "engine/*.cpp")
add_executable (megaminx ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(megaminx ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
