#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create()
{
  ::create(1,0,-1);
  SetLong("The dark stone walls of the sewer are wide and curved, glistening "
          "with a foul moisture, as if this were the belly of some great "
          "beast, not a run-down sewer. Running through the center of the "
          "room is a veritable river of foul, brackish sludge. The river of "
          "refuse twists towards the west, following a natural twist of the "
          "sewer tunnel.");
  SetItems(
  ([
    ({ "wall", "walls", "stone", "stones" }) : "The dark stone walls are "
       "covered with a thin layer of a greenish, moist slime.",
    ({ "slime", "moisture" }) : "This greenish moisture covering the walls "
       "is most like some sort of mildew caused by all the waste and "
       "dampness of the sewers.",
    ({ "river", "sludge", "refuse" }) : "A small river of waste runs "
       "through the middle of the room. Black and thick looking, you " 
       "really don't want to know what it's made of.",
  ]) );
  RemoveExit("east");
  RemoveExit("south");
}
