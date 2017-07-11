// mahkefel 2011
// blindsight, a sword slinging combat action
//  reveals everyone in the room, but you have to be blind/in darkness.
//  kind of a blind swordsman motif.

#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

int eventAttack(object who, object* targets);
int eventAction(object who, object* target);

static void create() {
  ::create();
  SetVerb("blindsight");
  SetRules("");
  SetHelp("Unhindered by sight, you reach out with your other senses "
    "to detect potential enemies in the area. You may only use this "
    "action while unable to see.");
  SetStaminaCost(70);
  SetRequiredWeapon("none"); // might break stuff, makes help look right.
  SetRequiredSkills( ([
    "sword slinging" : 75,
  ]) );
}

// overriding this to not require a weapon.
mixed CanAction(object who) {
  if(who->GetTestChar()) debug ("can action");
  if (who->GetStaminaPoints() < StaminaCost) {
    return "You are too tired.";
  }
  //if (who->GetParalyzed()) {
  //  return "You are paralyzed.";
  //}
  if (who->GetSleeping()) {
    return "You are asleep.";
  }
  foreach(string s in keys(RequiredSkills)) {
    if (who->GetSkillLevel(s) < RequiredSkills[s]) {
      return "You are not proficient enough in " + s + " to perform that action.";
    }

  }
  return 1;
}

// overridden so that dudes don't always attack because you blindsight with them.
int eventAction(object who, object* targets) {
  if(who->GetTestChar()) debug ("event action");
  eventAttack(who,targets);
  who->AddStaminaPoints(-StaminaCost);
  return 1;
}

mixed can_blindsight() {
  debug("can blindsight");
  if (!this_player()->GetEffectiveVision() == VISION_CLEAR) {
    return "Why don't use just look around?"; 
  }
  return CanAction(this_player());
}

mixed do_blindsight() {
  object* hidden_people = ({ });
  object room;

  if (!environment(this_player())) {
    debug("dude trying to blindsight is no where: "+this_player()->GetKeyName());
    return 0;
  }
  room = environment(this_player());
  foreach (object person in all_inventory(room) ) {
    if (person->is_living()) {
      if(person->GetInvis() == 1 || person->GetInvis() == 0) {
        hidden_people += ({ person });
      }
    }
  }
  debug ("do blindsight");
  return eventAction(this_player(), hidden_people );
}

int eventAttack(object who, object* targets) {
  int result;

  debug("eventAttack");

  if(who->GetTestChar()) debug ("invoke message");
  send_messages(({ "stand", "look"}), "$agent_name%^BOLD%^YELLOW%^ $agent_verb "
    "%^RESET%^very still and $agent_verb $agent_possessive head "
    "$agent_verb around with sightless eyes.",
    who, 0, environment());

  if (!sizeof(targets)) {
    who->eventPrint("You hear nothing but your own heartbeat.");
    who->AddParalyzed(2);
    return 0;
  }

  foreach (object target in targets) {
    int pro, con;

    pro = who->GetSkillLevel("sword slinging")/4;
    pro = who->SetStatLevel("wisdom")/2;
    pro = who->SetStatLevel("luck")/2;

    con += target->GetSkillLevel("dodge")/2;
    con += target->GetSkillLevel("stealth")/2;
    con += target->GetStatLevel("coordination")/2;
    con += target->GetStatLevel("luck")/2;

    result = who->eventCheckSkill("sword slinging", con, pro, 100);

    if (result > 0 ) {
      who->eventPrint("You hear the distinct heartbeat of " 
        + target->GetKeyName() + ".");
      target->eventPrint(who->GetKeyName() + " seems to be staring "
        "right at you.");
    } else {
      // can't find a messaging function that works right and doesn't reveal
      //   name.
      who->eventPrint("You hear a quickly indrawn breath, but "
        "can't pinpoint the source.");
      target->eventPrint("You hold your breath and hope you've "
        "taken enough baths lately.");
    }
  }
  who->AddParalyzed(1); // prevent xp spam thing
  return 1;
}

