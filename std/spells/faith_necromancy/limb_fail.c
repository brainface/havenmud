//
// Necro Limb Regen spell
// Liberal borrowing from Duuk's limb regen spell
// Laoise@Haven
// 2005

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

object who, target;
string *limbs;
int CheckValidLimb(string limb);
int eventRestoreLimb(string limb);
int LimbEffect(object target, int fidelity, int necro);

static void create() {
  spell::create();
  SetSpell("unholy growth");
  SetSkills( ([
    "faith"      : 70,
    "necromancy" : 70,
  ]) );
  SetRules("LIV","");
  SetMorality(-10);
  SetSpellType(SPELL_HEALING);
  SetHelp(
    "With this spell a faithful necromancer can attempt to restore "
    "a lost limb, by grafting a severed one in its place. The severed "
    "limb being used does not have to be the same as where it's being "
    "attached - all you need is a dead limb. Be warned that because this "
    "spell is an unholy perversion in which necromancy attempts to mimic "
    "healing arts, it has the potential for deadly consequences."
  );
}

int CanCast(object w, int level, mixed limb, object *targets) {
  if(!present("limb", w)) {
    w->eventPrint("You'll need to be grasping a severed limb to attempt this!");
    return 0;
  }
  return spell::CanCast(w, level, limb, targets);
}

varargs int eventCast(object w, int level, mixed limb, object *targets) {
  who = w;
  target = targets[0];
  limbs = target->GetMissingLimbs();

  if (!sizeof(limbs)) {
    who->eventPrint(
      "You fondly eye the severed limb in your possession, but find "
      "that your intended target has all of their limbs attached. \n"
      "Maybe now is a good time to rectify that?",
      );
    send_messages( ({ "eye", "seem" }),
      "$agent_name darkly $agent_verb " + present("limb", who)->GetShort() + " and $agent_verb lost in gruesome scheming.",
      who, 0, environment(who));
    return 1;
  }
  if (sizeof(limbs) == 1)  {
    eventRestoreLimb(limbs[0]);
    return 1;
  }
  if (sizeof(limbs) > 1) {
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
  if(!(target->GetMissingLimb(limb))) {
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

int eventRestoreLimb(string limb) {
  int fidelity = (this_player()->GetSkillLevel("faith")/25);
  int necro    = (this_player()->GetSkillLevel("necromancy")/25);

  send_messages( ({ "hold", "animate" }),
    "%^RED%^Grinning evilly, $agent_name $agent_verb " + present("limb", who)->GetShort() +
    " up to the stump of $target_possessive_noun missing limb. With a practiced "
    "glare $agent_name $agent_verb the dead flesh, which forms itself in to a "
    "replacement for $target_possessive missing "+ limb +".%^RESET%^",
    who, target, environment(who));
  target->RestoreLimb(limb);
  present("limb", who)->eventDestruct();

  call_out((: LimbEffect :), 20, fidelity, necro);
/*
  debug("LimbEffect call-out, faith: "+ fidelity +", necro: "+ necro);
*/
  return 1;
}

int LimbEffect(int fidelity, int necro) {
  int chance = random(200);
  object victim = target;

  if((chance + fidelity + necro) < 50)
  {

// This is the part where you get screwed over.
  debug("Bad effect. Target: "+target->GetCapName()+" Chance: "+chance);

    send_messages( ({ "collapse", "writhe" }),
      "%^RED%^Screaming with all $agent_possessive might, $agent_name "
      "$agent_verb to the ground. As $agent_name $agent_verb in pain, "
      "$agent_possessive newly-restored limb reverts to its undead state "
      "and drags the rest of $agent_possessive_noun body with it!%^RESET%^",
    victim, 0, environment(victim));
    victim->eventCollapse();
    victim->SetUndead(1);
    return 1;
  } else {

// You're safe
  if (who->GetTestChar())
  debug("Safe! Chance: "+chance);
    send_messages( ({ "" }),
      "$agent_possessive_noun newly-restored limb gives a small twitch, "
      "but quickly returns to normal.",
    victim, environment(who));
    return 1;
  }
}





