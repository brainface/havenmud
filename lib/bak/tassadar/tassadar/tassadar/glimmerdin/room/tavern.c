/*  the pub! */

#include <lib.h>
#include "../glim.h"


inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(45);
  SetShort("Glimmerdin tavern");
  SetLong("The tavern is a fairly small room, and tables and chairs "
    "are scattered throughout in a haphazard fashion making it hard to get "
    "through to the bar at the far wall. The situation is further complicated "
    "by the fact that many of the tables are turned over completely and "
    "some have been smashed. Obviously, this is the best tavern for miles. "
    "The bar is a big slab of stone, and weapons are mounted on the wall, "
    "many of which are battle worn; they give the tavern a nice, friendly "
    "feeling that warmly welcomes patrons as they enter.");
  SetItems( ([
    ({"tavern", "room", "pub"}) : (: GetLong :),
    ({"table", "tables", "chair", "chairs"})  :
      "Tables and chairs are scattered all throughout the tavern.  Many "
      "are smashed, and they perpetually bar convenient passage, much "
      "to the annoyance of many.",
    ({"bar", "slab", "stone", "wall", "far wall"}) :
      "The bar is a big slab of stone at the far wall.",
    ({"weapon", "weapons"})  :
      "The weapons are arranged on the walls with reasonably bad taste, "
      "but nonetheless, their atmosphere makes a visit to the tavern a jolly good "
      "use of one's time.",
    ]) );
  SetItemAdjectives( ([
    "tavern"  :  ({"fairly small", "small", "jolly good"}),
    "table"  :  ({"annoying", "shattered", "smashed", "scattered"}),
    "bar"  :  ({"big", "stone"}),
    "weapon"  :  ({"warm", "friendly", "nice", "battle worn", "worn", 
                   "happy", "dwarven", "jolly good", "good", "jolly"}),
    ]) );
  SetExits( ([
    ]) );
  SetSmell( ([
    "default" : "It smells like good ale.",
    ]) );
  SetListen( ([
    "default" : "The room is filled with rowdy voices.",
    ]) );
  SetInventory( ([
    G_NPC "style_trainer" : 1,
    G_NPC "bard" : 1,
    G_NPC "barmaid" : 1,
    ]) );
}
