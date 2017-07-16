/*    /lib/spell.c
 *    From Nightmare LPMud
 *    An object all spells inherit.
 *    Created by Descartes of Borg 951027
 *    Version: @(#) spell.c 1.20@(#)
 *    Last modified: 15 November 1998
 *    Was modified a while back by Zaxan@Haven
 *    Recent ReWrites for Haven
 *    done by Duuktsaryth
 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <daemons.h>
#include <magic_protection.h>
#define MAGIC_PILLARS ({ "conjuring", "faith", "natural magic", "chaos magic" })

inherit LIB_DAEMON;
inherit LIB_HELP;
int hitCallBack(object who, object agent, int x, class MagicProtection mp);
void endCallBack(object who);
string GetDetailedHelp(string useless);
string SetDetailedHelp(string str);

private int          AllLimbs = 0;                    // All limbs?
private int	     AreaSpell       = 0;	      // Affect all in env?
private int          AutoDamage      = -1;            // perform dmg?
private int          AutoHeal        = -1;            // perform healing?
private string       Conjure         = 0;             // file to clone
private int array    Damage          = ({ 0, 0 });    // base, random
private int          DamagingShield  = 0;             // no-yes
private mixed array  Messages        = ({});          // damage/heal messages
private int          DamageType      = MAGIC;         // damage type done
private int          Difficulty      = 0;             // 1-100 scale
private mixed array  Failure         = ({ 0, 0 });     // See below
private int	     GlobalSpell     = 0;	      // targetss anywhere?
private int array    Healing         = ({ 0, 0 });    // base, random
private int array    MagicCost       = ({ 0, 0 });    // base, random
private int array    HealthCost      = ({ 0, 0 });    // base, random
private int          Morality        = 0;             // bad? good?
private int          ProtectionAmount = 0;
private int          ProtectionBits  = 0;             // Types?
private int          ProtectionTime  = 0;
private function     ProtectionCallBack = (: hitCallBack :);
private function     ProtectionEndCall = (: endCallBack :);
private int          RecoveryTime    = 0;             // How long?
private string array  Religion       = ({ });     // Religions?
private int          RequiredMagic   = 0;             // min magic pts to cast
private int          RequiredHealth  = 0;             // min hp to cast
private int          RequiredStamina = 0;             // min stam pts to cast
private string array Rules           = ({});          // spell rules
private mapping      Skills          = ([]);          // skill requirements
private string       SpellName       = "";            // name of spell
private int          SpellType       = SPELL_HEALING; // spell type
private int array    StaminaCost     = ({ 0, 0 });    // base, random
private int          UniqueSpell     = 0;   // random
private string       DetailedHelp    = "";
private int          ProtectionLimit = 5;             // limits # of shields

static void create() {
    daemon::create();
    help::create();
    SetNoClean(1);
}

varargs mixed *SetFailure(int type, function failure) {
    if (type) (Failure[0] = type);
    if (failure) (Failure[1] = failure);
  }

mixed GetFailure(int value) {
    return (Failure[value]);
  }
varargs string *SetReligion(mixed who...) {
  if (arrayp(who)) return (Religion = who);
  else return (Religion = ({ who }) );
  }

string *GetReligion() {
    return (Religion);
  }

int SetDamagingShield(int flag) {
  return (DamagingShield = flag);
}

int GetDamagingShield() {
  return DamagingShield;
}

int SetProtectionTypes(int types) {
  return (ProtectionBits = types);
  }

int GetProtectionTypes() {
 return (ProtectionBits);
 }

int SetProtectionTime(int x) {
  return (ProtectionTime = x);
  }

int GetProtectionTime() {
  return (ProtectionTime);
 }

int SetProtectionAmount(int x) {
  return (ProtectionAmount = x);
  }

int GetProtectionAmount() {
  return (ProtectionAmount);
  }

mixed SetHitCallBack(mixed x) {
  return (ProtectionCallBack = x);
  }

mixed GetHitCallBack() {
  return (ProtectionCallBack);
  }

int SetProtectionLimit(int x) {
  return (ProtectionLimit = x);
  }

int GetProtectionLimit() {
  return (ProtectionLimit);
  }

mixed SetEndCall(mixed x) {
  return (ProtectionEndCall = x);
  }

mixed GetEndCall(mixed x) {
  return (ProtectionEndCall = x);
  }


int GetAreaSpell() {
    return AreaSpell;
}

static int SetAreaSpell(int x) {
    return (AreaSpell = x);
}

int GetAutoDamage() {
    return AutoDamage;
}

static int SetAutoDamage(int x) {
    return (AutoDamage = x);
}

int SetRecoveryTime(int rounds) {
   return (RecoveryTime = rounds);
  }

int GetRecoveryTime() {
  return (RecoveryTime);
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

int GetDamageType() {
    return DamageType;
}

int GetDifficulty() {
    return Difficulty;
}

static int SetDifficulty(int x) {
    return (Difficulty = x);
}

int GetGlobalSpell() {
    return GlobalSpell;
}

static int SetGlobalSpell(int x) {
    return (GlobalSpell = x);
}

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
    return "Cast it?";
  }
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

int GetMagicCost() {
    return MagicCost[0] + random(MagicCost[1]);
}

static varargs int array SetMagicCost(mixed args...) {
    MagicCost[0] = args[0];
    if( sizeof(args) == 2 ) {
	MagicCost[1] = args[1];
    }
    return MagicCost;
}

int GetMorality() {
    return Morality;
}

static int SetMorality(int x) {
    return (Morality = x);
}

int GetRequiredMagic() {
    return RequiredMagic;
}

static int SetRequiredMagic(int x) {
    return (RequiredMagic = x);
}

int GetRequiredStamina() {
    return RequiredStamina;
}

static int SetRequiredStamina(int x) {
    return (RequiredStamina = x);
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
    return (SpellType = x);
}

int GetHealthCost() {
     return (HealthCost[0] + random(HealthCost[1]));
 }

varargs int array SetHealthCost(int x, int y) {
   return (HealthCost = ({ x, y }));
  }

int GetRequiredHealth() {
   return (RequiredHealth);
   }

int SetRequiredHealth(int x) {
    return (RequiredHealth = x);
   }

int GetStaminaCost() {
    return StaminaCost[0] + random(StaminaCost[1]);
}

int SetAffectsAllLimbs(int x) {
    return (AllLimbs = x);
  }

int GetAffectsAllLimbs() {
    return (AllLimbs);
   }

static varargs int array SetStaminaCost(mixed args...) {
    StaminaCost[0] = args[0];
    if( sizeof(args) == 2 ) {
	StaminaCost[1] = args[1];
    }
    return StaminaCost;
}


string GetVerb() {
    return "cast";
}


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
            if( GlobalSpell ) {
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
    if( miss_count > 0 ) {
	bonus = who->GetTrainingModifier(misses/miss_count);
	foreach(string skill in GetSkills()) {
	    who->eventTrainSkill(skill, power/(hit_count+miss_count),
				 miss_con/miss_count, 0, bonus);
	}			 
    }
    if( hit_count < 1 ) {
	return -1;
    }
    bonus = who->GetTrainingModifier(hits/hit_count);	
    foreach(string skill in GetSkills()) {
	who->eventTrainSkill(skill, power/(hit_count+miss_count),
			     hit_con/hit_count, 1, bonus);
    }
    return 1;
}

varargs int CanCast(object who, int level, string limb, object array targets) {
    string array skills = GetSkills();
    string array tskills;
    object spell = this_object();
    int count = sizeof(skills);
    int cost = GetMagicCost();
    int x;

  if (!sizeof(targets)) {
		message("system", "Cast it on whom?", who);
		return 0;
	}
    if( cost > 0 ) {
	who->AddMagicPoints(-cost);
    }
   cost = GetHealthCost();
      if (cost > 0) {
          who->AddHealthPoints(-cost);
        }
    cost = GetStaminaCost();
    if( cost > 0 ) {
	who->AddStaminaPoints(-cost);
    }
    if (GetRecoveryTime()) who->AddRecoveryTime(GetRecoveryTime());
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
	    return 0;
	}
    }	
    foreach(string skill in skills) {
	level += who->GetSkillLevel(skill);
    }
    level = level/(count+1);
    if( AutoDamage != -1 ) {
	if( CanAttack(who, targets, level) == - 1 ) {
	    who->eventPrint("Your powers fail you.");
	    return 0;
	}
    }
    else {
	foreach(string skill in skills) {
	    who->eventTrainSkill(skill, level, GetDifficulty(), 1);
	}
    }
// Checks for spell immunities
    tskills = spell->GetSkills();
     
    foreach(object target in targets)
    {
      if(target->GetProperty("no magic") )
      {
        who->eventPrint(target->GetName() + " is protected against your magic "
                        "cancelling your spell.");
        return 0;
      }
      
      foreach(string tskill in tskills)
      {
        if( target->GetProperty("no " + tskill) )
        {
          who->eventPrint(target->GetName() + " is protected against your " +
                          tskill + " cancelling your spell.");
          return 0;
        }
      }
      
      if( target->GetProperty("no " + spell->GetSpell()) )
      {
        who->eventPrint(target->GetName() + " is protected against " +
                        spell->GetSpell() + ", causing your spell to fail.");
       return 0;
      }
    }
   if (GetFailure(1) && random(100) > level) {
      if (GetFailure(1) == FAILURE_UNIQUE) {
         evaluate(GetFailure(2), who, level, limb, targets);
         }
       else {
          SPELLS_D->GetSpellFailure(GetFailure(1))->eventSpellFailure(
                      who, level, limb, targets);
          }
        return 0;
       }
    return 1;
}

/* -1 means this did nothing
 * otherwise return damage amount for SPELL_DAMAGE
 * or heal amount for SPELL_HEAL
 */
varargs int eventCast(object who, int level, mixed limb, object array targets) {
    if (SpellType == SPELL_DEFENSE) {
      class MagicProtection mp;
      mp = new(class MagicProtection);
      mp->name   = GetSpell();
      mp->bits   = ProtectionBits;
      if (ProtectionTime) {
          mp->time = ProtectionTime;
          mp->protect = ProtectionAmount;
          }
     else
      mp->absorb = ProtectionAmount;
      mp->hit    = ProtectionCallBack;
      mp->end    = ProtectionEndCall;
      mp->caster = who;
      mp->args   = level;
      mp->limit  = ProtectionLimit;
      if (targets[0]->AddMagicProtection(mp)) {
        send_messages(Messages[0][0], Messages[0][1], who, targets[0],
                      environment(who));
        if (GetMorality())
        moral_act(who, targets[0], GetMorality() *
            query_sign(targets[0]->GetMorality()) );
        return 1;
      } else {
      who->eventPrint("Your spell fails horribly.");
        return 1;
        }
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
            moral_act(who, targets[0], GetMorality() *
                 query_sign(targets[0]->GetMorality()) );
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
            moral_act(who, targets[0], GetMorality() *
                 query_sign(targets[0]->GetMorality()) );
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
		if( member_array("STR", Rules) == -1 ) {
		    return GetErrorMessage();
		}
		return ({ args[0] });
	    }
	}
	if( member_array("STR of LIV", Rules) == -1 ) {
	    return GetErrorMessage();
	}
     if (stringp(args[0]) && objectp(args[1]) && living(args[1]) ) {
	    return ({ args[0], args[1] });
	}
	return "Cast it on what of whom?";
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

/* Set up target for SetRules("") responses. */

  if (!count) {                     /*  There are no arguments passed. */
     if (member_array("", Rules) == -1) {
          return 0;
        }     /*  Returns no target if no argument is not a valid rule. */
   if (AreaSpell == 1) {
      targets = filter(all_inventory(env), (: noncreatorp :));
      return (targets - ({ who }));
      }   /* Return all living targets for an area spell. */
    else {
            if ( (def) && (!AreaSpell) ) {
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
          filter(args, (: !(environment($1)->GetProperty("no magic")) :) );
          filter(args, (: !(environment($1)->GetProperty("no attack")) :));
          filter(args, (: !($1)->GetInvis() :));
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

string GetHelp(string useless) {
  string Help;
  Help = "Syntax:   \n";
  foreach(string rule in GetRules()) {
    Help += "     cast " + GetSpell() + 
            (sizeof(rule) ? " on " + rule : "") + "\n";
    }
  Help += "\n";
  Help += help::GetHelp(useless);
  Help += "\nRequirements: ";
  foreach(string skill in GetSkills()) {
  Help += skill + " (" + int_to_a(GetRequiredSkill(skill)) + ") ";
    }
  return (Help);
  }

string GetDetailedHelp(string useless) {
  string Help;
  Help = "Syntax:   \n";
  foreach(string rule in GetRules()) {
    Help += "     cast " + GetSpell() + 
            (sizeof(rule) ? " on " + rule : "") + "\n";
    }
  Help += "\n";
  if(DetailedHelp != "") {
   Help += DetailedHelp;
  } else Help += help::GetHelp(useless);
  Help += "\nRequirements: ";
  foreach(string skill in GetSkills()) {
  Help += skill + " (" + int_to_a(GetRequiredSkill(skill)) + ") ";
    }
  return (Help);
  }
  
string SetDetailedHelp(string str) { return (DetailedHelp = str); }

int hitCallBack(object who, object agent, int x, class MagicProtection mp) {
  if (!who) return x;
  if (who == mp->caster)
  foreach(string skill in (GetSkills()) ) {
  (mp->caster)->eventTrainSkill(skill, x, 0, 1);
  }
  send_messages(Messages[1][0], Messages[1][1], 
                who, agent, environment(who) );
  return x;
 }

void endCallBack(object who) {
  send_messages(Messages[2][0], Messages[2][1], 
                who, 0, environment(who) );
  return;
  }

int SetUniqueSpell(int flag) {
  return UniqueSpell = flag;
}

int GetUniqueSpell() {
  return UniqueSpell;
}
