/*                                                                   */

#include <lib.h>

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("tropical");
  SetShort("near an ancient pyramid");
  SetLong("The plants and trees in this area try to cover the path "
          "to an ancient pyramid just east of here. The ground "
          "begins to take a strange black tone as it approaches "
          "the pyramid."
         );
  SetItems( ([ 
               ({"pyramid"}) : "A huge pyramid is just east of here.",
               ({"plants","trees","plant","tree"}) : "Exotic plants and "
                                                     "trees are "
                                                     "abundant in this "
                                                     "region.",
               ({"ground"}) : "The ground gets darker and darker."
           ]) );
  SetDomain("Baria");
  SetItemAdjectives( ([                       
                       "plants" : ({"exotic"}),
                       "pyramid" : ({"dark","huge"}),
                       "ground" : ({"dark","black"})
                   ]) );
  SetExits( ([
              "east" : "/domains/baria/virtual/jungle/-5,3",
              "west" : "/domains/baria/virtual/jungle/-7,3",
              "north" : "/domains/baria/virtual/jungle/-6,4",
              "south" : "/domains/baria/virtual/jungle/-6,2"
           ]) );
}

