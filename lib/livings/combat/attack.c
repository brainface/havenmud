/* combat/attack.c
 * Controls setting of attacks, executing attacks
 * and pre-attack checks.
 * Duuktsaryth 3 February 1999
 */
#include <rounds.h>
#include <function.h>
#include <position.h>

varargs int SetAttack(mixed, function, int);
int eventExecuteAttack(mixed);
int eventPreAttack(object);
int eventPromptAllies(object);
varargs int eventReceiveAttack(int, string, object, int);

/* virtual declarations */
int GetParalyzed();
int SetSleeping(int);
int GetSleeping();
int GetBlind();
string GetKeyName();
int GetNextRound();
int GetLuck();
int GetMagicResistance();
int GetTrainingModifier(int);
varargs int eventTrainSkill(string, int, int, int, int);
function SetNextRoundFunction(function);
int SetNextRound(int);
function GetNextRoundFunction();
object GetCurrentEnemy();
int AddEnemy(object);
int RemoveEnemy(object);
object *SetSpecialTargets(object *);
int GetPosition();
void eventPrint(string);
int GetDying();
int eventMeleeRound(mixed, function);
int eventMagicRound(mixed, function);
int eventWeaponRound(mixed, mixed);
int eventStyle(object);
int GetSkillLevel(string);
int GetStatLevel(string);
object *GetWielded();
int id(string);
object *CheckFriends();

function NextRoundFunction;
int NextRound;

static void create() {
  NextRound = ROUND_UNDEFINED;
  NextRoundFunction = 0;
 }

varargs int SetAttack(mixed target, function callback, int round) {
  
  if (objectp(target)) target = ({ target });
  if (target) {
    /* If I am one of my targets, return error. */
    if (member_array(this_object(), target) != -1) return -1;
    /* If I am not in combat right now, skip to the event. */
    if (!GetCurrentEnemy()) call_out((: eventExecuteAttack :), 0, target);
    foreach(object t in target) { 
  	  AddEnemy(t); 
  	  t->AddEnemy(this_object()); 
  	  }
    SetSpecialTargets(target);
   }
  SetNextRoundFunction(callback);
  SetNextRound(round || ROUND_UNDEFINED);
  return 1;
}

int eventExecuteAttack(mixed target) {
  object *weapons;
  function attack = GetNextRoundFunction();
  int round = GetNextRound();
  int position = GetPosition();

  SetNextRoundFunction(0);
  SetNextRound(ROUND_UNDEFINED);
  if (position == POSITION_LYING || position == POSITION_SITTING) {
    eventPrint("You can't fight unless you are standing up!");
    return 0;
    }
  if (arrayp(target)) {
    if (!attack || functionp(attack) & FP_OWNER_DESTED) {
          /*  Has to error out, since by default this
              lib handles only one target */
          return 0;
          }
    /* Filter out targets which cannot be attacked and dested objects. */
    target = filter(target, function(object ob) {
                if (!ob) return 0;
                if (!(ob->eventPreAttack(this_object()))) return 0;
                return 1;
                });
    if (!sizeof(target)) return 0; /* No targets left after filter */
    } /* End the if(arrayp) */
    else { if(!target->eventPreAttack(this_object())) return 0; }
  target->eventPromptAllies(this_object());
  if (target->GetGuard() && !arrayp(target)) {
    send_messages("step", "$agent_name $agent_verb in front of an attack "
                          "aimed at $target_name!", target->GetGuard(), target,
                          environment());
    target = target->GetGuard();
    target->AddEnemy(this_object());
  }

  switch (round) {
    case ROUND_UNDEFINED:
      if (attack && !(functionp(attack) & FP_OWNER_DESTED)) {
        return evaluate(attack, target);
        }
      if (sizeof(weapons = GetWielded())) {
        return eventWeaponRound(target, weapons);
        }
        else { return eventMeleeRound(target, 0); }
      break;
    case ROUND_MELEE:
      return eventMeleeRound(target, functionp(attack) ? attack : 0);
      break;
    case ROUND_WEAPON:
      return eventWeaponRound(target, functionp(attack) ?
                                      attack : GetWielded() );
      break;
    case ROUND_MAGIC:
      return eventMagicRound(target, attack);
      break;
    case ROUND_OTHER:
      if (functionp(attack) && !(functionp(attack) & FP_OWNER_DESTED)) {
       return evaluate(attack);
       } else { return 0; }
      break;
    
    default: return 0; break;
  }
  return 0;
}

int eventPreAttack(object agent) {
  if (agent == this_object()) return 0;
  if (userp(agent) && newbiep()) {
    RemoveEnemy(agent);
    agent->RemoveEnemy(this_object());
    return 0;
    }
  if (environment()->GetProperty("no attack")) {
    agent->eventPrint("You are prevented from attacking by a force outside of your control.");
    RemoveEnemy(agent);
    agent->RemoveEnemy(this_object());
    return 0;
    }
  if (GetDying()) return 0;
  AddEnemy(agent);
  return 1;
}

int eventPromptAllies(object attacker) {
  int count = 0;
  object *friendlies = ({});
  object *tmp;

  friendlies = all_inventory(environment());
  foreach(object possible_ally in friendlies) {
    if (possible_ally->GetSleeping()) continue;
    tmp = possible_ally->CheckFriends();
    if (!sizeof(tmp)) continue;
    if (member_array(this_object(), tmp) != -1) possible_ally->AddEnemy(attacker);
    count++;
    }
  return count;
}

varargs int eventReceiveAttack(int attack, string style, object attacker, int defense) {
  int level_bonus, agent_level;

  if (!attacker) attacker = previous_object();
  if (!living(attacker)) { agent_level = 1; }
    else agent_level = attacker->GetLevel();
  // debug("eRA (" + short_file(base_name(this_object())) + ") : a = " + attack + " d = " + defense);
  if (GetParalyzed()) return 1;
  if (GetSleeping()) {
     send_messages("wake", "$agent_name $agent_verb up!", this_object(), 0, environment() );
      SetSleeping(0);
      return 1;
    }
  if (random(defense) > attack) {
    return 0;
  }
  if (style == "magic") {
    defense = GetMagicResistance();
    if (random(defense) > attack) return 0;
      else return 1;
    }
  level_bonus  = GetTrainingModifier(attack - defense);
  return 1;
}

int SetNextRound(int round) { return (NextRound = round); }

int GetNextRound() { return (NextRound); }

function SetNextRoundFunction(function f) { return (NextRoundFunction = f); }

function GetNextRoundFunction() { return (NextRoundFunction); }
