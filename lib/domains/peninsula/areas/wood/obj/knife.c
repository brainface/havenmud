/* 5/03 Libitina / skinning knife - hunter / newbie area / wooded vale */
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
    ::create();
    SetShort("a skinning knife");
    SetId( ({"knife"}) );
    SetAdjectives( ({ "skinning" }) );
    SetAdjectives( ({ "skinning" }) );
    SetKeyName("skinning knife");
    SetValue(6);
    SetMass(5);
    SetClass(8);
    SetDamagePoints(1200);
    SetWeaponType("knife");
    SetDamageType(SLASH);
    SetLong("This is a simple knife used for skinning "
      "animals. It has a long, thin blade and wooden handle."
    );
    SetVendorType(VT_WEAPON);
    SetMaterial("metal");
    SetRepairDifficulty(5);
}	        
