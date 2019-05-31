cmake_minimum_required(VERSION 3.14)

function(sdl_demo name)
    add_executable("${name}" "${name}.cpp")
    target_link_libraries("${name}" /home/burchr/code/SDL-mirror/libSDL2.a)
    target_link_libraries("${name}" gui core)
    target_include_directories("${name}" PUBLIC /home/burchr/code/SDL-mirror/include)
    install(TARGETS "${name}" DESTINATION ./usr/bin/)
endfunction()

sdl_demo(titlebar)
sdl_demo(rects)
