#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("glove");
  SetId(( {"glove", "skin", "animal skin" } ));
  SetShort("an animal skin glove");
  SetAdjectives( ({"natural"}) );
  SetLong(
    "This glove is completely made of a rather thick skinned animal. It offers the"
    "wearer a decent amount of damage while offering a large amount of warmth. The "
    "glove appears to be atleast five times thicker and tougher then any leather ever "
    "developed. It seems to allow the wearer's hand to move very well while wearing "
    "it, almost as if it was bare handed. It doesn't seem to be made of any kind of "
    "animal ever seen in the modern day. These gloves are very old and very rare. " );     
  SetMass(35);
  SetArmourClass(ARMOUR_NATURAL);
  SetSize(SIZE_MEDIUM);
  SetMaterial("natural");
  SetWarmth(4);
  SetRepairDifficulty(70);
  SetValue(10000);
  SetDamagePoints(1300);
  SetArmourType(A_GLOVE);  
  SetVendorType(VT_ARMOUR);
}
