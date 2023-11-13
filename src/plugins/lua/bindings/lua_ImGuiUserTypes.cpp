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

#include "pch.h"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/misc/cpp/imgui_stdlib.h>
#include <sol/sol.hpp>

#include <string>

#include "mq/imgui/Widgets.h"

namespace mq::lua::bindings {

//============================================================================

void RegisterBindings_ImGuiUserTypes(sol::state_view lua)
{
	// ImVec2
	lua.new_usertype<ImVec2>(
		"ImVec2"                                        , sol::call_constructor
		                                                , sol::constructors<ImVec2(), ImVec2(float, float)>(),
		"x"                                             , &ImVec2::x,
		"y"                                             , &ImVec2::y,
		sol::meta_function::to_string                   , [](ImVec2& mThis) { return fmt::format("({},{})", mThis.x, mThis.y); },
		sol::meta_function::addition                    , sol::overload(
			                                              [](ImVec2& a, ImVec2& b) { return ImVec2(a.x + b.x, a.y + b.y); },
			                                              [](ImVec2& a, float b) { return ImVec2(a.x + b, a.y + b); }),
		sol::meta_function::subtraction                 , sol::overload(
			                                              [](ImVec2& a, ImVec2& b) { return ImVec2(a.x - b.x, a.y - b.y); },
			                                              [](ImVec2& a, float b) { return ImVec2(a.x - b, a.y - b); }),
		sol::meta_function::multiplication              , sol::overload(
			                                              [](ImVec2& a, ImVec2& b) { return ImVec2(a.x * b.x, a.y * b.y); },
			                                              [](ImVec2& a, float b) { return ImVec2(a.x * b, a.y * b); }),
		sol::meta_function::division                    , sol::overload(
			                                              [](ImVec2& a, ImVec2& b) { return ImVec2(a.x / b.x, a.y / b.y); },
			                                              [](ImVec2& a, float b) { return ImVec2(a.x / b, a.y / b); }),
		sol::meta_function::equal_to                    , [](ImVec2& a, ImVec2& b) { return a.x == b.x && a.y == b.y; },
		sol::meta_function::less_than                   , [](ImVec2& a, ImVec2& b) { return std::tie(a.x, a.y) < std::tie(b.x, b.y); },
		sol::meta_function::less_than_or_equal_to       , [](ImVec2& a, ImVec2& b) { return std::tie(a.x, a.y) <= std::tie(b.x, b.y); }
	);

	// ImVec4
	lua.new_usertype<ImVec4>(
		"ImVec4"                                        , sol::call_constructor
		                                                , sol::constructors<ImVec4(), ImVec4(float, float, float, float)>(),
		"x"                                             , &ImVec4::x,
		"y"                                             , &ImVec4::y,
		"z"                                             , &ImVec4::z,
		"w"                                             , &ImVec4::w,
		sol::meta_function::to_string                   , [](ImVec4& mThis) { return fmt::format("({},{},{},{})", mThis.x, mThis.y, mThis.z, mThis.w); }
	);

	// ImGuiStyle
	lua.new_usertype<ImGuiStyle>(
		"ImGuiStyle"                                    , sol::no_constructor,
		"Alpha"                                         , &ImGuiStyle::Alpha,
		"WindowPadding"                                 , &ImGuiStyle::WindowPadding,
		"WindowRounding"                                , &ImGuiStyle::WindowRounding,
		"WindowBorderSize"                              , &ImGuiStyle::WindowBorderSize,
		"WindowMinSize"                                 , &ImGuiStyle::WindowMinSize,
		"WindowTitleAlign"                              , &ImGuiStyle::WindowTitleAlign,
		"WindowMenuButtonPosition"                      , &ImGuiStyle::WindowMenuButtonPosition,
		"ChildRounding"                                 , &ImGuiStyle::ChildRounding,
		"ChildBorderSize"                               , &ImGuiStyle::ChildBorderSize,
		"PopupRounding"                                 , &ImGuiStyle::PopupRounding,
		"PopupBorderSize"                               , &ImGuiStyle::PopupBorderSize,
		"FramePadding"                                  , &ImGuiStyle::FramePadding,
		"FrameRounding"                                 , &ImGuiStyle::FrameRounding,
		"FrameBorderSize"                               , &ImGuiStyle::FrameBorderSize,
		"ItemSpacing"                                   , &ImGuiStyle::ItemSpacing,
		"ItemInnerSpacing"                              , &ImGuiStyle::ItemInnerSpacing,
		"CellPadding"                                   , &ImGuiStyle::CellPadding,
		"TouchExtraPadding"                             , &ImGuiStyle::TouchExtraPadding,
		"IndentSpacing"                                 , &ImGuiStyle::IndentSpacing,
		"ColumnsMinSpacing"                             , &ImGuiStyle::ColumnsMinSpacing,
		"ScrollbarSize"                                 , &ImGuiStyle::ScrollbarSize,
		"ScrollbarRounding"                             , &ImGuiStyle::ScrollbarRounding,
		"GrabMinSize"                                   , &ImGuiStyle::GrabMinSize,
		"GrabRounding"                                  , &ImGuiStyle::GrabRounding,
		"LogSliderDeadzone"                             , &ImGuiStyle::LogSliderDeadzone,
		"TabRounding"                                   , &ImGuiStyle::TabRounding,
		"TabBorderSize"                                 , &ImGuiStyle::TabBorderSize,
		"TabMinWidthForCloseButton"                     , &ImGuiStyle::TabMinWidthForCloseButton,
		"ColorButtonPosition"                           , &ImGuiStyle::ColorButtonPosition,
		"ButtonTextAlign"                               , &ImGuiStyle::ButtonTextAlign,
		"SelectableTextAlign"                           , &ImGuiStyle::SelectableTextAlign,
		"DisplayWindowPadding"                          , &ImGuiStyle::DisplayWindowPadding,
		"DisplaySafeAreaPadding"                        , &ImGuiStyle::DisplaySafeAreaPadding,
		"MouseCursorScale"                              , &ImGuiStyle::MouseCursorScale,
		"AntiAliasedLines"                              , &ImGuiStyle::AntiAliasedLines,
		"AntiAliasedLinesUseTex"                        , &ImGuiStyle::AntiAliasedLinesUseTex,
		"AntiAliasedFill"                               , &ImGuiStyle::AntiAliasedFill,
		"CurveTessellationTol"                          , &ImGuiStyle::CurveTessellationTol,
		"CircleSegmentMaxError"                         , &ImGuiStyle::CircleTessellationMaxError,
		"TabBorderSize"                                 , &ImGuiStyle::TabBorderSize,
		"Colors"                                        , &ImGuiStyle::Colors,

		// Deprecated
		"CircleSegmentMaxError"                         , &ImGuiStyle::CircleTessellationMaxError
	);

	// ImGuiListClipper
	lua.new_usertype<ImGuiListClipper>(
		"ImGuiListClipper"                              ,
		"Begin"                                         , sol::overload(
				[](ImGuiListClipper& mthis, int items_count) { mthis.Begin(items_count); },
				&ImGuiListClipper::Begin),
		"End"                                           , &ImGuiListClipper::End,
		"Step"                                          , &ImGuiListClipper::Step,
		"DisplayStart"                                  , &ImGuiListClipper::DisplayStart,
		"DisplayEnd"                                    , &ImGuiListClipper::DisplayEnd);

	//----------------------------------------------------------------------------
	// ImDrawListSharedData
	lua.new_usertype<ImDrawListSharedData>(
		"ImDrawListSharedData", sol::no_constructor,

		"TexUvWhitePixel"                               , &ImDrawListSharedData::TexUvWhitePixel,
		"Font"                                          , &ImDrawListSharedData::Font,
		"FontSize"                                      , &ImDrawListSharedData::FontSize,
		"CurveTessellationTol"                          , &ImDrawListSharedData::CurveTessellationTol,
		"CircleSegmentMaxError"                         , &ImDrawListSharedData::CircleSegmentMaxError,
		"ClipRectFullscreen"                            , &ImDrawListSharedData::ClipRectFullscreen,
		"InitialFlags"                                  , &ImDrawListSharedData::InitialFlags
	);

	//----------------------------------------------------------------------------
	// ImDrawList
	auto imDrawList = lua.new_usertype<ImDrawList>(
		"ImDrawList", sol::constructors<ImDrawList(const ImDrawListSharedData*)>(),

		// Variables
		"Flags", &ImDrawList::Flags
	);

	// Functions
	imDrawList.set_function("PushClipRect", sol::overload(
		[](ImDrawList& mThis, ImVec2 clip_rect_min, ImVec2 clip_rect_max) { mThis.PushClipRect(clip_rect_min, clip_rect_min); },
		&ImDrawList::PushClipRect));
	imDrawList.set_function("PushClipRectFullScreen", &ImDrawList::PushClipRectFullScreen);
	imDrawList.set_function("PopClipRect", &ImDrawList::PopClipRect);
	imDrawList.set_function("PushTextureID", &ImDrawList::PushTextureID);
	imDrawList.set_function("PopTextureID", &ImDrawList::PopTextureID);
	imDrawList.set_function("GetClipRectMin", &ImDrawList::GetClipRectMin);
	imDrawList.set_function("GetClipRectMax", &ImDrawList::GetClipRectMax);
	imDrawList.set_function("ChannelsSplit", &ImDrawList::ChannelsSplit);
	imDrawList.set_function("ChannelsSetCurrent", &ImDrawList::ChannelsSetCurrent);
	imDrawList.set_function("ChannelsMerge", &ImDrawList::ChannelsMerge);

	// Primitives
	imDrawList.set_function("AddLine", sol::overload(
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, int col) { mThis.AddLine(p1, p2, ImU32(col)); },
		&ImDrawList::AddLine));
	imDrawList.set_function("AddRect", sol::overload(
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, int col) { mThis.AddRect(p1, p2, ImU32(col)); },
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, int col, float rounding) { mThis.AddRect(p1, p2, ImU32(col), rounding); },
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, int col, float rounding, int flags) { mThis.AddRect(p1, p2, ImU32(col), rounding, ImDrawFlags(flags)); },
		&ImDrawList::AddRect));
	imDrawList.set_function("AddRectFilled", sol::overload(
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, int col) { mThis.AddRectFilled(p1, p2, ImU32(col)); },
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, int col, float rounding) { mThis.AddRectFilled(p1, p2, ImU32(col), rounding); },
		&ImDrawList::AddRectFilled));
	imDrawList.set_function("AddRectFilledMultiColor", &ImDrawList::AddRectFilledMultiColor);
	imDrawList.set_function("AddQuad", sol::overload(
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, int col) { mThis.AddQuad(p1, p2, p3, p4, ImU32(col)); },
		&ImDrawList::AddQuad));
	imDrawList.set_function("AddQuadFilled", &ImDrawList::AddQuadFilled);
	imDrawList.set_function("AddTriangle", sol::overload(
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, int col) { mThis.AddTriangle(p1, p2, p3, ImU32(col)); },
		&ImDrawList::AddTriangle));
	imDrawList.set_function("AddTriangleFilled", &ImDrawList::AddTriangleFilled);
	imDrawList.set_function("AddCircle", sol::overload(
		[](ImDrawList& mThis, const ImVec2& center, float radius, int col) { mThis.AddCircle(center, radius, ImU32(col)); },
		[](ImDrawList& mThis, const ImVec2& center, float radius, int col, int num_segments) { mThis.AddCircle(center, radius, ImU32(col), num_segments); },
		&ImDrawList::AddCircle));
	imDrawList.set_function("AddCircleFilled", sol::overload(
		[](ImDrawList& mThis, const ImVec2& center, float radius, int col, int num_segments) { mThis.AddCircleFilled(center, radius, ImU32(col), num_segments); },
		&ImDrawList::AddCircleFilled));
	imDrawList.set_function("AddNgon", sol::overload(
		[](ImDrawList& mThis, const ImVec2& center, float radius, int col, int num_segments) { mThis.AddNgon(center, radius, col, num_segments); },
		&ImDrawList::AddNgon));
	imDrawList.set_function("AddNgonFilled", &ImDrawList::AddNgonFilled);
	imDrawList.set_function("AddText", sol::overload(
		[](ImDrawList& mThis, const ImVec2& pos, int col, std::string_view text) { mThis.AddText(pos, ImU32(col), text.data(), text.data() + text.size()); },
		[](ImDrawList& mThis, const ImFont* font, float font_size, const ImVec2& pos, int col, std::string_view text) { mThis.AddText(font, font_size, pos, ImU32(col), text.data(), text.data() + text.size()); }));

	imDrawList.set_function("AddPolyline", [](ImDrawList& mThis, const sol::as_table_t<std::vector<ImVec2>>& points, int col, int flags, float thickness)
		{
			const std::vector<ImVec2>& vecs = points.value();
			mThis.AddPolyline(&vecs[0], (int)vecs.size(), ImU32(col), ImDrawFlags(flags), thickness);
		});
	imDrawList.set_function("AddConvexPolyFilled", [](ImDrawList& mThis, const sol::as_table_t<std::vector<ImVec2>>& points, int col)
		{
			const std::vector<ImVec2>& vecs = points.value();
			mThis.AddConvexPolyFilled(&vecs[0], (int)vecs.size(), ImU32(col));
		});
	imDrawList.set_function("AddBezierCubic", sol::overload(
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, int col, float thickness) { mThis.AddBezierCubic(p1, p2, p3, p4, ImU32(col), thickness); },
		&ImDrawList::AddBezierCubic));
	imDrawList.set_function("AddBezierQuadratic", sol::overload(
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, int col, float thickness) { mThis.AddBezierQuadratic(p1, p2, p3, ImU32(col), thickness); },
		&ImDrawList::AddBezierQuadratic));

		// Image primitives
	imDrawList.set_function("AddImage", sol::overload(
		[](ImDrawList& mThis, ImTextureID user_texture_id, const ImVec2& p_min, const ImVec2& p_max) { mThis.AddImage(user_texture_id, p_min, p_max);  },
		[](ImDrawList& mThis, ImTextureID user_texture_id, const ImVec2& p_min, const ImVec2& p_max, const ImVec2& uv_min) { mThis.AddImage(user_texture_id, p_min, p_max, uv_min); },
		[](ImDrawList& mThis, ImTextureID user_texture_id, const ImVec2& p_min, const ImVec2& p_max, const ImVec2& uv_min, const ImVec2& uv_max) { mThis.AddImage(user_texture_id, p_min, p_max, uv_min, uv_max); }, [](ImDrawList& mThis, ImTextureID user_texture_id, const ImVec2& p_min, const ImVec2& p_max, const ImVec2& uv_min, const ImVec2& uv_max) { mThis.AddImage(user_texture_id, p_min, p_max, uv_min, uv_max); },
		[](ImDrawList& mThis, ImTextureID user_texture_id, const ImVec2& p_min, const ImVec2& p_max, const ImVec2& uv_min, const ImVec2& uv_max, int col) { mThis.AddImage(user_texture_id, p_min, p_max, uv_min, uv_max, ImU32(col)); }
	));
	imDrawList.set_function("AddImageQuad", sol::overload(
		[](ImDrawList& mThis, ImTextureID user_texture_id, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4) { mThis.AddImageQuad(user_texture_id, p1, p2, p3, p4); },
		[](ImDrawList& mThis, ImTextureID user_texture_id, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& uv1) { mThis.AddImageQuad(user_texture_id, p1, p2, p3, p4, uv1); },
		[](ImDrawList& mThis, ImTextureID user_texture_id, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& uv1, const ImVec2& uv2) { mThis.AddImageQuad(user_texture_id, p1, p2, p3, p4, uv1, uv2); },
		[](ImDrawList& mThis, ImTextureID user_texture_id, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& uv1, const ImVec2& uv2, const ImVec2& uv3) { mThis.AddImageQuad(user_texture_id, p1, p2, p3, p4, uv1, uv2, uv3); },
		[](ImDrawList& mThis, ImTextureID user_texture_id, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& uv1, const ImVec2& uv2, const ImVec2& uv3, const ImVec2& uv4) { mThis.AddImageQuad(user_texture_id, p1, p2, p3, p4, uv1, uv2, uv3, uv4); },
		[](ImDrawList& mThis, ImTextureID user_texture_id, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& uv1, const ImVec2& uv2, const ImVec2& uv3, const ImVec2& uv4, int col) { mThis.AddImageQuad(user_texture_id, p1, p2, p3, p4, uv1, uv2, uv3, uv4, ImU32(col)); }
	));
	imDrawList.set_function("AddImageRounded", sol::overload(
		[](ImDrawList& mThis, ImTextureID user_texture_id, const ImVec2& p_min, const ImVec2& p_max, const ImVec2& uv_min, const ImVec2& uv_max, int col, float rounding) { mThis.AddImageRounded(user_texture_id, p_min, p_max, uv_min, uv_max, ImU32(col), rounding); },
		[](ImDrawList& mThis, ImTextureID user_texture_id, const ImVec2& p_min, const ImVec2& p_max, const ImVec2& uv_min, const ImVec2& uv_max, int col, float rounding, int flags) { mThis.AddImageRounded(user_texture_id, p_min, p_max, uv_min, uv_max, ImU32(col), rounding, ImDrawFlags(flags)); }
	));

	imDrawList.set_function("AddTextureAnimation",
		[](ImDrawList& mThis, const std::unique_ptr<CTextureAnimation>& anim, const ImVec2& pos, const sol::optional<ImVec2>& size) {
			return imgui::AddTextureAnimation(&mThis, anim.get(), eqlib::CXPoint(pos.x, pos.y), size.has_value() ? CXPoint(size->x, size->y) : CXPoint());
		});


	// Stateful Path API
	imDrawList.set_function("PathClear", &ImDrawList::PathClear);
	imDrawList.set_function("PathLineTo", &ImDrawList::PathLineTo);
	imDrawList.set_function("PathLineToMergeDuplicate", &ImDrawList::PathLineToMergeDuplicate);
	imDrawList.set_function("PathFillConvex", &ImDrawList::PathFillConvex);
	imDrawList.set_function("PathStroke", sol::overload(
		[](ImDrawList& mThis, int col) { mThis.PathStroke(ImU32(col)); },
		[](ImDrawList& mThis, int col, int flags) { mThis.PathStroke(ImU32(col), ImDrawFlags(flags)); },
		[](ImDrawList& mThis, int col, int flags, float thickness) { mThis.PathStroke(ImU32(col), ImDrawFlags(flags), thickness); }
	));
	imDrawList.set_function("PathArcTo", sol::overload(
		[](ImDrawList& mThis, const ImVec2& center, float radius, float a_min, float a_max) { mThis.PathArcTo(center, radius, a_min, a_max); },
		[](ImDrawList& mThis, const ImVec2& center, float radius, float a_min, float a_max, int num_segments) { mThis.PathArcTo(center, radius, a_min, a_max, num_segments); }
	));
	imDrawList.set_function("PathArcToFast", &ImDrawList::PathArcToFast);
	imDrawList.set_function("PathBezierCubicCurveTo", sol::overload(
		[](ImDrawList& mThis, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4) { mThis.PathBezierCubicCurveTo(p2, p3, p4); },
		[](ImDrawList& mThis, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, int num_segments) { mThis.PathBezierCubicCurveTo(p2, p3, p4, num_segments); }
	));
	imDrawList.set_function("PathBezierQuadraticCurveTo", sol::overload(
		[](ImDrawList& mThis, const ImVec2& p2, const ImVec2& p3) { mThis.PathBezierQuadraticCurveTo(p2, p3); },
		[](ImDrawList& mThis, const ImVec2& p2, const ImVec2& p3, int num_segments) { mThis.PathBezierQuadraticCurveTo(p2, p3, num_segments); }
	));
	imDrawList.set_function("PathRect", sol::overload(
		[](ImDrawList& mThis, const ImVec2& rect_min, const ImVec2& rect_max) { mThis.PathRect(rect_min, rect_max); },
		[](ImDrawList& mThis, const ImVec2& rect_min, const ImVec2& rect_max, float rounding) { mThis.PathRect(rect_min, rect_max, rounding); },
		[](ImDrawList& mThis, const ImVec2& rect_min, const ImVec2& rect_max, float rounding, int flags) { mThis.PathRect(rect_min, rect_max, rounding, ImDrawFlags(flags)); }
	));

	lua.new_usertype<ImGuiTableColumnSortSpecs>(
		"ImGuiTableSortSpecsColumn"    , sol::no_constructor,
		"ColumnUserID"                 , sol::readonly(&ImGuiTableColumnSortSpecs::ColumnUserID),
		"ColumnIndex"                  , sol::readonly(&ImGuiTableColumnSortSpecs::ColumnIndex),
		"SortOrder"                    , sol::readonly(&ImGuiTableColumnSortSpecs::SortOrder),
		"SortDirection"                , sol::property([](ImGuiTableColumnSortSpecs* spec) { return spec->SortDirection;})
	);
	lua.new_usertype<ImGuiTableSortSpecs>(
		"ImGuiTableSortSpecs"          , sol::no_constructor,
		"Specs"                        , [](ImGuiTableSortSpecs* spec, int index) -> ImGuiTableColumnSortSpecs* { if (index > 0 && index <= spec->SpecsCount) return (ImGuiTableColumnSortSpecs*)&spec->Specs[index - 1]; return nullptr; },
		"SpecsCount"                   , sol::readonly(&ImGuiTableSortSpecs::SpecsCount),
		"SpecsDirty"                   , &ImGuiTableSortSpecs::SpecsDirty
	);

	// ImGuiFontAtlas
	lua.new_usertype<ImFontAtlas>(
		"ImFontAtlas"                  , sol::no_constructor,

		"Flags"                        , &ImFontAtlas::Flags,
		"TexID"                        , &ImFontAtlas::TexID,
		"TexWidth"                     , sol::readonly(&ImFontAtlas::TexWidth),
		"TexHeight"                    , sol::readonly(&ImFontAtlas::TexHeight)
	);


	// ImGuiIO
	lua.new_usertype<ImGuiIO>(
		"ImGuiIO"                      , sol::no_constructor,

		"ConfigFlags"                  , &ImGuiIO::ConfigFlags,
		"DisplaySize"                  , sol::readonly(&ImGuiIO::DisplaySize),
		"FontDefault"                  , sol::readonly(&ImGuiIO::FontDefault),
		"Fonts"                        , sol::readonly(&ImGuiIO::Fonts),
		"MouseDelta"                   , sol::readonly(&ImGuiIO::MouseDelta),
		"MousePos"                     , sol::readonly(&ImGuiIO::MousePos),

		"KeyCtrl"                      , sol::readonly(&ImGuiIO::KeyCtrl),
		"KeyShift"                     , sol::readonly(&ImGuiIO::KeyShift),
		"KeyAlt"                       , sol::readonly(&ImGuiIO::KeyAlt),
		"KeySuper"                     , sol::readonly(&ImGuiIO::KeySuper)
	);

	// ImGuiViewport
	lua.new_usertype<ImGuiViewport>(
		"ImGuiViewport"                , sol::no_constructor,

		"ID"                           , sol::readonly(&ImGuiViewport::ID),
		"Flags"                        , sol::readonly(&ImGuiViewport::Flags),
		"Pos"                          , sol::readonly(&ImGuiViewport::Pos),
		"Size"                         , sol::readonly(&ImGuiViewport::Size),
		"WorkPos"                      , sol::readonly(&ImGuiViewport::WorkPos),
		"WorkSize"                     , sol::readonly(&ImGuiViewport::WorkSize),
		"DpiScale"                     , sol::readonly(&ImGuiViewport::DpiScale),
		"ParentViewportId"             , sol::readonly(&ImGuiViewport::ParentViewportId),

		"GetCenter"                    , &ImGuiViewport::GetCenter,
		"GetWorkCenter"                , &ImGuiViewport::GetWorkCenter
	);
}

} // namespace mq::lua::bindings
