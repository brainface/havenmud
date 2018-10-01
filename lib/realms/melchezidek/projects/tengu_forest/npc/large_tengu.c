#include <lib.h>
#include <std.h>
#include <armour_types.h>
#include "../tengu.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetId("tengu");
  SetKeyName("large tengu");
  SetShort("a large tengu");
  SetLong("A large ugly tengu is a bird demon with a sharp"
          " beak and black feathers. His eyes are solid"
          " black orbs set deep within in his head due"
          " to an extremely large forehead.");
  SetGender("male");
  SetRace("bird", "demon");
  SetClass("ninja");
  SetLevel(145);
  SetInventory( ([
    TENG_OBJ "nodachi" : "wield nodachi",
  ]) );
  SetSpellBook( ([
     "tend wounds"       : 100,
     "full regeneration" : 100,
     "nature's recovery" : 100,
     ]) );
  SetCombatAction(35, ({
     "!emote squaks loudly.",
     "!disarm",
     "!disorient",
     "!cast tend wouds",
     "!cast full regeneration",
     "!cast nature's recovery",
     "!disarm",
     }) );
   AddLimb("left claw", "left wing", 3,({A_WEAPON}) );
   AddLimb("right claw", "right wing", 3,({A_WEAPON}) );
}
