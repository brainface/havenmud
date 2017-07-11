/*    Updated on 1/16/99
 *    by Haun for MUD_Upkeep purposes.
*/
#include <lib.h>
#include "path.h"
inherit LIB_ROOM;
static void create() {
    room::create();
    SetClimate("temperate");
    SetDomain("HavenWood");
    SetShort("a region fallen trees");
    SetLong("As far as the eye can see to the north and east a major "
      "logging operation is underway.  Fallen trees litter the area, "
      "as do the stumps from which they fell.  Wide logging paths are "
      "cut through the forest and gelfling lumberjacks lumber about "
      "as they prepare the logs to be taken to the cities of Kailie "
      "to be used for construction and fuel."               );
    SetItems( ([ ({"major logging operation","logging operation","operation"}) :
	(: GetLong :), 
	({"fallen trees","trees","logs"}) : 
	"They are large and wooden. " ,
	({"stumps"}) :
	"They are all that remains of once great trees. ",
	({"wide logging paths","logging paths","wide paths","paths"}) :
	"They lead about the logging operation.",
	({"forest"}) :
                            "The forest is being hacked to bits by the 
lumberjacks."
                                   ]) );
    SetListen( (["default" : "The sound of falling axes shatters the silence "
                             "of the forest."]));
    SetSmell(  (["default" : "A very pulpy wood smell attacks the senses."]));
    SetExits( ([ "north" : GLEN + "/rooms/path3"]));
    SetInventory (([ GLEN + "/npc/lumberjack" : (1)]));
    SetObviousExits("north");
}
