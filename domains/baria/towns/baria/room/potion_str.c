#include <lib.h>
#include <domains.h>
#include <std.h>
#include "../jungle.h"
inherit LIB_STOREROOM;

static void create() {
::create();
SetShort("apothecary shop of haven");
SetInventory( ([
STD_MEAL "drink/mana_pot_weak" :5,
STD_MEAL "drink/health_pot_weak" :5,
]) );
SetExits( ([
]) );
}

