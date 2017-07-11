//Alex@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../area.h"
inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("ku-choka");
  SetShort("Ku-Choka the Harried Mother");
  SetId( ({"ku-choka", "mother", "woman"}) );
  SetAdjectives( ({ "harried" }) );
  SetRace("human");
  SetBaseLanguage("Barian");
  SetLimit(1);
  SetClass("fighter");
  SetLevel(20);
  SetLong(
    "Ku-Choka is a young mother and wife, and a dirty, stressed-out "
    "young woman. She constantly harps on her husband and the kids "
    "about her living conditions, whenever she's not gossiping with "
    "other jungle wives about whether it's really the size of the banana, "
    "or the motion of the monsoon that makes the difference.");
  SetGender("female");
  SetCurrency("chits", 100);
  SetInventory( ([
    AREA_OBJ "staindress" : "wear dress",
    AREA_OBJ "leafsandals" : "wear sandals",
  ]) );
  SetAction(10, ({
    "!yell Don't make me come in there!",
    "!yell I've had it up to here with you kids!",
    "!yell It looks like a boar-sty in here!",
    "!sigh tiredly",
    }) );
  SetMorality(-50);
}
