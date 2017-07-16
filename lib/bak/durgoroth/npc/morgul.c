// Title : Durgoroth Town
// File: morgul.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract:   Morgul, Cleric leader of Saa'HaGoth
//
// Revision History: 
//
//Revised by Arika@Haven 1/16/1999

#include <lib.h>
#include <damage_types.h>
inherit LIB_LEADER;
#include "../durgoroth.h"
 
static void create() {
     leader::create();
     SetKeyName("morgul");
     SetId( ({ "morgul the demon lord","morgul the high priest",
          "demon lord","high priest","priest of Saahagoth","demon"
          "lord","priest" }) );
     SetShort("Morgul the Demon Lord and High Priest of Saahagoth");  
     SetLong(
       "Morgul the Demon Lord and the High Priest of Saahagoth, "
       "formost disciple of the Mistress of the dark flame. He is a huge and "
       "terrifying daemon, standing nearly eight feet tall with massive "
       "wings and razor sharp claws on his huge fists. He radiates "
       "an aura of sheer power and terror, and looks like he could "
       "easily rip any mortal into shreds in a heartbeat."
     );
     SetRace("daemon");
     SetTaughtSpheres( ({
       "religion saahagoth",
       "clerical",
       "clerical necromancy", 
       "clerical evokation"
     	 }) );
  	 SetClass("priest");
     SetUniqueSkills( ([
   			"blunt combat" : 0,
        "knife combat" : 1,
        "stealth" : 3,
        ]) );
     SetSkill("melee combat", 1, 1);
     SetSkill("slash combat", 1, 1);
     SetLevel(85);
     SetGender("male");
     SetTown("Durgoroth");
     SetReligion("Saahagoth","Saahagoth");
     SetMorality(-2000);
     SetPlayerTitles( ([
          "newbie" : "the Apprentice Dark Priest of Saahagoth",
          "mortal" : "the Dark Priest of Saahagoth",
          "hm" : "the Incarnation of Evil",
          "legend" : "the Devourer of Souls",
          "avatar" : "the One Whom All Mortals Fear",
          "chorist" : "the Mouthpiece of Pure Evil",
          "paladin" : "the Vengeful Crusader of Saahagoth"
          ]) );
     SetSpellBook( ([
          "pious obstructions" : 100,
          "purify" 						 : 100,
          "touch of death" 		 : 100,
          "hellfire" 					 : 100,
          "cause bleeding"		 : 100,
          "unholy power"			 : 100,
          ]) );
     RemoveLanguage("Gryshnak");
     SetLanguage("Blaodric",100,1);
     SetFreeEquip( ([
     		"/domains/frostmarches/towns/durgoroth/obj/knife":1
     		]) );
     SetCombatAction(50, ({
     		"!cast hellfire",
     		"!cast pious obstructions",
     		"!cast purify",
     		"!cast touch of death",
     		"!cast cause bleeding",
     		}) );
}

int AddEnemy( object ob ) {
     object who = this_object();
     if (!ob->GetProperty("morgul_attacker")) {
          who->eventForce("say Foolish mortal! You dare to attack me!?");
          who->eventForce("cast unholy power");
          who->eventForce("cast pious obstructions");
          message("bang","Morgul raises a hand and a bolt of pure energy "
               "shoots from it, striking you and sending you flying! "
               "You are hurled back through the archway, across the room "
               "beyond and slammed brutally into the wall on the far "
               "side.",ob);
          message("bang","Morgul raises a hand and a bolt of pure "
               "energy shoots from it, striking "+ob->GetCapName()+
               " and sending him flying back through the archway in a burst "
               "of light.",environment(ob),ob);
          ob->SetPermanentProperty("morgul_attacker",1);
          ob->eventMove( D_ROOM + "/cave02" );
          message("bang", "A resounding crack of thunder echo's about "
               "the room and suddenly "+ob->GetCapName()+" is hurled into "
               "the room in a burst of light. "+nominative(ob)+" is "
               "hurled across the chamber and slamed into the far wall "
               "with a bone shattering crash.",environment(ob),ob);
          ob->eventCollapse();
          }
     return leader::AddEnemy( ob );
     }
