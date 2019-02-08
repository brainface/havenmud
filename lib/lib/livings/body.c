/*    /lib/body.c
 *    from the Dead Souls LPC Library
 *    handles information regarding bodies as well as events which
 *    affect them
 *    created by Descartes of Borg 950121
 *    Version: @(#) body.c 1.24@(#)
 *    Last Modified: 96/12/21
 */

#include <lib.h>
#include <daemons.h>
#include <conditions.h>
#include <function.h>
#include <medium.h>
#include <position.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <magic_protection.h>
#include <std.h>
#include "include/body.h"

inherit LIB_REPUTATION;
inherit LIB_MOVE;
inherit LIB_POSITION;
inherit LIB_UNDEAD;

#define COLLAPSE_AT            10.0

string GetClass();
void ResetCooldowns();
int GetConditionFlag(int x);
void ResetConditions();
private int HealthPoints, MagicPoints, Bleeding;
private int Alcohol, Caffeine, Food, Drink, Poison, Sleeping, Hiding, Smoke;
private int Blessed, Cursed;
private float StaminaPoints;
private string Torso;
private mapping Fingers, Limbs, MissingLimbs;
private static int Dying, LastHeal;
private static function Protect;
private static mapping WornItems;
private static class MagicProtection *Protection;
static private int HeartModifier = 0;
private int NoCorpse = 0;

int GetNoCorpse();
void eventForce(string);
int GetLevel();
varargs int eventCheckSkill(string, int, int, int);
int AddRecoveryTime(int);
string GetOwner();
int GetTestChar();

/* bleeding adds because.. breaky */
varargs int eventInflictDamage(object agent, int type, int x, int internal, mixed limbs);

/* PersistentDamageTypes */
private mapping PersistentDamages;

static void create() {
    AddSave( ({ "HealthPoints", "MagicPoints", "StaminaPoints", "Undead",
                "Limbs", "MissingLimbs", "WornItems", "Sleeping", "Bleeding", "Smoke",
                "Blessed", "Cursed", "PersistentDamages",
                 }) );
    NewBody(0);
    Protect = 0;
    WornItems = ([]);
    Limbs = ([]);
    Food = Drink = 2000;
    Alcohol = Caffeine = Bleeding = Smoke = 0;
    Blessed = Cursed = 0;
    HealthPoints = MagicPoints = 50;
    StaminaPoints = 50.0;
    Dying = 0;
    LastHeal = time();
    Protection = ({});
    PersistentDamages = ([
				"bleeding": ([]),
			 ]);
}

mixed direct_tend_str_on_liv(string what) {
	if (GetUndead()) {
		return "You cannot tend the wounds of the dead.";
	}
	if (Dying) {
		return "That person's wounds are mortal.";
	}
	if (GetInCombat()) {
		return "That person is a bit busy right now.";
	}
        if (GetHealthPoints() == GetMaxHealthPoints()) {
                return "That person needs no healing.";
        }
	return 1;
}

mixed direct_turn_liv() {
    if( GetUndead() ) {
	return 1;
    }
    else {
	return "You cannot turn the living!";
    }
}

mixed direct_wake_liv() {
	if (!GetSleeping()) {
		return "But that person is already awake!";
	}
	if (GetSleeping() && GetParalyzed()) {
		return "That person is magically bound.";
	}
	return 1;
}


static void heart_beat() {
    object env = environment();
    int i;

    undead::heart_beat();
    if( i = sizeof(Protection) ) {
      while(i--)
        if( Protection[i]->time && (--Protection[i]->time < 1) )
          RemoveMagicProtection(i);
    }
    if( env && (GetResistance(GAS) != "immune") ) {
	if( (i = env->GetPoisonGas()) > 0 ) {
	    eventPrint("You choke on the poisonous gases.");
	    eventReceiveDamage(load_object(STD_DUMMY "gas"), GAS, i, 1);
	}
    }
    eventCheckHealing();
}

void eventReconnect() {
    LastHeal = time();
}

/************      /lib/body.c Modal Methods Section      ************/

mixed CanRemoveItem(object ob) { return 1; }

/************      /lib/body.c Events Section      ************/

private void checkCollapse() {
    float h = percent(GetHealthPoints(), GetMaxHealthPoints());

    if( h < COLLAPSE_AT ) {
	SetParalyzed(3, (: checkCollapse :));
	return;
    }
}

mapping GetPersistentDamages(string type) {
  switch(type) {
    case "bleeding":
      return PersistentDamages["bleeding"];
    default:
      return PersistentDamages;
  }
}

int eventBleed(int amount) {
  mixed k;
  string msg;
  //mixed *tmp;
  // new bleeding -- why is bleeding damage * 3?
  // Need to check if Dying and attribute death to the appropriate person
  if (sizeof(keys(PersistentDamages["bleeding"])) > 0) {
        foreach (k in keys(PersistentDamages["bleeding"])) {
                int amt = PersistentDamages["bleeding"][k];
                if (objectp(k) && amt > 0) {
                        if (playerp(k)) {
                                if (member_array(k, all_inventory(environment())) != -1) {
                                        eventReceiveDamage(k, DISEASE, amt * 3, 1);
                                } else { // bleeding inflictor is not in the room
                                        eventReceiveDamage(load_object(STD_DUMMY "bleeding"), DISEASE, amt * 3, 1);
                                }

                        } else {
                                eventReceiveDamage(k, DISEASE, amt * 3, 1);
                        }
                } else {
                        //debug("bleeding damage coming from not an object!");
                        if (k == "generic" && amt > 0) {
                                  //debug("generic bleeding amt: " + amt);
                                  eventReceiveDamage(load_object(STD_DUMMY "bleeding"), DISEASE, amt * 3, 1);
                        } else {
                                int accounted_for_sources;
                                int current_bleeding = GetBleeding();
                                foreach(mixed s in keys(PersistentDamages["bleeding"])) {
                                        if (objectp(s) || s == "generic") {
                                            accounted_for_sources += PersistentDamages["bleeding"][s];
                                        }
                                }
                                if (accounted_for_sources != current_bleeding) {
                                  /* this is necessary if a player logs off to ensure the damage
                                   * persists even if they're not around */
                                  int diff = current_bleeding - accounted_for_sources;
                                  PersistentDamages["bleeding"]["generic"] += diff;
                                  /* rebuild mapping */
                                  PersistentDamages["tmp"] = ([ ]);
                                  foreach (mixed s in keys(PersistentDamages["bleeding"])) {
                                     if (s != 0) {
                                        PersistentDamages["tmp"][s] = PersistentDamages["bleeding"][s];
                                     }
                                  }
                                  PersistentDamages["bleeding"] = PersistentDamages["tmp"];
                                  map_delete(PersistentDamages, "tmp");
                                  eventReceiveDamage(load_object(STD_DUMMY "bleeding"), DISEASE, diff * 3, 1);
                                }
                        }
                }
        }
    } 
  // make bleeding messages public, so everyone can laugh at you
  // someone should make these messages better.

  switch(GetBleeding()) {
	case 1..10: 
		msg = "Blood seeps from $agent_possessive_noun wounds.";
	        break;
	case 11..35: 
		msg = "Blood pours from $agent_possessive_noun severe wounds.";
		break;
	case 36..101: 
		msg = "Blood flows freely from $agent_possessive_noun severe wounds.";
		break;
	default:
		msg = "Blood seeps $agent_verb from $agent_possessive_noun wounds.";
		break;
  }
  send_messages("", "%^RED%^" + msg + "%^RESET%^", this_object(), 0, environment());

  //eventPrint("%^RED%^You are bleeding.%^RESET%^");
}

int eventTend(object tender, object tendee) {
  int healing, damage;
  int amount;
	string msg;
	healing = tender->GetSkillLevel("healing");
	damage = tendee->GetMaxHealthPoints() - tendee->GetHealthPoints();
	damage = damage * 100 / tendee->GetMaxHealthPoints();
	if (tender == tendee) msg = "$agent_name $agent_verb to $agent_possessive wounds.";
	  else msg = "$agent_name $agent_verb to $target_possessive_noun wounds.";
	tender->AddStaminaPoints(-20);
	amount = healing/5 + 1;
	tendee->eventHealDamage(amount, 0, tendee->GetLimbs());
  if (tendee->GetBleeding()) tendee->AddBleeding(-1);
//	debug("healing " + healing + " damage " + damage + " amount " + amount);
	send_messages("tend", msg, tender, tendee, environment(tender));
	return amount;
}

	
int eventCollapse() {
    int position = GetPosition();
    
    SetParalyzed(3, (: checkCollapse :));
    if( position == POSITION_LYING ) {
	return 1;
    }
    send_messages("collapse", "$agent_name $agent_verb to the ground.",
		  this_object(), 0, environment());
    SetPosition(POSITION_LYING);
    return 1;
}

void eventHealStamina() {
  object who = this_object();
  if (GetInCombat() && GetPosition() != POSITION_LYING) { if (userp(this_object())) AddStaminaPoints(-8); }
  if (MINE_D->GetMining(this_object()))  { return; } 
  if (FARM_D->GetFarming(this_object())) { return; }
  if (!GetInCombat() || GetPosition() == POSITION_LYING)
    AddStaminaPoints((GetHealRate() * GetMaxStaminaPoints())/50);  
  return;
}

void eventCheckHealing() {
  int x, y; int swim;

  foreach(string l in GetLimbs()) {
    if (GetDying()) continue;
    if (member_array(GetParentLimb(l), GetMissingLimbs()) != -1) {
      eventPrint("Held up by nothing, your " + l + " falls off!");
      MissingLimbs[l] = Limbs[l];
      map_delete(Limbs, l);
    }
  } 
  x = GetHeartRate() * 10;
  if (environment()->GetProperty("ocean") || environment()->GetProperty("shallows")) {
    if (environment()->GetProperty("ocean"))    y = eventCheckSkill("swimming", 300, 0, 100);     
    if (environment()->GetProperty("shallows")) y = eventCheckSkill("swimming", 100, 0, 100);     
    AddStaminaPoints(-50);
    if (y < 0 || GetParalyzed() || GetSleeping()) {
       if (y > 0) y = 100;
       eventPrint("You are %^BOLD%^BLUE%^drowning!%^RESET%^");
       SetSleeping(0);
       eventReceiveDamage(load_object(STD_DUMMY "drowning"), DROWNING, absolute_value(y), 1);
     } else {
       eventPrint("You swim along carefully.");
     }
  }
  if( (y = time() - LastHeal)  >= x ) {
        LastHeal = time();
        do {
          eventHealDamage((GetHealRate() * GetMaxHealthPoints())/100, 1);  
          eventHealDamage((GetHealRate() * GetMaxHealthPoints())/100, 0, GetLimbs());
          AddMagicPoints((GetHealRate() * GetMaxMagicPoints())/100);
          eventHealStamina();
                   
          if (GetStaminaPoints() < 50) { if (!random(4)) eventCollapse();  }
          if (GetHealthPoints() != GetMaxHealthPoints() ||
              GetStaminaPoints() != GetMaxStaminaPoints() ||
              GetMagicPoints() != GetMaxMagicPoints() ) {
                if (playerp()) { eventDisplayStatus(); }
                }
        } while( (y = y - x) >= x );
    if (GetBlessed()) {
      AddBlessed(-1);
    }
    if (GetCursed()) {
      AddCursed(-1);
    }
    if (Bleeding) {
    	if (!GetUndead()) eventBleed(Bleeding);
   	  AddBleeding(-1);
  	  }  		
	if( Alcohol > 0 ) {
	    Alcohol--;
	    if( !Alcohol ) {
		message("my_action", "You are left with a pounding headache.",
			this_object());
		AddHealthPoints(-(random(3) + 1));
	    }
	    else if( !GetSleeping() && random(100) < 8 ) {
		string verb, adv;
		
		switch(random(5)) {
		    case 0: verb = "burp"; adv = "rudely"; break;
			    case 1: verb = "look"; adv = "ill"; break;
			    case 2: verb = "hiccup"; adv = "loudly"; break;
			    case 3: verb = "stumble"; adv = "clumsily"; break;
			    case 4: verb = "appear"; adv = "drunk"; break;
			}
		message("my_action", "You " + verb + " " + adv + ".",
			this_object());
		message("other_action", GetName() + " " + pluralize(verb) + " " +
			adv + ".", environment(), ({ this_object() }));
	    }
	}
	if( Sleeping > 0 ) {
	    Sleeping--;
	    if( !Sleeping ) {
		message("my_action", "You wake up!", this_object());
		message("other_action", GetName() + " wakes up from " +
			possessive(this_object()) + " deep sleep.",
			environment(this_object()), ({ this_object() }));
	    }
	    else if( random(100) < 8 ) {
		message("my_action", "You snore.", this_object());
		message("other_action", (string)this_player()->GetName() +
			" snores loudly.", environment(this_object()),
			({ this_object() }));
	    }
	}
  if ( Caffeine > 0) {
      Caffeine--;
      if (!Caffeine) eventPrint("You have completely calmed down.");
    }
	if( Food > 0 && userp(this_object()) ) Food--;
	if (Food > 50 && Food < 100) {
		if (!GetUndead())
		 eventPrint("You are getting hungry.");
		}
	if (Food < 50) {
		if (!GetUndead() && userp() ) {
		  eventPrint("You are starving.");
		  eventReceiveDamage(load_object(STD_DUMMY "hunger"), HUNGER, random(10), 1);
		  }
		}
	if( Drink > 0 && userp(this_object())) Drink--;
  if (Drink >= 50 && Drink <= 100) {
  	if (!GetUndead()) {
		  eventPrint("You are getting thirsty.");
		  }
    }
  if (Drink < 50) {
  	if (!GetUndead() && userp() ) {
		  eventPrint("You are dying of thirst.");
		  eventReceiveDamage(load_object(STD_DUMMY "thirst"), HUNGER, random(10), 1);
		  }
    }
  if (Smoke > 0) {
    Smoke--;
    if (!random(10)) {
      eventPrint("Your lungs burn from your recent smoking.");
      eventForce("cough");
      eventReceiveDamage(load_object(STD_DUMMY "hangover"), DISEASE, random(10), 1);
    }
  }
  if (Poison > 0) { 
  	Poison--;
  	send_messages("shiver", 
  	  "$agent_name $agent_verb as poison runs through $agent_possessive veins.",
  	  this_object(), 0, environment() );
  	eventReceiveDamage(load_object(STD_DUMMY "poison"), POISON, Poison, 1);
  	}
  }
}

void eventCompleteHeal(int x) {
    eventHealDamage(x, 1, GetLimbs());
    AddMagicPoints(x + 1);
    AddStaminaPoints(x);
}

mixed eventFall() {
    object env = environment();
    string dest;

    if( !env ) {
	return 0;
    }
    if( GetPosition() == POSITION_LYING ) {
	return 0;
    }
    if( env->GetMedium() == MEDIUM_LAND ) {
	return position::eventFall();
    }
    dest = env->GetGround();
    if( !dest ) {
	send_messages(({ "fall", "die" }), "$agent_name $agent_verb into a "
	              "dark abyss and $agent_verb.", this_object(), 0, env);
	SetPosition(POSITION_LYING);
	eventDie();
    }
    else {
	int p = random(100) + 1;
	int was_undead = GetUndead();

	send_messages("fall", "$agent_name $agent_verb through the sky "
		      "towards the world below.", this_object(), 0, env);
	eventMove(dest);
	environment()->eventPrint(GetName() + " comes falling in from above.",
				  this_object());
	SetPosition(POSITION_LYING);
	foreach(string limb in GetLimbs()) {
	    int hp = GetHealthPoints(limb);

	    p = (hp * p)/100;
	    eventReceiveDamage(load_object(STD_DUMMY "falling"), BLUNT, p, 0, ({ limb }));
	    if( Dying || (was_undead != GetUndead()) ) {
		break;
	    }
	}
    }
}

void eventCheckCold() {
	string climate;
	object env = environment();
	if (!env) return;
	
	climate = env->GetClimate();
	if (climate == "indoors" || climate == "underground") return;
        if (random(GetStatLevel("durability"))) return;
        if (random(5)) return;
        if (newbiep()) return;
        if (GetClass() == "animal") return;
	 new(STD_GERMS "cold")->eventInfect(this_object());
}

/* varargs int eventHealDamage(int x, int internal, mixed limbs)
 * int x - amount of damage being healed, negatives illegal (required)
 * int internal - internal damage flag (optional)
 * mixed limbs - limb or limbs affected by the heal event (optional)
 *
 * defaults
 * internal defaults to 0
 * limbs defaults to 0
 *
 * description
 * this event is triggered whenever something performs a healing action
 * on the body
 *
 * if the internal flag is set then overall health is healed.
 * if limbs are specified then the specified limbs are healed.
 * if the internal flag is NOT set and NO limbs are specified (default)
 *   then both overall health as well as the health of all limbs are healed.
 *
 * returns the actual amount of healing done or -1 if an error occurs
 */
varargs int eventHealDamage(int x, int internal, mixed limbs) {
    if(!limbs && !internal) {
	limbs = GetLimbs(); internal = 1;
    }
    else if(stringp(limbs)) {
	limbs = ({ limbs });
    }
    if(!limbs) {
	limbs = ({});
    }
    if( !arrayp(limbs)) {
	error("Bad argument 3 to eventHealDamage().\n");
    }
    if(internal) {
	AddHealthPoints(x);
    }
    map(limbs, (: AddHealthPoints($(x), $1) :));
    return x;
}

/* varargs int eventReceiveDamage(object agent, int type, int x, int internal, mixed limbs)
 * object agent - the living object responsible for this damage (required)
 * int type - the damage type(s) being done (required)
 * int x - the amount of damage being done, negatives illegal (required)
 * int internal - flag for internal or external damage (optional)
 * mixed limbs - limbs to which damage has been done (optional)
 *
 * defaults
 * internal defaults to 0
 * limbs defaults to 0
 *
 * description
 * handles sorting out damage events which happen to the body
 * It assumes some agent is acting as the cause of this event, an
 * agent being some sort of being as the cause of the event
 * the previous_object() is considered to be doing the actual damage
 * what does the damage is different than the agent in the sense
 * that a knife does damage and a living thing is the agent
 * can't get into more detail without getting philosophical, which is
 * beyond the scope of a comment
 * "x" amount of damage gets attempted, modified by varying things like
 * armour and natural resistence to this type of damage
 * the internal flag with no limbs specified means that the damage
 * is taken solely to the overall health
 * if the internal flag is set with limbs, the damage is both internal and
 * done to named limbs
 * if no internal flag is set and no limbs are specified, damage is done to
 * all limbs
 * if no internal flag is set and limbs are specified, then damage is done
 * only to the specified limbs
 * NOTE: internal damage is not modified by armour worn
 *
 * returns the average actual amount of damage done
 */

int eventArmourProtect(object agent, int type, int amount, int internal, string limb) {
	int x; object *worn;
	
	x = amount;
	if (!limb) return x;
	worn = GetWorn(limb);
	foreach(object w in worn) {
		int tmp = x;
		x -= w->eventReceiveDamage(agent, type, amount, internal, limb);
 if (GetTestChar() && GetProperty("combat_debug"))	debug(w->GetShort() + " blocked " + (tmp - x) + " damage from hitting the " + limb + ".");
	}
	return x;
}

varargs int GetDamageInflicted(object agent, int type, int x, int internal, mixed limbs) {
  int i, total, maxi, rec;

  if( internal ) {
    x = eventCheckResistance(x, type);    
    return x;
  }
  
  if (!limbs) limbs = GetRandomLimb("torso");
	if( stringp(limbs) ) { limbs = ({ limbs });  }
  if( !arrayp(limbs) ) { return -1;  }
  
  x = eventCheckProtection(agent, type, x);
  x = eventCheckResistance(x, type);
    
  foreach(string limb in limbs) {
  	x = eventArmourProtect(agent, type, x, 0, limb);
  }
  return x;
}

varargs int eventInflictDamage(object agent, int type, int x, int internal, mixed limbs) {
  int i, rec;
  
  if (!limbs) limbs = GetRandomLimb("torso");
	if( stringp(limbs) ) {
	  limbs = ({ limbs });
    }
  if( !arrayp(limbs) ) {
	  return -1;
    }
  if (x < 0) {
    write_file("players/negative_xp", identify(agent) + " hit for negative XP. \n" +
                                      "target: " + identify(this_object()) + "\n" +
                                      "limbs: " + implode(limbs, ", ") + "\n");
    foreach(string l in limbs) {
      write_file("players/negative_xp", "worn (" + l +"): " + identify(GetWorn(l)) + "\n");
    }
    return 0;
  }
  foreach(string limb in limbs) {
	  if (!GetLimb(limb)) continue;
	  if (x > GetHealthPoints(limb)) x = GetHealthPoints(limb);
	  if( !AddHealthPoints(-x, limbs[i], agent) ) 
      RemoveLimb(limbs[i], agent);
  }
 	AddHealthPoints(-x, 0, agent);
  rec = x/20;
  if (rec > 10) rec = 10;
  AddRecoveryTime(rec);

 	if (agent) {
    if (agent->GetOwner()) {
      if (present(agent->GetOwner(), environment(this_object()))) agent = present(agent->GetOwner(), environment(this_object()));
  	}
  	if (!userp() && GetOwner() != agent->GetKeyName()) {
  	  if ((GetLevel() + 20) > agent->GetLevel() || GetLevel() > 90) agent->AddExperience(x);
  	}
  }
  if (Sleeping) { eventPrint("You wake up!"); SetSleeping(0); }
  return x;
}

varargs int eventReceiveDamage(object agent, int type, int x, int internal, mixed limbs) {
  int i, total, maxi, rec;
  if (GetTestChar() && GetProperty("combat_debug"))  debug("x = " + x + ", internal = " + internal);
  if( internal ) {
    x = eventCheckResistance(x, type);
    AddHealthPoints(-x, 0, agent);
    rec = x/20;
    if (rec > 10) rec = 10;
    AddRecoveryTime(rec);
  if (GetTestChar() && GetProperty("combat_debug"))  debug("internal damage -> " + x);
  	if (agent) {
  	  if (agent->GetOwner()) {
  	    if (present(agent->GetOwner(), environment(this_object()))) agent = present(agent->GetOwner(), environment(this_object()));
  	  }
  	   	 if (!userp() && GetOwner() != agent->GetKeyName()) {
  	   	  if (x > GetMaxHealthPoints()) x = GetMaxHealthPoints();
  	   	  if ((GetLevel() + 20) > agent->GetLevel() || GetLevel() > 90) agent->AddExperience(x);
  	   	 }
  	}    
    return x;
    }
  if (!limbs) limbs = GetRandomLimb("torso");
	if( stringp(limbs) ) {
	  limbs = ({ limbs });
    }
  if( !arrayp(limbs) ) {
	  return -1;
    }
  
  x = eventCheckProtection(agent, type, x);
  total = 0;
  foreach(string limb in limbs) {
  	int tmp;
  	tmp = eventArmourProtect(agent, type, x, 0, limb);
  	if (tmp > 0) {
  		tmp = eventCheckResistance(tmp, type);
  		if (tmp > GetHealthPoints(limb)) tmp = GetHealthPoints(limb);
  		total += tmp;
  if (GetTestChar() && GetProperty("combat_debug"))	debug(tmp + " damaged leaked through on the " + limb);
  		if( !AddHealthPoints(-tmp, limbs[i], agent) ) 
           	 RemoveLimb(limbs[i], agent);
      }
  }
  if( total ) {
  	AddHealthPoints(-total, 0, agent);
  	rec = x/20;
    if (rec > 10) rec = 10;
    AddRecoveryTime(rec);
  if (GetTestChar() && GetProperty("combat_debug")) 	debug("Leaked damage to HP: " + total);
  	if (agent) {
  	  if (agent->GetOwner()) {
  	    if (present(agent->GetOwner(), environment(this_object()))) agent = present(agent->GetOwner(), environment(this_object()));
  	  }
  	 if (!userp() && GetOwner() != agent->GetKeyName()) {
  	  if ((GetLevel() + 20) > agent->GetLevel() || GetLevel() > 90) agent->AddExperience(total);
  	  }
  	}
  	return total;
  	}
 if (GetTestChar() && GetProperty("combat_debug")) debug("return 0");
  return 0;
}

int eventCheckResistance(int amount, int type) {
  int num_types = 0; 
  string resistance;
  int amt_ea, i = 0;
  
  amt_ea = amount;
  amount = 0;
  
  while ((1 << i) <= MAX_DAMAGE_BIT) {
  	if (type & (1 << i)) { 
  		num_types++;
  	if (GetTestChar() && GetProperty("combat_debug")) debug("Tested Positive on i = " + i);
  		}
  	i++;
  }
  amt_ea = (amt_ea/num_types);
  i = 0;
  while ((1 << i) <= MAX_DAMAGE_BIT) {
  	if ((1 << i) & type) {
  		resistance = GetResistance((1 << i));
  	if (GetTestChar() && GetProperty("combat_debug")) debug("Resistance Check for (1 << " + i + ") = " + resistance);
  		switch(resistance) {
  			case "weakness": amount += amt_ea * 2;   break;
  			case "none"    : amount += amt_ea;       break;
        case "low"     : amount += (3*amt_ea)/4; break;
        case "medium"  : amount += (amt_ea/2);   break;
        case "high"    : amount += (amt_ea/4);   break;
        case "immune"  : break;
      }
    }
    resistance = "";
  	i++;
  }
  if (GetTestChar() && GetProperty("combat_debug")) debug("num_types " + num_types + ", amount = " + amount + ", amt_ea = " + amt_ea);
  return amount;
}


/*  int eventCheckProtection(object agent, int type, int damage)
 *
 *  agent  : object doing the damage
 *  type   : damage type(s)
 *  damage : original amount damage being done
 *
 *  This function cycles through any magic protection found, reducing
 *  damage accordingly.
 *
 *  returns modified damage
 */
int eventCheckProtection(object agent, int type, int damage) {
    int i, y;
    if( !i = sizeof(Protection) ) return damage;
    while(i--) {
        float damratio = 0.0;
        int x;
	
        int numdamtypes=0; // numdamtypes will be the number of damage
                           // types that the incoming damage is.
        int shieldedcount=0; // shielded count will be the number of
                             // damage types, within those being dealt,
                             // that the current shield protects against.
        for(int tempcnt=1; tempcnt<MAX_DAMAGE_BIT; tempcnt= (tempcnt << 1)) {
          if(tempcnt & type)
            numdamtypes++;
        }
        for(int tmpcntb=1; tmpcntb<MAX_DAMAGE_BIT; tmpcntb = (tmpcntb << 1)) {
          if(tmpcntb & type & Protection[i]->bits)
            shieldedcount++;
        }

        if(numdamtypes == 0)
          numdamtypes = 1;
        damratio = 1.0 * shieldedcount / numdamtypes;
                      // damratio is now the percent of the damage being
                      // dealt that should be reduced by the shield.
                      // All lines that end up subtracting the damage
                      // done from the shield health or the shield protection
	              // from the damage done are multiplied by this.

        if( (type & Protection[i]->bits) == 0 ) continue;
        if( Protection[i]->absorb ) {
            if( (x = (Protection[i]->absorb - damage * damratio)) < 1 ) {
                x = Protection[i]->absorb;
                RemoveMagicProtection(i);
                damage -= x * damratio;
                if( damage < 1 ) return 0;
                continue;
            }
            Protection[i]->absorb -= damage * damratio;
        }
        else if( Protection[i]->protect )
            x = (random(Protection[i]->protect / 2) +
                (Protection[i]->protect / 2));
        else {
            RemoveMagicProtection(i);
            continue;
        }
        if( y = functionp(Protection[i]->hit) ) {
            if( y == FP_OWNER_DESTED ) {
                RemoveMagicProtection(i);
                continue;
             }
            else x = (int)evaluate(Protection[i]->hit, this_object(),
                                    agent, x, Protection[i]);
        }
        damage -= (x>damage? damage:x) * damratio;
        if( damage < 1 ) return 0;
    }
    return damage;
}

/* varargs int eventDie(object agent)
 * object agent - the agent responsible for the death (optional)
 *
 * description
 * Kills the owner of this body if not already dying
 *
 * returns true if the thing is dying
 */
varargs int eventDie(object agent) {
    int x;
    int q = sizeof(GetMagicProtection());
    while(q--) {
      RemoveMagicProtection(q);
    }
    ClearShortSuffixes();
    SetParalyzed(2);
    SetRecoveryTime(0);
    x = GetUndead();
    if( agent ) {
  	  if (agent->GetOwner()) {
  	    if (present(agent->GetOwner(), environment(this_object()))) agent = present(agent->GetOwner(), environment(this_object()));
  	  }
        if (GetOwner() != agent->GetKeyName()) {
          if ((GetLevel() + 20) > agent->GetLevel() || GetLevel() > 90) agent->AddExperience(150 * (GetLevel() + 1));
          }
        if( x ) agent->eventDestroyEnemy(this_object());
        else agent->eventKillEnemy(this_object());
    }
    if( environment() ) {
        object *obs;
        string *currs;
        object ob;
        string curr;
        int i;


        if (NoCorpse) { ob = environment(); } else { ob = new(LIB_CORPSE); }
        ob->SetCorpse(this_object());
        if (agent) ob->SetKiller(agent);
        ob->eventMove(environment(this_object()));
        obs = filter(all_inventory(), (: !((int)$1->GetRetainOnDeath()) :));
        i = sizeof(obs);
        while(i--) obs[i]->eventMove(ob);
        currs = (string *)this_object()->GetCurrencies() || ({});
        foreach(curr in currs) {
            object pile;
            int amt;

            if( amt = (int)this_object()->GetCurrency(curr) ) {
                pile = new(LIB_PILE);
                pile->SetPile(curr, amt);
                pile->eventMove(ob);
                this_object()->AddCurrency(curr, -amt);
            }
        }
        // note that the corpse will get to their cemetery before them. eh, whatchagonnado.
        if( playerp(this_object()) && this_object()->GetTown() ) {
          if( SETUP_D->GetCemetery(this_object()->GetTown()) ) {
            // godfuckingdammitall, Lisht.
            if ( this_object()->GetTown() != "Lisht" ) {
              ob->eventMove(SETUP_D->GetCemetery(this_object()->GetTown()));
            } else if (this_object()->GetRace() == "elf") {
              ob->eventMove("/domains/xandria/towns/lisht/room/elf/healer");
            } else {
              ob->eventMove("/domains/xandria/towns/lisht/room/gnoll/graveyard");
            }
          } 
        }
    }
    SetUndead(!x);
    SetBleeding(0);
    ResetConditions();
    ResetCooldowns();
    call_out( function() { Dying = 0; }, 0);
    return 1;
}

/* int eventRemoveItem(object ob)
 * object ob - the item being removed
 *
 * Removes a worn or wielded item from the list
 *
 * returns 1 on success, 0 on failure
 */
int eventRemoveItem(object ob) {
    string limb;

    foreach(limb in keys(WornItems)) {
        if( !WornItems[limb] ) continue;
        if( member_array(ob, WornItems[limb]) != -1) {
	    WornItems[limb] -= ({ ob });
	}
    }
    return 1;
}

/* int eventWear(object ob, mixed limbs)
 * object ob - the item being worn (wielded)
 * mixed limbs - string or array of limbs on which it is being worn
 *
 * description
 * marks the limbs "limbs" as being protected by the armour "ob"
 *
 * returns 1 if successful, 0 if failure
 */
int eventWear(object ob, mixed limbs) {
    string limb;
// debug("eW " + implode(limbs, ","));
    if( stringp(limbs) ) {
      limbs = ({ limbs });
    }
    foreach(limb in limbs) {
        if( !WornItems[limb] ) WornItems[limb] = ({ ob });
          else WornItems[limb] += ({ ob });
    }
    return 1;
}

/************     /lib/body.c Data manipulation functions      *************/
void NewBody(string race) {
    if(!race)
      Limbs = ([ (Torso = "ooze") : ([ "parent" : 0, "children" : ({}),
      "health" : 50, "class" : 1, "armours" : 0 ]) ]);
    else Limbs = ([]);
    MissingLimbs = ([]);
    Fingers = ([]);
    Bleeding = 0;
}

mixed CanWield(object ob, string *limbs) {
  string limb;
  string short = ob->GetShort();
//debug("CW " + implode(limbs, ","));
  if (GetConditionFlag(CONDITION_PREVENT_WIELD)) return "You cannot wield right now.";
  foreach(limb in limbs) {
    object worn_item;
    int tmp = 0;
    if (!Limbs[limb]) return "You don't seem to have a " + limb + "!";
    if( !(Limbs[limb]["armours"] & A_WEAPON) ) { return "You cannot wield with your " + limb + "."; }
 
    if( !WornItems[limb] ) continue; /* nothing there, ok */
    foreach(worn_item in WornItems[limb]) {
        if( !worn_item ) continue;
        tmp += (int)worn_item->GetArmourType();
    }
    /* again, not allowing 2 weapons or a shield and weapon */
    if(tmp & (A_SHIELD | A_WEAPON)) {
      return "You cannot wield " + short + " there right now.";
      }
    }
  return 1;
}

mixed CanWear(object ob, string *limbs) {
  string limb;
  string short = ob->GetShort();
  int a_type   = ob->GetArmourType();
  int a_class  = ob->GetArmourClass();
  object *worn; int x; object *clothing;
  
  if (a_type == A_WEAPON) return CanWield(ob, limbs);
  if (!limbs || !sizeof(limbs)) return "Wear " + short + " where?";
  foreach(limb in limbs) {
    if (!Limbs[limb]) return "You have no " + limb + "!";
    if( !(Limbs[limb]["armours"] & a_type) ) return "You cannot wear " + short + " on your " + limb + "!";
  }
  if (a_type == A_RING) {
    worn = GetWorn(limbs[0]);
    x = sizeof(filter(worn, (: $1->GetArmourType() == A_RING :)));
    if (x >= GetFingers(limbs[0])) return "You have no more fingers to wear a ring on your " + limbs[0] + ".";
  }
  if (a_type == A_LONG_SOCK || a_type == A_LONG_BOOT || a_type == A_LONG_GLOVE) {
    if (sizeof(limbs) != 2) return capitalize(GetShort()) + " must be worn on adjoining limbs.";
    if (GetParentLimb(limbs[0]) != limbs[1] && GetParentLimb(limbs[1]) != limbs[0])
      return "Your " + limbs[0] + " is not connected to your " + limbs[1] + ".";
    }
  /* check for clothing */
  foreach(limb in limbs) {
    worn = GetWorn(limb);
    clothing = filter(worn, (: $1->GetArmourClass() == ARMOUR_CLOTH :) );
    worn -= clothing;
 //  debug("c: " + conjunction(clothing->GetKeyName(), "and"));
 //  debug("w: " + conjunction(worn->GetKeyName(), "and"));
    x = 0;
    if (a_class == ARMOUR_CLOTH && sizeof(clothing)) {
      foreach(object worn_item in clothing) {
        if (worn_item->GetArmourType() != A_RING) x += worn_item->GetArmourType();
      }
      if ((a_type & x) && a_type != A_RING) {
        return "You are already wearing clothing of that type on your " + limb + "!";
      }
    }
    x = 0;
    if (a_class != ARMOUR_CLOTH && sizeof(worn)) {
      foreach(object worn_item in worn) {
        if (worn_item->GetArmourType() != A_RING) x += worn_item->GetArmourType();
      }
      if ((a_type & x) && a_type != A_RING) {
        return "You are already wearing a " + armour_type_string(a_type) + " on your " + limb + "!";
      }
    }
  }
  return 1;
}
    
  

/* int AddLimb(string limb, string parent, int classes, int *armours)
 * string limb - the limb being added (required)
 * string parent - the limb to which this one is being attached (required)
 * int classes - rating of the limb's strength (optional)
 * int *armours - the types of armours which can be worn here (optional)
 *
 * defaults
 * classes defaults to 1
 * armours defaults to ({})
 *
 * description
 * adds the named limb to the body, attached at the named point
 * the limb classes starts at 1 for a torso (strongest)
 * to whatever the documentation rates as the weakest
 *
 * returns 1 on success, 0 on failure
 */
varargs int AddLimb(string limb, string parent, int classes, int *armours) {
    int arm = 0;

    if(!limb || Limbs[limb] || (parent && !Limbs[parent])) return 0;
    if(armours) {
        int i;

        i = sizeof(armours);
        while(i--) arm |= armours[i];
    }
    if(MissingLimbs[limb]) map_delete(MissingLimbs, limb);
    if( parent ) Limbs[parent]["children"] += ({ limb });
    else Torso = limb;
    if( !classes ) classes = 5;
    Limbs[limb] = ([ "parent" : parent, "children" : ({}), "class" : classes,
      "armours" : arm ]);
    Limbs[limb]["health"] = GetMaxHealthPoints(limb);
    return 1;
}

int RestoreLimb(string limb) {
    string parent;
    if( !MissingLimbs[limb] ) return 0;
    Limbs[limb] = MissingLimbs[limb];
    // added below to re-attach limb to parent - not sure how long this
    // has been an issue, but it was breaking the new armours command.
    // - Mel 2015-12-04
    if (GetLimbParent(limb)) {
	parent = GetLimbParent(limb);
	Limbs[parent]["children"] += ({ limb });
	}
    Limbs[limb]["health"] = GetMaxHealthPoints(limb);
    map_delete(MissingLimbs, limb);
    return 1;
}

/* int DestLimb(string limb)
 * string limb - the limb being removed
 *
 * description
 * removes a limb from the limbs mapping.  The limb isn't marked as mising,
 * and the monster doesn't die even if you remove a fatal limb.  Useful for
 * removing limbs from standard race types.  Removing the torso isn't allowed.
 *
 * returns -1 on error, 0 on failure, 1 on success
 */
int DestLimb(string limb) {
    string *kiddies;
    int i;

    if(!limb || !Limbs[limb]) return -1;
    if(!Limbs[limb]["parent"]) {
        return -1;
    }
    Limbs[Limbs[limb]["parent"]]["children"] -= ({ limb });
    if( (i = sizeof(kiddies = Limbs[limb]["children"])) )
      while(i--) DestLimb(kiddies[i]);
    map_delete(Limbs, limb);
    return 1;
}

/* int RemoveLimb(string limb, object agent)
 * string limb - the limb being removed
 * object agent - the agent who is responsible for the limb removal
 *
 * description
 * removes a limb from the limbs mapping and stores vital data in the
 * missing limbs mapping
 *
 * returns -1 on error, 0 on failure, 1 on success
 */
int RemoveLimb(string limb, object agent) {
    string *kiddies;
    int i;

    if(!limb || !Limbs[limb]) return -1;
    if(!Limbs[limb]["parent"] || Limbs[limb]["class"] == 1) {
        HealthPoints = 0;
        if( !Dying ) {
            Dying = 1;
            call_out((: eventDie, agent :), 0);
        }
    }
    if (limb == GetTorso()) return 0;
    MissingLimbs[limb] = Limbs[limb];
    if( (i = sizeof(kiddies = MissingLimbs[limb]["children"])) )
      while(i--) RemoveLimb(kiddies[i], agent); 
    Limbs[Limbs[limb]["parent"]]["children"] -= ({ limb });
    map_delete(Limbs, limb);
    if( environment() ) {
        object ob = environment();

        message("environment", possessive_noun(GetName()) + " " + limb +  " is severed!", environment(), ({ this_object() }));
        message("environment", "Your "+ limb + " is severed!", this_object());
        if (living(this_object())) {   //(userp(this_object())) {
	      if(!userp(agent)) {
		//debug("Limb severed by NON-USER ->"  + agent->GetKeyName());
		AddBleeding(10); 
		} else {
		//debug("Limb severed by USER -> " + agent->GetCapName());
		AddBleeding(10, agent);
		}
	} /* new_bleeding -- should cause npc bleeding too */
        if (agent) {
          if (userp(agent) && limb == "head") agent->AddSeveredHead(1);
          }
        if (!GetNoCorpse()) {
          ob = new(LIB_LIMB);
          ob->SetLimb(limb, GetCapName(), GetRace());
          ob->eventMove(environment());
        }
      if (sizeof(WornItems[limb]))
      foreach(object item in WornItems[limb]) {
        string *tmp = item->GetWorn();
        if (sizeof(tmp) > 1) {
          item->SetWorn(tmp - ({ limb }));
        } else {
          item->eventUnequip(this_object());
          item->eventMove(ob);
        }
      }
    }
    if (agent) {
  	  if (agent->GetOwner()) {
  	    if (present(agent->GetOwner(), environment(this_object()))) agent = present(agent->GetOwner(), environment(this_object()));
  	  }
    if (GetOwner() != agent->GetKeyName()) {
    	if ((GetLevel() + 20) > agent->GetLevel() || GetLevel() > 90) agent->AddExperience(5 * (GetLevel() +1 ));
    	}
    }
    return 1;
}

mapping GetLimb(string limb) {
    if(!limb || !Limbs[limb]) return 0;
    else return copy(Limbs[limb]);
}

/* string GetRandomLimb(string targ)
 * string targ - the targetted limb
 *
 * description
 * returns a random limb weighted towards the targetted limb
 */

string GetRandomLimb(string targ) {
    string array limbs;

    if( !targ ) {
	targ = GetTorso();
    }
    if( member_array(targ, (limbs=keys(Limbs))) == -1) {
	targ= GetTorso(); /* no target or illegal target, weight torso */
    }
    targ = (limbs + (targ ? ({ targ, targ }) : ({})))[random(sizeof(limbs)+2)];
    return targ;
}

string GetTorso() {
    string *limbs;
    int i;

    i = sizeof(limbs = keys(Limbs));
    while(i--) {
	if(!Limbs[limbs[i]]["parent"]) {
	    return limbs[i];
	}
    }
    return 0;
}

string array GetLimbs() {
    return (Limbs ? keys(Limbs) : 0);
}

int GetLimbClass(string limb) { 
  if (!sizeof(Limbs)) return 0;
  if (!Limbs[limb]) return 0;
  return Limbs[limb]["class"]; 
}

string GetLimbParent(string limb) { 
  if (!Limbs[limb]) { return 0; } 
  return Limbs[limb]["parent"]; 
}

string GetParentLimb(string limb) {
   if (!Limbs[limb]) { return 0; }
   return Limbs[limb]["parent"];
}  // Added due to idiocy in DescartesCode[tm]

string array GetLimbChildren(string limb) {
    return Limbs[limb]["children"] + ({});
}

mapping GetMissingLimb(string limb) {
    return (limb ? copy(MissingLimbs[limb]) : 0);
}

string array GetMissingLimbs() { return keys(MissingLimbs); }

string GetLong(string nom) {
    string *limbs;
    string str;
    float h;
    
    str = (nom = capitalize(nom));
    h = percent(GetHealthPoints(), GetMaxHealthPoints());
    if( h < 10.0 ) str += " is mortally wounded.\n";
    else if( h < 20.0 ) str += " is near death.\n";
    else if( h < 30.0 ) str += " is severely injured.\n";
    else if( h < 40.0 ) str += " is badly injured.\n";
    else if( h < 50.0 ) str += " is hurt.\n";
    else if( h < 60.0 ) str += " is slightly injured.\n";
    else if( h < 70.0 ) str += " has some cuts and bruises.\n";
    else if( h < 80.0 ) str += " is in decent shape.\n";
    else if( h < 90.0 ) str += " is quite keen.\n";
    else str += " is in top condition.\n";
    limbs = GetMissingLimbs();
    if( sizeof(limbs) ) {
	int i, maxi;

	str += nom + " is missing " + add_article(limbs[0]); 
	for(i=1, maxi = sizeof(limbs); i<maxi; i++) {
	    if( i < maxi-1 ) str += ", " + add_article(limbs[i]);
	    else {
		if( maxi > 2 ) str += ",";
		str += " and " + add_article(limbs[i]);
	    }
	}
	str += ".\n";
    }
     if (GetBleeding() > 30) 
        str += nom + " is %^BOLD%^RED%^severely bleeding%^RESET%^";
     if (GetBleeding() > 10 && GetBleeding() <= 30) 
        str += nom + " is %^BOLD%^RED%^mildly bleeding%^RESET%^";
     if (GetBleeding() && GetBleeding() <= 10)
        str += nom + " is %^BOLD%^RED%^slightly bleeding%^RESET%^";
    if (GetBleeding())
        str += ".\n";
    return str;
}

string array GetWieldingLimbs() {
    return filter(keys(Limbs), (: (Limbs[$1]["armours"] & A_WEAPON) :));
}

/* int AddFingers(string limb, int x)
 * string limb - the limb to which fingers will be added
 * int x - the number of fingers being added, can be negative
 *
 * description
 * adds the given number of fingers to the given limb
 *
 * returns the total number of fingers after addition
 */

varargs int AddFingers(string limb, int x) {
    if((Fingers[limb] += x) < 1) Fingers[limb] = 1;
    return Fingers[limb];
}

int GetFingers(string limb) {
    return Fingers[limb];
}

varargs object *GetWorn(string limb) {
    if(!limb) {
        object *ret = ({});
        string *limbs;
        int i;

        i = sizeof(limbs = keys(Limbs));
        while(i--) if(WornItems[limbs[i]]) ret += ({ WornItems[limbs[i]] });
        return distinct_array(ret);
    }
    else if(!WornItems[limb]) return ({});
    else return (WornItems[limb] + ({}));
}

varargs mixed GetWielded(string limb) {
    if(!limb) {
        object *ret = ({});
        string *limbs;
        int i;

        i = sizeof(limbs = keys(Limbs));
        while(i--) {
            if(!WornItems[limbs[i]]) continue;
            else ret += filter(WornItems[limbs[i]],
              (: (int)$1->GetArmourType() == A_WEAPON :));
        }
        return distinct_array(ret);
    }
    else if(!WornItems[limb]) return 0;
    else {
        object *ret;

        ret = filter(WornItems[limb], (: (int)$1->GetArmourType() == A_WEAPON :));
        if(sizeof(ret)) return ret[0];
        else return 0;
    }
}

/* varargs static int AddHealthPoints(int x, string limb, object agent)
 * int x - number of points being added, may be negative (required)
 * string limb - the limb to which health is being added (optional)
 * object agent - the living responsible for this damage
 *
 * defaults
 * limb defaults to 0
 *
 * description
 * if the value of limb is not zero, then "x" number of health points will
 * be added to limb "limb"
 * if he value is 0, then the overall health points will be modified
 *
 * returns the remaining number of health points for the limb in question
 * or for the overall health points
 */

varargs int AddHealthPoints(int x, string limb, object agent) {
    int y;

    if( limb ) {
        if( !Limbs[limb] ) return -1;
        if((Limbs[limb]["health"] += x) < 1) Limbs[limb]["health"] = 0;
        else if(Limbs[limb]["health"] > (y = GetMaxHealthPoints(limb)))
          Limbs[limb]["health"] = y;
        return Limbs[limb]["health"];
    }
    else {
        if((HealthPoints += x) < 1) HealthPoints = 0;
        else if(HealthPoints > (y = GetMaxHealthPoints())) HealthPoints = y;
        if( HealthPoints < 1 ) {
            if( !Dying ) {
                Dying = 1;
                call_out( (: eventDie, agent :), 0);
            }
        }
	else {
	    float h = percent(GetHealthPoints(), GetMaxHealthPoints());

	    if( h < COLLAPSE_AT ) {
		eventCollapse();
	    }
	}
        return HealthPoints;
    }
}

varargs int GetHealthPoints(string limb) {
    if(limb) {
        if(!Limbs[limb]) return -1;
        else return Limbs[limb]["health"];
    }
    else return HealthPoints;
}

varargs int GetMaxHealthPoints(string limb) { return 0; }

/* int AddMagicPoints(int x)
 * int x - the number of magic points being added, may be negative
 *
 * description
 * adds magic points to the body
 *
 * returns the remaining magic points
 */

int AddMagicPoints(int x) {
    int y;

    if((MagicPoints += x) < 1) MagicPoints = 0;
    else if(MagicPoints > (y = GetMaxMagicPoints())) MagicPoints = y;
    return MagicPoints;
}

int GetMagicPoints() { return MagicPoints; }

int GetMaxMagicPoints() { return 0; }

/* int AddStaminaPoints(int x)
 * int x - number of stamina points being added
 *
 * description
 * adds "x" stamina points, can be negative
 *
 * returns the remaining number of stamina points
 */

float AddStaminaPoints(mixed x) {
    float y;

    if( !intp(x) && !floatp(x) )
      error("Bad argument 1 to AddStaminaPoints().\n");
    if( intp(x) ) x = to_float(x);
    if((StaminaPoints += x) < 0.1) StaminaPoints = 0.0;
    else if(StaminaPoints > (y = GetMaxStaminaPoints())) StaminaPoints = y;
    checkCollapse();
    return StaminaPoints;
}

int GetStaminaPoints() { return to_int(StaminaPoints); }

float GetMaxStaminaPoints() {  return 0; }

varargs int SetBleeding(int x, object who) {
	mixed k;
        if (GetDying()) {
	    return 1;
        }
	if (!mapp(PersistentDamages["bleeding"])) {
		//debug("Bleeding isn't a mapping, creating");
		PersistentDamages["bleeding"] = ([]);
	}
	foreach(k in keys(PersistentDamages["bleeding"])) {
		//debug("Deleting mapping: " + k + ".");
		map_delete(PersistentDamages["bleeding"], k);
		//debug("Size of bleeding map: " + sizeof(PersistentDamages["bleeding"]) + ".");
	}
	if (playerp(who)) {
		PersistentDamages["bleeding"][who] = x;
	} else {
		PersistentDamages["bleeding"]["generic"] = x;
	}
	return Bleeding = x; 
}

mixed GetBleedingInfo() {
	string ret = "";
	mixed k;
	string nom = "generic";
	if (sizeof(keys(PersistentDamages["bleeding"])) > 0) {
		foreach( k in keys(PersistentDamages["bleeding"])) {
			if (objectp(k)) {
				if (playerp(k)) nom = k->GetCapName();
			} else {
				if (k == "generic") nom = "generic";
			}
			ret += sprintf("%s : %d, ", nom, PersistentDamages["bleeding"][k]);
		}
	}
	return ret;
}

varargs int AddBleeding(int x, object who) {
	mixed k;
	int current_bleeding = Bleeding;
	int accounted_for_sources;
        Bleeding = 0; /* reset bleeding for later calcs */

        if (member_array("bleeding", keys(PersistentDamages)) == -1) {
            PersistentDamages["bleeding"] = ([]);
        }

	if (x < 0) { /* we're getting healed */
		mixed a;
		int num_of_agents = sizeof(PersistentDamages["bleeding"]);

		if (num_of_agents > 0) { /* should always be true because of generic */
			mixed amt_to_heal_per_agent = abs(x) / num_of_agents;

			if(floatp(amt_to_heal_per_agent)) { 
				amt_to_heal_per_agent = to_int(amt_to_heal_per_agent);
			}
			if(amt_to_heal_per_agent < 1) {
				amt_to_heal_per_agent = 1;
			}
			
			foreach(a in keys(PersistentDamages["bleeding"])) {
				PersistentDamages["bleeding"][a] -= amt_to_heal_per_agent;
			}
		}
	} else { /* we're adding bleeding, categorize appropriately */
		if (who && playerp(who)) {
			/* Damage from a player, get that XP, woot */
			PersistentDamages["bleeding"][who] += x;
		} else {
			/* Damage from any other source, even npc, throw to generic */
			PersistentDamages["bleeding"]["generic"] += x;
		}
	}

	/* square up, remove mappings that no longer exist and set bleeding total */
	if (sizeof(keys(PersistentDamages["bleeding"])) > 0) {
		foreach(k in keys(PersistentDamages["bleeding"])) {
			if (PersistentDamages["bleeding"][k] <= 0 && k != "generic") {
				map_delete(PersistentDamages["bleeding"], k);
			} else {
				Bleeding += PersistentDamages["bleeding"][k];
			}
		}
	} else {
		Bleeding = 0;
	}
  if (Bleeding <= 0) {
  	eventPrint("You are no longer bleeding.");
	SetBleeding(0);
  	Bleeding = 0;
  }
  if (Bleeding >= 200) Bleeding = 200;
  return Bleeding;
}

varargs int GetBleeding(object who) { return Bleeding; }

int AddMagicProtection(class MagicProtection cl) {
    if( ( !cl->absorb && !(cl->protect && cl->time) ) ||
        ( cl->hit && !functionp(cl->hit) ) ||
        ( cl->end && !functionp(cl->end) ) ||
        ( !cl->bits )
      ) {
        error("Illegal class setting passed to AddMagicProtection.\n");
        return 0;
      }
    cl->timestamp = time();
  if (sizeof(Protection) >= 5) return 0;
    Protection += ({ cl });
    return 1;
}

class MagicProtection array GetMagicProtection() { return Protection; }
string *GetMagicProtectionNames() {
  string *tmp = ({ });
  foreach(class MagicProtection x in Protection) {
    tmp += ({ x->name });
    }
  return tmp;
}

int RemoveMagicProtection(int i) {
    if( i > sizeof(Protection) - 1 ) return 0;
    if( Protection[i]->end ) {
	if( !(functionp(Protection[i]->end) & FP_OWNER_DESTED) ) {
	    evaluate(Protection[i]->end, this_object());
	}
    }
    Protection -= ({ Protection[i] });
    return 1;
}

int GetDying() { return Dying; }

int SetSleeping(int x) { return (Sleeping = x); }

int GetSleeping() { return Sleeping; }

int SetHiding(int x) { return Hiding = x; }
int GetHiding() { return Hiding; }

int AddAlcohol(int x)
{
    if ((Alcohol + x) < 0)
    {
	return (Alcohol = 0);
    }
    
    return (Alcohol += x);
}

int GetAlcohol() { return Alcohol; }

int AddCaffeine(int x) { 
  Caffeine += x;
  if (Caffeine < 0) Caffeine = 0;
  return Caffeine;
}

int GetCaffeine() { return Caffeine; }

int AddDrink(int x) { Drink += x; if (Drink < 0) Drink = 0; return Drink; }

int GetDrink() { return Drink; }

int AddFood(int x) { Food += x; if (Food < 0) Food = 0; return Food; }

int GetFood() { return Food; }

int AddSmoke(int x) { Smoke += x; if (Smoke < 0) Smoke = 0; return Smoke; }

int GetSmoke() { return Smoke; }

int AddPoison(int x) {
    Poison += x;
    if( Poison < 1 ) {
	Poison = 0;
    }
    return Poison;
}

int SetPoison(int x) { return Poison = x; }

int GetPoison() { return Poison; }

string GetResistance(int type) { return "none"; }

string GetRace() { return 0; }

string GetName() { return 0; }

string GetCapName() { return 0; }

int GetHeartRate() {
    int rate;

    rate = (GetAlcohol() - GetCaffeine());
    if( rate > 50 ) rate = 6;
    else if( rate > 25 ) rate = 5;
    else if( rate > 0 ) rate = 4;
    else if( rate > -25 ) rate = 3;
    else rate = 2;
    rate += HeartModifier;
    if( rate < 1 ) {
	rate = 1;
    }
    else if( rate > 10 ) {
	rate = 10;
    }
    return rate;
}

int GetHealRate() {
    int heal = 1;
    
    if (Blessed > 0) heal += 5;
    if (Cursed > 0) heal -= 5;
    if (Sleeping) heal += 5;
    if (GetPosition() == POSITION_LYING) heal += 2;
    if (GetPosition() == POSITION_SITTING) heal += 1;
    if (Food > 100) heal += 1;
    if (Drink > 100) heal += 1;
    if (Food < 50) heal -= 3;
    if (Drink < 50) heal -= 2;
    if (GetAlcohol() > (GetStatLevel("durability")/10)) { heal += 5; }
    if (newbiep()) heal += 5;
    if (heal < 0) heal = 0;
    if (!Food || !Drink) return 0;
    return heal;
}

string GetHealthShort() {
    string cl, sh;
    float h;

    if( !(sh = GetShort()) ) return 0;
    h = percent(GetHealthPoints(), GetMaxHealthPoints());
    if( h > 90.0 ) cl = "%^BOLD%^GREEN%^";
    else if( h > 75.0 ) cl = "%^GREEN%^";
    else if( h > 50.0 ) cl = "%^BOLD%^BLUE%^";
    else if( h > 35.0 ) cl = "%^BLUE%^";
    else if( h > 20.0 ) cl = "%^BOLD%^RED%^";
    else cl = "%^RED%^";
    return cl + capitalize(sh);
}
/*
mixed SetProtect(function f) { return (Protect = f); }

function GetProtect() { return Protect; }
*/
int GetHeartModifier() {
    return HeartModifier;
}

object *GetUniqueWorn() {
	object *worn = ({});
	foreach(string limb in GetLimbs()) {
	  worn += GetWorn(limb);
	}
	return distinct_array(worn);
}

int GetWarmth() {
	int x = 0;
	foreach(object o in GetUniqueWorn()) {
		x += o->GetWarmth();
		}
	x += environment()->GetRoomWarmth();
	foreach(object ob in all_inventory()) {
	  if (ob->GetProperty("germ")) x += ob->GetWarmth();
	  }
	return x;
}

varargs int AddHeartModifier(int x, int t) {
    HeartModifier += x;
    if( t > 0 ) {
	call_out((: AddHeartModifier(-$(x)) :), t);
    }
    return HeartModifier;
}

int SetNoCorpse(int x) { return NoCorpse = x; }

int GetNoCorpse() { return NoCorpse; }

int GetBlessed() { return Blessed; }

int AddBlessed(int x) { 
  if ((Blessed + x) <= 0) {
    if (Blessed) eventPrint("%^MAGENTA%^Your blessing fades.%^RESET%^");
    return Blessed = 0;
  }
  if (x > 0) eventPrint("%^MAGENTA%^You have been blessed.%^RESET%^");
  Blessed += x;
  if (Blessed > 20) Blessed = 20;
  return Blessed;
}

int GetCursed() { return Cursed; }

int AddCursed(int x) { 
  if ((Cursed + x) <= 0) {
    if (Cursed) eventPrint("%^RED%^Your curse fades.%^RESET%^");
    return Cursed = 0;
  }
  if (x > 0) eventPrint("%^RED%^You have been cursed.%^RESET%^");
  Cursed += x;
  if (Cursed > 20) Cursed = 20;
  return Cursed;
}
