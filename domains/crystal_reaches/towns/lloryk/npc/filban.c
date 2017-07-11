#include <lib.h>
#include "../path.h"
inherit LIB_MAYOR;

static void create() {
  mayor::create();
  SetKeyName("filban");
  SetShort("Filban Torklerum, Prime Minister of the Shire");
  SetId( ({ "prime minister", "minister", "filban", "torklerum" }) );
  SetAdjectives( ({ "filban", "prime"}) );
  SetLong("Standing just over three feet tall, Filban still manages to "
          "project an aura of competence and authority.");
  SetRace("halfling");
  SetGender("male");
  SetClass("evoker");
  SetSkill("blunt combat",1,2);
  SetLevel(12);
  SetInventory( ([ 
    LLORYK + "obj/gavel.c" : "wield gavel",
    LLORYK + "obj/mrobes.c" : "wear robes",
     ]) );
  SetTown("Lloryk");
  SetLocalCurrency("rounds");
  SetTax(25);
  SetSpellBook( ([
    "shock" : 100,
    "capsule"   : 100,
    "ice ball" : 100,
    ]) );
  SetCombatAction(65, ({
    "!cast shock",
    "!cast capsule",
    "!cast ice ball",
    }) );
  SetTownRanks( ({
    ({ "Kulkhoznik", "Kulkhoznik" }),
      ({ "Comrade", "Comrade" }),
    ({ "Minister", "Minister" }),
    ({ "Commissar", "Commissar" }),
    ({ "Deputy Premier", "Deputy Premier" }),
    ({ "Premier", "Premier" }),
    ({ "Deputy Prime Minister", "Deputy Prime Minister" }),
    }) );
}
