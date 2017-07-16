//Selket@Haven
//2006
#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {

  room::create();
  SetDomain("Crystal Reaches");
  SetShort("the roads of Ungkh");
  SetDayLong(
    "The road of Ungkh is littered with debris "
    "and various body parts.  The entire highway "
    "seems to have been trampled rather than being "
    "built in the normal way.  Light from the sun "
    "glistens off many small metal fragments "
    "imbedded in the dirt from all the marching "
    "the path has taken over the years."
    );
  SetNightLong(
    "The road of Ungkh is littered with debris "
    "and various body parts.  The entire highway "
    "seems to have been trampled rather than being "
    "built in the normal way.  Light from the moon "
    "glistens off many small metal fragments "
    "imbedded in the dirt from all the marching "
    "the path has taken over the years."
    );
  SetSmell( ([
    "default" : 
    "The entire village smells of offal. ",
    ]) );
  SetListen( ([
    "default" :
    "Grunt sounds can be heard all around.",
    ]) );
  SetItems( ([
    ({ "road", "highway", "area", "path" }) :
       (: GetLong :),
    ({ "debris", "body", "parts", "trash", "pit", 
    "feces", "limbs" }) :
       "The entire path into Ungkh has become a cesspit "
       "where the streets are clotted with debris, feces "
       "and even severed limbs.",
    ({ "village", "huts", "ungkh", "city" }) :
       "The city here seems to have been a small "
       "village of huts before it started to thrive.  Ogres, "
       "Orcs, Half-Orcs, Goblins, Gnolls and Lizardmen can all "
       "be seen going about their lives.",
    ({ "light", "heavens", "moon", "sun" }) :
       "The light falls from the heavens, caressing everything "
       "with a touch that seems entirely wasted here.",
    ({ "splinters", "fragments", "dirt" }) :
       "Splinters from metal weapons seem to have broken off "
       "and have been trampled into the dirt over the years.  ",
    ]) );
  SetItemAdjectives( ([
    "limbs"     : ({ "severed" }),
    "village"   : ({ "small" }),
    "body"      : ({ "parts", "various" }),
    "fragments" : ({ "many", "small", "metal" }),
    ]) );
  SetExits( ([
    "south" : U_ROOM + "road03",
    "east" : U_ROOM + "road05",
    ]) );
  SetInventory( ([
    U_NPC "hacktroll" : 3,
    U_NPC "meleetroll" : 3,
  ]) );
  }
