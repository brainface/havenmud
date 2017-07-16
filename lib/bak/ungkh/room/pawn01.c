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
    "than having been made for a reason.  Various "
    "piles of junk have been left scattered all "
    "about the area."
    );
  SetSmell( ([
    "default" : 
    "The smells of urine, feces and trash "
    "all combine and assault the nostrils.",
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
    ({ "hut" }) :
       "The hut to the east seems to be a center attraction "
       "to this primitive city.",
    ({ "pile", "piles", "junk" }) :
       "These piles of junk or what is left over from the pawn "
       "dealer of Ungkh who keeps up his shop here.",
    ({ "building" }) :
       "The three story building to the east seems to be a place "
       "of good spirits and enthusiastic patrons.",
    ]) );
  SetItemAdjectives( ([
    "pile"      : ({ "various", "junk", "of" }),
    "limbs"     : ({ "severed" }),
    "village"   : ({ "small" }),
    "forest"    : ({ "large" }),
    "body"      : ({ "parts", "various" }),
    "fragments" : ({ "many", "small", "metal" }),
    "hut"       : ({ "large" }),
    "building"  : ({ "three", "story" }),
    ]) );
  SetInventory( ([
    U_NPC + "cronag_merchant" : 1,
    U_NPC + "gobskork_vendor" : 1,
    ]) );
  SetExits( ([
    "south" : U_ROOM + "road03",
    "east" : U_ROOM + "gob_food",
    ]) );
  }
