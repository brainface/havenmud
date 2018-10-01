// Targoviste
// Laoise
// August 2004

#include <lib.h>
#include <domains.h>
#include "../targoviste.h"
inherit LIB_ROOM;

static void create() 
{
  room::create();
  SetDayLight(-20);
  SetDomain("Estergrym");
  SetTown("Targoviste");
  SetShort("before the gates of Targoviste");
  SetLong(
    "The Estergrym Mountians gather together here, dropping "
    "sharply to create steep cliffs on either side of the road. "
    "Set in to the flat rock face is the massive gateway of "
    "Targoviste. Battlements are carved in to the rock above "
    "either side of the gate, forming parapets that allow the gate "
    "to be defended. To the east lies the fortress of Targoviste, "
    "while to the west Targoviste Road leads back towards the "
    "North Road."  
  );
  SetItems( ([ 
    ({ "mountain", "mountains" }) : "The mountains which surround "
    "this area are jagged spires of black rock, reaching upwards "
    "and blocking out any view of the sky.",
    ({ "cliff", "cliffs", "rock", "face" }) : "Sheer cliffs rise "
    "to either side of the road, making it nearly impossible to "
    "approach the gates of Targoviste without being noticed.",
    ({ "gates", "gateway", "entrance" }) : "Formed of black "
    "granite, the slabs which comprise the entrance are smoothed "
    "to a faint sheen, preventing any attempt at scaling them "
    "when closed. Huge hinges bore deep in to the mountain rock "
    "on either side, holding the gates in place.",
    ({ "granite" }) : "The black granite of these gates has been "
    "hewn completely smooth, such that it has a faint sheen to it.",
    ({ "gate", "door", "slab" }) : "Both doors of the gates are formed "
    "of massive slabs of black granite.",
    ({ "battlements", "battlement", "parapet", "parapets" }) : "Carved "
    "in to the cliff walls on either side of the gates, these are "
    "intended to help defend Targoviste against attack.",
    ({ "Targoviste", "fortress", "east" }) : "The fortress of Targoviste "
    "lies through the gates to the east.",
    ({ "road", "west" }) : "Targoviste leads to the west from here, "
    "leading towards the North Road.",
  ]) );
  SetItemAdjectives( ([
    "mountain" : ({ "Estergrym", "large", "black", "jagged", "spire",
    "surrounding", "blocking" }),
    "cliff" : ({ "sheer", "sharp", "steep", "mountain", "rock" }),
    "gates" : ({ "black", "granite", "tall", "massive", "huge", }),
    "granite" : ({ "black" }),
    "gate" : ({ "both", "city", "Targoviste", "massive", "granite" }),
    "battlement" : ({ "defensive", "city" }),
    "fortress" : ({ "east", "eastern", "nearby" }),
    "road" : ({ "Targoviste", "west", "western" }),
  ]) );
  SetListen( ([ 
    "default" : "The wind whistles high in the mountains.",
  ]) );
  SetSmell( ([
    "default" : "A hint of moisture tinges the air.",
  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "west_out4",
  ]) );
}
