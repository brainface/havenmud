// Written by Vanyel
#include <lib.h>
#include <size.h>
#include "ice.h"
#include <armour_types.h>
inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("yeti");
    SetId( ({ "yeti" }) );
    SetAdjectives( "giant", "towering");
    SetShort("a giant yeti");
    SetLong("Towering at twelve feet tall, this giant yeti "
        "guards his precious armour carefully.");
    SetRace("yeti", 1);
    SetSize(SIZE_LARGE);
    SetClass("fighter");
    SetLevel(20 + random(10));
    SetGender("male");
    SetMorality(-300);
    AddLimb("torso", 0, 1, ({ A_ARMOUR }) );
    SetDie("The yeti growls in rage.");
    AddLimb("head", "torso", 1, ({ }) );
    AddLimb("right arm", "torso", 2, ({ A_ARMOUR }) );
    AddLimb("left arm", "torso", 2, ({ A_ARMOUR }) );
    AddLimb("right hand", "right arm", 3, ({ }) );
    AddLimb("left hand", "left arm", 3, ({ }) );
    AddLimb("left leg", "torso", 2, ({ }) );
    AddLimb("right leg", "torso", 2, ({ }) );
    AddLimb("left foot", "left leg", 4, ({ }) );
    AddLimb("right foot", "right leg", 4, ({ }) );
    SetStat("strength", 80, 5);
    SetStat("agility", 20, 5);
    SetStat("coordination", 40, 5);
    SetStat("luck", 60, 5);
    SetStat("charisma", 0, 5);
    SetStat("intelligence", 20, 5);
    SetStat("wisdom", 10, 5);
    SetStat("durability", 80, 5);
    SetStat("speed", 60, 5);
    SetEncounter(40);
    SetCombatAction(5, ({ 
    	"!growl", 
    	"!flex", 
    	"!snarl" 
    	}));
    SetInventory( ([ 
    	ICE_OBJ + "/icearmor.c" : "wear armour" 
    	]) );
}
