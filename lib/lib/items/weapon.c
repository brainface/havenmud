/*    /lib/comp/weapon.c
 *    From the Dead Souls V Object Library
 *    This object combines the ability to be wielded with damage doing
 *    Created by Descartes of Borg 960211
 *    Version: @(#) weapon.c 1.13@(#)
 *    Last modified: 97/01/01
 */

#include <lib.h>
#include <function.h>

inherit LIB_DAMAGE;
inherit LIB_EQUIP;
inherit LIB_POISON;

private int          Hands      = 1;
private string       WeaponType = "blunt";
private static mixed Wield      = 0;

// abstract methods
string GetDefiniteShort();
string GetKeyName();
string GetShort();
int eventDestruct();
mixed GetPreventDrop() {return 0; }
// end abstract methods

varargs string GetEquippedDescription(object who) {
    if( GetWorn() ) {
	string tmp = "\nIt is wielded in ";
	
	if( !who ) {
	    who = this_player();
	}
	if( who == environment() ) {
	    tmp += "your";
	}
	else {
	    tmp += possessive_noun(environment());
	}
	// mahk: replace wielded 'in head' with 'in mouth'
	tmp += " " + replace_string(item_list(GetWorn()),"head","mouth") + ".";
	return tmp;
  }
  return 0;
}


string GetEquippedShort() {
    object env = environment();
    string ret = GetShort();
    string array limbs;
    string limb;
 
    if( !env || !living(env) ) {
	return ret;
    }
    limbs = GetWorn();

    // mahk: replace wileded 'in head' with 'in mouth'
    limb = replace_string(item_list(limbs),"head","mouth");
    if( sizeof(limbs) > 0 ) {
	ret += " (wielded in " + limb + ")";
    }
    return ret;
}

int GetHands() {
    return Hands;
}

int SetHands(int x) {
    return (Hands = x);
}

string array GetSave() {
    return (damage::GetSave() + equip::GetSave() + poison::GetSave());
}

string GetWeaponType() {
    return WeaponType;
}
 
string SetWeaponType(string str) {
    if( !stringp(str) ) {
	error("Bad argument 1 to SetWeaponType().\n\tExpected: string, Got: " +
	      typeof(str) + "\n");
    }
    return (WeaponType = str);
}
 
mixed GetWield() {
    return Wield;
}
 
mixed SetWield(mixed val) {
    return (Wield = val);
}
 
mixed CanEquip(object who, string array limbs) {
    mixed tmp;

    if( !limbs || !sizeof(limbs) ) { /* let's try and guess */
      string array guess = who->GetWieldingLimbs();
	    if( !guess ) { return "You have no limbs!"; }
      limbs = guess;
      limbs = filter(limbs, (: !$(who)->GetWielded($1) :));
      if (sizeof(limbs) > GetHands()) { limbs = ({ limbs[0] }); }
//      debug("guess " + implode(limbs, ",") );
    }

    tmp = equip::CanEquip(who, limbs);

    if( tmp != 1 ) {
	return tmp;
    }
    if( GetHands() != sizeof(limbs) ) {
        return "#You must use "+ consolidate(Hands, "hand") + " to wield " +
	    GetDefiniteShort() + ".";
    }
    if( Hands > sizeof(who->GetWieldingLimbs()) ) {
	return "#You do not have enough limbs for that weapon!";
    }
    return 1;
}

int eventDeteriorate(int type) {
  int x = GetClass();
  object env = environment();
 
  if (!env) {
    eventDestruct();
    return -1;
  }
  if( x > 1 ) {
	   env->eventPrint("%^BOLD%^RED%^" + capitalize(GetDefiniteShort()) + " is wearing down.%^RESET%^");
	   SetClass(x -1);
	   return GetClass();
	}
	env->eventPrint("%^RED%^" + capitalize(GetDefiniteShort()) + " breaks.%^RESET%^");
  eventDestruct();
	return 1;
}

mixed eventEquip(object who, string array limbs) {
    mixed tmp;
    
    if( functionp(Wield) ) {
	if( functionp(Wield) & FP_OWNER_DESTED ) {
	    return "Function pointer owner destructed.";
	}
	if( !evaluate(Wield, who, limbs) ) {
	    return 1;
	}
	else {
	    return equip::eventEquip(who, limbs);
	}
    }
    tmp = equip::eventEquip(who, limbs);
    if( tmp != 1 ) {
	return tmp;
    }
    if( stringp(Wield) ) {
	who->eventPrint(Wield);
    }
    else {
	who->eventPrint("You wield " + GetShort() + ".");
    }
    environment(who)->eventPrint(who->GetName() + " wields " + GetShort() +
				 ".", who);
    return 1;
}
 
int eventStrike(object target) {
    int poison = GetPoison();
 
    if( poison > 0 ) {
	int x = random(poison) + 1;
	
        if( x > 0 ) {
	    send_messages("", "$agent_possessive_noun " + GetKeyName() +
			  " poisons $target_name.", environment(), target,
			  environment(environment()));
            target->AddPoison(x);
            AddPoison(-x);
        }
    }
    return damage::eventStrike(target);
}

mixed eventUnequip(object who) {
    mixed tmp = equip::eventUnequip(who);

    if( tmp != 1 ) {
	return tmp;
    }
    send_messages("unwield", "$agent_name $agent_verb $target_name.",
		  who, this_object(), environment(who));
    return 1;
}

// Some things to respond to provide friendly error messages
mixed direct_remove_obj() {
    if( environment() != this_player() ) {
	return "#You don't have that!";
    }
    return "#Do you mean to unwield it?";
}

mixed direct_wear_obj() {
    if( environment() != this_player() ) {
	return "#You don't have that!";
    }
    return "#Do you mean to wield it?";
}

mixed direct_unwield_obj() {
    if( environment() != this_player() ) {
	return "#You don't have that!";
    }
    return CanUnequip(this_player());
}
 
mixed direct_wield_obj() {
    int hands;
    string array limbs;
 
    if( environment() != this_player() ) {
	    return "#You don't have that!";
    }

    limbs = (this_player()->GetWieldingLimbs() || ({}));
    limbs = filter(limbs, (: !this_player()->GetWielded($1) :));
    if( !sizeof(limbs) ) {
	return "You have nowhere to wield it!";
    }
    if( sizeof(limbs) > hands ) {
	limbs = limbs[0..(hands-1)];
    }
    return CanEquip(this_player(), limbs);
}
 
mixed direct_wield_obj_word_str(object target, string wrd, string limb) {
    if( environment() != this_player() ) {
	return "#You don't have that!";
    }
    return CanEquip(this_player(), explode_list(limb));
}

int CanDisarm(object who, object target) {
  if (GetProperty("no disarm")) { return 0; }
  if (GetPreventDrop()) return 0;
  else return 1;
 }
