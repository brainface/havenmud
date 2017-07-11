#include <lib.h>
#include "../westwood.h"
inherit LIB_ROOM;

static void create() {
	::create();
	
	SetClimate("temperate");
	SetShort("a small clearing");
	SetNightLight(20);
	SetLong("Coals glow at the base of a small, smoky campfire.  "
		"Although some minor attempt was made at clearing brush "
		"and building a ring of stones around the fire, serious "
		"gaps in basic safety are easily recognizable.  Deciduous "
		"trees surround the mini-clearing, but all are sickly and  "
		"one can easily pass through them in any cardinal direction.  "
		"Trash is scattered around the campsite.");
	SetItems( ([
			({ "clearing","campsite","camp" }) : (: GetLong :),
			({ "small smoky campfire","fire","campfire","stones",
				"stone","ring","coal","coals","brush",
				"kindling","firewood","wood", }) :
				"The fire glows with a dim light, producing "
				"thick, acrid smoke.  A broken ring of stones "
				"surrounds the fire, with obvious gaps that "
				"are filled with bits of brush and kindling.  "
				"The firewood is young and green, barely "
				"fit for burning.",
			({ "campfire smoke","smoke" }) :
				"Dancing tendrils of smoke raise from the "
				"campfire, twisting and writhing in the light "
				"wind.",
			({ "deciduous trees","tree","trees","trunk","trunks" }) :
				"The leaves of the trees are brown at the tips, "
				"and a slimy mold grows arounds their trunks.  "
				"The trees are thin here, so one can easily "
				"leave the campsite to the north, south, "
				"east and west.",
			({ "slimy mold","mold","ground" }) :
				"Covering the trees and growing across the "
				"ground, the slimy mold is the obvious "
				"source for the sickness of the trees.",
			({ "disgusting trash","trash","ground","rags","rag" }) :
				"Moldy, spilled stew and filthy cloth rags "
				"are scattered around the campsite.",
		]) );
	SetSmell( ([
			"default" : "A mixture of smoke, mold, and filth "
				"pollute the air with odiferous scents.",
			"mold" : "The mold smells like decomposing humainoid waste.",
			"smoke" : "Acrid and full of soot, the smoke from the "
				"campfire would disgust virtually any living creature.",

		]) );
	SetListen( ([
			"default" : "The fire crackles and snaps as the young, green "
				"firewood burns.",
			"campfire" : "The fire crackles and snaps as the young, green "
				"firewood burns.",
		]) );
	SetExits( ([
			"north" : "2,3",
			"south" : "2,1",
			"east" : "3,2",
			"west" : "1,2",
		]) );
	SetInventory( ([
			W_NPC + "filthyorc" : 5,
			W_OBJ + "muezzinstewpot" : 1,
			]) );
}
