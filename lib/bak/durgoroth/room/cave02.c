// Title: Durgoroth Town
// File: cave02.c
// Author: Timothy Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: Interior of Durgoroth cave. Contains Saa'HaGoth cavalier
//                      leader
//
// Revision History: 
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

int CheckStatus( object who );
int PreExit( object who );

static void create() {
        room::create();
        SetShort("a small chamber");
        SetLong("This small chamber has been extensively worked, "
                "making it into a suitable Nosferatu habitat. Dim torches "
                "flicker in ornate wall brackets. To the north is a large "
                "ebony arch. While to the east is a smaller door, which "
                "appears to be made of gold.");
        SetObviousExits("north, east, southeast");
        SetClimate("indoors");
        SetDomain("FrostMarches");
    SetAmbientLight(20);
        SetItems( ([
                ({"small chamber","chamber","cave","habitat"}) : (: GetLong :),
                ({"dim torches","torches","ornate wall brackets","wall brackets",
                "brackets"}) : "Special torchers, dimmer then normal ones, "
                        "suitable for Nosferatu eyes, flicker in ornate golden "
                        "wall brackets of excellent craftsmanship.",
                ({"large ebony arch","large arch","ebony arch","arch"}) :
                        "The large arch of polished black stone supports the "
                        "cave ceiling through a passage that leads to the north. ",
                ({"small gold door","small door","gold door","door"}) :
                        "The small golden door is set in the eastern wall of the "
                        "chamber. It is finely worked with depictions of "
                        "Nosferatu worshippers of Saa'HaGoth kneeling at the "
                        "feet of the Mistress of the Dark Flame.",
                ]) );
        SetExits( ([
                "southeast" : D_ROOM + "/cave01",
                ]) );
        AddExit("north", D_ROOM + "/cave03", (: CheckStatus :));
        AddExit("east", D_ROOM + "/cave05", (: PreExit :));
        SetInventory( ([
                D_NPC + "/razarac" : 1,
          D_NPC + "/gostir" : 1,
                D_NPC + "/elite_guard" : 2,
                ]) );
        }

int PreExit( object who ) {
  who = this_player();
  if (( who->GetReligion() != "Saahagoth" ) && 
    (!creatorp(who))) {
  who->AddStaminaPoints(-50);
  message("nope", "A magical force seems to prevent "
    "you from opening the door.", who);
  message("nope", who->GetCapName()+" tries to go "
    "east, but is unable to.", environment(who), who);
  return 0;
  }
  else
    return 1;
  }

int CheckStatus( object who ) {
  who = this_player();
  if ((this_player()->GetProperty("morgul_attacker")) &&
    (present("elite guard") || present("razarac") ||
    present("gostir"))) {
  message("nope", "The guards block you from leaving that "
    "way", who);
  message("nope", "The guards block "+who->GetCapName()+
    " from leaving north.", environment(who), who);
  return 0;
  }
return 1;
}
