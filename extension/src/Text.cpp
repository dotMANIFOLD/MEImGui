//
// Created by ryen on 7/1/25.
//

#include "Global.h"

HL_PRIM void HL_NAME(Text)(vstring* text) {
    ImGui::Text(hl_to_utf8(text->bytes));
}

HL_PRIM void HL_NAME(TextColored)(ME::Vector4* color, vstring* text) {
    ImGui::TextColored(*color, hl_to_utf8(text->bytes));
}

HL_PRIM void HL_NAME(TextDisabled)(vstring* text) {
    ImGui::TextDisabled(hl_to_utf8(text->bytes));
}

HL_PRIM void HL_NAME(TextWrapped)(vstring* text) {
    ImGui::TextWrapped(hl_to_utf8(text->bytes));
}

HL_PRIM void HL_NAME(LabelText)(vstring* label, vstring* text) {
    ImGui::LabelText(hl_to_utf8(label->bytes), hl_to_utf8(text->bytes));
}

HL_PRIM void HL_NAME(BulletText)(vstring* text) {
    ImGui::BulletText(hl_to_utf8(text->bytes));
}

DEFINE_PRIM(_VOID, Text, _STRING)
DEFINE_PRIM(_VOID, TextColored, _VECTOR4 _STRING)
DEFINE_PRIM(_VOID, TextDisabled, _STRING)
DEFINE_PRIM(_VOID, TextWrapped, _STRING)
DEFINE_PRIM(_VOID, LabelText, _STRING _STRING)
DEFINE_PRIM(_VOID, BulletText, _STRING)
