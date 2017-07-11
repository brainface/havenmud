#include <lib.h>
#include <magic.h>
#include <daemons.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("wall of glare");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetHelp("Using this spell causes the target to shine with a brilliant light,
    harming and possibly blinding any who would attack them for a period
    of time."
  );
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  SetDamagingShield(1);
  SetSkills( ([
    "illusion" : 100,
    ]) );
  SetMessages( ({ 
    ({ "weave", "$agent_name $agent_verb a brilliant wall of "
       "%^BOLD%^CYAN%^bright light%^RESET%^ around $agent_reflexive."}),
    ({ /* hit callback */ }),
    ({ /* end callback */ }),
  }) );
}


int hitCallback(object who, object agent, int x, class MagicProtection cl) {
    string colour;
    
    if (who == agent) return 0;
    if( cl->time < 20 ) {
      colour = "%^CYAN%^";
    }
    else {
      colour = "%^BOLD%^CYAN%^";
    }
   send_messages("", 
      "The " + colour + "harsh light %^RESET%^surrounding "
      "$agent_name burns $target_possessive flesh.",
       who, agent, environment(who) );
   if (!random(50)) {
     send_messages("",
       "The light %^BOLD%^YELLOW%^blinds%^RESET%^ $target_name!",
       who, agent, environment(who) );
     agent->eventBlind(who, 10+random(10));
   }
   return x;
}
 
void endCallback(object who) {
  if( who ) {
    send_messages("", 
      "The %^BOLD%^CYAN%^bright light%^RESET%^ around $agent_name fades away.",
    who, 0, environment(who));
  }
}
