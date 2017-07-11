/*  A spell to warp wood
 */
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("warp wood");
  SetSpellType(SPELL_OTHER);
  SetRules("OBJ");
  SetRequiredMagic(80);
  SetMagicCost(40,40);
  SetSkills( ([
     "natural magic" : 10,
      "enchantment" : 10,
     ]) );
  SetDifficulty(15);
  SetHelp(
          "Attempts to destroy a given wooden object.");
  }

varargs int eventCast(object who, int level, mixed n, object *t) {
  object target = t[0];
  if(member_array("wood", target->GetMaterials()) == -1) {
     send_messages("fail", "$agent_name $agent_verb with a spell.",
           who, 0, environment(who) );
       return 0;
     }
  if(random(100) < level) {
    send_messages( ({ "study", "watch" }),
       "$agent_name $agent_verb on $target_name and $agent_verb "
       "as it warps and twists.",
       who, target, environment(who) );
       target->eventDeteriorate();
        return 1;
        }
  send_messages( ({ "study" }),
      "$agent_name $agent_verb on $target_name, but nothing happens.",
       who, target, environment(who) );
  return 1;
  }
