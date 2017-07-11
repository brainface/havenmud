/*    /domains/Ylsrim/armour/shield.c
 *    from the Nightmare V Object Library
 *    an example shield
 *    created by Lassondra@Nightmare
 */

#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;


static void create() {
    armour::create();
    SetKeyName("wooden shield");
    SetId( ({ "shield" }) );
    SetAdjectives( ({ "wooden", "small" }) );
    SetShort("a small wooden shield");
    SetLong("This shield is a simple circle of wood with no markings.");
    SetDamagePoints(600);
    SetVendorType(VT_ARMOUR);
    SetMass(400);
    SetValue(0);
    SetArmourType(A_SHIELD);
  SetArmourClass(ARMOUR_NATURAL);
    SetSize(SIZE_SMALL);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(20);
   SetRepairSkills( ([
                       "armour smithing" : 4,
                       "wood working" : 4,
                  ]) );
}
 
