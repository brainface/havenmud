/* Arcanith Library first21
 * Entrance
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
  SetShort("the entrance to a ruined library");           
  SetLong(
    "Stone steps here lead down to a creaky old wooden floor. The twin "
    "doors once adorning the entranceway lie broken amidst shattered glass. "
    "Rent and ruined tapestries hang in tatters from the ceiling. Walking "
    "west seems to lead to an abandoned lobby, while walking to the north "
    "or south leads to other areas of the library."
  );                                                                                

  SetItems( ([
    ({"library"}) : 
      (: GetLong :),
    ({"steps"}) : 
      "Time has loosened the stones.",
    ({"floor"}) :
      "Broken glass spreads out across the floor like tiny caltrops.",
    ({"doors","glass"}) :
      "The steel frames of the door are warped as if from a massive "
      "explosion. The stained glass inset in the door is now broken and "
      "scattered around the remains.",
    ({"tapestries"}) :
      "These tattered rags may have welcomed visitors to the library long ago",
    ({"lobby"}) :
      "There is an abandoned lobby to the west.",
    ({"ceiling","light","gaps"}) :
      "Dim light shines through gaps in the ceiling.",
  ]) );                                                                        

  SetItemAdjectives( ([
   "steps" : ({"stone"}),
   "doors" : ({"twin","broken","shattered"}),
   "tapestries" : ({"tattered","rent","ruined"}),
   "lobby" : ({"abandoned"}),
   "ceiling" : ({"dim"}),
  ]) );

  SetListen( ([
    "default" : "Wind whistles across the open doorway.",
  ]) );

  SetSmell( ([
    "default" : "Dust is heavy in the air.",
  ]) );

  SetInventory( ([
ARC_LIBRARY_NPC "dust_mephit" : random(3)+1,
ARC_LIBRARY_NPC "wind_mephit" : random(3)+1,
  ]) );

  SetExits( ([
    "north" : "first20",
    "west" : "first11",
    "south" : "first22",
  ]) );

}
