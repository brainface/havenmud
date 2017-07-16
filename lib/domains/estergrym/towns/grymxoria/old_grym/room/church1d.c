// Title: Destroyed Grymxoria Town
// File: church1d.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Basillica of the Cathedral of Saahagoth
//
// Revision History: 
// Gaby Jan99

#include <lib.h>
#include <domains.h>
#include <vendor_types.h>
#include "../grymxoria.h"
inherit LIB_CHAPEL;
 
static void create() {
    chapel::create();
	SetShort("the Cathedral of Saahagoth");
    SetClimate("indoors");
    SetDomain("Estergrym");
    SetAmbientLight(20);
    SetExits( ([ "down" : G_ROOM "church2c" ]) );
    SetLong("The basilica of the Cathedral of Saahagoth. "
        "This is a huge room built in the gothic style. "
        "Long rows of black marble benches line the room. "
        "At the end of the room is large black marble statue "
	  "of Morgoth, the god of Saahagoth. Beside the statue of "
	  "Morgoth lies a toppled and defaced statue of Ukla, the "
	  "former god of SaaHaGar. At the feet of the "
	  "the statues is a pulpit for use by the high priest of "
        "Saahagoth. At the back of the room is a large "
        "instrument that looks like a pipe organ. Other than "
        "the toppled statue, this room seems unsoiled. In front "
        "of the pulpit writhes a large%^BOLD%^BLUE%^ "
        "portal of flickering energy.%^RESET%^");
    SetTown("Grymxoria");
    SetReligion("Saahagoth", "Saahagoth");
    SetClasses( ({ "cleric" }) );
    SetAllowSacrifice(1);
    SetSacrificeType(VT_ALL);
    SetDeities(  ({ "Morgoth" })  );
    SetItems( ([
        "benches" : "Long rows of black marble benches.",
	    "statues" : "There are two statues one statues of Laoise "
            "and a newer statue of Ukla.  ",
	    ({ "statue of laoise", "laoise" }) : "A large statue "
            "of what the goddess Laoise is thought to look like. "
            "It is a large imposing visage carved out of black "
            "marble.",
	    ({ "statue of ukla", "ukla" }) :
		    "This is a large statue done to resemble how Ukla "
		    "looked when he was a mortal deathknight, but it "
            "has been toppled over and defaced, many parts "
            "gouged or broken.",
        "pulpit" : "A small pulpit at the foot of the statue, "
            "carved out of the same black stone as the rest of the "
            "church.",
        ({ "organ", "pipe organ" }) : "A large pipe organ. "
            "The large brass pipes stretch up to the high arched "
            "ceiling.",
		({"large portal","flickering portal"}) : "A large oval "
			"shaped portal of flickering blue energy, that "
			"seems to lead straight into the void.",
		"portal" : "A large oval "
			"shaped portal of flickering blue energy, that "
			"seems to lead straight into the void.",
		]) );
	SetEnters( ([
    "portal" : FROSTMARCHES_TOWNS "durgoroth/room/cave04",
		]) );
    SetListen( ([
        "default" : "Depressing and morbid organ music plays "
            "in the background."]) );
    }
