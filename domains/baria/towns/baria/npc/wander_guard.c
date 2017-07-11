//
//  Wandering guards for the village
//  Created by: Rhakz@Haven -- Angel Cazares
//  For Baria
//  Date: 14/02/99
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("guard");
  SetId( ({"guard", "draconian","baria_wander"}) );
  SetAdjectives( ({ "barian" }) );
  SetShort("a member of the Barian Guard");
  SetLong(
     "This large and powerful looking draconian guard has a fierce "
     "look, carrying the demeanor of a true warrior. The sharp claws "
     "and thick scales of this particular draconian look to be well "
     "groomed, yet tough and strong. This person is not one to be "
     "trifled with. "
  );
  SetMorality(30);
  SetGender("male");
  SetRace("draconian");
  SetTown("Baria");
  SetLimit(4);
  SetClass("fighter");
  SetSkill("melee combat", 1, 1);
  SetLevel(40 + random(10));
  SetWander(10);
  SetFriends( ({
                "guard","kid","Ariana","Ayla","Brun","Creb","carian",
                "drunkard","Ginfur","Mianin","mother","native","Pakal",
                "Vorn","Naj","Sardaukar"
  }) );
  SetInventory( ([
     BARIA_OBJ + "loincloth" : "wear loincloth",
  ]) );
  SetCurrency( ([
     "chits" : 10 + random(40),
  ]) );
  RemoveLanguage("Dragonish");
  SetLanguage("Barian", 100, 1);
  SetAction(3, ({
     "!say I do my duty to protect the village.",
     "!say Do not break the law.",
     "!say Down with our enemies!",
     "!say Praise be to our Ancestors!",
  }) );
}
