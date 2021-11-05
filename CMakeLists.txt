cmake_minimum_required(VERSION 3.10)

project(getglver CXX)

set(CPP_COMPILE_FLAG "-g -Wall -DENABLE_LOG")

set(GET_GL_VERSION_SRC
    src/get_gl_version.cpp)

add_definitions(${CPP_COMPILE_FLAG})

add_executable(getglver ${GET_GL_VERSION_SRC})

set_property(TARGET getglver PROPERTY CXX_STANDARD 11)

if(UNIX)
    target_link_libraries(getglver GL GLEW glfw3 dl m Xrandr
                          Xi X11 Xxf86vm Xinerama Xcursor pthread)
elseif(MINGW)
    target_link_libraries(getglver opengl32 glfw3 glew32)
endif()

