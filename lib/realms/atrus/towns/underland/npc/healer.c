#include <lib.h>
#include <std.h>
#include "../underland.h"
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("pilthon");
  SetRace("gnome");
  SetGender("male");
  SetShort("Pilthon the Healer");
  SetId( ({ "gnome", "pilthon", "healer" }) );
  SetAdjectives( ({  }) );
  SetLong(
    "Pilthon is the Healer here in the Underland. His skills "
    "at restoring the wounded (or dead) to their best is known "
    "throughout the land."
    );
  SetClass("cleric");
  SetTown("Underland");
  SetLevel(20);
  SetInventory( ([
    STD_BLUNT "war-hammer" : "wield hammer",
    UNDER_OBJ "chainmail"  : "wear chainmail",
    ]) );
}
