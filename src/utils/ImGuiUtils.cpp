//
// Created by somepineaple on 2/1/22.
//

#include "ImGuiUtils.h"

#include "../vendor/imgui/imgui.h"

void ImGuiUtils::drawHelper(const char *desc) {
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered()) {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}
