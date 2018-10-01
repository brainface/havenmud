#include <lib.h>
#include "../grymxoria.h"
inherit LIB_SAGE;

static void create()
{
  sage::create();
  SetKeyName("justin");
  SetShort("Justin Deathwatch");
  SetId( ({
    "justin deathwatch", "deathwatch", "nosferatu", "justin",
    }) );
  SetLong(
    "Justin is an extremely aged nosferatu. He wears the "
    "robes of the dark mages and stands with an air of "
    "extreme intelligence and dignity. Justin is the Lore "
    "Keeper of Grymxoria."
  );
  SetRace("nosferatu");
  SetGender("male");
  SetClass("necromancer");
  SetLevel(40);
  SetLocalCurrency("bloodgems");
  SetSpellBook( ([
    "wards of protection" : 100,
    "wound" : 100,
    "wither" : 100,
    "hellfire" : 100,
  ]) );
  SetCombatAction(15, ({
    "!cast wards of protection",
    "!cast hellfire",
    "!cast wound",
    "!cast wither",
  }) );
}
