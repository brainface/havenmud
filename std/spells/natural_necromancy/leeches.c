#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

object GetVoodooDollTarget(object who, object doll);

static void create() {
  ::create();
  SetSpell("leeches");
  SetSpellType(SPELL_HEALING);
  SetSkills( ([
    "natural magic" : 50,
    "necromancy" : 50,
    ]) );
  SetRules("", "LIV", "OBJ");
  SetHelp("A shaman of moderate skill can summon leeches to consume "
    "poison afflicted himself or an ally. The spell may also be directed "
    "at a voodoo doll, allowing the shaman to cure someone at range.");
  SetDifficulty(20);
}

int CanCast(object who, int level, mixed limb, object *targets) {
   object target = targets[0];

   if(target->GetKeyName() == "voodoo doll") {
     // this probably needs to be done again in eventCast,
     // in case someone logs mid spell
     target = GetVoodooDollTarget(who, target);
     if (!target) {
       who->eventPrint("The spirits can't seem to find "
       "the being you wish to affect.");
       return 0;
     }
   } else if (!living(target)) {
     who->eventPrint("You can't summon leeches through that!");
     return 0;
   }

   if(!(target->GetPoison())) {
      if(target == who) {
         message("system", "But you're not poisoned.",
                 who);
         return 0;
      } else {
         message("system", "But that person doesn't seem to "
                 "be poisoned!",who);
         return 0;
      }
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets) {
   object target = targets[0];
  int amt = level + who->GetSkillLevel("natural magic") / 10;

   if(target->GetKeyName() == "voodoo doll") {
     // this probably needs to be done again in eventCast,
     // in case someone logs mid spell
     target = GetVoodooDollTarget(who, target);
     if (!target) {
       message("system", "The spirits can't seem to find "
       "the being you wish to affect.", who);
       return 0;
     }
  }

   send_messages(({""}), "Fat leeches suddenly crawl over $target_name, "
     "noisily sucking blood!",
       who, target, environment(target));
   if(amt > target->GetPoison()) { amt = target->GetPoison(); }
   target->AddPoison(-amt);
   if(target->GetPoison() > 0) {
      send_messages(({"look"}), "$target_name still $target_verb affected "
                    "by deadly poisons. ", who, target, environment(who));
   }
   return 1;
}

object GetVoodooDollTarget(object who, object doll) {
  object target;

  target = find_living(doll->GetVictim());
  if (!target) {
    return 0;
  }

  if (environment(target)->GetProperty("no magic")) {
    who->eventPrint("Some magic is warding the spirits away!");
    return 0;
  }

  return target;

}

