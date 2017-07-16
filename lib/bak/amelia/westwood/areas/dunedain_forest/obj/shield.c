/*    /domains/Ylsrim/armour/shield.c
 *    from the Nightmare V Object Library
 *    an example shield
 *    created by Lassondra@Nightmare
 */

#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;


static void create() {
    armour::create();
    SetKeyName("wooden shield");
    SetId( ({ "shield", "wooden shield" }) );
    SetShort("a wooden shield");
    SetLong("This shield is a simple circle of wood with no markings.");
    SetDamagePoints(600);
    SetVendorType(VT_ARMOUR);
    SetMass(400);
    SetWarmth(0);
    SetValue(75);
    SetArmourType(A_SHIELD);
    SetProtection(BLUNT, 5);
    SetProtection(SLASH, 3);
    SetProtection(PIERCE, 10);
    SetProtection(SHOCK, 10);
}
 


/* Approved by Balishae on Thu Sep 11 14:00:35 1997. */
