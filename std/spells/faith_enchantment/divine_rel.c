#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create()
	{
	spell::create();
	SetSpell("divine religion");
	SetSpellType(SPELL_OTHER);
	SetRules("LIV");
	SetSkills(  ([
     "faith" : 75,
     "enchantment" : 75,
		])  );
  SetMagicCost(75,75);
	SetDifficulty(20);
  SetHelp(
		"Enables the caster to divine the religion of the target.");

}

int eventCast(object who, int level, mixed limbs, object array targets) {

   object person = targets[0];
   send_messages( ({"call", "point"}),
      "$agent_name $agent_verb upon the power of the Gods and $agent_verb "
      "at $target_name.",
   who, person, environment(who)  );
   if (!(person->GetReligion())) {
	message("system",
		"Using your faith, you find that "
		+ capitalize(person->GetKeyName()) + " has no god.",
	who);
   } else {
   message("system",
      "Through your faith, you discover that "
      + capitalize(person->GetKeyName()) + " is "
      + (person->GetReligion()) + " in faith.",
      who);
   }
}


/* Approved by Dylanthalus on Sun Oct 11 17:37:35 1998. */
