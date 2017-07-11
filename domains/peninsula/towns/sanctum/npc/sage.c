#include <lib.h>
#include "../rome.h"

inherit LIB_SAGE;

static void create() {
  sage::create();
  SetKeyName("Elia Linguis");
  SetRace("human");
  SetLimit(1);
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetShort("Elia Linguis, Translator for Sanctum");
  SetId( ({ "elia", "linguis", "translator" }) );
  SetAdjectives( ({ "sanctum", "elia", }) );
  SetLong("Elia Linguis aids the Empire's commerce by training "
          "citizens in foreign tongues. She also trains foreign "
          "travellers in the language of the Empire.");
  SetGender("female");
  SetTown("Sanctum");
  SetClass("evoker");
  SetLevel(35);
  SetSpellBook( ([
     "missile"    : 100,
     "fireball"   : 100,
     "chain lightning" : 100,
     "sphere" : 100,
     ]) );
  SetCombatAction(75,({
     "!cast missile",
     "!cast fireball",
     "!cast sphere",
     "!cast chain lightning",
         }) );
  SetTaughtLanguages( ({ "Eltherian", "Uruk", "Imperial", }) );
  SetLocalCurrency("imperials");
  SetCharge(300);
  SetInventory( ([
    ROME_OBJ "stola_poor" : "wear stola",
  ]) );
}

