/*  Ranger Sleep Spell
 * Created 12 Sept 1997
 * Duuktsaryth@Haven
 */
#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;
static void create() {
  spell::create();
  SetSpell("soothe");
  SetRules("LIV");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
    "natural magic" : 25,
    "enchantment" : 25,
    ]) );
  SetDifficulty(12);
  SetMagicCost(20,10);
  SetRequiredStamina(20);
  SetMagicCost(10, 10);
  SetRequiredMagic(30);
  SetHelp(
          "Slows down and possibly puts a living target to sleep."
    );
  }

varargs int eventCast(object who, int level, mixed useless, object array targets) {
   object target = targets[0];
  int my_level = who->GetSkillLevel("natural magic");
  int target_level = target->GetLevel();
  int time;
  my_level = my_level /4;
  time = my_level - target_level;

  if (time < 1) {
     send_messages("have",
        "$agent_possessive_noun spell has no effect on $target_name.",
         who, target, environment(who) );
      return 1;
      }
  if (time < 5) {
      send_messages("doze", 
         "$target_name $target_verb off into a light slumber.",
          who, target, environment(who) );
       target->eventCollapse();
       target->SetSleeping(time);
       target->SetParalyzed(time);
       return 1;
      }
   if (time < 10) {
        send_messages("drift",
           "$target_name $target_verb into a deep sleep.",
            who, target, environment(who) );
       target->eventCollapse();
         target->SetSleeping(time);
         target->SetParalyzed(time);
         return 1;
        }
    send_messages("thump",
       "$target_name $target_verb to the ground in a deep magical sleep.",
         who, target, environment(who) );
    target->eventCollapse();
       target->SetSleeping(time);
       target->SetParalyzed(time);
        return 1;
    }


/* Approved by Duuktsaryth on Sun Sep 14 22:58:59 1997. */
