#include "path.h"
#include <lib.h>

inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("orc raider");
    SetId( ({"orc", "raider", "orc raider" }) );
    SetMorality(-50);
    SetShort("an orc raider");
    SetLong("This orc is an example of the standard forces in the orkish "
            "hordes.  He looks like little more than cannon fodder, "
           "but could still put up a fight.");
    SetRace("orc");
    SetClass("fighter");
    SetLevel(12);
    SetGender("male");
    SetInventory( ([
          BEORN_OBJ + "brigandine.c" : "wear brigandine armour",
          BEORN_OBJ + "morningstar.c" : "wield morning star",
					]) );
}
