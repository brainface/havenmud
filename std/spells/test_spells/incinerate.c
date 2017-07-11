#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("incinerate");
   SetSpellType(SPELL_COMBAT);
   SetRules("", "LIV");
   SetUniqueSpell(1);
   SetSkills( ([
      "conjuring" : 500,
      "evokation" : 500,
   ]) );
   SetAutoDamage(0);
   SetDifficulty(150);
   SetDamageType(HEAT);
  SetEnhanceSkills( ({ "fire magic" }) );
  SetMessages( ({ 
    ({ "blast", 
      "$agent_name $agent_verb $target_name with intense %^RED%^flames%^RESET%^ "
      "burning $target_name badly." }),
    ({ "are",
      "$target_name $target_verb %^RED%^immolated%^RESET%^ by  " +
      "$agent_possessive_noun fiery explosion." }),
    ({ "incinerate",
      "$agent_name%^BOLD%^%^RED%^ $agent_verb%^RESET%^ $target_name with a " +
      "deadly blast of flames." }),
    }) );
  SetHelp(
           "A fire mage's best attack spell, it offers extreme destructive powers "
           "as well as has a chance to melt the targets weapons.");
}

int eventCast(object who, int level, string limb, object *targets) {
  object target = targets[0];
   int num = who->GetSkillLevel("evokation")/20;
   object array eq = target->GetWielded();
  
   if( CanAttack(who, targets, GetSpellLevel() + level/2) == - 1 ) {
            return ::eventCast(who, level, limb, targets);
          }
  if( random(level) > 90 ) { 
   for(int i=0;i<num;i++) {
      if(sizeof(eq)) {
         object thing = (eq[random(sizeof(eq))]);
            send_messages("cause", "$agent_name $agent_verb "
                          "$target_possessive "+
                           remove_article(thing->GetShort())+" to disintegrate into ash!",who, 
                           target, environment(who));
            thing->eventDestruct();
      }
    }
   return ::eventCast(who, level, limb, targets);
  }
 return ::eventCast(who, level, limb, targets);
}
