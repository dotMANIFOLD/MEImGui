#pragma once

extern "C" {
    #include <hl.h>
}
#include <MECore/MECore.h>
#include <MEImGui/imgui.h>

#define HL_NAME(n) MEImGui_##n

#define _PTR _I64

#define _VECTOR2 _STRUCT
#define _VECTOR3 _STRUCT
#define _VECTOR4 _STRUCT
