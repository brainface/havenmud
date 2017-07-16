//Addition to the Inn in Malveillant//
//by Alessandra 9/04                //

#include <lib.h>
#include <../mal.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetClimate("indoors");
  SetShort("a dim backroom");
  SetLong(
     "Tucked behind the main room of the inn, this backroom "
     "is a small comfortable place for patrons to relax with their "
     "drinks and take in some musical entertainment. A make-shift "
     "stage has been set up along the southern wall, comfortable "
     "chairs scattered around small tables placed before it. A good "
     "sized fireplace rests against the eastern wall. To the north "
     "is the Inn's main room."
     );
  SetSmell( ([
     "default" : "The scent of ale lingers heavily here."
     ]) );
  SetListen( ([
     "default" : "The murmur of patron's chatter fills the air."
     ]) );
  SetItems( ([
     ({"backroom", "place", "room"}) : (:GetLong:),
     ({"tables", "table"}) : "Small round tables are surrounded by "
       "comfortable looking chairs.",
     ({"chair", "chairs"}) : "Overly stuffed, these chairs look "
       "extremely comfortable. They surround the tables that scatter "
       "the backroom.",
     ({"wall", "walls"}) : "The smooth walls are made of obsidian.",
     ({"patrons", "patron"}) : "Content looking patrons relax in "
       "the chairs with their ale, some humming along with the songs "
       "of the bard.",
     ({"stage", "wood", "planks"}) : "Planks of a highly polished, "
       "dark wood have been hastily thrown together to make this "
       "stage for the local bard.",
     ({"fireplace"}) : "The stone fireplace is quite impressive.",
     ]) );
  SetItemAdjectives( ([
     "backroom" : ({"dim"}),
     "table" : ({"small", "round"}),
     "chair" : ({"stuffed", "comfortable", "overly", "extremely"}),
     "wall" : ({"smooth"}),
     "stage" : ({"wood", "make", "shift"}),
     "fireplace" : ({"stone", "impressive"}),
     ]) ); 
  SetInventory( ([
     MAL_NPC + "lucen" : 1,   
     MAL_NPC + "darany" : 1,  
     ]) );
  SetExits( ([
     "north" : MAL_ROOMS + "inn", 
     ]) );
}


