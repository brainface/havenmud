/*  A bottom feeder in the chain of devils */
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
  SetRace("lemure",1);
  AddLimb("torso", 0, 1, ({A_BODY_ARMOUR}));
  AddLimb("right arm", "torso", 2, ({A_BODY_ARMOUR}));
  AddLimb("left arm", "torso", 2, ({A_BODY_ARMOUR}));
  AddLimb("head", "torso", 1);
  AddLimb("right hand", "right arm", 4, ({A_WEAPON}));
  AddLimb("left hand", "left arm", 4, ({A_WEAPON}));
  SetStat("strength", 15, 2);
  SetStat("durability", 15, 2);
  SetStat("agility", 2, 4);
  SetStat("coordination", 2, 4);
  SetClass("rogue");
  SetInventory( ([
    PLANE_OBJ "lemure_club" : "wield femur",
    PLANE_OBJ "lemure_rags" : "wear rags",
  ]) );
  SetLevel(30);
  SetMorality(-100);
  }
