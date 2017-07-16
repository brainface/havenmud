
/* nymph
   Elasandria 4/16/98
*/

#include <lib.h>
#include "../kingdom.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("nymph");
  SetShort("a playful nymph");
  SetId( ({"nymph","woman","sprite"}) );
  SetAdjectives( ({"playful","teasing","beautiful","happy","water"}) );
  SetLong("This beautiful young water sprite frolics happily in the water. "
        "The woman has deep blue eyes and damp tendrils of her emerald "
        "green hair curls becomingly around her face.");
  SetGender("female");
  SetRace("nymph");
  SetClass("rogue");
  SetLevel(8);
  SetMorality(500);
  SetAction(5,
          ({"!emote winks teasingly and splashes you with water.",
         "The beautiful nymph winks teasingly and splashes you with water."}) 
         );
  SetInventory( ([
         ]) );
}
