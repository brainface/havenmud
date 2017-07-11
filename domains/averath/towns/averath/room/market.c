// Aerelus
#include <lib.h>
#include <domains.h>
#include "../averath.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("in a busy market");
  SetLong(
    "The Averath market is a very busy place where people can buy all manner "
    "of goods from local merchants. Any citizen is free to offer their wares "
    "here so long as they cause no trouble. Some merchants have set up "
    "wooden stalls to display their products. A small path leads back to the "
    "main road to the northwest."    
  );
  SetItems( ([
    ({ "road" }) : "The main road lies northwest.",
    ({ "city", "market", "Averath" }) : (: GetLong :),
    ({ "goods", "wares", "products", "stalls" }) : "There are a few stalls "
      "here, each displaying various products on sale, which can be bought "
      "from the local merchants.",
      ({ "path" }) : "This small path leads northwest to the main road.",    
  ]) );
  SetItemAdjectives( ([
    "road" : ({ "main" }),
    "market" : ({ "Averath" }),
    "stalls" : ({ "wooden" }),
    "path" : ({ "small" }),    
  ]) );
  SetInventory( ([
    AVERATH_NPC "fish_vendor" : 1,
    AVERATH_NPC "farmer" : 1,
    AVERATH_NPC "haberdasher" : 1,
    AVERATH_NPC "citizen" : 1,
    AVERATH_NPC "guard" : 1,    
  ]) );
  SetListen( ([
     "default" : "The sounds of haggling and the occasional argument can be "
       "heard.",
  ]) );
  SetSmell( ([
     "default" : "The market is home to a unique concoction of smells, mostly "
     "fish, spices and fresh bread.",
  ]) );  
  SetExits( ([        
    "northwest" : AVERATH_ROOM "road3",
  ]) );      
}