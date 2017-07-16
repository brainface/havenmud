// Proximo@Via Imperialis
// 06/12/2003

#include <lib.h>
#include <std.h>
#include <vendor_types.h>
#include "../sulumus.h"

inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("merchant");
  SetId( ({ "merchant", "we_wander" }) );
  SetAdjectives( ({ "traveling", }) );
  SetShort("a traveling merchant");
  SetLong(
     "This short, thin, long haired man is one of the many travelers that pass through the "
     "trading post. His hair is jet black, faced heavily tanned, and he looks to have "
     "suffered great hardships along his paths in life. He walks with a limp in his right "
     "leg, nods with several scars across his brow, and speaks with a very rough and horse "
     "voice. He seems like a person who's soul has been shattered and rebuilt again, but this "
     "time a lot less sensative about the needs of others than before. He seems greedy, only "
     "caring about the profits he can earn and not the will of others. "
  	 );
  SetLimit(1);
  SetRace("human"); SetBaseLanguage("Imperial");
  SetGender("male");
  RemoveLanguage("Human");
  SetWander(1+random(2));
  SetLanguage("Imperial", 100, 1);
  SetClass("merchant");
  SetSkill("melee combat", 1, 3);
  
  SetLevel(16);
  SetInventory( ([
     S_OBJ + "pants" : "wear pants",
     S_OBJ + "shirt" : "wear shirt",
     STD_OBJ + "storage/pouch" : "wear pouch",
  ]) );
  SetFriends( ({
  }) );
  SetCurrency("imperials", random(195));
  SetMorality(-200);
  SetAction(1, ({ 
     "!say What you say?",
     "!say Heeee Heeee",
     "!say The world can sure be tough at times...damn near stresses the hell out of me!",
     "!say See this scar? This one right here across my face? Wild boar got at my face and "
     "damn near gouged my eye out!",
     "!say I've traveled to a lot of different places...this place just ain't too bad, well if you "
     "like being near choked up by guards that is!",
     "!spit",
     "!mmm",
     "!say Eh?",
     "!say Yeeeeep!",
  }) );
  SetCombatAction(1, ({
     "!I'm just a big coward...please don't hurt me anymore!",
     "!say Oh please stop!",
  }) );
}
