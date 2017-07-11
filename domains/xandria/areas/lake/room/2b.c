//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("inside a ceramics workshop");
  SetClimate("indoors");
  SetLong(
    "Gigantic kilns, giving off waves of heat, stand on every "
    "wall here. Benches hold fired clay and more brittle faience "
    "pieces in various forms of production as the workers go "
    "about their dangerous, hot business. There is an exit out "
    "as well as a doorway into a quieter, cooler room to the west."
  );
  SetItems( ([
    ({ "kiln", "kilns" }) :
    "Enormous. Huge. They bake many things at a time at white-hot "
    "temperatures.",
    ({ "bench", "benches" }) :
    "The stone benches hold ceramics. ",
    ({ "clay", "faience", "pieces", "ceramics" }) : 
    "Beads, pots, sculptures, platters. Everything and anything.",
  ]) );
  SetItemAdjectives( ([
  "kilns" : ({ "gigantic" }),
  "clay" : ({ "fired" }),
  "faience" : ({ "brittle" }),
  "bench" : ({ "stone" }),
  ]) );
  SetInventory( ([
    LAKE_NPC "worker" : 2,
  ]) );
  SetListen("The rushing of heated air makes billowing noises.");
  SetSmell("The air smells dry and dusty.");
  SetExits( ([
    "out"  : LAKE_ROOM "/2c",
    "west" : LAKE_ROOM "/2a",
  ]) );
}
