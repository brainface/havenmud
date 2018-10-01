/*  Aetheric Rift defense spell
 *  Does cool stuff to an attacker...because cool just isn't damage
 *  Thoin@haven
 */
#include <lib.h>
#include <daemons.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;
int ShieldStrike(object who, object agent, int x, class MagicProtection cl);
void endCallback(object who);

static void create() {
  spell::create();
  SetSpell("aetheric rift");
  SetRules("", "LIV");
  SetDamagingShield(1);
  SetUniqueSpell(1);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  SetSpellType(SPELL_DEFENSE);
  SetSkills( ([
     "conjuring" : 400,
     "evokation" : 400,
     ]) );
  SetDifficulty(200);
  SetMorality(0);
  SetHelp(
            "This powerful defense spell protects the caster "
            "from all types of attacks and it also has negative "
            "effects to those who attack those protected by it. However "
            "because of the power and chaotic nature of magic unknown "
            "things may happened."
  );
  SetMessages( ({ 
        ({ ({"pull", "wrap"}),
       "$agent_name $agent_verb %^CYAN%^aether%^RESET%^ from "
       "the air and $agent_verb it around $target_name." }),
    ({ "assault", "The %^BOLD%^CYAN%^aetheric rift"
          "%^RESET%^ around $agent_name %^BOLD%^RED%^shimmers brightly"
        "%^RESET%^ as $target_name $target_verb it!" }),
    
    }) );
}

int CanCast(object who, int level, mixed blah, object *targets){
    object target = targets[0];    
    string *pros = ({ });

    foreach (class MagicProtection pro in target->GetMagicProtection()){
     pros += ({ pro->name });
   }

    if (sizeof(filter(pros, (: $1 == "aetheric rift" :) ) ) > 2){
        message("", "You cannot stack any more of these."
        , who);
        return 0;
    }
  
    return spell::CanCast(who, level, blah, targets);
}
/*
int hitCallback(object who, object agent, int dmg, class MagicProtection cl) {

  if (who == agent) return 0;  
  switch(random(100)) {  
    case 1..80 :
      send_messages("assault", "The %^BOLD%^CYAN%^aetheric rift"
          "%^RESET%^ around $agent_name %^BOLD%^RED%^shimmers brightly"
          "%^RESET%^ as $target_name $target_verb it!",
          who, agent, environment(who) );
       if (agent && living(agent) )
       if (living(agent) && !SPELLS_D->GetDamagingShield(agent))
       agent->eventReceiveDamage(who, MAGIC|SHOCK, who->GetSpellLevel("aetheric rift"));
      break;  
    case 81..90 :
      send_messages("assault", "The %^BOLD%^CYAN%^aetheric rift"
          "%^RESET%^ around $agent_name %^BOLD%^%^WHITE%^flickers quickly%^RESET%^ "
          "as $target_name $target_verb it!",
          who, agent, environment(who) );
       if (agent && living(agent) )
       if (living(agent) && !SPELLS_D->GetDamagingShield(agent))
       agent->eventBlind(4);
      break;
    case 91..100 :
        send_messages("assault", "The %^BOLD%^CYAN%^aetheric rift"
          "%^RESET%^ around $agent_name %^YELLOW%^flashes continuously"
          "%^RESET%^ as $target_name $target_verb it!",
          who, agent, environment(who) );
       if (agent && living(agent) )
       if (living(agent) && !SPELLS_D->GetDamagingShield(agent))
       agent->SetParalyzed(4);
      break;

    default :
        send_messages("assault", "The %^CYAN%^BOLD%^aetheric rift"
          "%^RESET%^ around $agent_name %^BLUE%^ripples slightly"
          "%^RESET%^ as $target_name $target_verb it!",
          who, agent, environment(who) );
      break;  
    }
  return dmg;
  }
*/
void endCallback(object who) {
    if( who ) {
      send_messages("", "The %^BOLD%^CYAN%^aetherial magic%^RESET%^ around"
        " $agent_name fades into the void.",
        who, 0, environment(who));
    }
}
