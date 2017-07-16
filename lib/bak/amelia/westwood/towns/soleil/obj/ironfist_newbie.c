// Amelia@Haven

#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;
inherit LIB_WEAPON;

static void create() {
   armour::create();
   SetKeyName("iron fist");
   SetShort("an iron fist");
   SetId( ({ "iron fist","iron","fist" }) );
   SetLong("This rather heavy looking glove is made completely of iron, "
           "more associated with the purpose of hitting very hard with "
           "one's fist than protecting the hand.");
   SetMass(50);
  SetMaterial("metal");
  SetWarmth(0);
   SetValue(0);
   SetDamagePoints(600);
   SetProtection(PIERCE,7);
   SetProtection(SLASH,7);
   SetProtection(BLUNT,7);
   SetWeaponType("melee");
   SetDamageType(BLUNT);
   SetClass(10);
   SetArmourType(A_WEAPON);
   SetVendorType(VT_ARMOUR | VT_WEAPON);
}

/*
mixed eventWear(object who, string limbs) {
   armour::eventWear(who,limbs);
   armour::eventWield(who,limbs);
}

mixed CanWear(object who, string *limbs) {
   string *tmp = who->GetLimbs();
   if(!limbs) {
      return "Do you want to wear this on your right hand or "
             "left hand?";
   }
   limbs = ({ });
 
   if(member_array("right hand", tmp) != -1) {
      limbs += ({ "right hand" });
   } else if(member_array("left hand", tmp) != -1) {
      limbs += ({ "left hand" });
   } else {
      return "This may only be worn on your right hand or left hand.";
   }
   return (mixed)who->CanWear(this_object(), limbs);
}
*/
