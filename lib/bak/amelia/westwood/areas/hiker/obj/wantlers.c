#include <size.h>
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;
inherit LIB_WEAPON;

static void create() {
   armour::create();
   SetKeyName("white antlers");
   SetShort("a set of white antlers");
   SetId( ({ "set","antlers","antler" }) );
   SetAdjectives( ({ "set of","white","large","beautiful" }) );
   SetLong("The antlers are large and beautiful, unlike any across "
           "all Kailie.  They are also a pure, un-tarnished white.");
   SetMass(100);
   SetValue(400);
   SetVendorType(VT_ARMOUR|VT_TREASURE);
   SetArmourType(A_HELMET);
   SetDamagePoints(700);
   SetProtection(BLUNT,13);
   SetProtection(SLASH,13);
   SetProtection(PIERCE,9);
   SetProtection(MAGIC,10);
   SetMaterial( ({ "natural" }) );
   SetWarmth(4);
   SetWear("The antlers fit strangely.");
   SetProperty("history","The antlers were once on the head of the "
               "great white stag of the West Wood.");
   SetProperty("magic","In a time long past, these antlers were blessed "
               "as part of the body of the white stag of the West Wood.  "
               "How they were blessed, it is unknown.");
   // affect headbutt if that is implemented
   SetClass(14);
   SetSize(SIZE_SMALL);
   SetDamageType(BLUNT);
   SetWeaponType("blunt");
}
