#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a cheerful and modest dwelling");
  SetExits( ([
    "out" : PARVA_ROOM "path4",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetLong(
    "This is the modest dwelling of Parva's local healer. The light from "
    "sweetly burning candles bathes the room in a peaceful, lambent glow. "
    "One wall is lined with rolls of snowy linen bandages and vials of "
    "medicine. Hanging from the oaken rafters are strands of various drying "
    "herbs and flowers, which give the home an altogether pleasant smell and "
    "appearance. A few tidily kept cots stand in one quiet corner of the "
    "room, awaiting occupants."
    );
  SetItems( ([
    ({ "light", "candles", "glow" }) : "The beeswax candles give off a faint lavender fragrance, conveying harmony and calmness throughout the home.",
    ({ "wall" }) : "The wall is lined with tools of the healing trade, kept very neatly organized.",
    ({ "bandgages", "rolls" }) : "The bandages are pristine and very soft.",
    ({ "vials", "medicine" }) : "The various vials of medicine and tonics look quite efficacious.",
    "rafters" : "Thick beams made from oak trees support the ceiling up above.",
    ({ "herbs", "flowers" }) : "The herbs and flowers not only give the home a pleasing scent and appearance, but also seem to be used in the healing arts.",
    ({ "cots", "corner" }) : "The cots seem comfortable enough to make anyone feel well again just from one night's rest here.",
    ]) );
  SetItemAdjectives( ([
    "light" : ({ "burning", "peaceful", "lambent" }),
    "bandages" : ({ "snowy", "linen" }),
    "rafters" : ({ "oaken" }),
    "herbs"  : ({ "strands", "various", "drying" }),
    "cots"  : ({ "tidily", "kept", "quiet" }), 
    ]) );
  SetSmell("The home smells of sweet herbs and warmth.");
  SetListen("It is tranquilly silent here.");
  SetInventory( ([
    PARVA_NPC "healer" : 1,
    ]) );
}
