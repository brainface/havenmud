/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: bulky_pack.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 19th, 1998
// Abstract: A large bulky backpack worn by the fisher.
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
  SetKeyName("heavy backpack");
  SetId( ({ "pack","backpack" }) );
  SetAdjectives( ({ "large","heavy","bulky","big","very big" }) );
  SetShort("a big and bulky backpack");
  SetLong("This backpack is made to carry a fair amount of equipment. "
          "Fashioned from some type of durable and heavy cloth, it "
          "appears to be of high quality. It is very big and bulky. It "
          "can be worn on one's torso, or slung over an arm.");
  SetMass(150);
  SetValue(300);
  SetVendorType(VT_CLOTHING);
  SetDamagePoints(1500);
  SetMaterial( ({ "textile" }) );
  SetWarmth(10);
  SetRepairSkills( ([ "textile" : 1,]) );
  SetRepairDifficulty(30);
  SetCanClose(1);
  SetClosed(1);
  SetMaxCarry(1000);
  }
