#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("mind stab");
  SetSpellType(SPELL_COMBAT);
  SetDamageType(MAGIC);
  SetRules("", "LIV");
  SetHelp(
    "A novice illusionist can cause all to real wounds with a crude "
    "illusionary weapon, though stronger minds tend to be unimpressed."
          );
  SetSkills( ([
    "illusion" : 20,
    ]) );
  SetEnhanceSkills( ({ "ice magic" }) );
  SetAutoDamage(0);
  SetMessages( ({
    ({ "stare",
      "$agent_name%^CYAN%^ $agent_verb%^RESET%^ intently at $target_name, as if waiting for something to happen."}),
    ({ "fling",
      "$agent_name%^BOLD%^CYAN%^ $agent_verb%^RESET%^ an illusory knife at $target_name, mildly discomfiting $target_objective!"}), 
    ({ "stab",
      "$agent_name%^BOLD%^MAGENTA%^ $agent_verb%^RESET%^ $target_name with a %^BOLD%^CYAN%^phantasmal dagger!%^RESET%^"}),
  }) );
  SetDifficulty(5);
}

// broadcast a message to the room
// all this does is make them emote the correct body part.
int eventAfterEffect(object who, int level, string limb, object array target) {
  send_messages( ({ "scream", "clutch" }) ,
    "$target_name $target_verb and $target_verb $target_possessive " + limb + "!",
    who, target, environment(who)); 
}

