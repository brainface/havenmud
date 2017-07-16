#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("unshackle servant");
  SetSpellType(SPELL_OTHER);
  SetRules("");
  SetHelp(
    "Even necromancers know some mercy. With this spell, they release "
    "their servant from bondage, wherever they are, allowing their spirit "
    "to pass on and the corpse to return to its natural, still state. "
    "The more callous and jaded may say this incantation is for when a dark "
    "wizard simpy simply can't be bothered to find and personally dismiss "
    "their undead abominations."
    );
  SetMagicCost(100, 100);
  SetStaminaCost(50, 50);
  SetDifficulty(50);
  SetSkills( ([
    "necromancy" : 50,
  ]) );
}


varargs int eventCast(object who, int level, mixed u, object *t) {
  object zombie;
  object zombie_env;
  string file = who->GetProperty("animate_zombie");

  if (!file) {
    who->eventPrint("You find no zombies beholden to you.");
    return 1;
  }
  if (!zombie = find_object(file)) {
    who->eventPrint("Your zombie has returned to the realm of the dead.");
    who->RemovePermanentProperty("animate_zombie");
    return 1;
  }
  if (!zombie_env = environment(zombie)) {
    zombie->eventDestruct();
    who->eventPrint("Your zombie has returned to the realm of the dead.");
    who->RemovePermanentProperty("animate_zombie");
    return 1;
  }
  who->eventPrint("Closing your eyes to locate your loyal servant"
    + ", you visualize " + zombie->GetShort() + 
    " collapsing into a heap of dust and bones, and it does.");
  zombie->eventForce("emote suddenly collapses into a heap of dust and bones!");
  zombie->eventDestruct();
  who->RemovePermanentProperty("animate_zombie");
  return 1;
}

