	
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetClimate("temperate");
     SetShort("the edge of a forest");
     SetDayLong("The forest is thin here, yet, the mix "
         "of oaks and birches gives the forest an eerie, "
         "unnerving, atmosphere. The paths lead off in "
         "in each of the cardinal directions. The path "
         "leading west seems to be more grassy, while "
         "the path south seems more stony.  The paths to "
         "the east and north seem to lead further into "
         "the forest. " );
     SetNightLong("The forest is thin here, yet "
         "slightly scary even for the fearless. The oaks "
         "seem like they are trying to trap hapless "
         "beings beneath them. The birches look like "
         "ghosts wandering the forest.  Paths lead off "
         "between the trees in each of the cardinal "
         "directions.  The paths to the north and east "
         "seem to travel deeper into darkness.  The "
         "path to the south seems to lead to a brighter, "
         "rockier area, while the path to the west "
         "seems even brighter and smoother.");
     SetItems( ([
          ({"forest", "path"  }) : (:GetLong:),
          ({ "tree","trees"}) :
                 "This part of the forest has a mix of "
                 "oaks and birches.",
         ({ "oak", "oaks"}):
                 "The oaks bend down as if they were "
                 "trying to trap hapless travelers. ",
         ({"birch", "birches", "knot", "knots", "eye"
              "eyes"}) : 
               "The white birches appear ghostly at night "
               "and the dark knots on their trunks seem "
               "like thousands of staring eyes.",
        ({ "being", "beings", "traveler", "travelers"}) :
              (: this_player()->GetLong() :)
                      ]) );
/*  SetItemAdjectives( ([
                    "tree" : ({"oak", "birch"}),
                    "
                     ]) );*/
    SetSmell( ([
                "default" : "A hint of salt air mixes with " 
                      "the musty, moldy smell of decaying "
                      "leaves. "
                       ]) );
    SetListen( ([
                "default" :  "An eerie silence settles over "
                  "the forest."
             ]) );
    /*SetInventory( ([
              AVERATH_NPC + "" : 1]) );*/
    SetExits( ([
            "south" : AVERATH_ISLAND + "6,-7,0",
            "north" : AVERATH_ISLAND + "6,-5,0",
            "east" : AVERATH_ISLAND + "7,-6,0",
            "west" : AVERATH_ISLAND + "5,-6,0"
                   ]) );
   SetInventory( ([
                    FOREST_NPC + "reclusem" : 3,
                    FOREST_NPC + "raven" : 1,
               ]) );
}
