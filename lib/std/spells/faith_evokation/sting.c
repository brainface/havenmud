/*
 * Somebody wrote this 20 years ago
 */
// mahk 2018 omg it's called sting i'm changing it from fire to poison magic
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("sting");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
    "evokation" : 10,
    "faith" : 10,
    ]) );
  SetRules("", "LIV");
  SetAutoDamage(0);
  SetDamageType(MAGIC);
  SetEnhanceSkills( ({ "poison magic" }) );
  SetDifficulty(10);
  SetHelp("This is the first combat spell taught to all new clerics. "
          "It is not highly effective.");
  SetMessages( ({
    ({ "create",
          "$agent_name $agent_verb a %^RED%^small stinger%^RESET%^ against "
          "$target_name." }),
    ({ "attack",
          "$agent_name $agent_verb $target_name with a small %^RED%^sting%^RESET%^."
          }),
    ({ "sting",
          "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_name with "
          "$agent_possessive magic!",
          }),
     }) );
}

