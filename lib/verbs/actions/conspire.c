// mahkefel 2011
// a party buff for dirty tricksers. Will not affect self.

#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

int eventAttack(object who, object* targets);
int eventAction(object who, object* target);

static void create() {
  ::create();
  SetVerb("conspire");
  SetRules("with LIV","");
  SetHelp("Syntax: conspire, conspire with LIV\n\n"
    "You share a truly brilliant plan with your allies, increasing "
    "their deviousness and sparing them from whatever nonsensical "
    "thoughts of their own that were disorienting them."
  );
  SetStaminaCost(100);
  SetRequiredWeapon("none"); // might break stuff, makes help look right.
  SetRequiredSkills( ([
    "dirty tricks" : 75,
  ]) );
}

// overridden so that dudes don't always attack because you fade with them.
int eventAction(object who, object* targets) {
  if(who->GetTestChar()) debug ("event action");
  eventAttack(who,targets);
  who->AddStaminaPoints(-StaminaCost);
  return 1;
}

mixed can_conspire() {
  if ( this_player()->GetPartyMembers() == ({}) ) {
    return "It appears your friends know you to well to be around "
      "your conspiracies.";}
  return CanAction(this_player());
}

mixed can_conspire_with_liv() {
  //debug ("can rally liv");
  return CanAction(this_player());
}

mixed do_conspire_with_liv(object target) {
  //debug ("do rally liv");
  if (target == this_player()) {
    this_player()->eventPrint("You listen closely to the words the voices in "
      "your head say. They're not very helpful.");
    return;
  }
  return eventAction(this_player(), ({target}) );
}

mixed do_conspire() {
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
    who->eventPrint("But you have no one to conspire with!");
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
  send_messages( ({ "share" }),
    "$agent_name%^BOLD%^BLACK%^ $agent_verb%^RESET%^ a daring plan with "
    + conjunction(targets->GetName()) + ", accompanied by much gestures and hand motions.",
    who, 0, environment(who));

  foreach (object target in targets) {
    int pro, con;

      // fuckit, this can be a skillcheck. big depressive guy is hard to rally.

      // idea is dude will probably have 1 of these skills, defender at least one of other.
      pro = who->GetSkillLevel("accuracy")/3;
      pro += who->GetSkillLevel("enchantment")/3;
      pro += who->GetSkillLevel("stealing")/3;
      pro += who->GetLuck();
      pro += who->GetStatLevel("intelligence");

      // these are the defender's RELUCTANCE to be ACCOMPLICE TO MURDER skills.
      con = target->GetSkillLevel("plate armour")/3; // was +=. oops.
      con += target->GetSkillLevel("natural magic")/3;
      con += target->GetSkillLevel("faith")/3;

      if(who->GetProperty("action_debug")) debug ("Conspire skill check--pro: "+pro+" con: "+con);

      result = who->eventCheckSkill("dirty tricks", con, pro, 100);

      if (result > 0 ) {
        send_messages( ({"listen"}), "$target_name%^BLACK%^BOLD%^ $target_verb%^RESET%^ "
          "closely to $agent_possessive_noun words.",
          who, target, environment(who) );

        // add ally buff
        "/verbs/actions/obj/conspiracy"->eventRage(target, who);

      } else {
        send_messages( ({"frown"}), "$target_name%^BOLD%^ $target_verb%^RESET%^ dubiously.",
        who, target, environment(who) );
      }
    }

  return 1;
}

