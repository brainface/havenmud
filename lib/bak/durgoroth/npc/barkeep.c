// Title : Durgoroth Town
// File: innkeeper.c
// Author: Tim Morris aka Morgoth@Haven
// Date: June 1998
//
// Abstract:	
//
// Revision History: 
//

#include <lib.h>
#include "../durgoroth.h"
#include "rescueme.h"
inherit LIB_BARKEEP;

static void create() {
	barkeep::create();
	SetKeyName("mortilus");
        SetId( ({"barkeep" }) );
       SetShort("Mortilus, the barkeep");
        SetLong("Mortilus is a tall man who spends most of his time "
                "standing behind the bar.  He looks tough enough "
               "to act as his own bouncer as well.  He looks like "
               "he'd be happy to pour a drink, or send someone on their "
                  "merry way the hardway it they were short on money.");
	SetRace("human");
  SetTown("Durgoroth");
	SetClass("fighter");
	SetSkill("bargaining",4,0);
	SetLevel(20);
  RemoveLanguage("Enlan");
  SetLanguage("Blaodric", 100, 1);
	SetGender("male");
	SetMorality(-40);
	SetProperty("durgorothNPC", 1);
	SetInventory( ([
		]) );
	SetCurrency("crystals", 45 + random(26));
	SetCombatAction( 30, (: summonGuard, this_player() :));
	SetMenuItems( ([
        "water" : "/std/meal/drink/water",
        "ale" : "/std/meal/alcohol/ale",
        "beer" : "/std/meal/alcohol/beer",
        "scotch" : "/std/meal/alcohol/scotch",
		]) );
	SetLocalCurrency("crystals");
	}
