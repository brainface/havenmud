// Mahkefel 2014: elemental spell for rath cult
// hits target with random element from elemental chaos or whatever

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

int GetRandomElement() {
  int element;
  switch(element = random(4)) {
    case 0:
      element = COLD;
      break;
    case 1:
      element = HEAT;
      break;
    case 2:
      element = SHOCK;
      break;
    default:
      element = POISON;
      break;
  }
  return element;
}

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("primordial leak");
  SetSpellType(SPELL_COMBAT);
  SetRules("", "LIV");
  SetSkills( ([
    "faith" : 15,
    "evokation" : 15,
  ]) );
  SetMorality(0);
  SetDifficulty(20);
  SetAutoDamage(0);
  SetDamageType(GetRandomElement());
  SetEnhanceSkills( ({ "fire magic", "ice magic",
    "shock magic", "poison magic" }) );
  SetHelp(
    "With this forbidden spell, followers of the Rath Cult can form a weak "
    "connection to the primordial from which Rath draws his power. Contact "
    "with so power is rarely healthy nor predictable, but can usually be "
    "pointed in the direction of an enemy"
  );
}

// broadcast a message to the room
int eventCast(object who, int level, string limb, object array targets) {
  int result;
  object target = targets[0];
  int damage_type = GetRandomElement();
  send_messages("open",
    "$agent_name $agent_verb holds $agent_possessive hands in front of "
    "$agent_objective and a small but ominous %^BOLD%^BLACK%^vortex%^RESET%^ "
    "opens.", who, target, environment(who));
  if(damage_type == COLD) {
    SetEnhanceSkills( ({"ice magic"}) );
    SetMessages( ({
      ({ "are", "$target_name $target_verb mildly inconvenienced by a spray "
         "of smelly goop from the vortex." }),
      ({ "are", "$target_name $target_verb coated in a deep layer of "
        "%^BOLD%^CYAN%^frost %^RESET%^ that sprays from the vortex!" }),
      ({ "", "Hail and ice spew from the vortex, "
        "%^BOLD%^CYAN%^freezing%^RESET%^ $target_name!"}),
    }) );
  } else if (damage_type == HEAT) {
    SetEnhanceSkills( ({"fire magic"}) );
    SetMessages( ({
      ({ "are", "$target_name $target_verb mildly inconvenienced by a spray "
         "of smelly goop from the vortex." }),
      ({ "are", "$target_name $target_verb singed by a spray of soot and "
        "smoke %^BOLD%^BLACK%^spewing%^RESET%^ from the vortex!" }),
      ({ "", "Fire and spoke erupt from the vortex, "
        "%^BOLD%^RED%^igniting%^RESET%^ $target_name!"}),
    }) );
  } else if (damage_type == SHOCK) {
      SetEnhanceSkills( ({"shock magic"}) );
      SetMessages( ({
        ({ "are", "$target_name $target_verb mildly inconvenienced by a spray "
           "of smelly goop from the vortex." }),
        ({ "are", "A sudden spray of sparks spray from the vortex, "
          "$^BOLD%^YELLOW%^shocking%^RESET%^ $target_name!" }),
        ({ "", "Ozone spews from the vortex as a tiny bolt of "
          "%^BOLD%^YELLOW%^lightning%^RESET%^ strikes $target_name!",
        }),
      }) );
  } else {
    SetEnhanceSkills( ({"poison magic"}) );
    SetMessages( ({
      ({ "are", "$target_name $target_verb mildly inconvenienced by a spray "
         "of %^ORANGE%^smelly goop%^RESET%^ from the vortex." }),
      ({ "are", "$target_name $target_verb coated in a thin film of "
        "%^%^GREEN%^strange slime %^RESET%^ that sprays from the vortex!" }),
      ({ "", "A filthy ichor spews from the vortex, "
        "%^BOLD%^GREEN%^sickening%^RESET%^ $target_name!"}),
    }) );
  }

  return spell::eventCast(who,level,limb,targets);
}


