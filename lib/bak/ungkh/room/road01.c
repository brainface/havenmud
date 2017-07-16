//-- Torak@Haven --//
//--    Ungkh    --//
//--   5/19/99   --//

#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;
int CheckPC();

static void create() {

  room::create();
  SetDomain("Crystal Reaches");
  SetTown("Ungkh");
  SetShort("near Ungkh");
  SetDayLong(
    "The road to Ungkh is littered with debris "
    "and various body parts.  The entire highway "
    "seems to have been trampled into being rather "
    "than having been made for a reason.  Light from "
    "the sun glistens off many small metal fragments "
    "imbedded in the dirt from all the marching "
    "the path has taken over the years.  More fresh "
    "tree stumps in the woods surround the road as the "
    "the city to the northeast keeps growing."
    );
  SetNightLong(
    "The road to Ungkh is littered with debris "
    "and various body parts.  The entire highway "
    "seems to have been trampled into being rather "
    "than having been made for a reason.  Light from "
    "the moon slithers through the trees to add a "
    "shadowy feel to the area.  More fresh "
    "tree stumps in the woods surround the road as the "
    "the city to the northeast keeps growing."
    );
  SetSmell( ([
    "default" : 
    "The smells of urine, feces and trash "
    "all combine and assault the nostrils.",
    ]) );
  SetListen( ([
    "default" :
    "Loud sounds of the city resound from the northeast.",
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
       "The city to the northeast seems to have been a small "
       "village of huts before it started to thrive.  Ogres, "
       "Orcs, Half-Orcs, Goblins, Gnolls and Lizardmen can all "
       "be seen going about their lives.",
    ({ "light", "heavens" }) :
       "The light falls from the heavens, caressing everything "
       "it graces with a touch.",
    ({ "splinters", "fragments", "dirt" }) :
       "Splinters from metal weapons seem to have broken off "
       "and have been trampled into the dirt over the years.  ",
    ({ "tree", "trees", "stump", "stumps", "woods", "forest" }) :
       "A large forest surounds this road and many of the trees "
       "have been cut to the stump for lumber supplies to support "
       "the city of Ungkh to the northeast.",
    ]) );
  SetItemAdjectives( ([
    "limbs"     : ({ "severed" }),
    "village"   : ({ "small" }),
    "forest"    : ({ "large" }),
    "body"      : ({ "parts", "various" }),
    "fragments" : ({ "many", "small", "metal" }),
    "stump"     : ({ "fresh", "tree" }),
    ]) );
  SetInventory( ([
    ]) );
  SetExits( ([
    "northeast" : U_ROOM + "road02",
    ]) );
  AddExit("west", CRYSTAL_REACHES_VIRTUAL + 
    "glimmerdinroad/-2,17", (:CheckPC:) );
  }

int CheckPC() {
  if (this_player()->id("ungkher")) return 0;
    else return 1;
}
