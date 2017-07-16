#include <lib.h>
#include <std.h>
#include "../hive.h"
inherit LIB_NPC;

static void create() {
	string WHO_ME;
	string ADJ;
	string GENDER;
	switch(random(2)) {
		
		case 0:
		GENDER = "male";
		break;
		case 1:
		GENDER = "female";
		break;
	}
	::create();
	SetRace("thri-kreen");
	SetGender(GENDER);
	SetMorality(0);
	SetClass("merchant");
	SetSkill("pierce combat", 1, 1);
	
	ADJ = "thri-kreen";
	switch(random(2)) {
		
		case 0:
		WHO_ME = "miner";
		SetLevel(20 + random(10));
		if (GetLevel() > 24) {
			AddAdjective( ({ "fragile", "fragile-looking"}) );
			ADJ = "fragile thri-kreen";
		}
		SetInventory( ([
		      HIVE_ARM "browncloak" : "wear cloak on torso and upper left arm and upper right arm",
		      HIVE_OBJ "spade"      : "wield spade",
		      ]) );
		break;
		
		case 1:
		  WHO_ME = "craftsman";
	    SetLevel(20 + random(10));
	  	if (GetLevel() > 24) {
	  		AddAdjective( ({ "fragile", "fragile-looking"}) );
	  		ADJ = "fragile thri-kreen";
	  	}
	  	SetInventory( ([
	  	      HIVE_ARM "browncloak" : "wear cloak on torso and upper left arm and upper right arm",
	  	      ]) );
	  	   switch(random(2)) {
		   	
	   	   	case 0:
		     	AddInventory(HIVE_OBJ "awl", "wield awl");
		    	break;
		   	
		    	case 1:
		    	AddInventory(HIVE_OBJ "mallet", "wield mallet");
		    	break;
		   }
		break;
	}
	SetShort("a " + ADJ + " " + WHO_ME);
	SetLong("This is a " + ADJ + " " + WHO_ME + ". The life of a worker in the"
	        " hive is hard, but rewarding. While not trained directly in"
	        " combat, the workers are still thri-kreen and as such, fairly"
	        " strong and mostly capable of defending themselves when the soldiers"
	        " fail to do their job.");
	SetId( ({ WHO_ME, "worker", "thri-kreen" }) );
	SetKeyName(ADJ + " " + WHO_ME);
}
