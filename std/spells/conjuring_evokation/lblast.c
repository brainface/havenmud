#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create(){
  spell::create();
  SetSpell("lightning blast");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
    "conjuring" : 200,
    "evokation" : 200,
    ]) );
  SetMorality(0);
  SetDifficulty(50);
  SetAutoDamage(0);
  SetDamageType(SHOCK);
  SetEnhanceSkills( ({ "shock magic" }) );
  SetMessages( ({ 
    ({ "blast", 
      "$agent_name $agent_verb $target_name with strong electricity." }),
    ({ "are",
      "$target_name $target_verb %^RED%^burnt%^RESET%^ by " +
      "$agent_possessive_noun lightning blast." }),
    ({ "devastate",
      "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ $target_name with a " +
      "massive blast of electrical power." }),
    }) );
  SetHelp(
    "This advanced spell uses the power of lightning not only to devestate its "
    "target with massive amounts of electricity but to also blind them." 
    );
}

int eventCast(object who, int level, mixed limb, object array targets) {
    object target = targets[0];

    if( CanAttack(who, targets, GetSpellLevel() + level/2) == - 1 ) {
            who->eventPrint("You fail to blind your target.");
            return ::eventCast(who, level, limb, targets);
          }
  if( random(level) > 40 ) {
    target->eventBlind(who, level/10);
    send_messages( ({ "scream", "are" }),
      "$target_name $target_verb as $target_possessive eyes blacken from the electrical power.",
      who, target, environment(who) ); 
    return ::eventCast(who, level, limb, targets);
  }
  return ::eventCast(who, level, limb, targets);
}
