//  Aless added poison healing 2014

#include <lib.h>
#include <daemons.h>
inherit LIB_NPC;

int eventResurrect(object who, string args);
int eventHeal(object who, string what);
int eventRestore(object who, string limb);
string GetLocalCurrency();

mapping SetFees(mapping mp);
/* mapping Fees needs to have:
 * "resurrect" as the fee, in LocalCurrency, PER LEVEL of the asker.
 * "magic" as the fee per 5 mp restored
 * "stamina" as the fee per 5 sp restored
 * "health" as the fee per 5 hp restored
 * "poison" as the fee per 10 poison removed
 * "restore" as the fee per limb (again per level)
 */
mapping Fees;
string LocalCurrency;


static void create() {
  npc::create();
  Fees = ([
    "resurrect" :  10,
    "magic"     :   5,
    "health"    :   2,
    "stamina"   :   2,
    "restore"   :   2,
    "poison"    : 100,
    ]);
  LocalCurrency = "imperials";
}

mapping SetFees(mapping mp) {
        return Fees; /* This function deliberately does not do anything anymore */
}

mapping GetFees() { return Fees; }

int GetFee(string what) {
  float x = currency_rate(GetLocalCurrency());
  int cost = to_int(Fees[what] * x);
  if (cost < 1) cost = 1;
  return cost;
}

string SetLocalCurrency(string x) { return LocalCurrency = x; }

string GetLocalCurrency() { return LocalCurrency; }

mixed eventAsk(object who, string args) {
        string cmd, what;
        mixed tmp;
        if (tmp = npc::eventAsk(who, args) == 1) return 1;

        if (!args || args == "") {
                eventForce("speak Are you asking me to heal you?");
                return 1;
        }
        if( sscanf(args, "%s %s", cmd, what) != 2 ) {
        cmd = args;
        what = 0;
    }

  // mahkefel 2018:
  // ugly bit of code makes religios healers help anyone of same
  // religion, race, town, or of good reputation in town
  if (GetReligion() != "agnostic") {
    if (GetReligion() && (who->GetReligion() != GetReligion())) {
      if (GetTown() && (who->GetTown() != GetTown())) {
        if (GetRace() && (who->GetRace() != GetRace())) {
          if (who->GetReputation(GetTown()) > 250 ) {
            eventForce("speak I'm really not supposed to help foreigners, but "
              "for you I'll gladly make an exception."); 
          } else {
            eventForce("speak You are not one of the " + GetReligion() + " faithful, "
              "nor of " + GetTown() + ", and I will not assist you.");
            return 1;
          }
        }
      }
    }
  }
  if (who->GetReputation(GetTown()) < -100) {
        eventForce("speak Why would I heal someone as disliked as you?");
        return 1;
    }

        switch(cmd) {
                case "res": case "resurrect": case "rez":
                  eventResurrect(who, what);
                  break;
                case "heal":
                  eventHeal(who, what);
                  break;
                case "restore":
                  eventRestore(who, what);
                  break;
                default:
                  eventForce("speak I am not sure what you need. Do you need to be "
                             "resurrected, healed, or have a limb restored?");
                  break;
                }
                return 1;
}

void eventGreet(object who) {
  eventForce("speak I can heal you, raise you from the dead, and restore your limbs. "
             "Just <ask " + GetKeyName() + " to> either heal, restore, or resurrect.");
}

int GetResurrectModifier(int x) {
  int cost;
  switch(x) {
    case 0..25:
      cost  = 0;
      break;
    case 26..50:
      cost  = 50;
      break;
    case 51..100:
      cost  = 250;
      break;
    case 101..200:
      cost  = 1000;
      break;
    case 201..300:
      cost  = 2500;
      break;
    case 301..399:
      cost  = 10000;
      break;
    case 400..9999:
      cost  = 100000;
      break;
    }
  return cost;
}


int eventResurrect(object who, string what) {
        int tmp;

        if (!what || (what != "me" && present(what) != who)) {
                eventForce("speak Who would you like me to resurrect?");
                return 1;
        }
        if (!tmp = GetFee("resurrect")) {
                eventForce("speak Sadly I do not perform resurrections.");
                return 1;
        }
  if (newbiep(who)) tmp = 0;
  tmp = to_int(tmp);
        tmp = tmp * GetResurrectModifier(who->GetLevel());
        if (tmp  > who->GetCurrency(GetLocalCurrency()) ) {
                eventForce("speak Sadly you cannot afford my services.  I charge "
                           + tmp + " " + GetLocalCurrency() + " to resurrect "
                           "someone of your stature.");
                return 1;
        }
  if (who->GetUndead() == 0) {
                eventForce("speak But you are not undead!");
                return 1;
  }
  who->AddCurrency(GetLocalCurrency(),-tmp);
  who->eventRevive();
  send_messages("take", "$agent_name $agent_verb " + tmp + " " + GetLocalCurrency() +
                " from $target_name.", this_object(), who, environment() );
  eventForce("speak Well then.  Good as new.");
  return 1;
}

int eventRestore(object who, string what) {
        int tmp;
        if (!what || (member_array(what, who->GetMissingLimbs()) == -1)) {
                eventForce("speak But what would you like me to restore for you?");
                return 1;
        }
        if (!tmp = GetFee("restore")) {
                eventForce("speak Sadly I cannot restore limbs.");
                return 1;
        }
        tmp = tmp * who->GetLevel();
        tmp = to_int(tmp);
        if (newbiep(who)) tmp = 0;
        if (tmp > who->GetCurrency(GetLocalCurrency()) ) {
                eventForce("speak Sadly you cannot afford my services.  I charge "
                           + tmp + " " + GetLocalCurrency() + " to restore limbs for "
                           "someone of your stature.");
                return 1;
        }
  if (!who->GetMissingLimb(what)) {
        eventForce("speak But you are not missing you " + what + "!");
        return 1;
        }
  if (who->GetMissingLimb(who->GetMissingLimb(what)["parent"])) {
    eventForce("speak I would need to restore your " + (who->GetMissingLimb(what)["parent"]) + " first!");
    return 1;
  }
  who->AddCurrency(GetLocalCurrency(),-tmp);
  who->RestoreLimb(what);
  who->AddBleeding(-200);
  send_messages("take", "$agent_name $agent_verb " + tmp + " " + GetLocalCurrency() +
                " from $target_name.", this_object(), who, environment() );
  eventForce("speak Well then.  Good as new.");
  return 1;
}

int eventHeal(object who,string what) {
  if (what == "mana") what = "magic";
  if(GetStaminaPoints()<10) {
    eventForce("speak I'm sorry, I must rest before I can heal again.");
    return 1;
  }
  if(!what) {
      eventForce("speak Would you like me to heal your health, stamina, "
                 "mana or poison?");
      return 1;
   }
   if(!GetFee(what)) {
      eventForce("speak Sadly, I do not perform healings of " +
                 what + " right now.");
      return 1;
   }
   if(who->GetCurrency(GetLocalCurrency()) < GetFee(what) ) {
      eventForce("speak I'm afraid you cannot afford my services.  I charge "
                 + GetFee(what) + " " + GetLocalCurrency() + " to heal "
                 + what + ".");
      return 1;
   }
   if ((what == "me") || (what == who->GetKeyName())) {
       what = "health";
   }
   switch(what) {
      case "health":
      if(who->GetHealthPoints()+5 >= who->GetMaxHealthPoints()) {
         eventForce("speak But you are perfectly healthy!");
         return 1;
      }
      break;
      case "stamina":
      if(who->GetStaminaPoints()+5 >= who->GetMaxStaminaPoints()) {
         eventForce("speak But you are fully energized!");
         return 1;
      }
      break;
      case "magic": case "mana":
      if(who->GetMagicPoints()+5 >= who->GetMaxMagicPoints()) {
         eventForce("speak But you are fully magically energized!");
         return 1;
      }
      break;
        case "poison":
      if(!(who->GetPoison())) {
         eventForce("speak But you are not poisoned!");
         return 1;
      }
      break;
   }
   who->AddCurrency(GetLocalCurrency(),-(GetFee(what)));
   send_messages("take", "$agent_name $agent_verb " + GetFee(what) + " "
                + GetLocalCurrency() +
                " from $target_name.", this_object(), who, environment() );
   switch(what) {
      case "health":
      AddStaminaPoints(-10);
      who->eventHealDamage(5,1);
      eventForce("speak Now you're looking a little healthier!");
      break;
      case "stamina":
      AddStaminaPoints(-10);
      who->AddStaminaPoints(5);
      eventForce("speak Now you're looking a little perkier!");
      break;
      case "magic": case "mana":
      AddStaminaPoints(-10);
      who->AddMagicPoints(5);
      eventForce("speak Now you're looking more energized!");
      break;
        case "poison":
      AddStaminaPoints(-10);
      who->AddPoison(-10);
      eventForce("speak Now you're looking a little healthier!");
      break;
   }

   return 1;
}

int SetCharge(int x) {
  CHAT_D->eventSendChannel(GetKeyName(), "error", base_name(this_object()) + " is an OLD HEALER!  FIX ME!");
  return 1;
}

