/* A graceful katana */
#include <damage_types.h>
#include <vendor_types.h>
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("graceful katana");
  SetId( ({ "katana" }) );
  SetAdjectives( ({ "graceful" }) );
  SetShort("a graceful katana");
  SetClass(24);
  SetDamagePoints(4000);
  SetMass(180);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
     "metal working" : 6,
     "weapon smithing" : 6,
    ]) );
  SetRepairDifficulty(30);
  SetLong(
     "This long sword is a katana. It's blade is long, thin, and "
     "has a gentle curve the entire length of the blade. The hilt is "
     "attached to the bottom of this large piece of metal. Using a "
     "shaped, treated piece of wood that has been soaked in sake, the "
     "hilt is shaped around the end. The wood is carved with shapes "
     "of dragons and serpants. A jet black piece of silk garment wraps "
     "around the hilt for extra grip and ease of use. This is a "
     "graceful and beautiful weapon. "
  );
  SetProperty("history",
         "This weapon was forged in the smithies of Tai-Ri.");
  SetValue(1200);
}
