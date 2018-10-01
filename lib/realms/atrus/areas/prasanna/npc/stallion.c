#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("stallion");
    SetId( ({"stallion" }) ); 
    SetShort("a white stallion");
    SetAdjectives( ({ "beautiful","white" }) );
    SetRace("horse");
    SetGender("male");
    SetClass("animal");
    SetLevel(15);
    SetLong("This beautiful white stallion is a masterpiece of "
            "breeding, and appears to be a regal, wondrous animal. "
            "His legs bulge with well ridden muscles, and his "
            "bearing is that of a noble steed. Perhaps he is ridden "
            "by a state official, or a galliant knight. His fine "
            "mane has been braided, and his coat freshly brushed. "
            "His hooves show signs of recent shoeing, and are very "
            "well maintained.");
}
