#include <lib.h>
#include "../ranger_hall.h"
inherit LIB_ROOM;
int PreExit(string dir);

static void create() {
  room::create();
  SetShort("a small path");
  SetDomain("Valley");
  SetDayLong("A small path leads from the main road to the west. From "
             "here a small crevice in the ground can be seen, hidden "
             "slightly by some underbrush and a tall tree standing to "
             "the side. The forest has a very powerful feeling here..."
             "like the woods are manifesting their power into the "
             "surroundings.");
  SetNightLong("The forest looms like an imposing giant obscuring the "
               "moon. To the west, branches grow thinner. A small "
               "crevice carved into rock resides under a large, lifelike "
               "tree. The forest has a very powerful feeling here..."
               "like the woods are manifesting their power into the "
               "surroundings.");
  SetClimate("temperate");
  SetProperty("no bump",1);
  SetExits( ([
      "west" : "/domains/valley/areas/jidoor_forest/room/path07", 
  ]) );
 
  SetItems( ([  
      ({"path","road"}) : "This small path leading away from the main "
                          "road is surrounded by lush greenery.",
      ({"greenery"}) : "The greenery all around includes plants and "
                       "trees of all varieties.",
      ({"crevice","ground"}) : "This small crevice in the ground is "
                               "hidden well by the underbrush and the "
                               "tall tree seeming to stand almost at "
                             "guard.",
      ({"underbrush"}) : "This underbrush is growing almost "
                         "intentially here slightly hiding a crevice.",
      ({"tree"}) : "The tree has almost a life-like quality. Paired "
                   "with its age, it looks almost sentient.",
      ({"forest","woods","surrounding"}) : "The surrounding forest gives "
                                           "off an unmistakable feeling "
                                           "of power.",
      ({"moon"}) : "The moon is fairly hidden by the surrounding forest.",
      ({"rock"}) : "A strange crevice is carved into the rock here.", 
      ({"branches"}) : "To the west these branches grow thinner as they "
                       "near the main road.",  ]) );
  SetItemAdjectives( ([ 
      "path" : ({"small"}),
      "crevice" : ({"strange", "small"}),
      "forest" : ({"surrounding"}),
      "tree" : ({"life-like", "tall", "large"}),
  ]) );
  AddEnter("crevice", RH_ROOM + "ranger_guildhall", (: PreExit :) );
       }

int PreExit(string dir) {
   if ( (this_player()->GetGuild() == "ranger") ||
      (creatorp(this_player() ) ) ) {
         return 1;
     } else {
         message("my_action",
                   "The large tree uses its branches to push you "
                   "away.",
                   this_player() );
         message("other_action",
                   this_player()->GetCapName() + " is blocked by the "
                                                 "large tree when "
                                                 "trying to enter a "
                                                 "crevace.",
                    this_object(), this_player() );
         return 0;
        }
 }