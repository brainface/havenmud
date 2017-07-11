/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: f_jidoor_bird.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 20th, 1998
// Abstract: This is an excellent fishing pole carried by the lazy 
//           fisherman in Jidoor Forest.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
//                   August 24th, 1998 - Fixed Morgoth Approval Suggestions
/* ----------------------------------------------------------------------- */

 
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
 
inherit LIB_POLE;
 
static void create() 
  {
  pole::create();
  SetKeyName("fishing rod");
  SetId( ({ "pole", "rod", "fishing rod"  }) );
  SetAdjectives( ({ "good", "sturdy", "expensive","mithril" }) );
  SetShort("a mithril fishing rod");
  SetLong("This appears to be a very good, sturdy and expensive "
          "fishing rod.  It has been fashioned from mithril and "
          "the only fragile piece of it is the fishing wire.");
  SetClass(9);
  SetValue(600);
  SetMass(130);
  SetDamagePoints(400);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON | VT_FISHING);
  SetRepairDifficulty(15);
  SetRepairSkills( (["mithril working" : 1, ]) );
  SetMaterial( ({ "mithril" }) );
  SetStrength(400);
  SetChance(50);
  }
