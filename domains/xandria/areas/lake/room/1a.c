//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("near a large building");
  SetClimate("arid");
  SetLong(
    "Here where the River Itro meets Lake Rantera, the "
    "ground is lush and verdant with plants. A large mud-brick "
    "building stands to the south of here, but it is not "
    "accessable from this side. The waterway lies off to the "
    "east, and the wall of this building continues to the "
    "southeast."
  );
  SetItems( ([
    "ground" : "The ground is blanketed with green grass. ",
    ({ "building"}) :
    "It is a long building, although not tall, built from "
    "bricks of mud. ",
    "waterway" : "The river is northeast, the lake southeast. ",
    ({ "plants" }) : 
    "Besides grass, delicate desert flowers poke through the "
    "ground, as well as various types of cacti.",
  ]) );
  SetItemAdjectives( ([
  "ground" : ({ "lush", "verdant" }),
  "building" : ({ "large", "mud-brick", "brick", "long" }),
  ]) );
  SetListen("The chirping of birds can be heard.");
  SetSmell("It smells sweetly fresh here.");
  SetExits( ([
    "east"  : LAKE_ROOM "/1b",
  ]) );
}
