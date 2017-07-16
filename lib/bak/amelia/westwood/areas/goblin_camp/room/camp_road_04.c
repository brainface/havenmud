#include <lib.h>
inherit LIB_FISHING;
#include "../goblin.h"
 
static void create() 
{
  fishing::create();
  SetDomain("WestWood");
  SetShort("a beaten trail");
  SetLong("This trail meanders farther north away from the cobblestone road.  "
    "The trail is beaten into the ground suggesting that it is highly "
    "used.  Evergreen trees flourish to the east and north while to "
    "the south there lies a lake.  The trail leads northwest and "
    "south returning back to the cobblestone road.");
  SetItems( ([
    ({ "path","trail","road","ground" }) : (: GetLong :),
    ({ "trees","tree" }) :
      "The beautiful evergreens flourish in the fertile "
      "atmosphere of the WestWood, growing close to the "
      "road.",
    ({ "lake" }) : "The lake is very smooth and clear.  The water "
      "is so smooth and clear that the bottom can be seen.  "
      "There isnt anything in the bottom other than plants.",
    ({ "plant","plants","reed","reeds" }) : "The plants in the "
      "bottom of the lake are nothing more than smalls reeds "
      "that grow well in wet enviroment of the lake.  They "
      "stand very tall and are a very light, almost "
      "translucent, shade of green.",
    ]) );
  SetItemAdjectives( ([
    "trail" : "beaten",
    "plant" : "lake",
    "tree" : "evergreen",
    "path" : "forest",
  ]) );
  SetInventory( ([
    G_NPC + "goblin_fisher_boy" : 2,
  ]) );
  SetListen( ([
    "default" : "Low voices can be heard to the northwest.",
  ]) );
  SetSmell( ([
    "default" : "The scent of smoke lightly fills the air.",
  ]) );
  SetExits( ([
    "northwest" : G_ROOM + "camp_road_05",
    "south" : G_ROOM + "camp_road_03",
  ]) );
  SetSpeed(3);
  SetFish( ([ 
    G_OBJ + "fish_a" : 110,
    G_OBJ + "fish_b" : 50,
  ]) );
  SetChance(45);
  SetMaxFishing(25);
}
