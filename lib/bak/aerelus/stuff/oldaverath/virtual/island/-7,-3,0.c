/* tunnel2.c */

#include <lib.h>
#include <domains.h>
#include "../glim.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(45);
  SetClimate("underground");
  SetShort("a narrow tunnel");
  SetLong("The tunnel is rather narrow and it extends in both "
    "the eastern and western directions from here. It cuts "
    "directly into the mountain and descends quickly as it "
    "approaches the dwarven halls of stone that lie deep within "
    "the mountains. The tunnel's crafting makes it clear that "
    "dwarves are unlike any other builders in Kailie. It seems they "
    "prefer to go deeper into the subterranean "
    "world as they expand instead of upwards and towards the "
    "the heavens. Upon the walls are carved tales of valor, strength "
    "and courage in battle against the enemies of the clans.");
  SetItems( ([
    ({"tunnel"}) :
     "The tunnel extends in both the eastern and western directions.",
    ({"walls", "wall", "tale", "tales"}) :
      "Carvings on the walls tell of long past victories in the name of "
      "the state.",
    ({"torch", "torches"}) :
      "Torches give the area a dim, flickering light.",
    ]) );
  SetItemAdjectives( ([
    "walls" : ({"carved", "stone"}),
    "tunnel" : ({"narrow", "descending", "declining"}),
    "torch" : ({"dim", "flickering"}),
    ]) );
  SetExits( ([
   "east" : AVERATH_ISLAND "-6,-3,0",
   "west" : AVERATH_ISLAND "-8,-3,0",
   ]) );
  SetSmell( ([
    "default" : "Smoke is fairly thick here.",
    ]) );
  SetListen( ([
    "default" : "The sounds of dwarven speech echo about.",
    ]) );
  SetInventory( ([
    G_NPC "coot" : 1,
    ]) );
}
