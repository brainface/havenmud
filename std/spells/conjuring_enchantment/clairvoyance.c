/* ----------------------------------------------------------------------- */
// Filename: clairvoyance.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Dec 18th, 1998
// Abstract: Basically, an advanced discern location spell. 
// Revision History: Note of thanks to Vanyel, Morgoth and Zeddicus for 
//                     various roles in the creation of this spell.
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("clairvoyance");
  SetDifficulty(50);
  SetRules("LIV", "STR");
  SetGlobalSpell(1);
  SetRequiredMagic(100);
  SetMagicCost(50, 50);
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
     "conjuring" : 75,
     "enchantment" : 75,
     ]) );
  SetHelp(
          "This power of the diviner allows them to perceive "
          "the location of the target as though they were themselves "
          "standing in it for a brief moment.");
  }

/* CanCast is from discern location, originally 
   coded by Vanyel@Haven */

int CanCast(object who, int level, mixed limb, object *targets) {
  if (creatorp(targets[0])) {
      message("system", "Cast it on whom?", who);
      return 0;
     }
  if (vehiclep(environment(targets[0]))) {
    who->eventPrint("That person is on a ship and clouds prevent your conjuring.");
    return 0;
  }
  return spell::CanCast(who, level, limb, targets);
}

varargs int eventCast(object who, int level, mixed n, object *t) {
  object target = t[0];
  message("scry", "%^CYAN%^BOLD%^In your mind's eye "
                  "you see:%^RESET%^", who);
  message("scry",
  environment(who)->GetRemoteDescription(base_name(environment(target)), 1), who);
  return 1;
}



/* Approved by Morgoth on Fri Dec 18 21:03:23 1998. */
