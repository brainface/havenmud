// Coded by Zeratul 11-27-99
#include <lib.h>
#include "../lake.h"
inherit LIB_FISHING;

static void create() {
  fishing::create();
  SetDomain("Estergrym");
  SetClimate("temperate");
  SetShort("On a dock");
  SetDayLong("The sun beats on the lake in a relaxing way, as the water "
     "sparkles peacefully. Fish jump from the water and deadwood floats about "
     "the lake's surface. The waterfall across the water sparkles with "
     "radiance as it sprays a mist that blankets the area."
     );
  SetNightLong("The moon shines down on the lake in a relaxing way, as the "
     "water sparkles peacefully. Fish jump from the water and deadwood floats "
     "about the lake's surface. The waterfall across the water sparkles "
     "with radiance as it sprays a mist that blankets the area. "
     );
  SetListen( ([
     "default" : "Fish jumping and other wildlife can be heard.",
     ]) ); 
  SetSmell( ([
     "default" : "The air smells cool and fresh.",
     ]) );
  SetItems( ([
     ({"water","lake"}) : "The water ripples slightly and brings a "
     "feeling of happyness and calm that fills the surrounding area.",
     ({"waterfall","rushing waters"}) : "The water flows steadly as it comes "
     "crashing down, spraying a mist that blankets around the area.",
     ({"deadwood","dead wood"}) : "The wood that lies here rots away to "
     "nothing that provides shelter to a variety of insects and animals.",
     ]) );
  SetItemAdjectives( ([
     "lake" : ({"gentle","calm","rippling"}),
     "deadwood" : ({"rotting","shelter"}),
     "waterfall" : ({"flowing","cool","crashing","spraying"}),
     ]) );
  SetExits( ([
     "southeast" : LAKE_ROOM + "/lake3",
     ]) );
  SetInventory( ([ LAKE_NPC + "/fisher" : 1,
                 ]) );
  SetSpeed(5);
  SetFish( ([
          LAKE_OBJ + "/fish_1" : 100,
     ]) );
  SetChance(50);
}
