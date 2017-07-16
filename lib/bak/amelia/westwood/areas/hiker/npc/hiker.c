#include <lib.h>
inherit LIB_NPC;
#include "../hiker.h"
#include <size.h>

static void create() {
   mapping inv;
   string tempsize = "";
   int i, x;
   npc::create();
   SetProperty("hikernoleave",1);
   switch(random(2)){
      case 0:
      SetGender("male");
      break;
      case 1:
      SetGender("female");
      break;
   }
   switch(random(3)) {
      case 0:
      SetKeyName("adult hiker");
      SetShort("an adult hiker");
      SetId( ({ "hiker","adult" }) );
      SetAdjectives( ({ "adult" }) );
      SetLong("The " + GetGender() + " hiker has strong legs and is "
              "well-tanned, having been out in the sun a lot for hiking "
              "trips.  " + capitalize(nominative(this_object())) + " seems "
              "to revel in the fresh air and life surrounding the area.");
      i = 2;
      break;
      case 1:
      SetKeyName("tall hiker");
      SetShort("a tall hiker");
      SetId( ({ "hiker" }) );
      SetAdjectives( ({ "tall" }) );
      SetLong("The tall hiker has very long legs for " + 
              possessive(this_object()) + " race, and has "
              "very good straight-backed posture.");
      i = 3;
      break;
      case 2:
      SetKeyName("plump hiker");
      SetShort("a plump hiker");
      SetId( ({ "hiker" }) );
      SetAdjectives( ({ "plump" }) );
      SetLong("The hiker is rather large, and looks sorry for "
              "having agreed to go on this hike.  However, " +
              nominative(this_object()) + " doesn't seem to be too "
              "weak.");
      i = 1;
      break;
   }
   SetClass("valkyr");
   switch(random(7)) {
      case 0:
      SetRace("muezzin");
      break;
      case 1:
      SetRace("elf");
      break;
      case 2:
      SetRace("gelfling");
      break;
      case 3:
      SetRace("dwarf");
      break;
      case 4:
      SetRace("human");
      break;
      case 5:
      SetRace("halfling");
      break;
      case 6:
      SetRace("sprite");
      SetKeyName("adult hiker");
      SetShort("an adult hiker");
      SetId( ({ "hiker","adult" }) );
      SetAdjectives( ({ "adult" }) );
      SetLong("Strong wings on the back of the sprite hiker propel "
              + objective(this_object()) + " forward.  " + 
              capitalize(nominative(this_object())) + " is well-tanned "
              "and happy in the fresh air of the outdoors.");
      break;
   }
   inv = ([
            H_OBJ + "/snack" : random(2),
            H_OBJ + "/bottle" : 1,
            H_OBJ + "/trailmix" : random(2),
         ]);
   if(GetRace()=="sprite") {
      x = 9;
      SetSkill("enchantment",20);
      SetSkill("conjuring",20);
      SetSpellBook( ([
                       "ice ball" : 100,
                  ]) );
      SetCombatAction(40,({ "!cast ice ball" }) );
   }
   else {
      x = 10;
   }
   switch(GetSize()) {
		case SIZE_VERY_SMALL:
		tempsize = "very_small_";
		break;
		case SIZE_SMALL:
		tempsize = "";
		break;
		case SIZE_MEDIUM:
		tempsize = "medium_";
		break;
   }

   for(i=2;i>=0;i--) {
      switch(random(10)) {
         case 0:
         if(inv[H_OBJ + tempsize + "boots"]) {
            i++;
            break;
         }
         inv += ([ H_OBJ + tempsize + "boots" : "wear boots" ]);
         break;
         case 1:
         if(inv[H_OBJ + tempsize + "visor"]) {
            i++;
            break;
         }
         inv += ([ H_OBJ + tempsize + "visor" : "wear visor on head" ]);
         break;
         case 2:
         if(inv[H_OBJ + tempsize +"windbrk"] || 
		inv[H_OBJ + tempsize + "shirt"] ||
            inv[H_OBJ + tempsize + "tee"] || 
		inv[H_OBJ + tempsize + "flannel"]) {
            i++;
            break;
         }
         inv += ([ H_OBJ + tempsize + "windbrk" : "wear windbreaker" ]);
         break;
         case 3:
         if(inv[H_OBJ + tempsize + "belt"]) {
            i++;
            break;
         }
         inv += ([ H_OBJ + tempsize + "belt" : "wear belt" ]);
         break;
         case 4:
         if(inv[H_OBJ + tempsize + "pants"] || inv[H_OBJ + tempsize + "shorts"]) {
            i++;
            break;
         }
         inv += ([ H_OBJ + tempsize + "pants" : "wear pants" ]);
         break;
         case 5:
         if(inv[H_OBJ + tempsize +"windbrk"] || 
		inv[H_OBJ + tempsize + "shirt"] ||
            inv[H_OBJ + tempsize + "tee"] || 
		inv[H_OBJ + tempsize + "flannel"]) {
            i++;
            break;
         }
         inv += ([ H_OBJ + tempsize + "shirt" : "wear shirt" ]);
         break;
         case 6:
         if(inv[H_OBJ +tempsize + "shorts"] || inv[H_OBJ + tempsize + "pants"]) {
            i++;
            break;
         }
         inv += ([ H_OBJ + tempsize + "shorts" : "wear shorts" ]);
         break;
         case 7:
         if(inv[H_OBJ + tempsize +"windbrk"] || 
		inv[H_OBJ + tempsize + "shirt"] ||
            inv[H_OBJ + tempsize + "tee"] || 
		inv[H_OBJ + tempsize + "flannel"]) {
            i++;
            break;
         }
         inv += ([ H_OBJ + tempsize + "tee" : "wear tee" ]);
         break;
         case 8:
         if(inv[H_OBJ + tempsize +"windbrk"] || 
		inv[H_OBJ + tempsize + "shirt"] ||
            inv[H_OBJ + tempsize + "tee"] || 
		inv[H_OBJ + tempsize + "flannel"]) {
            i++;
            break;
         }
         inv += ([ H_OBJ + tempsize + "flannel" : "wear flannel" ]);
         break;
         case 9:
         if(inv[H_OBJ + tempsize + "walkpole"]) {
            i++;
            break;
         }
         inv += ([ H_OBJ + tempsize + "walkpole" : "wield stick in left hand" ]);
         SetSkill("pole attack",5);
         SetSkill("pole defense",5);
         break;
      }
   }

   SetAction(1,({ "!emote grunts heavily.","!emote shuffles around.",
                  "!emote pulls out a small snack and munches on it.",
                  "!emote drinks some from a bottle of water.",
                  "!emote leans over and picks at the ground.",
                  "!emote examines some leaves." }) );
   SetInventory(inv);
   SetLevel(25+random(5));
   if(GetKeyName()=="plump hiker") {
      SetLevel(GetLevel()-random(6));
   }
   if(GetKeyName()=="tall hiker") {
      SetLevel(GetLevel()+random(4));
   }

}
