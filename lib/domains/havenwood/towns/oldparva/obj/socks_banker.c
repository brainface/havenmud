#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("socks");
   SetShort("a pair of long socks");
   SetId( ({ "socks","sock" }) );
   SetAdjectives( ({ "pair of","long","brown" }) );
   SetLong("The brown socks would reach up to nearly the knee of "
           "a full grown male human.  The milk chocolate brown "
           "color hides dirt easily, disguising how dirty the "
           "socks truly are.  They look warm and comfortable.");
   SetMass(5);
   SetValue(15);
   SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);

   SetVendorType(VT_CLOTHING);
   SetArmourType(A_SOCK);
   SetProperty("multiples",1);
   SetDamagePoints(35);
   // SetProtection(BLUNT,1);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,2);
   // SetProtection(COLD,4);
   // SetProtection(HEAT,1);
   SetWear("The socks pull on easily.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(4);
   SetRepairDifficulty(3);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetProperty("history","It used to be the property of Magnum, Parva Banker.");
}
