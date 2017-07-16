#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
item::create();
  SetKeyName("hammer");
  SetId( ({ "hammer" }) );
  SetAdjectives( ({ "war" }) ); 
  SetShort("a war hammer");
  SetLong("This war hammer is made completely out of black iron. "
          "Etched into both sides of head, is the symbol of "
          "the Kylin faith, a balance with dragon entwined around "
          "it. The handle is wrapped in hard leather strips to "
          "prevent the users hand from slipping during combat.");
  SetMass(240);
  SetValue(1000);
  SetDamagePoints(2000);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetClass(35);
  SetMaterial( ({"metal"}) );
  SetRepairDifficulty(30);
  SetVendorType(VT_WEAPON);
}