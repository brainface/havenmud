#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("key");
  SetProperty("history", "",);
  SetProperty("magic", "" );
  SetId( ({ "key", "jidoor_jail_key" }) );
  SetAdjectives( ({ "small","metal"}) );
  SetShort("a small mithril key");
  SetLong("The small mithril key is made to unlock some kind of door.");
  SetMass(1);
  SetValue(15);
  SetDamagePoints(20);
  SetMaterial("mithril");
  SetVendorType(VT_TREASURE);
  SetDisableChance(10);
}
