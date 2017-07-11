// mahkefel 2011
// reveals history
// boring spell is boring.
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create()
{
  spell::create();
  SetSpell("reveal soul");
  SetSpellType(SPELL_OTHER);
  SetRules("LIV");
  SetSkills(  ([
    "faith" : 100,
  ])  );
  SetMagicCost(100,100);
  SetDifficulty(20);
  SetHelp(
    "Enables the devout to lay bare the soul of the target, viewing the "
    "strands of fate that made them what they are.");

}

int eventCast(object who, int level, mixed limbs, object array targets) {

   object person = targets[0];
   send_messages( ({"call", "point"}),
      "$agent_name $agent_verb upon the divine knowledge of the Gods "
      "and $agent_verb at $target_name.",
   who, person, environment(who)  );
   if (!(person->GetStory())) {
        message("system",
          "Using your extreme powers of your faith, you find that "
          + capitalize(person->GetKeyName()) + " is a boring lout.",
        who);
   } else {
     message("system",
       "Visions of " + capitalize(person->GetKeyName()) + "'s early life "
       "flash before your eyes.",
        who);
     who->eventPrint(person->GetStory());
   }
}


/* Approved by Dylanthalus on Sun Oct 11 17:37:35 1998. */

