//
// Necro Limb Regen spell
// Liberal borrowing from Duuk's limb regen spell
// Laoise@Haven
// 2005
//

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

object who, target;
string *limbs;
int CheckValidLimb(string limb);
int eventRestoreLimb(string limb);

static void create() {
  spell::create();
  SetSpell("limb spell");
  SetSkills( ([
    "necromancy" : 70,
    "faith" : 70,
  ]) );
  SetRules("LIV","");
  SetMagicCost(100,50);
  SetMorality(-10);
  SetSpellType(SPELL_OTHER);
  SetHelp(
    "Necro limb regen spell "
  );
}

int CanCast(object me, int level, mixed limb, object *targets)
{
  if(!present("limb", me))
  {
    message("", "You'll need to obtain a severed limb before you can "
      "properly perform this spell.", me);
    return 0;
  }
debug("Success with CanCast");
return spell::CanCast(me, level, limb, targets);
}

varargs int eventCast(object me, int level, mixed limb, object *targets) 
{
  who = me;
  target = targets[0];
  limbs = target->GetMissingLimbs();

  if(!present("limb", who))
  {
    message("", "You'll need to obtain a severed limb before you can "
      "properly perform this spell.", who);
    return 0;
  }
  if (!sizeof(limbs)) 
  {
    message("my_action",
      "You fondly eye the severed limb in your possession, but find "
      "that your intended target has all of their limbs attached. "
      "Maybe now is a good time to rectify that?",
      who);
    message("other_action",
      who->GetCapName() + " darkly eyes a rotting piece of flesh and "
        "seems lost in gruesome scheming.",
      environment(who), who);
    return 1;
  }
  if (sizeof(limbs) == 1) 
  {
    debug("One limb missing, sending to Restore.");
    eventRestoreLimb(limbs[0]);
    return 1;
  }
  if (sizeof(limbs) > 1) 
  {
    message("my_action",
      "The target is missing the following limbs: " +
      implode(limbs, ", ") + ".\n" +
      "Which would you like to regenerate first?",
      who);
    input_to( (: CheckValidLimb :) );
    return 1;
  }
return 1;
}

int CheckValidLimb(string limb) 
{
  if(!(target->GetMissingLimb(limb))) 
  {
    message("my_action", 
      "The target is missing more than one limb, which would you like "
      "to restore first?" + implode(target->GetMissingLimbs(), ", ") + ".",
      who);
    input_to( (: CheckValidLimb :) );
    return 1;
  }
  if(!(target->GetLimb((target->GetMissingLimb(limb))["parent"]))) 
  {
    message("my_action", 
      "You must first reattach the parent limb before you can attach "
      "this limb. \nPlease enter a valid limb:", who);
    input_to( (: CheckValidLimb :) );
    return 1;
  }
return eventRestoreLimb(limb);
}

int eventRestoreLimb(string limb) 
{
  debug("In Restore.");

  send_messages( ({ "hold", "animate" }),
    "%^RED%^Grinning evilly, $agent_name $agent_verb a rotting pile of flesh "
    "up to the stump of $target_possessive_noun missing limb. With a practiced "
    "glare $agent_name $agent_verb the dead flesh, which forms itself in to a "
    "replacement for $target_possessive_noun missing "+ limb +".%^RESET%^",
    who, target, environment(who));
  target->RestoreLimb(limb);
  debug("Removing severed body parts from caster's inventory.");
  present("limb", who)->eventDestruct();
  debug("Restore finished.");
  return 1;
}
