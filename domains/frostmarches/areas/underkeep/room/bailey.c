//
//A bailey
//by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
  inherit LIB_ROOM;

static void create() {
  room::create();
SetShort("an ominous bailey");
  SetLong("This is the only way in to the center of the castle, the keep."
     " Murder-holes line the ceiling, where slings and arrows would have "
     "been cast down upon the invaders. The portcullis has dropped "
     "down, and would present a serious impediment to further progress, "
     "into the keep, were it not rusted through by the actions of time "
     "and water.");

SetClimate("underground");
SetAmbientLight(1);

SetExits( ([
   "north" : RNQ_RM + "forect.c",
   "south" : RNQ_RM + "keep.c",
   ]) );
SetItems( ([
   ({"murder holes","holes","hole"}) : "These vicious looking devices are"
     " all but useless now. They have been totally blocked up by silt.",
   ({"castle","center"}) : 
     "The castle consists of two parts: the outer, where the "
     "townsfolk live, which is mostly blocked up by rubble, and "
     "the keep, where the king, his courtiers, and his soldiers would live.",
   ("keep") : "This is the center of the castle.",
   ({"wall","walls"}) : "These walls, built to withstand a heavy siege, "
     "are pretty downright useless here, buried under all this rock.",
   ("ceiling") : "The ceiling has murder-holes in it.",
   ("silt") : "This is loose dirt, trickling slightly from the murder-holes.",
   ("portcullis") : "The portcullis is rusted right through. A hole through "
     "the center, made by someone (or something) previously, provides easy "
     "passage south.",
   "hole" : "The hole in the portcullis is just large enough to squeeze through.",
   ]) );
SetItemAdjectives( ([
   "walls" : ({"outer"}),
   "portcullis" : "rusted",
   ]) );

SetListen( ([
   "default" : "Movement can be heard to the south.",
   ]) );
SetSmell( ([
   "default" : "The smell of rust and dirt is omnipresent.",
   ]) );
SetInventory( ([
   RNQ_NPC + "skeleton2.c" : 3,
   ]) );
}
