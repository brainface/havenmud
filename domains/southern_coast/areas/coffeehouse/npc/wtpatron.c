#include <lib.h>
#include <position.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("coffeehouse patron");
  SetShort("a patron of the coffeehouse");
  SetId( ({"patron",}) );
  SetAdjectives( ({ "coffeehouse" }) );
  SetLong("This frequent patron of the Twitchy Nymph sits in one of the chairs "
          "near a small table. He is dressed in old, much worn clothes and has a bit "
          "of stubble growing on his chin. He stares out the windows idly.");
  SetRace("human");
  SetGender("male");
  SetClass("fighter");
  SetSkill("melee combat",1,2);
  SetLevel(2);
  SetCurrency("imperials", random(20) );
  SetPosition(POSITION_SITTING);
   // Above line added by Duuk  -- 071597
}
