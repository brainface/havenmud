/*
 * Practice Field
 *
 * Holds some moderately interesting npcs
 * Leads off to a cabin on one side, a clearing on the other
 * one npc is a newbie item giver 
*/

#include <lib.h>

#include "../fence.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arctic");
  SetDomain("Frostmarches");
  SetNightLight(15); // torches
  SetShort("a practice field on the side of the mountain");
  SetDayLong(
    "The trail ends here at an open field in front of a cabin. Benches "
    "sit at one end of the field and an old stump sits at the other. The "
    "field itself is a swath of bare earth compacted by the footwork of "
    "several fencers. Surrounding the field is a forest of scraggly "
    "trees. In the distance to the northeast, a snow covered peak towers "
    "over all."
  );
  SetNightLong(
    "The trail ends here at an open field in front of a lit cabin. "
    "Benches sit at one end of the field and an old stump sits at the "
    "other. The field itself is a swath of bare earth compacted by the "
    "footwork of several fencers. A handful of torches illuminate the "
    "field and nearby trees. In the distance to the northeast, a snow "
    "covered peak shines in the night."
  );
  SetItems( ([
    ({"field","swath","earth"}) :
      (: GetLong :),
    ({"ground","topsoil"}):
      "The field has been robbed of snow and topsoil by the constant "
      "dance of hooves.",
    ({"benches","bench","stones"}):
      "These benches are little more than large stones rolled into place. "
      "They would allow several observers to sit and watch the swordplay.",
    ({"cabin"}) :
      "The cabin was crafted from pine logs. The bark is fresh, and the " 
      "logs are still leaking sap. Snow covers the roof, and a window is "
      "open to the practice field. An iron door bars the way inside.",
    // duplicate of above line
    ({"bark", "sap"}) :
      "The cabin was crafted from pine logs. The bark is fresh, and the " 
      "logs are still leaking sap. Snow covers the roof, and a window is "
      "open to the practice field. An iron door bars the way inside.",
    ({"firewood"}):
      "The firewood is piled high and would provide fuel for quite some "
      "time.",
    /* iron door is an object */    
    ({"fog"}):
      "Between the surrounding trees and obscuring fog, it is difficult "
      "to see far from this site.",
    ({"forest", "trees", "pines", "underbrush","leaves"}):
      "Short, stunted pine trees surround the practice field. A few "
      "stumps lie among the healthy trees." ,
    ({"hatchet"}) :
      "The hatchet is old and well-used. It would be of little use to "
      "anyone but a lumberjack.",
    ({"observers", "observer"}):
      "No other observers are currently watching the field.",
    ({"peak","mountain","shimmer"}):
      "The peak of the mountain is vaguely visible through the "
      "surrounding fog. Oddly, it seems to be covered in a faint shimmer.",
    ({"snow","roof"}):
      "Snow covers the roof of the cabin and the leaves of the "
      "surrounding trees, but the movement of the fencers has cleared it " 
      "from the field.",
    ({"stump"}):
      "This large stump sits on the far side of the field. A hatchet is "
      "currently buried into it, and beside it is a large pile of " 
      "firewood.",
    ({"stumps"}):
      "A few stumps of larger trees can be seen from here, evidently " 
      "felled in the construction of the cabin.",
    ({"torches","light","tripod"}):
      "The torches are a simple affair on a wooden tripod. They provide "
      "some moderate light.",
    ({"trail","path"}):
      "The trail, little more than a path of cleared underbrush, leads "
      "west to the clearing and back to the main trail up the mountain.",
    ({"window","interior"}):
      "The window is cracked open, though little can be seen of the "
      "interior of the cabin from here.",
  ]) );
  SetItemAdjectives( ([   
    "benches" : ({"stone","large"}),
    "cabin" : ({"log","lit"}),
    "field" : ({"practice","open","bare"}),
    "forest" : ({
      "cleared","scraggly", "short","stunted","pine","surrounding",
      "healthy", "nearby"
    }),
    "fog" : ({"obscuring","surrounding"}),
    "logs" : ({"pine"}),
    "peak": ({"snow covered","faint"}),
    "stump" : ({"large","old"}),
    "torches" : ({"moderate","wooden"}),
  ]) );
  SetListen( ([
    "default" : "The banter of the fencers is the only sound.",
  ]) );
  SetSmell( ([
    "default" : "The field smells of sweat and disturbed earth.",
  ]) );
  SetInventory( ([
    FENCE_NPC "cowardly_student.c" : 1,
    FENCE_NPC "fencemaster.c" : 1,
    FENCE_NPC "brash_student.c" : 1,
  ]) );
  SetExits( ([
    "west" : FENCE_ROOM "clearing",
  ]) );
  SetEnters( ([
    ({"cabin"}) : FENCE_ROOM "cabin",
  ]) );
  SetDoor( "cabin", FENCE_OBJ "iron_door" ); 
}

