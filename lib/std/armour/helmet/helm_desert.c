/*    /domains/Ylsrim/armour/helm.c
 *    from the Nightmare V Object Library
 *    created by Descartes of Borg 960302
 */
 
#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
 
inherit LIB_ARMOUR;
 
int WearHelm(object who);
 
static void create() {
    armour::create();
    SetKeyName("desert helm");
    SetId( ({ "helm","helmet" }) );
    SetAdjectives( ({ "sandy","brown","dusty","desert" }) );
    SetShort("a dusty helm");
    SetLong("This helm is the Desert helm, bestowed upon honoured "
            "knights of the desert.  It is made from a magic sand bound "
            "together to protect the heads of the righteous.");
    SetDamagePoints(3000);
    SetVendorType(VT_ARMOUR);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CHAIN);
    SetMass(200);
    SetValue(300);
    SetArmourType(A_HELMET);
    SetWear( (: WearHelm :) );
    SetProperty("magic","Magical sand was bound together for this "
                "helmet to protect the righteous.");
    SetMaterial( ({ "natural" }) );
    SetWarmth(3);
}
 
int WearHelm(object who) {
    if( (int)who->GetMorality() < 300 ) {
        who->eventPrint("The helm burns your head!");
        who->eventReceiveDamage(0, HEAT, random(10) + 10, 0, "head");
        return 0;
    }
    who->eventPrint("You wear the desert helm.");
    return 1;
}
