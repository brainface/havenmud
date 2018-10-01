#include <lib.h>
#include "../drazh.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("rat");
  SetId( ({"rat", "creature"}) );
  SetShort("a giant rat");
  SetLong(
     "This hairy creature is a very large with its body covered "
     "in fur with a long hairless tail. The creature looks more "
     "like a small dog than a giant rat.");
  SetAdjectives( ({"giant"}) );
  
  SetRace("rodent");
  SetGender("male");
  SetClass("animal");
  SetLevel(4);
  SetMorality(0);
  SetAction(5, ({ 
     "!emote stands on his hind paws.", 
     "!sniff." 
     }) );
  SetCombatAction(5, ({ "!growl." }) );
  }
