#include "Global.h"

HL_PRIM bool HL_NAME(Begin)(vstring* name, bool* open, ImGuiWindowFlags flags) {
	return ImGui::Begin(hl_to_utf8(name->bytes), open, flags);
}

HL_PRIM void HL_NAME(End)() {
	ImGui::End();
}

// HL_PRIM bool HL_NAME(begin_child)(vstring* str_id, vimvec2* size, bool* border, ImGuiWindowFlags* flags)
// {
// 	return ImGui::BeginChild(convertString(str_id), getImVec2(size), convertPtr(border, false), convertPtr(flags, 0));
// }
//
// HL_PRIM bool HL_NAME(begin_child2)(int id, vimvec2* size, bool* border, ImGuiWindowFlags* flags)
// {
// 	return ImGui::BeginChild(ImGuiID(id), getImVec2(size), convertPtr(border, false), convertPtr(flags, 0));
// }
//
// HL_PRIM void HL_NAME(end_child)()
// {
// 	ImGui::EndChild();
// }

DEFINE_PRIM(_BOOL, Begin, _STRING _REF(_BOOL) _I32);
DEFINE_PRIM(_VOID, End, _NO_ARG);
// DEFINE_PRIM(_BOOL, begin_child, _STRING _IMVEC2 _REF(_BOOL) _REF(_I32));
// DEFINE_PRIM(_BOOL, begin_child2, _I32 _IMVEC2 _REF(_BOOL) _REF(_I32));
// DEFINE_PRIM(_VOID, end_child, _NO_ARG);
