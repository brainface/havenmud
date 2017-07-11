//
// Filename: hp1.c
// Part of the Holy Path
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("the Holy Path");
   SetExits( ([ "south" : H_ROOM + "holy_path/hp2" ]) );
   SetDayLong("During the day, brightness overwhelms the street as "
              "it is reflected off the walls of Church of Kylin. "
              "Rising into the sky like a spire into the Heavens, the "
              "church of Kylin can be seen from every point of the town. "
              "Its majestic towers and grandiose architecture overshadow "
              "all but the Grand Library of Haven Town in beauty and "
              "sheer magnitude.  To the west is the Haven Cemetery, a "
              "foul place of death and decay. To the south the Holy "
              "Path continues.");
   SetNightLong("At night, even the stars seem abashed by the presence "
                "of the Church of Kylin. Its majestic towers and sheer "
                "size make it seem more of a natural force than a building. "
                "In the darkness, the building seems to darken the street, "
                "chilling it in a way that only the center of the Lord of "
               "Balance's power could awe a mortal. To the west is the Haven "
               "Cemetery, a foul place of death and decay. To the south the "
               "Holy Path continues.");
   SetItems( ([ 
      ({ "church", "building", "structure", "palace" }) : 
         "The Church of Kylin is a huge structure with large spiring "
         "towers that rise into the very heavens nearly in defiance of "
         "them.  Its large vaulted doors give the impression that this "
         "is the largest church in Kailie.  Columns of marble stand like "
         "soldiers guarding the palace in a true mockery of secular "
         "power.  It is no wonder that many people believe the church "
         "runs the town.",
      ({ "cemetery", "place" }) :
         "The Haven Town cemetery, located to the west, is a chilling "
         "sight.",
      ({ "street", "path", "road" }) :
         (: GetLong :),
      ({ "wall", "walls" }) :
         "The walls of the church are large, giving off an aura of "
         "religious power.",
      ({ "tower", "towers" }) :
         "The majestic towers of the church rise high into the sky.",
      ({ "column", "columns", "soldier", "soldiers" }) :
         "These columns of marble are standing like soldiers guarding "
         "the church.",
      ({ "architecture" }) :
         "The grandoise architecture of the church overshadows all "
         "but the Grand Library of Haven in beauty and magnitude.",
   ]) );
   SetItemAdjectives( ([
      "church" : ({ "kylin", "huge" }),
      "cemetery" : ({ "foul" }),
      "street" : ({ "holy" }),
      "wall" : ({ "large" }),
      "tower" : ({ "majestic", "large", "spiring" }),
      "architecture" : ({ "grandoise" }),
      "column" : ({ "marble" }),
   ]) );
   SetEnters( ([ 
      "church" : H_ROOM + "church/entrance",
      "cemetery" : H_ROOM + "cemetery",
   ]) );
   SetListen( ([ 
      "default" : "A low chanting of the faithful is moving through the "
                  "air.",
   ]) );
   SetSmell( ([ 
      "default" : "The scent of incense is strong here.",
   ]) );
  SetInventory( ([
    H_NPC + "templar" : 3,
    ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 18:57:06 1999. */
