/*  Dress - Kobold Women - Level #1 Caverns  */

#include <lib.h>
#include <damage_types.h>
#include <armour_types.h> 
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("dirty dress");
  SetId( ({ "dirty dress", "dress" }) );
  SetAdjectives( ({ "dirty", "red" }) );
  SetShort("a dirty dress");
  SetLong(
    "The red dress has been dirtied by many stains and grime that has "
    "been on the dress for many years.  As such, the dress is "
    "irrepairable and little better than a rag."
  );
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_BODY_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(20);
  SetValue(0);
  SetDamagePoints(75);
  SetSize(SIZE_SMALL);
  SetMaterial("textile");
  SetRepairDifficulty(2);
  SetWarmth(10);
}
