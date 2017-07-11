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
   SetSpell("dark burial");
   SetRules("OBJ");
   SetSpellType(SPELL_OTHER);
   SetSkills( ([
      "necromancy" : 25,
      "faith"      : 25,
      ]) );
   SetMorality(-25);
   SetStaminaCost(15,15);
   SetDifficulty(20);
   SetHelp(
           "Faithful priests skilled in necromancy can use this spell "
           "to cause a corpse to sink into the ground, draining the "
           "remaining magical energy from it. Only the most evil of priest can perform this ritual.");
}

int CanCast(object who, int level, string limb, object *targets) {
   object target = targets[0];

   if (!target) return 0;
   if(!target->GetDecayLife()) {
     message("spell_failure","You cannot give a dark burial to " + target->GetName() + "!",who);
     return 0;
     }
   if (target->GetUserCorpse()) { 
     who->eventPrint("That corpse refuses to be buried.");
     return 0;
     }
   if(living(environment(target))) {
     message("system","The corpse must be on the ground for "
               "the dark burial to begin.", who);
     return 0;
     }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets) {
   object target = targets[0];
   object *inv = all_inventory(target);
   int strength = target->GetLevel();
   send_messages("drain", "%^RED%^The corpse convulses wickedly "
                 "before turning into a shimmering ethereal form and "
                 "slowly sinking into the ground as $agent_name "
                 "$agent_verb the magical energy from it.%^RESET%^",who, 
                  0, environment(who));
  level = level/20;
  if (!level) level = 1;
  who->AddMagicPoints((strength * level));
  foreach(object thing in inv) {
      thing->eventMove(environment(target));
   }
   target->eventDestruct();
   return 1;
}


/* Approved by Dylanthalus on Mon Dec 14 10:40:18 1998. */
