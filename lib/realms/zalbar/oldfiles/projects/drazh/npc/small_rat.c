#include <lib.h>
#include "../drazh.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("rat");
  SetId( ({"rat", "creature"}) );
  SetShort("a small rat");
  SetLong(
     "This small rat has its body covered in fur with "
     "a long hairless tail. The rat looks at the world with "
     "its red beady eyes and sniffs around with it long "
     "pink snout."
     );
  SetAdjectives( ({"small"}) );
  
  SetRace("rodent");
  SetClass("animal");
  SetLevel(1);
  SetGender("male");
  SetMorality(0);
  SetAction(5, ({ 
     "!emote stands on his hind paws.", 
     "!sniff." 
     }) );
  SetCombatAction(5, ({ "!hiss." }) );
}
