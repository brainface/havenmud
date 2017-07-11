#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("berton's Armoury");
  SetClimate("indoors");
  SetAmbientLight(20);
  SetLong(
    "The armory is dimly lit by several torches and "
    "the large forge. Around the room are various "
    "pieces of armor, some complete, some in "
    "progress."
  );
  SetItems( ([
    ({ "forge" }) : "the forge is a large structure that is big enough "
    "for a large creature to fit into.  ",
    ({"pieces of armor", "armor" }) :
    "All of the pieces are of excellent workmanship.  ",
  ]) );
  SetEnters( ([
    "forge" : G_ROOM + "forge2",
  ]) );
  SetInventory(  ([
    G_NPC + "berton" : 1,
    G_NPC + "gesar"  : 1,
  ])  );
  SetExits( ([ 
    "out" : G_ROOM + "road24" 
  ]) );
}

