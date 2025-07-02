cmake_minimum_required(VERSION 3.21)
cmake_policy(SET CMP0048 NEW)

if (DEVELOPMENT)
    add_subdirectory(vendor/MECore EXCLUDE_FROM_ALL)
endif()

# IMGUI
set(imgui_srcs
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/imconfig.h
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/imgui_draw.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/imgui_tables.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/imgui_widgets.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/imgui_internal.h
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/imgui.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/imgui.h
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/imstb_rectpack.h
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/imstb_textedit.h
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/imstb_truetype.h
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/imgui_demo.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/misc/cpp/imgui_stdlib.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/misc/cpp/imgui_stdlib.h
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_sdl3.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_sdl3.h)

add_library(imgui STATIC ${imgui_srcs})
target_include_directories(imgui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)
add_library(MEImGui STATIC)
target_sources(MEImGui PRIVATE ${SOURCES})
target_include_directories(MEImGui
        PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/include
        PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

MECore_configure(MEImGui)
target_link_libraries(MEImGui PRIVATE imgui)

add_library(ME::ImGui ALIAS MEImGui)
