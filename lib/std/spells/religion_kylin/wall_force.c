
/*  Wall of Force defense spell
 *  Does cool stuff to an attacker ;)
 */
#include <lib.h>
#include <daemons.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("wall of force");
  SetRules("", "LIV");
  SetDamagingShield(1);
  SetReligions("Kylin");
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  SetSpellType(SPELL_DEFENSE);
  SetSkills( ([
     "faith"       : 100,
     "evokation" : 100,
     ]) );
  SetDifficulty(20);
  SetMorality(0);
  SetHelp(
            "This spell instills the target (or caster) with an "
            "invisible wall of protection against damage of all "
            "types. It also has negative effects on someone that "
            "attacks anyone thus protected."
  );
  SetMessages( ({ 
  	({ "appear",
       "$target_name $target_verb %^BLUE%^protected%^RESET%^ by the "
       "divine touch of the Lord of Balance." }),
    ({ /* Handled by hitCallBack */ }),
    ({ /* handled by endCallBack */ }),
    }) );
}


int hitCallback(object who, object agent, int x, class MagicProtection cl) {
    string colour;
    
    if (who == agent) return 0;
    if( cl->time < 20 ) {
    	colour = "%^BLUE%^";
    }
    else {
	    colour = "%^BOLD%^BLUE%^";
    }
   send_messages("", 
      "The " + colour + "wall of force %^RESET%^protecting "
      "$agent_name responds to $target_possessive attacks.",
       who, agent, environment(who) );
/*  if (agent && living(agent) )
  if (living(agent) && !SPELLS_D->GetDamagingShield(agent))
  agent->eventReceiveDamage(who, MAGIC, who->GetSpellLevel("wall of force"), 0, agent->GetRandomLimb()); */
    return x;
}
 
void endCallback(object who) {
    if( who ) {
   send_messages("", 
      "The %^BLUE%^wall of force%^RESET%^ around $agent_name vanishes.",
      who, 0, environment(who));
    }
}


/* Approved by Duuktsaryth on Mon Sep  8 15:49:46 1997. */
