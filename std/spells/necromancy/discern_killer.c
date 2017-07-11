/*  Discern Killer, basically calls GetKiller() in a corpse.
 *  Zeddicus 9/17/98
 *  With lib changes to body.c and corpse.c
 */
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("speak with dead");
  SetSpellType(SPELL_OTHER);
  SetRules("OBJ");
  SetSkills( ([
     "necromancy" : 20,
     ]) );
  SetMagicCost(75, 50);
  SetDifficulty(80);
  SetHelp(
    "Cast this on a corpse to see what or who killed it."
    );
}

int eventCast(object who, int level, mixed useless, object *targets) {
  object corpse = targets[0];
  string msg;
  int blah = level + who->GetSkillLevel("necromancy");
  
  send_messages("stare",
    "$agent_name $agent_verb blankly at $target_name.",
    who, corpse, environment(who) );

  if (!(corpse->GetKillerRace())) {
    who->eventPrint(corpse->GetCapName() + "'s demise seems to have been " 
                    + possessive(corpse->GetGender()) + " own fault.");
    return 1;
  }
  blah += (100 / corpse->GetDecayCount()); /* Bonus for fresher corpses. */
  switch(blah = random(blah)) {
    case 0..33:
      msg = "You fail miserably in your attempt to determine the cause of death.";
      break;
    case 34..66:
      msg = capitalize(corpse->GetShort()) + " was killed by " + add_article(corpse->GetKillerRace()) + ".";
      break;
    case 67..99:
      msg = capitalize(corpse->GetShort()) + " was killed by a " + corpse->GetKillerGender() + " " + corpse->GetKillerRace() + ".";
      break;
    case 100..9999:
      msg = capitalize(corpse->GetShort()) + " was killed by " + capitalize(corpse->GetKillerName()) + "!";
      break;
    }
  if (blah > 150) {
    send_messages( ({ "stand", "intone" }),
      "$agent_name $agent_verb up and $agent_name $agent_verb in a loud, unearthly voice, \"I was killed by " + capitalize(corpse->GetKillerName()) + "\"!",
      corpse, 0, environment(corpse));
    }
  who->eventPrint(msg);
  return 1;
}


/* Approved by Balishae on Sun Sep 20 01:52:14 1998. */
