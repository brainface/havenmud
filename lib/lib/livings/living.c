/*    /lib/living.c
 *    from the Dead Souls V Object Library
 *    handles common living code
 *    created by Descartes of Borg 951218
 *    Version: @(#) living.c 1.29@(#)
 *    Last Modified: 96/12/15
 */

#include <lib.h>
#include <daemons.h>
#include "include/living.h"
inherit LIB_CARRY;
inherit LIB_COMBAT;
inherit LIB_CURRENCY;
inherit LIB_CRAFTING;
inherit LIB_FOLLOW;
inherit LIB_MAGIC;
inherit LIB_LEAD;
/*
inherit LIB_SMELL;
*/

private int isPK;

static mixed *AddSave(mixed *vars) { return combat::AddSave(vars); }

varargs mixed CanReceiveHealing(object who, string limb);

static void create() {
    combat::create();
    currency::create();
    follow::create();
    lead::create();
    isPK = 0;
}

int is_living() { return 1; }

int inventory_accessible() { return 1; }

int inventory_visible() { return 1; }

mixed indirect_plant_obj_on_liv() { 
  if (newbiep() && userp()) return "You can't frame a newbie.  Sorry.";
  return 1;
}

mixed direct_verb_rule(string verb) {
    return SOUL_D->CanTarget(this_player(), verb, this_object());
}

mixed direct_debate_liv() {
  if (GetClass() == "animal") return "You can't debate an animal.";
  if (GetInCombat()) return "That person seems a bit busy right now.";
  return 1;
}

mixed direct_greet_liv() {
  return 1;
}

mixed direct_scream_at_liv() {
  return 1;
}

mixed direct_convert_liv() {
  if (GetProperty("converting")) return 1;
  return "That person does not wish to convert just yet.";
}

mixed direct_attack_liv() {
    return 1;
}

mixed direct_bite_liv() {
    return 1;
}

mixed direct_consider_liv() {
  return 1;
}

mixed direct_capture_liv_word_obj() {
    return 1;
}

mixed direct_disorient_liv() {
  if (!sizeof(GetSpellBook()) && !sizeof(GetSongBook())) {
    return "Disorienting that person would not be worthwhile.";
  }
  return 1;
}

mixed direct_disarm_liv() {
  if (userp(this_player()) && newbiep(this_object())) {
   return "Disarming innocent newbies, are you?";
   }
  if (sizeof(GetWielded())) return 1;
  return "But " + GetShort() + " is not wielding a weapon!";
 }

mixed direct_pray_for_str_against_str_for_liv() {
    return 1;
}

mixed direct_sing_str_to_obj() {
	return 1;
}

mixed direct_concentrate_str_on_obj() {
	return 1;
}

mixed direct_concentrate_str_on_str_of_obj() {
	return 1;
}

mixed direct_cast_str_on_obj() {
    return 1;
}

mixed direct_cast_str_against_str() {
    return 1;
}


mixed direct_cast_str_on_str_of_obj() {
    return 1;
}

mixed direct_free_liv_from_obj() {
    return 1;
}

mixed direct_get_obj() {
    return "You can't get a living thing!";
}

mixed direct_get_obj_from_obj() {
    return "You can't get a living thing!";
}

mixed direct_give_liv_obs() {
    return direct_give_liv_obj();
}

mixed direct_give_liv_obj() {
    if( this_player() == this_object() ) return "Are you confused?";
    return 1;
}

mixed indirect_give_obj_to_liv(object item) {
    if( !item ) return 0;
    if( this_player() == this_object() ) return "Are you confused?";
    if( environment(item) != this_player() ) return "You don't have that!";
    return CanCarry((int)item->GetMass());
}

mixed indirect_give_obs_to_liv(object *items) {
    return 1;
}

mixed direct_give_liv_wrd_wrd(object targ, string num, string curr) {
    return direct_give_wrd_wrd_to_liv(num, curr);
}

mixed direct_give_wrd_wrd_to_liv(string num, string curr) {
    mixed tmp;
    int amt;
    
    if( this_object() == this_player() )
      return "Are you feeling a bit confused?";
    if( (amt = to_int(num)) < 1 ) return "What sort of amount is that?";
    tmp = CanCarry(currency_mass(amt, curr));
    if( tmp != 1 ) return GetName() + " cannot carry that much "+ curr+ ".";
    return 1;
}

mixed direct_look_obj() { return 1; }

mixed direct_look_at_obj() {
  return 1;
}

/*
mixed direct_smell_obj(object ob, string id) {
    return smell::direct_smell_obj(ob, id);
}
*/

mixed direct_steal_wrd_from_liv(string wrd) {
    if( wrd != "money" ) return 0;
    if( this_player() == this_object() ) return "Are you fool?";
    if( this_player()->GetInCombat() )
      return "You are too busy fighting at the moment.";
    if (!sizeof(GetCurrencies())) return "That person has no money!";
    if (newbiep() || (newbiep(this_player()) && userp(this_object())))
      return "Newbie restrictions prevent this.";
    return 1;
}

mixed indirect_steal_obj_from_liv(object item, mixed args...) {
    mixed tmp;
    
    if( environment()->GetProperty("no attack") )
        return "Mystical forces prevent your malice.";
    if( !item ) return 1;
// Mahkefel 2014: okay. this check exists in the verb as well, and WORKS. this one... fails if the player has a similiarly named object in inventory.
// I do not know why! It shouldn't! it's pretty much the same check.
// so for right now I've commented this one out. I suspect occasional
// lightning-strike common chicanery where the object moves before this check happens?
    //if( environment(item) != this_object() ) return "That is not present on the target.";
    if( this_player() == this_object() ) return "Are you a fool?";
    if( this_player()->GetInCombat() )
      return "You are too busy fighting at the moment.";
    tmp = (mixed)item->CanDrop(this_object());
    if( tmp != 1 )
      return GetName() + " will not let go of " + (string)item->GetShort()+".";
    if (newbiep() || (newbiep(this_player()) && userp(this_object())))
      return "Newbie restrictions prevent this.";
    return 1;
}

mixed direct_backstab_liv() {
    if( this_object() == this_player() )
      return "That would be messy.";
    if( member_array(this_object(), this_player()->GetEnemies()) != -1 )
      return "%^RED%^You have lost the element of surprise.";
    if( environment()->GetProperty("no attack") ||
        GetProperty("no backstab") )
      return "A mysterious forces stays your hand.";
    if (newbiep() || (newbiep(this_player()) && userp(this_object())))
      return "Newbie restrictions prevent this.";
    return 1;
}

int direct_bump_liv() { return 1; }
int direct_evade_liv() { return 1; }
int direct_follow_liv() { return 1; }
int direct_lead_liv() { return 1; }
int direct_marry_liv_to_liv() { 
  if (GetProperty("marry")) return 1; 
  eventPrint("Someone is attempting to peform a marriage involving you. "
             "If this is something you wish to do, 'set marriage to yes'.");
  this_player()->eventPrint(GetCapName() + " does not wish to be married.");
  return 0;
}
int direct_party_wrd_liv() { return 1; }
int direct_challenge_liv() { return 1; }

int indirect_throw_obj_at_obj() { return 1; }
int indirect_buy_str_from_liv() { return 1; }
int indirect_sell_obj_to_liv() { return 1; }
int indirect_marry_liv_to_liv() { return 1; }

void heart_beat() {
	combat::heart_beat();
	magic::heart_beat();
}


/*     **********     /lib/living.c modal methods     **********     */
int CanCarry(int amount) { return carry::CanCarry(amount); }

varargs mixed CanReceiveHealing(object who, string limb) {
    int max, hp;

    max = GetMaxHealthPoints(limb);
    hp = GetHealthPoints(limb);
    if( (max-hp) < max/20 ) {
	if( limb ) {
	    return possessive_noun(GetName()) + " " + limb + " needs no help.";
	}
	else {
	    return GetName() + " needs no help.";
	}
    }
    return 1;
}

mixed CanReceiveMagic(int hostile, string spell) {
    if( GetProperty(spell) == "immune" ) {
        this_player()->eventPrint(GetName() + " is immune to such magic.");
        return 0;
    }
    if( !hostile ) return 1;
    if( this_player() == this_object() ) {
        eventPrint("That would be construed as quite foolish.");
        return 0;
    }
    return 1;
}

varargs mixed CanCastMagic(int hostile, string spell) {
    object env = environment();

    if (!env) return "You are nowhere!";
    if( spell && GetProperty("no " + spell) ) {
        eventPrint("A mysterious forces prevents you from doing that.");
        return 0;
    }
    if( env->GetProperty("no magic") ) {
        eventPrint("Mystical forces prevent your magic.");
        return 0;
    }
    if( !hostile ) return 1;
    if( env->GetProperty("no attack" ) ) {
        eventPrint("Mystical forces prevent your hostile intentions.");
        return 0;
    }
    return 1;
}

/*     **********     /lib/living.c event methods     **********     */
mixed eventCure(object who, int amount, string type) {
    object array germs = filter(all_inventory(),
				(: $1->IsGerm() && $1->GetType()== $(type) :));

    if( !sizeof(germs) ) {
	return GetName() + " suffers from no such affliction.";
    }
    return germs[0]->eventCure(who, amount, type);
}

int eventFollow(object dest, int followChance) {
    string dir;

    if( objectp(dest) ) {
	if( !environment() ) {
	   Destruct();
	    return 0;
	}
	dir = environment()->GetDirection(base_name(dest));
    }
    if( !stringp(dir) ) dir = "";
    if( dir != "" && followChance > random(100) ) eventForce(dir);
    if( environment() == dest ) return 1;
    return 0;
}

mixed eventInfect(object germ) {
    return germ->eventInfect(this_object());
}

varargs mixed eventShow(object who, string str, string on_id) {
    who->eventPrint(GetLong(str));
    if (!who->GetInvis())
    environment(who)->eventPrint((string)this_player()->GetName() +
				 " looks at " + GetShort() + ".",
				 ({ who, this_object() }));
    return 1;
}

varargs mixed eventSteal(object target, mixed what) {
	int skill; mixed tmp; int diff;
	int amt;
	
	diff = target->GetLevel() - GetLevel();
	if (diff <= 0) diff = 1;
	skill = GetSkillLevel("stealing") * GetLuck();
	skill += (int)(GetStatLevel("agility")/10);
		
	if (stringp(what)) { /* I am stealing money */
	  eventPrint("You reach for " + possessive_noun(target) + " money.");
	  tmp = target->eventRob(this_object(), "money", skill);
	  if (!tmp) {
	  	return "You cannot steal from that target.";
	  }
	  if (tmp == 1) { /* Success! */
	  	AddExperience(target->GetLevel() * 10);
	  	eventPrint("You succeed in stealing some money!");
	  	return 1;
	  }
	  if (tmp == 2) { /* Not so successful! */
	  	 AddExperience(target->GetLevel() * 2);
	  	 eventPrint("You fail to steal any money.");
	  	 return 1;
	  }
	  return tmp;
	} /* EndIf stringp(what) */
	/* Object Stealing Code Goes Here */
	tmp = target->eventRob(this_object(), what, skill);
	if (tmp == 1) {
	  	AddExperience(target->GetLevel() * 5);
	  return 1;
	}
	if (tmp == 2) {
	  	AddExperience(target->GetLevel() * 1);
    return 1;	
	}
  return tmp;
}

varargs mixed eventRob(object agent, mixed what, int skill) {
	int defense;
	
	defense = GetStatLevel("wisdom") + (random(20) * GetLuck());
	if (newbiep() && userp(this_object()) && userp(agent)) {
		  return "You cannot steal from a newbie!";
	  }
	if (stringp(what)) { /* Someone is stealing money from me */
	   if (skill > defense) {
		  foreach(string curr in GetCurrencies()) {
			  int x;
			  if (!GetCurrency(curr)) continue;
			  if (!(x = random(GetCurrency(curr)/5) + 1)) continue;
			  if (x > agent->GetSkillLevel("stealing")) x = agent->GetSkillLevel("stealing");
			  if (x < 1) x = 1;
			  AddCurrency(curr, -x);
			  agent->AddCurrency(curr, x);
			  agent->eventPrint("You manage to steal " + x + " " + curr + " from " + GetCapName() + ".");
			  }
			  return 1;
	  }
	  if (skill <= defense) {
		  agent->eventPrint("You are unsure if your victim noticed your attempts.");
		 if (random(GetStatLevel("wisdom")) > 40) {
			  eventPrint(agent->GetCapName() + " just tried to steal money from you!");
			  if (agent->GetSleeping()) {
			    agent->SetSleeping(0);
			    agent->eventPrint("You wake up.");
			  }
			  if (!userp(this_object())) SetAttack(agent);
			  this_object()->SetProperty("steal victim", 1);
	  	}
		  return 2;
	  }
	} /* EndIf Stringp */
	/* Object Robbery Code Goes Here */
       if (arrayp(what)) what = what[0];
       if (what) {
	defense += ((int)what->GetMass());
	if (skill > defense) {
		agent->eventPrint("You manage to lift " + what->GetShort() + " without being noticed.");
		what->eventMove(agent);
		return 1;
	}
	if (skill <= defense) {
	 agent->eventPrint("You are unsure if your victim noticed your attempts.");
	 if (random(GetStatLevel("wisdom")) > 40) {
	   eventPrint(agent->GetCapName() + " just tried to steal something from you!");
	   if (agent->GetSleeping()) {
			    agent->SetSleeping(0);
			    agent->eventPrint("You wake up.");
		 }
		 if (!userp(this_object())) SetAttack(agent);
		 this_object()->SetProperty("steal victim", 1);
	   }
	 return 2;
	}
    } return 0;
}

	  	
int AddCarriedMass(int x) { return carry::AddCarriedMass(x); }

int GetCarriedMass() {
    return (currency::GetCurrencyMass() + carry::GetCarriedMass());
}

int GetMaxCarry() { return combat::GetMaxCarry(); }

int SetPK(int x) { return (isPK = x); }

int GetPK() { return isPK; }

mixed indirect_look_at_obj_word_obj() {
    return 0;
}

int AddSkillPoints(string s, int i) { return -1; }

mixed indirect_show_obj_to_liv() {
  return 1;
}
