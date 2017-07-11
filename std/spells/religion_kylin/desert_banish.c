//
// The Desert Banishment Spell
// Banishes someone to a random spot in the Yozrath Desert
// Created by Zaxan@Haven
// made to work by vivake gupta (dunedain@haven)
// Altered by Morgoth@Haven to fix several balance issues
//

#include <lib.h>
#include <magic.h>
#include <domains.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("desert banishment");
  SetRules("LIV");
  SetSpellType(SPELL_OTHER);
  SetRequiredMagic(200);
  SetMagicCost(100,100);
  SetSkills( ([
    "faith"       : 50,
    "evokation" : 50,
  ]) );
  SetReligions("Kylin");
  SetRequiredStamina(100);
  SetStaminaCost(50,50);
  SetDifficulty(70);
  SetMorality(-30);
  SetHelp(
   "Used by the most powerful Desert Kylin clerics, this "
   "spell allows them to channel powerful energy from "
   "Duuktsaryth to banish their target to a random "
   "spot in the mighty desert.");
}

int CanCast(object who, int level, string limb, object *targets) {
  object target = targets[0];

  if (!sizeof(targets)) { 
     targets = ({ who->GetCurrentEnemy() });
    }
  if(creatorp(target)) {
    who->eventPrint("How dare you even THINK to banish an immortal!");
    return 0;
  }
  if( environment(who)->GetProperty("no teleport") || environment(who)->GetProperty("no attack") ) {
	  who->eventPrint("You can not do that here.");
	  return 0;
	}
  return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets) {
  int x = random(100)+1;
  int y = random(100)+1;
  string location = YOZRATH_VIRTUAL "desert/" + x + "," + y;
  object target = targets[0];
  if (x >= -2 && x <= 2) x = 49;
  if (y >= -2 && y <= 2) x = 49;
  if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
	    who->eventPrint("Your powers fail you.");
	    send_messages( ({"call", "attempt", "fail", "are"}), 
        "$agent_name $agent_verb energy from He Who Judges, and $agent_verb "
        "to banish $target_name, but $agent_verb and $agent_verb taken away to the desert.", 
        who, target, environment(who));
      who->eventMoveLiving(location, 
        "$N is taken away into the endless Yozrath Desert.", 
        "$N enters the Yozrath Desert from nowhere, banished by "+ possessive(who)+ " own failure."
        );
      return 1;
      }
	send_messages( ({ "call", "banish" }), 
	  "$agent_name $agent_verb energy from He Who Judges, and $agent_verb $target_name "
    "to the endless Yozrath Desert!", who, target, environment(target) );
  target->eventMoveLiving(location,
      "$N is banished into the endless Yozrath Desert by "+ who->GetCapName() + "!", 
      "$N enters the Yozrath desert from nowhere, banished there by " + who->GetKeyName() + "!"
      );
  return 1;
}
  
