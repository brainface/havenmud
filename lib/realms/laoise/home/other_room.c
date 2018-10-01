/*  This is a basic workroom object that connects
 *  your workroom to Olympus, the home of the GodBoard.
 *  Please make sure to read that board at least once per
 *  day, as it is the prime means of communication.
 *  Created by Duuktsaryth@Haven
 */
#include <lib.h>
#include <std.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("Deep within the Spider's Lair");
  SetLong("A large spider web covers the west wall of this massive "
    "black wall, trailing down across part of the floor. The middle "
    "area of the web seems to bulge outward, forming some sort of "
    "cocoon. A deep green blanket is tossed casually across this area, "
    "suggesting its use as a couch.");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetItems( ([
    ({"blanket"}) : "A fuzzy green blanket in a dark color. It appears "
    "to be made of wool and looks as if it would be warm.\n",
  ]) );
  SetItemAdjectives( ([
    "blanket" : ({"fuzzy","green","dark","dark green","wool","warm"}),
  ]) );
  SetExits( ([
/*
     "north" : "/domains/heaven/room/olympus",
     "east"  : STD_ROOM + "basic",
    "cloud" : "/realms/laoise/cloud_city/room/cloud1",
    "dit" : "/realms/laoise/ditmar/room/townhall",
    "keep" : "/realms/laoise/goodkeep/room/entrance",
    "yam" : "/realms/laoise/heyam/room/entrance",
    "mal" : "/realms/laoise/maleen/room/path1",
  "lich" : "/realms/laoise/lich_island/room/1,0",
*/
      ]) );
  SetObviousExits("darkness");
  SetInventory( ([
    "/realms/laoise/stuff/npc/student" : 1,
  ]) );
  }
