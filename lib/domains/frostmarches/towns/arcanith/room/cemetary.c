/* an ancient cemetary - made by Sardonas */

#include <lib.h>
#include <std.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort("a foreboding cemetary");
  SetClimate("arctic");
  
  SetDayLight(-30);
  SetExits( ([
    "south"  : ROOM "/ruins3a",
  ]) );

    SetLong("Large tombstones rise out of the ground like bleached "
            "bones of some dead beast. The ground is soft and feels "
            "moist.  Shadows flit about the cemetary in a macabre dance. "
            "A mist covers the cemetary floor.");
 
  SetItems( ([
    ({ "cemetary" })  :
       (: GetLong :),
    ({ "large tombstone", "large tombstones", "burial markers",
       "burial marker", "tombstones", "tombstone", "markers", "marker" })  :
       "Many large tombstones fill the cemetery.  Many of them have carvings "
       "of wolves or demons that seem to leer at the world.  Dark green "
       "moss covers most of the markers.",
    ({ "dark, green moss", "dark green moss", "dark moss", "green moss",
       "moss" })  :
       "The moss that covers everything is the only living thing in the "
       "cemetary.",
     ({ "cold white mist", "cold, white mist", "mist", "ground", "cold mist",
       "white mist", "floor", "soft ground", "soft squishy ground", 
       "soft, squishy ground" })  :
       "The ground is covered in a cold, white mist.",
    ({ "shadows" })  :
       "The shadows seem to take on a life of their own.",
   ({ "small carvings of wolves", "small carving of wolves", 
      "carvings of wolves", "carving of wolves", "wolves", "wolf",
      }) :
      "Small carvings of wolves decorate the tombstones and cemetary.",
   ({ "small carvings of demons", "small carving of demons", "demons", "demon",
      "carving of demons", "carving of demon", "carvings of demon", 
      "carvings of demons" })  :
      "Carved demons seem to leap out of the tombstones.  They seem to mock "
      "the resting place of the dead.",
   ({ "bleached bones", "bleached bone", "bones", "bone", "dead beast",
      "beast", "large bones", "large bone" })  :
      "The tombstones are bleached white from the elements.  They look like "
      "large bones.  They almost look like the remains of a giant beast.",
  ]) );

  SetSmell( ([
    "default"   :  "Death and decay overpower this area with their stench.",
  ]) );

  SetListen( ([
    "default"   :  "Scraping and scuttling noises sound throughout the "
                   "cemetery.",
  ]) );

  SetInventory( ([
     STD_OBJ "reztotem" : 1,
     NPC "/gargoyle" : 1,
     NPC "/healer"   : 1,
      ]) );
}
