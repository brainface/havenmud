#include <lib.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leather vest");
  SetId( ({ "leather vest", "vest" }) );
  SetShort("a ragged leather vest");
  SetDamagePoints(600);
  // SetProtection(BLUNT, 5);
  // SetProtection(PIERCE, 1);
  // SetProtection(SLASH, 2);
  // SetProtection(COLD, 3);
  SetSize(SIZE_SMALL);
  SetArmourClass(ARMOUR_LEATHER);
  SetArmourType(A_VEST);
  SetVendorType(VT_ARMOUR);
  SetWarmth(15);
  SetRepairSkills( ([
     "leather working" : 1,
     ]) );
  SetMaterial( ({ "leather" }) );
  SetValue(50);
  SetMass(80);
 SetLong("This torn and ragged vest of leather is small and nearly "
         "useless, but could be worn by someone that didn't care.");
 }
