/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
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

#include <mq/Plugin.h>

PreSetup("MQ2EQBugFix");

class CDisplay_Hook
{
public:
	int is_3dON_Trampoline();
	int is_3dON_Detour()
	{
		if (!this)
		{
			DebugSpew("MQ2EQBugFix: Crash avoided in is_3dON");
			return 0;
		}
		return is_3dON_Trampoline();
	}
};
DETOUR_TRAMPOLINE_EMPTY(int CDisplay_Hook::is_3dON_Trampoline());

// This class implementation is specifically for the bug fix.
class CUnSerializeBuffer_BugFix
{
	const char* m_buffer = nullptr;
	size_t      m_length = 0;
	size_t      m_offset = 0;

public:
	bool GetString_Trampoline(char* dest, unsigned int destSize);
	bool GetString_Detour(char* dest, unsigned int destSize)
	{
		// Use our own implementation which does not have the bug.
		size_t size = strnlen(m_buffer + m_offset, m_length - m_offset) + 1;
		size_t readAmount = std::min(destSize - 1, size);

		if (m_offset + readAmount > m_length)
		{
			*dest = 0;
			return false;
		}

		memcpy(dest, m_buffer + m_offset, readAmount);
		dest[readAmount] = 0;
		m_offset += size;
		return true;
	}
};
DETOUR_TRAMPOLINE_EMPTY(bool CUnSerializeBuffer_BugFix::GetString_Trampoline(char*, unsigned int));

PLUGIN_API void InitializePlugin()
{
	DebugSpewAlways("Initializing MQ2EQBugFix");

	// Check against a null `this` pointer. This has been here for ages. We'ren ot even sure
	// that this is still needed.
	EzDetour(CDisplay__is3dON, &CDisplay_Hook::is_3dON_Detour, &CDisplay_Hook::is_3dON_Trampoline);

	// Avoid a buffer over-read in CUnSerializeBuffer::GetString. This function will call strlen on
	// a network message that may already have been read to the end, resulting in a buffer over-read.
	// In some cases this will read past the end of the page boundary. If this happens, and the next
	// page isn't allocated, this will result in a crash. The fix is to use strnlen instead, so that
	// the strlen call is properly bounds checked.
	// As of the 5/21/2020 live patch, this happens occasionally when receiving guild names, regardless
	// of if MQ2 is loaded.
	EzDetour(CUnSerializeBuffer__GetString, &CUnSerializeBuffer_BugFix::GetString_Detour, &CUnSerializeBuffer_BugFix::GetString_Trampoline);
}

PLUGIN_API void ShutdownPlugin()
{
	DebugSpewAlways("Shutting down MQ2EQBugFix");

	RemoveDetour(CDisplay__is3dON);
	RemoveDetour(CUnSerializeBuffer__GetString);
}