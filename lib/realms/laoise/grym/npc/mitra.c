#include <lib.h>
#include "../grymxoria.h"
inherit LIB_HEALER;

static void create() {
  healer::create();
  SetKeyName("mitra");
  SetShort("Mitra, the healer of Saahagoth");
  SetId( ({ "healer of saahagoth", "nosferatu", "healer",
    "mitra", }) );
  SetLong(
    "Mitra is the local healer.  It is her job to make "
    "sure that anyone who can get up and fight again, "
    "does so, for a modest fee of course."
  );
  SetRace("nosferatu");
  SetGender("female");
  SetClass("cleric");
  SetLevel(40);
  SetTown("Grymxoria");
  SetReligion("Saahagoth", "Saahagoth");
  SetSkill("blunt attack", 120, 0);
  SetSkill("necromancy", 120, 0);
  SetSkill("enchantment", 120, 0);
  SetSkill("healing", 82, 2);
  SetSkill("pole defense", 82, 2);
  SetSkill("divination", 82, 2);
  SetSkill("blunt defense", 82, 2);
  SetCurrency("bloodgems", 4000);
  SetLocalCurrency("bloodgems");
  SetFees( ([
    "resurrect" : 100,
    "magic" : 10,
    "stamina" : 1,
    "health" : 3,
    "restore" : 50,
  ]) );
  SetFriends( ({ "vyper" }) );
}
