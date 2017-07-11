/*  NEW IMPROVED LOCKED PORTAL!
 *  One that WORKS!
 *  Duuktsaryth
 */
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("lock area");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetRequiredMagic(60);
  SetMagicCost(100,100);
  SetSkills( ([
     "conjuring" : 190,
     "enchantment" : 190,
     ]) );
  SetDifficulty(40);
  SetHelp(
          "Locks an area into the caster's memory for later teleportation with the "
          "use of the teleport spell. Attempting to teleport long distances "
          "gets increasingly difficult with the distance.");
  }

varargs int CanCast(object who, int level, mixed n, object *tars) {
  if (environment(who)->GetProperty("no teleport")) {
    message("system", "Something clouds your mind, preventing you from "
                      "remembering this area.", who);
    return 0;
      }
  return spell::CanCast(who, level, n, tars);
  }

varargs int eventCast(object who, int level, mixed n, object *t) {
  message("system",
      "You get a clear picture of this area firmly in your mind.",
        who);
  who->SetPermanentProperty("locked_area", file_name(environment(who)));
  return 1;
  }
