#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("abaya");
  SetId(( { "abaya", "black abaya", "cotton abaya", 
    "black cotton abaya" } ));
  SetShort("a black cotton abaya");
  SetLong("This abaya is a commonly worn traditional"
  " garment worn by the women of Yozrath. It"
  " is a full length robe that is made of a"
  " soft, thin cotton material that has been"
  " dyed black. A beautiful desert rose has"
  " been embroidered near the hem of this"
  " garment. ");
  SetMass(60);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(15);
  SetWarmth(20);
  SetValue(100);
  SetDamagePoints(400);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_BODY_ARMOUR);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
}
