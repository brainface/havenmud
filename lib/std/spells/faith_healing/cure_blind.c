/* ----------------------------------------------------------------------- */
// Filename: cure_blind.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Oct 10th, 1998
// Abstract: This is a healing spell that will cure blindness.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;
static void create() {
  spell::create();
  SetSpell("cure blindness");
  SetRules("", "LIV");
  SetSpellType(SPELL_HEALING);
  SetSkills( ([
    "healing" : 40,
    "faith"   : 40,
    ]) );
  SetDifficulty(25);
  SetHelp(
          "This powerful healing spell cures blindness within a target "
          "if one is specified or within the caster if not."
    );
  }

varargs int eventCast(object who, int level, mixed useless, object array targets) {
   object target = targets[0];

  int is_blind = target->GetBlind();

  if (is_blind == 0) {
     send_messages("have",
        "$agent_possessive_noun spell has no effect on $target_name.",
         who, target, environment(who) );
      return 1;
      }
  else { 
      target->eventRestoreSight(who, who->GetSkillLevel("healing")/5);
      send_messages("pray", 
         "$agent_name $agent_verb for the restoration of $target_possessive_noun vision!",
          who, target, environment(who) );
       return 1;
      }
    }


/* Approved by Dylanthalus on Sat Nov 28 04:15:43 1998. */
