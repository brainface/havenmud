/*  5/03 Libitina / chipmunk for newbie area / wooded vale  */


#include <lib.h>
inherit LIB_NPC;
static void create() {
    npc::create();
    SetKeyName("chipmunk");
    SetShort("a small chipmunk");
    SetId( ({ "chipmunk" }) );
	  SetAdjectives( ({ "small" }) );
    SetClass("animal");
    SetRace("rodent");
    SetGender("male");
    SetLevel(1);
    SetLong("Brown and grey stripes run from this animal's head down "	
      			"to his tail. His black eyes look forward while his whiskers twitch "
      			"and his tail flicks. He chitters in curiousity, almost too "
      			"cute to hunt."
    				);
 
    SetAction(2, ({
			"!emote chitters nervously.",
			"!emote searches for some food.",
      }) );
    SetCombatAction(2, ({
			"!emote chitters angrily at you.",
			"!emote slashes at you with his long claws.",
			"!emote bites at you with his sharp teeth.",
      }) );
}
