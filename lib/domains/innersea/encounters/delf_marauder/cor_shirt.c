//  Lucie's shirt Zara 8/15/98
//  Stolen properly by Aless 2011
//  for dark-elf buxom corsair

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  
  SetKeyName("shirt");
  SetId( ({ "shirt" }) );
  SetAdjectives( ({ "ruffled", "white", "silk" }) );
  SetShort("white silk shirt");
  SetLong(
     "This ruffled white shirt is made of the finest silk. It is tailored to display "
     "a woman's charms to best advantage. Darts run along the mid-chest, gathering "
     "the fabric inward to cling tightly. The neckline of the shirt is shaped in a V,  "
     "plunging downwards towards the gathered waist. Ruffles run along the "
     "neckline and both sleeves, forming tiers near the end of both arms which "
     "would drape over the hands of the user."
     );
  SetMass(40);
  SetWarmth(3);
  SetValue(500);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_SHIRT);
  SetArmourClass(ARMOUR_CLOTH); 
  SetVendorType(VT_CLOTHING);
  SetMaterial( ({ "textile" }) );
  SetDamagePoints(3000);
  SetRepairDifficulty(25);
  
}
