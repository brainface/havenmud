/* ----------------------------------------------------------------------- */
// Filename: r_paralysis.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Oct 6th, 1998
// Abstract: This is a healing spell that will remove paralysis from a 
//           targeted creature.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;
static void create() {
  spell::create();
  SetSpell("remove paralysis");
  SetRules("LIV");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
    "healing" : 20,
    "faith"   : 20,
    ]) );
  SetDifficulty(35);
  SetMagicCost(50, 30);
  SetHelp(
          "Powerful healers can utilize this spell to cure paralysis "
          "from the targeted creature."
    );
  }

varargs int eventCast(object who, int level, mixed useless, object array targets) {
   object target = targets[0];
   int chance = (this_player()->GetSkillLevel("healing")/5);

  int is_paralyzed = target->GetParalyzed();

  if (is_paralyzed == 0) {
     send_messages("have",
        "$agent_possessive_noun spell has no effect on $target_name.",
         who, target, environment(who) );
      return 1;
      }
  else {
      target->AddParalyzed(-chance);
      send_messages("begin", 
         "$agent_possessive_noun magic has successfully removed some of "
         "the paralysis $target_possessive_noun body!",
          who, target, environment(who) );
       return 1;
      }
    }


/* Approved by Morgoth on Sun Oct 11 01:51:14 1998. */
