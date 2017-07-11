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
  SetSpell("forest banishment");
  SetReligions("Eclat");  
  SetRules("LIV");
  SetSpellType(SPELL_OTHER);
  SetMagicCost(100, 100);
  SetSkills( ([
    "natural magic" : 75,
    "enchantment"   : 75,
  ]) );
  SetStaminaCost(50,50);
  SetDifficulty(70);
  SetMorality(-30);
  SetHelp(
   "Used by the most powerful Eclat Druids, this "
   "spell allows them to channel powerful energy from "
   "the forest plane to banish their target to a random "
   "spot in that dreadful lower plane.");
}

int CanCast(object who, int level, string limb, object *targets) {
  object target = targets[0];

  if (!sizeof(targets)) { 
     targets=who->GetCurrentEnemy();
    }
  if( creatorp(target) )
  {
    who->eventPrint("How dare you even THINK to banish an immortal!");
    return 0;
  }
  if( environment(who)->GetProperty("no teleport") ||
    environment(who)->GetProperty("no attack") ) {
	who->eventPrint("You can not do that here.");
	return 0;
	}
  return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets)
{
  int x = random(100)+1;
  int y = random(100)+1;
  string location = DOMAIN_PLANES "virtual/forest/" + x + "," + y;
  object target = targets[0];
  if (x >= -2 && x <= 2) x = 49;
  if (y >= -2 && y <= 2) x = 49;
  if( target->GetLevel() + random(100) < who->GetLevel() + (level/3) ) {
    send_messages( ({ "call", "banish" }), "$agent_name $agent_verb energy "
      "from nature and $agent_verb $target_name "
      "to the endless Forest Plane!", who, target, environment(target) );
    target->eventMoveLiving(location,
      "$N is banished into the endless Forest Plane by "+ who->GetCapName()+
      "!", "$N enters the Forest Plane from nowhere, banished there by " +
      who->GetKeyName() + "!");
    return 1;
  }
  if( !random(20) ) {
    send_messages( ({"call", "attempt", "fail", "are"}), 
      "$agent_name $agent_verb energy from nature, and $agent_verb to banish $target_name, but "
      "$agent_verb and $agent_verb taken away to the forest plane!", who, target,
      environment(who));
    who->eventMoveLiving(location, "$N is taken away into the "
	  "endless Forest.", "$N enters the Forest Plane from "
	  "nowhere, banished by "+possessive(who)+" own failure.");
    return 1;
  }
  send_messages("fail",
    "$agent_name $agent_verb to banish $target_name.",
    who, target, environment(who) );
  return 1;
}


