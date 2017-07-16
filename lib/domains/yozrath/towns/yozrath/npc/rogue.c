#include <lib.h>
#include <std.h>
#include "../yozrath.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("navid");
  SetShort("Navid of Yozrath");
  SetId( ({ "navid" }) );
  SetRace("human");
  SetBaseLanguage("Padashi");
  SetClass("rogue");
  SetLevel(20);
  SetTown("Yozrath");
  SetGender("male");
  SetMorality(-250);
  SetLong(
    "Navid has long been rumoured to be the leader of the thieves' guild "
    "in Yozrath. With his honorable bent and humble demeanor, the Sheik "
    "has permitted him to live so long as crime stays within the realm of "
    "harmless thieving in the city."
    );
  SetPlayerTitles( ([
    "newbie" : "$N the Humble Thief",
    "mortal" : "$N the Silent Walker of the Desert",
    "hm"     : "$N the Retriever of Lost Things",
    "legend" : "$N the Desert Scrounger",
    ]) );
  SetFreeEquipment( ([
    STD_KNIFE "freeknife" : 2,
    STD_LOCKPICKS "newbiepicks" : 1,
    ]) );
  SetInventory( ([
    YOZRATH_OBJ "thobe" : "wear thobe",
    ]) );
  SetLimit(1);
}
