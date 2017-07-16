/* Lucie's shirt
  Zara 8/15/98
*/
#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shirt");
  SetShort("white silk shirt");
  SetId( ({"shirt"}) );
  SetAdjectives( ({"ruffled","white","silk"}) );
  SetLong(
    "This ruffled white shirt is made of the finest silk. It is tailored to display "
    "a woman's charms to best advantage. Darts run along the mid-chest, gathering "
    "the fabric inward to cling tightly. The neckline of the shirt is shaped in a V,  "
    "plunging downwards towards the gathered waist. Ruffles run along the "
    "neckline and both sleeves, forming tiers near the end of both arms which "
    "would drap over the hands of the user."
  );
  SetMass(15);
  SetSize(SIZE_MEDIUM);
  SetValue(50);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  SetDamagePoints(50);
  // SetProtection(BLUNT, 2);
  // SetProtection(SLASH, 2);
  // SetProtection(HEAT, 4);
  // SetProtection(COLD, 4);
  // SetProtection(SHOCK, 3);
  // SetProtection(WATER, 1);
  // SetProtection(ACID, 1);
  SetMaterial("textile");
  SetRepairDifficulty(15);
  SetArmourType(A_SHIRT);
}
