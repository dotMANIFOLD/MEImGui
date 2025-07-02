cmake_minimum_required(VERSION 3.21)
cmake_policy(SET CMP0048 NEW)

project(MEImGui VERSION 1.0.0 DESCRIPTION "MANIFOLDEngine ImGui")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

if (PROJECT_IS_TOP_LEVEL)
    set(DEVELOPMENT TRUE)
endif()

add_subdirectory(plugin)
add_subdirectory(extension)

function(MEImGui_configure target)
    target_link_libraries(${target} PRIVATE ME::ImGui ME::ImGuiExt imgui)
    add_custom_command(TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:MEImGuiExt> "${CMAKE_CURRENT_BINARY_DIR}")
endfunction()
