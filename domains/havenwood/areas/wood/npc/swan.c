/* This is a swan coded by Lynna on January 20, 1998
*/
#include <lib.h>
#include "../beach.h"
inherit LIB_NPC;

static void create()
{
	npc::create();
	SetKeyName("swan");
	SetShort("a graceful, white swan");
	SetId( ({"swan"}) );
	SetAdjectives( ({"graceful", "white"}) );
	SetLong( "This graceful white swan glides across "
		"the water of the beaches as the time slowly drifts.");
	SetRace("bird");
	SetClass("animal");
	SetLevel(3);
	SetInventory( ([
		]) );
	SetCorpseItems( ([
		BEACH_OBJ + "feather" : 1,
		]) );
	SetGender("female");
	SetAction(5, ({
	"!emote glides across the water."}) );
}
