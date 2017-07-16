/*    /lib/armour.c
 *    from the Nightmare IV LPC Library
 *    the standard armour object
 *    created by Descartes of Borg 950408
 */
 
 
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "/lib/include/armour.h"
 
inherit LIB_ITEM;
 
private int Fingers;
private int startDamage;
private mapping Protection = ([ ]);
private mapping ProtectionBonus = ([ ]);
private string *RestrictLimbs;
private static mixed Wear;
private static mapping MaxProtection;
 
/*  ***************  /lib/armour.c  driver applies  ***************  */
 
static void create() {
    item::create();
  AddSave( ({ "Protection" }) );
    SetVendorType(VT_ARMOUR);
    Fingers = 0;
    MaxProtection = ([]);
}
 
mixed direct_remove_obj() {
    mixed tmp;
 
    if( environment() != this_player() ) return "#You don't have that!";
    if( !GetWorn() ) return "You are not wearing that!";
    tmp = (mixed)this_player()->CanRemoveItem(this_player(), this_object());
    if( tmp != 1 ) return 1;
    return 1;
}
 
mixed direct_wear_obj() {
    if( environment() != this_player() ) return "#You don't have that!";
    return CanWear(this_player(), GetRestrictLimbs());
}
 
mixed direct_wear_obj_on_str(object target, string str) {
    if( environment() != this_player() ) return "#You don't have that!";
    return CanWear(this_player(), ({ remove_article(lower_case(str)) }));
}
 
/*     ************** armour.c modal functions ****************      */
 
mixed CanWear(object who, string *limbs) {
    if( GetWorn() ) return "You are already wearing it.";
    if( !limbs ) { /* let's try and guess */
	string array tmp = (string array)who->GetLimbs();
        string limb;

	if( !tmp ) {
	    return "You have no limbs!";
	}
        limbs = ({});
        foreach(limb in tmp) {
            mapping mp;
 
            mp = (mapping)who->GetLimb(limb);
            if( mp["armours"] & GetArmourType() ) limbs += ({ limb });
        }
        if( (mixed)who->CanWear(this_object(), limbs) != 1 )
          return "Wear " + GetShort() + " on which limb?";
        else return 1;
    }
    else if( sizeof(limbs) == 1 ) {
        string which;
 
        switch(GetArmourType()) {
            case A_SHIELD:
            if( which = (string)who->GetParentLimb(limbs[0]) )
              limbs = ({ limbs[0], "torso", which });
            break;
 
            case A_LONG_GLOVE: case A_LONG_BOOT:
            if( which = (string)who->GetParentLimb(limbs[0]) )
              limbs = ({ limbs[0], which });
            else limbs = ({ limbs[0] });
            break;
 
            default: limbs = ({ limbs[0] });
        }
    }
    return (mixed)who->CanWear(this_object(), limbs);
}
 
mixed CanWield(object who, string *limbs) { return 0; }
 
mixed CanRepair(object who) { return 1; }
 
/*  ***************  /lib/armour.c event functions  ***************  */
 
void eventDeteriorate(int type) {
    int *types = keys(Protection);
    int i;
 
    i = sizeof(types);
    while(i--)
      if( (types[i] & type) && Protection[types[i]] ) {
	  if(GetProperty("blessed")) {
		Protection[types[i]] = Protection[types[i]] - 2;
	  }	
	  else Protection[types[i]]--;
	}
  message("system",
    capitalize(GetShort()) + " is looking worse for wear.",
     environment() );
  SetValue(0);
}
 
void eventEquipAgain(string *limbs) {
    object env;
    mixed ret;
 
    env = environment();
    ret = CanWear(env, limbs);
    if(ret == 1) ret = eventWear(env, limbs);
    if(stringp(ret)) message("my_action", ret, env);
}
 
int eventReceiveDamage(object agent, int type,
                       int strength, int internal, mixed limb) {
    int *types;
    int x = -1, i;
 
    i = sizeof(types = keys(Protection));
    while(i--) {
        if( (types[i] & type) ) {
            if( x == -1 ) x = Protection[types[i]];
            else if( Protection[types[i]] < x ) x = Protection[types[i]];
        }
    }
    x = x/2 + random(x/2);
    x = item::eventReceiveDamage(agent, type, x, internal, limb);
   return (x * 10);  /* This modified by Duuk to make armour worth having. */
}
 
varargs mixed eventUnequip(object who) {
    mixed tmp;
 
    if( !who ) who = this_player();
    tmp = (mixed)who->eventRemoveItem(this_object());
    if( tmp != 1 ) return tmp;
    SetWorn(0);
    who->eventPrint("You remove " + GetShort() + ".");
    environment(who)->eventPrint((string)who->GetName() +
                                " removes " + GetShort() + ".",
                                 who);
    return 1;
}
 
mixed eventWear(object who, string *limbs) {
    mixed tmp;
 
    if( !limbs ) { /* let's try and guess */
        string limb;
 
        limbs = ({});
        foreach(limb in (string *)who->GetLimbs()) {
            mapping mp;
 
            mp = (mapping)who->GetLimb(limb);
            if( mp["armours"] & GetArmourType() ) limbs += ({ limb });
        }
        if( (mixed)who->CanWear(this_object(), limbs) != 1 )
          return "Wear " + GetShort() + " on which limb?";
    }
    else if( sizeof(limbs) == 1 ) {
        string which;
 
        switch(GetArmourType()) {
            case A_SHIELD:
            if( which = (string)who->GetParentLimb(limbs[0]) )
              limbs = ({ limbs[0], "torso", which });
            break;
 
            case A_LONG_GLOVE: case A_LONG_BOOT:
            if( which = (string)who->GetParentLimb(limbs[0]) )
              limbs = ({ limbs[0], which });
            else limbs = ({ limbs[0] });
            break;
 
            default: limbs = ({ limbs[0] });
        }
    }
    if( functionp(Wear) && !evaluate(Wear, who) ) return 1;
    tmp = (mixed)who->eventWear(this_object(), limbs);
    if( tmp != 1 ) return "Error in wearing armour.";
    tmp = GetShort();
    SetWorn(limbs);
    if( functionp(Wear) ) return 1;
    else if( stringp(Wear) ) message("my_action", Wear, who);
    else message("my_action", "You wear " + tmp + ".", who);
    if(environment( this_player() ))
      message("other_action", (string)who->GetName() + " wears " +
            tmp + ".", environment(who), who);
    return 1;
}
 
varargs mixed eventRepair(object who, int strength, int type) {
    if( !who || !strength ) return 0;
    if( !type ) type = ALL_DAMAGE;
    foreach(int i in keys(Protection)) {
        if( !(i & type) || !MaxProtection[i]) continue;
        Protection[i] += strength;
        if( Protection[i] > MaxProtection[i] )
          Protection[i] = MaxProtection[i];
    }
    return 1;
}
 
/*  ***************  /lib/armour.c data functions  ***************  */

string GetWornDescription() {
  if( GetWorn() ) {
    string ret;
    ret = "It is worn on ";
    if(this_player() == environment()) ret += "your";
    else ret += possessive_noun(environment());
    ret += " " + conjunction(GetWorn()) + ".";
    return ret;
  }
  return 0;
}

/*  Just check the surface for blade/knife/blunt damage
 *  Other damage types will be checked via more costly methods
 *  -blitz
 */

string GetItemCondition() {
    int cuts, dents;
    string ret;
    cuts = dents = -1;
    foreach(int type, int val in Protection) {
        int x;
        if( BLADE & type || KNIFE & type ) {
             if(GetMaxProtection(type)) {
            x = to_float(val) / GetMaxProtection(type) * 100;
            if( cuts == -1 || x < cuts ) cuts = x;
              }
        }
        else if( BLUNT & type ) {
            if(GetMaxProtection(type)) {
            x = to_float(val) / GetMaxProtection(type) * 100;
            if( dents == -1 || x > dents ) dents = x;
              }
        }
    }
    if( cuts == -1 && dents == -1 ) return 0;
    if( cuts > -1 ) switch( cuts ) {
        case 1..4: ret = "slashed all to hell"; break;
        case 5..10: ret = "shredded to pieces"; break;
        case 11..20: ret = "shredded"; break;
        case 21..40: ret = "mildly shredded"; break;
        case 41..60: ret = "slashed up"; break;
        case 61..80: ret = "scratched"; break;
        case 81..90: ret = "somewhat nicked"; break;
        default: ret = "unbroken";
    }
    if( dents > -1 ) {
        if( ret ) ret += " and ";
        else ret = "";
        switch( dents ) {
            case 0..10: ret += "utterly battered"; break;
            case 11..20: ret += "terribly pounded"; break;
            case 21..40: ret += "serverly dented"; break;
            case 41..60: ret += "pretty dented"; break;
            case 61..80: ret += "dented"; break;
            case 81..90: ret += "slightly dented"; break;
            default: ret += "unmarred";
        }
    }
    return "Its surface is " + ret + ".";
}
 
int SetArmourType(int x) {
    int ret;
 
    ret = item::SetArmourType(x);
    if( ( x == A_GLOVE || x == A_LONG_GLOVE ) && !GetFingers() )
      SetFingers(5);
    return ret;
}
 
int SetProtection(int type, int amount) {
    MaxProtection[type] = amount;
    return (Protection[type] = MaxProtection[type] - startDamage);
}
 
int AddProtectionBonus(int type, int amount, int time) {
   if(!ProtectionBonus[type]) ProtectionBonus[type] = amount;
    else (ProtectionBonus[type] += amount);
   call_out( (: RemoveProtectionBonus, type, amount :), time);
  return ProtectionBonus[type];
  }

int RemoveProtectionBonus(int type, int amount) {
  message("system", "%^YELLOW%^" + capitalize(GetShort()) + 
          " returns to its normal state. %^RESET%^", environment());
   return (ProtectionBonus[type] -= amount);
  }

int GetProtectionBonus(int type) {
    return (ProtectionBonus[type]);
    }

int GetProtection(int type) {
    int *types;
    int bonus = 0;
    int i;
 
    i = sizeof(types = keys(ProtectionBonus));
    while (i--) if (types[i] & type) bonus += ProtectionBonus[types[i]];
    i = sizeof(types = keys(Protection));
    while(i--) if( types[i] & type ) {
     return (Protection[types[i]] + bonus +
             GetProperty("blessed") );
    }
    return 0;
}
 
int GetMaxProtection(int type) { return MaxProtection[type]; }
 
string *SetRestrictLimbs(string *limbs) { return (RestrictLimbs = limbs); }
 
string *GetRestrictLimbs() { return RestrictLimbs; }
 
int SetFingers(int x) { return (Fingers = x); }
 
int GetFingers() { return Fingers; }
 
mixed SetWear(mixed val) { return (Wear = val); }
 
mixed GetWear() { return Wear; }
 
string GetEquippedShort() {
    string ret;
 
    ret = GetShort();
   if( GetWorn() ) ret += " (worn on " + conjunction(GetWorn()) + ")";
    return ret;
}

int AddDamage(int howMuch)
{
	int *types = keys(Protection);
	int i;
	startDamage += howMuch;
	
	i = sizeof(types);
	while(i--)
	{
		Protection[types[i]] -= howMuch;
	}
	return howMuch;
}
