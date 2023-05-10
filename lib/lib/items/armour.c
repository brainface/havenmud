/*    /lib/std/armour.c
 *    From the Dead Souls Object Library
 *    The standard armour object
 *    Created by Descartes of Borg 950408
 *    Version: @(#) armour.c 1.9@(#)
 *    Last modified: 97/01/01
 */
  
#include <lib.h>
#include <function.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <daemons.h>
#include "include/armour.h"
 
inherit LIB_BURY;
inherit LIB_DETECT;
inherit LIB_DETERIORATION;
inherit LIB_DROP;
inherit LIB_EQUIP;
inherit LIB_GET;
inherit LIB_GIVE;
inherit LIB_LOCK_WITH;
inherit LIB_MASS;
inherit LIB_MOVE;
inherit LIB_OBJECT;
inherit LIB_PERSIST;
inherit LIB_POISON;
inherit LIB_PUT;
inherit LIB_READ;
inherit LIB_SELL;
inherit LIB_STEAL;
inherit LIB_UNIQUENESS;
inherit LIB_VALUE;

private int            Fingers       = 5;
private int            Warmth        = 0;
private mapping        ProtectionBonus    = ([]);
private string array   RestrictLimbs = 0;
private int            Size          = SIZE_MEDIUM;
private static mixed   Wear          = 0;
private static mapping MaxProtection = ([]);
private int            Class         = 0;
private int            MaxClass      = 0;
private int            ArmourClass   = 0;
private int            MagicBonus    = 0;
private int            Deterioration = 0;

int direct_cast_str_on_obj() { return 1; }
int direct_resize_obj_to_str() { return 1; }

mixed direct_plant_obj_on_liv() { 
    if (environment() != this_player()) return "You don't have that.";
    return 1;
}


mixed direct_throw_obj_at_obj() {
  if (sizeof(GetWorn())) {
    return "You cannot throw something you are wearing!";
  }
  return 1;
}

mixed direct_throw_obj() {
  if (sizeof(GetWorn())) {
    return "You cannot throw something you are wearing!";
  }
  return 1;
}




mixed direct_repair_obj() {
  return CanRepair(this_player());
}

mixed direct_compare_obj_to_obj() {
    return 1;
}

mixed indirect_compare_obj_to_obj() {
    return 1;
}

int GetMaxProtection(int type);

private int RetainOnDeath = 0;

int SetRetainOnDeath(int x ) { return (RetainOnDeath = x); }

int GetRetainOnDeath() { return RetainOnDeath; }

int GetDeterioration() { return Deterioration; }

/*  ***************  /lib/armour.c data functions  ***************  */
varargs string GetEquippedDescription(object who) {
  if( GetWorn() ) {
	  string tmp = "It is worn on ";
	  if( !who ) {
	    who = this_player();
	    }
	  if( who == environment()) {
	      tmp += "your";
	    }	else {
	      tmp += possessive_noun(environment());
	    }
	  tmp += " " + item_list(GetWorn()) + ".";
	  return tmp;
  }
    return 0;
}

string GetEquippedShort() {
  string tmp = GetShort();
  if( GetWorn() ) {
	  tmp += " (worn on " + item_list(GetWorn()) + ")";
    }
  return tmp;
}

int GetFingers() {
    return Fingers;
}

int SetMagicBonus(int x) { return MagicBonus = x;  }

int GetMagicBonus() { return MagicBonus; }


int SetFingers(int x) {
    return (Fingers = x);
}

int SetWarmth(int x) { return Warmth = x; }

int GetWarmth() { return Warmth; }

varargs int SetClass(int x, int y) {
  MaxClass = x;
  if (y) Class = y;
    else Class = x;
}
int GetClass() { return Class; }
 
/*  Just check the surface for blade/knife/blunt damage
 *  Other damage types will be checked via more costly methods
 *  -blitz
 */
string GetItemCondition() {
    string ret, a_type;
    switch (10 - Deterioration) {
        case 0:     ret = "It is completely destroyed and offers no protection."; break;
        case 1:     ret = "It is utterly battered and offers only minimal protection."; break;    
        case 2..3:  ret = "It is terribly pounded and offers only slight protection."; break;   
        case 4..5:  ret = "It is severly damaged and offers about half its normal protection."; break;    
        case 6..7:  ret = "It is fairly damaged and offers moderately less protection than normal."; break;      
        case 8:     ret = "It is damaged and offers less protection than normal."; break;             
        case 9:     ret = "It is slightly damaged and offers slightly less protection than normal."; break;    
        default:    ret = "It is undamaged and offers full normal protection.";                      
    }
    switch (ArmourClass) {
      case ARMOUR_CLOTH:       a_type = "clothing";           break;
      case ARMOUR_LEATHER:     a_type = "leather armour";     break;
      case ARMOUR_REINFORCED:  a_type = "reinforced leather"; break;
      case ARMOUR_NATURAL:     a_type = "natural armour such as bone or wood"; break;
      case ARMOUR_CHAIN:       a_type = "chainmail";          break;
      case ARMOUR_PLATE:       a_type = "platemail";          break;
      case ARMOUR_HEAVY_PLATE: a_type = "heavy platemail";    break;
    }
    ret = "If worn, this appears to offer as much protection as " + a_type + ".\n" + ret;
   if (sizeof(GetRepairSkills())) {
     ret += "\nRepairing this item requires " + conjunction(GetRepairSkills(), "and") + ".";
   } else ret += "\nThis item cannot be repaired."; 
    return ret;
}
 

int GetProtection(int damage_type) {
  int x; float det;
  int *Damages = ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
  int modifier = 0;

  object env = environment();

  if (ArmourClass == ARMOUR_CLOTH) {
      modifier = 25;
      if (env) {
         if (env->GetSkillLevel("cloth armour"))
           modifier += (env->GetSkillLevel("cloth armour")/25 || 1);
          }
    }
  if (ArmourClass == ARMOUR_LEATHER) {
      modifier = 50;
      if (env) {
         if (env->GetSkillLevel("leather armour"))
           modifier += (env->GetSkillLevel("leather armour")/25 || 1);
          }
    }    
  if (ArmourClass == ARMOUR_REINFORCED) {
      modifier = 58;
      if (env) {
         if (env->GetSkillLevel("reinforced armour"))
           modifier += (env->GetSkillLevel("reinforced armour")/25 || 1);
          }
    }      
  if (ArmourClass == ARMOUR_NATURAL) {
      modifier = 65;
      if (env) {
         if (env->GetSkillLevel("natural armour"))
           modifier += (env->GetSkillLevel("natural armour")/25 || 1);
          }
    }      
  if (ArmourClass == ARMOUR_CHAIN) {
      modifier = 70;
      if (env) {
         if (env->GetSkillLevel("chain armour"))
           modifier += (env->GetSkillLevel("chain armour")/25 || 1);
          }
    }      
  if (ArmourClass == ARMOUR_PLATE) {
      modifier = 80;
      if (env) {
         if (env->GetSkillLevel("plate armour"))
           modifier += (env->GetSkillLevel("plate armour")/25 || 1);
          }
    }    
  if (ArmourClass == ARMOUR_HEAVY_PLATE) {
      modifier = 90;
      if (env) {
         if (env->GetSkillLevel("heavy plate armour"))
           modifier += (env->GetSkillLevel("heavy plate armour")/25 || 1);
          }
    }    
  if (GetProperty("blessed")) modifier += 20;

  if (modifier > 95) modifier = 95;
  modifier += GetProtectionBonus(damage_type);  
  
  det = Deterioration / 10.0;
  modifier -= to_int(modifier * det);
  if (modifier < 0) modifier = 0;
    
  if (environment()->GetTestChar()) 
    debug("AC: " + ArmourClass + " DT: " + damage_type + " Pro: " + modifier);
  return modifier;
}

 
int SetProtection(int type, int amount) {
  debug(base_name(this_object()) + " is using SetProtection()");
  return 0;
}

mapping SetProtectionBonus(int type, int amount) {
  ProtectionBonus[type] = amount;
  return ProtectionBonus;
}

int GetProtectionBonus(int type) {
  return ProtectionBonus[type] || 0;
}

int SetSize(int size) { return Size = size; }

int GetSize() { return Size; }

string array GetRestrictLimbs() {
    return RestrictLimbs;
}
 
string array SetRestrictLimbs(string array limbs) {
    return (RestrictLimbs = limbs);
}
 
static mixed array AddSave(mixed array vars) {
    return persist::AddSave(vars);
}

string array GetSave() {
    return persist::GetSave();
}

mixed GetWear() {
    return Wear;
}
 
mixed SetWear(mixed val) {
    return (Wear = val);
}
 

int SetArmourClass(int s) { return ArmourClass = s; }
int GetArmourClass() { return ArmourClass; }
 
/* ****************** armour.c modals ********************* */ 
mixed CanEquip(object who, string array limbs) {
    mixed tmp; string limb;
    int maxlimbs = 1;
    int armour = GetArmourType();
  
  if (armour == A_ARMOUR || armour == A_BODY_ARMOUR) maxlimbs = 5;
  if (armour == A_LONG_GLOVE || armour == A_LONG_SOCK || armour == A_LONG_BOOT) maxlimbs = 2;
  if (armour == A_CLOAK) maxlimbs = 3;
  if (armour == A_PANTS) maxlimbs = 2;
  if (armour == A_SHIRT) maxlimbs = 3;
  
    
  if (GetSize() != who->GetSize() && GetArmourType() != A_SHIELD) {
  	return "That is the wrong size for you to wear.";
   	}
  if (GetProperty("multiples")) maxlimbs += GetProperty("multiples");

  if( !limbs ) { 
	  string array guess = who->GetLimbs();

	  if( !guess ) { return "You have no limbs!"; }
    limbs = ({});
    foreach(limb in guess) {
      mapping data;
    
      data = who->GetLimb(limb);
      if( data["armours"] & armour ) {
		    limbs += ({ limb });
	    }
    }
    if (sizeof(limbs) > maxlimbs) return "Wear " + GetShort() + " on which limb?";
	  if (GetArmourType() == A_RING) {
	    foreach(limb in limbs) {
	      if (sizeof(filter(who->GetWorn(limb), (: $1->GetArmourType() == A_RING :))) >= who->GetFingers(limb)) {
	        limbs -= ({ limb });
	      }
	    }
	  }

	  if( equip::CanEquip(who, limbs) != 1 ) {
	    return "Wear " + GetDefiniteShort() + " on which limb?";
	  } else {
	  return 1;
	  }
  } 
 //  debug("ArCW: " + implode(limbs, ","));
	 
    if( sizeof(limbs) == 1 ) {
  //        debug("sizeof = 1");
          if (armour == A_LONG_GLOVE || armour ==  A_LONG_BOOT || armour == A_LONG_SOCK) {
  //          debug("armour is long");
            if (who->GetParentLimb(limbs[0]) == "torso" || !who->GetParentLimb(limbs[0]) ) {
	//	          debug("no parent/bad parent");
		          return "Long socks, gloves, and boots must be worn on two limbs.";
		        }
	//	        debug("adding extra limb");
		        limbs = ({ limbs[0], who->GetParentLimb(limbs[0]) });
          }
    }
    if (sizeof(limbs) > maxlimbs) return "Wear " + GetShort() + " on which limb(s)?";
    return equip::CanEquip(who, limbs);
}
 
mixed CanRepair(object who) {
    foreach(string sk in GetRepairSkills()) {
      if (!who->GetSkillLevel(sk)) return "But you don't know anything about " + sk + ".";
      }
    if (!Deterioration) return "But " + GetShort() + " isn't significantly damaged.";
    
    return 1;
}
 

int NeedsRepairs() {
    if (Deterioration) return 1;
    return 0;
}

mixed CanSteal(object who) {
    if( GetWorn() ) {
	return "You can't steal something equipped!";
    }
    return steal::CanSteal(who);
}
 
/* ********************* armour.c events *********************** */ 
static int Destruct() {
    if( GetWorn() && environment() ) {
	    eventUnequip(environment());
      }
    return object::Destruct();
}
 
void eventDeteriorate(int type) {
    SetDestroyOnSell(1);
    Deterioration++;
    if (Deterioration > 10) Deterioration = 10;
    if (Deterioration < 0)  Deterioration = 0;
    SetValue(GetValue() * (10 - Deterioration) / 10);
    if (living(environment())) {
    	environment()->eventPrint("%^RED%^" + capitalize(GetShort()) +  " is looking worse for wear.%^RESET%^");
    }
}
 
mixed eventEquip(object who, string array limbs) {
    mixed tmp;
	  string limb;
	  int armour = GetArmourType(); 
    if (!limbs || !sizeof(limbs)) {  
	  string array guess = who->GetLimbs();

	    if( !guess ) { return "You have no limbs!"; }
      limbs = ({});
      foreach(limb in guess) {
        mapping data;
    
        data = who->GetLimb(limb);
        if( data["armours"] & armour ) {
		      limbs += ({ limb });
	      }
      }
   }
  tmp = who->CanWear(this_object(), limbs);
  if (tmp != 1) return tmp;
  if( functionp(Wear) ) {
	  if( functionp(Wear) & FP_OWNER_DESTED ) {
	    return "Error in evaluating function pointer.";
	  }
	  if( !evaluate(Wear, who, limbs) ) {
	    return 1;
	  }
  }
  tmp = equip::eventEquip(who, limbs);
  if( tmp != 1 ) {
	  if( tmp ) {
	    who->eventPrint(tmp);
	   }	else {
 	    who->eventPrint("Error in wearing armour.");
	  }
	  return 1;
  }
  tmp = GetShort();
  SetWorn(limbs);
  if( functionp(Wear) ) {
	  return 1;
    } else if( stringp(Wear) ) { who->eventPrint(Wear); }
    else {
	  who->eventPrint("You wear " + tmp + ".");
  }
  environment(who)->eventPrint(who->GetName() + " wears " + tmp + ".", who);
  return 1;
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
 
int eventReceiveDamage(object agent, int type, int amount, int u, mixed array l) {
  float pro;
  pro = GetProtection(type);
  if (pro > 100) pro = 100;
  pro = pro/100 * amount;
  if (environment()->GetTestChar())
    debug("reducing damage by " + pro + " on a hit of " + amount + " with deterioration of " + Deterioration);
  deterioration::eventReceiveDamage(agent, type, amount/10, l);
  return pro;
}

varargs int eventRepair(object who, object room, int auto) {
    int success, smithy;
    int damage = Deterioration;
    smithy = 1;
    
    if (!who)  return 0;
    if (!room) return 0;
    
    foreach(string sk in GetRepairSkills()) {
      if (!room->GetProperty(sk)) smithy = 0;
    }
    if (!auto) {
      foreach(string sk in GetRepairSkills()) {
        success += who->eventCheckSkill(sk, damage * 10, smithy * 10);
      }
    }
    if (who->GetTestChar()) debug(success + ": D: " + damage + " sm? " + smithy);
    if (success < 0 && !auto) {
      send_messages( ({ "fail" }),
        "$agent_name $agent_verb to significantly repair " + GetShort() + ".",
        who, 0, room);
      return 1;
    }
    if (Deterioration > 0) { Deterioration--; }
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
    if( GetPoison() ) {
      if( random(100) < who->GetSkillLevel("stealth") ) {
         who->eventPrint("You notice a strange substance on it.");
	       }
      }
    who->eventPrint("It seems to be " + RACES_D->GetSizeString(GetSize()) + " size."); 
    who->eventPrint(GetItemCondition());
    return 1; 
    
}

varargs mixed eventUnequip(object who) {
    mixed tmp = equip::eventUnequip(who);
 
    if( tmp != 1 ) {
	return tmp;
    }
    send_messages("remove", "$agent_name $agent_verb $target_name.",
		  who, this_object(), environment(who));
    return 1;
}
 
/* ******************** armour.c driver applies ******************** */
static void create() {
    AddSave(equip::GetSave() + value::GetSave() + mass::GetSave() +
	    poison::GetSave() + deterioration::GetSave() + ({ "Deterioration" }));
    steal::create();
    object::create();
    SetVendorType(VT_ARMOUR);
}

void init() { }
