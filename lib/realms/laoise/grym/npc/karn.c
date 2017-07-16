#include <lib.h>
#include "../grymxoria.h"
inherit LIB_TRAINER;

static void create()

{
  trainer::create();
  SetKeyName("karn");
  SetShort("Karn Resnar, a dark mage");
  SetId( ({ "karn resnar", "nosferatu", "resnar", 
    "karn", "mage", }) );
  SetLong(
    "Karn Resnar is a master of all magic related "
    "skills that pertain to necromancy and the dark arts. "
    "Karn may be willing to share this knowledge "
    "with young necromancers."
  );
  SetRace("nosferatu");
  SetGender("male");
  SetClass("necromancer");
  SetLevel(35);
  SetInventory( ([
    G_OBJ + "nosf_staff" : "wield staff",
    G_OBJ + "nosf_armor" : "wear armor",
  ]) );
  SetSpellBook( ([
    "wither" : 100,
    "reckoning" : 100,
    "wound" : 100,
    "wards of protection" : 100,
    "splash" : 100,
    "planar assault" : 100,
    "asphyxation" : 100,
    "chill touch" : 100,
    "plane warp" : 100,
  ])  );
  SetCombatAction(10, ({
    "!cast wards of protection",
    "!cast reckoning",
    "!cast wound",
    "!cast wither",
    "!speak You Dare !",
    "!cast plane warp",
    "!speak You will die.",
  }) );
  SetFriends( ({ "agnod", "guard" }) );
  AddTrainingSkills("necromancy");
  AddTrainingSkills("evokation");
  AddTrainingSkills("enchantment");
}
