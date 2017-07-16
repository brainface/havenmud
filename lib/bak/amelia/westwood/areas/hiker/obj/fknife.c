#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
inherit LIB_SMELL;

static void create() {
   item::create();
   SetKeyName("fish knife");
   SetShort("a fish knife");
   SetId( ({ "knife" }) );
   SetAdjectives( ({ "fish","fishing" }) );
   SetLong("This knife was specially designed for fisherman.  It "
           "is supposed to be used for cutting up fish and seperating "
           "out all the bad stuff that one doesn't want to eat so "
           "that all the good stuff that tastes good and is healthy "
           "is left.  It has a few stains from the fish on its "
           "wood handle, though.");
   SetSmell("The knife smells fishy, which is only to be expected, since "
            "it has dealt with fish a lot before.");
   SetProperty("history","The knife was used by a young fisherman for "
               "years, serving him well in its task of cutting the "
               "fish carefully and preparing them for cooking.");
   SetMass(75);
   SetValue(20);
   SetVendorType(VT_WEAPON);
   SetWeaponType("knife");
   SetDamageType(PIERCE|SLASH);
   SetDamagePoints(340);
   SetClass(9);
   SetMaterial( ({ "wood","metal" }) );
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "wood working" : 0,
                       "metal working" : 0,
                       "weapon smithing" : 0,
                  ]) );
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
