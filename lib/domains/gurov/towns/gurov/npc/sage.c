/* Astara Banewulf, Sage v 2.0 compliant */
#include <lib.h>
inherit LIB_SAGE;

static void create() {
  sage::create();
  SetKeyName("Natasha Rostov");
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetTown("Gurov");
  SetShort("Natasha Rostov the Foreign Minister of Gurov");
  SetId( ({ "natasha", "rostov", "minister" }) );
  SetAdjectives( ({ "natasha", "foreign", "gurov" }) );
  SetLong(
    "Natasha Rostov serves as Foreign Minister for the Principality "
    "of Gurov.  Her role consists mainly of teaching foreign languages "
    "to the citizens so they can travel and represent the nation."
  );
  SetGender("female");
  SetClass("evoker");
  SetSpellBook( ([
     "missile"  : 100,
     "fireball" : 100,
     "sphere"   : 100,
     ]) );
  SetLevel(35);
  SetCombatAction(80,
      ({ 
        "!cast missile",
        "!cast fireball",
        "!cast sphere",
        }) );
  SetTaughtLanguages( ({ 
  	"Eltherian", "Enlan", "Sprith", "Gurovian", "Tai", "Eetria" 
  	}) );
  SetLocalCurrency("rubles");
  SetCharge(250);
}
