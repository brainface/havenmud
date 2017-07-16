// Dalnairn
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../dalnairn.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("in the dalnairn tavern");
  SetLong(
    "This building is the only tavern in the city. Since the Duergar "
    "population thoroughly enjoy alcohol, especially the locally distilled "
    "whisky, it brings in amazing profits which are mirrored by the "
    "luxurious furniture and decorations. Soft couches are positioned around "
    "the tavern, with a table at each. The main bar extends over the entirety "
    "of the northern wall, with a vast selection of spirits and other drinks "
    "on display."
  );
  SetItems( ([
  ({ "building", "tavern" }) : (: GetLong :),
  ({ "furniture", "couches", "tables" }) : 
    "Soft red couches are positioned throughout the tavern. They look very "
    "comfortable and seem very expensive. Short tables are positioned at each "
    "couch.",
  ({ "decorations", "paintings" }) : 
    "Paintings of some of the more popular Duergar of times long past hang "
    "from the walls, each in finely decorated obsidian frames.",
  ({ "bar" }) : 
    "The bar, where the bartender usually stands awaiting customers, has a "
    "vast selection of drinks.",
  ({ "wall" }) : 
    "The wall, almost entirely covered by bottles, is home to the main bar.",
  ({ "spirits", "drinks" }) : 
    "Most of the drinks at the bar are local whisky, though there are some "
    "others that look mostly untouched.",  
  ]) );
  SetItemAdjectives( ([
    "tavern" : ({ "dalnairn" }),
    "furniture" : ({ "luxurious" }),
    "couches" : ({ "soft", "comfortable" }),
    "tables" : ({ "short" }),
    "decorations" : ({ "luxurious" }),
    "bar" : ({ "main" }),
    "wall" : ({ "northern" }),
    "drinks" : ({ "other" }),  
  ]) );
  SetInventory( ([
    DAL_NPC "morven" : 1,
    DAL_NPC "aulay" : 1,
  ]) );
  SetListen( ([
    "default" : "The sounds of merrymaking and drunken behaviour surround "
      "the bar.",
  ]) );
  SetSmell( ([
    "default" : "The tavern strongly smells of whisky and tobacco smoke.",
  ]) );
  SetExits( ([
    "out" : DAL_ROOM "road1",
  ]) );  
}
