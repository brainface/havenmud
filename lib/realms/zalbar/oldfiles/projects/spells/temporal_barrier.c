/* ----------------------------------------------------------------------- */
// Filename: temporal_barrier.c
// Author: Derek Noble
// Immortal: Dylanthalus@haven (with help from Zeddicus)
// Creation Date: April 16th, 1999
// Abstract: This is the ultimate high level shield for mages.  Being that 
//           all new mages have planar magic as a primary skill, eventually 
//           all mages should be able to learn this spell.  Unlike most 
//           other defense spells, this spell improves with the knowledge 
//           the cast has in planar magic and conjuring.  At first, the 
//           spell is slightly overbalanced.  To the degree of an extra 2
//           points in SetProtectionTime(), however, as the mage improves 
//           his knowledge of the relevant skills, the spell becomes 
//           underbalanced.  No Magical Shield should exceed this spell as
//           this is the ultimate magical defense spell for mages.
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;
int ShieldStrike(object who, object agent, int x, class MagicProtection cl);
void endCallback(object who);

static void create() {
  spell::create();
  SetUniqueSpell(1);
  SetSpell("temporal barrier");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetShieldType(SHIELD_TIMED);
  SetProtectionTypes(ALL_EXTERNAL);
  SetSkills( ([     
    "conjuring" : 300,
    "evokation" : 300,
    ]) );
  SetDifficulty(200);
  SetHelp(
    "The temporal barrier spell is a prize for any mage with the ability "
    "to cast it.  It has the ability to defend against all external forms of damage for "
    "an extended period of time while still being effective at blocking "
    "an impressive amount of damage."
    );    
  SetMessages( ({
  	({ "",  "A %^MAGENTA%^BOLD%^temporal barrier %^RESET%^MAGENTA%^ripples slightly%^RESET%^ as it surrounds $target_name." }),
  	({ /* This should be handled by hitCallback */ }),
  	({ /* This should be handled by endCallBack */ }),
  	}) );
  	   
 }

int hitCallback(object who, object agent, int dmg, class MagicProtection cl) {
  if (who == agent) return 0;  
  switch(random(3)) {
    case 0:
      send_messages("assault", "The %^MAGENTA%^BOLD%^temporal barrier"
          "%^RESET%^ around $agent_name %^BOLD%^WHITE%^flares brightly"
          "%^RESET%^ as $target_name $target_verb it!",
          who, agent, environment(who) );
      break;
    case 1:
        send_messages("assault", "The %^MAGENTA%^BOLD%^temporal barrier"
          "%^RESET%^ around $agent_name %^MAGENTA%^ripples continuously"
          "%^RESET%^ as $target_name $target_verb it!",
          who, agent, environment(who) );
      break;
    case 2:
      send_messages("assault", "The %^MAGENTA%^BOLD%^temporal barrier "
          "%^RESET%^around $agent_name %^CYAN%^flickers suddenly%^RESET%^ "
          "as $target_name $target_verb it!",
          who, agent, environment(who) );
      break;
    }
  return dmg;
  }

void endCallback(object who) {
    if( who ) {
      send_messages("", "The %^BOLD%^CYAN%^temporal barrier%^RESET%^ around"
        " $agent_name ripples as it ceases to exist.",
        who, 0, environment(who));
    }
}


/* Approved by Dylanthalus on Thu May  6 23:11:53 1999. */
