// Coded by Zeratul
// 3-14-2000

#include <lib.h>
#include <domains.h>
#include <vendor_types.h>
#include "../../vacazar.h"
inherit LIB_CHAPEL;

int Skadar(string);

static void create() {
  chapel::create();
  SetClimate("underground");
  SetProperty("no bump",1);
  SetReligion("Skadar");
  SetTown("Vacazar");
  SetClasses( ({ "cleric" }) );
  SetAllowSacrifice(1);
  SetSacrificeType(VT_ALL);
  SetDeities( ({ "Zeratul" }) );
  SetShort("The church of Skadar");
  SetLong(
     "The huge church stands tall over the city. From the inside, "
     "the church stands about three to four stories in height, holding "
     "within it the Skadar faith. A huge statue stands here, telling "
     "the story of the Skadar's beginnings. Several benches are lined up "
     "around the room, which focus around the statue. A pedestal stands in "
     "the middle of the room, with decorative urns around it. "
     "To the south the room of the faithful can be seen. "
  );
  SetItems( ([
     ({"benches","stone benches"}) : "These stone benches are placed in a "
     "circle around "
     "the room. They appear to circle around the statue. ",
     ({"pedestal"}) : "The wooden pedestal stands in the center of the room. "
     "This is what the priests use to speak out about the faith of Skadar. "
     "There are what appears to be small wheels on the bottom of it, "
     "making it mobile. ",
     ({"urn","urns"}) : "These urns stand around the statue. They appear "
     "to be burning with some sort of incense. ",
     ({"room","church","church of skadar"}) : (:GetLong:),
     ({"statue","statue of zeratul"}) : "This huge statue is a sight to see. "
     "The large and detailed sculpture tells a story about the beginnings "
     "of the Skadar religion. It mentions about how Zeratul saved the skaven "
     "from the pain of being shunned by the rest of Kailie. ",
  ]) );
  SetItemAdjectives( ([
     "church" : ({"large","stone","impressive"}),
     "urns" : ({"religions","important"}),
     "benches" : ({"useful"}),
     "pedestal" : ({"mobile"}),
     "statue" : ({"impressive","large"}),
  ]) );
  SetListen( ([
     "default" : "The sounds of praying is heard here. ",
  ]) );
  SetSmell( ([
     "default" : "The smell of lit urns fills the room. ",
  ]) );
  SetInventory( ([
     V_NPC + "sarakar" : 1,
     V_NPC + "healer" : 1,
  ]) );
  SetExits( ([
     "out" : V_ROOM + "main_road/mr8",
     "east" : V_ROOM + "church/cemetery",
  ]) );
  AddExit("south", V_ROOM + "church/ch2", (: Skadar :));
  }


int Skadar(string dir) {
  if(this_player()->GetReligion() == "Skadar" ||
    creatorp(this_player())) {
    return 1;
  }
  this_player()->AddStaminaPoints(-50);
  message("system", "An invisibile ward prevents your entery. ",
         this_player());
  return 0;
  }
