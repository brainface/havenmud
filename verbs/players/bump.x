/*  /cmds/verbs/player/bump.c
 *  Allows players to possibly bump a target into another room
 *  created by Blitz@Dead Souls
*/

#pragma save_binary

#include <lib.h>
#include <damage_types.h>
#include "include/bump.h"

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("bump");
    SetRules("LIV");
    SetErrorMessage("Whom would you like to bump?");
    SetHelp( "Syntax: bump LIV\n\n"
         "This command allows you bump the living object named "
         "into an adjacent room.  It is quite possible that "
         "bumping may cause you bodily injury.");
}

mixed can_bump_liv() {
    object env = environment(this_player());

   if( !env ) return "You are nowhere!";
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
  if(this_player()->GetParalyzed()) {
    return "You cannot move.";
  }
   if( env->GetProperty("no bump") )
      return "Mystical forces prevent your pushy actions.";
    return 1;
}

mixed do_bump_liv(object ob) {
  int Strength, TargetStrength;
  string *Exits;
  string NewLocation, OldLocation;
  mixed var;
  object env;

  if( !ob ) return 0;
  if( !(env = environment(ob)) ) return 0;
  if( (int)ob->GetProperty("no bump") ) {
    send_messages("try", "$agent_name $agent_verb to bump $target_name!",
      this_player(), ob, env);
    if( !playerp(ob) )
      ob->eventForce("growl "+(string)this_player()->GetKeyName());
    return 1;
  }
  if( var = ob->eventBump(this_player()) ) return var;
  this_player()->AddStaminaPoints( -(random(15) + 3) );
  if( ( random((int)ob->GetStatLevel("agility"))) >
      ( (int)this_player()->GetStatLevel("strength")) ) {
    send_messages("sidestep", "$target_name deftly $agent_verb " +
      "$agent_possessive_noun attempt to bump $target_objective.",
      this_player(),ob,env);   
    return 1;
  }
  Strength = random((int)this_player()->GetStatLevel("strength")) +
             random((int)this_player()->GetStatLevel("agility") / 2);
  TargetStrength = random((int)ob->GetStatLevel("strength")) +
                   random( (int)ob->GetStatLevel("agility") / 2 );
  if( (Strength - TargetStrength) < -10 ) {
    send_messages("shove","$target_name $target_verb $agent_name "
      "to the ground!", this_player(), ob, env);
    // mahkefel--I added this line, but npc
    // stats are hilarious, so it's going to be terrible.
    this_player()->eventCollapse();
    return 1;
  }
  else if( (Strength - TargetStrength) < (5 + random(20)) ) {
    send_messages("fail", "$agent_name $agent_verb to bump $target_name "
      "out of the way!", this_player(), ob, env);
    return 1;
  } else {
    this_player()->AddStaminaPoints( -(random(15) + 50) );

    Exits = (string *)env->GetExits();
    Exits = filter(Exits,
            (: !(object)$(env)->GetDoor($1) ||
               !(object)$(env)->GetDoor($1)->GetClosed() :) );
    if( !sizeof(Exits) ) {
      send_messages("", "There is nowhere for $target_name to go!",
        this_player(), ob, env);
      ob->eventCollapse();
      return 1;
    }
    NewLocation = Exits[ random(sizeof(Exits)) ];
    send_messages("shove", "$agent_name $agent_verb $target_name "
      "to the " + lower_case(NewLocation) + "!", this_player(), ob, env);
    NewLocation = environment(ob)->GetExit(NewLocation);
    OldLocation = base_name(environment(ob));
    if( !(int)ob->eventMove(NewLocation) ) {
      message("other_action", (string)ob->GetCapName()+" is bounced "
        "back into the room.", environment(ob), ob);
      message("my_action", "You are bounced back to your original "
        "location.",
        ob);
      ob->eventCollapse();
    } else {
      ob->eventDescribeEnvironment(0);
      ob->eventCollapse();
      if( !userp(ob) )
        call_out((: MoveBack :), 12 + random(6), ob, OldLocation);
    }
    return 1;
  }
  return 0;
}

void MoveBack(object ob, string where) {
  if( !ob ) return;
  ob->eventForce("stand up");
  ob->eventMoveLiving(where, "$N leaves angrily.", "$N enters angrily.");
  ob->eventForce("growl");
}

