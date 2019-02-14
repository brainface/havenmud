/*    /verbs/rooms/go.c
 *    from the Dead Soulsr2 Object Library
 *    go STR
 *    go into STR
 *    created by Descartes of Borg 951104
 */

#pragma save_binary

#include <lib.h>
#include <vehicle.h>
#include <damage_types.h>
#include <daemons.h>
#include <position.h>

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("drive");
    SetRules("STR");
    SetErrorMessage("Drive the wagon where??");
    SetHelp("Syntax: <drive DIRECTION>\n"
      "Directs the wagon you're sitting on in the direction you specify. "
      "\nA mule or similiar creature must be hitched to the wagon for it to move."
      "\nSee also: board, mount, hitch, unhitch, hijack"
    );
}

mixed can_drive_str(string str) {
  object wagon = this_player()->GetChair();
  object who = this_player();
  string tmp;
  if (who->GetSleeping()) return "You are asleep!";
  if (who->GetParalyzed()) return "You are paralyzed!";
  if (who->GetStaminaPoints() < 25) return "You are too tired.";
  if( !wagon ) return "You're not on a wagon! (You must be sitting on the wagon, not inside it.)";
  if (!(wagon->GetProperty("PROP_VEHICLE"))) return "You're not sitting on a wagon that can move!";
  if (!wagon->GetHitcher()) return "There's nothing hitched to the wagon!";
  if (wagon->GetHitcher()->GetPosition() != POSITION_STANDING) return "Your lazy " + wagon->GetHitcher()->GetKeyName() + " is sitting down on the job.";
  if (wagon->GetHasMoved()) return "The wagon has expended its movement for now";
  return (mixed)environment(wagon)->CanGo(wagon->GetHitcher(), str);
}

mixed do_drive_str(string str) {
  object who = this_player();
  object wagon = who->GetChair();
  object horse = wagon->GetHitcher();
  int success;
  int enemies = 0;
  int con = 5;
  int pro = 0;
  object *e = ({ });
  object *eP = ({ });

  if (!horse) {
    who->eventPrint("You could swear there used to be a horse at the front of this thing.");
    return 1;
  }
  
  eP = e->GetPilot();
  eP = filter(eP, (: $1 :) );
  //con = environment(wagon)->GetDrivingDifficulty();
  //TODO: driving difficulty
  con = 10;
  if (WEATHER_D->GetRaining(environment(wagon)->GetDomain()) == 10) {
    who->eventPrint("Driving in such weather is more difficult!");
    con *= 2;
  }
  /* phhhbbbt
  if (who->GetTestChar()) debug("Driving Difficulty: " + con + " (base "
    + environment(wagon)->GetDriveingDifficulty() + ", Size: " +
    wagon->GetVehicleSize() + ", Rain: " +
    (WEATHER_D->GetRaining(environment(wagon)->GetDomain()) == 10 ? "Yes" : "No") );
  */
    success = who->eventCheckSkill("riding", con, 0, enemies);
  if (who->GetTestChar()) if (enemies)
    debug("success: " + success + "eP->driving: " + enemies);

  send_messages("drive",
    "$agent_name $agent_verb the wagon " + str + ".",
    this_player(), 0, wagon);
  if (success < 0) {
    switch(random(100)) {
      case 0..50:
        who->eventPrint("You hit a rock and circle aimlessly.");
        wagon->eventPrint("The wagon clatters ominously.");
        //wagon->eventReceiveDamage(0, BLUNT, absolute_value(success) * 5);
        break;
      case 51..80:
        who->eventPrint("The wagon gets stuck in a rut.");
        wagon->eventPrint("The wagon seems to be stuck.");
        return 1;
        break;
      case 81..95:
        who->eventPrint("You steer directly into an old dead tree.");
        wagon->eventPrint("You hear a loud *THUNK* from the front of the wagon as the world tilts dangerously.");
        //wagon->eventReceiveDamage(0, BLUNT, absolute_value(success) * 25);
        break;
      case 96..100:
        who->eventPrint("%^BOLD%^RED%^You run the wagon into a ditch and go flying forward!%^RESET%^");
        who->eventCollapse();
        wagon->eventPrint("%^BOLD%^RED%^You hear a scream from the front of the wagon as it goes teeter totter.%^RESET%^");
        break;
    }
  }
  if (success <= 0) {
    who->eventPrint("The wagon doesn't move.");
    return 1;
  }

  return (mixed)environment(horse)->eventGo(horse, str);
}

