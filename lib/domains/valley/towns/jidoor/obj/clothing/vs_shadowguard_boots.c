#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("boots");
  SetShort("a polished pair of very small black boots");
  SetId( ({ "boots" }) );
  SetAdjectives( ({ "polished", "very", "small", "black" }) );
  SetProperty("history", "These appear to be the standard issue boots for the "
           "Jidoor City Shadowguard.",);
  SetLong("They are a long pair of black boots made from some kind of dyed "
           "leather.");
  SetMass(8);
  SetProperty("multiples", 1);
  SetSize(SIZE_VERY_SMALL);
  SetArmourClass(ARMOUR_LEATHER);
  SetValue(10);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BOOT);
  SetDamagePoints(1500);
  SetRepairSkills( ([ "leather working" : 1,]) );
  SetMaterial( ({ "leather" }) );
  SetWarmth(5);
  SetRepairDifficulty(10);
  // SetProtection(SLASH, 5);
  // SetProtection(COLD, 5);
}
