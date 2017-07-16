// Title: Destroyed Grymxoria Town
// File: thorian_shrine.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Defaced shrine for the Thorian religion
//
// Revision History: 
// Gaby Jan99
 
#include <lib.h>
#include <vendor_types.h>
#include "../grymxoria.h"
inherit LIB_CHAPEL;

static void create() {
    chapel::create();
  SetShort("a small abandoned shrine");
    SetClimate("indoors");
    SetDomain("Estergrym");
    SetTown("Grymxoria");
    SetAmbientLight(15);
    SetExits( (["south" : G_ROOM + "church2b" ]) );
    SetLong("Splatters of red cover the entire room from floor to ceiling.  "
        "On the north wall there is a depiction of Zeddicus, the lord of "
        "pain jabbing needles into a kneeling nosferatu, it has been "
        "horribly slashed and many parts of the picture are smashed off. "
        "Below the depiction is a low, stone altar which has a "
        "complete Nosferatu skeleton impaled through the chest with "
        "a spear lying on it.  In the northwest and northeast "
        "corners there are marble statues of Thorian faithfuls "
        "which have been toppled and defaced.");
    SetItems( ([
        ({ "splatters of red", "red splatters", "splatters", "red" }) :
            "The walls, floor, and ceiling are all totally covered "
            "in red.  One cannot be certain wether it is simply red "
            "paint or real blood.",
        ({ "depiction of zeddicus", "depiction", "picture", 
            "painting" }) :
            "The depiction is painted with red and shows Zeddicus in "
            "the form of a nosferatu jabbing 9 inch needles into one "
            "of his followers, but it has been horribly defaced, "
            "many parts of it are slashed or broken off of the wall.",
        ({ "low stone altar", "stone altar", "low altar", "altar" }) :
            "The alter is about 5 feet long, 8 feet wide, and only "
            "3 feet high.  It is made of dark granite and has a kind "
            "of basin carved out of most of it's top, about 6 inches "
            "deep in the center.  The entire altar is stained of "
            "blood. Resting in the altar is a complete Nosferatu "
            "skeleton with a spear through it's chest, still fully "
            "clothed in tattered robes.",
        ({ "marble statues", "marble statue", "statues", "statue",
            "thorian faithfuls", "faithfuls" }) :
            "The statues are completely identical.  They are in the "
            "form of an obviously starving nosferatu collapsed to his "
            "knees, leaning back and screaming towards the sky in "
            "tremendous agony. But they have been toppled into the "
            "middle of the room, and many projecting parts of them "
            "have been broken off and scattered about the room.",
        "ceiling" : "Because of the darkness, all that can be "
             "discerned about the ceiling is that it is very stained by "
             "something red...most likely blood.",
             "floor" : "The floor is covered by what looks like dried "
             "blood.",
        ({ "north wall", "wall" }) : "The north wall is covered with "
             "a defaced red depiction of Zeddicus, the lord of pain.",
        ({ "nine inch needles", "long needles", "needles", "needle" }) :
             "The needles have been stabbed deeply into the body of a "
             "kneeling nosferatu.",
        "walls" : "Covered in red, the walls are a fearful sight.",
        ({ "kneeling nosferatu", "nosferatu", "follower" }) :
             "Kneeling on the floor, the nosferatu is put through great "
             "suffering by his loving, yet highly punishing deity.",
        ({ "corners", "northwest corner", "northeast corner" }) :
             "Marble statues sit in the northeast and northwest corners "
             "of the room.",
        ({"skeleton","nosferatu skeleton","spear"}) : "In the center "
            "of the altar is a complete Nosferatu skeleton, with "
            "a spear through it's chest. It is fully clothed in what "
            "appear to be priestly robes",
        ]) );
    SetReligion("Thorian", "Thorian");
    SetClasses( ({ "cleric" }) );
    SetAllowSacrifice(1);
    SetSacrificeType(VT_ALL);
    SetDeities( ({ "Zeddicus" }) );
  SetInventory( ([
    ]) );
    }
