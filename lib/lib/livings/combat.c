/*  combat.c
 *  inherits revised combat code.
 *  Duuktsaryth 5 february 1999
 */
#include <dirs.h>
#include <lib.h>
#include <conditions.h>
#include <rounds.h>

inherit LIB_CLASSES;
inherit LIB_COMBATMSG;
inherit DIR_LIB "/livings/combat/actions";
inherit DIR_LIB "/livings/combat/attack";
inherit DIR_LIB "/livings/combat/attack_types";
inherit DIR_LIB "/livings/combat/conditions";
inherit DIR_LIB "/livings/combat/enemies";
inherit DIR_LIB "/livings/combat/magic";
inherit DIR_LIB "/livings/combat/melee";
inherit DIR_LIB "/livings/combat/paralysis";
inherit DIR_LIB "/livings/combat/party";
inherit DIR_LIB "/livings/combat/physical";
inherit DIR_LIB "/livings/combat/style";
inherit DIR_LIB "/livings/combat/weapon";
inherit DIR_LIB "/livings/combat/wimpy";

/* virtual declarations */
int GetSleeping();
int GetDying();
int AddCooldown(string, int);

private static string *Friends;
mapping Cooldowns = ([]);

static void create() {
     classes::create();
     attack::create();
     attack_types::create();
     enemies::create();
     magic::create();
     melee::create();
     party::create();
     paralysis::create();
     physical::create();
     style::create();
     weapon::create();
     wimpy::create();
     Friends = ({});
}

void heart_beat() {
  physical::heart_beat();
  conditions::heart_beat();
  style::heart_beat();
  	
  if (!Cooldowns) Cooldowns = ([]);
  foreach(string cool in keys(Cooldowns)) {
  	AddCooldown(cool, -1);
  }
  if (GetConditionFlag(CONDITION_PREVENT_COMBAT)) return;
  if (GetParalyzed() > 0) {
    AddParalyzed(-1);
    return;
  }
  if (GetSleeping() || GetDying() ) return;
  if (sizeof(GetEnemies())) {
    object ob;
    if (sizeof(GetSpecialTargets())) {
      foreach(object target in GetSpecialTargets()) {
        if(objectp(SetCurrentEnemy(target))) break;
        }
      eventExecuteAttack(GetSpecialTargets());
      SetSpecialTargets(0);
      }
      else if(ob = ResetCurrentEnemy()) eventExecuteAttack(ob);
    }
    else {
      if (GetNextRound() != ROUND_UNDEFINED &&
          functionp(GetNextRoundFunction()) ) {
          function f;
          f = GetNextRoundFunction();
          SetNextRound(ROUND_UNDEFINED);
          evaluate(f);
          }
       }
}

int AddCooldown(string cool, int timer) {
	if (!Cooldowns) Cooldowns = ([]);
	Cooldowns[cool] += timer;
  if (Cooldowns[cool] <= 0) {
    map_delete(Cooldowns, cool);
    eventPrint(capitalize(cool + " is no longer on cooldown."));
   }
  return Cooldowns[cool];
}

int GetCooldown(string cool) {
	if (!Cooldowns) return 0;
        if (member_array(cool, keys(Cooldowns)) == -1) return 0;
	return Cooldowns[cool];
}

void RemoveCooldown(string cool) {
	if (!Cooldowns) Cooldowns = ([]);
        if (member_array(cool, keys(Cooldowns)) == -1) return;
	map_delete(Cooldowns, cool);
	return;
}

void ResetCooldowns() {
	Cooldowns = ([]);
	return;
}

string *GetCooldowns() {
	if (!Cooldowns) return ({});
	return keys(Cooldowns);
}
		      
int GetTrainingModifier(int diff) {

  if (diff >=  16)              return 5;
  if (diff >=   6 && diff < 16) return 4;
  if (diff >=   1 && diff <  6) return 3;
  if (diff >=  -9 && diff <  1) return 2;
  if (diff >= -20 && diff < -9) return 1;
  return 0;
}

int GetInCombat() {
  FilterEnemies();
  if (sizeof(GetEnemies())) {
    foreach(object enemy in GetEnemies()) {
      if (present(enemy, environment())) return 1;
      }
    }
  return 0;
}

string *SetFriends(string *x) {
	if (!arrayp(x)) x = ({ x });
	return Friends = x;
}

string *GetFriends() { return Friends; }

string *AddFriend(string filename) { 
	return Friends += ({ filename });
}

string *RemoveFriend(string filename) {
	return Friends -= ({ filename });
}

object *CheckFriends() {
	object *tmp = ({ });
	
	foreach(object thing in all_inventory(environment())) {
    foreach(string id in thing->GetId()) {
      if (member_array(id, Friends) != -1) {
        if (living(thing) && thing != this_object()) tmp += ({ thing });
        }
	  }
	}
	return tmp;
}
