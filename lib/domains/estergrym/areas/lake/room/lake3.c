// Coded by Zeratul 11-26-99
#include <lib.h>
#include "../lake.h"
inherit LIB_FISHING;

static void create() {
  fishing::create();
  SetDomain("Estergrym");
  SetClimate("temperate");
  SetShort("on a lake shore");
  SetDayLong("The sun radiates off of the sparkling water of the lake. "
     "The trees stop at the water edge of the lake, with deadwood and other "
     "plantlife growing into the water from the treeline. The sun shines down "
     "bringing light and warmth to the area. "
     "A waterfall across the water sparkles with radiance as it sprays a "
     "mist that blankets the area. "
     "There is a dock here that is a prime spot for fishing."
     );
  SetNightLong("The moon light shines off of the water with a gentle rippling "
     "at the waters edge. The trees look like giant mothers protecting their "
     "children as they loom over the surrounding area. Gentle winds provide a "
     "soothing feel to the area, bringing calm and happyness. "
     "The moonlight makes the waterfall glow with a soothing essence, as "
     "the rushing water sprays a mist that blankets the area. "
     "There is a dock here that is a prime spot for fishing. "
     );
  SetListen( ([
     "default" : "Crickets and other wildlife can be heard.",
     ]) );
  SetSmell( ([
     "default" : "The air smells cool and fresh.",
     ]) );
  SetItems( ([
     ({"water", "lake"}) : "The water ripples slightly and brings a feeling of "
     "happyness and calm that fills the surrounding area.",
     ({"forest","trees"}) : "These big trees look like giant mothers protecting "
     "their children as they loom over the plantlife and provide shade to the "
     "surrounding area.",
     ({"waterfall","rushing waters"}) : "The water flows steadly as it comes "
     "crashing down, spraying a mist that blankets around the area.",
     ({"deadwood","dead wood"}) : "The wood that lies here rots away to nothing "
     "that provides shelter to a variety of insects and animals.",
     ({"dock"}) : "The dock extends out over the lake a little and makes "
     "this the perfect spot to do some fishing.",
     ]) );
  SetItemAdjectives( ([
    "trees" : ({"large","mother like","protective"}),
     "lake" : ({"gentle","calm","rippling"}),
     "deadwood" : ({"rotting","shelter"}),
     "waterfall" : ({"flowing","cool","crashing","spraying"}),
     ]) );
  SetExits( ([
     "west" : LAKE_ROOM + "/lake2",
     "northeast" : LAKE_ROOM + "/lake4",
     "southeast" : LAKE_ROOM + "/cabin_out",
     "northwest" : LAKE_ROOM + "/dock1",
     ]) );
  SetSpeed(5);
  SetFish( ([
          LAKE_OBJ + "fish_1" : 100,
     ]) );
  SetChance(45);
}
