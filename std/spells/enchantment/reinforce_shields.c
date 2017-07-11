// mahkefel 2010                                             
//   give casters something to do when riding                
//   along in a boat.                                        

#include <lib.h>
#include <dirs.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();    
  SetSpell("reinforce shields");
  SetRules("");                 
  SetSpellType(SPELL_OTHER);    
  //SetRequiredMagic(270);      
  SetSkills( ([                 
     "enchantment" : 200,       
  ]) );
  SetDifficulty(40);
  SetMorality(0);
  SetHelp(
    "With this spell the caster can reinforce damaged shields "
    "on a sailing vessel, attempting to restore them to full "
    "operation even under the duress of combat. "
    "
You must be aboard a ship to use this spell."
  );
}

int CanCast(object who, int level, mixed limb, object *targets) {
  object ship;
  string *systems;

  ship = environment(who);
  if (!ship) return 0;
  systems = ship->GetDamagedSystems();
  if (!systems) {
    who->eventPrint("But you aren't aboard a ship!");
    return 0;
  }
  if ( !ship->GetShieldSystem() ) {
    who->eventPrint("But this ship has no shield system!");
    return 0;
  }
  if (member_array("shield",systems) == -1) {
    who->eventPrint("But the shields aren't damaged!");
    return 0;
  }
  return spell::CanCast(who, level, limb, targets);
}

varargs int eventCast(object who, int level, mixed blah, object *targets) {
  object ship;
  int success;
 
  ship = environment(who);
  if (!ship) return 0;

  success = who->eventCheckSkill("enchantment",
    150 - (ship->GetDamagePoints() * 100 / ship->GetMaxDamagePoints()),
    0,
    100);
  if (success) {
    send_messages("touch", "$agent_possessive_noun hand glows with a "
      "fierce %^BOLD%^BLUE%^light%^RESET%^ as $agent_possessive "
      "$agent_verb the deck of the ship, and the shields hum with "
      "power once more.", who, 0, environment(who));
    ship->RemoveDamagedSystem("shield");
  } else {
    send_messages("falter", "$agent_possessive $avent_verb "
      "in $agent_possessive chant and sends bolts of "
      "%^BOLD%^BLUE%^energy%^RESET%^ coursing through "
      "the ship's hull!", who, 0, environment(who));
    ship->eventReceiveDamage(0, MAGIC,
      random(who->GetSkillLevel("enchantment")*5));
  }

  return 1;
}
