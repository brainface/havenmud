	
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetClimate("temperate");
     SetShort("the edge of a forest");
     SetDayLong("The forest is thin here, yet, the mix "
         "of oaks, birches, and mulberry trees "
         "gives the forest an eerie, "
         "unnerving, atmosphere. A giant spider web "
         "stretches between two of the tallest birch "
         "trees. The bottom of the web is nestled "
         "in the dense undergrowth.  "
         "The web does not affect either the "
         "path running from west to east or "
         "the path running from north to south.");
     SetNightLong("The forest is thin here, yet "
         "slightly scary even for the fearless. The oaks "
         "seem like they are hunting. The birches look "
         "like ghosts wandering the forest and the "
         "mulberries look bloody. On clear nights, "
         "the moonlight shimmers off of a giant "
         "spider web stretched between two of the "
         "tallest birch trees, giving the web an "
         "ephemeral appearance. The bottom of the web "
         "disappears into the dark depths "
         "of the undergrowth. The paths running from "
         "north to south and east to west seem "
         "clear, but dark." );
     SetItems( ([
          ({"forest", "path"  }) : (:GetLong:),
          ({ "tree","trees"}) :
                 "This part of the forest has a mix of "
                 "oaks, birches and mulberries.",
         ({ "oak", "oaks"}):
                 "The oaks bend down as if they were "
                 "trying to trap something. ",
         ({"birch", "birches", "knot", "knots", "eye"
              "eyes"}) : 
               "The white birches appear ghostly at night "
               "and the dark knots on their trunks seem "
               "like thousands of staring eyes.",
         ({"web"}) : 
               "The web is as taller than a human and "
               "equally as broad. Its intricate design "
               "is one of the most beautiful natural "
               "wonders that can be found in a forest. ",
        ({"design"}) :
              "The design consists of a spiral with "
           "several spokes. It is incredibly beautiful. ",
    ({"mulberry tree", "mulberry", "mulberries"}) :
            "The bright red berries on the mulberry trees "
            "may seem like drops of blood to those "
            "with overactive imaginations. Otherwise "
            "they look inviting and perfectly ripe.",
     ({"undergrowth"}) : 
            "The undergrowth consists primarily of "
            "ferns, devil's clubs, and blueberry "
            "bushes. Patches of bare ground remain "
            "visible between the bushes.",
     ({ "bare ground","ground","dirt","earth" }) :
           "Rich brown earth provides fertilization for "
           "the myriad of plants living here.",
     ({ "fiddlehead ferns","fiddlehead fern",           
           "ferns","fern" }) :
           "Still curled into little balls at their tips, the "
           "fiddlehead ferns rise out of the ground about "
           "a third of a meter.",
      ({ "devil's clubs","devil's club","clubs","club" }) :
           "Light brown bark conceals the prickly spines "
           "of the devil's club.  At the top, large leaves "
           "with thorns along the veins flop in the "
           "breeze, with a sprig of brilliant red berries "
           "in the center.",
      ({ "blueberry bushes","bushes","bush","blueberry 
              bush" }) : 
            "The blueberry bushes sprout small circular "
            "leaves with a tinge of blue.  Berries grow at "
            "random points along the branches.",
                      ]) );
 SetItemAdjectives( ([
                    "tree" : ({"oak", "birch"}),
                    "web" : ({"intricate", "giant", "spider"}),
                     "design" : ({"intricate", "beautiful"}),
                                          ]) );
    SetSmell( ([
                "default" : "The musty, moldy smell of "
                     "decaying leaves hangs heavily in the "
                     "air. "
                       ]) );
    SetListen( ([
                "default" :  "An eerie silence settles over "
                  "the forest."
             ]) );
    SetInventory( ([
              FOREST_NPC + "reclusef" : 1,
              FOREST_NPC + "reclusem" : 2]) );
    SetExits( ([
            "south" : AVERATH_ISLAND + "6,-6,0",
            "north" : AVERATH_ISLAND + "6,-4,0",
            "east" : AVERATH_ISLAND + "7,-5,0",
            "west" : AVERATH_ISLAND + "5,-5,0"
                   ]) );
}
    
