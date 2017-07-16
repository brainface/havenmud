#include <lib.h>
#include <magic.h>
#include <dirs.h>
#include <damage_types.h>
#include <daemons.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("clear skies");
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
    ({ "reach", "$agent_name $agent_verb out $agent_possessive "
       "to the skies in a placating gesture." }),
    }) );
  SetHelp(
    "Using a lifetime's experience of casting simple magics, a "
    "witch can use even her limited power to reach out to the "
    "world around her and calm the stormy skies."
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

  debug(level);

skill = (who->GetSkillLevel("practical magic") - 300) / 20 +1; // 1-11
  
  if (!environment(who)) {
    debug("A bad thing done happened");
    who->eventPrint("You've got bigger problems than a little rain");
    return 0;
  }
  debug ("removing rain in : "+domain+" of this amount:");
  debug (skill);
  domain = environment(who)->GetDomain();
  if (WEATHER_D->GetRaining(domain) >= 10) {
    send_messages( "",
       "%^BOLD%^CYAN%^The rain suddenly stops falling from the sky.%^RESET",
       who, who, environment(who));
  } else if (WEATHER_D->GetRaining(domain) <= 0) {
    send_messages( "look",
      "$agent_name $agent_verb a bit like an idiot, standing there gaping "
      "up at the sky.",
       who, who, environment(who));
  } else {
    send_messages( "",
      "%^BOLD%^CYAN%^All around you, the clouds disperse.%^RESET",
      who, who, environment(who));
  }
  WEATHER_D->AddRaining(domain, -skill);

  return spell::eventCast(who, level, limb, targets);
}

