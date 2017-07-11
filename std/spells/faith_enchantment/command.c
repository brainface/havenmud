/* Mahkefel 2017
 * there were no level 1 faith enchantment spells, wanted to add one
 * knocks down the target
 * pretty big effect but it's going to scale into uselessness soo.
 *
 * also hey! it's an iconic cleric spell from that game.
 */
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("command");
  SetSpellType(SPELL_COMBAT);
  SetRules("", "LIV");
  SetDifficulty(20);
  SetSkills( ([
    "faith" : 1,
    "enchantment" : 1,
    ]) );
  SetHelp("Drawing upon your newfound faith, you command your enemies to "
    "kneel before you and bask in your righteousness. Only the very weak "
    "willed are impressed by this act.");
}

int eventCast(object who, int level, mixed limb, object *targets) {
  object target = targets[0];

  if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
    who->eventPrint("Your powers fail you.");
    return 0;
  }

  send_messages( ({ "point","gesture" }),
    "$agent_name $agent_verb at $target_name and%^BOLD%^YELLOW%^ $agent_verb"
    "%^RESET%^ for $target_objective to kneel!", who, target, environment(who) );

  target->eventCollapse();
  return 1;
}

