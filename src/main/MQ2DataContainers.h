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

#pragma once

// this header is to create containers used for passing data around
// try to make them generic and reusable

namespace mq {

class MQ2SlotInItem
{
public:
	ItemGlobalIndex GlobalIndex;
	int Slot;
	MQ2SlotInItem(const ItemGlobalIndex& GlobalIndex, int Slot)
		: GlobalIndex(GlobalIndex), Slot(Slot) {}
};

}

