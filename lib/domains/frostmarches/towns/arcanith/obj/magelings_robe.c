/* Mageling's robe
 * Filename: magelings_robe.c
 * Idea: A magical robe for mages
 * Coded by: Sardoans@haven (a.k.a. Robert Kehrer)
 * Coded: 11/11/98
 */

#include <lib.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

int WearMe();

static void create() {
  armour::create();
  SetKeyName("blue robe");
  SetId( ({ "robe" }) );
  SetAdjectives( ({ "blue", "glistening", "mageling's" }) );
  SetShort("a glistening blue robe");
  SetLong("This is a soft blue robe made of a glistening material.  The "
          "cuffs, hem, and collar of the robe are all lined with silver "
          "fabric.  Upon closer inspection of the robe, it is revieled "
          "that the cloth glistens because there are small silver threads "
          "sewn through out the cloth, which forms small runes.");
  SetProperty( "history", "This robe is one of the first creations made "
                          "by an aspiring arch-mage.  It is usually made "
                          "by mages learning to imbue items with magical "
                          "energy.  This particular robe was created by "
                          "the mageling Venturas, to protect himself from "
                          "the mageling Tival.");
  SetProperty( "magic", "This robe glows when worn by any type of wizard.  "
                        "This robe gives defense to against many physical "
                        "attacks and electrical damage.");

  SetMass(60);
  SetValue(800);
  SetVendorType(VT_ARMOUR | VT_TREASURE | VT_MAGIC);
  SetSize(SIZE_SMALL);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(350);
  // SetProtection(BLUNT, 6);
  // SetProtection(PIERCE, 6);
  // SetProtection(SLASH, 6);
  // SetProtection(SHOCK, 6);
  SetArmourType(A_BODY_ARMOUR);
  SetMaterial( ({ "textile" }) );
  SetWarmth(20);
  SetWear((: WearMe :));
}

int WearMe() {

  if(this_player()->GetClass()!="evoker"&&
     this_player()->GetClass()!="enchanter"&&
     this_player()->GetClass()!="diviner"&&
     this_player()->GetClass()!="necromancer") {
    message("system", "You wear a glistening blue robe. ", this_player());
    return 1;
    } 
  else {
    message("system", "A shiver races up and down your spine as you wear "
                      "the shimmering blue robe.  It begins to "
                      "%^BOLD%^BLUE%^glow%^RESET%^ as it settles on your "
                      "body.", this_player());
    return 1;
    }
}
