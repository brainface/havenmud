#include <lib.h>
#include <domains.h>
inherit AVERATH_LIB;

varargs static void create(int x, int y) {
  ::create(0,0);
  SetShort("the Crossroads of Averath");
  SetTown("Averath");
  SetLong("The Duke's Road and River Road meet here to form a loose gathering of "
    "buildings which could be mistaken for a town square. Along the northeast side of "
    "the area is a small building with a sign displaying a mug of ale. "
    "To the southeast of the Crossroads is a wooden building which appears to be a shop. "
    "River Road continues east and west from here, while the Duke's Road continues to the "
    "north and south. The Averath River continues its slow journey from the northeast to the southwest, "
    "travelling through the crossroads at a cross angle.  A small wooden bridge spans it here."
  );
  SetItems( ([
    ({ "building", "small building", "tavern" }) : "This small building is a well kept tavern.",
    ({ "building", "wooden building", "shop", "post" }) : "This wooden building is a bustling trading post.",
    ({ "bridge" }) : "This wooden bridge spans the Averath River.",
    ({ "river" }) : "The Averath River starts to the northeast and heads southwest, its blue waters shine in "
                    "the light.",
     ({"sign"}) : "A small wooden sign displaying a mug of ale.",
    ]) );
  SetItemAdjectives( ([
      "tavern" : ({ "small" }),
      "post" : ({ "trading", "wooden" }),
      "bridge" : ({ "wooden", "small" }),
    ]) );
  SetEnters( ([
    "tavern" : AVERATH_CITY "tavern",
     "shop" : AVERATH_CITY "shop",
    ]) );
  SetListen( ([
      "default" : "The sounds of the city's commerce quietly hum in the air.",
      ]) );
  SetSmell( ([
      "default" : "The smell of city life tinges the air.",
    ]) );
  SetInventory( ([
     AVERATH_NPC "citizen" : random(4),
    AVERATH_OBJ "fountain" : 1,
   ]) );
}
