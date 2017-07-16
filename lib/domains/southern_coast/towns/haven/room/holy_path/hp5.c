//
// Filename: hp5.c
// Part of the Holy Path
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("the Holy Path");
   SetExits( ([ 
      "north" : H_ROOM + "holy_path/hp4",
      "south" : H_ROOM + "holy_path/hp6",
   ]) );
   SetDayLong("Traffic along this stretch of road is steady, with people "
              "moving in and out of the town hall to the west regularly. "
              "Off to the north the road leads to the Church of Kylin, "
              "while just to the south the road meets up with Merchants' "
              "Way, the prime economic heart of Haven Town.");
   SetNightLong("To the west, Haven Town Hall lies.  The road is dark and "
                "shadowy at this time of night, but oddly safe.  Far to  "
                "the north, the spires of the Church block the moons.  Off "
                "to the south the road joins up with Merchants' Way.");
   SetItems( ([ 
      ({ "hall" }) : 
         "The Town Hall is a large building with the flag of Haven Town "
         "draped onto it. The large oaken doors are set within a columned "
         "entranceway, giving the bearer a sight that was meant to awe.",
      ({ "flag" }) :
         "The flag of Haven is a dragon wrapped around a set of scales, "
         "showing the balance of justice and order with the will to keep "
         "it that way.",
      ({ "column", "columns"}) : 
         "The columns are large, marble structures.",
      ({ "marble", "slab" }) : 
         "The marble seems to have been cut from a single large slab.",
      ({ "traffic" }) :
         "In the part of the city the traffic holds a slow, steady pace.",
      ({ "people" }) :
         "People are moving in and out of the town hall to the west on "
         "a regular basis.",
      ({ "church", "spire", "spires" }) :
         "Off to the north lies the Church of Kylin.",
      ({ "heart" }) :
         "Located to the west is Merchants' Way, the prime economic "
         "heart of Haven Town.",
      ({ "door", "doors" }) :
         "The doors to the town hall are made of a thick oak.",
      ({ "entranceway" }) :
         "This entranceway to the town hall is set within mighty "
         "columns.",
      ({ "dragon" }) :
         "This dragon wrapped arond a set of scales signifies the "
         "balance of justice and order.",
      ({ "scale", "scales" }) :
         "These scales represent the balance of justice and order.",
   ]) );
   SetItemAdjectives( ([
      "hall" : ({ "town" }),
      "flag" : ({ "haven" }),
      "column" : ({ "marble", "large", "mighty" }),
      "slab" : ({ "single", "large" }),
      "church" : ({ "kylin" }),
      "heart" : ({ "economic" }),
      "door" : ({ "oaken", "oak", "large" }),
   ]) );
   SetEnters( ([ 
      "hall" : H_ROOM + "town_hall/town_hall",
   ]) );
 }


/* Approved by Duuktsaryth on Sun Apr 25 18:58:36 1999. */
