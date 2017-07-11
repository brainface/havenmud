#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("sword");
   SetShort("a small sword");
   SetId( ({ "sword" }) );
   SetAdjectives( ({ "small" }) );
   SetLong("This small sword is plain and unadorned, but is "
           "probably useful in a fight.  It is worth no "
           "money, but makes a good weapon for training and "
           "fo beginners.");
   SetMass(20);
   SetValue(0);
   SetClass(10);
   SetVendorType(VT_WEAPON);
   SetWeaponType("slash");
   SetDamageType(SLASH);
   SetDamagePoints(500);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(5);
   SetProperty("history","This is one of the free items given "
               "to young rangers in Parva.");
}
