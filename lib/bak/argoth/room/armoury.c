#include <lib.h>
#include "../argoth.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetShort("Argoth Armoury");
    SetLong("Built out of tempered steel, the Argoth Armoury has a tendency "
    "to get very hot very fast during summer days.  However, the thinking "
    "behind the owner's decision to build it in such a way is clear:  The "
    "building can easily attract customers because of its odd shape, and they "
    "stay to buy merchandise.");
  SetDomain("Crystal Reaches");
    SetItems( ([
    ({ "tempered steel", "steel" }) :
    "The steel is a dark grey color",
    ({ "building", "armoury", "argoth armoury" }) :
    (: GetLong :),
]) );
    SetExits( ([
    "out" : ARGOTH_ROOM + "rd4.c",
]) );
    SetObviousExits("out");
    SetSmell( ([
    "default" : "There is a faint odor of leather.",
]) );
    SetInventory( ([
    ARGOTH_NPC + "dannel.c" : 1,
]) );
    SetClimate("indoors");
    SetAmbientLight(40);
}
