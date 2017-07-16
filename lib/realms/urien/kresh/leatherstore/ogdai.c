// Urien 110613 - Newbie Equipper
// Changed FileName, Long, Actions
// Changed Pathing - More "Solid" Now

#include <lib.h>
#include "../goblins.h"

inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("Ogdai");
  SetId( ({ "ogdai", "tanner" }) );
  SetShort("Ogdai the Tanner");   
  SetLong(
    "Ogdai is a dark brown Goblin runt with a knack "
    "for leather workings. Black tribal painting on his "
    "lumpy face make his red eyes stand out. His hands "
    "are hardened from multiple years of leather craft. "
    "He is a core part of the leather trade in Kresh and "
    "looks as if he has had seen a fair amount of battle. "
    "This Goblin seems eager to offer his help to anyone "
    "who cannot afford the main shop and is quite "
    "generous. He eagerly awaits to assist those who "
    "greet him.");              
  SetRace("goblin");
  SetGender("male");
  SetMorality(-100);
  SetClass("fighter");
  SetLevel(10);      
  SetFreeEquipment( ([
    "vest": STORE_DIR + "oldvest",
    "pants": STORE_DIR + "oldpants",
    "boots": STORE_DIR + "oldboots",
    "glove": STORE_DIR + "oldglove",
    "helmet": STORE_DIR + "oldhelmet",     
  ]) );
  SetLevelLimit(10);   
  SetAction(1, ({
    "!say If you cannot afford Temu. Ogdai may be able "
         "to help.",
    "!say Ogdai can assist with leather gear.",
    "!emote scratches something.",
   }) );
}