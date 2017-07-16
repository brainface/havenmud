/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: regal_mace.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 23rd, 1998
// Abstract: This is the mace used by P'alirith
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
//                   August 24th, 1998 - Fixed Morgoth Approval Suggestions
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create()
  {
  item::create();
  SetKeyName("regal mace");
  SetId( ({ "mace", "regal mace" }) );
  SetShort("a regal mace");
  SetLong("This is a finely made mace.  It appears almost regal.  It "
          "not only looks expensive, it looks like it would be a "
          "great blunt weapon.");
  SetAdjectives( ({ "regal" }) );
  SetValue(900);
  SetDamagePoints(2000);
  SetClass(18);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "wood" }) );
  SetRepairDifficulty(20);
  SetRepairSkills( ([
                     "wood working" : 20,
                     "weapon smithing" : 20,
                 ]) );

  }
