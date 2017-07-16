// Title: Durgoroth Town
// File: hargard.c
// Author: Tim Morris aka Morgoth@Haven
// Date: June 1998
//
// Abstract: Hargard, owner of Durgoroth's Finest Armours
//
// Revision History: 
//

#include <lib.h>
#include <vendor_types.h>
#include "../durgoroth.h"
#include "rescueme.h"
inherit LIB_VENDOR;

static void create() {
	vendor::create();
	SetKeyName("hargard");
	SetShort("Hargard the master armourer");
	SetId( ({ "hargard the master armourer","hargard the master",
						"master hargard","master armourer","armorer" }) );
	SetRace("human");
  SetTown("Durgoroth");
	SetGender("male");
	SetClass("fighter");
	SetSkill("melee combat",1,1);
	SetSkill("bargaining",5,0);
	SetLevel(25);
	SetVendorType(VT_ARMOUR);
	SetLocalCurrency("crystals");
	SetLong("Hargard is a short and stocky man, his skin tanned "
					"and roughened by years in front of the forge. He looks "
					"quiet skilled at his trade, and doubtless knows more "
					"about armour than anyone for hundreds of miles around.");
	SetStorageRoom( D_ROOM + "/sr_armour");
	RemoveLanguage("Enlan");
	SetLanguage("Blaodric", 100, 1);
	SetCurrency("crystals", 50 + random(150));
	SetMorality(-100);
	SetCombatAction(30, (: summonGuard, this_player() :));
  }



