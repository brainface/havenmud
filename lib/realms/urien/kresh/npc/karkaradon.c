/*  A sage to teach the humanoid languages. */
#include <lib.h>
#include "../goblins.h"
inherit LIB_SAGE;

static void create() {
  ::create();
  SetKeyName("Karkaradon");
  SetGender("male");
  SetShort("Karkaradon the Wise");
  SetRace("goblin");
  SetClass("rogue");
  SetSkill("blunt combat",1,2);
  SetLevel(30 + random(10));
  SetMorality(-300);
  SetCurrency( ([
     "rounds" : random(300),
    ]) );
  SetId( ({ "karkaradon", "goblin", "teacher" }) );
  SetAdjectives( ({ "wise" }) );
  SetLong("Karkaradon the Wise is the smartest goblin alive. He has "
          "travelled across the world in search of knowledge and power. "
          "It is rumored he would be willing to share that knowledge "
          "to all who are interested.");
  SetInventory( ([
      GOBLIN_OBJ + "sap" : "wield sap",
      ]) );
  SetTaughtLanguages( ({ "Gobyshkin", "Eltherian", "Uruk", "Slith", "Skavish",
                         "Koblich", "Heyami", "Trog", "Shangtai", 
                      }) );
  SetLocalCurrency("rounds");
  SetCharge(350);
}
