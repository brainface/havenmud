//Selket@Haven
//2006

#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;
int CheckPC();

static void create() {

  room::create();
  SetShort("near Ungkh");
  SetDayLong(
    "The road to Ungkh is littered with debris "
    "and strewn with body parts. The entire highway "
    "seems to have been trampled under heavy feet "
    "rather than being made in a more formal fashion. "
    "The sunlight glitters off the metal fragments poking "
   "out of the dirt and other refuse. The road leads into "
    "the town to the northeast and west in the other direction. "
    );
  SetNightLong(
    "The road to Ungkh is littered with debris "
   "and strewn with body parts. The entire highway "
    "seems to have been trampled under heavy feet "
   "rather than being built in a more formal fashion. "
    "Light from the moon above casts shadows on the "
    "road towards the city in the northeast."
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
    "The road into Ungkh has become a cesspit of "
    "trash the inhabitants are too lazy to take further "
    "than their doorsteps.",
    ({ "village", "huts", "ungkh", "city" }) :
       "The city to the northeast seems to have been a small "
       "village of huts before it started to thrive.  Ogres, "
       "Giants, Trolls, and even a small band of Half-Orcs all "
      "reside here, going about their pitiable lives.",
    ({ "light", "heavens" }) :
       "The light falls from the heavens, caressing everything "
      "it touches with a light that seems absolutely wasted here.",
    ({ "splinters", "fragments", "dirt" }) :
       "Splinters from metal weapons seem to have broken off "
       "and have been trampled into the dirt over the years.  ",
]) );
  SetItemAdjectives( ([
    "body"      : ({ "parts", "various" }),
    "fragments" : ({ "many", "small", "metal" }),
    ]) );
  SetExits( ([
    "northeast" : U_ROOM + "road02",
    ]) );
  AddExit("west", CRYSTAL_REACHES_VIRTUAL + 
    "glimmerdinroad/-2,17", (:CheckPC:) );
  }

int CheckPC() {
  if (this_player()->id("troll_wander")) return 0;
    else return 1;
}
