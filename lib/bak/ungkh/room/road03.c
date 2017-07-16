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
  SetShort("the city of Ungkh");
  SetLong(
    "The road in Ungkh is littered with debris "
    "and various body parts.  The entire highway "
    "seems to have been trampled into being rather "
    "than having been made for a reason.  A large "
    "hut is to the east, in the center of Ungkh.  "
    "A three story building which seems to have "
    "just started construction resides to the west."
    "  A hut has been built here."
    );
  SetSmell( ([
    "default" : 
    "The smells of urine, feces and trash "
    "all combine and assault the nostrils.",
    ]) );
  SetListen( ([
    "default" :
    "Moans of pleasure echo out from the hut.",
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
    "The hut to the west is under construction.",
    ({ "building" }) :
       "The three story building to the east seems to be a place "
       "of good spirits and enthusiastic patrons.",
    ]) );
  SetItemAdjectives( ([
    "limbs"     : ({ "severed" }),
    "village"   : ({ "small" }),
    "forest"    : ({ "large" }),
    "body"      : ({ "parts", "various" }),
    "fragments" : ({ "many", "small", "metal" }),
    "hut"       : ({ "large" }),
    "building"  : ({ "three", "story" }),
    ]) );
  SetInventory( ([
    U_NPC + "female_cit_steal" : 1,
    U_NPC + "magrat_sage" : 1,
    U_NPC + "male_cit_steal" : 1,
    ]) );
  SetEnters( ([
    "hut" : U_ROOM + "whore01",
    ]) );
  SetExits( ([
    "north" : U_ROOM + "pawn01",
    "east"  : U_ROOM + "hall01",
    "south" : U_ROOM + "road02",
    ]) );
  }
