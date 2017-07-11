// mahkefel 2011
// berserking combat action, disorients foes and may draw their ire.

// (no idea if "taunting" works)

#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

int eventAttack(object who, object* targets);
int eventAction(object who, object* target);

static void create() {
  ::create();
  SetVerb("rattle");
  SetRules("LIV","");
  SetHelp("Syntax: rattle, rattle LIV\n\n"
    "You thump your weapon repeatedly against your shield, distracting and "
    "annoying your foes.");
  SetStaminaCost(100);
  SetRequiredWeapon("shield"); // might break stuff, makes help look right.
  SetRequiredSkills( ([
    "berserking" : 25,
  ]) );
}

mixed can_rattle() {
  //debug("can rattle");
  if (!this_player()->GetInCombat()) { return "But you fight no one!"; }
  return CanAction(this_player());
}

mixed can_rattle_liv() {
  //debug ("can rattle liv");
  return CanAction(this_player());
}

mixed do_rattle_liv(object target) {
  //debug ("do rattle liv");
  return eventAction(this_player(), ({target}) );
}

mixed do_rattle() {
  //debug ("do rattle");
  return eventAction(this_player(), this_player()->GetEnemies() );
}

int eventAttack(object who, object* targets) {
  int result;
  object buckler;

  //debug("eventAttack");
  // try to make sure targets are actually in the room
  foreach (object target in targets) {
    if (environment(target) != environment(who) ) {
      if(who->GetTestChar()) debug ("enemy not in room");
      targets -= ({target});
    }
    if (member_array(who,target->GetEnemies()) == -1) {
      if(who->GetTestChar()) debug ("target is not an enemey");
      targets -= ({target});
    }
  }
  if (!sizeof(targets)) {
    who->eventPrint("But you fight no one!");
    return 0;
  }

  buckler = GetAnyWeapon(who);

  if (!buckler) {
    if (who->GetTestChar()) debug("ain't no shield");
    who->eventPrint("You must have a shield in hand to do this!");
    send_messages( ({ "waves","seem" }), "$agent_name%^RED%^ $agent_verb%^RESET%^ "
      "$agent_possessive_noun hands in the air menacingly, but $agent_verb "
      "to have forgotten something!",
      who, 0, environment(who));
    return 0;
  }


 if(who->GetTestChar()) debug ("invoke message");
  send_messages( ({ "bang" }),
    "$agent_name%^RED%^ $agent_verb%^RESET%^ repeatedly against "
    "$agent_possessive "+buckler->GetKeyName()+"!",
    who, 0, environment(who));

  foreach (object target in targets) {
    int pro, con;

      pro = who->SetStatLevel("luck")/2;
      pro += who->GetStatLevel("charisma")/2;

      // dual casters will resist heavily.
      con = target->GetSkillLevel("faith")/2; // was +=. oops.
      con += target->GetSkillLevel("conjuring")/2;
      con += target->GetSkillLevel("natural magic")/2;
      con += target->GetSkillLevel("vocal music")/2;
      con += target->GetStatLevel("wisdom")/2;
      con += target->GetStatLevel("luck")/2;

      result = who->eventCheckSkill("berserking", con, pro, 100);

      if (result > 0 ) {
        send_messages( ({"vex"}), "$agent_name%^BOLD%^RED%^ $agent_verb%^RESET%^ $target_name with "
          "the infuriating racket!", who, target, environment(who) );

        target->AddDisorient(who->GetSkillLevel("disorient")/4+who->GetSkillLevel("berserking")/4);
        // this may not actually taunt!
        target->SetCurrentEnemy(who);
        // add rage.
        "/verbs/actions/obj/rage"->eventRage(who);

      } else {
        send_messages( ({"ignore"}), "$target_name stoically%^RED%^ $target_verb%^RESET%^ $agent_possessive_noun "
          "ridiculous taunt.", who, target, environment(who) );
      }
    }

  return 1;
}

