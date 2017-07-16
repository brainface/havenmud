#include <lib.h>
#include <std.h>
#include "../hive.h"
inherit LIB_NPC;

static void create() {
	string WHO_ME;
	string ADJ;
	::create();
  SetRace("thri-kreen");
  SetGender("male");
  SetMorality(0);
  SetClass("fighter");
  SetSkill("pierce combat", 1,1);
  
  ADJ = "thri-kreen";
  switch(random(3)) {
  	
  	case 0:
  	WHO_ME = "guardian";
  	SetLevel(95);
  	SetInventory( ([
  	      HIVE_OBJ "glaive"      : "wield glaive in upper left hand and upper right hand",
  	      HIVE_ARM "armlet"      : "wear 1st armlet on upper left arm and upper left hand",
  	      HIVE_ARM "armlet2"     : "wear 1st armlet on upper right arm and upper right hand",
  	      HIVE_ARM "bodyarmour"  : "wear suit of armour on torso and upper left arm and"
  	                               " upper right arm and left leg and right leg",
  	      HIVE_ARM "plumehelmet" : "wear helmet",
  	      HIVE_ARM "redcloak"    : "wear cloak on torso",
  	    ]) );
  	break;
  	
  	case 1:
  	WHO_ME = "archer";	
  	SetLevel(55 + random(10));
  	SetInventory( ([
  	      HIVE_OBJ "sling"       : "wield sling",
  	      HIVE_ARM "bodyarmour"  : "wear suit of armour on torso and upper left arm and"
  	                               " upper right arm and left leg and right leg",
  	      HIVE_ARM "helmet"      : "wear helmet",
  	      HIVE_ARM "redcloak"    : "wear cloak on torso",
  	    ]) );
  	break;
  	
  	case 2:
  	WHO_ME = "footsoldier";
  	SetLevel(35 + random(35));
      if (GetLevel() > 50) {
      	  AddAdjective( ({ "huge" }) );
      	  ADJ = "huge thri-kreen";
      	}

     	SetInventory( ([
  	      HIVE_ARM "bodyarmour"  : "wear suit of armour on torso and upper left arm and"
  	                               " upper right arm and left leg and right leg",
  	      HIVE_ARM "helmet"      : "wear helmet",
  	      HIVE_ARM "redcloak"    : "wear cloak on torso",
  	    ]) );
  	    
   	      switch(random(3)) {
   	      	case 0:
  	        AddInventory(HIVE_OBJ "axe", "wield axe");
  	        break;
  	        
  	        case 1:
  	        AddInventory(HIVE_OBJ "big_axe", "wield axe in upper right hand and upper left hand");
  	        break;
  	        
  	        case 2:
  	        AddInventory(HIVE_OBJ "spike", "wield spike");
  	        break;
  	      }
  	    break;
  	  }

  SetShort("a " + ADJ + " " + WHO_ME);
  SetLong("This is a " + ADJ + " " + WHO_ME + ". He is"
          " charged with defending everyone in the hive"
          " against all threats and looks more than capable"
          " of doing so.");
  SetId( ({ WHO_ME, "soldier", "thri-kreen" }) );
  SetKeyName(ADJ + " " + WHO_ME);
}
