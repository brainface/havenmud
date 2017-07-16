#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("jawbone");
  SetId( ({ "jawbone", "axe" }) );
  SetAdjectives( ({ "huge", "sharpened" }) );
  SetShort("a huge sharpened jawbone");
  SetLong("This is a massive jawbone from some"
          " long dead demon which had to be of"
          " monsterous proportions. The tip of the"
          " bone has been filed down to a very sharp"
          " edge.");
  SetClass(35);
  SetProperty("magic", "This jawbone has residual magic"
              " from the demon it came from.");
  SetDamagePoints(2000);
  SetValue(10000);
  SetWeaponType("hack");
  SetDamageType(SLASH | MAGIC);
  SetMass(300);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_WEAPON);
  SetHands(2);
}
