#include <lib.h>
#include <dirs.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
	spell::create();
	SetSpell("swarm");
	SetRules("", "LIV");
	SetDifficulty(55);
	SetSpellType(SPELL_COMBAT);
	SetSkills( ([
	  "natural magic"  : 125,
	  "evokation"      : 125,
	  	]) );
	SetHelp("This spell summons a swarm of wasps to attack a target. It is a highly"
	        " potent spell. \n"
	        "Once the target is dead, the wasps vanish.");
	      }
	      
	      

int CanCast(object who, int level, mixed limb, object array targets)  {
   object target = targets[0];
   int wasps = sizeof(filter(all_inventory(environment(who)), (: living($1) &&
		             $1->GetKeyName() == "wasp" :)));
   int wasp_max = 1 + level/10;
     if(wasps >= wasp_max) {
  	   who->eventPrint("You already have too many wasps.");
  	return 0;
    }
   if (target == who) {
      message("system","Cast it on yourself?", who);
      return 0;
   }
   if(newbiep(target))  {
      message("system", "You can't cast that on a newbie!"
              ,who);
      return 0;
      }
   return spell::CanCast(who, level, limb, targets);

}
	      
varargs int eventCast(object who, int level, mixed n, object *targets) {
	object target = targets[0];
	object wasp;
	string waspstr = DIR_SPELLS "/obj/swarm_wasp";
	int wasps;
	int wasp_max = 1 + level/10;
	 if (wasp_max > 10) wasp_max = 10;
	wasps = sizeof(filter(all_inventory(environment(who)), (: living($1) &&
		             $1->GetKeyName() == "wasp" :)));
	if (who->GetTestChar()) debug("Wasps: " + wasps + " Wasp_max: " + wasp_max);
  }
  send_messages("summon", "$agent_name $agent_verb forth a %^RED%^swarm%^RESET%^ of"
                " wasps to attack $target_name", who, target, environment(who));
	while(wasp_max > wasps) {
		wasp = new(waspstr);
		wasp->eventMove(environment(target));
		wasp->AddFriends(who->GetKeyName());
		wasp->SetOwner(who->GetKeyName());
		wasp->SetAttack(target);
		wasps++;
	}
	return 1;
}
		
