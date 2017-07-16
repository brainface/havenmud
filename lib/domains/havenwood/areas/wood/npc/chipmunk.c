/* This is a chipmunk for the woods coded by Lynna on February 15, 1998
*/

#include <lib.h>
#include "../beach.h"
inherit LIB_NPC;

static void create() {
	npc::create();
		SetKeyName( "chipmunk" );
		SetShort( "a tiny chipmunk" );
		SetInventory( ([
			BEACH_OBJ + "acorn" : 1,
			]) );
		SetId( ({ "chipmunk" }) );
		SetAdjectives( ({ "tiny" }) );
		SetLong( "This tiny chipmunk has a long black stripe down its "
			"back.");
		SetRace("rodent");
		SetClass("animal");
		SetGender("male");
		
		SetAction(5,({
			"!emote runs up a tree." }) );
		}
