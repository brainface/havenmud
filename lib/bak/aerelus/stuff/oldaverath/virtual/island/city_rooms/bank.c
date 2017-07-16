#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;


static void create() { 
  room::create();
  SetClimate("indoors");
  SetAmbientLight(30);
  SetShort("First Averath Bank");
  SetLong("Ornate woodwork frames the doorways and windows inside this "
     "grand bank. A lone desk and chair sit to one side, awaiting the "
     "business of citizens and travellers. Just to the left of the doorway "
     "stands a hat rack, and a leafy potted plant to the right. Towards "
     "the back of the bank, a heavy gate is suspended across a wide "
     "doorway.");
  SetItems( ([
       ({"desk", "chair"}) : "Due to the size of the desk and it's sturdy "
         "materials, it seems as though the ancient pair are immobile. ",
       ({"woodwork"}) : "The woodwork was obviously done by a skilled hand.",
       ({"hat rack", "rack"}) : "Long fingers arch up from the center of the "
          "hat rack, awaiting the garments of citizens.",
       ({"lock", "gate"})  : "The gate guards the vault from intruders. " 
          " It is made of steel and looks inpenetrable.  A large lock has been "
          "seamlessly welded into its frame.",
       ({"plant"}) : "This large potted plant adds a nice touch to the "
          "inside of the bank.",
     ]) );
  SetItemAdjectives( ([
       "chair" : ({"lone"}),
       "woodwork" : ({"ornate"}),
       "rack" : ({"sturdy"}),
       "gate" : ({"heavy"}),
       "plant" : ({"green","leafy","potted"}),
     ]) );
  SetExits( ([
       "out" : AVERATH_ISLAND + "1,0,0",
     ]) );
  SetSmell( ([
       "default" : "The air is a bit stuffy in here. "
     ]) );
  SetInventory( ([
        AVERATH_NPC + "teller"    : 1,
        AVERATH_NPC + "bankguard" : 1
     ]) );
}

