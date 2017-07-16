//
// The Center Wing of the Library
// Filename: training_hall.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("the central training wing of the Library");
   SetClimate("indoors");
   SetAmbientLight(45);
   SetExits( ([
      "east" : "masters_hall",
      "west" : "entrance",
      "north" : "north_library",
      "south" : "south_library",
   ]) );
   SetLong("This is the central crossroads in the Haven Library. From here, "
           "young mages can travel north or south in an effort to choose "
           "the path that most closely resembles his or her desires for "
           "magical studies. Enchanters and Evokers are instructed "
           "to go south for training or north for a little relaxation."
           " To the east lies a large hall of study for use "
           "only by the most powerful of mages.");
   SetNewsgroups( ({ "magic.ideas", "magic.announcements", "magic.general" }) );
   SetItems( ([
      ({ "crossroad", "crossroads" }) :
         (: GetLong :),
      ({ "mage", "mages" }) :
         "From here, young mages can travel north or south to their "
         "respective training halls.",
      ({ "necromancer", "necromancers", "diviner", "diviners" }) :
         "From here, necromancers and diviners should go north.",
      ({ "enchanter", "enchanters", "evoker", "evokers" }) :
         "From here, enchanters and evokers should go south.",
      ({ "hall" }) :
         "To the east lies a large hall that is to only be used by the "
         "most powerful of mages.",
   ]) );
   SetItemAdjectives( ([
      "mage" : ({ "young" }),
      "hall" : ({ "large", "study" }),
   ]) );
   SetSmell( ([
      "default" : "An odd smell of death mixes with the smells of life here.",
   ]) );
   SetListen( ([
      "default" : "An occasional scream sounds from the east.",
   ]) );
   SetInventory( ([
/*
      H_NPC + "elian" : 1,
*/
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 19:49:35 1999. */

