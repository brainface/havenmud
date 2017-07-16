// Bug Report 1179, typo fix.
//  Urien 110213 - Added Day/Night Long
//  Climate, Town, Domain, Items, Adjectives
//  Kept overall description the same.

#include <domains.h>
#include <lib.h>
#include "../goblins.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Southern Coast");
  SetTown("Kresh");
  SetObviousExits("north, south, west");
  SetShort("along the main path");
  SetDayLong("A main path continues into the tent village "
     "to the south and leads north to the Imperial Road. "
     "Directly to the south a split in the path has been "
     "made which leads deeper into the separate parts of "
     "the village. A simple leather yurt near the alleyway "
     "to the west has a fairly spruced up look about it. "
     "Numerous, smaller cloth tents crudely made with wooden "
     "planks sit along the field with a less than inviting "
     "look to them.");
  SetNightLong("The night shade blankets the main path which "
     "stretches north reaching the Imperial Road. Directly "
     "to the south a split in the path has been made which "
     "reach deeper into the village. A single leather yurt "
     "has light creeping from the entrance suggesting "
     "its convenient availability at this hour. Smaller "
     "cloth tents sit in the field to the east, devoid "
     "of all light and less welcoming.");
  SetItems( ([
   ({ "plains" }): (: GetLong :),
   ({ "ground", "floor" }): "The ground is quite packed "
     "from travel in this intersection. A single leather "
     "yurt which looks quite settled has scraps of leather "
     "strewn about. The grass that borders the path appears "
     "trodden from much use.",
   ({ "yurt", "tent" }): "The leather yurt appears sturdy "
     "against the natural elements of the Southern "
     "Coast. It has wooden planks which support the external "
     "circular integrity. With the scraps of leather hide "
     "littered along the ground would suggest it is the "
     "local leather expert.",
   "alleyway": "An alleyway leads westward away from "
     "this yurt landmark. It promptly leads west, away "
     "from the dense tent village to the south and "
     "the main path.",
   "planks": "The wooden planks used to structure the yurt "
     "and tent structures appear sturdy. They border the "
     "exterior of the tents from the outside elements.",
   "tents": "Smaller cloth tents sit huddled off in the "
     "distance scattered near the path. A closer inspection "
     "shows habitable quality to them and they appear "
     "similar to glorified umbrellas. They would provide "
     "shade to a weary nomad, if not much else. They seem "
     "halfway complete in construction. The tents south "
     "near the split path are more functional and numerous.",
   "path": "The main path leads north to the Imperial Road "
     "and south toward the heart of the Goblin Horde. A "
     "little alleyway amidst all of the tents in these plains "
     "leads west away from the village. It is merely packed "
     "soil and void of life.",
   "split": "A split in the path can be seen to the "
     "south separating behind a denser collection of "
     "tents. It splits in different directions in "
     "the center of the Goblin home.",
   "village": "South of this leather yurt landmark, a "
     "more compact settlement of tents can be seen. It "
     "is the very core of the Goblin nomadic home.",
   "grass": "The aged dry grass borders the main pathway "
     "and stretches in all directions on the plains. To the "
     "south near the Goblin village, it gets less frequent. "
     "It looks previously dried from sun damage.",
   "scraps": "Irregular leather hide scraps litter the "
     "path outside the yurt. All of the them seem to "
     "have been trimmed previously for the leather "
     "dealer. They vary in size and texture, vice "
     "being all equally worthless.",
   "entrance": "An entrance on the leather yurt structure "
     "is simple in design and appears welcoming. A thin "
     "flap of leather hide blocks in most of the luminous "
     "light on the inside, simply to block out pests but "
     "not welcome patrons.",
    ]) );
  SetItemAdjectives( ([
   "yurt": ({ "sturdy","leather","simple","single" }),
   "tent": ({ "sturdy","leather","simple","single" }),
   "tents": ({ "smaller","cloth","numerous"}),
   "planks": ({ "wooden","sturdy","wood" }),
   "path": ({ "main","dirt" }),
   "village": ({ "tent","kresh" }),
   "scraps": ({ "leather","hide" }),
   "grass": ({ "aged","dry" }),
   "entrance": ({ "yurt","tent" }),
   "split": ({ "path" }),
   "": ({ "","" }),
  ]) ); 
  SetEnters( ([
    "yurt": STORE_DIR "leatherstore",
    "tent": STORE_DIR "leatherstore",
  ]) );
  SetExits( ([
    "west": GOBLIN_ROOM + "w_1",
    "north": GOBLIN_ROOM + "m_1",
    "south": GOBLIN_ROOM + "m_3",
  ]) );
  SetInventory( ([
      GOBLIN_NPC + "slash_medium" : 1,
  ]) );
}