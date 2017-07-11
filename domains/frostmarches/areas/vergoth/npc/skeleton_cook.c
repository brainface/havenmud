#include <lib.h>
#include "../vergoth.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("skeleton cook");
  SetRace("human");
  SetId( ({ "human", "skeleton", "skeleton cook","cook" }) );
  SetAdjectives( ({ "skeleton" }) );
  SetClass("rogue");
  SetGender("male");
  SetShort("skeleton cook");
  SetLevel(2);
  SetUndead(1);
  SetNoCorpse(1);
  SetLong(
     "This skeleton appears to have been a cook before its death.  It "
     "has been bleached white with age and stands about six feet tall.  "
     "It is moving about as though it is trying to perform its before "
     "death duties.");
  SetInventory( ([
     V_OBJ + "knife" : "wield knife",
     ]) );
  SetMorality(-300);
  SetCombatAction(30, ({ 
     "!emote pulls himself together.",
     "!emote clanks loudly as he swings.",
     "!emote rattles as he moves around.",
     }) );
  SetAction(10, ({
     "!emote shakes some pans about.",
     "!emote tosses flour in the air.",
     "!whistle",
     "!emote supervises everyone.",
     "!emote mutters something about pay.",
      }) );
  SetDie( "A skeleton shatters into fragments of dust." );
}
