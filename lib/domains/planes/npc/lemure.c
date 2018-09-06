/*  A bottom feeder in the chain of devils */
// mahk 2018: changed to wraith/lemure race, NoCorpse
// 
#include <lib.h>
#include <armour_types.h>
#include "../planes.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("lemure");
  SetId( ({ "lemure", "devil" }) );
  SetAdjectives( ({ "slimy" }) );
  SetShort("a slimy lemure");
  SetLong("This is a lemure, one of the damned souls stuck for "
          "all eternity in the Lower Planes. Its pitiful body "
          "has only a slimy, muck-like lower half with two "
          "protrusions that pass as arms and a half formed head with "
          "large and unclosing eyes of solid black.");
  SetRace("wraith","lemure");
  SetClass("rogue");
  SetInventory( ([
    PLANE_OBJ "lemure_club" : "wield femur",
    PLANE_OBJ "lemure_rags" : "wear rags",
  ]) );
  SetLevel(30);
  SetMorality(-500); 
  SetNoCorpse(1);
}

int eventDie(object killer) {
  object room = environment();
  if (room) {
    room->eventPrint("The lemure dissolves into a pile of smelly grease.");
  }
  return (npc::eventDie(killer));
}

