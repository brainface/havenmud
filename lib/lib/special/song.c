/*    /lib/song.c
 *    From Dead Souls LPMud
 *    An object all songs inherit.
 *    Created by Descartes of Borg 951027
 *    Version: @(#) song.c 1.22@(#)
 *    Last modified: 96/12/17
 */

#include <lib.h>
#include <daemons.h>
#include <magic.h>
#include <music.h>
#include <damage_types.h>
#include <magic_protection.h>

inherit LIB_DAEMON;
inherit LIB_HELP;
private int          AreaSong       = 0; 
private int          GlobalSong     = 0;
private int          AutoDamage      = -1;            // perform dmg?
private int          AutoHeal        = -1;            // perform healing?
private string       Conjure         = 0;             // file to clone
private int          Cooldown        = 0;
private int array    Damage          = ({ 0, 0 });    // base, random
private int          DamagingShield  = 0;
private mixed array  Messages        = ({});          // damage/heal messages
private int          DamageType      = MAGIC;         // damage type done
private int          Difficulty      = 0;             // 1-100 scale
private string      *EnhanceSkills   = ({});
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
private string      *Religions       = ({ });             // limit who can sing
private int          RemoteTargets   = 0;             // can targets be remote
private string array Rules           = ({});          // song rules
private mapping      Skills          = ([]);          // skill requirements
private string       SongName       = "";            // name of song
private int          SongType       = SONG_HEALING; // song type
private int array    StaminaCost     = ({ 0, 0 });    // base, random
private int          UniqueSong     = 0;             // Is this a special song?
private string       Verb            = "sing";        // use what verb?

/* Defs for new lib */
void eventTrainSong(object who, int success);
int eventFail(object who, int grade);
int hitCallback(object, object, int, class MagicProtection);
void endCallback(object); 
int eventTestFailure(object who, int level, mixed limb, object array targets);
string GetSong();
int GetSongLevel();

/* ********************* song.c attributes ************************ */

int SetAreaSong(int x) { return AreaSong = x; }

int GetAreaSong() { return AreaSong; }

int SetGlobalSong(int x) { return GlobalSong = x; }

int GetGlobalSong() { return GlobalSong; }


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

string *SetEnhanceSkills(string *sk) { return EnhanceSkills = sk; }
string *GetEnhanceSkills() { return EnhanceSkills; }

int GetDamage(int level) {
  int damage;
  
  damage = GetSongLevel() * level;
  damage = damage/3;
  if (damage < 1) damage = 1;
  damage += random(damage);
  return damage;
}

int SetDamageType(int type) {
  return DamageType = type;
}

varargs static void SetDamage(int type, mixed array rest...) {
   /* unused. Mostly */
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

int SetUniqueSong(int x) { return UniqueSong = x; }

int GetUniqueSong() { return UniqueSong; }

string GetErrorMessage() {
  string rule = Rules[0];

  switch(rule) {
    case "":
	    return "Simply sing it?";
    case "LIV":
	    return "Sing it on whom?";
    case "OBJ": case "STR": 
	    return "Sing it on what?";
    case "STR of LIV":
	    return "Sing it on what of whom?";
    case "against STR":
	    return "Sing against what?";
    default:
      return "Sing it?";
    }
}

int GetHealing(int level) {
  int damage;
  
  damage = GetSongLevel() * level;
  damage = damage/10;
  if (damage < 1) damage = 1;
  damage += random(damage) + random(damage);
  return damage;
}

static varargs int array SetHealing(mixed args...) {
  /* unused */
    return Healing;
}


int GetMagicCost(object who) {
    if (SongType == SONG_DEFENSE) MagicCost = ({ (GetSongLevel() * 2) + 20, (GetSongLevel() * 2) + 20 });
      if (SongType == SONG_COMBAT)  MagicCost = ({ (GetSongLevel()) + 10, (GetSongLevel()) + 10 });
    if (SongType == SONG_HEALING) MagicCost = ({ (GetSongLevel() * 2) + 20, (GetSongLevel() * 2) + 20 });
    return MagicCost[0] + MagicCost[1] - (MagicCost[1]* who->GetSongLevel(GetSong())/100);
}

static varargs int array SetMagicCost(mixed args...) {
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
	max = GetSongLevel() * 30;;
    }
    else {
	max = GetSongLevel() * 30;
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

string GetSong() {
    return SongName;
}

static string SetSong(string str) {
    return (SongName = str);
}

int GetSongType() {
    return SongType;
}

static int SetSongType(int x) {
    if (x == SONG_COMBAT) SetMorality(-1);
    if (x == SONG_HEALING) SetMorality(1);
    return (SongType = x);
}

int GetStaminaCost(object who) {
    return StaminaCost[0] + StaminaCost[1] - (StaminaCost[1] * who->GetSongLevel(GetSong())/100);
}

int GetHealthCost(object who) {
    return HealthCost[0] + HealthCost[1] - (HealthCost[1] * who->GetSongLevel(GetSong())/100);
}


static varargs int array SetStaminaCost(mixed args...) {
    StaminaCost[0] = args[0];
    if( sizeof(args) == 2 ) {
	StaminaCost[1] = args[1];
    }
    return StaminaCost;
}
varargs object *GetTargets(object who, mixed args...) {
   object env = environment(who);
   object array targets = ({ });
   object def;
   int count = sizeof(args);
   int attack = (SongType == SONG_COMBAT);

  if (attack) {
      def = who->GetCurrentEnemy();
      if (!(who->GetInCombat())) def = 0;
      }
     else {
      def = who;
     }

/* Set up target for SetRules("") responses. */

  if (!count) {                     /*  There are no arguments passed. */
     if (member_array("", Rules) == -1) {
          return 0;
        }     /*  Returns no target if no argument is not a valid rule. */
   if (AreaSong == 1) {
      targets = filter(all_inventory(env), (: living :));
      targets = filter(targets, (: noncreatorp :) );
      return (targets - ({ who }));
      }   /* Return all living targets for an area song. */
    else {
            if ( (def) && (!AreaSong) ) {
              return ({ def });
             }
        else {
       return 0;
      }
   }
    }  /*  End of No Arg */

/*  Number of Args == 1
 *  Test for objectp() livingp()
 *  Test Rules arrays for Possible Targets
 */

  else if (count == 1) {          
      if (objectp(args[0])) {       /*  If the first arg is an object */
         if (living(args[0])) {      /*  If the object is a living */
            if (member_array("LIV", Rules) == -1) {  
              /*  Living is not a valid Rule for this song. */
               return 0;
               }  
             else {
                return ({ args[0] });
                }
           }
         else {                 /*  Args are not living, but are object */
            if (member_array("OBJ", Rules) == -1) {
               /*  OBJ is not a valid Rule for this song. */
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
         if (GlobalSong) {
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
                  if( (def) && (!GlobalSong) ) {
                      return ({ def });
                    }
                  else {
                      return 0;
                    }
                 }
         }
      /*  More than 1 argument passed */
       }

/*  Multiple Argument Songs
 *  Allowed on STR of LIV
 */

  if (objectp(args[1])) {    /*  Check to be sure second arg is an object */
      if (living(args[1])) {   /*  If object is living. */
         if (member_array("STR of LIV", Rules) == -1) {
             /*  Cannot sing this song on STR of LIV */
             return 0;
             }
       else {
           return ({ args[1] });
            }
          }
        else {
           if (member_array("STR of OBJ", Rules) == -1) {
              /*  Cannot sing this song on STR of OBJ */
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

/* ******************** song.c modals *************************** */
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
	
	power += (GetSongLevel() - enemies[i]->GetLevel());
	if( !enemies[i]->eventReceiveAttack(power, "magic", who) ) {
	    misses += enemies[i]->GetLevel();
	    miss_count++;
	    miss_con += enemies[i]->GetMagicResistance();
	    send_messages("repel", "$target_name $target_verb "
			  "$agent_possessive_noun magic attack.", who,
			  enemies[i], area);
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

varargs int CanSing(object who, int level, string limb, object array targets) {
    string array skills = GetSkills();
    int count = sizeof(skills);
    int cost = GetMagicCost(who);
    int x;
    object env = environment(who);

  if (!env) {
    who->eventPrint("You have issues.");
    return 0;
  }
  if (env->GetProperty("no magic")) {
    who->eventPrint("Something prevents the magic.");
    return 0;
  }
  if (env->GetProperty("no attack") && SongType == SONG_COMBAT) {
    who->eventPrint("You cannot attack here!");
    return 0;
  }
  if (MinMorality != -1) {
    if (who->GetMorality() < MinMorality) {
      who->eventPrint("You lack sufficient morality to sing that song!");
      return 0;
    }
  }
  if (MaxMorality != -1) {
    if (who->GetMorality() > MaxMorality) {
      who->eventPrint("You are far too pious to sing that song!");
      return 0;
    }
  }
  if (sizeof(Religions)) {
	  if( member_array(who->GetReligion(1), Religions) == -1 ) {
	    who->eventPrint("Your religion does not have that kind of power."); 
	    return 0;
	  }
  }
  if (who->GetCooldown(GetSong()) > 0) {
  	who->eventPrint("You cannot cast " + GetSong() + " for another " + who->GetCooldown(GetSong()) + " seconds.");
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

/* ******************** song.c events *********************** */

/*
 * 1 means it failed, 0 means it did not
 */
int eventTestFailure(object who, int level, mixed limb, object array targets) {
    int *failure = ({ 0, 0 });
    int fc = 0;
    failure[0] = random(GetDifficulty());
    failure[0] = (failure[0] * 50) / (who->GetSongLevel(GetSong()));
    failure[0] += (who->GetRecoveryTime() * 3); 
    foreach(string skill in GetSkills()) {
	    failure[0] -= (who->GetSkillLevel(skill) - GetRequiredSkill(skill)) * 5; 
      }
    if (failure[0] < 0) failure[0] = 0;
    failure[1] = random(100);
    if (failure[1]  < failure[0]) {
	    fc = failure[0] - failure[1];
	    if (fc > GetSongLevel() * 4) fc = GetSongLevel() * 4;
	    if (who->GetTestChar())
	      debug("Random -> " + failure[1] + " FailChance -> " + failure[0] + " eventFail called (" + (fc) + ")");
	    eventFail(who, fc);
	    eventTrainSong(who, 0);
	    return 1;
      }
    eventTrainSong(who, 1); 
    if (RecoveryTime) {
     	who->AddRecoveryTime(RecoveryTime);
      }
  	if (GetMorality())
        moral_act(who, targets[0], GetMorality() * (query_sign(targets[0]->GetMorality()) || 1) );
    return 0;
}

/* -1 means this did nothing
 * otherwise return damage amount for SONG_DAMAGE
 * or heal amount for SONG_HEAL
 */
varargs int eventSing(object who, int level, mixed limb, object array targets) {
  class MagicProtection protection;
  
  if (GetCooldown()) { who->AddCooldown(GetSong(), GetCooldown()); }
  if (SongType == SONG_DEFENSE) {
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
  		protection->time    = (GetSongLevel() * level)/10 + 1; 
  		protection->protect = ((GetSongLevel() * level)/10 + 1) ;
  		if (who->GetTestChar())
  		  debug("Time = " + protection->time + " Amount = " +  protection->protect + " SL: " + GetSongLevel());
  	} else {
  		protection->absorb = (GetSongLevel() * level);
  		if (who->GetTestChar())
  		  debug("Absorb = " +  protection->absorb + " SL: " + GetSongLevel());
  	}
  	protection->args = level;
  	protection->name = GetSong();
  	if(targets[0]->AddMagicProtection(protection)) {
  		send_messages(Messages[0][0], Messages[0][1], who, targets[0], environment(who));
  		return 1;
  	} else {
                who->eventPrint("That person cannot have more protections right now.");
  		send_messages("", "$agent_possessive_noun song fails.", who, 0, environment(who));
  		return 1;
  	}
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
	    who->AddExperience(healing);
	    total_healing += healing;
	    tmp = GetMessage(healing, 1);
	    send_messages(tmp[0], tmp[1], who, target, environment(who));
	    /* if( !messages[tmp[1]] ) {
		messages[tmp[1]] = ([ tmp[0] : ({ target }) ]);
	    } else {
		if( !messages[tmp[1]][tmp[0]] ) {
		    messages[tmp[1]][tmp[0]] = ({ target });
		}	else {
		    messages[tmp[1]][tmp[0]] += ({ target });
		  }
	  } */
	}
/*	foreach(string message, mapping tmp in messages) {
	    foreach(string verb, object array obs in tmp) {
		send_messages(verb, message, who, obs,
			      environment(who), ([ "$limb" : limb ]));
	    }
	} */
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
  
  if( CanAttack(who, targets, GetSongLevel() + level/5) == - 1 ) {
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
	      int damageboost = who->GetSkillLevel(enhance) / (GetSongLevel() * 2);
	      if (damageboost > 3) damageboost = 3;
	      damage += damage * damageboost;
	    }  
	    damage = target->GetDamageInflicted(who, GetDamageType(), damage,	AutoDamage, limb);
	    tmp = GetMessage(damage);
	    send_messages(tmp[0], tmp[1], who, target, environment(who));
	    
	    damage = target->eventInflictDamage(who, GetDamageType(), damage,	AutoDamage, limb);
	    total_damage += damage;
	    /* if( !messages[tmp[1]] ) {
		messages[tmp[1]] = ([ tmp[0] : ({ target }) ]);
	    } else {
		if( !messages[tmp[1]][tmp[0]] ) {
		    messages[tmp[1]][tmp[0]] = ({ target });
		}	else {
		    messages[tmp[1]][tmp[0]] += ({ target });
		  }
	  } */
	}
/*	foreach(string message, mapping tmp in messages) {
	    foreach(string verb, object array obs in tmp) {
		send_messages(verb, message, who, obs,
			      environment(who), ([ "$limb" : limb ]));
	    }
	} */
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
    if( Verb == "sing" ) {
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
	return "Sing it on what of whom?";
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

/* ***************** song.c driver applies ******************** */
static void create() {
    daemon::create();
    SetNoClean(1);
}

void eventTrainSong(object who, int success) {
  int points = 4 + (success * 4);
  int numskills =0;
  int skillval = 1;

  foreach(string skill in GetSkills()) {
    numskills++;
    if(numskills<=2) {
      skillval = GetRequiredSkill(skill);
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
	
  send_messages("", "$agent_possessive_noun song fails.", 
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
   object Singer = cl->caster;

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
	 string tmp = "Syntax:   ";
	 foreach(string rule in Rules) {
	 	  tmp += "sing " + GetSong();
	 	  if (rule == "") { tmp += "\n          "; }
	 	  else { tmp += " to " + rule + "\n          "; }
	 	}
	 tmp += "\n";
	 switch(SongType) {
	  case SONG_COMBAT:
	    tmp += "Type: Combat\n";
	    break;
	  case SONG_DEFENSE:
	    if (ShieldType == SHIELD_TIMED)  tmp += "Type: Timed Shield\n";
	    if (ShieldType == SHIELD_DAMAGE) tmp += "Type: Damage-based Shield\n";
	    break;
	  case SONG_HEALING:
	    tmp += "Type: Healing\n";
	    break;
	  case SONG_OTHER:
	    tmp += "Type: Special Magic\n";
	    break;
	 }
	 tmp += "Song Level: " + GetSongLevel() + "\n";
	 tmp += "Requirements: ";
	 foreach(string skill in GetSkills()) {
	 	tmp += skill + ": " + GetRequiredSkill(skill) + " ";
	}
	tmp += "\n";
	if (sizeof(EnhanceSkills)) tmp += "Enhancing Skills: " + conjunction(EnhanceSkills, "and") +"\n"; 
	tmp += "Singing costs: ";
  if (SongType == SONG_DEFENSE) MagicCost = ({ (GetSongLevel() * 2) + 20, (GetSongLevel() * 2) + 20 });
    if (SongType == SONG_COMBAT)  MagicCost = ({ (GetSongLevel()) + 10, (GetSongLevel()) + 10 });
  if (SongType == SONG_HEALING) MagicCost = ({ (GetSongLevel() * 2) + 20, (GetSongLevel() * 2) + 20 });	
	if ((MagicCost[0]   + MagicCost[1]))   tmp += (MagicCost[0]  + "-" + (MagicCost[0]   + MagicCost[1]))  + " Magic ";
	if ((StaminaCost[0] + StaminaCost[1])) tmp += (StaminaCost[0]+ "-" + (StaminaCost[0] + StaminaCost[1]))+ " Stamina ";
	if ((HealthCost[0]  + HealthCost[1]))  tmp += (HealthCost[0] + "-" + (HealthCost[0]  + HealthCost[1])) + " Health ";
	tmp += "\n";
	if (sizeof(GetReligions())) {
		tmp += "Religion: " + conjunction(GetReligions(), "or");
		if (UniqueSong) tmp += "\n";
	}
	if (UniqueSong) {
	  tmp += "This song is UNIQUE and must be taught by specific individuals.\n";
	  }
	tmp += "\n" + ::GetHelp("bleh") + "\n";
	return tmp;
}


int GetSongLevel() {
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
