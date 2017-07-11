//
// The city guard's knife
// Made into a knife by Zaxan Zimtafarous@Haven
//

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../jidoor.h"

inherit LIB_ITEM;

int Wielding(object ob);

static void create() {
   item::create();
   SetKeyName("long-bladed knife");
   SetId( ({ "knife" }) );
   SetShort("a long-bladed knife");
   SetAdjectives( ({ "long", "bladed" }) );
   SetLong("This deadly knife has an extended blade and a weighted hilt.");
   SetProperty("history", "This is the standard issue knife for a Jidoor "
            "City Shadowguard.",);
   SetMass(18); 
   SetValue(0);
   SetMaterial( ({ "metal" }) );
   SetDamagePoints(5000);
   SetWeaponType("knife");
   SetDamageType(PIERCE);
   SetClass(15);
   SetVendorType(VT_WEAPON);
   SetDestroyOnSell(1);
   SetWield( (: Wielding :) );
}

int Wielding(object ob) {
   if(member_array("guard", this_player()->GetId()) == -1) { 
      message("my_action","You are not worthy of using "
              "this!",this_player());
      message("my_action","The knife suddenly disappears into "
              "thin air.",this_player());
      eventDestruct();
      return 0;
   } else return 1;
}
