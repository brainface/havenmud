#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("cappa");
  SetId(( { "cappa" } ));
  SetShort("an ornate golden cappa");
  SetAdjectives( ({ "ornate", "golden" }) );
  SetLong("This cappa is a long cloak-like item worn"
          " by priests and other holy people. It is open"
          " at the front and drapes over the shoulders and"
          " down the back. It appears to be made of a"
          " fine cloth sewn together with golden thread."
          " It is clasped at the breast with a small"
          " golden fastener.");
  SetMass(60);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(15);
  SetWarmth(10);
  SetValue(500);
  SetDamagePoints(400);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_CLOAK);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
}
