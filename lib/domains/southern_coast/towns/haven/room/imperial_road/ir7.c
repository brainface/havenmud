//
// Filename: ir7.c
// Part of the Imperial Road
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("corner of Imperial Road and Galleon's Passage");
   SetExits( ([ 
      "north" : H_ROOM + "galleons_passage/gp3",
      "south" : H_ROOM + "galleons_passage/gp2",
      "east"  : H_ROOM + "imperial_road/ir8",
      "west"  : H_ROOM + "imperial_road/ir6",
   ]) );
   SetLong("The road comes to a four-way intersection here, leading "
           "off to the Haven Library to the east, the wharf to the "
           "south, the Haven Guard barracks to the north, and the "
           "city center to the west.");
   SetItems( ([
      ({ "road", "intersection" }) :
         (: GetLong :),
      ({ "library" }) :
         "The Haven Library, home of Haven's magic, can be found to "
         "the east.",
      ({ "wharf" }) :
         "The commercial area known as the wharf is located to "
         "the south of here.",
      ({ "barracks" }) :
         "The Haven Guard barracks is located to the north of here.",
      ({ "center" }) :
         "To the west lies the city center.",
   ]) );
   SetItemAdjectives( ([
      "intersection" : ({ "four-way", "four way" }),
      "library" : ({ "haven" }),
      "wharf" : ({ "commercial" }),
      "barracks" : ({ "haven", "guard" }),
      "center" : ({ "city" }),
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 19:19:01 1999. */
