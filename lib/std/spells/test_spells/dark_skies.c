#include <lib.h>
#include <magic.h>
#include <dirs.h>
#include <damage_types.h>
#include <daemons.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("dark skies");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetRequiredMagic(50);
  SetSkills( ([
    "practical magic" : 300,
  ]) );
  SetMagicCost(40, 10);
  SetDifficulty(10);
  SetMorality(0);
  SetMessages( ({ 
    ({ "howl", "$agent_name $agent_verb at the heavens "
       "in rage." }),
    }) );
  SetHelp(
    "Using a lifetime's experience of casting simple magics, a "
    "witch can use her marginal power to transfer her rage to "
    "the heavens, calling storms and rain."
  );
}

// prevent casting indoors without a natural charge
//   I guess natural charge should still work with this?
int CanCast(object who, int level, mixed limb, object *targets) {
  if( (environment(who)->GetClimate() == "indoors") ||
  (environment(who)->GetClimate() == "underground") ){
    if (!present("natural_charge", who)) {
      who->eventPrint("Your spell fizzles and refuses to work "
        "without a view of the sky.");
      return 0;
     }
  }
  return spell::CanCast(who, level, limb, targets);
}

// broadcast a message to the room
int eventCast(object who, int level, mixed limb, object array targets) {
  int skill = 0;
  string domain = "";
  skill = (who->GetSkillLevel("practical magic") - 300) / 20 +1; // 1-11
  
  if (!environment(who)) {
    debug("A bad thing done happened");
    who->eventPrint("You've got bigger problems than a little rain");
    return 0;
  }
  debug ("adding rain in : "+domain+" of this amount:");
  debug (skill);
  domain = environment(who)->GetDomain();
  if (WEATHER_D->GetRaining(domain) >= 10) {
    send_messages( "look",
      "$agent_name $agent_verb a bit like an idiot, standing there gaping "
      "up at the sky, accomplishing nothing.",
       who, who, environment(who));
  } else if (WEATHER_D->GetRaining(domain) <= 0) {
    send_messages( "",
      "%^BOLD%^BLACK%^Dark clouds suddenly gather across the open skies.%^RESET",
      who, who, environment(who));
  } else {
    send_messages( "",
      "%^BOLD%^BLACK%^All around you, dark clouds billow, and "
      "thunder peals in the distance.%^RESET",
      who, who, environment(who));
  }
  WEATHER_D->AddRaining(domain, -skill);

  return spell::eventCast(who, level, limb, targets);
}

