// updated lib chapel 2/june/2017 torak@haven

#include <lib.h>
#include "../rome.h"
inherit LIB_CHAPEL;

int Thorian(string);

static void create() {
  ::create();
  SetClimate("indoors");
  SetWarmth(50);
  SetAmbientLight(50);
  SetShort("inside the Thorian Temple");
  SetListen( ([
    "default" : "Gentle whispers seem to echo from the walls, "
                "welcoming all who enter.",
    ]) );
  SetSmell( ([
    "default" : "The Temple has two conflicting smells, incense and "
                "a rich, coppery smell.",
    ]) );
  SetReligion("Thorian");
  SetInventory( ([
    ROME_NPC "narrin" : 1,
    ROME_NPC "garric" : 1,
    ]) );
  SetExits( ([
    "out" : ROME_ROOM "rd14",
    ]) );
  AddExit("east", ROME_ROOM "thorian_hall", (: Thorian :));
  SetLong("The Thorian Temple of Sanctum is a large affair dedicated to "
          "the Thorian faith. Around the room are various pictures of "
          "death, dying, disease, and corrupted bodies. Large alabaster "
          "columns make up the walls, which are covered in artwork of "
          "the religion of death. Various bits of incense burn around "
          "the room, left by people wishing to speed the journey of their "
          "lost loved ones.");
  SetItems( ([
    ({ "picture", "pictures" }) : "The pictures depict death in all its "
                                  "forms. Near the bodies in each picture "
                                  "are flowers and plants growing from the "
                                  "soil.",
    ({ "column", "columns" }) : "The columns are plain white stonework, "
                                "giving the impression of the care with "
                                "which this temple is maintained.",
    ({ "incense" }) : "Small bits of nicely smelling incense lie burning "
                      "in holders embedded in the walls.",
    ({ "holder", "holders" }) : "These are normal brass incense holders.",
    ]) );
  SetItemAdjectives( ([
    "column" : ({ "large", "alabaster" }),
    ]) );
}

int Thorian(string dir) {
   if(this_player()->GetReligion() == "Thorian" ||
      creatorp(this_player())) {
      return 1;
   }
   message("system", "A gust of %^BOLD%^%^BLACK%^smoke%^RESET%^ keeps you "
   "away from there.",
           this_player());
   return 0;
 }
