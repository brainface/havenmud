//-- Torak@Haven --//

//--    Ungkh    --//
//--   5/27/99   --//

#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {

  room::create();
  SetDomain("Crystal Reaches");
  SetTown("Ungkh");
  SetShort("the city of Ungkh");
  SetLong(
    "The road in Ungkh is littered with debris "
    "and various body parts.  The entire highway "
    "seems to have been trampled into being rather "
    "than having been made for a reason.  A small "
    "forge is here, on the road."
    );
  SetSmell( ([
    "default" : 
    "The smells of urine, feces and trash "
    "all combine and assault the nostrils.",
    ]) );
  SetListen( ([
    "default" :
    "Hammer clanging on metal resounds from the hut.",
    ]) );
  SetItems( ([
    ({ "road", "highway", "area",
       "path", "landscape", "center",
        "forge" }) :
       (: GetLong :),
    ({ 
    "debris", "body", "parts", 
    "trash", "pit", "feces", "limbs" 
    }) :
       "The entire path into Ungkh has become the trash "
       "pit of the town itself, with debris, feces and even "
       "severed limbs cluttering the sides of the road.",
    ({ "village", "huts", "ungkh", "city" }) :
       "The city here seems to have been a small "
       "village of huts before it started to thrive.  Ogres, "
       "Orcs, Half-Orcs, Goblins, Gnolls and Lizardmen can all "
       "be seen going about their lives.",
    ({ "row", "rows", "crop", "crops" }) :
       "A row of crops, half eaten by bugs, serves as the source "
       "of food for the city of Ungkh.",
    ({ "hut" }) :
       "This hut serves as the armoury of Ungkh.",
    ]) );
  SetItemAdjectives( ([
    "pile"      : ({ "various", "junk", "of" }),
    "limbs"     : ({ "severed" }),
    "village"   : ({ "small" }),
    "forest"    : ({ "large" }),
    "body"      : ({ "parts", "various" }),
    "fragments" : ({ "many", "small", "metal" }),
    "hut"       : ({ "" }),
    "building"  : ({ "three", "story" }),
    ]) );
  SetEnters( ([
    "hut" : U_ROOM + "armour02",
    ]) );
  SetInventory( ([
    U_NPC + "smithy" : 1,
    U_NPC + "lizaria_armourer" : 1,
    ]) );
  SetExits( ([
    "east" : U_ROOM + "thief01",
    "south" : U_ROOM + "smith01",
    "west" : U_ROOM + "road02",
    "north" : U_ROOM + "hall01",
    ]) );
   SetProperties( ([
      "metal working" : 1,
      "natural working" : 1,
      "wood working" : 1,
      "leather working" : 1,
      "textile working" : 1,
      "mithril working" : 1,
   ]) );
  }
