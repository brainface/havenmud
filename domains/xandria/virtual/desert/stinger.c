// mahkefel 2011
// scorpion stinger
// copied sanctum poison stuff
#include <lib.h>
#include <damage_types.h>                        
#include <vendor_types.h>                
inherit LIB_ITEM;                        
inherit LIB_POISON_WITH;                 

static void create() {
   ::create();
   SetKeyName("stinger");
   SetShort("a vicious stinger");
   SetId( ({ "stinger" }) );
   SetAdjectives( ({ "vicious"}) );
   SetLong(
     "This brown stinger looks like it was removed from the "
     "body of a rather large scorpion. Noxious black ichor "
     "still drips from the tip, and could probably be used "
     "to coat another weapon, if someone was so inclined."
   );
   SetMass(10);
   SetValue(200);
   SetVendorType(VT_TREASURE);
   SetMaterial( ({ "natural" }) );
   SetWeaponType("knife");
   SetDamageType(PIERCE);
   SetDamagePoints(200);
   SetPoison(15);
   SetPoisonStrength(20);
  SetPoisonUses(1);
}

