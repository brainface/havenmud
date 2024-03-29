/*    /lib/spell.c
 *    From Dead Souls LPMud
 *    An object all spells inherit.
 *    Created by Descartes of Borg 951027
 *    Version: @(#) spell.c 1.22@(#)
 *    Last modified: 96/12/17
 */

#include <lib.h>
#include <daemons.h>
#include <magic.h>
#include <damage_types.h>
#include <magic_protection.h>

inherit LIB_DAEMON;
inherit LIB_HELP;
private string       Animate         = 0;             // zombie file to raise
private int          AreaSpell       = 0; 
private int          GlobalSpell     = 0;
private int          AutoDamage      = -1;            // perform dmg?
private int          AutoHeal        = -1;            // perform healing?
private string       Conjure         = 0;             // file to clone
private int          Cooldown       = 0;
private int array    Damage          = ({ 0, 0 });    // base, random
private int          DamagingShield  = 0;
private mixed array  Messages        = ({});          // damage/heal messages
private int          DamageType      = MAGIC;         // damage type done
private int          Difficulty      = 0;             // 1-100 scale
private int array    DrinkCost       = ({ 0, 0 });    // base, random
private int array    Healing         = ({ 0, 0 });    // base, random
private int array    HealthCost      = ({ 0, 0 });
private int array    MagicCost       = ({ 0, 0 });    // base, random
private int          Morality        = 0;             // bad? good?
private int          MaxMorality     = -1;
private int          MinMorality     = -1;
private int          ProtectionAmount = 0;
private int          ProtectionTime  = 0;
private int          ProtectionTypes = 0;
private int          ShieldType      = 0;
private int          RecoveryTime    = 0;
private string      *Religions       = ({ });             // limit who can cast
private int          RemoteTargets   = 0;             // can targets be remote
private string array Rules           = ({});          // spell rules
private mapping      Skills          = ([]);          // skill requirements
private string      *EnhanceSkills   = ({});          // skills that boost the spell
private string       SpellName       = "";            // name of spell
private int          SpellType       = SPELL_OTHER; // spell type
private int array    StaminaCost     = ({ 0, 0 });    // base, random
private int          UniqueSpell     = 0;             // Is this a special spell?
private string       Verb            = "cast";        // use what verb?

/* Defs for new lib */
void eventTrainSpell(object who, int success);
int eventFail(object who, int grade);
int hitCallback(object, object, int, class MagicProtection);
void endCallback(object); 
int eventTestFailure(object who, int level, mixed limb, object array targets);
string GetSpell();
int GetSpellLevel();

// mahkefel 2017--prototype for spells to override, applies affects on "hit"
int eventAfterEffect(object who, int level, string limb, object target) { return 0;}
int GetDrinkCost(object who);

/* ********************* spell.c attributes ************************ */

int SetAreaSpell(int x) { return AreaSpell = x; }

int GetAreaSpell() { return AreaSpell; }

int SetGlobalSpell(int x) { return GlobalSpell = x; }

int GetGlobalSpell() { return GlobalSpell; }


int GetAutoDamage() {
    return AutoDamage;
}

int SetDamagingShield(int x) { return DamagingShield = x; }

int GetDamagingShield() { return DamagingShield; }

int SetShieldType(int x) { return ShieldType = x; }

int GetShieldType() { return ShieldType; }

int SetRecoveryTime(int x) { return RecoveryTime = x; }

int GetRecoveryTime() { return RecoveryTime; }

static int SetAutoDamage(int x) {
    return (AutoDamage = x);
}

int GetAutoHeal() {
    return AutoHeal;
}

static int SetAutoHeal(int x) {
    return (AutoHeal = x);
}

string GetConjure() {
    return Conjure;
}

int SetCooldown(int x) {
	return Cooldown = x;
}

int GetCooldown() {
	return Cooldown;
}

static string SetConjure(string str) {
    return (Conjure = str);
}

// animate dead type spells
string SetAnimate(string str) {
  return (Animate = str);
}
string GetAnimate() {
  return Animate;
}

int GetDamage(int level) {
  int damage;
  
  damage = GetSpellLevel() * level;
  damage = damage/3;
  if (damage < 1) damage = 1;
  damage += random(damage);
  return damage;
}

int SetDamageType(int type) {
  DamageType = type;
  return DamageType;
}

varargs static void SetDamage(int type, mixed array rest...) {
   //unused. Mostly.
   DamageType = type;
   return;
}

int GetDamageType() {
    return DamageType;
}

int GetDifficulty() {
    return Difficulty;
}

static int SetDifficulty(int x) {
    return (Difficulty = x);
}

int SetUniqueSpell(int x) { return UniqueSpell = x; }

int GetUniqueSpell() { return UniqueSpell; }

string GetErrorMessage() {
  string rule = Rules[0];

  switch(rule) {
    case "":
	    return "Simply cast it?";
    case "LIV":
	    return "Cast it on whom?";
    case "OBJ": case "STR": 
	    return "Cast it on what?";
    case "STR of LIV":
	    return "Cast it on what of whom?";
    case "against STR":
	    return "Cast against what?";
    default:
      return "Cast it?";
    }
}

int GetHealing(int level) {
  int damage;
  
  damage = GetSpellLevel() * level;
  damage = damage/10;
  if (damage < 1) damage = 1;
  damage += random(damage) + random(damage);
  return damage;
}

static varargs int array SetHealing(mixed args...) {
    // unused
    return ({ 1 });
}

int GetMagicCost(object who) {
  // mrr, override for vampire spells
  if (DrinkCost[0]) return 0;

    if (SpellType == SPELL_DEFENSE) MagicCost = ({ (GetSpellLevel() * 2) + 20, (GetSpellLevel() * 2) + 20 });
    if (SpellType == SPELL_COMBAT)  MagicCost = ({ (GetSpellLevel()) + 10, GetSpellLevel() + 10 });
    if (SpellType == SPELL_HEALING) MagicCost = ({ (GetSpellLevel() * 2) + 20, (GetSpellLevel() * 2) + 20 });
    return MagicCost[0] + MagicCost[1] - (MagicCost[1]* who->GetSpellLevel(GetSpell())/100);
}

static varargs int array SetMagicCost(mixed args...) {
  // This function only actually does anything for SPELL_OTHER
    MagicCost[0] = args[0];
    if( sizeof(args) == 2 ) {
	    MagicCost[1] = args[1];
      }
    return MagicCost;
}

static varargs int array SetHealthCost(mixed args...) {
  HealthCost[0] = args[0];
  if (sizeof(args) == 2) {
    HealthCost[1] = args[1];
   }
  return HealthCost;
}


varargs string array GetMessage(int damage, int healing) {
    int max, div, i;

    if( damage < 1 ) {
	return Messages[0];
    }
    if( sizeof(Messages) == 2 ) {
	return Messages[1];
    }
    if( healing) {
	max = GetSpellLevel() * 30;;
    }
    else {
	max = GetSpellLevel() * 30;
    }
    div = max/(sizeof(Messages) - 1);
    i = (damage/div) + 1;
    if( i >= sizeof(Messages) ) {
	i = sizeof(Messages)-1;
    }
    return Messages[i];
}

mixed array GetMessages() {
    return Messages;
}

static mixed array SetMessages(mixed array messages) {
    return (Messages = messages);
}

int GetMorality() {
    return Morality;
}

static int SetMorality(int x) {
    return (Morality = x);
}

int SetMinimumMorality(int x) { return MinMorality = x; }
int SetMaximumMorality(int x) { return MaxMorality = x; }
int GetMinimumMorality() { return MinMorality; }
int GetMaximumMorality() { return MaxMorality; }

string array GetReligions() {
    return Religions;
}

string *SetReligions(string *religions) {
    if (!arrayp(religions)) religions = ({ religions });
    return (Religions = religions);
}

int GetRemoteTargets() {
    return RemoteTargets;
}

static int SetRemoteTargets(int x) {
    return (RemoteTargets = x);
}

int GetRequiredSkill(string skill) {
    return Skills[skill];
}

string array GetRules() {
    return Rules;
}

varargs static string array SetRules(mixed args...) {
    if( !args ) {
	args = ({ "" });
    }
    else if( arrayp(args[0]) ) {
	args = args[0];
    }
    return (Rules = args);
}

string array GetSkills() {
    return keys(Skills);
}

static mapping SetSkills(mapping mp) {
    return (Skills = mp);
}

int GetMaxSpellLevel(object who) {
  int x = 100;
  int y;
  foreach(string skill in GetSkills()) {
     y = 5 * (who->GetSkillLevel(skill) - GetRequiredSkill(skill)) + 5; 
     if (y < x) x = y;
  }
  return x;
}

static string *SetEnhanceSkills(string *sk) {
  return (EnhanceSkills = sk);
}

string *GetEnhanceSkills() { return EnhanceSkills; }

string GetSpell() {
    return SpellName;
}

static string SetSpell(string str) {
    return (SpellName = str);
}

int GetSpellType() {
    return SpellType;
}

static int SetSpellType(int x) {
    if (x == SPELL_COMBAT)  SetMorality(-1);
    if (x == SPELL_HEALING) SetMorality(1);
    return (SpellType = x);
}

int GetStaminaCost(object who) {
    return StaminaCost[0] + StaminaCost[1] - (StaminaCost[1] * who->GetSpellLevel(GetSpell())/100);
}

int GetHealthCost(object who) {
    return HealthCost[0] + HealthCost[1] - (HealthCost[1] * who->GetSpellLevel(GetSpell())/100);
}

int GetDrinkCost(object who) {
    return DrinkCost[0] + DrinkCost[1] - (DrinkCost[1] * who->GetSpellLevel(GetSpell())/100);
}

static varargs int array SetStaminaCost(mixed args...) {
    StaminaCost[0] = args[0];
    if( sizeof(args) == 2 ) {
	StaminaCost[1] = args[1];
    }
    return StaminaCost;
}

static varargs int array SetDrinkCost(mixed args...) {
    DrinkCost[0] = args[0];
    if( sizeof(args) == 2 ) {
	DrinkCost[1] = args[1];
    }
    return DrinkCost;
}

varargs object *GetTargets(object who, mixed args...) {
   object env = environment(who);
   object array targets = ({ });
   object def;
   int count = sizeof(args);
   int attack = (SpellType == SPELL_COMBAT);

  if (attack) {
      def = who->GetCurrentEnemy();
      if (!(who->GetInCombat())) def = 0;
      }
     else {
      def = who;
     }

  // Set up target for SetRules("") responses.

  if (!count) { // There are no arguments passed.
     if (member_array("", Rules) == -1) {
          return 0;
     }     //  Returns no target if no argument is not a valid rule.
     if (AreaSpell == 1) {
       targets = filter(all_inventory(env), (: $1 :) );
       targets = filter(targets, (: living :));
       targets = filter(targets, (: noncreatorp :) );
       
       // mahkefel 2017: make offensive area effects not target allies
       if (GetSpellType()==SPELL_COMBAT) {
         // remove self
         targets -= ({ who });
         foreach(object target in targets) {
            // exclude pets
         	  if(target->GetOwner() == who->GetKeyName()) {
         	  	  targets -= ({target});
         	  }
            // exclude guarded drugrunners
            if(target->GetGuard() == who) {
            	targets -= ({target});
            }
            // exclude friends (so npcs won't attack each other)
            if(member_array(target, who->CheckFriends()) != -1 ) {
            	  debug(who->CheckFriends());
            	  targets -= ({target});
            }
            // exclude party members
            if(member_array(target->GetKeyName(), who->GetPartyMembers()) != -1) {
            	targets -= ({target});
            }
         }
       }
       return targets;
       // Return all living targets for an area spell.
    } else {
      if ( (def) && (!AreaSpell) ) {
        return ({ def });
      } else {
         return 0;
      }
    }
  }  //  End of No Arg

/*  Number of Args == 1
 *  Test for objectp() livingp()
 *  Test Rules arrays for Possible Targets
 */

  else if (count == 1) {          
      if (objectp(args[0])) {       /*  If the first arg is an object */
         if (living(args[0])) {      /*  If the object is a living */
            if (member_array("LIV", Rules) == -1) {  
              /*  Living is not a valid Rule for this spell. */
               return 0;
               }  
             else {
                return ({ args[0] });
                }
           }
         else {                 /*  Args are not living, but are object */
            if (member_array("OBJ", Rules) == -1) {
               /*  OBJ is not a valid Rule for this spell. */
               return 0;
               }
                else {
                   return ({ args[0] });
                   }
            }
        }
         /*  Arg is not an object.  */
      if (stringp(args[0])) {      /*  Args is not an object, is a STR */
         if (member_array("STR", Rules) == -1) {
              return 0;
              }
         if (GlobalSpell) {
             if (stringp(args)) args = explode(args, " ");
              else if (arrayp(args) && sizeof(args) && stringp(args[0]))
                  args = explode(args[0], " ");
                else if(!arrayp(args)) args = ({ args });
                args = map(args, function(mixed tmp) {
                   if (stringp(tmp)) return convert_name(tmp);
                   else if(objectp(tmp)) return tmp->GetKeyName();
                  else return 0;
                   } );
          args = filter(args, (: stringp :));
          args = filter(map(args, (: find_living($1) :)), (: objectp :));
          args = filter(args, (: environment($1) :) );
          args = filter(args, (: !(environment($1)->GetProperty("no magic")) :) );
//          args = filter(args, (: !(environment($1)->GetProperty("no attack")) :));
          args = filter(args, (: !($1)->GetInvis() :));
            return args;
                }
               else {
                  if( (def) && (!GlobalSpell) ) {
                      return ({ def });
                    }
                  else {
                      return 0;
                    }
                 }
         }
      /*  More than 1 argument passed */
       }

/*  Multiple Argument Spells
 *  Allowed on STR of LIV
 */

  if (objectp(args[1])) {    /*  Check to be sure second arg is an object */
      if (living(args[1])) {   /*  If object is living. */
         if (member_array("STR of LIV", Rules) == -1) {
             /*  Cannot cast this spell on STR of LIV */
             return 0;
             }
       else {
           return ({ args[1] });
            }
          }
        else {
           if (member_array("STR of OBJ", Rules) == -1) {
              /*  Cannot cast this spell on STR of OBJ */
                return 0;
                 }
               else {
                   return ({ args[1] });
                    }
               }
       }
  return ({ def });
 } 

string GetVerb() {
    return Verb;
}

static string SetVerb(string verb) {
    return (Verb = verb);
}

/* ******************** spell.c modals *************************** */
static int CanAttack(object who, object array enemies, int power) {
    int i, maxi = sizeof(enemies);
    int hits = 0;
    int misses = 0;
    int hit_count = 0;
    int miss_count = 0;
    int hit_con = 0;
    int miss_con = 0;
    int con, bonus;
    
    if( !maxi ) {
	return -1;
    }
    for(i=0; i<maxi; i++) {
	mixed area;
	
	if( !enemies[i] ) {
	    continue;
	}
	if( !enemies[i]->eventPreAttack(who) ) {
	    enemies[i] = 0;
	    continue;
	}
	if( environment(enemies[i]) != environment(who) ) {
	    if( RemoteTargets ) {
		area = 0;
	    }
	    else {
		enemies[i] = 0;
		continue;
	    }
	}
	else {
	    area = environment(who);
	}
	
	
	
	if( !enemies[i]->eventReceiveAttack(power, "magic", who) ) {
	    misses += enemies[i]->GetLevel();
	    miss_count++;
	    miss_con += enemies[i]->GetMagicResistance();
	    send_messages("repel", "$target_name $target_verb $agent_possessive_noun magic attack.", who, enemies[i], area);
	    enemies[i] = 0;
	}
	else {
	    hit_count++;
	    hits += enemies[i]->GetLevel();
	    hit_con += enemies[i]->GetMagicResistance();
	}
    }
    if( hit_count < 1 ) {
	    return -1;
    }
    return 1;
}

varargs int CanCast(object who, int level, string limb, object array targets) {
    string array skills = GetSkills();
    int count = sizeof(skills);
    int cost = GetMagicCost(who);
    int x, check_morality;
    object env = environment(who);

  if (!userp(who)) level = GetMaxSpellLevel(who);
  if (!env) {
    who->eventPrint("You have issues.");
    return 0;
  }
  if (env->GetProperty("no magic")) {
    who->eventPrint("Something prevents the magic.");
    return 0;
  }
  if (env->GetProperty("no conjuring") && member_array("conjuring", GetSkills()) != -1) {
    who->eventPrint("Something prevents the conjuring.");
    return 0;
  }
  if (env->GetProperty("no faith") && member_array("faith", GetSkills()) != -1) {
    who->eventPrint("Something prevents you from communing with your deity.");
    return 0;
  }
  if (env->GetProperty("no attack") && SpellType == SPELL_COMBAT) {
    who->eventPrint("You cannot attack here!");
    return 0;
  }
  if (MinMorality != -1) {
    if (who->GetMorality() < MinMorality) {
      who->eventPrint("You lack sufficient morality to cast that spell!");
      return 0;
    }
  }
  if (MaxMorality != -1) {
    if (who->GetMorality() > MaxMorality) {
      who->eventPrint("You are far too pious to cast that spell!");
      return 0;
    }
  }
  if (GetRequiredSkill("faith") || GetRequiredSkill("natural magic")) {
    if (check_morality = MORALITY_D->CheckMorality(who)) {
      if (who->GetTestChar()) debug("!0");
      if (check_morality == 1) {
       if (who->GetTestChar()) debug("== 1");      
        who->eventPrint("You are entirely too \"good\" to use magic right now.");
        return 0;
      }
      if (check_morality == 2) {
        if (who->GetTestChar()) debug("== 2");
        who->eventPrint("You are entirely too \"evil\" to use magic right now.");
        return 0;
      }
    }
  }
  if (sizeof(Religions)) {
	  if( member_array(who->GetReligion(1), Religions) == -1 ) {
	    who->eventPrint("Your religion does not have that kind of power."); 
	    return 0;
	    }
    }
  if (who->GetCooldown(GetSpell()) > 0) {
  	who->eventPrint("You cannot cast " + GetSpell() + " for another " + who->GetCooldown(GetSpell()) + " seconds.");
  	return 0;
  }
  if (cost > who->GetMagicPoints()) {
  	who->eventPrint("You don't have enough power.");
  	return 0;
    }
  if( cost > 0 ) {
	  who->AddMagicPoints(-cost);
    }
  cost = 0;
  cost = GetStaminaCost(who);
  if (cost > who->GetStaminaPoints()) {
    who->eventPrint("You don't have enough stamina.");
  	return 0;
    }
  if( cost > 0 ) {
	  who->AddStaminaPoints(-cost);
    }
  cost = 0;
  cost = GetHealthCost(who);
  if (cost > who->GetHealthPoints()) {
    who->eventPrint("You don't have enough health.");
  	return 0;
    }
  if( cost > 0 ) {
	  who->eventReceiveDamage(who, HUNGER, cost, 1);
    }
  cost = 0;
  cost = GetDrinkCost(who);
  if (cost > who->GetDrink()) {
    who->eventPrint("You're too thirsty for that.");
    return 0;
  }
  if (cost > 0) {
    who->AddDrink(-cost);
  }
  if( AutoHeal != -1 ) {
	  int i, maxi = sizeof(targets);
    	for(i=0; i<maxi; i++) {
	      int hp, max_hp;
	      if( !targets[i] ) {
		      continue;
	        }
	      if( limb ) {
		      if( member_array(limb, targets[i]->GetLimbs()) == -1 ) {
		        send_messages("have", "$target_name $target_verb no " +
				                  limb + ".", who, targets[i]);
		        targets[i] = 0;
		        continue;
		        }
	        }
	      hp = targets[i]->GetHealthPoints(limb);
	      max_hp = targets[i]->GetMaxHealthPoints(limb);
	      if(hp >= max_hp) {
		    if( limb ) {
		      send_messages("", "$target_possessive_noun " + limb +
				                " needs no healing.", who, targets[i]);
		      }	else {
		      send_messages("need", "$target_name $target_verb no "
				               "healing.", who, targets[i]);
		      }
		     targets[i] = 0;
		     continue;
	      }
	  }
	  if( !sizeof(filter(targets, (: $1 :))) ) {
	      who->eventPrint("No targets?");
	      return 0;
	      }
  }	
  return 1;
}

/* ******************** spell.c events *********************** */

/*
 * 1 means it failed, 0 means it did not
 */
int eventTestFailure(object who, int level, mixed limb, object array targets) {
    int *failure = ({ 0, 0 });
    int fc = 0;
    if (!userp(who)) level = GetMaxSpellLevel(who);
    failure[0] = random(GetDifficulty());
    failure[0] = (failure[0] * 50) / (who->GetSpellLevel(GetSpell()));
    failure[0] += (who->GetRecoveryTime() * 3); 
    foreach(string skill in GetSkills()) {
	    failure[0] -= (who->GetSkillLevel(skill) - GetRequiredSkill(skill)) * 5; 
      }
    if (failure[0] < 0) failure[0] = 0;
    failure[1] = random(100);
    if (failure[1]  < failure[0]) {
	    fc = failure[0] - failure[1];
	    if (fc > GetSpellLevel() * 4) fc = GetSpellLevel() * 4;
	    if (who->GetTestChar())
	      debug("Random -> " + failure[1] + " FailChance -> " + failure[0] + " eventFail called (" + (fc) + ")");
	    eventFail(who, fc);
	    eventTrainSpell(who, 0);
	    return 1;
      }
    eventTrainSpell(who, 1); 
    if (RecoveryTime) {
     	who->AddRecoveryTime(RecoveryTime);
      }
        if (GetMorality() && targets[0])
        moral_act(who, targets[0], GetMorality() * (query_sign(targets[0]->GetMorality()) || 1) );
    return 0;
}

/* -1 means this did nothing
 * otherwise return damage amount for SPELL_DAMAGE
 * or heal amount for SPELL_HEAL
 */
varargs int eventCast(object who, int level, mixed limb, object array targets) {
  class MagicProtection protection;
  
  if (!userp(who)) level = GetMaxSpellLevel(who);
  if (GetCooldown()) { who->AddCooldown(GetSpell(), GetCooldown()); }
  if (who->GetProperty("spelltest")) debug("level :" + level);
  if (SpellType == SPELL_DEFENSE) {
  	if (!ShieldType) {
  		error("No ShieldType.  Someone should probably fix that.");
  		return -1;
  		}
  	protection = new(class MagicProtection);
  	protection->bits = ProtectionTypes;
  	protection->end = (: endCallback :);
    protection->hit = (: hitCallback :);
  	protection->caster = who;
  	if (ShieldType == SHIELD_TIMED) {
  		protection->time    = (GetSpellLevel() * level)/3 + 1; 
  		protection->protect = ((GetSpellLevel() * level)/10 + 1) ;
  		if (who->GetTestChar())
  		  debug("Time = " + protection->time + " Amount = " +  protection->protect + " SL: " + GetSpellLevel());
  	} else {
  		protection->absorb = (GetSpellLevel() * level);
  		if (who->GetTestChar())
  		  debug("Absorb = " +  protection->absorb + " SL: " + GetSpellLevel());
  	}
  	protection->args = level;
  	protection->name = GetSpell();
  	if(targets[0]->AddMagicProtection(protection)) {
  		send_messages(Messages[0][0], Messages[0][1], who, targets[0], environment(who));
  		return 1;
  	} else {
                who->eventPrint("That person cannot have more protections right now.");
  		send_messages("", "$agent_possessive_noun spell fails.", who, 0, environment(who));
  		return 1;
  	}
    return 1;
  }
  // handle animate dead et al
  if( GetAnimate() ) {
    object zombie;
    object corpse = targets[0];
    int zombielevel = 1;

    if( !corpse ) {
      who->eventPrint("Your corpse has gone missing.");
      return 1;
    }
    if(!RACES_D->GetValidRace(corpse->GetRace())) {
      who->eventPrint(capitalize(corpse->GetShort()) + "'s bizarre anatomy defies reanimation.");
      return 1;
    }
    zombie = new(GetAnimate());
    if( !zombie ) {
      who->eventPrint("An error occurred in animation. Please bug report this.");
      return 1;
    }
    zombie->SetGender(corpse->GetGender());
    zombie->SetRace(corpse->GetRace());
    zombie->SetClass(corpse->GetOriginalClass());
    switch(level) {
      case 0..20:
        zombielevel = who->GetLevel() - 50;
        break;
      case 21..50:
        zombielevel = who->GetLevel() - 20;
        break;
      case 51..100:
        zombielevel = who->GetLevel() - 10;
        break;
      }
    if (zombielevel < 1) zombielevel = 1;
    if (zombielevel > corpse->GetLevel() * 2) zombielevel = corpse->GetLevel() * 2;
    zombie->SetLevel(zombielevel); 

    //descriptions
    zombie->SetId( ({ zombie->GetId()..., corpse->GetId()..., corpse->GetRace() }) );
    zombie->SetAdjectives( ({ zombie->GetAdjectives()..., corpse->GetAdjectives(),
	    corpse->GetRace() }) );
    // short/log/keyname all need to have "$r" somewhere in them to dynamically show race
    zombie->SetKeyName(replace_string(zombie->GetKeyName(),"$r",corpse->GetRace()));
    zombie->SetShort(replace_string(zombie->GetShort(),"$r",corpse->GetRace()));
    zombie->SetLong(replace_string(zombie->GetExternalDesc(),"$r",add_article(corpse->GetRace())));
    zombie->SetCapName(capitalize(zombie->GetKeyName())); 

    foreach(object thing in all_inventory(corpse)) {
      thing->eventMove(zombie);
    }
    zombie->eventForce("wear all");
    // send custom spell effect message
    send_messages(Messages[0][0], Messages[0][1], who,zombie,environment(who));
    corpse->eventDestruct();
    who->SetPermanentProperty("animate_zombie", file_name(zombie));
    zombie->SetOwner(who->GetKeyName());
    zombie->eventMove(environment(who));
    zombie->eventForce("emote blinks its eyes open.");
    zombie->eventForce("speak You... rang...?");
    zombie->eventForce("follow "+ who->GetKeyName());
    who->eventForce("lead "+ zombie->GetKeyName());
    zombie->eventForce("guard " + who->GetKeyName());
    zombie->SetReligion(who->GetReligion());
    return 1;
  }
  if( GetConjure() ) {
	object ob = new(GetConjure());

	if( !ob ) {
	    who->eventPrint("An error occurred in conjuring.");
	    return 1;
	}
	send_messages(Messages[0][0], Messages[0][1], who, 0,environment(who));
	if( !ob->eventMove(who) ) {
	    send_messages("drop", "$agent_name could not carry " +
			  ob->GetShort() + " and $agent_verb it!", who, 0,
			  environment(who));
	    ob->eventMove(environment(who));
	}
	return 1;
  }
    if( AutoHeal != -1 ) {
	mapping messages = ([]);
	int total_healing = 0;

	foreach(object target in targets) {
	    string array tmp;
	    int healing;

	    if( !target ) {
		continue;
	    }
	    healing = (GetHealing(level));
	    healing = target->eventHealDamage(healing, AutoHeal, limb);
	    total_healing += healing;
	    who->AddExperience(healing);
	    tmp = GetMessage(healing, 1);
	    send_messages(tmp[0], tmp[1], who, target, environment(who));
	}
	if( sizeof(targets) ) {
	    return total_healing/sizeof(targets);
	}
	else {
	    return 0;
	}
    }
    if( AutoDamage != -1 ) {
	mapping messages = ([]);
	int total_damage = 0;
  
	if( CanAttack(who, targets, GetSpellLevel() + level/2 /*level/5*/) == - 1 ) {
	    who->eventPrint("Your powers fail you.");
	    return 0;
	    }
  
	foreach(object target in targets) {
	    string array tmp;
	    int damage;

	    if( !target ) {
		    continue;
	    }
	    
	    damage = (GetDamage(level));
	    foreach(string enhance in EnhanceSkills) {
	      int damageboost = who->GetSkillLevel(enhance) / (GetSpellLevel() * 2);
	      if (damageboost > 3) damageboost = 3;
	      damage += damage * damageboost;
	    }
	    if (target->GetTestChar()) debug("base damage = " + GetDamage(level) + " level = " + level + " SpellLevel = " + GetSpellLevel() +  " damage = " + damage);
	    
	    // mahk 2018: fun fact, lib was getting damage to Random Limb, then 
	    // applying damage to RandomLimb usuuuaallly not the same limb
	    // so daemons, skaven with unarmored tails could die to spell headshots
	    if (!limb) limb = target->GetRandomLimb("torso");
	    
	    damage = target->GetDamageInflicted(who, GetDamageType(), damage,	AutoDamage, limb);
	    
	    tmp = GetMessage(damage);
	    send_messages(tmp[0], tmp[1], who, target, environment(who));
	    
	    damage = target->eventInflictDamage(who, GetDamageType(), damage,	AutoDamage, limb);
	    
	    total_damage += damage;
	    eventAfterEffect(who, level, limb, target);
	}
	if( sizeof(targets) ) {
	    return total_damage/sizeof(targets);
	}
	else {
	    return 0;
	}
    }
    return -1;
}

varargs mixed eventParse(object who, mixed array args...) {
    int count = sizeof(args);

    if( count < 1 ) {
	if( member_array("", Rules) == -1 ) {
	    return GetErrorMessage();
	}
	return ({});
    }
    if( Verb == "cast" ) {
	if( count == 1 ) {
	    if( objectp(args[0]) ) {
		if( !living(args[0]) ) {
		    if( member_array("OBJ", Rules) == -1 ) {
			return GetErrorMessage();
		    }
		    return ({ args[0] });
		}
		if( sizeof(({ "OBJ", "LIV"}) & Rules) == 0 ) {
		    return GetErrorMessage();
		}
		return ({ args[0] });
	    }
	    if( stringp(args[0]) ) {
		int which = member_array("against STR", Rules);
		
		if( which == -1 && member_array("STR", Rules) == -1 ) {
		    return GetErrorMessage();
		}
		return ({ args[0] });
	    }
	}
	if( member_array("STR of LIV", Rules) == -1 ) {
	    return GetErrorMessage();
	}
	if( stringp(args[0]) && objectp(args[1]) && living(args[1]) ) {
	    return ({ args[0], args[1] });
	}
	return "Cast it on what of whom?";
    }
    else {
	if( count == 1 ) {
	    if( objectp(args[0]) ) {
		if( sizeof(({ "for OBJ", "for LIV" }) & Rules) ) {
		    if( !living(args[0]) ) {
			if( member_array("for OBJ", Rules) == -1 ) {
			    return GetErrorMessage();
			}
		    }
		    return ({ args[0] });
		}
		return GetErrorMessage();
	    }
	    if( member_array("against STR", Rules) == -1 ) {
		return GetErrorMessage();
	    }
	    return ({ args[0] });
	}
	if( member_array("against STR for LIV", Rules) == -1 ) {
	    return GetErrorMessage();
	}
	if( stringp(args[0]) && objectp(args[1]) && living(args[1]) ) {
	    return ({ args[0], args[1] });
	}
	return "Pray for it against what for whom?";
    }
}

/* ***************** spell.c driver applies ******************** */
static void create() {
    daemon::create();
    SetNoClean(1);
}

void eventTrainSpell(object who, int success) {
  int points = 4 + (success * 4);
  int numskills =0;
  int skillval = 1;

  foreach(string skill in GetSkills()) {
    numskills++;
    if(numskills<=2) {

      points *= skillval;
    }
  }

  if(numskills==1) {
    points *= skillval;
  }
  points += GetDifficulty() * 5;
  foreach(string skill in GetSkills()) {
    who->AddSkillPoints(skill, points);
  }
}

int eventFail(object who, int grade) {
	object fail;
	
  send_messages("", "$agent_possessive_noun spell fails!", 
                who, 0, environment(who) );
	if (grade < 0) grade = 0;
	switch(grade) {
		case 0..100:
		  fail = FAILURE_D->GetFailure("minor");
		  if (!fail) return 1;
		  fail->eventFail(who, this_object());
		  return 1;
		  break;
		case 101..200:
		  fail = FAILURE_D->GetFailure("moderate");
		  if (!fail) return 1;
		  fail->eventFail(who, this_object());
		  return 1;
		  break;
		case 201..500:
		  fail = FAILURE_D->GetFailure("major");
		  if (!fail) return 1;
		  fail->eventFail(who, this_object());
		  return 1;
		  break;
		default:
		  fail = FAILURE_D->GetFailure("catastrophic");
		  if (!fail) return 1;
		  fail->eventFail(who, this_object());
		  return 1;
		  break;
    }
}

int SetProtectionTypes(int x) { return ProtectionTypes = x; }

int GetProtectionTypes() { return ProtectionTypes; }

int SetProtectionAmount(int x) { return ProtectionAmount = x; }

int GetProtectionAmount() { return ProtectionAmount; }

int SetProtectionTime(int x) { return ProtectionTime = x; }

int GetProtectionTime() { return ProtectionTime; }

int hitCallback(object who, object agent, int x, class MagicProtection cl) {
   string str;
   object Caster = cl->caster;

//debug("w="+base_name(who)+", a="+base_name(agent)+", e="+base_name(environment(who)));
  send_messages(Messages[1][0], Messages[1][1],
                  who, agent, environment(who));
  return x;
}

void endCallback(object who) {
    if( who ) {
        send_messages(Messages[2][0], Messages[2][1], who, 0, environment(who));
    }
}

string GetHelp(string str) {
         object who = this_player();
//         debug("Who?: " + who->GetName());
	 string tmp = "Syntax:   ";
	 foreach(string rule in Rules) {
	 	  tmp += "cast " + GetSpell();
	 	  if (rule == "") { tmp += "\n          "; }
	 	  else { tmp += " on " + rule + "\n          "; }
	 	}
	 tmp += "\n";
	 switch(SpellType) {
	  case SPELL_COMBAT:
	    tmp += "Type: Combat\n";
	    break;
	  case SPELL_DEFENSE:
	    if (ShieldType == SHIELD_TIMED)  tmp += "Type: Timed Shield\n";
	    if (ShieldType == SHIELD_DAMAGE) tmp += "Type: Damage-based Shield\n";
	    break;
	  case SPELL_HEALING:
	    tmp += "Type: Healing\n";
	    break;
	  case SPELL_OTHER:
	    tmp += "Type: Special Magic\n";
	    break;
	 }
	 
	 tmp += "Spell Level: " + GetSpellLevel() + "\n";
	 tmp += "Requirements: ";
	 foreach(string skill in GetSkills()) {
	 	tmp += skill + ": " + GetRequiredSkill(skill) + " ";
	  }
	if (MinMorality != -1) tmp += " Minimum Morality: (" + MinMorality + ") ";
	if (MaxMorality != -1) tmp += " Maximum Morality: (" + MaxMorality + ") ";
	tmp += "\n";
	if (sizeof(EnhanceSkills)) tmp += "Enhancing Skills: " + conjunction(EnhanceSkills, "and") +"\n"; 
	tmp += "Casting costs: ";
	if (SpellType == SPELL_DEFENSE && !DrinkCost[0]) MagicCost = ({ (GetSpellLevel() * 2) + 20, (GetSpellLevel() * 2) + 20 });
	if (SpellType == SPELL_COMBAT && !DrinkCost[0])  MagicCost = ({ GetSpellLevel() + 10, GetSpellLevel() + 10 });
	if (SpellType == SPELL_HEALING && !DrinkCost[0]) MagicCost = ({ (GetSpellLevel() * 2) + 20, (GetSpellLevel() * 2) + 20 });
	if ((MagicCost[0] + MagicCost[1]))     tmp += (MagicCost[0]   + "-" + (MagicCost[0]   + MagicCost[1]))   + " Magic ";
	if ((StaminaCost[0] + StaminaCost[1])) tmp += (StaminaCost[0] + "-" + (StaminaCost[0] + StaminaCost[1])) + " Stamina ";
	if ((HealthCost[0] + HealthCost[1]))   tmp += (HealthCost[0]  + "-" + (HealthCost[0]  + HealthCost[1]))  + " Health ";
	if ((DrinkCost[0] + DrinkCost[1]))   tmp += (DrinkCost[0]  + "-" + (DrinkCost[0]  + DrinkCost[1]))  + " Drink (Blood) ";
	tmp += "\n";
	if (sizeof(GetReligions())) 
		tmp += "Religion: " + conjunction(GetReligions(), "or") + "\n";
	if (UniqueSpell) tmp += "This spell is UNIQUE and must be taught by specific individuals.\n";
        
	/* If we know this spell, display what % we know it at - mel 1/22/2019 */
        if (playerp(who)) {
            if (member_array(str, keys(who->GetSpellBook())) != -1) {
                 tmp += "\nYour Mastery: " + who->GetSpellLevel(str) + "%\n";
            }
        }
	tmp += "\n" + ::GetHelp("bleh") + "\n";
	return tmp;
}


int GetSpellLevel() {
	int tmp = 0;
	foreach(string skill in GetSkills()) {
		tmp += GetRequiredSkill(skill);
	}
	tmp -= 4 * sizeof(GetSkills());
	tmp = tmp/2;
	tmp = tmp/ sizeof(GetSkills());
	if (tmp <= 1) tmp = 1;
	return tmp;
}

/*  Compat-buster functions */
int SetRequiredHealth(int x) { return 0; }
int SetRequiredStamina(int x) { return 0; }
int SetRequiredMagic(int x) { return 0; }
