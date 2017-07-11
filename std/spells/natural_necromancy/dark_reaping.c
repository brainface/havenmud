// mahkefel 2012: copying into dark reaping, natural/necro corpse->health
/* ----------------------------------------------------------------------- */
// Filename: dark_burial.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Oct 28th, 1998
// Abstract: Necro/Faith spell that draws magical energy from a corpse by
//           buring it under the ground.
// Revision History: source code: spirit call by Arathorn@Haven
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("dark reaping");
   SetRules("OBJ");
   SetSpellType(SPELL_OTHER);
   SetSkills( ([
      "necromancy" : 25,
      "natural magic" : 25,
      ]) );
   SetMorality(-1);
   SetStaminaCost(15,15);
   SetDifficulty(20);
   SetHelp(
     "Shamans holding power over life and death can absorb "
     "vitality from a fallen corpse, destroying it in the "
     "process. Relying on the natural powers of rot and decay, "
     "this spell may not be cast indoors without a natural charge.");
}

int CanCast(object who, int level, string limb, object *targets) {
   object target = targets[0];

  if( (environment(who)->GetClimate() == "indoors") ){
    if (!present("natural_charge", who)) {
      who->eventPrint("Your spell fizzles and refuses to work in these types of environmental settings.");
      return 0;
     }
  }

   if (!target) return 0;
   if(!target->GetDecayLife()) {
     message("spell_failure","You cannot reap " + target->GetName() + "!",who);
     return 0;
     }
   if (target->GetUserCorpse()) {
     who->eventPrint("That corpse refuses to be reaped.");
     return 0;
     }
   if(living(environment(target))) {
     message("system","The corpse must be on the ground for "
               "the reaping to begin.", who);
     return 0;
     }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets) {
   object target = targets[0];
   object *inv = all_inventory(target);
   int strength = target->GetLevel();

   send_messages("drain", "Wickedly thorned vines %^GREEN%^unravel%^RESET%^ "
     "from $agent_possessive_noun outstretched hand and eagerly "
     "wrap around $target_name. Moments later, they recede, leaving "
     "nothing but %^BOLD%^BLACK%^dust%^RESET%^ behind.",who,
                  target, environment(who));
  level = level/20;
  if (!level) level = 1;
  who->AddHealthPoints((strength * level));
  foreach(object thing in inv) {
      thing->eventMove(environment());
   }
   target->eventDestruct();
   return 1;
}

