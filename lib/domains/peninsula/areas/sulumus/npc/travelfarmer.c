// Proximo@Pax Imperialis
// 06/19/2003

#include <std.h>
#include <lib.h>
#include <vendor_types.h>
#include "../sulumus.h"

inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("farmer");
  SetId( ({ "farmer", "we_wander" }) );
  SetAdjectives( ({ "peasant" }) );
  SetShort("a peasant farmer");
  SetLong(
     "This tall and strong man stands tall with his long hair and bushy beard. He looks "
     "heavily tanned, suggesting he has worked many long and hard days under the glare "
     "of the sun. He has traveled here from his farm to trade his crops and goods "
     "for a little extra coin. "
     );
  SetGender("male");
  SetLimit(2);
  SetRace("human"); 
  SetBaseLanguage("Imperial");
  RemoveLanguage("Human");
  SetLanguage("Imperial", 100, 1);
  SetWander(1+random(3));
  SetClass("merchant");
  SetSkill("melee combat", 1, 3);
  SetSkill("slash combat", 1, 3);
  SetSkill("pierce combat", 1, 3);
  SetSkill("blunt combat", 1, 3);
  SetLevel(1+random(10));
  SetInventory( ([
     S_OBJ + "dshirt" : "wear shirt",
     S_OBJ + "overalls" : "wear overalls",
  ]) );
  SetFriends( ({
  }) );
  SetCurrency("imperials", 10 + random(99));
  SetMorality(250);
  SetAction(1, ({
     "!say You know what my favorite time of day is? Dawn...I love the smell of "
     "fresh manure in the morning!",
     !"say Hello there",
     "!say I've come here to seal a few deals for the next crop season. ",
     "!yawn",
     "!spit",
     "!say Has anyone told you that you are a bit funny-looking?",
     "!say It's a shame every time we get a dry season...kills most of my crop!",
     "!say Out of my way!",
     "!grin evil",
     "!smile hap",
  }) );
  SetCombatAction(1, ({
     "!say Momma says to go into the light...",
     "!say Hey cut that out will you!",
     "!say You're asking for a walloping...",
  }) );
}
