#include <lib.h>
#include "../durgoroth.h"


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetShort("inside the Hollow Inn");
  SetLong("Tables covered in blood and scraps of"
          " skin decorate the inside of the inn. The"
          " walls are unadorned except for some"
          " large holes in them. Upturned chairs"
          " and tables are seen throughout adding"
          " to the Inn's already pathetic appearance.");
  SetItems( ([
          ({ "tables", "blood", "skin", "chair", "tables" }) :
             "The Inn is in complete disarray. Only a few of"
             " the tables remain upright and those that do"
             " are covered in blood and scraps of skin.",
          ]) );
  SetSmell( ([ 
          "default" : "Fresh blood and rotting flesh add"
                      " a foul aroma to the air here.", 
          ]) );
  SetInventory( ([
          DURG_NPC "drinkseller" : 1,
          DURG_NPC "weakcitizen" : 1,
          DURG_NPC "healer" : 1,
          ]) );
  SetExits( ([
          "out" : DURG_ROOM "road03",
          ]) );
}
