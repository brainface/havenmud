#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "out" : GUROV_ROOM "dock3",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(45);
  SetShort("the Whiny Wench");
  SetLong(
     "The Whiny Wench is a tavern of ill repute that lies next to the "
    "docks in Gurov. The tavern is brightly lit except for one corner, "
    "where a barrel sits that doesn't seem to serve any purpose. The "
    "fireplace gives off warmth and causes the tavern to feel much "
    "more friendly than it actually is. A thick wooden bar dominates "
    "the eastern half of the tavern."
    );
  SetItems( ([
    "barrel" : "Under inspection, it seems fairly obvious that the "
               "barrel is empty.  It appears to have handles on the "
               "inside, as if the barrel could be entered.",
    "bar"    : "The bar is a huge wooden structure which looks almost "
               "defensive.",
    "fireplace" : "The fireplace is warm and friendly.",
    ]) );
  SetEnters( ([
    "barrel" : GUROV_ROOM "guild1",
    ]) );
  SetNewsgroups( ({ "player.general" }) );
  SetSmell("The fireplace mixes with alcohol to give this tavern a differet smell.");
  SetListen("The sounds of the fire mix with an odd dripping noise from near the barrel.");
  SetInventory( ([
    GUROV_NPC "shiptrainer" : 1,
  GUROV_NPC "feliks" : 1,
    ]) );
}
