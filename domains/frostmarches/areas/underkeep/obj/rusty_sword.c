//
// a rusty sword
// created by Ranquest@Haven
//
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("sword");
    SetId( ({ "sword" }) );
    SetAdjectives( ({ "rusty" }) );
    SetShort("a rusty sword");
    SetLong("This sword, no doubt crafted by some long-dead master of the art,"
            " would probably have been of considerable value, were it not "
            "for the rust that has set in.");
   SetProperty("history","This sword was crafted by the famous Yuk Foo Tuk "
      "for His Majesty King Radchek's Royal Bodyguard. This was originally one of "
      "a set of twelve, and magically enhanced to be deadly against foes. "
      "However, the passage of time has eroded these charms to nothingness, "
      "and empty sockets in the hilt bear silent testimony to the looting of this "
      "place over the millenia.");
   SetDamagePoints(500);
   SetClass(12);
   SetMaterial("metal");
   SetRepairSkills( ([ "weapon smithing" : 1,
                       "metal working" : 1,
                      ]) );
   SetVendorType(VT_WEAPON);
   SetValue(250);
   SetRepairDifficulty(13);
   SetMass(100);
   SetWeaponType("slash");
   SetDamageType(SLASH);

   call_out( (:eventReceiveDamage, 0, SLASH, 500:),0 );
}
