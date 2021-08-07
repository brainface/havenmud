#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("minor hemokinesis");
  SetSpellType(SPELL_HEALING);
  SetSkills( ([
    "vampirism" : 1,
    ]) );
  SetDrinkCost(25,25);
  SetMagicCost(0,0);
  SetRules("");
  SetHelp(
    "Thier dead bodies are far beyond the assistance of simple "
    "first aid, but a vampire can attempt to prevent blood from "
    "leaving their body through direct hemokinesis, forcing "
    "the blood back into their veins.");
  SetDifficulty(20);
}

varargs int CanCast(object who, int level, mixed x, object *t) {
  if (!who->GetBleeding()) { 
    who->eventPrint("You are not bleeding.");
  }
  return (::CanCast(who, level, x, t) && sizeof(t));
}

varargs int eventCast(object who, int level, mixed x, object *t) {
  object target = t[0];
  int amount = random(who->GetSkillLevel("vampirism"));
  int bleed = target->GetBleeding();

  amount *= level/100;
  if (amount < 1) amount = 1;

  target->AddBleeding(-amount);
  if (!amount) {
    send_messages( ({ "swat" }),
      "$agent_name desperately %^BOLD%^WHITE%^$agent_verb%^RESET%^ at "
      "the blood leaving $agent_possessive body, accomplishing a "
      "great deal of nothing.",
      who, target, environment(who) );
    return 1;
  }
  if (amount < bleed) {
    send_messages( ({ "coax" }),
      "$agent_name%^BOLD%^YELLOW%^ $agent_verb %^RESET%^some of "
      "$agent_possessive missing blood back into $agent_possessive body.",
      who, target, environment(who) );
    return 1;
  }
  send_messages( ({ "none" }),
    "$agent_possessive_noun blood flows back into $agent_possessive body "
    "with a%^BOLD%^RED%^ slurping%^RESET%^ noise.",
    who, target, environment(who) );
  return 1;
}
