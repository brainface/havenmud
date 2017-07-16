#include <lib.h>
#include "../argoth.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetShort("Argoth Weaponsmith");
  SetDomain("Crystal Reaches");
    SetLong("The Argoth Weaponsmith is decorated in a unique fashion, with "
    "deadly looking weapons hanging from the walls, as well as skulls from "
    "various races in a display case near the wall.");
     SetItems( ([
    ({ "deadly looking weapons", "weapons" }) :
    "All forms of the various implements of war are represented here.",
    ({ "walls", "wall" }) :
    "The walls are made of a very dark wood.",
    ({ "skulls" }) :
    "The skulls are from the nosferatu, dwarf, and sprite races.",
    ({ "display case", "case" }) :
    "The display case was crudely fashioned out of iron and wood.",
]) );
    SetExits( ([
    "out" : ARGOTH_ROOM + "rd4.c",
]) );
    SetObviousExits("out");
    SetSmell( ([
    "default" : "The Weaponsmith smells of lacquer polish and coal.",
]) );
    SetInventory( ([
    ARGOTH_NPC + "garret.c" : 1,
]) );
    SetClimate("indoors");
    SetAmbientLight(40);
}
