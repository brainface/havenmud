//
//  Snakebite
//  copy of thoin's venomous touch spells
//  Mahkefel 2010
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("snakebite");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
    "natural magic" : 60,
    "evokation"     : 60,
  ]) );
  SetDifficulty(30);
  SetMorality(-5);
  SetAutoDamage(0);
  SetDamageType(PIERCE);
  SetEnhanceSkills( ({ "poison magic" }) );
  SetMessages( ({
    ({ "scratch",
      "$agent_possessive_noun venomous fangs barely%^BOLD%^GREEN%^ $agent_verb%^RESET%^ $target_name."}),
    ({ "pierce",
      "$agent_possessive_noun venomous fangs%^BOLD%^GREEN%^ $agent_verb%^RESET%^ $target_possessive_noun skin."}),
    ({ "strike",
       "$agent_name%^BOLD%^GREEN%^ $agent_verb%^RESET%^ $target_name "
       "viciously with $agent_possessive venomous fangs."}),
  }) );
  SetHelp(
    "With this spell, the caster can grow fangs as a viper and deliver a "
    "venomous bite. "
  );
}

// prevent casting indoors without a natural charge
int CanCast(object who, int level, mixed limb, object *targets) {
  if( (environment(who)->GetClimate() == "indoors") ||
    (environment(who)->GetClimate() == "underground") ){
    if (!present("natural_charge", who)) {
      who->eventPrint("Your spell fizzles and refuses to work in these types of environmental settings.");
      return 0;
     }
  }
  return spell::CanCast(who, level, limb, targets);
}

// broadcast a message to the room
int eventCast(object who, int level, mixed limb, object array targets) {
  send_messages("",
    "$agent_possessive_noun jaw unhinges like a snake and sprouts needle-like fangs, "
    "dripping with %^GREEN%^venom%^RESET%^.", who, targets[0], environment(who)
  );
  return ::eventCast(who, level, limb, targets);
}

// poison targets successfully hit
int eventAfterEffect(object who, int level, mixed limb, object target) {
  int poison = level/7;
  poison += who->GetSkillLevel("poison magic")/20;
  target->AddPoison(poison);
}

