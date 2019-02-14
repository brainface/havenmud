/* Combat Action Inheritable
 * August 16th, 2008
 * Scrooge McDuuk
 */
 // Mahkefel 2011:
 // debugs on SetProperty("action_debug", 1 )
#include <lib.h>
#include <daemons.h>
#include <rounds.h>
#include <armour_types.h>
#include <conditions.h>
inherit LIB_VERB;

int StaminaCost;
int Cooldown = 0;
mapping RequiredSkills;
string Help;
string RequiredWeapon;

//Mahkefel 2011: moar functions for me.
private int GetStandardDamage(object wielder);
int GetHit(object who, object target);
int GetLowDamage(object wielder);
int GetHighDamage(object wielder);
object* GetWeapons(object wielder);
object GetAnyWeapon(object wielder);

static void create() {
  verb::create();
  Help = "No help provided.";
  //SetRules("LIV", "");
  RequiredWeapon = "melee";
}

int SetCooldown(int x) { return Cooldown = x; }
int GetCooldown() { return Cooldown; }

int SetStaminaCost(int x) { return StaminaCost = x; }
int GetStaminaCost() { return StaminaCost; }
mapping SetRequiredSkills(mapping m) { return RequiredSkills = m; }
mapping GetRequiredSkills() { return RequiredSkills; }
string SetHelp(string h) { return Help = h; }
// Use "any" for things like backstab or disarm, other use "pierce", etc.
// none also works
string SetRequiredWeapon(string x) { return RequiredWeapon = x; }
string GetRequiredWeapon() { return RequiredWeapon; }

// Set the rage object filepath
private string Rage;
string SetRage(string rage) {return Rage = rage;}
string GetRage() {return Rage;}

// handle hand restrictions (requiring 2-handers)
private int Hands = 0;
int SetHands(int hands) {return Hands = hands;}
int GetHands() {return Hands;}

// handle single/dual wielding
// 1 = only one weapon, 2 = dual wielding, 0 = i don't care.
private int MultipleWeapons = 0;
int SetMultipleWeapons(int x) {return MultipleWeapons = x;}
int GetMultipleWeapons() { return MultipleWeapons;}

// handle requiring light armour and so forth.
int MaxArmourClass = 0;
int SetMaxArmourClass(int AC) {return MaxArmourClass = AC;}
int GetMaxArmourClass() {return MaxArmourClass;}

string GetHelp(string u) {
  string h = Help;
  string *sk = ({ });
  foreach(string s in keys(RequiredSkills)) {
    sk += ({ s + ": " + RequiredSkills[s] });
  }
  h += "\n\nRequired Skills: " + implode(sk, ", ");
  
  h += "\nWeapon Requirements: "; 
  if (GetHands()==1) h+= "one-handed ";
  if (GetHands()==2) h+= "two-handed ";
  if (GetMultipleWeapons()) h+= GetMultipleWeapons() + " ";
  h+= RequiredWeapon;
  if (GetMultipleWeapons() > 1) h+= "s";
  h += "\nStamina Cost: " + StaminaCost;
  if (GetCooldown()) h+= "\nCooldown: " + GetCooldown() + " seconds.";
  return h;
}

mixed CanAction(object who) {
  if (who->GetStaminaPoints() < StaminaCost) {
    return "You are too tired.";
  }
  if (who->GetCooldown(GetVerb())) {
    return "That is still on cooldown.";
  }
  if (who->GetParalyzed()) {
    return "You are paralyzed.";
  }
  if (who->GetSleeping()) {
    return "You are asleep.";
  }
  if (who->GetConditionFlag(CONDITION_PREVENT_COMBAT)) {
    return "Violent impulse flees your mind!"; 
  }
  foreach(string s in keys(RequiredSkills)) {
    if (who->GetSkillLevel(s) < RequiredSkills[s]) {
      return "You are not proficient enough in " + s + " to perform that action.";
    }
  }

  // if the verb requires weapon type "Any", then GetAnyWeapon will return a weapon.

  // failed at two-hands
  if (!GetAnyWeapon(who) && GetHands() == 2) {
    return "You must be wielding a two-handed " + RequiredWeapon + " weapon to use " + GetVerb() + ".";  
  }
  // failed at one-hands
  if (!GetAnyWeapon(who) && GetHands() == 1) {
    return "You must be wielding a one-handed " + RequiredWeapon + " weapon to use " + GetVerb() + ".";  
  }
  
  // dual wielding /single weapon restrictions
  if (GetMultipleWeapons() == 1 &&  sizeof(GetWeapons(who)) != 1) {
    return "You must be wielding a single " + RequiredWeapon + " weapon to use " + GetVerb() + "."; 
  }
  if (GetMultipleWeapons() == 2 && sizeof(GetWeapons(who)) != 2) {
    return "You must be wielding two " + RequiredWeapon + " weapons to use " + GetVerb() + "."; 
  }
  
  // not weilding any correct weapon, and this isn't a brawly type attack
  if (!GetAnyWeapon(who) && RequiredWeapon != "melee" ) {
    return "You must be wielding a " + RequiredWeapon + " weapon to use " + GetVerb() + ".";
  // not wieldling any correct weapon, and this IS an unarmed attack
  } else if ( !GetAnyWeapon(who) && RequiredWeapon == "melee" ) {
    foreach(object weapon in who->GetWielded()) {
      if (weapon->GetWeaponType() != RequiredWeapon) return "You must be unarmed "
       "or wielding a melee weapon to use " + GetVerb() + ".";
    }
  }
  
  // handle armour restrictions
  if (GetMaxArmourClass()) {
    foreach(object w in who->GetUniqueWorn()) {
      if (w->GetArmourClass() > GetMaxArmourClass()) {
      	return "Your " + w->GetKeyName() + " weighs you down!";
      }
    }
  }

  return 1;
}

int eventAttack(object who, object target) {
  send_messages(GetVerb(), "$agent_name $agent_verb $target_name.", who, target, environment(who));
  return 1;
}

int eventAction(object who, object target) {
  if (Cooldown) who->AddCooldown(GetVerb(), Cooldown);
  who->SetAttack(target, (: eventAttack, who, target :), ROUND_OTHER);
  who->AddStaminaPoints(-StaminaCost);
  return 1;
}

// Mahkefel 2011
// The intended purpose here is to always return
//   an amount of damage that is worth actually
//   using the style and giving up like 10 attacks
//   for that round. (AKA it can't be 0.)
//
// This function returns a static value. Use GetLowDamage or GetHighDamage,
//   which calls this function
private int GetStandardDamage(object wielder, object weapon) {
  string *damageSkills = ({ });
  int combatSkillLevel = 0;
  int damage = 0;
  int weaponClass = 0;
  float multiplier = 1.0;

  damageSkills += keys(GetRequiredSkills());
  if(wielder->GetProperty("action_debug") ) debug(damageSkills[0]);
  // what skill does the weapon we're using use?
  //   (We need this for backstab, disarm, etc.)
  if (weapon->GetVendorType() && weapon->GetClass()) {
    weaponClass = weapon->GetClass();
    damageSkills += ({ weapon->GetWeaponType() + " combat" });
  } else {
    // unarmed or something else odd.
    // damageSkills += ({ "melee combat" }); //we'll let the verb decide this.
  }

  // sum up and average the skills we're using to attack here. note that weapon combat
  //   skills typically count double here. It makes sense in my head and doesn't hurt.
  foreach(string skill in damageSkills) {
    combatSkillLevel += wielder->GetSkillLevel(skill);
  }
  combatSkillLevel /= sizeof(damageSkills);

  // calculate weapon class for melee / shield bash / weird stuff here.
  if (weaponClass == 0) {
    weaponClass = 5 + combatSkillLevel / 10;
    if (weaponClass > 50) weaponClass = 50;
  }

  // this should be very, very similiar to spell damage.
  damage = combatSkillLevel * 16;

  if(wielder->GetProperty("action_debug") ) debug( "base damage: " + damage);

  // if someone has awesome strength, a sweet weapon, and combat rage,
  //   they'll deal as much damage as an evoker with full fire magic tossing
  //   a fireball.

  // full combat rage ranks = 2x damage.
  if (wielder->GetSkillLevel("combat rage") < combatSkillLevel) {
    multiplier += wielder->GetSkillLevel("combat rage") / combatSkillLevel;
  } else {
    multiplier += 1.0;
  }
  if(wielder->GetProperty("action_debug") ) debug( "After combat rage: " + multiplier * damage);

  // add some for weapon class. (~ 1.5x)
  multiplier += weaponClass / 100.0;
  if(wielder->GetProperty("action_debug") ) debug( "After weapon class: " + multiplier * damage);

  // add some for high strength (~ 1.5x)
  multiplier += wielder->GetStatLevel("strength") / 300.0;
  if(wielder->GetProperty("action_debug") ) debug( "After strength: " + multiplier * damage);

  // if someone kicks ass, should add up to about 3x damage.
  if (multiplier > 3.0) multiplier = 3.0;

  damage *= multiplier;

  if(wielder->GetProperty("action_debug") ) debug( "final standard damage (may decrease): " + damage);

  return damage;
}


// low level abilities, chain attacks, area effects, etc.
// deals 1/2 as much on average as High damage.
int GetLowDamage(object wielder, object weapon) {
  int damage = GetStandardDamage(wielder, weapon);
  damage = damage * 1/10 + random(damage); // range from 10% to 110%
  if(wielder->GetProperty("action_debug") ) debug( "final random low damage: " + damage);
  return damage;
}

// single target, higher level attacks
// deals twice as much on average as low damage.
int GetHighDamage(object wielder, object weapon) {
  int damage = GetStandardDamage(wielder, weapon);
  damage = damage + random(damage); // range from 100% to 200%
  if(wielder->GetProperty("action_debug") ) debug( "final random high damage: " + damage);
  return damage;
}


//Mahkefel 2011: hit/miss function. I do not want to type this everyt ime.
// 0 = miss
// -1 = complete whiff
int GetHit(object who, object target) {
  int pro, con;
  // update: i mucked with base offense/defense, they should roughly equal
  // assuming equal training in key skills.
  // Offense is soooo much lower than Defense. This might
  //   give about 66% chance to hit. Just comparing Offense vs. Defense
  //   means critical misses happen 4x more than fucking hits.
  // On the other hands, mobs without parry/dodge are waaayyyy easier to hit.
  //   having parry doubles its defense, parry + dodge triples. So any math that
  //   has a tolerable chance to hit fighters will maul clerics, priests, & rangers
  //   (evokers/enchanters/necromancers/druids have one of dodge/parry)
  pro = 2 * who->GetOffense( keys(GetRequiredSkills()) );
  pro += who->GetLuck();
  con = target->GetDefense();
  con += target->GetLuck();
  // more cons is unneccessary, defense is like 3x offense already
  if(who->GetProperty("action_debug")) debug("Combat action: pro: " + pro +" con: " + con);

  pro = random(pro); con = random(con);

  if (con > pro * 3) return -1; // leeet's reduce fumblin'
  if (con > pro ) return 0;
  return 1;
}

// returns weapons dude is wielding that can be used with combat style.
// i.e. any wielded swords for swordslinging.
object* GetWeapons(object wielder) {
  object* weapons = ({ });
  object* limbs = ({ });

  if (wielder->GetProperty("action_debug")) debug("Required weapon: "+RequiredWeapon);

  // backstab, disarm
  if (RequiredWeapon == "any") {
    return wielder->GetWielded();
  }
  
  if (RequiredWeapon == "none") {
    weapons += ({ wielder }); // this should work. it just needs a return value of some sort.
  }

  // melee when unarmed.
  if (RequiredWeapon == "melee" && wielder->GetWielded() == ({ }) ) {
    weapons += ({ wielder }); // like none, this should work
  } 


  // shield is required weapon, find all shields
  // that are not worn on the arm.
  if (RequiredWeapon == "shield") {
    //if (wielder->GetProperty("action_debug")) debug("looping thru inventory for shield");
    limbs = wielder->GetWorn();
    foreach (object *limb in limbs) {
      foreach (object accoutrement in limb) {
        //if (wielder->GetProperty("action_debug")) debug(accoutrement->GetKeyName());
        if (accoutrement->GetArmourType() & A_SHIELD) {
          //if (wielder->GetProperty("action_debug")) debug("found a shield");
          if (accoutrement->GetWorn()[0]!="left arm" && accoutrement->GetWorn()[0]!="right arm") {
            if (wielder->GetProperty("action_debug")) debug("found shield not on arm: "+accoutrement->GetKeyName());
            weapons += ({accoutrement});
          }
        }
      }
    }
  }

  // about everything else
  foreach(object contender in wielder->GetWielded()) {
    if (contender->GetWeaponType() == RequiredWeapon) {
      if(GetHands()) {
      	if (GetHands() == contender->GetHands()) weapons += ({contender});  
      } else {
        weapons += ({contender});
      }
    }
  }
  return weapons;
}

// I don't want to type this 300 times.
// Give me a weapon they're wielding that can be used with this combat action.
object GetAnyWeapon(object wielder) {
  object *weapons = GetWeapons(wielder);
  if (!sizeof(weapons)) return 0;
  return GetWeapons(wielder)[random(sizeof(GetWeapons(wielder)))];
}

