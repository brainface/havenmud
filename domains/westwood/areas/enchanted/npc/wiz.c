// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;
#include "balz.h"

int CheckPerson();

static void create() {
   npc::create();
   SetKeyName("wizard");
   SetId( ({ "old wizard","wizard" }) );
   SetShort("an old wizard");
   SetLong("Old and wrinkled, the golem wizard appears to have been "
           "fashioned long ago out of a hunk of wood.  He appears to "
	   "wear "
           "wrinkled, unkempt clothing, but closer observation "
	   "reveals his clothing to be no more than patterns carved "
           "into the wood.  Odd stains, "
           "suggestive of chemical spills, mark his body.");
   
   
   SetSpellBook( ([
		  "aura"     : 100,
			"buffer"   : 100,
			"missile"  : 100,
			"ice ball" : 100,
			]) );
   SetRace("golem");
   SetClass("evoker");
   SetSkill("blunt combat",1,1);
   SetLevel(random(2)+5);
   SetGender("male");
   SetInventory( ([
      B_OBJ + "/branchc" : "wield branch",
      B_OBJ + "/gleaf" : random(4),
      B_OBJ + "/sleaf" : random(5),
      ]) );
   SetAction(5, ({ 
   		"The wizard cackles insanely.",
   		"The wizard mutters something about his beautiful trees.",
   		"The wizard looks around and growls at the floor.",
		  "!cast aura",
		  "!cast buffer",
		  }) );
   SetCombatAction(60, ({ 
   	"The wizard screams insanely.",
   	"!yell Stay away from my trees!",
		"!cast missile",
		"!cast ice ball",
		"!cast buffer",
		"!cast aura",
		}) );
   SetEncounter( (: CheckPerson :) );
   SetMorality(-175-random(50));
}

int CheckPerson() {
   if( (creatorp(this_player()))) return 0;
   if( (living(this_player())) && this_player()->GetLevel() >= 8) return 1;
   else return 0;
}