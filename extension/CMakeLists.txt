cmake_minimum_required(VERSION 3.21)
cmake_policy(SET CMP0048 NEW)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)

add_library(MEImGuiExt SHARED)
target_sources(MEImGuiExt PRIVATE ${SOURCES})

target_link_libraries(MEImGuiExt PRIVATE ME::Core Jolt::Jolt libhl ME::ImGui imgui)

set_target_properties(MEImGuiExt PROPERTIES PREFIX "" OUTPUT_NAME MEImGui SUFFIX .hdll)

add_library(ME::ImGuiExt ALIAS MEImGuiExt)
