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
  SetId( ({"guard", "human","baria_wander"}) );
  SetAdjectives( ({ "barian" }) );
  SetShort("a member of the Barian Guard");
  SetLong(
     "This tall and intimidating human presents himself as a "
     "guard of the town of Baria. He stands at attention, poised to "
     "stop any wrong doers in his Town. His facial expression is that "
     "of calmness and confidence in his duty."
  );
  SetMorality(30);
  SetGender("male");
  SetRace("human");
  SetTown("Baria");
  SetLimit(8);
  SetSkill("melee attack", 1, 1);
  SetSkill("melee defense", 1, 1);
  SetSkill("projectile attack", 2, 1);
  SetSkill("projectile defense", 2, 1);
  SetSkill("blunt defense", 3, 1);
  SetSkill("pierce defense", 3, 1);
  SetSkill("slash defense", 3, 1);
  SetSkill("hack defense", 3, 1);
  SetSkill("knife defense", 3, 1);
  SetSkill("pole defense", 3, 1);
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
     "chits" : 500 + random(200),
  ]) );
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
  SetAction(3, ({
     "!say I do my duty to protect the village.",
     "!say Do not break the law.",
     "!say Down with the enemies of the Jungle!",
     "!say Praise be to the Ancients!",
  }) );
}
