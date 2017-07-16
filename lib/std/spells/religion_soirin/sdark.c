#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("stab in the dark");
  SetRules("","LIV");
  SetSpellType(SPELL_COMBAT);
  SetDifficulty(10);
  SetSkills( ([
      "evokation" : 50,
      "faith" : 50,
    ]) );
  SetReligions("Soirin");
  SetHelp(
          "This spell harnesses the art of deception and backstabbing"
          " into one masterful stroke for a Soirin priest. Drawing upon"
          " the greatest acts of assassination in history, this spell will"
          " attempt to pierce the target with a chance of introducing"
          " poison into their bloodstream.");
  SetDamageType(POISON);
  SetEnhanceSkills( ({ "poison magic" }) );
  SetAutoDamage(0);
  SetMessages( ({
    ({ "evade", "$target_name $target_verb $agent_possessive_noun "
                   "stab in the dark with ease." }),
    ({ "summon", "$agent_name $agent_verb a field of energy, "
                 "that pierces $target_name skin."}),
    ({ "summon", "$agent_name $agent_verb a deadly, knife-shaped surge "
                 "of energy that penetrates $target_possessive_noun back." }),
    }) );
 }

varargs int eventCast(object who, int level, mixed x, object *tars) {
  if (!(random(25))) {
    send_messages( ({ "look" }),
       "$agent_name $agent_verb sick!",
       tars[0], who, environment(who) );
    tars->AddPoison(who->GetSkillLevel("faith")/25);
    }
  ::eventCast(who, level, x, tars);
  }
