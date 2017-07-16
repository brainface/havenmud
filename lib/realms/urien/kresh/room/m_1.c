// Main Path through the goblin village.
// Connects the village to the roads.
//  Urien 110113 - Added Day/Night Long
//  Climate, Town, Domain, Items, Adjectives
//  Kept overall description the same.
#include <domains.h>
#include <lib.h>
#include "../goblins.h"

#define ROAD_PATH  SOUTHERN_COAST_VIRTUAL "havenroad/-32,0"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Southern Coast");
  SetTown("Kresh");
  SetShort("a grassy plains leading to Kresh");
  SetExits( ([
      "east" : GOBLIN_ROOM + "e_1",
     "south" : GOBLIN_ROOM + "m_2",
  ]) );
  AddExit("north", ROAD_PATH);
  SetInventory( ([
      GOBLIN_NPC + "little" : 2,
  ]) );
  SetDayLong("This large and open grassy plains extend "
    "southward to a small tent village of nomads. An "
    "obvious pathway leads from the Imperial Road to the "
    "southern tent village. A durable tent rests to the east "
    "with heavy traffic markings leading to the entrance. "
    "Various campfire pits lay scattered along the plains "
    "breaching the dry grass surface littered with black "
    "soil. The well lit scenery looks overgrazed in some "
    "spots displaying short wooden posts.");
  SetNightLong("A large and open grassy plains extend "
    "southward to a dimly lit tent village of nomads. A "
    "heavily used pathway leads north toward the Imperial "
    "Road. An isolated tent sits to the east with "
    "light creeping slightly from the entrance. Abandoned "
    "campfire pits sit scattered along the dry and patchy "
    "grass scenery. The darkness softly contrasts a "
    "soft violet hue over the plains itself.");
  SetItems( ([
    ({ "plains","scenery" }): (: GetLong :),
    ({ "kresh", "Kresh" }): "The tent village of Kresh can "
       "be seen further down the plains to the south.",
    ({ "ground", "floor" }) : "The flat grassy plains is "
       "considerably vegetated with dry grass and "
       "sporadic bare spots. Scattered along the surface "
       "of the ground, some wooden posts and campfire pits "
       "can be seen.",
    "smoke": "It is not visible to the natural eye.",   
    "grunting": "The grunting only assaults the ear senses.",
    "pits": "The campfire pits are in all varieties from new to "
       "obviously old. None of them are active and all seem "
       "to have served some purpose. They seem to be used "
       "until the pit itself is no longer functional or "
       "forgotten about.",
    "tent": "An isolated tent sits apart from the main "
       "village to the east. It is noticeable that the "
       "tent has seen much traffic from the Imperial Road "
       "and the village to the south. ",
    "tents": "Numerous tents sit assembled together on "
       "the plains to the south. They are of Goblin make "
       "and standard.",
    "village": "The tent village of Kresh can be seen to the "
       "distant south. It is the most recent home to the "
       "nomadic Goblin Horde.",
    "spots": "Some bare spots can be seen along the surface "
       "of these plains. In the center of every empty patch "
       "a skinny wooden post can be seen poking out of the "
       "soil.",
    "posts": "In the direct center of every overgrazed "
       "bare spot a wooden post can be seen. Most likely "
       "a way the inhabitants secure horses during feeding.",
    "post": "It is roughly half the size of a normal human "
       "and split from wood. It seems deeply buried in the "
       "ground to secure something in place.",
    "markings": "A considerable amount of traffic markings "
       "can be seen leading to the durable tent to the east "
       "and leading from the village of Kresh to the Imperial "
       "Road.",
    "entrance": "An entrance on the eastern tent can be "
       "distinguished offering a welcoming invitation.",
    "grass": "The dry grass blankets the ground in this "
       "grassy plains. Some bare spots can be seen along "
       "the surface. It grows rather wild and seems "
       "nutritious enough for a horse diet.",
    "soil": "The dark brown soil of the grassy plains looks "
       "ample for grass to grow but not much else due to "
       "traffic. Repeated travel keeps the local fauna from "
       "progressing. Large bare spots of soil are exposed "
       "along the blanketed plains with single wooden posts "
       "in the direct center of them.",
    "footprints": "There are several footprints along the "
       "obvious pathway. A majority seem to be Goblin "
       "with trickles of horse markings aside them. They lead "
       "in various directions.",
    "pathway": "One main pathway divides the plains from the "
       "Imperial Road to the village of Kresh to the south. A "
       "more frequent travelled route than the tent to the "
       "east. It is merely packed soil and void of life. ",
    "dung": "Few horse dung piles litter the ground in "
       "the plains. More frequent mashed dung sits blended "
       "secretly in the pathway.",
   ]) );
   SetItemAdjectives( ([
    "plains": ({ "grassy" }),
    "tent": ({ "single","isolated","durable" }),
    "pit": ({ "campfire","camp","fire","abandoned" }),
    "pits": ({ "campfire","camp","fire","abandoned" }),
    "footprints": ({ "goblin","horse" }),
    "village": ({ "tent" }),
    "spots": ({ "bare","overgrazed" }),
    "posts": ({ "wooden","center" }),
    "post": ({ "wooden","center","short" }),
    "markings": ({ "footprint","traffic" }),
    "tents": ({ "several","numerous","kresh","Kresh" }),
    "grass": ({ "dried","dry" }),
    "soil": ({ "dark","brown","packed" }),
    "pathway": ({ "pathway","obvious" }),
    "dung": ({ "mashed","horse","piles" }),
  ]) );
  SetListen( ([
    "default": "Random grunting carries on the rare burst "
               "of wind.",
    "grunting": "Slight grunting can be heard from the tent "
                "village of Kresh from the south.",
  ]) );
  SetSmell( ([
    "default" : "The southern tent village wafts of smoke "
                "mixed with horse dung.",
    "smoke": "Something burning can be smelt emanating "
             "from the village of Kresh.",
    "dung": "The soft scent of horse manure fills the "
            "nostrils. The scent gets stronger toward "
            "the southern tent village.",
  ]) );
}