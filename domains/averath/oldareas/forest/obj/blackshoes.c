// amelia
#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("shoes");
   SetShort("a pair of black leather shoes");
   SetId( ({ "shoes" }) );
   SetAdjectives( ({ "pair of","leather","black"}) );
   SetLong("The shoes have a soft sole that helps prevent unnecessary "
           "noise, yet provide protection from sharp rocks.  The material "
           "they were made from is leather, polished to a black shine.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_BOOT);
   SetArmourClass(ARMOUR_LEATHER);
   SetMass(10);
   SetValue(90);
   SetSize(SIZE_MEDIUM);
   SetProperty("multiples",1);
   SetDamagePoints(300);
}
