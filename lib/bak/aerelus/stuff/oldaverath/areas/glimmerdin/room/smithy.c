/*  weapon house */

#include <lib.h>
#include <domains.h>
#include "../glim.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(45);
  SetShort("the Great Smithy");
  SetLong("This is the office of the Glistendin Ministry of "
    "Weapon Craft.  It is here that weapons go through final "
    "proofing before they are either distributed to the armies "
    "or sold to citizens.  The stone walls are lined with axes, "
    "hammers, maces and many other sorts of weapons of "
    "varying size, make magnitude.  The warlike ways of the "
    "dwarves are all to evident to one standing here; it seems "
    "they are producing weapons in massive quantities and "
    "are quickly preparing to destroy their enemies.  A passage "
    "is to the north.");
  SetItems( ([
    ({"office", "ministry", "weaponry"}) :  (:GetLong:),
    ({ "passage" })  :
      "The Western Passage is outside.",
    ({"weapon", "axe", "hammer", "mace"})  :
      "All sorts of weapons line the walls.",
    ({"wall", "walls"})  :
      "The walls are made of stone.",
    ({"weaponry"})  :
     "The weaponry is to the south.",
    ({"armoury"})  :
      "The armoury is to the north.",
    ({"stone floor", "floor"})  :
       "The floor is made of stone.",
    ({"stone"})  :
      "The stone is very hard.",
    ({ "torches", "torch" }) : "The torches glow red with the heat.",
    ]) );
  SetItemAdjectives( ([
    "torches"  :  ({"red"}),
    "armoury"  :  ({"standard"}),
    "passage"  :  ({"outside"}),
    "stone"  :  ({"hard"}),
    "wall"  :  ({"stone"}),
    ]) );
  SetExits( ([
    "out" : AVERATH_ISLAND "-7,-3,1",
    ]) );
  SetSmell( ([
    "default" : "Dust and smoke linger in the air.",
    ])  );
  SetListen( ([
    "default" : "The crack of iron on steel can be heard.",
    ]) );
  SetInventory( ([
    G_NPC "weapon_dude" : 1,
    ]) );
}
