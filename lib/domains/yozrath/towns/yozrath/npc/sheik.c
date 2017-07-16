

#include <lib.h>
#include "haven.h"
#include "../yozrath.h"
inherit LIB_MAYOR;

static void create() {
  ::create();
  SetKeyName("Sheik Fahdi");
  SetShort("Sheik Fahdi bin Yossef");
  SetId( ({ "sheik", "fahdi", "yossef", }) );
  SetAdjectives( ({ "bin", "sheik", "fadhi" }) );
  SetLong(
    "Sheik Fahdi bin Yossef is a well built man whose family has "
    "ruled the desert for over a hundred years. His aged face shows "
    "that his wise rule has lasted for some time."
  );
  SetRace("human");
  SetBaseLanguage("Padashi");
  SetGender("male");
  SetClass("janissary");
  SetLevel(60);
  SetTown("Yozrath");
  SetMorality(250);
  SetInventory( ([
    YOZRATH_OBJ "thobe" : "wear thobe",
    YOZRATH_OBJ "bisht" : "wear bisht",
    YOZRATH_OBJ "turban" : "wear turban",
    ]) );
  SetTax(50);
  SetLocalCurrency("dinar");
  SetTownRanks( ({
    ({ "Slave", "Slave" }),
    ({ "Citizen", "Citizen" }),
    ({ "Pasha", "Pasha" }),
    ({ "Taifa", "Taifa" }),
    ({ "Shah", "Shah" }),
    ({ "Emir", "Emir" }),
    ({ "Malik", "Malika" }),
    }) );
}
