#include <lib.h>
#include "../argoth.h"

inherit LIB_ROOM;
static void create() {
    room::create();
  SetDomain("Crystal Reaches");
    SetShort("a dank room");
    SetLong("A small amount of light streams in through the holes in the sewer "
    "grate above, revealing a small, damp, murky room.  Water drips from the "
    "ceiling and mold grows everywhere.  Only the most depraved of individuals "
    "would want to make a dwelling here.");
    SetItems( ([
    ({ "holes", "sewer grate", "grate" }) :
    "Holes are spaced evenly on the sewer grate which allows entry to this "
    "room, allowing some light to pass through.",
    ({ "small, damp, murky room", "damp room", "murky room", "small room",
    "room" }) :
    "This room is a miserable, depressing place.",
    ({ "water" }) :
    "Water from the street above constantly drips from the ceiling.",
    ({ "ceiling" }) :
    "The ceiling is wet, dirty, and covered in mold.",
    ({ "mold" }) :
    "The mold is a sickening shade of yellow-green.",
]) );
    SetExits( ([
    "out" : ARGOTH_ROOM + "rd6.c",
]) );
    SetObviousExits("out");
    SetSmell( ([
    "default" : "There is a nauseating smell of waste and rot here.",
]) );
    SetListen( ([
    "default" : "The scurrying of rats can be heard.",
]) );
    SetInventory( ([
    ARGOTH_NPC + "rogue_leader.c" : 1,
]) );
}
