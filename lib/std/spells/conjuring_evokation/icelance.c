#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("ice lance");
   SetSpellType(SPELL_COMBAT);
   SetRules("", "LIV");
   SetSkills( ([
      "conjuring" : 350,
      "evokation" : 350,
   ]) );
   SetAutoDamage(0);
   SetDifficulty(100);
   SetDamageType(COLD|PIERCE|MAGIC);
   SetEnhanceSkills( ({ "ice magic" }) );
   SetMessages( ({ 
    ({ "nick", 
      "$agent_name $agent_verb $target_name with a small %^BLUE%^ice%^RESET%^ "
      "lance." }),
    ({ "skewer",
      "$agent_name $agent_verb $target_name with a large %^BOLD%^%^BLUE%^ice lance%^RESET%^. "}),
    ({ "impale",
      "$agent_name%^BOLD%^%^RED%^ $agent_verb%^RESET%^ $target_name with a perfectly formed " +
      "%^BOLD%^%^BLUE%^ice lance%^RESET%^." }),
    }) );
   SetHelp(
           "A ice mage's best attack spell, it offers extreme destructive powers "
           "as well as has a chance to freeze the target.");
}

int eventCast(object who, int level, string limb, object *targets) {
  object target = targets[0];
  
   if( CanAttack(who, targets, GetSpellLevel() + level/2) == - 1 ) {
            return ::eventCast(who, level, limb, targets);
          }
  if( random(level) > 80 ) { 
          send_messages("freeze", "$agent_name $agent_verb "
                     "$target_name with a  %^BLUE%^blast%^RESET%^ of frozen air."
                     ,who,targets,environment(who));
          targets->SetParalyzed(4);
   return ::eventCast(who, level, limb, targets);
  }
 return ::eventCast(who, level, limb, targets);
}
