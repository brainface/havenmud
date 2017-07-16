// mahkefel 2011
// a party buff for berserkers. Will not affect self.



#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

int eventAttack(object who, object* targets);
int eventAction(object who, object* target);

static void create() {
  ::create();
  SetVerb("rally");
  SetRules("LIV","");
  SetHelp("Syntax: rally, rally LIV\n\n"
    "You shout a roar of defiance, rallying your allies "
    "to overcome their fear and rejoin the fight."
  );
  SetStaminaCost(100);
  SetRequiredWeapon("none"); // might break stuff, makes help look right.
  SetRequiredSkills( ([
    "berserking" : 100,
  ]) );
}

// overridden so that dudes don't always attack because you fade with them.
int eventAction(object who, object* targets) {
  if(who->GetTestChar()) debug ("event action");
  eventAttack(who,targets);
  who->AddStaminaPoints(-StaminaCost);
  return 1;
}

mixed can_rally() {
  //debug("can rally");
  //if (!this_player()->GetInCombat()) { return "But you fight no one!"; }
  //if ( !this_player()->GetTestChar() ) {return "You don't think knowledge of this has quite reached the world.";}
  if ( this_player()->GetPartyMembers() == ({}) ) {return "It's hard to rally your friends when you have none.";}
  return CanAction(this_player());
}

mixed can_rally_liv() {
  //debug ("can rally liv");
  return CanAction(this_player());
}

mixed do_rally_liv(object target) {
  //debug ("do rally liv");
  return eventAction(this_player(), ({target}) );
}

mixed do_rally() {
  object* targets = ({});
  foreach(string member in this_player()->GetPartyMembers()) {
    targets += ({get_object(member)});
  }
  return eventAction(this_player(), targets );
}

int eventAttack(object who, object* targets) {
  int result;
  string* target_names = ({});

  if (!sizeof(targets)) {
    who->eventPrint("But you have no one to rally!");
    return 0;
  }

  //debug("eventAttack");
  // try to make sure targets are actually in the room
  foreach (object target in targets) {
    if (environment(target) != environment(who) ) {
      if(who->GetProperty("action_debug")) debug ("party member not in room");
      targets -= ({ target });
    }
  }

  foreach(object target in targets) {
    target_names += ({ target->GetKeyName() });
  }

 if(who->GetTestChar()) debug ("invoke message");
  send_messages( ({ "shout" }),
    "$agent_name%^BOLD%^RED%^ $agent_verb%^RESET%^ a rallying cry to "
   + conjunction(targets->GetName()) + "!",
    who, 0, environment(who));

  foreach (object target in targets) {
    int pro, con;

      // fuckit, this can be a skillcheck. big depressive guy is hard to rally.

      // idea is dude will probably have 1 of these skills, defender at least one of other.
      pro = who->GetSkillLevel("combat rage")/3;
      pro += who->GetSkillLevel("faith")/3;
      pro += who->GetSkillLevel("vocal music")/3;
      pro += who->GetLuck();
      pro += who->GetStatLevel("charisma");

      // these are the defender's COWARDISM skills.
      con = target->GetSkillLevel("dodge")/3; // was +=. oops.
      con += target->GetSkillLevel("parry")/3;
      con += target->GetSkillLevel("enchantment")/3;

      if(who->GetProperty("action_debug")) debug ("Rally skill check--pro: " +pro+" con: "+con);

      result = who->eventCheckSkill("berserking", con, pro, 100);

      if (result > 0 ) {
        send_messages( ({"rally"}), "$target_name%^BOLD%^RED%^ $agent_verb%^RESET%^ "
          "against $target_possessive fear and panic!",
          who, target, environment(who) );

        // add inspire & rage.
        "/verbs/actions/obj/inspire"->eventRage(target, who);
        "/verbs/actions/obj/rage"->eventRage(who);

      } else {
        send_messages( ({"shake"}), "$target_name%^RED%^ $target_verb%^RESET%^ $target_possessive "
          "head sadly at $agent_possessive_noun unispiring shout.", who, target, environment(who) );
      }
    }

  return 1;
}

