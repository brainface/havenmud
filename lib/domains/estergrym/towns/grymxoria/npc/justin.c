#include <lib.h>
#include "../grymxoria.h"
inherit LIB_SAGE;

static void create()
{
  sage::create();
  SetKeyName("justin");
  SetShort("justin Deathwatch");
  SetId( ({ "justin deathwatch", "deathwatch", "nosferatu", "justin" }) );
  SetLong(
    "Justin is an extremely aged nosferatu. He wears the robes of the "
    "dark mages and stands with an air of extreme intelligence and "
    "dignity. Justin is the Lore Keeper of Grymxoria.  ");
  SetRace("nosferatu");
  SetGender("male");
  SetClass("necromancer");
  SetLevel(40);
  SetMorality(-2000);
  SetLocalCurrency("bloodgems");
  SetTaughtLanguages( ({
    "Eltherian", "Runic", "Gryshnak", "Padashi", "Tai", "Gurovian"
  }) );
  SetCharge(500);
  SetSpellBook( ([
    "necromantic shield" : 100,
    "wound"              : 100,
    "drain soul"         : 100,
    "fireball"					 : 100,
  ]) );
  SetCombatAction(65,  ({
    "!cast necromantic shield",
    "!cast fireball",
    "!cast wound",
    "!cast drain soul",
  }) );
}
