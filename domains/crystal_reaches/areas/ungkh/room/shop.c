//Selket@Haven
//2006
#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {

  room::create();
  SetShort("riesin's Herbs and Stuff");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong(
    "This is a shop where citizens of Ungkh come to buy from Riesin, "
    "the giantess. Her wares are prominently displayed on shelves that "
    "reach from the floor to the giant-high ceiling, yet one gets the "
    "feeling that shoplifting from Riesin would be a big mistake. A "
    "door leads back out to the village."
    );
  SetSmell("You can smell herbs, dust, and other sundry items.");
  SetListen("The sounds of Ungkh are muted inside the shop.");
  SetItems( ([
    ({ "shop" }) :
       (: GetLong :),
    ({ "wares" }) :
    "Riesin sells herbs, poisons, and various other things.",
    ({ "shelves" }) : 
    "The stone shelves are lined with many goods.",
    ]) );
  SetExits( ([
    "out" : U_ROOM + "road07",
    ]) );
  SetInventory( ([
    U_NPC "riesin" : 1,
  ]) );
  }
