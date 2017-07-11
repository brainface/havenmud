#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("cutting knife");
   SetShort("a cutting knife");
   SetId( ({ "knife" }) );
   SetAdjectives( ({ "cutting","survival" }) );
   SetLong("This knife has only one side sharpened, and folds in if "
           "you press against the other side, making it possible to "
           "carry it without accidentally cutting yourself or your "
           "other goods.  It looks like it is meant for basic "
           "survival purposes, but that doesn't mean it isn't "
           "of good quality for other things too.");
   SetMass(20);
   SetValue(70);
   SetVendorType(VT_WEAPON);
   SetWeaponType("knife");
   SetDamageType(SLASH|PIERCE);
   SetDamagePoints(350);
   SetClass(9);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "metal working" : 1,
                       "weapon smithing" : 1,
                  ]) );
}
