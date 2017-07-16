// stolen ~ torak@haven 2013 ~ dark burial -> sea burial damhair clerics
// added checks to make sure things don't break, you're in a vehicle and in deep ocean
// changed from mp to sp gains && made it a moral act

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("sea burial");
  SetRules("OBJ");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
     "enchantment" : 50,
     "faith"      : 50,
     ]) );
  SetMagicCost(50,10);
  SetDifficulty(20);
  SetHelp(
    "While on a boat in deep ocean, the cleric of the Sea God may "
    "perform sea burials in return for a cleaner boat, a boost "
    "in stamina as well as a small atonement."
    );
  }

int CanCast(object who, int level, string limb, object *targets) {
  object target = targets[0];

  if (!environment(who)) return 0; // breaking bad is a terrible show.

  if (!(vehiclep(environment(who)))) {
    who->eventPrint("%^RED%^You are not aboard a ship!%^RESET%^");
    return 0;
  } 

  if (!(environment(environment(who)))->GetProperty("ocean")) {
    who->eventPrint("%^RED%^You are not in the deep ocean!%^RESET%^");
    return 0;
  }
  if (!target) return 0;
  if(!target->GetDecayLife()) {
    message("spell_failure","%^RED%^You cannot give a sea burial to " 
            + target->GetName() + "!%^RESET%^",who);
    return 0;
  }
  if (target->GetUserCorpse()) { 
    who->eventPrint("%^RED%^That corpse refuses to be buried at sea.%^RESET%^");
    return 0;
  }
  if(living(environment(target))) {
    message("system","%^RED%^The corpse must be on the ground for "
            "the sea burial to begin.%^RESET%^", who);
    return 0;
    }
  return spell::CanCast(who, level, limb, targets);
}


int eventCast(object who, int level, mixed limb, object *targets) {
   object target = targets[0];
   object *inv = all_inventory(target);
   int strength = target->GetLevel();
   send_messages("perform", 
     "%^CYAN%^BOLD%^A shroud appears over the body as $agent_name $agent_verb the "
     "rights of passage, offering the newly deceased to the Master of "
     "Storms. A wave breaks across the deck and recedes, dragging the "
     "corpse to its watery grave.%^RESET%^", who, 0, environment(who));
  level = level/20;
  if (!level) level = 1;
  who->AddStaminaPoints((strength * level));
  if (who->GetMorality() > 0) {
    who->eventMoralAct(-15);
  } else {
    if (who->GetMorality() < 0) {
      who->eventMoralAct(15);
    }
  }
  foreach(object thing in inv) {
      thing->eventMove(environment());
   }
   target->eventDestruct();
   return 1;
}
