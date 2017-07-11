/*  The compare verb */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_types.h>
inherit LIB_VERB;

mixed can_compare_obj_to_obj();
mixed do_compare_obj_to_obj(object one, object two);
void DisplayDamageCompare(object, object, object, int, string);

static void create() {
  verb::create();
  SetVerb("compare");
  SetErrorMessage("Compare what to what?");
  SetRules("OBJ to OBJ");
  SetHelp("Syntax:        \"compare OBJ to OBJ\"   \n\n"
          "Allows a skilled warrior or merchant to compare weapons. \n"
          "Allows someone trained in armour use to compare armours. \n"
          "The \"merchant\" class may use this command at no cost and without required skills."
          );
  }

mixed can_compare_obj_to_obj() {
  if (this_player()->GetParalyzed()) return "You cannot move.";
  if (this_player()->GetSleeping())  return "In your dreams all things are equal.";
  if (this_player()->GetInCombat())  return "You're far too busy to worry about nuances right now.";
  if (!this_player()->ClassMember("merchant")) 
    if (this_player()->GetStaminaPoints() < 100) return "You're too tired to worry about which is better.";
  return 1;
}


mixed do_compare_obj_to_obj(object one, object two) {
  int VT_ONE, VT_TWO;
  int DP_ONE, DP_TWO;
  int CL_ONE, CL_TWO;
  object who = this_player();
  if (!who->ClassMember("merchant")) who->AddStaminaPoints(-100);
  if ((VT_ONE = one->GetArmourType()) != (VT_TWO = two->GetArmourType())) {
    who->eventPrint(capitalize(one->GetShort()) + " is a " + armour_type_string(VT_ONE) + " and " +
                    two->GetShort() + " is a " + armour_type_string(VT_TWO) + "!");
    return 1;
  }
  DP_ONE = one->GetDamagePoints(); DP_TWO = two->GetDamagePoints();
  if (DP_ONE > DP_TWO) {
    who->eventPrint(capitalize(one->GetShort()) + " is more durable.");
  } else {
    who->eventPrint(capitalize(two->GetShort()) + " is more durable.");
  }
  if (one->GetValue() > two->GetValue()) {
    who->eventPrint(capitalize(one->GetShort()) + " could be sold for more money.");
  } else {                                          
    who->eventPrint(capitalize(two->GetShort()) + " could be sold for more money.");
  }
  if (VT_ONE == A_WEAPON) {
    CL_ONE = one->GetClass();
    CL_TWO = two->GetClass();
    foreach(string skill in ({ one->GetWeaponType(), two->GetWeaponType() })) {
      if (who->GetSkillLevel(skill + " combat") < 1 && who->ClassMember("merchant") == 0) {
        who->eventPrint("You don't know enough about " + skill + " weapons to decide which is better.");
        return 1;
      }
    }
    if (CL_ONE > CL_TWO) {
      who->eventPrint(capitalize(one->GetShort()) + " is a better weapon.");
    } else {
      who->eventPrint(capitalize(two->GetShort()) + " is a better weapon.");
    }
  }
  if (VT_ONE != A_WEAPON) {
    DisplayDamageCompare(who, one, two, BLUNT  , "blunt"   );
    DisplayDamageCompare(who, one, two, SLASH  , "slash"   );
    DisplayDamageCompare(who, one, two, PIERCE , "pierce"  );
    DisplayDamageCompare(who, one, two, WATER  , "water"   );
    DisplayDamageCompare(who, one, two, SHOCK  , "shock"   );
    DisplayDamageCompare(who, one, two, COLD   , "cold"    );
    DisplayDamageCompare(who, one, two, HEAT   , "heat"    );
    DisplayDamageCompare(who, one, two, GAS    , "gas"     );
    DisplayDamageCompare(who, one, two, ACID   , "acid"    );
    DisplayDamageCompare(who, one, two, MAGIC  , "magic"   );
    DisplayDamageCompare(who, one, two, HUNGER , "hunger"  );
    DisplayDamageCompare(who, one, two, DISEASE, "disease" );
    DisplayDamageCompare(who, one, two, POISON , "poison"  );
    DisplayDamageCompare(who, one, two, VACUUM , "void"    );   
    return 1;
  }
}

void DisplayDamageCompare(object who, object one, object two, int dam_type, string str_type) {
  int PRO_ONE, PRO_TWO;
  string tmp;
  
  PRO_ONE = one->GetProtection(dam_type); PRO_TWO = two->GetProtection(dam_type);
  
  if (PRO_ONE > PRO_TWO) tmp = capitalize(one->GetShort()) + " protects better against " + str_type + " damage.";
  if (PRO_ONE < PRO_TWO) tmp = capitalize(two->GetShort()) + " protects better against " + str_type + " damage.";
  if (PRO_ONE == PRO_TWO) tmp = "Both of these armours protect equally well against " + str_type + " damage.";
  who->eventPrint(tmp);
}