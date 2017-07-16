//
// Filename: ir1.c
// Part of the Imperial Road
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../haven.h"

#define GROVE SOUTHERN_COAST_AREAS "mage_tower/grove/entrance"

inherit LIB_ROOM;

int PreEnter();

static void create() {
   room::create();
   SetShort("Imperial Road");
   SetExits( ([
      "east" : "../imperial_road/ir2",
      "west" : H_ROOM "gate",
   ]) );
   SetListen( ([ 
      "default" : "The sounds of city life surround you.",
   ]) );
   SetSmell( ([ 
      "default" : "The smells of a city abound.",
   ]) );
   SetDayLong("Haven Town spreads out to the east. Passersby seem to "
              "shuffle quickly through this part of town, keeping cautious "
              "eye on the evil-looking grove of trees to the north. Off "
              "to the east though, the city seems to hustle and bustle "
              "a nice and welcoming feeling. Further east along the "
              "Imperial Road lies the Great Library and other major "
              "landmarks of the most powerful city of Kailie.");
   SetNightLong("Haven Town by night is a quiet and peaceful city, "
                "with peace and order maintained by both the Haven Town "
                "Guard and the Templars of Kylin. To the north lies a "
                "dark and shadowy grove of trees, while to the east "
                "the city stretches out into the distance.");
   SetItems( ([
      ({ "grove", "trees", "tree" }) : 
         "The evil-looking grove seems hostile and uninviting.",
      ({ "passer", "passers", "passerby", "passersby" }) :
         "The passersby shuffle quickly through this part of town.",
      ({ "city", "town" }) :
         "The city of Haven spreads out to the east of here.",
      ({ "library" }) :
         "Far off to the east lies the Great Library.",
      ({ "landmark", "landmarks" }) :
         "The many landmarks of Haven Town lie inside the city to "
         "the east.",
      ({ "templar", "templars", "guard" }) :
         "The Templars of Kylin as well as the Haven Town Guard are "
         "responsible for the peace and order of Haven Town.",
      ({ "distance" }) :
         "In the distance to the east, Haven Town can be seen.",
   ]) );
   SetItemAdjectives( ([
      "grove" : ({ "evil-looking", "evil", "hostile", "uninviting",
                   "dark", "shadowy" }),
      "city" : ({ "haven", "welcoming" }),
      "library" : ({ "haven", "great" }),
      "landmark" : ({ "many", "major" }),
      "templar" : ({ "haven", "kylin" }),
   ]) );
   AddEnter("grove", GROVE, (: PreEnter :));
   SetInventory( ([
    ]) );
}

int PreEnter() {
    int lvl = this_player()->GetLevel();
    if (!userp(this_player())) return 0;    
    if (lvl >= 25) return 1;
    
    this_player()->eventPrint("You do not think it is wise to enter"
                           " the grove");                       
    return 0;
    }


