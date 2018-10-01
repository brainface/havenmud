#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("helmet");
  SetId(( {"helmet", "stone", "hollowed"} ));
  SetShort("a hollowed stone helmet");
  SetAdjectives( ({"helmet", "stone", "hollowed"}) );
  SetLong(
    "This stone helmet is hand made out of a small stone. It appears to "
    "have been hollowed out allow the wearers head to fit into it. Down each "
    "side of this stone are several vines that were hardened by clay to protect "
    "each side of the head down to the neck. The front of the helmet has several "
    "vines hanging just like the side to help defend the face. This piece of "
    "amrour offers very good protection to the wearer's head, however does "
    "lack comfort." );     
  SetMass(40);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_NATURAL);
  SetSize(SIZE_MEDIUM);
  SetMaterial("natural");
  SetWarmth(0);
  SetRepairDifficulty(50);
  SetValue(2500);
  SetDamagePoints(2000);
  SetArmourType(A_HELMET);  
}
