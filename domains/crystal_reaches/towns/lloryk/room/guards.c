#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the Shire Guard Post");
  SetExits( ([
    "out" : LLORYK "room/sg2",
    ]) );
  SetLong("The Shire Guard post is a spartan structure of wood and "
          "iron bars. Around the post are a few cots for off duty "
          "guards and a weapons rack that is securely locked down. "
          "The wooden floor is well-maintained and clean, and the "
          "entire post sparkles from military cleanliness.");
  SetItems( ([
    ({ "bars", "bar" }) : "The iron bars reinforce the structure.",
    ({ "cots", "cot" }) : "The cots are small and do not look "
                          "very comfortable.",
    ({ "rack" }) : "The weapons rack is securely locked to prevent "
                   "any unauthorized borrowing of weapons.",
    ({ "floor" }) : "The wooden floor is clean and tidy.",
    ]) );
  SetItemAdjectives( ([
    "bars" : ({ "iron" }),
    "rack" : ({ "weapon", "weapons" }),
    "floor" : ({ "wooden", }),
    ]) );
  SetInventory( ([
    LLORYK "npc/josef" : 1,
    LLORYK "npc/guard" : 2,
    LLORYK "npc/vlad"  : 1,
    LLORYK "npc/armour_equipper" : 1,
    ]) );
  SetSmell( ([
    "default" : "The Shire Guard post smells clean and well-polished.",
    ]) );
  SetListen( ([
    "default" : "The room is pleasantly quiet and peaceful.",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(40);  
}
