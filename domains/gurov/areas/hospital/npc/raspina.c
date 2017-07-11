#include <lib.h>
#include <std.h>
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("raspina");
  SetShort("Raspina the Blessed, Tender of the Wounded");
  SetId( ({ "raspina", "tender", }) );
  SetAdjectives( ({ "blessed", "tender", }) );
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetClass("priest");
  SetSkill("multi-weapon", 1, 1);
  SetLevel(50);
  SetLong(
    "Raspina is the Tender of the Wounded here, and is often "
    "willing to heal those who have fallen ill or even fallen "
    "in battle. Simply <ask>ing her is usually enough."
    );
  SetFees( ([
    "resurrect" : 50,
    "magic"     : 50,
    "stamina"   :  2,
    "health"    :  3,
    "restore"   :  3,
    ]) );
  SetLocalCurrency("rubles");
  SetTown("Gurov");
  SetGender("female");
  SetInventory( ([
    STD_BLUNT "iron_mace" : 2,
    ]) );
  SetFirstCommands( ({ 
    "wield all", 
  }) );
  SetSpellBook( ([
    ]) );
  SetLimit(1);
}