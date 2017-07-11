// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("the Axe Barracks");
  SetLong(
    "The interior of this building is stark and simple. Its walls are made of "
    "a plain grey stones which appears to have been planed smooth and then "
    "fitted together with minimal use of adhesive. The floor is of the same "
    "stone, now shaded a darker color in many places due to the repetitive "
    "movement of feet across them. On both the north and south walls are a "
    "massive pair of crossed axes, below which there are multiple weapon "
    "racks. A simple door stands to the west, leading towards Karak road, "
    "otherwise this building is without exits."
  );
  SetItems( ([
    ({ "building", "barracks" }) : (: GetLong :),
    ({ "wall", "walls" }) : "The walls are made of a simple grey stones, "
    "fitted tightly together. On the north and south walls are hung crossed "
    "pairs of axes.",
    ({ "axes" }) : "Pairs of crossed axes hang on the north and south walls.",
    ({ "floor" }) : "The floor remains flat and solid, made of the same "
    "stone as the walls, but a darker color in some places due to repetitive "
    "usage.",
    ({ "rack", "racks" }) : "These are sturdy racks, designed to hold training "
    "weapons when they are not in use.",
    ({ "door" }) : "This plain door is set in the west wall and leads back "
    "to the Karak Road.",
  ]) );
  SetItemAdjectives( ([
    "building" : ({ "axe", "stone", "simple" }),
    "wall" : ({ "simple", "grey", "stone", "barrack", "north", "south" }),
    "axes" : ({ "hung", "wall", "on", "pair", "pairs", "crossed" }),
    "floor" : ({ "plain", "grey", "stone", "darkened", "darker", "barracks" }),
    "rack" : ({ "sturdy", "weapon", "training", "barrack" }),
    "door" : ({ "plain", "west", "wall" }),
  ]) );
  SetSmell( ([
    "default" : "The pungent reek of sweat has been absorbed in to the "
    "very walls.",
  ]) );
  SetListen( ([
    "default" : "The eerie silence before battle hangs in the air.",
  ]) );
  SetInventory( ([
    KARAK_NPC + "leader_fighter" : 1,
    KARAK_NPC + "trainer_fighter" : 1,
  ]) );
  SetExits( ([
    "out" : KARAK_ROOM + "rd2",
  ]) );
}
