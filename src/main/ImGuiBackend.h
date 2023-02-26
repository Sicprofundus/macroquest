/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include <d3d9.h>
#include <imgui.h>

namespace mq {

bool     ImGui_ImplDX9_Init(IDirect3DDevice9* device);
void     ImGui_ImplDX9_Shutdown();
void     ImGui_ImplDX9_NewFrame();
void     ImGui_ImplDX9_RenderDrawData(ImDrawData* draw_data);

// Use if you want to reset your rendering device without losing ImGui state.
void     ImGui_ImplDX9_InvalidateDeviceObjects();
bool     ImGui_ImplDX9_CreateDeviceObjects();


bool     ImGui_ImplWin32_Init(void* hwnd);
void     ImGui_ImplWin32_Shutdown();
void     ImGui_ImplWin32_NewFrame();

float    ImGui_ImplWin32_GetDpiScaleForMonitor(void* monitor);

void     ImGui_EnableViewports(bool enable);
void     ImGui_EnableDocking(bool enable);
bool     ImGui_IsImGuiForeground();

// Implemented by ImGuiOverlay.cpp
bool     ImGuiOverlay_HandleMouseEvent(int mouseButton, bool pressed);

void     ImGuiRenderDebug_UpdateImGui();

} // namespace mq
