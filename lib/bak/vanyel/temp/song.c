/*    /lib/song.c
 *    From Dead Souls LPMud
 *    An object all songs inherit.
 *    Created by Descartes of Borg 951027
 *    Version: @(#) song.c 1.22@(#)
 *    Last modified: 96/12/17
 */

#include <lib.h>
#include <daemons.h>
#include <music.h>
#include <magic.h>
#include <damage_types.h>
#include <magic_protection.h>

inherit LIB_DAEMON;
inherit LIB_HELP;
private int          AreaSong = 0, GlobalSong = 0;    // Special Songs
private int          AutoDamage      = -1;            // perform dmg?
private int          AutoHeal        = -1;            // perform healing?
private string       Conjure         = 0;             // file to clone
private int array    Damage          = ({ 0, 0 });    // base, random
private mixed array  Messages        = ({});          // damage/heal messages
private int          DamageType      = MAGIC;         // damage type done
private int          Difficulty      = 0;             // 1-100 scale
private int array    Healing         = ({ 0, 0 });    // base, random
private int array    MagicCost       = ({ 0, 0 });    // base, random
private int          Morality        = 0;             // bad? good?
private int          ProtectionAmount = 0;
private int          ProtectionTime  = 0;
private int          ProtectionTypes = 0;
private string array Religions       = 0;             // limit who can sing
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
string GetSong();

/* ********************* song.c attributes ************************ */
int SetAreaSong(int x) { return AreaSong = x; }

int GetAreaSong() { return AreaSong; }

int SetGlobalSong(int x) { return GlobalSong = x; }

int GetGlobalSong() { return GlobalSong; }


int GetAutoDamage() {
    return AutoDamage;
}

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

static string SetConjure(string str) {
    return (Conjure = str);
}

int GetDamage() {
    int damage = Damage[0];

    if( Damage[1] ) {
	damage += random(Damage[1]);
    }
    return damage;
}

varargs static void SetDamage(int type, mixed array rest...) {
    DamageType = type;
    if( arrayp(rest[0]) ) {
	rest = rest[0];
    }
    Damage[0] = rest[0];
    if( sizeof(rest) == 2 ) {
	Damage[1] = rest[1];
    }
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
	if( Verb == "pray" ) {
	    return "Just pray for it.";
	}
	else {
	    return "Simply sing it?";
	}

    case "LIV":
	if( Verb == "pray" ) {
	    return "Pray for it for whom?";
	}
	else {
	    return "Sing it on whom?";
	}

    case "OBJ": case "STR": 
	if( Verb == "pray" ) {
	    return "Pray for it for what?";
	}
	else {
	    return "Sing it on what?";
	}

    case "STR of LIV":
	if( Verb == "pray" ) {
	    return "Pray for it for whom against what?";
	}
	else {
	    return "Sing it on what of whom?";
	}

    case "for LIV": 
	return "Pray for it for whom?";

    case "for OBJ":
	return "Pray for it for what?";

    case "against STR":
	if( Verb == "pray" ) {
	    return "Pray against what?";
	}
	else {
	    return "Sing against what?";
	}
	
    case "against STR for LIV":
	return "Pray against what for whom?";
    }
    if( Verb == "pray" ) {
	return "Pray for it?";
    }
    return "Sing it?";
}

int GetHealing() {
    return Healing[0] + random(Healing[1]);
}

static varargs int array SetHealing(mixed args...) {
    Healing[0] = args[0];
    if( sizeof(args) == 2 ) {
	Healing[1] = args[1];
    }
    return Healing;
}

int GetMagicCost(object who) {
    return MagicCost[0] + MagicCost[1] - (MagicCost[1]* who->GetSongLevel(GetSong())/100);
}

static varargs int array SetMagicCost(mixed args...) {
    MagicCost[0] = args[0];
    if( sizeof(args) == 2 ) {
	MagicCost[1] = args[1];
    }
    return MagicCost;
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
	max = Healing[0] + Healing[1];
    }
    else {
	max = Damage[0] + Damage[1];
    }
    div = max/(sizeof(Messages) - 1);
    i = (damage/div) + 1;
    if( i >= sizeof(Messages) ) {
	i = sizeof(Messages)-1;
    }
    return Messages[i];
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

string array GetReligions() {
    return copy(Religions);
}

varargs static string array SetReligions(string array religions...) {
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
    return (SongType = x);
}

int GetStaminaCost(object who) {
    return StaminaCost[0] + StaminaCost[1] - (StaminaCost[1] * who->GetSongLevel(GetSong())/100);
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
      targets = filter(all_inventory(env), (: noncreatorp :));
      return (targets - ({ who }));
      }   /* Return all living targets for an area spell. */
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
          filter(args, (: !(environment($1)->GetProperty("no magic")) :) );
          filter(args, (: !(environment($1)->GetProperty("no attack")) :));
          filter(args, (: !($1)->GetInvis() :));
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
	  moral_act(who, enemies[i], 
                GetMorality() * query_sign(enemies[i]->GetMorality()) );
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
    int *failure = ({ 0, 0 });
    int count = sizeof(skills);
    int cost = GetMagicCost(who);
    int x;
    
    if (sizeof(Religions)) {
	if( member_array(who->GetReligion(1), Religions) == -1 ) {
	    who->eventPrint("Your deity does not have that kind of power."); 
	    return 0;
	}
  }
  if (cost > who->GetMagicPoints()) {
  	who->eventPrint("You don't have enough power.");
  	return 0;
  }
  
    if( cost > 0 ) {
	who->AddMagicPoints(-cost);
    }
    cost = GetStaminaCost(who);
    if (cost > who->GetStaminaPoints()) {
  	  who->eventPrint("You don't have enough stamina.");
  	return 0;
  }
  
    if( cost > 0 ) {
	who->AddStaminaPoints(-cost);
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
	    if( max_hp - hp < (Healing[0]+Healing[1])/10 + 1 ) {
		if( limb ) {
		    send_messages("", "$target_possessive_noun " + limb +
				  " needs no healing.", who, targets[i]);
		}
		else {
		    send_messages("need", "$target_name $target_verb no "
				  "healing.", who, targets[i]);
		}
		targets[i] = 0;
		continue;
	    }
	}
	if( !sizeof(filter(targets, (: $1 :))) ) {
	    who->eventPrint("No targets.");
	    return 0;
	}
    }	
    foreach(string skill in skills) {
	level += who->GetSkillLevel(skill);
    }
    
    if( AutoDamage != -1 ) {
	if( CanAttack(who, targets, level) == - 1 ) {
	    who->eventPrint("Your powers fail you.");
	    return 0;
	}
    }
    else {
	if( GetMorality() ) {
	    moral_act(who, 0, GetMorality());
	  }
	}
  
   
  failure[0] = GetDifficulty();
  failure[0] = (failure[0] * 50) / (who->GetSongLevel(GetSong()));
  foreach(string skill in GetSkills()) {
    failure[0] -= (who->GetSkillLevel(skill) - GetRequiredSkill(skill)) * 5; 
    }
  if (failure[0] < 0) failure[0] = 0;
  failure[1] = random(100);
  if (failure[1]  < failure[0]) {
  	 eventFail(who, failure[1] - failure[0]);
  	 eventTrainSong(who, 0);
  	 return 0;
  	 }
    eventTrainSong(who, 1);
    return 1;
}

/* ******************** song.c events *********************** */
/* -1 means this did nothing
 * otherwise return damage amount for SONG_DAMAGE
 * or heal amount for SONG_HEAL
 */
varargs int eventSing(object who, int level, mixed limb, object array targets) {
  class MagicProtection protection;
  
  if (SongType == SONG_DEFENSE) {
  	protection = new(class MagicProtection);
  	protection->bits = ProtectionTypes;
  	protection->end = (: endCallback :);
    protection->hit = (: hitCallback :);
  	protection->caster = who;
  	if (GetMorality())
        moral_act(who, targets[0], GetMorality() *
            query_sign(targets[0]->GetMorality()) );
  	if (ProtectionTime) {
  		protection->time = ProtectionTime;
  		protection->protect = ProtectionAmount;
  	} else {
  		protection->absorb = ProtectionAmount;
  	}
  	protection->args = level;
  	protection->name = GetSong();
  	if(targets[0]->AddMagicProtection(protection)) {
  		send_messages(Messages[0][0], Messages[0][1], who, targets[0], environment(who));
  		return 1;
  	} else {
  		send_messages("", "$agent_possessive_noun song fails to add more shielding.", who, 0, environment(who));
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
	    healing = (GetHealing() * level)/100;
	    healing = target->eventHealDamage(healing, AutoHeal, limb);
	    total_healing += healing;
	    tmp = GetMessage(healing, 1);
	    if( !messages[tmp[1]] ) {
		messages[tmp[1]] = ([ tmp[0] : ({ target }) ]);
	    }
	    else {
		if( !messages[tmp[1]][tmp[0]] ) {
		    messages[tmp[1]][tmp[0]] = ({ target });
		}
		else {
		    messages[tmp[1]][tmp[0]] += ({ target });
		}
	    }
	}
	foreach(string message, mapping tmp in messages) {
	    foreach(string verb, object array obs in tmp) {
		send_messages(verb, message, who, obs,
			      environment(who), ([ "$limb" : limb ]));
	    }
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

	foreach(object target in targets) {
	    string array tmp;
	    int damage;

	    if( !target ) {
		continue;
	    }
	    damage = (GetDamage() * level)/100;
	    damage = target->eventReceiveDamage(who, GetDamageType(), damage,
						AutoDamage, limb);
	    total_damage += damage;
	    tmp = GetMessage(damage);
	    if( !messages[tmp[1]] ) {
		messages[tmp[1]] = ([ tmp[0] : ({ target }) ]);
	    }
	    else {
		if( !messages[tmp[1]][tmp[0]] ) {
		    messages[tmp[1]][tmp[0]] = ({ target });
		}
		else {
		    messages[tmp[1]][tmp[0]] += ({ target });
		}
	    }
	}
	foreach(string message, mapping tmp in messages) {
	    foreach(string verb, object array obs in tmp) {
		send_messages(verb, message, who, obs,
			      environment(who), ([ "$limb" : limb ]));
	    }
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
  int skillcnt = 0;
  int skillnum = 1;

  foreach(string skill in GetSkills()) {
    skillcnt++;
    if(skillcnt<=2) {
      skillnum = GetRequiredSkill(skill);
      points *= skillnum;
    }
  }
  if(skillcnt==1) {
    points *= skillnum;
  }
  points += GetDifficulty() * 5;
  foreach(string skill in GetSkills()) {
    who->AddSkillPoints(skill, points);
    }
}

int eventFail(object who, int grade) {
	string fail;
	
  send_messages("", "$agent_possessive_noun song fails.", 
                who, 0, environment(who) );
	if (grade < 0) grade = 0;
	switch(grade) {
		case 0..50:
		  fail = (FAILURE_D->GetFailure("minor"));
		  if (!fail) return 1;
		  fail->eventFail(who, this_object());
		  return 1;
		  break;
		case 51..100:
		  fail = FAILURE_D->GetFailure("moderate");
		  if (!fail) return 1;
		  fail->eventFail(who, this_object());
		  return 1;
		  break;
		case 101..200:
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
	 tmp += ::GetHelp("bleh") + "\n";
	 tmp += "Requirements: ";
	 foreach(string skill in GetSkills()) {
	 	tmp += skill + ": " + GetRequiredSkill(skill) + " ";
	}
	tmp += "\n";
	if (sizeof(GetReligions())) {
		tmp += "Religion: " + conjunction(GetReligions(), "or");
	}
	return tmp;
}
