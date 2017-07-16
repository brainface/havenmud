#include <lib.h>

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("in a sweltering jungle");
   SetClimate("tropical");
   SetDomain("Baria");
   SetDayLong(
              "The jungle is filled with towering trees and exotic foliage, "
            "which block the sun almost completely. The ground is covered "
            "with vines and dry remains of plants. The greenness of the "
            "jungle stretches out in all directions. A hut is wedged between "
            "the trees."
   );
   SetNightLong(
               "The dark jungle is covered with shadows of trees and foliage "
              "that filter the faint moonlight. The ground would seem like  "
              "a dark void if it wasn't for the few rays of pale light. Only "
              "darkness can be seen around. A hut is wedged between "
              "the trees."
   );
   SetItems( ([
       ({ "tree", "trees" }) : "The trees are normal palm and other "
                               "tropical varieties.",
       ({ "vine", "vines" }) : "The vines are normal dead plants that "
                               "fell from the trees above.",
       ({ "hut" }) : "This hut is tightly wedged between a group of trees. ",
   ]) );  
  SetListen( ([ "default" : "There's an incessant sound of moving leaves." ]) );
  SetSmell( ([ "default" : "The smell of the trees and plants is refreshing." ]) );
  SetExits( ([ 
      "north" : "/domains/baria/virtual/jungle/-6,-5",
      "east" : "/domains/baria/virtual/jungle/-5,-6",
      "west" : "/domains/baria/virtual/jungle/-7,-6",
      "south" : "/domains/baria/virtual/jungle/-6,-7",
   ]) );   
  SetEnters( ([
    ({"hut"}) : "/domains/baria/areas/bariahut/room/common"
    ]) );
}
