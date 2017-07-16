//-- Torak@Haven --//
//--    Ungkh    --//
//--   5/20/99   --//

#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {

  room::create();
  SetDomain("Crystal Reaches");
  SetTown("Ungkh");
  SetShort("outside the brothel");
  SetLong(
    "The road in Ungkh is littered with debris "
    "and various body parts.  The entire highway "
    "seems to have been trampled into being rather "
    "than having been made for a reason.  The "
    "largest building, and only actual building, in "
    "Ungkh has been built here, serving as the "
    "watering hole for all the citizens of Ungkh."
    );
  SetSmell( ([
    "default" : 
    "An assaulting odor of drunken breath and "
    "spilled grog infest the nostrils.",
    ]) );
  SetListen( ([
    "default" :
    "Fights and drunken laughter abound from the "
    "brothel.",
    ]) );
  SetItems( ([
    ({ "road", "highway", "area", "path" }) :
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
    ({ "building", "brothel" }) :
       "The three story building here seems to be a place "
       "of good spirits and enthusiastic patrons.",
    ]) );
  SetItemAdjectives( ([
    "limbs"     : ({ "severed" }),
    "village"   : ({ "small" }),
    "forest"    : ({ "large" }),
    "body"      : ({ "parts", "various" }),
    "fragments" : ({ "many", "small", "metal" }),
    "building"  : ({ "three", "story", "large", 
                     "only", "largest" }),
    ]) );
  SetInventory( ([
    ]) );
  SetEnters( ([
    "building" : U_ROOM + "brothel02",
    ]) );
  SetExits( ([
    "east"  : U_ROOM + "road03",
    ]) );
  }
