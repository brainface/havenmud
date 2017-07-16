/* Arcanith Library first22
 *
 *
 */
#include <lib.h>                   

// mikes includes dir
#include "../arc_library.h" 

// must be in all rooms
inherit LIB_ROOM;      

static void create() {
  // get it started   
  ::create();     

  SetClimate("indoors");
  SetAmbientLight(30); // I hope this is dark?
  SetShort("a section of a ruined library");           
  SetLong(
    "Three long bookcasses remain standing, but empty of all but dust and "
    "cobwebs. Dessicated books lie scattered in haphazard piles on the "
    "floor. A faded mural on the outer wall shows a group of children "
    "intently as an elderly woman reads from a colorful tome. Walking north "
    "would lead back to the entrance."
  );                                                                                

  SetItems( ([
    ({"floor"}) :
      "Dessicated books lie scattered in haphazard piles on the floor.",
    ({"mural"}) :
      "The mural has faded and flaked with time.",
    ({"books","piles"}):
      "The books lie in scattered piles on the floor, as if someone "
      "hurriedly rifled through them.",
    ({"bookcases","bookcase"}):
      "Faded pastel paint has peeled off leaving large sections of pale "
      "wood, and the shelves are home only to spiders now.",
    ({"ceiling"}):
      "Faint light shines though holes in the ceiling above.",       
  ]) );                                                                        

  SetItemAdjectives( ([
   "mural" : ({"faded"}),
   "books" : ({"scattered","dessicated","haphazard"}),
   "bookcases" : ({"long"}),
  ]) );

  SetListen( ([
    "default" : "The ceiling groans dangerously.",
  ]) );

  SetSmell( ([
    "default" : "Dust is heavy in the air.",
  ]) );

  SetInventory( ([
    ARC_LIBRARY_NPC "dust_mephit" : random(3)+1,
    ARC_LIBRARY_NPC "wind_mephit" : random(2),
  ]) );

  SetExits( ([
    "north" : "first21.c",
  ]) );

}
