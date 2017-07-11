/*    /lib/item.c
 *    from the Dead Souls LPC Library
 *    inheritable object for all tangible game objects
 *    created by Descartes of Borg 950207
 *    Version: @(#) item.c 1.30@(#)
 *    Last Modified: 97/01/01
 */
 
#include <lib.h>
#include <dirs.h>
#include <daemons.h>

inherit LIB_BURY;
inherit LIB_COMBINE;
inherit LIB_DETECT;
inherit LIB_DETERIORATION;
inherit LIB_DROP;
inherit LIB_GET;
inherit LIB_GIVE;
inherit LIB_LOCK_WITH;
inherit LIB_MASS;
inherit LIB_MOVE;
inherit LIB_OBJECT;
inherit LIB_PERSIST;
inherit LIB_PUT;
inherit LIB_READ;
inherit LIB_SELL;
inherit LIB_STEAL;
inherit LIB_UNIQUENESS;
inherit LIB_VALUE;
inherit LIB_WEAPON;

private int RetainOnDeath;
private int Limit;
private int MagicBonus = 0;
private int Deterioration;  /* Unused but added to stop spamming runtime/catch log */


/* ******************** item.c attributes ******************** */

int SetMagicBonus(int x) { return MagicBonus = x;  }

int GetMagicBonus() { return MagicBonus; }

int SetLimit(int x) { return Limit = x; }

int GetLimit() { return Limit; }

string GetExternalDesc() {
    string desc = object::GetExternalDesc();
    string tmp;
    
    if( desc == "" ) {
	return "";
    }
    if( tmp = GetEquippedDescription() ) {
        desc += tmp;
    }
    if( GetBroken() ) {
	desc += "It appears to be broken.";
    }
    else if( tmp = GetItemCondition() ) {
       if (!GetPreventGet())
         desc +=  tmp;
       }
  if (!GetPreventGet())
    desc += "\nIf wielded, this item would be used as a " + GetWeaponType() + " weapon.";
  if (sizeof(GetRepairSkills())) {
    desc += "\nRepairing this item requires " + conjunction(GetRepairSkills(), "and") + ".";
  } else desc += "\nThis item cannot be repaired.";
  return desc;
}

int GetClass() {
  int x = weapon::GetClass();
  if (x > 50) {
   if (environment()) environment()->eventPrint(capitalize(GetShort()) + " snaps into a million small pieces.");
   CHAT_D->eventSendChannel("HIGH CLASS?", "reports", identify(this_object()) + " nuked due to a class of " + x);
   eventDestruct();
   return 0;
  }
  return x;
} 

string GetItemCondition() {
    if( GetMaxClass() ) {
        float i = to_float(GetClass()) / GetMaxClass() * 100.0;
 
        if( i > 95.0 ) {
	    return "\nIt is as good as new.";
	}
        else if( i > 80.0 ) {
	    return "\nIt is in good condition.";
	}
        else if( i > 70.0 ) {
	    return "\nIt is in decent condition.";
	}
        else if( i > 50.0 ) {
	    return "\nIt is somewhat worn and battered.";
	}
        else if( i > 30.0 ) {
	    return "\nIt is worn down and dented.";
	}
        else if( i > 10.0 ) {
	    return "\nIt is very worn down and in bad shape.";
	}
        else {
	    return "\nIt has worn down completely.";
	}
    }
    else {
	return "\n";
    }
}

int GetRetainOnDeath() {
    return RetainOnDeath;
}
 
int SetRetainOnDeath(int x) {
    return (RetainOnDeath = x);
}
 
static mixed array AddSave(mixed array vars) {
    return persist::AddSave(vars);
}

string array GetSave() {
    return persist::GetSave();
}

int GetDeterioration() { 
  return GetMaxClass() - GetClass();
}

/* ************************ item.c modals *********************** */ 
mixed CanRepair(object who) {
    foreach(string sk in GetRepairSkills()) {
      if (!who->GetSkillLevel(sk)) return "But you don't know anything about " + sk + ".";
      }
    if( GetBroken() ) return 1;
    else if( !GetMaxClass() || GetClass() == GetMaxClass()) return "It doesn't need repairing.";
    return 1;
}

int NeedsRepairs() {
  if (GetMaxClass() && (GetClass() != GetMaxClass())) return 1;
    return 0;
}

mixed CanSteal(object who) {
    if( GetWorn() ) {
	return "You can't steal something equipped!";
    }
    return steal::CanSteal(who);
}
 
varargs mixed CanThrow(object who, object target) {
    return 1;
}

/* ********************* item.c events ************************ */ 
static int Destruct() {
    if( GetWorn() && environment() ) {
	eventUnequip(environment());
    }
    return object::Destruct();
}
 
int eventMove(mixed dest) {
    if( !environment() && GetWorn() ) {
	mixed array limbs = GetWorn();

	SetWorn(0);
	call_out((: eventRestoreEquip :), 0, limbs);
    }
    if( GetWorn() && environment() ) {
	eventUnequip(environment());
    }
    return move::eventMove(dest);
}
 
void eventDeteriorate(int type) {
    weapon::eventDeteriorate();
    SetDestroyOnSell(1);
    SetValue(GetValue()/2);
}

varargs int eventUse(object who, string what) {
  who->eventPrint(capitalize(GetShort()) + " does nothing at all.");
  return 1;
}

void eventRemoveBlessing() {
    SetProperty("blessed", 0);
    if( living(environment()) ) {
	environment()->eventPrint("%^YELLOW%^"
				  + capitalize((string)GetDefiniteShort()) +
				  " returns to its normal state.");
    }
}
    
int eventBless(int amount, int time) {
    if(!amount || !time) return 0;
    if(GetProperty("blessed")) return 0;
    SetProperty("blessed", amount);
    call_out( (: eventRemoveBlessing :), time);
    if(GetProperty("blessed") > 0) {
	 SetProperty("magic item", "blessed");
	}
    if(GetProperty("blessed") < 0) {
	 SetProperty("magic item", "cursed");
	}
    return 1;
}
 
varargs int eventRepair(object who, object room, int auto) {
    int success, smithy;
    int damage = GetMaxClass() - GetClass();
    smithy = 1;
    
    if (!who)  return 0;
    if (!room) return 0;
    
    foreach(string sk in GetRepairSkills()) {
      if (!room->GetProperty(sk)) smithy = 0;
    }
    foreach(string sk in GetRepairSkills()) {
      success += who->eventCheckSkill(sk, damage * 10, smithy * 10);
      }
    if (who->GetTestChar()) debug(success + ": D: " + damage + " sm? " + smithy);
    if (success < 0 && !auto) {
      send_messages( ({ "fail" }),
        "$agent_name $agent_verb to significantly repair " + GetShort() + ".",
        who, 0, room);
      return 1;
    }
    if (GetClass() < GetMaxClass()) { SetClass(GetClass() + 1); }
    send_messages( ({ "succeed" }),
        "$agent_name $agent_verb in slightly repairing " + GetShort() + ".",
        who, 0, room);
    return 1;  
}

mixed eventShow(object who, string component) {
    mixed tmp = object::eventShow(who, component);

    if( component || tmp != 1 ) {
	return tmp;
    }
    if( GetPoison() > 0 ) {
        if( random(100) < who->GetSkillLevel("stealth") ) {
            who->eventPrint("You notice a strange substance on it.");
	}
    }
    return 1;
}

/* ***************** item.c driver applies ****************** */
static void create() {
    AddSave(weapon::GetSave() + value::GetSave() + mass::GetSave() +
	    deterioration::GetSave());
    steal::create();
    object::create();
    Limit = 0;
}

mixed direct_sing_str_to_obj() {
	return 1;
}
 
mixed direct_cast_str_on_obj() {
    return 1;
}

mixed direct_cast_str_on_str_of_obj() {
    return 1;
}

mixed direct_balance_obj_to_obj() {
    return 1;
}

mixed indirect_balance_obj_to_obj() {
    return 1;
}

mixed direct_compare_obj_to_obj() {
    return 1;
}

mixed indirect_compare_obj_to_obj() {
    return 1;
}

mixed direct_turn_obj() {
    return 0;
}

mixed direct_repair_obj() {
  return CanRepair(this_player());
}

mixed direct_use_obj_to_str() {


    if( environment() != this_player() )
      return "#You need better access to it.";
    else return 1;
}

mixed direct_use_obj() {
    if( environment() != this_player() )
      return "#You need better access to it.";
    else return 1;
}
  

mixed direct_throw_obj_word_obj() {
    if( environment() != this_player() ) {
        return "#Throw something you are not holding?";
    }
    else return 1;
}

mixed indirect_throw_obj_into_obj() {
    return 1;
}

mixed direct_throw_obj() {
    return 1;
}


int direct_sacrifice_obj_to_str(string deus) {
    mixed tmp;
    object env;
 
    if( !sizeof(deus) ) return 0;
    deus = lower_case(remove_article(deus));
    if( !env = environment(this_player()) ) return 0;
    tmp = (mixed)env->CanSacrifice(this_player(), this_object(), deus);
    if( !tmp ) {
        this_player()->eventPrint("This is not the place for sacrifices.");
        return 0;
    }
    else return 1;
}


mixed direct_bless_obj() {
    if( environment() != this_player() ) {
	return "#You don't have that!";
    }
    return 1;
}
    
mixed direct_curse_obj() {
    if( environment() != this_player() ) {
	return "#You don't have that!";
    }
    return 1;
}

void init() { }

