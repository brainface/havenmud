//-- Torak@Haven --//
//--    Ungkh    --//
//--   7/17/99   --//
//-- modified to use Lala vendor, not Lala barkeep --//
//-- by Gabriel@haven 09/30/99                     --//

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
    "than having been made for a reason.  This area "
    "been clear cut to provide for an area of rest "
    "and healing."
    );
  SetSmell( ([
    "default" : 
    "The smell of dried blood clings in the air.",
    ]) );
  SetItems( ([
    ({ "road", "highway", "area", "path", "landscape" }) :
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
    ]) );
  SetItemAdjectives( ([
    "pile"      : ({ "various", "junk", "of" }),
    "limbs"     : ({ "severed" }),
    "village"   : ({ "small" }),
    "forest"    : ({ "large" }),
    "body"      : ({ "parts", "various" }),
    "fragments" : ({ "many", "small", "metal" }),
    ]) );
  SetEnters( ([
    ]) );
  SetInventory( ([
    U_NPC + "lala" : 1,
    U_NPC + "salvia_healer" : 1,
    ]) );
  SetProperty("no teleport", 1);
 SetProperty("no magic", 1);
  SetProperty("no attack", 1);
  SetExits( ([
    "east" : U_ROOM + "cemetery",
    "south" : U_ROOM + "bank",
    "west" : U_ROOM + "gob_food",
    ]) );
  }
