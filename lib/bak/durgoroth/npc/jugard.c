// Title: Durgoroth Town
// File: jugard.c
// Author: Tim Morris aka Morgoth@Haven
// Date: June 1998
//
// Abstract: Jugard, owner of Jugard's exceptional weapons
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
  SetKeyName("jugard");
  SetShort("Jugard the blacksmith");
  SetRace("nosferatu");
  SetTown("Durgoroth");
  SetReligion("Saahagoth");
  SetGender("male");
  SetClass("fighter");
  SetSkill("melee combat",1,1);
  SetSkill("bargaining",8,0);
  SetLevel(25);
  SetVendorType(VT_WEAPON);
  SetLocalCurrency("crystals");
  SetLong("Jugard is a giant Nosferatu with huge bulging muscles"
          "and large callused hands, both courtesy of his profession. "
		  		"He is a very skilled craftsman, and is said to be a fair "
		  		"businessman as well.");
  SetStorageRoom(D_ROOM + "/sr_weapon");
  SetCurrency("crystals", 50 + random(200));
  SetMorality(-250);
  SetCombatAction(30, (: summonGuard, this_player() :));
  }



