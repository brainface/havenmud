//
//  Ayla the medicine woman
//  kyla 11-97
//  Modified by Rhakz - Angel Cazares
//  Date: 10/13/98 
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_HEALER;

static void create() {
  healer::create();
  SetKeyName("ayla");
  SetShort("Ayla the Medicine Woman");
  SetId( ({ "ayla", "woman","medicine woman","ayla the medicine woman"}) );
  SetLong("This woman is quite tall and beautiful. A white aura "
          "surrounds her body, transmitting peace to everyone "
          "near her. She could tend to someone's wounds if "
          "paid the right amount."
         );
  SetAdjectives( ({"tall","beautiful"}) );
  SetGender("female");
  SetMorality(random(200) - 100);
  SetRace("human");
  SetClass("shaman");
  SetSkill("healing", 100, 1);
  SetSkill("conjuring", 100, 1);
  SetLevel(50);
  SetTown("Baria");
  SetSpellBook( ([
                  "mangle" : 100,
                  "crush" : 100,
                  "ancient power" : 100,
              ]) );
  SetCombatAction(30, ({
                        "!cast mangle",
                        "!cast crush",
                        "!cast ancient power",
                  }) );
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
  SetFees( ([
    "resurrect" : 100,
    "magic" : 10,
    "stamina" : 1,
    "health" : 3,
    "restore" : 50,
  ]) );
  SetLocalCurrency("chits");
  SetCurrency( ([ 
     "chits" : random(250) + 250,
  ]) );
}

