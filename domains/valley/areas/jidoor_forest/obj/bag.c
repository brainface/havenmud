/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: bulky_pack.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 19th, 1998
// Abstract: A small bag of holding for Lauranna to have.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
//                   August 24th, 1998 - Fixed Morgoth Approval Suggestions
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <armour_class.h>
inherit LIB_STORAGE;
#include <armour_types.h>
#include <size.h>
#include <vendor_types.h>
static void create() 
  {
  ::create();
  SetKeyName("small bag");
  SetId( ({ "bag" }) );
  SetAdjectives( ({ "small", "holding" }) );
  SetShort("a small bag");
  SetLong("This small bag of holding is made to carry a vast amount of equipment. "
          "Fashioned from some type of durable and heavy cloth, it "
          "appears to be of high quality. It is quite small and is meant  "
          "can be worn on the torso attached to one's belt.");
  SetProperty("magic", "The small bag is enchanted to allow to fit more then "
              "it normally could. The inside of the bag is a seperate dimension"
              "which allows the physical size of the bag to not limit the amount "
              "it can hold.");
  SetMass(150);
  SetValue(300);
  SetVendorType(VT_CLOTHING);
  SetDamagePoints(1500);
  SetMaterial( ({ "textile" }) );
  SetWarmth(0);
  SetRepairSkills( ([ "textile" : 1,]) );
  SetRepairDifficulty(30);
  SetCanClose(1);
  SetClosed(1);
  SetMaxCarry(10000);
  }

