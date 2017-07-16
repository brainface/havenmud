#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a meeting room above the Divine Chalice");
  SetExits( ([
    "down" : H_ROOM + "shops/tavern",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(30);
  SetLong(
    "This small room appears to serve as a meetingplace for some group "
    "or another. No evidence of any activity remains however. A table "
    "surrounded by a few chairs sits neatly in the center of the room. "
    );
  SetSmell("The room smells faintly of old sweat.");
  SetListen("Noise echoes up from the tavern.");
  SetInventory( ([
    H_NPC "rogue"       : 1,
    ]) );
}