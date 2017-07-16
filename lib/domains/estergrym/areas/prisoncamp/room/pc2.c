#include <lib.h>
#include "../prisoncamp.h"
inherit LIB_ROOM;

static void create()
{
	room::create();
	SetShort("before the cell");
	SetLong("Guards stand before the cell and keep an eye on the "
		"prisoners who are not working this shift.  "
		"The prison camp gate is a ways south of here.  Work "
		"continues in most other directions.  ");
	SetClimate("underground");
	SetAmbientLight(30);
	SetExits(  ([
		"north" : P_ROOM + "cell",
		"east" : P_ROOM + "pc3",
		"south" : P_ROOM + "pc5",
		"west" : P_ROOM + "pc1",
		"southeast" : P_ROOM + "pc6",
		"southwest" : P_ROOM + "pc4",
		])  );
	SetInventory(  ([
		P_NPC "guard" : 2,
		])  );
	SetSmell(  ([
		"default" : "A foul stench pours from the cell.  ",
		])  );
	SetListen(  ([
		"default" : "The prisoners can be heard talking inside "
			"their cell.  ",
		])  );
	SetItems(  ([
		"cell" : "The guards block the view of the inside of the "
			  "cell.  ",
		"gate" : "The gate is in the south wall of the prison.  "
			"Details can not be made out from here.  ",
		({ "prison camp", "prison", "camp" }) :
			"Elves are breaking stones while under the "
			"supervision of nosferatu guards.  ",
		])  );
}
