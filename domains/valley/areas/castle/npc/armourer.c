#include <lib.h>
#include <vendor_types.h>
inherit LIB_VENDOR;
#include "../castle.h"

static void create() {
   vendor::create();
   SetKeyName("armourer");
   SetShort("the tall armourer");
   SetId( ({ "armourer" }) );
   SetAdjectives( ({ "tall","bulky","strong" }) );
   SetLong("Tall, bulky, and strong, the armourer is not "
           "one to be taken lightly.  He has a grim look to "
           "him, scanning the surrounding area for suspicious "
           "people.");
   SetRace("dwarf");
   SetGender("male");
   SetClass("fighter");
   SetSkill("bargaining",5);
   SetLevel(25);
   SetMorality(150);
   SetVendorType(VT_ARMOUR);
   SetLocalCurrency("nuggets");
   SetStorageRoom(VC_NPC + "/sr_arm");
   SetMaxSingleItem(5);
   SetCurrency("nuggets", 10 + random(10));
   SetMorality(100);

}
