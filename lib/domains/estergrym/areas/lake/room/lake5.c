// Coded by Zeratul 11-26-99
// Double Checked by Tassadar 11-27-99
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_FISHING;
string PathSearch();

static void create() {
  fishing::create();
    SetDomain("Estergrym");
  SetClimate("temperate");
  SetShort("on a lake shore");
  SetDayLong("The sun radiates off of the sparkling water of the lake. "
     "The trees stop at the water edge of the lake, with deadwood and other "
     "plantlife growing into the water from the treeline. The sun shines down"
     "bringing light and warmth do the area. "
     "A waterfall across the water sparkles with radiance as it sprays a "
     "mist that blankets the area."
     );
  SetNightLong("The moon lights shines off the water with gentle rippling "
     "at the waters edge. The trees look like giant mothers protecting their "
     "children as they loom over the surrounding area. Gentle winds provide a "
     "soothing feel to the area, bringing calm and happyness. "
     "The moonlight makes the waterfall glow with a soothing essence, as "
     "the rushing water sprays a mist that blankets the area. "
      );
  SetListen( ([
     "default" : "Crickets and other wildlife can be heard.",
     ]) );
  SetSmell( ([
     "default" : "The air smells cool and fresh.",
     ]) );
  SetItems( ([
     ({"water","lake"}) : "The water ripples slightly and brings a feeling of "
     "happyness and calm that fills the surrounding area.",
     ({"forest","trees"}) : "These big trees look like giant mothers "
     "protecting their children as they loom over the plantlife and "
     "provide shade to the surrounding area.",
     ({"waterfall","rushing waters"}) : "The water flows steadly as it comes "
     "crashing down, spraying a mist that blankets around the area.",
     ({"deadwood","dead wood"}) : "The wood that lies here rots away to "
     "nothing that provides shelter to a variety of insects and animals.",
     ]) );
  SetItemAdjectives( ([
     "trees" : ({"large","mother like","protective"}),
     "lake" : ({"gentle","calm","rippling"}),
     "deadwood" : ({"rotting","shelter"}),
     ]) );
  SetInventory( ([
     LAKE_NPC + "/deer" : 1,
     ]) );
  SetSearch( ([
     "default" : (: PathSearch :),
     ]) );
  SetExits( ([
     "south" : LAKE_ROOM + "/lake4",
     "north" : ESTERGRYM_AREAS "bog/room/bog2",
     ]) );
  SetSpeed(5);
  SetFish( ([
          LAKE_OBJ + "/fish_1" : 100,
     ]) );
  SetChance(45);
}

string PathSearch() {
  if (GetExit("east")) {
   return "This area has been search already, revealing an exit to the east.";
     }
  AddExit("east", LAKE_ROOM +"/path1");
  return "You found an exit leading to the east!";
  }
