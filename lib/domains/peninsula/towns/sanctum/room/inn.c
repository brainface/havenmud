/* An inn */
#include <lib.h>
#include <std.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetInventory( ([
    ROME_NPC "druscilla" : 1,
    ROME_NPC "verres" : 1,
    ROME_NPC "hippalus" : 1,
    STD_NPC  "brawler"   : 1,
    ]) );
  SetProperty("no bump", 1);
  SetNewsgroups( ({ "player.general" }) );
  SetExits( ([
    "out" : ROME_ROOM "vi08",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetShort("the Broken Stine Tavern");
  SetLong("The Broken Stine is a less then reputable establishment "
          "of dubious character. The owner, Druscilla, used to work for "
          "the previous owner when the Tavern was called the Groggy "
          "Sailor. The city shut down that festering sore on the city "
          "but the Broken Stine isn't much better.");
  SetSmell( ([
    "default" : "The smell of stale beer fills the air.",
    ]) );
  SetListen( ([
    "default" : "The clank of pottery on tables is part of the noise.",
    ]) );
}
