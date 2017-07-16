#include <lib.h>
#include <domains.h>
#include "../averath.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetProperties( ([
    "no magic" : 1,
    "no attack" : 1,
    ]) );
  SetAmbientLight(20);
  SetShort("the Averath Tavern");
  SetLong(
     "Quite dark and almost well kept, the Averath Tavern is much like "
     "any other. Dark wood tables are scattered about the room with ample "
     "chairs to fit more than enough people to keep it in business. The "
     "walls hold little decoration aside from the normal notice tacked "
     "occasionally. The bar itself is cluttered with half empty mugs and "
     "plates of unfinished food."
     );
  SetListen( ([
     "default" : "Loud laughter and talking drowns the city noises outside.",
     ]) );
  SetSmell( ([
     "default" : "The odor of sweat and cheap ale permeates the air.",
     ]) );
  SetItems( ([
     ({"table","tables"}) : "Hardly well made, these dark wood tables show "
       "their age. The color is dulled in spots from years of spills and "
       "some have cracks running across them.",
     ({"bar","mugs","plates"}) : "Scattered across the wooden bar are "
       "several half empty mugs of ale and various drinks, along with "
       "plates of half eaten meals, yet to be cleaned.",
     ({"chair","chairs"}) : "These wood chairs tip with the weight of the "
       "patrons who use them, but haven't collapsed yet. Cracks run across "
       "the seats and lumps of some hard substance or another seem almost "
       "glued onto several spots.",
     ({"walls"}) : "The walls have no windows, making the tavern dark "
       "and somewhat dingy looking. A rather large hole adorns one wall, "
       "looking as if a fist went through it in a rowdy brawl.",
     ({"notices","notice"}) : "Old papers posted, most likely advertising "
       "a special on 'ale' or perhaps notices from the church telling sinners "
       "to come convert. You can't really tell because they are faded and "
       "ripped.",
     ]) );
  SetItemAdjectives( ([
     "table" : ({"dark wood","wood"}),
     "chair" : ({"wood"}),
     ]) );
  SetExits( ([
     "out" : AVERATH_ROOM "road1",
     ]) );
  SetInventory( ([
    AVERATH_NPC "ale_vendor" : 1,
    AVERATH_NPC "bard" : 1,
    AVERATH_NPC "citizen" : 1,
    AVERATH_NPC "guard" : 1,
    ]) );
}
