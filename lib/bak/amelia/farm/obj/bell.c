#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("cowbell");
   SetShort("a brass cowbell");
   SetId( ({ "brass cowbell","brass bell","bell","cowbell" }) );
   SetAdjectives( ({ "brass","cow" }) );
   SetLong("The bell looks sullen and tired.");
   SetMass(3);
   SetValue(100);
   SetVendorType(VT_TREASURE);
}