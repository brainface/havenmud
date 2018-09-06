#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include <daemons.h>
#include <dirs.h>
#include "../hive.h"

inherit LIB_CONTROLLER;

int HelpMe();
void CombatStuffs();

static void create() {
	::create();
	SetKeyName("xurlchi");
	SetId( ({ "matron", "hive_queen", "queen" }) );
	SetShort("Xurlchi the Hive Matron");
	SetAdjectives( ({ "hive" }) );
	SetLong("");
	SetRace("thri-kreen");
	SetGender("female");
	SetMorality(0);
	SetClass("fighter");
	SetLevel(125);
	SetCombatAction(99, (: CombatStuffs :) );
}

int HelpMe() {
  object *guards = ({ });
  object who = this_player();
  int guard_num;
  
  debug("Working HelpMe, Stage 1: " + who->GetKeyName());
  guards = filter(all_inventory(environment(who)), (: living($1) && $1->GetKeyName() == "queens guard" :));
  guard_num = sizeof(guards);
  debug("guard_num: " + guard_num + " guards: " + sizeof(guards));
  if (sizeof(guards) > 4) return 0;
  switch(random(2)) {
  	case 0:
  	 who->eventForce("yell Guards! To me! Protect your Mother!");
  	break;
  	case 1:
  	who->eventForce("yell Your Matron is under attack! Swarm to protect your Mother!");
  	break;
  }
  environment(who)->eventPrint("More guards shuffle into the room.");
  debug("Working HelpMe, Stage 2");
  while(guard_num < 6) {
    new(HIVE_NPC "queen_guard")->eventMove(environment());
    guard_num++;
  }
  return 1;
}
void CombatStuffs() {

	switch(1) {
		case 1:
		HelpMe();
		break;
	}
}
