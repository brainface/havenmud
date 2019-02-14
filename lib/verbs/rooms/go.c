/*    /verbs/rooms/go.c
 *    from the Dead Soulsr2 Object Library
 *    go STR
 *    go into STR
 *    created by Descartes of Borg 951104
 */

#pragma save_binary

#include <lib.h>
#include <conditions.h>
#include "include/go.h"

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("go");
    SetRules("STR", "into STR");
    SetErrorMessage("Go in which direction?");
    SetHelp("Syntax: <go DIRECTION>\n"
	    "        <go into PLACE>\n\n"
	    "Moves you towards the direction you specify, or into the place "
	    "you specify.  The command \"go into\" is synonymous with the "
	    "\"enter\" command.  Note that most directions are pre-aliased "
	    "for you to the proper \"go\" commands.  For example, "
	    "\"go south\" has been pre-aliased to \"s\".\n\n"
	    "See also: climb, enter, jump");
}

mixed can_go_str(string str) {
  object horsie = this_player()->GetChair();
  object wagon;

  if (this_player()->GetConditionFlag(CONDITION_PREVENT_MOVE)) return "You are unable to move.";
  if(this_player()->GetParalyzed()) return "You are unable to move.";
  if(this_player()->GetSleeping() ) return "You are asleep!";
  if( !environment(this_player()) ) return "You are nowhere.";

  /*
  // technically works, but plays poorly--wagon is left behind and player
  // never knows why, echos to the room the player left.
  // prevent cheaty wagon movement (leading or command the horse to move faster 
  // than the drive verb would allow.)
  if (this_player()->GetHitcher() ) {
    if (this_player()->GetHitcher()->GetHasMoved()) {
  	  send_messages("strain", "$agent_name $agent_verb at the weight behind "
  	  	"it but can't seem to go any faster.",
		this_player(), 0, environment(this_player()));
  	  return 0;
  	}
  }   
  */
  // more wagon stuff: keep a player who is being followed by a horse
  // hitched to a wagon from outpacing the wagon's speed
  if (this_player()->GetFollowers()) {
    foreach(object follower in this_player()->GetFollowers()) {
      if (follower->GetHitcher()) {
        send_messages( ({"ignore","start"}), "$agent_name stubbornly "
          "$agent_verb $target_name and starts searching the ground for "
          "something to eat.", follower, this_player(), environment(this_player()));
        this_player()->RemoveFollower(follower);
	this_player()->eventPrint("You have to sit on the wagon and drive it "
	  "if you want " + add_article(follower->GetKeyName()) + " to pull it anywhere.");
        return 0;
      }
    }
  }
  
  if( horsie ) {
    //debug("we gotta horsey");
    if ( horsie->GetRider() == this_player() ) {
      if (horsie->GetParalyzed() ) return horsie->GetName() + " is unable to move!";
      if (horsie->GetSleeping() )  return horsie->GetName() + " is too lazy to move.";
      if (horsie->GetHitcher() ) {
        if (horsie->GetHitcher()->GetShort() ) {
          return "You'll have to drive the " + remove_article(horsie->GetHitcher()->GetName())
            + " " + horsie->GetKeyName() + " is hitched to.";
        } else {
          return horsie->GetName() + " is stuck on something!"; 
        }
      }
      if ( !environment(horsie) ) {
        return "Your horse is mucked up bad, bad (bug report this please.)";
      }
      //debug("Trying to CanGo horse");
      return (mixed)environment(horsie)->CanGo(horsie, str);
    } else {
      // sitting on something not a mount of some kind.
      return "You're not going anywhere sitting on " + horsie->GetShort() +
        ". (You have to [mount] a horse to ride.)";
    }
  }
  
  if( !creatorp(this_player()) && (int)this_player()->GetStaminaPoints() <3 )
      return "You are too tired to go anywhere right now.";
  return (mixed)environment(this_player())->CanGo(this_player(), str);
}

mixed can_go_into_str(string str) {
  object horsie = this_player()->GetChair();

  if( horsie ) {
    if (horsie->GetRider() == this_player() ) {
      return "You can't ride " + horsie->GetKeyName() + " indoors!";
    }
  }

  if (this_player()->GetConditionFlag(CONDITION_PREVENT_MOVE)) return "You are unable to move.";
  if (this_player()->GetSleeping()) return "You are asleep!";
    if( !environment(this_player()) ) return "You are nowhere.";
    if( !creatorp(this_player()) && (int)this_player()->GetStaminaPoints() <3 )
      return "You are too tired right now.";
    return (mixed)environment(this_player())->CanEnter(this_player(), str);
}

mixed do_go_str(string str) {
  object horsie = this_player()->GetChair();
 
  if (horsie) {
    //debug("Trying to ride " + str + " on " + horsie->GetName());
    return (mixed)environment(horsie)->eventGo(horsie, str);
  }

  return (mixed)environment(this_player())->eventGo(this_player(), str);
}

mixed do_go_into_str(string str) {
    return (mixed)environment(this_player())->eventEnter(this_player(), str);
}
