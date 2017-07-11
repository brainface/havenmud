#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("axe");
  SetId( ({"axe"}) );
  SetAdjectives( ({ "ancient" }) );
  SetShort("an ancient axe");
  SetLong(
    "This long-edged lochaber axe once defeated many enemies "
    "in combat. The haft is all that remains of a long, now "
    "missing wooden shaft, and the edge is marred with many "
    "nicks and scrapes. However, it still seems sharp and free "
    "of rust, and may just do the job."
  );
  SetClass(15);
  SetDamagePoints(2400);
  SetValue(850);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetKeyName("battle axe");
  SetMass(350);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({ "steel" }) );
  SetHands(2);
}
