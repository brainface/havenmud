#include <lib.h>
#include <daemons.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
spell::create();
SetSpell("miasmic guardian");
SetRules("");
SetProtectionTypes(ALL_EXTERNAL);
SetDamagingShield(1);
SetShieldType(SHIELD_TIMED);
SetSpellType(SPELL_DEFENSE);
SetSkills( ([
   "faith" : 200,
   "necromancy" : 200,
   ]) );
SetDifficulty(125);
SetMorality(-10);
SetHelp(
       "The miasmic guardian shield spell allows a Soirin pries to"
       " summon forth a dense cloud of poisonous gas to enshroud"
       " them providing protection from all types of damage for"
       " a limited amount of time."
       );
 SetMessages( ({
    ({ ({"call", "enshroud" }),
     "$agent_name $agent_verb forth a %^BLACK%^miasmic guardian%^RESET%^ to"
     " $agent_verb $agent_reflexive"}),
    ({ ({"condense", "strike"}),
     "The %^BLACK%^miasmic guardian%^RESET%^ around $agent_name $agent_verb"
    " as $target_name $target_verb it."}),
   }) );
  }
  
int hitCallBack(object who, object agent, int dmg, class MagicProtection cl) {
  if (who == agent) return 0;
  switch(random(100)) {
  case 1..75 :
      send_messages({"condense", "strike"}),
           "The %^BLACK%^miasmic guardian%^RESET%^ around $agent_name $agent_verb"
           " as $target_name $target_verb it.",
        who, agent, environment(who));
       break;
   case 76..85 :
       send_messages("spew", "The %^BLACK%^miasmic guardian%^RESET%^ around"
          " $agent_name $agent_verb forth a poisonous cloud as it is struck"
          " by $target_name.",
          who, agent, environment(who));
       environment(who)->AddPoisonGas(random(5));
       break;
   case 86..95 :
         send_messages(({"defile", "strike"}), "$agent_name_possessive"
            " %^BLACK%^miasmic guardian %^RESET%^ $agent_verb $target_name"
            " as $target_nominative $target_verb it.",
          who, agent, environment(who));
        agent->AddPoison(random(5));
        break;
   case 96..100 :         
       send_messages("respond", "The %^BLACK%^miasmic guardian%^RESET%^ around"
           " $agent_name $agent_verb aggressively to the attack by $target_name.",
           who, agent, environment(who));
          if (living(agent) && !SPELLS_D->GetDamagingShield(agent))
            agent->eventReceiveDamage(who, MAGIC|POISON, who->GetSpellLevel("miasmic guardian"));
            break;
      default :
      send_messages({"condense", "strike"}),
           "The %^BLACK%^miasmic guardian%^RESET%^ around $agent_name $agent_verb"
           " as $target_name $target_verb it.",
        who, agent, environment(who));
       break;      
          }
          return dmg;
       }
