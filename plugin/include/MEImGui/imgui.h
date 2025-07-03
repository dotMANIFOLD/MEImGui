//
// Created by ryen on 7/3/25.
//

#pragma once

#include <MECore/math/Types.h>

#define IM_VEC2_CLASS_EXTRA                                                     \
    constexpr ImVec2(const ME::Vector2& f) : x(f.x), y(f.y) {}                   \
    operator ME::Vector2() const { return ME::Vector2{x,y}; }

#define IM_VEC4_CLASS_EXTRA                                                     \
    constexpr ImVec4(const ME::Vector4& f) : x(f.GetX()), y(f.GetY()), z(f.GetZ()), w(f.GetW()) {}   \
    operator ME::Vector4() const { return ME::Vector4(x,y,z,w); }

#include <imgui.h>
