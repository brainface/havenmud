#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the city barracks");
  SetLong(
    "The barracks is a large, stone building built of smooth surfaces. "
    "The hallway leads both to the north and to the east from here, and "
    "large wrought iron doors head out back onto the Blood River road. "
    "Arrayed on the wall are various banners seized in the wars that "
    "Grymxoria has fought, some from the days of nosferatu ownership, and "
    "some from the more recent human settlement."
    );
  SetItems( ([
    ({ "surface", "surfaces" }) : "The surfaces of the barracks are all "
        "smooth black stone.",
    ({ "stone", }) : "The stone is smoothly cut, black, and polished.",
    ({ "banner", "banners" }) : "These banners show the glory of the "
       "city of Grymxoria.",
    ({ "door", "doors" }) : "The doors are made of a heavy wrought iron "
       "and could probably resist a siege for some time.",
    ]) );
  SetItemAdjectives( ([
    "surface" : ({ "smooth", "black", "stone" }),
    "stone"   : ({ "smooth", "black", }),
    "door"    : ({ "wrought", "iron", "large", }),
    ]) );
  SetExits( ([
    "north" : G_ROOM + "barracks2",
    "out"   : G_ROOM + "road2",
    "east"  : G_ROOM + "barracks3",
    ]) );
  SetSmell( ([
    "default" : "The smells of stale human sweat eminate from the north.",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(20);
  SetProperty("no bump",1);
  SetInventory(  ([
    G_NPC "crier" : 1,
  	])  );
}
