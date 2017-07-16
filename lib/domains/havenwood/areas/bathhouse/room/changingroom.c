
#include <lib.h>
#include "../bathhouse.h"
#include "/domains/havenwood/towns/parva/parva.h"

inherit LIB_ROOM;

static void create() {
 room::create();
 SetTown("Parva");
 SetClimate("indoors");
 SetAmbientLight(30);
 SetShort("the changing room");
 SetLong(
    "All around the wooden room are pegs for hanging various "
    "belongings. The floor is covered in a thin layer of "
    "sawdust, to keep people from slipping and hurting themselves. "
    "The wooden ceiling drips a little from, hopefully, the water "
    "that has evaporated from the bath. To the north the baths can "
    "been seen through a doorway, and to the east is the entrance "
    "of Wadlow's.");
 SetItems( ([
    ({ "pegs", "peg", "belongings" }) :
    "These pegs are nothing fancy, just wooden pegs used to hang "
    "the various belongings of the customers.",
    ({ "sawdust", "floor" }) :
    "The floor is covered in a thin layer of sawdust to reduce "
    "the amount of slips and spills a wet floor can cause.",
    ({ "ceiling", "drip" }) :
    "Overhead, the ceiling sags a little bit from poor maintenance. "
    "Water drips freely onto the floor from various parts of the "
    "ceiling.",
    ({ "doorway", "door" }) :
    "The doorways are simple affairs, wooden with no guard at the bottom. "
    "To the north is the bathing room, to the east is the exit of this "
    "sordid establishment.",
  ]) );
 SetItemAdjectives( ([
    "pegs" : ({ "wooden", "wood" }),
    "floor" : ({ "covered" }),
    "door" : ({ "east", "eastern", "north", "northern" }),
  ]) );
 SetSmell( ([
    "default" : "Some awful rotten fish odor has been poorly masked "
    "by the smell of burning herbs."
  ]) );
 SetListen( ([
    "default" : "Through the doorway, other guests can be heard "
    "enjoying themselves."
  ]) );
 SetInventory( ([
    BH_NPC + "lady" :1,
  ]) );
 SetExits( ([
    "east" : BH_ROOM + "entrance",
    "north" : BH_ROOM + "baths",
  ]) );
}


