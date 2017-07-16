//-- Torak@Haven --//
//--    Ungkh    --//
//--   5/19/99   --//

#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {

  room::create();
  SetDomain("Crystal Reaches");
  SetTown("Ungkh");
  SetShort("the pits of Ungkh");
  SetDayLong(
    "The road to Ungkh is littered with debris "
    "and various body parts.  The entire highway "
    "seems to have been trampled into being rather "
    "than having been made for a reason.  Light from "
    "the sun glistens off many small metal fragments "
    "imbedded in the dirt from all the marching "
    "the path has taken over the years.  A small "
    "clearing has been stomped down here, serving "
    "as a training ground for the warriors."
    );
  SetNightLong(
    "The road to Ungkh is littered with debris "
    "and various body parts.  The entire highway "
    "seems to have been trampled into being rather "
    "than having been made for a reason.  Light from "
    "the moon slithers through the trees to add a "
    "shadowy feel to the area.  A small "
    "clearing has been stomped down here, serving "
    "as a training ground for the warriors.  A large "
    "hut has been built here."
    );
  SetSmell( ([
    "default" : 
    "The smells of urine, feces and trash "
    "all combine and assault the nostrils.",
    ]) );
  SetListen( ([
    "default" :
    "Grunts of pain and agony resound from the clearing.",
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
    ({ "light", "heavens" }) :
       "The light falls from the heavens, caressing everything "
       "it graces with a touch.",
    ({ "splinters", "fragments", "dirt" }) :
       "Splinters from metal weapons seem to have broken off "
       "and have been trampled into the dirt over the years.  ",
    ({ "clearing" }) :
       "This large clearing seems to be an arena for "
       "combat training and advanced tactics.",
    ({ "hut" }) : 
       "A large hut serves as the barracks for the entire town.",
    ]) );
  SetItemAdjectives( ([
    "limbs"     : ({ "severed" }),
    "village"   : ({ "small" }),
    "forest"    : ({ "large" }),
    "body"      : ({ "parts", "various" }),
    "fragments" : ({ "many", "small", "metal" }),
    "clearing"  : ({ "small" }),
    "hut"       : ({ "large" }),
    ]) );
  SetInventory( ([
    U_NPC + "corlebus_barbarian" : 1,
    U_NPC + "gorkor_valkyr" : 1,
    U_NPC + "borkalog_ranger" : 1,
    ]) );
  SetEnters( ([
    "hut" : U_ROOM + "combat_hut",
    ]) );
  SetExits( ([
    "north" : U_ROOM + "road03",
    "southwest" : U_ROOM + "road01",
    "east" : U_ROOM + "armour01",
    ]) );
  }
