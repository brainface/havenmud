//
// Filename: hp3.c
// Part of the Holy Path
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

string CheckTorch();

static void create() {
   room::create();
   SetShort("the Holy Path");
   SetDayLong("The road continues to travel from north to south here, "
              "making its way north to the Church of Kylin.  Off to "
              "the south is the Imperial Road, the main street of Haven "
              "Town.  The Holy Path is busy during the day, with citizens "
              "going about their business all around. The Eclat Temple is "
              "here, resplendant marble in gold and white trim.");
   SetNightLong("The road is brightly lit at night, with torches scattered "
                "about.  The road leads off to the north and south from  "
                "here, leading to the sea to the south and the church to the "
                "north.  Few people move about at night, but those that do " 
                "quickly and quietly move off to their destination. The Eclat "
                "Temple is here, resplendant in its white marble with gold trim.");
   SetItems( ([ 
      ({ "torch", "torches", "light" }) : 
         (: CheckTorch :),
      ({ "street" }) :
         "The main street of Haven Town, the Imperial Road, is located to "
         "the south.",
      ({ "road" }) :
         "From here, the road heads north to the Church of Kylin and south "
         "to the Imperial Road.",
      ({ "citizen", "citizens", "people" }) :
         "The citizens of Haven Town are making their way through the city, "
         "peacefully carrying out their business.",
      "temple" : "The Eclat Temple is a building of white marble with gold trim.",
   ]) );
   SetItemAdjectives( ([
      "street" : ({ "main" }),
      "torch" : ({ "simple" }),
   ]) );
   SetExits( ([ 
      "north" : H_ROOM + "holy_path/hp2",
      "south" : H_ROOM + "imperial_road/ir2",
   ]) );
   SetEnters( ([
     "temple" : H_ROOM "church/eclat_temple",
     ]) );
}

string CheckTorch() {
   if(query_night()) {
      return "These simple torches are lighting the path, providing a "
             "small amount of light for people to see with.";
   } else {
      return "During the day, the torches that light the road are "
             "extinguished.";
   }
}

/* Approved by Duuktsaryth on Sun Apr 25 18:57:36 1999. */
