#include "path.h"
#include <lib.h>
inherit LIB_NPC;

static void create() {
    npc::create();
    SetMorality(25);
    SetKeyName("human footsoldier");
    SetId( ({ "footsoldier", "soldier", "human" }) );
    SetAdjectives( ({ "foot", "human" }) );
    SetShort("a human footsoldier");
    SetLong("This soldier is a standard infantryman in the human army. "
             "His visage is grim and determined, as if nothing could "
            "faze him.");
    SetRace("human");
    SetClass("fighter");
    SetLevel(random(5) + 10);
    SetGender("male");
    SetInventory( ([
          BEORN_OBJ + "flail.c" : "wield flail",
          BEORN_OBJ + "banded.c" : "wear banded armour",
					]) );
}
