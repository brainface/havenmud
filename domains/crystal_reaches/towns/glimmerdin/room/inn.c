#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(30);
  SetShort("a rustic looking inn");
  SetLong(
    "The inn is a small and rustic looking area set in the mountain. "
    "The walls feature murals of dwarves drinking and enjoying their "
    "lives. Thick stone benches and tables fill the room, their bulk "
    "filling the space and not leaving much floor space. Built into the "
    "wall is a large fireplace, which fills the room with light and warmth."
    );
  SetProperty("no teleport",1);
  SetProperty("no conjuring",1);
  SetItems( ([
    ({ "wall", "walls" }) :
      "The walls are smooth rock and are covered with murals.",
    ({ "mural", "murals", }) :
      "The murals display dwarves in various states of inebriation.",
    ({ "bench", "benches", "table", "tables" }) :
      "The tables and benches are thick stone, worn smooth by dwarves "
      "over generations.",
    ({ "fireplace" }) :
      "The fireplace is a large stone inset into the wall.",
    ]) );
  SetExits( ([
    "out" : G_ROOM "gh_west",
    ]) );
  SetSmell( ([
    "default" : "Incredible aromas drift through the room.",
    ]) );
  SetListen( ([
    "default" : "An incessant chatter buzzes in the room.",
    ]) );
  SetInventory( ([
    G_NPC "mort" : 1,
    ]) );
}