// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetNewsgroups( ({ "town.karak" }) );
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("Karak Town Hall");
  SetLong(
    "Made of local wood, this building is sturdy and well-maded, but "
    "simplistic and functional in design. Flat walls are adorned only "
    "with a pair of crossed axes on the north wall. The floor is equally "
    "asture, appearing to have been buffed clean regularly. A single table "
    "and plain wooden chair stand near the west wall."
  );
  SetItems( ([
    ({ "building", "hall" }) : (: GetLong :),
    ({ "wall", "walls", "floor" }) : "The floor and walls of this building "
    "are simple and sturdy, made of local wood and cleaned regularly.",
    ({ "table", "chair" }) : "A sturdy table and chair stand near the west "
    "wall of this simple room.",
  ]) );
  SetItemAdjectives( ([
    "building" : ({ "town" }),
    "wall" : ({ "flat", "wood", "wooden", "simple", "sturdy", "clean" }),
    "table" : ({ "sturdy", "wooden", "single", "plain" }),
  ]) );
  SetListen( ([
    "default" : "A jumble of sounds floats through the door from the "
    "nearby Karak Road.",
  ]) );
  SetSmell( ([
    "default" : "The warm smell of clean wood fills the room.",
  ]) );
  SetInventory( ([
    KARAK_NPC + "mayor" : 1,
  ]) );
  SetExits( ([
    "out" : KARAK_ROOM + "rd5",
  ]) );
}
