/*  armoury */

#include <lib.h>
#include <domains.h>
#include "../glim.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(45);
  SetShort("the Great Armoury");
  SetLong("This is the office of the Glistendin Ministry of armour Craft.  "
    "It is here that armour goes through final approval before it is "
    "distributed to the dwarven armies or sold to the dwarven "
    "populace.  Torches are attached to various points along the "
    "stone wall and provide a flickering, red light that seems to give "
    "the room a feeling of darkness, almost as if that which lies in "
    "this room was meant to protect cruel soldiers.  Great piles "
    "of armour, all standard in make, rest upon racks and seem to "
    "eminate a red aura in the flickering fire light.");
  SetItems( ([
    ({"office", "ministry", "amoury", "armoury"}) :  (:GetLong:),
    ({"torches", "torch", "flickering fire light", "fire", "light"}) :
      "Torches provide the room with a flickering, red light.",
    ({"western passage", "passage"})  :
      "The Western Passage is outside.",
    ({"armour", "armours", "armour", "armours", "piles", "pile"})  :
      "armour rests upon racks and awaits distribution.",
    ({"rack", "racks"})  :
      "Racks support armour awaiting distribution.",
    ({"weaponry"})  :
     "The weaponry is to the south.",
    ({"armoury"})  :
      "The armoury is to the north.",
    ({"stone floor", "floor"})  :
       "The floor is made of stone.",
    ({"stone"})  :
      "The stone is very hard.",
   ]) );
  SetItemAdjectives( ([
    "torches"  :  ({"red"}),
    "armour"  :  ({"standard"}),
    "western passage"  :  ({"outside"}),
    "stone"  :  ({"hard"}),
    "armoury"  :  ({"greatest"}),
    ]) );
  SetExits( ([
    "out" : AVERATH_ISLAND "-7,-3,1",
    ]) );
  SetSmell( ([
    "default" : "Smoke is rather heavy here.",
    ]) );
  SetListen( ([
    "default" : "Torches smolder and crackle as they burn.",
    ]) );
  SetInventory( ([
    G_NPC "armour_dude" : 1,
  ]) );
}
