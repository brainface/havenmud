//
// Filename: ir2.c
// Part of the Imperial Road
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("intersection of Holy Path and Imperial Road");
   SetExits( ([ 
      "north" : "../holy_path/hp3",
      "south" : "../holy_path/hp4",
      "east" : H_ROOM + "imperial_road/ir3",
      "west" : H_ROOM + "imperial_road/ir1",
   ]) );
   SetInventory( ([
     H_OBJ + "fountain" : 1,
     H_NPC "dwarf" : 1,
     H_NPC "avatarfighter" : 1,
     H_NPC + "guard" : 1,
     H_NPC + "kid" : 1,
     H_NPC + "citizen" : 1,
   ]) );
   SetDayLong("This is the busiest intersection in Haven Town.  People "
              "move about going from the central districts to the church "
              "in rapid fashions.  Off to the north, Holy Path continues "
              "off to the Church of Kylin, the religion of the elvish "
              "people that inhabit the town.  Off to the east, the road "
              "leads into the center of town, which holds many of the town's "
              "businesses and town offices.  To the south the road travels "
              "to the sea's edge.  The Town Hall sits to the south.  Further "
              "west, the town gate looms like a giant soldier on guard.");
   SetNightLong("At night, this intersection is still busy.  To the north "
                "lies the Church of Kylin.  To the south lies the Town Hall "
                "and the sea.  To the west is the town gate leading out of "
                "Haven Town.  Off east is the central town district.");
   SetItems( ([
      ({ "intersection" }) :
         (: GetLong :),
      ({ "person", "people" }) :
         "Many people are wandering through this busy intersection of town.",
      ({ "district", "districts" }) :
         "The central district of town is located to the east of here.",
      ({ "church" }) :
         "Down the Holy Path to the north lies the Church of Kylin.",
      ({ "business", "businesses", "office", "offices" }) :
         "Further to the east is the central district of the city which "
         "contains the many offices and businesses of Haven Town.",
      ({ "sea" }) :
         "The Ruined Sea can be seen to the south.",
      ({ "hall" }) :
         "South of here lies the Town Hall, where people may become citizens "
         "of Haven Town.",
      ({ "gate", "soldier", "guard" }) :
         "West of here lies the town gate, looming like a giant soldier on "
         "guard.",
   ]) );
   SetItemAdjectives( ([
      "intersection" : ({ "main", "busy", "busiest" }),
      "district" : ({ "central" }),
      "church" : ({ "kylin" }),
      "business" : ({ "town" }),
      "sea" : ({ "ruined" }),
      "hall" : ({ "town" }),
      "gate" : ({ "town" }),
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 19:09:26 1999. */
