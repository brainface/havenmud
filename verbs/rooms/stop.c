/* Stop version 2.0D
 * Replaced the idiotic DescartesLogic[tm]
 * (Honestly now, who uses a DAEMON in the 
 * /verbs dir?) and replaced it with new,
 * shiny, happy DuukCode[tm], which of
 * course makes it vastly cooler and even
 * easier to read.
 */
#include <lib.h>
#include <daemons.h>
inherit LIB_VERB;

string *Args = ({ "fishing", "guarding", "following", "leading", 
                  "farming", "questing",
                });

static void create() {
  ::create();
  SetVerb("stop");
  SetRules("STR");
}

string GetErrorMessage() {
  return "Stop " + conjunction(Args, "or") + "?";
}

mixed can_stop_str(string str) { 
    object ob;
    mixed err;
  if ( !(ob = environment(this_player()))) 
        return "You are so screwed.";
  switch(str) {
    
    case "fishing":
      return (mixed)ob->CanStop(this_player(), str);
      break;
    case "guarding":
      if (ob = this_player()->GetProperty("guarding")) {
           return 1;
         } else {
         	return "But you are not guarding!";
         }
       break;
    case "following":
       if (ob = this_player()->GetLeader()) {
         return 1;
        } else {
          return "But you are not following!";
        }
        break;
    case "leading":
      if (sizeof(this_player()->GetFollowers())) {
        return 1;
       } else {
       	return "You are not leading!";
      }
      break;
    case "farming":
  	if (FARM_D->GetFarming(this_player())) {
  		return 1;
  	} else {
  		return "You are not farming!";
  	}
  	break; 
    case "mining":
      if (MINE_D->GetMining(this_player()))
        return 1;
      return "You are not mining!";
      break;
    case "questing":
      if (!(this_player()->GetProperty("mission"))) 
        return "You are not questing!";
      return 1;
      break;
    default:
      return "You can't stop " + str;
      break;
  }
}
  
mixed do_stop_str(string str) {
    object ob;

  switch(str) {
  	
  	case "fishing":
      ob = environment(this_player());
      return (mixed)ob->eventStop(this_player(), str);
      break;
    case "mining":
      MINE_D->RemoveMiner(this_player());
      this_player()->eventPrint("You stop mining.");
      return;
      break;
    case "guarding":
      ob = this_player()->GetProperty("guarding");
      if (living(ob)) {
        if (ob->GetGuard() != this_player()) return "But you aren't guarding " + objective(ob) + "!";
        ob->SetGuard(0);
        }
      if (!living(ob)) { 
        ob->Destruct(); 
        }
      this_player()->SetProperty("guarding",0);
      send_messages("stop", "$agent_name $agent_verb guarding.",
          this_player(), 0, environment(this_player()) );
      return 1;
      break;
      
    case "following":
      ob = this_player()->GetLeader();
      this_player()->eventPrint("You stop following " +
                     ob->GetName() + ".");
      this_player()->SetLeader(0);
      ob->RemoveFollower(this_player());
      break;
      
    case "leading":
      foreach(ob in this_player()->GetFollowers()) {
        this_player()->RemoveFollower(ob);
        this_player()->eventPrint("You stop leading " +
                       ob->GetName() + ".");
        ob->eventPrint(this_player()->GetName() + " is " +
                       "no longer leading you.");
        }
   	  break;
      
    case "farming":
   	  FARM_D->RemoveFarmer(this_player());
   	  send_messages("stop", "$agent_name $agent_verb farming.",
   	                this_player(), 0, environment(this_player()) );
   	  break;
   	case "questing":
   	  ob = load_object(this_player()->GetProperty("mission"));
   	  CHAT_D->eventSendChannel("QUEST", "reports", this_player()->GetKeyName() + " gave up on " + ob->GetMissionName());
   	  this_player()->RemovePermanentProperty("mission");
   	  send_messages("give", "$agent_name $agent_verb up on $agent_possessive quest.", this_player(), 0, environment(this_player()));
   	  break;
    default:
      send_messages("stop", "$agent_name $agent_verb " + str + ".",
        this_player(), 0, environment(this_player()) );
      break;
    }
  return 1;
}


string GetHelp(string str) {
    return ("Syntax: <stop STRING>\n\n"
        "Allows you to stop " + conjunction(Args, "or") + "." +
        "\n\n"
        "See also: " + implode(Args, ", ")
      );
}
