/* repair verb */
#include <lib.h>
#include <damage_types.h>
#include <vehicle.h>

inherit LIB_VERB;
mixed do_repair_obj(object);

static void create() {
        ::create();
        SetVerb("repair");
        SetRules("STR", "OBJ", "");
        SetErrorMessage("Repair what?");
        SetHelp("Syntax:     repair <system>    \n"
                "            repair <ship>      \n"
                "            repair <object>    \n"
                "            repair             \n"
                "Use this command to either repair a ship "
                " or repair a ship system (if you are within "
                "the ship). You can also use this command to attempt to repair "
                "weapons or armour.  This is more effective if you are in a "
                "smithy. Using this command without a target will cycle through "
                "worn objects looking for a repairable object."
                "\nThis skill requires skills based on what you are trying to repair.");
}

mixed can_repair() {
  object who = this_player();
        if (who->GetParalyzed()) return "You cannot move!";
        if (who->GetSleeping()) return "You're asleep.  Nice try.";
        if (who->GetInCombat()) { return "You are in combat and should focus on that instead of trying to repair."; }
        if (who->GetStaminaPoints() < 50) return "You're too tired.";
        if (!sizeof(who->GetWorn()) && !vehiclep(environment(who))) return "But you have nothing equipped!";
        return 1;
}


mixed can_repair_obj() {
        object who = this_player();
        if (who->GetParalyzed()) return "You cannot move!";
        if (who->GetSleeping()) return "You're asleep.  Nice try.";
        if (who->GetInCombat()) { return "You are in combat and should focus on that instead of trying to repair."; }
        if (who->GetStaminaPoints() < 50) return "You're too tired.";

        return 1;
}


mixed do_repair() {
  object *stuff = ({ });

  stuff = this_player()->GetUniqueWorn();
  foreach(object thingy in stuff) {
    int canRepair = 1;
    if(thingy->NeedsRepairs()) {
//      debug(thingy->GetKeyName() + " needs repairs!");
      foreach(string sk in thingy->GetRepairSkills()) {
        if (!this_player()->GetSkillLevel(sk))  {
//          debug("you don't know "+sk);
          canRepair = 0;
          this_player()->eventPrint("You lack the skill in " + sk +" to repair " +
            thingy->GetKeyName() + ".");
          //this_player()->eventPrint("But you don't know anything about " + sk + ".");
          //return 0;

        }
      }

      if (canRepair) {
//        debug( "can repair "+thingy->GetKeyName() );
        return do_repair_obj(thingy);
      }
//      debug( "couldn't repair "+thingy->GetKeyName() );
    }
  }

  this_player()->eventPrint("But nothing you can repair is significantly damaged!");
  //return do_repair_obj(environment(this_player()));
}

mixed do_repair_obj(object ship) {
  object who = this_player();
  int repair;
  
  who->AddStaminaPoints(-25);
  
  if (vehiclep(ship)) {
    //mahkefel: switched to wood working and doubled effect
    repair = who->eventCheckSkill("wood working", 100 - (ship->GetDamagePoints() * 100 / ship->GetMaxDamagePoints()) );
    repair = repair * 10; 
  
    if (who->GetProperty("repair debug")) debug("Ship repair: " + repair + " of " + ship->GetMaxDamagePoints() );
    if (repair <= -100) {
      if (repair < -100) repair = -100;
      send_messages("break", "While trying to repair the ship, $agent_name $agent_verb something.", who, 0, environment(who) );
      ship->eventReceiveDamage(0, BLUNT, 50);
      return 1;
    }
    if (repair <= 0) {
      who->eventPrint("You fail to repair any damage.");
      return 1;
    }
    
    send_messages("repair", "$agent_name $agent_verb some of the damage to the ship.",  who, 0, environment(who) );
    if (who->GetSkillLevel("wood working") > 250 && ship->GetVehicleSize() <= VS_DREADNAUGHT ) {
      repair *= 8;
    } else if (who->GetSkillLevel("wood working") > 100 && ship->GetVehicleSize() <= VS_CRUISER ) {
      repair *= 4;
    } else if (who->GetSkillLevel("wood working") > 50 && ship->GetVehicleSize() <= VS_GALLEY ) {
      repair *= 2;
    }
    ship->AddDamagePoints(repair);
    return 1;
  }

  send_messages( ({ "attempt" }), "$agent_name $agent_verb to repair " + ship->GetShort() + ".",  who, ship, environment(who) );
  ship->eventRepair(who, environment(who));
  return 1;

}


mixed can_repair_str(string str) {
        object who = this_player();
        object ship = environment(who);

        if (str == "weapons") str = "weapon";
        if (!vehiclep(ship)) return "You must be inside a ship to repair non-objects.";
        if (!(ship->GetDamagedSystem(str))) return "But that isn't broken!";
        return can_repair_obj();
}

mixed do_repair_str(string str) {
        object who = this_player();
        object ship = environment(this_player());
        string skill;
        int success;
        if (str == "weapons") str = "weapon";
        skill = ship->GetRepairSkill(str);
        success = who->eventCheckSkill(skill,
                      150 - (ship->GetDamagePoints() * 100 / ship->GetMaxDamagePoints()),
                      0,
                      100);
        who->AddStaminaPoints(-50);
        if (success <= 0) {
         if (success < -100) success = -100;
           send_messages("break",
                "While trying to repair the " + str + ", $agent_name $agent_verb something.",
                who, 0, environment(who) );
                ship->eventReceiveDamage(0, BLUNT, 50);
                return 1;
        }
  ship->RemoveDamagedSystem(str);
  send_messages("repair",
    "$agent_name $agent_verb the " + str + " system!",
    who, 0, ship);
  return 1;
}

