/*  Averath Isle virtual file.  */
#include <lib.h>
#include <domains.h>

inherit LIB_ROOM;

string eventSearchFirepit();
string eventSearchSewer();
int XPos, YPos, ZPos;

varargs static void create(int x, int y, int z) {
  string runninglong = "";
  int tmpflag = 0;
  ::create();
  if (!z) z = 0;

  XPos = x;
  YPos = y;
  ZPos = z;
  
  /* Exits */
  if (z == 0) {
  if ((x < 10) && (absolute_value(x) + absolute_value(y) < 13)) {
    AddExit("east", AVERATH_VIRTUAL "island/" + (x + 1) + "," + y + "," + z);
    }
  if ((x > -10) && (absolute_value(x) + absolute_value(y) < 13)) {
    AddExit("west", AVERATH_VIRTUAL "island/" + (x - 1) + "," + y + "," + z);
    }
  if ((y > -6) && (absolute_value(x) + absolute_value(y) < 13)) {
    AddExit("south", AVERATH_VIRTUAL "island/" + x + "," + (y - 1) + "," + z);
    }
  if ((y < 5) && (absolute_value(x) + absolute_value(y) < 13)) {
    AddExit("north", AVERATH_VIRTUAL "island/" + x + "," + (y + 1) + "," + z);
    }
  if (absolute_value(x) + absolute_value(y) == 13) {
      if (x < 0) {
         AddExit("east", AVERATH_VIRTUAL "island/" + (x + 1) + "," + y + "," + z);
        if (y > 0) AddExit("south", AVERATH_VIRTUAL "island/" + x + "," + (y - 1) + "," + z);
        if (y < 0) AddExit("north", AVERATH_VIRTUAL "island/" + x + "," + (y + 1) + "," + z);
    }
      if (x > 0) {
         AddExit("west", AVERATH_VIRTUAL "island/" + (x - 1) + "," + y + "," + z);
        if (y > 0) AddExit("south", AVERATH_VIRTUAL "island/" + x + "," + (y - 1) + "," + z);
        if (y < 0) AddExit("north", AVERATH_VIRTUAL "island/" + x + "," + (y + 1) + "," + z);
        }
      }
   }
  if (y == 5) {
  	AddExit("north", INNERSEA_VIRTUAL "ocean/" + x + ",-100");
  	SetProperty("coastal", 1);
  }
  if (y == -6 && x != 6 && x != 7) {
  	AddExit("south", INNERSEA_VIRTUAL "ocean/" + x + ",-112");
  	SetProperty("coastal", 1);
  }
  if (y == -7) {
  	AddExit("south", INNERSEA_VIRTUAL "ocean/" + x + ",-112");
  	SetProperty("coastal", 1);
  }
  if (x == 10) {
  	AddExit("east", INNERSEA_VIRTUAL "ocean/" + "11," + (y - 105));
  	SetProperty("coastal", 1);
  }
  if (x == -10) {
  	AddExit("west", INNERSEA_VIRTUAL "ocean/" + "-11," + (y - 105));
  	SetProperty("coastal", 1);
  }
  if (x == -9 && y == -4) {
  	AddExit("south", INNERSEA_VIRTUAL "ocean/-9,-110");
  	AddExit("west", INNERSEA_VIRTUAL "ocean/-10,-109");
  	SetProperty("coastal", 1);
  }
  if (x == -10 && y == -3) {
  	AddExit("south", INNERSEA_VIRTUAL "ocean/-10,-109");
  	AddExit("west", INNERSEA_VIRTUAL "ocean/-11,-108");
  	SetProperty("coastal", 1);
  }
  if (x == -10 && y == 3) {
  	AddExit("north", INNERSEA_VIRTUAL "ocean/-10,-102");
  	AddExit("west", INNERSEA_VIRTUAL "ocean/-11,-103");
  	SetProperty("coastal", 1);
  }
  if (x == 10 && y == 3) {
  	AddExit("north", INNERSEA_VIRTUAL "ocean/10,-102");
  	AddExit("east", INNERSEA_VIRTUAL "ocean/11,-103");
  	SetProperty("coastal", 1);
  }
  if (x == -8 && y == 5) {
  	AddExit("west", INNERSEA_VIRTUAL "ocean/-9,-101");
  	SetProperty("coastal", 1);
  }
  if (x == 8 && y == 5) {
  	AddExit("east", INNERSEA_VIRTUAL "ocean/9,-101");
  	SetProperty("coastal", 1);
  }
  if (x == -7 && y == -6) {
  	AddExit("west", INNERSEA_VIRTUAL "ocean/-8,-111");
  	SetProperty("coastal", 1);
  }
  if (x == -9 && y == 4) {
  	AddExit("north", INNERSEA_VIRTUAL "ocean/-9,-101");
  	AddExit("west", INNERSEA_VIRTUAL "ocean/-10,-102");
  	SetProperty("coastal", 1);
  }
  if (x == 9 && y == 4) {
  	AddExit("north", INNERSEA_VIRTUAL "ocean/9,-101");
  	AddExit("east", INNERSEA_VIRTUAL "ocean/10,-102");
  	SetProperty("coastal", 1);
  }
  /* End Exits */

  /* Begin adding lines to the long. */

  if (z == 0) {
  if (!GetExit("north")) {
    runninglong += "The sea lies directly to the north, allowing only "
                   "those afloat to continue. ";
    AddItem("sea", "The sea stretches off endlessly to the north.");
    }
  if (!GetExit("south")) {
    runninglong += "The sea lies directly to the south, allowing only "
                   "those afloat to continue. ";
    AddItem("sea", "The sea stretches off endlessly to the south.");
    }
  if (!GetExit("east")) {
    runninglong += "The sea lies directly to the east, allowing only "
                   "those afloat to continue. ";
    AddItem("sea", "The sea stretches off endlessly to the east.");
    }
  if (!GetExit("west")) {
    runninglong += "The sea lies directly to the west, allowing only "
                   "those afloat to continue. ";
    AddItem("sea", "The sea stretches off endlessly to the west.");
    }
  if (GetItem("sea")) {
    SetSmell( ([
      "default" : "The smell of the ocean is bitter and cold.",
      ]) );
    SetListen( ([
      "default" : "The crash of the surf fills the air.",
      ]) );
    }
  if (x == y) {
    runninglong += "The Averath River runs through here, heading off "
                   "to the southwest from the northeast. ";
    AddItem("river", "The Averath River's crystal blue waters invite "
                     "locals to bathe and swim.");
    SetListen( ([
      "default" : "The river's current adds a hum of noise.",
      ]) ); 
   }
  if (x < -5 && x - y < -10) {
    SetShort("a sandy beach");
    runninglong += "A small beach lies here, bordering on the "
                   "endless sea to the north and west. Scattered "
                   "along the edge of the beach are a few palm "
                   "trees, seeming to dare the sands to touch them. ";
    AddItem("sand", "The sand is a fine white-brown powdery grit.");
    AddItem("tree", "The palm trees seem to grow comfortably here.");
    SetListen( ([
      "default" : "The wash of the sea onto the beach is a comforting "
                  "sound.",
      ]) );
    SetSmell( ([
      "default" : "The scent of sea air is both pleasant and tart.",
      ]) );
    tmpflag = 1;
    }
  if (x > 5 && x + y > 10) {
    SetShort("a sandy beach");
    runninglong += "A small beach lies here, bordering on the "
                   "endless sea to the north and east. Scattered "
                   "along the edge of the beach are a few palm "
                   "trees, seeming to dare the sands to touch them. ";
    AddItem("sand", "The sand is a fine white-brown powdery grit.");
    AddItem("tree", "The palm trees seem to grow comfortably here.");
    SetListen( ([
      "default" : "The wash of the sea onto the beach is a comforting "
                  "sound.",
      ]) );
    SetSmell( ([
      "default" : "The scent of sea air is both pleasant and tart.",
      ]) );

    tmpflag = 1;
    }
  if (x > 5 && y < -2) {
    SetShort("inside a small forest");
    runninglong += "Trees grow out of the ground in increasing "
                   "numbers here, forming a small forest. "
                   "The forest gets deeper and denser to the "
                   "south and east, while it seems to thin to "
                   "the north and west. ";
    AddItem("tree", "These thick trees vary by types to oak, birch "
                    "and mulberry.");
    SetSmell( ([
      "default" : "The scent of wet wood fills the air.",
      ]) );
    SetListen( ([
      "default" : "The sounds of the forest whisper from the trees.",
      ]) );
    tmpflag = 1;
    }
  if (!tmpflag) {
    SetShort("on the plains of Averath");
    runninglong += "The grassy plains of Averath lead out from here, "
                   "displaying their beauty for all the world to see. ";
    SetSmell( ([
      "default" : "The fresh air has a wonderfully clean smell.",
      ]) );
    SetListen( ([
      "default" : "Birds chirp happily around you.",
      ]) );
    }
  if (z == 0 && y > -3) {
    SetClimate("sub-tropical");
  }
  if (z == 0 && y < -2) {
    SetClimate("temperate");
    }
  
  /* Randomizer */
  switch (random(10)) {
    case 0:
      runninglong += "Small patches of brownish green grass slightly mar "
                     "the pristine surroundings. ";
      AddItem("grass", "These small patches are simply dead grass.");
    break;
    case 1:
      runninglong += "A single tree stands apart, looking like a forgotten "
                     "soldier. ";
      AddItem("tree", "This large oak tree stands apart from any others.");
    break;
    default:
      runninglong += "Small footprints of animals lead in many directions from "
                     "here. ";
      AddItem("footprints", "These footprints are simply animal tracks "
                            "that lead in no particular direction. ");
    break;
  }
  if (!random(25)) {
    runninglong += "The remains of a camp litter the ground. ";
    AddItem( ({ "remains", "camp" }), "The remains of the camp consist of "
               "a small firepit and dents from sleeping forms.");
    AddItem("dents", "These dents are roughly human sized.");
    AddItem("firepit", "The firepit is surrounded by small rocks.");
    AddItem(({ "rock", "rocks"}), "The rocks are normal stones.");
    AddSearch("firepit", (: eventSearchFirepit :) );
    }
  }
   /* Exits */
  if (z != 0) {
  if ((x < 10) && (absolute_value(x) + absolute_value(y) < 13)) {

    AddExit("east", AVERATH_UNDERGROUND + (x + 1) + "," + y + "," + z);

    }

  if ((x > -10) && (absolute_value(x) + absolute_value(y) < 13)) {

    AddExit("west", AVERATH_UNDERGROUND + (x - 1) + "," + y+ "," +
z);

    }

  if ((y > -6) && (absolute_value(x) + absolute_value(y) < 13)) {

    AddExit("south", AVERATH_UNDERGROUND + x + "," + (y - 1) + ","
+ z);

    }

  if ((y < 5) && (absolute_value(x) + absolute_value(y) < 13)) {

    AddExit("north", AVERATH_UNDERGROUND + x + "," + (y + 1) + ","
+ z);

    }

  if (absolute_value(x) + absolute_value(y) == 13) {

      if (x < 0) {

         AddExit("east", AVERATH_UNDERGROUND + (x + 1) + "," + y +
"," + z );

        if (y > 0) AddExit("south", AVERATH_UNDERGROUND + x + "," +
(y - 1) + "," + z);

        if (y < 0) AddExit("north", AVERATH_UNDERGROUND + x + "," +
(y + 1) + "," + z);

    }

      if (x > 0) {

         AddExit("west", AVERATH_UNDERGROUND + (x - 1) + "," + y +
"," + z);

        if (y > 0) AddExit("south", AVERATH_UNDERGROUND + x + "," +
(y - 1) + "," + z);

        if (y < 0) AddExit("north", AVERATH_UNDERGROUND + x + "," +
(y + 1) + "," + z);

    }

  }

  /* End Exits */



  /* Begin adding lines to the long. */



  SetShort("inside a dark tunnel");

  SetSmell( ([

    "default" : "The stench of wet dirt, must, and mold abound.",

    ]) );

  SetListen( ([

    "default" : "The constant drip-dropping of water echoes through "
                     "the network of tunnels.",

    ]) );

  if (sizeof(GetExits()) == 1) {

    runninglong += "The tunnel dead ends here, forcing travellers "

                   "to return from whence they came. ";

    }

  if (sizeof(GetExits()) > 1) {

    runninglong += "Dark and foreboding, the tunnel leads off to the " +

      conjunction(GetExits(), "and") + ".";

      }

  SetClimate("underground");

  if (x < 2 && x > -2 && y < 2 && y > -2) {
    AddSearch("default", (: eventSearchSewer :) );
    SetTown("Averath");
    runninglong += " The curved walls of the tunnel are wet and slimy, "
             "and the ceiling is high enough in the center to allow a human "
             "of average stature to stand upright. Created from thick concrete, "
             "the tunnel can give even the most fearless an occasional feeling "
             "of claustrophobia. The muck covered floor indicates that the "
             "tunnel is a part of a sewer system.";
    }
  }
  
  SetLong(runninglong);
  if (!random(20)) {
    SetInventory( ([
      AVERATH_NPC "dog" : 1,
      ]) );
  }
  if (!random(20)) {
    SetInventory( ([
      "/std/npc/minstrel" : 1,
     ]) );
 }

}

string GetPositions() {
  return "X == " + XPos + " Y== " + YPos + " Z == " + ZPos;
}

string eventSearchFirepit() {
  object who = this_player();
  int bucks = random(5) + 1;
  if (random(100) < who->GetStatLevel("intelligence")) {
    send_messages("find",
      "$agent_name $agent_verb something by rustling around the firepit.",
      who, 0, environment(who) );
    who->eventPrint("You discover " + bucks + " ducats!");
    who->AddCurrency("ducats", bucks);
    RemoveSearch("firepit");
    return "You pocket the money.";
    }
  return "You find nothing at all.";
}

string eventSearchSewer() {
  object who = this_player();
  object prize = 0;
  int tmp = 0;

  if (random(200) > (who->GetStatLevel("intelligence") +
who->GetStatLevel("luck"))) {
    return "You don't find a thing.";
    }
  switch(random(6)) {
    case 0:
      return "You manage to get muck all over your hands.";
      break;
    case 1:
      prize = new(AVERATH_OBJ "sewer_sword");
      prize->eventMove(who);
      RemoveSearch("default");
      return "You find a nasty old sword in the muck.";
      break;
    case 2:
      tmp = random(6) + 1;
who->AddCurrency("ducats", tmp);
      RemoveSearch("default");
      return ("You find " + tmp + " ducats!");
      break;
    default:
      return "You find nothing at all.";
    }
}

 
