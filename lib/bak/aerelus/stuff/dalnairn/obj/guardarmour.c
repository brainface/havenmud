#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("duergar armour");
  SetId(( {"armour", "suit"} ));
  SetShort("a suit of Duergar armour");
  SetLong(
    "This suit of armour is made from the toughest steel available in "
    "Dalnairn, home of the Duergar. It covers most of the body, offering "
    "great protection against physical attacks. It is thinly lined with "
    "soft cotton, providing a little extra warmth for the wearer."
  );  
  SetAdjectives( ({"duergar", "suit of"}) );  
  
  SetMass(220);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_SMALL);
  SetMaterial("metal");
  SetWarmth(3);
  SetRepairDifficulty(50);    
  SetValue(2000);
  SetDamagePoints(4000);  
  SetArmourType(A_BODY_ARMOUR);
  SetRestrictLimbs( ({ "right arm", "left arm", "torso" }) );
  SetWear("The armour feels cold against the skin, but comfortable.");
}